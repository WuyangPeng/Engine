// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 11:31)

#ifndef RENDERING_SCENE_GRAPH_PARTICLES_H
#define RENDERING_SCENE_GRAPH_PARTICLES_H

#include "Rendering/RenderingDll.h" 

#include "TrianglesMesh.h"
#include "Camera.h"

RENDERING_EXPORT_SHARED_PTR(ParticlesImpl);

namespace Rendering
{	
	class Culler;
	
	class RENDERING_DEFAULT_DECLARE Particles : public TrianglesMesh
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(Particles);
		using ParentType = TrianglesMesh;
		using ParticlesSmartPointer = CoreTools::NinthSubclassSmartPointer<ClassType>;
		using ConstParticlesSmartPointer = CoreTools::ConstNinthSubclassSmartPointer<ClassType>;		

	public:
		// VertexFormat对象必须包含3元组位置。
		// 也必须有2元组的纹理坐标在通道零，
		// 这些都是设置为标准(每个四边形为单位正方形)。
		// vertexbuffer元素的数量必须是4的倍数。
		// 元素的粒子数量的是1/4 vertexbuffer元素的个数。
		// 索引缓冲区是自动生成的。
		// 'positionSizes'包含位置在开始的三元组和大小在第四元组。
		Particles(const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,int indexSize,
				  const std::vector<APoint>& positions,const std::vector<float>& sizes,float sizeAdjust);
		virtual ~Particles();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Particles);

		int GetNumParticles() const;
		const APoint GetPosition(int index) const;
		float GetSize(int index) const;
		void SetSizeAdjust(float sizeAdjust);
		float GetSizeAdjust() const;

		void SetPosition(int index, const APoint& position);
		void SetSize(int index, float size);

		// 允许应用程序指定小于最大数量的顶点绘制。
		void SetNumActive(int numActive);
		int GetNumActive() const;

		// 粒子是广告牌，总是面对镜头。
		void GenerateParticles (const ConstCameraSmartPointer& camera);

		virtual ControllerInterfaceSmartPointer Clone() const override;		
	
		virtual void GetVisibleSet(Culler& culler, bool noCull) override;

	private:
		void InitIndexBuffer(int indexSize);
		void InitTextureCoord();

	private:
		IMPL_TYPE_DECLARE(Particles);
	};

	CORE_TOOLS_STREAM_REGISTER(Particles);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Ninth, Particles); 
}

#endif // RENDERING_SCENE_GRAPH_PARTICLES_H
