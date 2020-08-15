// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 10:42)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_IMPL_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/VertexFormatFlags.h"
#include "Rendering/Resources/VertexFormatElement.h"
#include "System/Helper/EnumCast.h"

namespace CoreTools
{
	class BufferTarget;
	class BufferSource;
	class WriteFileManager;
	class ReadFileManager;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE VertexFormatImpl
	{
	public:
		using ClassType = VertexFormatImpl;
		using BufferTarget = CoreTools::BufferTarget;
		using BufferSource = CoreTools::BufferSource;
		using AttributeType = VertexFormatFlags::AttributeType;
		using AttributeUsage = VertexFormatFlags::AttributeUsage;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
		explicit VertexFormatImpl (int numAttributes);

		CLASS_INVARIANT_DECLARE;

		void SetAttribute (int attribute, unsigned int streamIndex,unsigned int offset, 
						   AttributeType type,AttributeUsage usage,unsigned int usageIndex);

		void SetAttribute (int attribute, unsigned int streamIndex,unsigned int offset,const VertexFormatType& vertexFormatType);

		void SetAttribute(int attribute,const VertexFormatElement& vertexFormatElement);
		
		void SetStride (int stride);		
		
		int GetNumAttributes () const noexcept;
		
		unsigned int GetStreamIndex (int attribute) const;
		unsigned int GetOffset (int attribute) const;
		AttributeType GetAttributeType (int attribute) const;
		AttributeUsage GetAttributeUsage (int attribute) const;
		unsigned int GetUsageIndex (int attribute) const;		
		
		int GetStride () const noexcept;	

		int GetIndex(AttributeUsage usage, unsigned int usageIndex = 0) const noexcept;
		
		static int GetComponentSize (AttributeType type) noexcept;
		static int GetNumComponents (AttributeType type) noexcept;
		static int GetTypeSize (AttributeType type) noexcept;

		int GetStreamingSize () const;
		void Save (BufferTarget& target) const;
		void Load (BufferSource& source);

		void SaveToFile(WriteFileManager& outFile) const;
		void ReadFromFile(ReadFileManager& inFile); 	
		
	private:			
		int m_NumAttributes;
		VertexFormatElement m_Elements[System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes)];
		int m_Stride;
		
		static int sm_ComponentSize[System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)];
		static int sm_NumComponents[System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)];
		static int sm_TypeSize[System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)];
	};
}

#endif // RENDERING_RESOURCES_VERTEX_FORMAT_IMPL_H
