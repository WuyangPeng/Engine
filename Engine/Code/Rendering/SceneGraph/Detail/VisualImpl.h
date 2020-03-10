// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 11:00)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_IMPL_H
#define RENDERING_SCENE_GRAPH_VISUAL_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Bound.h"
#include "Rendering/SceneGraph/VisualData.h"
#include "Rendering/SceneGraph/Flags/VisualFlags.h"

#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Shaders/VisualEffectInstance.h"

#include <string>
#include <vector>

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
	class ObjectRegister;
	class ObjectLink;
	class Object;	
}

namespace Rendering
{	
	class VisualEffectInstance;
	class Transform;

	class RENDERING_HIDDEN_DECLARE VisualImpl
	{
	public:
		using ClassType = VisualImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using ObjectRegister = CoreTools::ObjectRegister;
		using ObjectLink = CoreTools::ObjectLink;
		using Object = CoreTools::Object;
		using APoint = Mathematics::APointf;

	public:
		explicit VisualImpl(VisualPrimitiveType type = VisualPrimitiveType::None);	
		VisualImpl(VisualPrimitiveType type,const VertexFormatSmartPointer& vertexformat,const VertexBufferSmartPointer& vertexbuffer,const IndexBufferSmartPointer& indexbuffer);
 
		CLASS_INVARIANT_DECLARE;
		   
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
		const ConstVisualEffectInstanceSmartPointer GetEffectInstance() const;

		// 对几何更新的支持。
		const Bound GetWorldBound(const Transform& worldTransform);
		void UpdateModelBound();
		void ComputeBounding(const std::vector<APoint>& positions);
		
		void Load(BufferSource& source);
		void Save(BufferTarget& target) const;
		int GetStreamingSize() const;
		void Register(ObjectRegister& target) const;
		void Link(ObjectLink& source);
		
		CORE_TOOLS_NAMES_IMPL_DECLARE;

	private:
		void DoUpdateModelBound();
		
	private:
		VisualData m_VisualData;
		Bound m_ModelBound;			
	
		// 着色器效果用来绘制视觉。
		VisualEffectInstanceSmartPointer m_Effect;		
	};
}

#endif // RENDERING_SCENE_GRAPH_VISUAL_IMPL_H
