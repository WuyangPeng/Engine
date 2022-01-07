// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 11:25)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_TYPE_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_TYPE_H

#include "Rendering/RenderingDll.h"

#include "Flags/VertexFormatFlags.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
	class BufferTarget;
	class BufferSource;
	class WriteFileManager;
	class ReadFileManager;
}

namespace Rendering
{ 
	class RENDERING_DEFAULT_DECLARE VertexFormatType
	{
	public:
		using ClassType = VertexFormatType;
		using BufferTarget = CoreTools::BufferTarget;
		using BufferSource = CoreTools::BufferSource;
		using AttributeType = VertexFormatFlags::AttributeType;
		using AttributeUsage = VertexFormatFlags::AttributeUsage;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
		VertexFormatType(AttributeType type, AttributeUsage usage,unsigned int usageIndex) noexcept;
            VertexFormatType() noexcept;

		CLASS_INVARIANT_DECLARE;
 
		AttributeType GetType() const noexcept;
                void SetType(AttributeType type) noexcept;
                AttributeUsage GetUsage() const noexcept;
                void SetUsage(AttributeUsage usage) noexcept;
                unsigned int GetUsageIndex() const noexcept;
                void SetUsageIndex(unsigned int usageIndex) noexcept;

		int GetStreamingSize() const noexcept;
		void Save(CoreTools::BufferTarget& target) const;
		void Load(CoreTools::BufferSource& source);

		void SaveToFile(WriteFileManager& outFile) const;
		void ReadFromFile(ReadFileManager& inFile); 	

	private:		
		AttributeType m_Type;	
		AttributeUsage m_Usage;		
		unsigned int m_UsageIndex;		
	};	 
}

#endif // RENDERING_RESOURCES_VERTEX_FORMAT_TYPE_H
