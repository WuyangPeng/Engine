// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 14:42)

#include "Rendering/RenderingExport.h"

#include "TextureBuffer.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

using std::make_shared;

Rendering::TextureBuffer
	::TextureBuffer(int itemSize)
	:m_Data{},m_ItemSize{ itemSize }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TextureBuffer
	::TextureBuffer(const TextureBuffer& rhs)
	:m_Data{ 0 < rhs.m_Data->GetSize() ? new FileBuffer(*rhs.m_Data) : nullptr },m_ItemSize{ rhs.m_ItemSize }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::TextureBuffer& Rendering::TextureBuffer
	::operator=(const TextureBuffer& rhs)
{
	RENDERING_CLASS_IS_VALID_1;

	if (0 < rhs.m_Data->GetSize())
	{
		m_Data = make_shared<FileBuffer>(*rhs.m_Data);
	}
	else
	{
		m_Data.reset();
	}

	m_ItemSize = rhs.m_ItemSize;

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::TextureBuffer
	::IsValid() const noexcept
{
	if (0 < m_ItemSize)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

const char* Rendering::TextureBuffer
    ::GetReadOnlyData () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(m_Data != nullptr,"数据还未读取！");
    
    return m_Data->GetBufferBegin();
}

char* Rendering::TextureBuffer
    ::GetWriteData()
{
    RENDERING_CLASS_IS_VALID_1;
    
    return const_cast<char*>(static_cast<const ClassType*>(this)->GetReadOnlyData());
} 

void Rendering::TextureBuffer
	::Reset(int bufferSize)
{
	RENDERING_CLASS_IS_VALID_1;

	m_Data = make_shared<FileBuffer>(bufferSize);  
}

void Rendering::TextureBuffer
    ::Load( CoreTools::BufferSource& source )
{
	RENDERING_CLASS_IS_VALID_1;    

	int numTotalBytes = 0;
	source.Read(numTotalBytes);

	if(numTotalBytes != 0)
	{
		m_Data = make_shared<FileBuffer>(numTotalBytes); 
		
		source.Read(boost::numeric_cast<int>(m_Data->GetSize()), m_Data->GetBufferBegin());
	}	
}

void Rendering::TextureBuffer
    ::Save( CoreTools::BufferTarget& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1; 
	
	if (m_Data != nullptr && m_Data->GetSize() != 0)
	{
		target.WriteWithNumber(boost::numeric_cast<int>(m_Data->GetSize()), m_Data->GetBufferBegin());
	}		
	else
	{
		target.Write(0);
	}		
}

int Rendering::TextureBuffer
    ::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(0);
    
	return m_Data != nullptr ? boost::numeric_cast<int>(m_Data->GetSize() + size) : size;
}

void Rendering::TextureBuffer
	::SaveToFile(WriteFileManager& outFile) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	outFile.Write(boost::numeric_cast<uint32_t>(m_ItemSize), boost::numeric_cast<uint32_t>(m_Data->GetSize() / m_ItemSize), m_Data->GetBufferBegin());
}

void Rendering::TextureBuffer
	::ReadFromFile( ReadFileManager& inFile )
{
	RENDERING_CLASS_IS_VALID_1;

	inFile.Read(m_ItemSize, boost::numeric_cast<uint32_t>(m_Data->GetSize() / m_ItemSize),m_Data->GetBufferBegin());
}

void Rendering::TextureBuffer
	::ExpandFileBufferSize(int newNumTotalBytes, int numLevel0Bytes)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(numLevel0Bytes <= boost::numeric_cast<int>(m_Data->GetSize()), "传入的等级0字节数太大。");
	
	FileBufferPtr fileBuffer{ make_shared<FileBuffer>(newNumTotalBytes) };
	
	memcpy(fileBuffer->GetBufferBegin(), GetReadOnlyData(), numLevel0Bytes);

	m_Data = fileBuffer;		
}

void Rendering::TextureBuffer
	::ExpandFileBufferSizeOnCube(int newNumTotalBytes, int numLevel0Bytes)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_0(numLevel0Bytes * 6u <= m_Data->GetSize(), "传入的等级0字节数太大。");

	auto oldNumTotalBytes = boost::numeric_cast<int>(m_Data->GetSize());

	FileBufferPtr fileBuffer{ make_shared<FileBuffer>(newNumTotalBytes) };

	for (auto face = 0; face < 6; ++face)
	{
		auto oldFaceOffset = face * oldNumTotalBytes / 6;
		auto faceOffset = face * newNumTotalBytes / 6;
		memcpy(fileBuffer->GetBufferBegin() + faceOffset,  GetReadOnlyData() + oldFaceOffset, numLevel0Bytes);
	}

	m_Data = fileBuffer;
}

int Rendering::TextureBuffer
	::GetSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Data->GetSize());
}



 