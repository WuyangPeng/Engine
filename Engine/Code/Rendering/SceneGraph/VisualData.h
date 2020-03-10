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
		VisualData(VisualPrimitiveType type,const VertexFormatSmartPointer& vertexformat,
				   const VertexBufferSmartPointer& vertexbuffer,const IndexBufferSmartPointer& indexbuffer);
 
		CLASS_INVARIANT_DECLARE;
		   
		void SetPrimitiveType(VisualPrimitiveType type);
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
		
		void Load(BufferSource& source);
		void Save(BufferTarget& target) const;
		int GetStreamingSize() const;
		void Register(ObjectRegister& target) const;
		void Link(ObjectLink& source);
		
		CORE_TOOLS_NAMES_IMPL_DECLARE;

		bool IsVertexSmartPointerValid() const;
		int GetVertexBufferNumElements() const;
		int GetVertexFormatStride() const;
		int GetPositionOffset() const;
		const char* GetVertexBufferReadOnlyData() const;
	 
	private:
		VisualPrimitiveType m_Type;
		VertexFormatSmartPointer m_VertexFormat;
		VertexBufferSmartPointer m_VertexBuffer;
		IndexBufferSmartPointer m_IndexBuffer;			
	};
}

#endif // RENDERING_SCENE_GRAPH_VISUAL_DATA_H
