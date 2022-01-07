// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 15:09)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_DATA_H
#define RENDERING_SCENE_GRAPH_VISUAL_DATA_H

#include "Rendering/RenderingDll.h"

#include "Flags/VisualFlags.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/Resources/VertexBuffer.h"

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
	class RENDERING_HIDDEN_DECLARE VisualData
	{
	public:
		using ClassType = VisualData;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using ObjectRegister = CoreTools::ObjectRegister;
		using ObjectLink = CoreTools::ObjectLink;
		using Object = CoreTools::Object;

	public:
		explicit VisualData(VisualPrimitiveType type = VisualPrimitiveType::None);
		VisualData(VisualPrimitiveType type,const VertexFormatSharedPtr& vertexformat,
				   const VertexBufferSharedPtr& vertexbuffer,const IndexBufferSharedPtr& indexbuffer);
 
		CLASS_INVARIANT_DECLARE;
		   
		void SetPrimitiveType(VisualPrimitiveType type);
		VisualPrimitiveType GetPrimitiveType() const;
		
		void SetVertexFormat(const VertexFormatSharedPtr& vertexformat);
		ConstVertexFormatSharedPtr GetConstVertexFormat() const;
		VertexFormatSharedPtr GetVertexFormat();
		
		void SetVertexBuffer(const VertexBufferSharedPtr& vertexbuffer);
		ConstVertexBufferSharedPtr GetConstVertexBuffer() const;
		VertexBufferSharedPtr GetVertexBuffer();
		
		void SetIndexBuffer(const IndexBufferSharedPtr& indexbuffer);
		ConstIndexBufferSharedPtr GetConstIndexBuffer() const;
		IndexBufferSharedPtr GetIndexBuffer();		 
		
		void Load(CoreTools::BufferSource& source);
		void Save(CoreTools::BufferTarget& target) const;
		int GetStreamingSize() const;
                void Register(CoreTools::ObjectRegister& target) const;
		void Link(CoreTools:: ObjectLink& source);
		
		CORE_TOOLS_NAMES_IMPL_DECLARE;

		bool IsVertexSharedPtrValid() const;
		int GetVertexBufferNumElements() const;
		int GetVertexFormatStride() const;
		int GetPositionOffset() const;
		const char* GetVertexBufferReadOnlyData() const;
	 
	private:
		VisualPrimitiveType m_Type;
		VertexFormatSharedPtr m_VertexFormat;
		VertexBufferSharedPtr m_VertexBuffer;
		IndexBufferSharedPtr m_IndexBuffer;			
	};
}

#endif // RENDERING_SCENE_GRAPH_VISUAL_DATA_H
