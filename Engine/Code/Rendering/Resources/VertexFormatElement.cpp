// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 16:16)

#include "Rendering/RenderingExport.h"

#include "VertexFormatElement.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::VertexFormatElement
	::VertexFormatElement() noexcept
	:m_StreamIndex{ 0 }, m_Offset{ 0 }, m_VertexFormatType{}
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexFormatElement ::VertexFormatElement(unsigned int streamIndex, unsigned int offset, const VertexFormatType& vertexFormatType) noexcept
    : m_StreamIndex{ streamIndex }, m_Offset{ offset }, m_VertexFormatType{ vertexFormatType }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,VertexFormatElement)

unsigned int Rendering::VertexFormatElement ::GetStreamIndex() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_StreamIndex;
}

void Rendering::VertexFormatElement ::SetStreamIndex(unsigned int streamIndex) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_StreamIndex = streamIndex;
}

unsigned int Rendering::VertexFormatElement ::GetOffset() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Offset;
}

void Rendering::VertexFormatElement ::SetOffset(unsigned int offset) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_Offset = offset;
}

Rendering::VertexFormatFlags::AttributeType Rendering::VertexFormatElement
	::GetType() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VertexFormatType.GetType();
}

void Rendering::VertexFormatElement ::SetType(AttributeType type) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_VertexFormatType.SetType(type);
}

Rendering::VertexFormatFlags::AttributeUsage Rendering::VertexFormatElement ::GetUsage() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VertexFormatType.GetUsage();
}

void Rendering::VertexFormatElement ::SetUsage(AttributeUsage usage) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_VertexFormatType.SetUsage(usage);
}

unsigned int Rendering::VertexFormatElement ::GetUsageIndex() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VertexFormatType.GetUsageIndex();
}

void Rendering::VertexFormatElement ::SetUsageIndex(unsigned int usageIndex) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_VertexFormatType.SetUsageIndex(usageIndex);
}

int Rendering::VertexFormatElement
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(m_StreamIndex);
	size += CORE_TOOLS_STREAM_SIZE(m_Offset);
	size += m_VertexFormatType.GetStreamingSize();

	return size;
}

void Rendering::VertexFormatElement
	::Save( CoreTools::BufferTarget& target ) const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.Write(m_StreamIndex);
	target.Write(m_Offset);
	m_VertexFormatType.Save(target);
}

void Rendering::VertexFormatElement
	::Load( CoreTools::BufferSource& source )
{	
	RENDERING_CLASS_IS_VALID_9;

	source.Read(m_StreamIndex);
	source.Read(m_Offset);
	m_VertexFormatType.Load(source);
}

void Rendering::VertexFormatElement ::SetVertexFormatType(const VertexFormatType& vertexFormatType) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_VertexFormatType = vertexFormatType;
}

void Rendering::VertexFormatElement ::Set(unsigned int streamIndex, unsigned int offset, const VertexFormatType& vertexFormatType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

	SetStreamIndex(streamIndex);
	SetOffset(offset);
	SetVertexFormatType(vertexFormatType);
}

void Rendering::VertexFormatElement
	::SaveToFile( WriteFileManager& outFile ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	outFile.Write(sizeof(unsigned int),&m_StreamIndex);
	outFile.Write(sizeof(unsigned int),&m_Offset);
	m_VertexFormatType.SaveToFile(outFile);	 
}

void Rendering::VertexFormatElement
	::ReadFromFile( ReadFileManager& inFile )
{
	RENDERING_CLASS_IS_VALID_9;

	inFile.Read(sizeof(unsigned int),&m_StreamIndex);
	inFile.Read(sizeof(unsigned int),&m_Offset);
	m_VertexFormatType.ReadFromFile(inFile);
}
