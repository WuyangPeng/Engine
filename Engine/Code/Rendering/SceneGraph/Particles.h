// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 11:31)

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
		// VertexFormat����������3Ԫ��λ�á�
		// Ҳ������2Ԫ�������������ͨ���㣬
		// ��Щ��������Ϊ��׼(ÿ���ı���Ϊ��λ������)��
		// vertexbufferԪ�ص�����������4�ı�����
		// Ԫ�ص�������������1/4 vertexbufferԪ�صĸ�����
		// �������������Զ����ɵġ�
		// 'positionSizes'����λ���ڿ�ʼ����Ԫ��ʹ�С�ڵ���Ԫ�顣
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

		// ����Ӧ�ó���ָ��С����������Ķ�����ơ�
		void SetNumActive(int numActive);
		int GetNumActive() const;

		// �����ǹ���ƣ�������Ծ�ͷ��
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
