// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 16:17)

#include "Rendering/RenderingExport.h"

#include "VertexFormatType.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"

Rendering::VertexFormatType ::VertexFormatType() noexcept
    : m_Type{ VertexFormatFlags::AttributeType::None }, m_Usage{ VertexFormatFlags::AttributeUsage::None }, m_UsageIndex{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexFormatType ::VertexFormatType(AttributeType type, AttributeUsage usage, unsigned int usageIndex) noexcept
    : m_Type{ type }, m_Usage{ usage }, m_UsageIndex{ usageIndex }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VertexFormatType)

Rendering::VertexFormatFlags::AttributeType Rendering::VertexFormatType ::GetType() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Type;
}

void Rendering::VertexFormatType ::SetType(AttributeType type) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_Type = type;
}

Rendering::VertexFormatFlags::AttributeUsage Rendering::VertexFormatType ::GetUsage() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Usage;
}

void Rendering::VertexFormatType ::SetUsage(AttributeUsage usage) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_Usage = usage;
}

unsigned int Rendering::VertexFormatType ::GetUsageIndex() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_UsageIndex;
}

void Rendering::VertexFormatType ::SetUsageIndex(unsigned int usageIndex) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_UsageIndex = usageIndex;
}

int Rendering::VertexFormatType
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	int size = CORE_TOOLS_STREAM_SIZE(m_Type);
	size += CORE_TOOLS_STREAM_SIZE(m_Usage);
	size += CORE_TOOLS_STREAM_SIZE(m_UsageIndex);

	return size;
}

void Rendering::VertexFormatType
	::Save( CoreTools::BufferTarget& target ) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.WriteEnum(m_Type);
	target.WriteEnum(m_Usage);
	target.Write(m_UsageIndex);
}

void Rendering::VertexFormatType
	::Load( CoreTools::BufferSource& source )
{	
	RENDERING_CLASS_IS_VALID_9;

	source.ReadEnum(m_Type);
	source.ReadEnum(m_Usage);
	source.Read(m_UsageIndex);
}

void Rendering::VertexFormatType
	::SaveToFile( WriteFileManager& outFile ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	 const auto type = System::EnumCastUnderlying(m_Type);
        const auto usage = System::EnumCastUnderlying(m_Usage);

	outFile.Write(sizeof(int), &type);
	outFile.Write(sizeof(int), &usage);
	outFile.Write(sizeof(unsigned int),&m_UsageIndex);
}

void Rendering::VertexFormatType
	::ReadFromFile( ReadFileManager& inFile )
{
	RENDERING_CLASS_IS_VALID_9;

	auto type = 0;
	auto usage = 0;

	inFile.Read(sizeof(int),&type);
	inFile.Read(sizeof(int),&usage);
	inFile.Read(sizeof(unsigned int),&m_UsageIndex);

	m_Type = System::UnderlyingCastEnum<AttributeType>(type);
	m_Usage = System::UnderlyingCastEnum<AttributeUsage>(usage);
}
