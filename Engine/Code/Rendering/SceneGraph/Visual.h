// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 15:07)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_H
#define RENDERING_SCENE_GRAPH_VISUAL_H

#include "Rendering/RenderingDll.h"

#include "Spatial.h"
#include "Flags/VisualFlags.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Shaders/VisualEffectInstance.h"

RENDERING_EXPORT_SHARED_PTR(VisualImpl);

namespace Rendering
{	
	class VisualEffectInstance;
	class Culler;

	class RENDERING_DEFAULT_DECLARE Visual : public Spatial
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(Visual);
		using ParentType = Spatial;
		using VisualSmartPointer = CoreTools::SixthSubclassSmartPointer<ClassType>;
	    using ConstVisualSmartPointer = CoreTools::ConstSixthSubclassSmartPointer<ClassType>;	
		using APoint = Mathematics::APointf;

	public:
		explicit Visual(VisualPrimitiveType type = VisualPrimitiveType::None);	
		Visual(VisualPrimitiveType type,const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,const IndexBufferSmartPointer& indexbuffer);
		virtual ~Visual();
 
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Visual);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
		   
		VisualPrimitiveType GetPrimitiveType() const;
		
		void SetVertexFormat(const VertexFormatSmartPointer& vertexformat);
		ConstVertexFormatSmartPointer GetConstVertexFormat() const;
		VertexFormatSmartPointer GetVertexFormat();
		
		void SetVertexBuffer(const VertexBufferSmartPointer& vertexbuffer);
		ConstVertexBufferSmartPointer GetConstVertexBuffer() const;
		VertexBufferSmartPointer GetVertexBuffer();
		
		void SetIndexBuffer(const IndexBufferSmartPointer& indexbuffer);
		ConstIndexBufferSmartPointer GetConstIndexBuffer() const;
		IndexBufferSmartPointer GetIndexBuffer();
		
		const Bound& GetModelBound () const;
		Bound& GetModelBound ();		
	
		// 存取绘制对象的视觉效果。
		void SetEffectInstance (const VisualEffectInstanceSmartPointer& effect);
		const ConstVisualEffectInstanceSmartPointer GetConstEffectInstance() const;
		const VisualEffectInstanceSmartPointer GetEffectInstance();

		virtual void UpdateModelSpace(VisualUpdateType type);

	protected:
		virtual void UpdateModelBound();
		void ComputeBounding(const std::vector<APoint>& positions);

		// 支持分级裁剪。
		virtual void GetVisibleSet(Culler& culler, bool noCull) override;

	private:
		// 对几何更新的支持。
		virtual void UpdateWorldBound() override;

		ConstVisualSmartPointer GetSmartPointer() const;

		void CloneData(const Visual& rhs);
		void CloneIndexBuffer( const Visual &rhs );
		void CloneVertexBuffer( const Visual &rhs );
		void CloneVertexFormat( const Visual &rhs );

	private:
		IMPL_TYPE_DECLARE(Visual);
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(Visual);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Sixth, Visual); 
}

#endif // RENDERING_SCENE_GRAPH_VISUAL_H
