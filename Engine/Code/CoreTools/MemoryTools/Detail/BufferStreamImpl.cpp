// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 11:58)

#include "CoreTools/CoreToolsExport.h"

#include "CoreTools/MemoryTools/Buffer.h"
#include "BufferStreamImpl.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/MemoryTools/BufferPool.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::vector;
using std::string;

CoreTools::BufferStreamImpl
	::BufferStreamImpl(BufferPool* pool, int minSize)
	:m_Pool{ pool }, m_OriginalMemoryLength{ minSize }, m_Buffer{}, m_StartDataPosition{ 0 },
	 m_DataLength{ 0 }, m_ReadPosition{ -1 }, m_ReadLength{ 0 }, m_TotalMemoryLength{ 0 }
{
	ResetData();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::BufferStreamImpl
	::BufferStreamImpl(BufferPool* pool)
	:m_Pool{ pool }, m_OriginalMemoryLength{ Buffer::GetMaxSize() }, m_Buffer{}, m_StartDataPosition{ 0 },
	 m_DataLength{ 0 }, m_ReadPosition{ -1 }, m_ReadLength{ 0 }, m_TotalMemoryLength{ 0 }
{
	ResetData();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::BufferStreamImpl
	::~BufferStreamImpl()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	Release();
}

// private
void CoreTools::BufferStreamImpl
	::Release()
{
	for (auto ptr : m_Buffer)
	{
		m_Pool->Release(ptr);
	}

	m_Buffer.clear();
	m_TotalMemoryLength = 0;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::BufferStreamImpl
	::IsValid() const noexcept
{
	if (0 < m_OriginalMemoryLength && m_OriginalMemoryLength <= Buffer::GetMaxSize() &&
		m_Pool != nullptr && 0 <= m_StartDataPosition &&
		0 <= m_DataLength && (-1 == m_ReadPosition || m_StartDataPosition <= m_ReadPosition) &&
		0 <= m_ReadLength && m_ReadLength <= m_DataLength &&
		m_StartDataPosition + m_DataLength <= m_TotalMemoryLength)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

void CoreTools::BufferStreamImpl
	::ResetData()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	Release();

	m_StartDataPosition = 0;
	m_DataLength = 0;
	m_ReadPosition = -1;
	m_ReadLength = 0;
	m_TotalMemoryLength = 0;

	Append(m_OriginalMemoryLength);
}

int CoreTools::BufferStreamImpl
	::GetOriginalMemoryLength() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_OriginalMemoryLength;
}

void CoreTools::BufferStreamImpl
	::Append(int minSize)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_2(0 <= minSize, "要增加的大小为负数！");

	AppendBuffer(minSize);
}

// private
void CoreTools::BufferStreamImpl
	::AppendBuffer(int minSize)
{
	if (minSize <= Buffer::GetMaxSize())
	{
		DoAppendBuffer(minSize);
	}
	else
	{
		auto appendTime = minSize / m_OriginalMemoryLength + 1;
		DoAppendBuffer(minSize, appendTime);
	}
}

// private
void CoreTools::BufferStreamImpl
	::DoAppendBuffer(int minSize)
{
	auto buffer = m_Pool->GetBuffer(minSize);

	m_Buffer.push_back(buffer);

	m_TotalMemoryLength += buffer->GetSize();
}

// private
void CoreTools::BufferStreamImpl
	::DoAppendBuffer(int minSize, int appendTime)
{
	for (auto i = 0; i < appendTime; ++i)
	{
		if (i != appendTime - 1)
		{
			DoAppendBuffer(m_OriginalMemoryLength);
		}
		else
		{
			DoAppendBuffer(minSize - m_OriginalMemoryLength * (appendTime - 1));
		}
	}
}

void CoreTools::BufferStreamImpl
	::SetDataLength(int newLength)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_DataLength = newLength;

	ExceedAppend();
}

// private
void CoreTools::BufferStreamImpl
	::ExceedAppend()
{
	auto exceedLength = m_StartDataPosition + m_DataLength - m_TotalMemoryLength + 1;

	if (0 < exceedLength)
	{
		AppendBuffer(exceedLength);
	}
}

void CoreTools::BufferStreamImpl
	::AddDataLength(int length)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_DataLength += length;

	ExceedAppend();
}

int CoreTools::BufferStreamImpl
	::GetDataLength() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_DataLength;
}

int CoreTools::BufferStreamImpl
	::GetTotalMemoryLength() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_TotalMemoryLength;
}

int CoreTools::BufferStreamImpl
	::GetRemainDataLength() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_TotalMemoryLength - m_StartDataPosition - m_DataLength;
}

void CoreTools::BufferStreamImpl
	::AdvanceDataStartPosition(int length)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_StartDataPosition += length;
	m_DataLength -= length;

	if (m_DataLength < 0)
	{
		m_DataLength = 0;
	}

	ExceedAppend();
}

void CoreTools::BufferStreamImpl
	::Set(int index, uint32_t data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Set(index, reinterpret_cast<const uint8_t*>(&data), sizeof(uint32_t));
}

void CoreTools::BufferStreamImpl
	::Set(int index, int32_t data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Set(index, reinterpret_cast<const uint8_t*>(&data), sizeof(int32_t));
}

void CoreTools::BufferStreamImpl
	::Set(int index, uint16_t data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Set(index, reinterpret_cast<const uint8_t*>(&data), sizeof(uint16_t));
}

void CoreTools::BufferStreamImpl
	::Set(int index, int16_t data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Set(index, reinterpret_cast<const uint8_t*>(&data), sizeof(int16_t));
}

void CoreTools::BufferStreamImpl
	::Set(int index, uint8_t data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Set(index, &data, sizeof(uint8_t));
}

void CoreTools::BufferStreamImpl
	::Set(int index, int8_t data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Set(index, reinterpret_cast<const uint8_t*>(&data), sizeof(int8_t));
}

void CoreTools::BufferStreamImpl
	::Set(int index, bool data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	auto value = static_cast<uint8_t>(data ? 1 : 0);

	return Set(index, &value, 1);
}

void CoreTools::BufferStreamImpl
	::Set(int index, const uint8_t* buffer, int bufferLength)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_0(m_StartDataPosition <= index && index < m_StartDataPosition + m_DataLength, "索引越界！");

	auto position = index;
	auto copyBufferLength = bufferLength;

	for (auto ptr : m_Buffer)
	{
		if (copyBufferLength <= 0)
			break;

		auto actualCopyBufferLength = DoSet(ptr, position, buffer, copyBufferLength);

		if (0 < actualCopyBufferLength)
		{
			buffer += actualCopyBufferLength;
			copyBufferLength -= actualCopyBufferLength;
			position = 0;
		}
		else
		{
			position -= ptr->GetSize();
		}
	}
}

// private
int CoreTools::BufferStreamImpl
	::DoSet(Buffer* ptr, int position, const uint8_t* buffer, int copyBufferLength)
{
	CORE_TOOLS_ASSERTION_2(0 < copyBufferLength, "要复制的数组大小小于或等于零！");

	if (0 <= position && position < ptr->GetSize())
	{
		auto actualCopyBufferLength = copyBufferLength;
		auto remainBufferLength = ptr->GetSize() - position;

		if (remainBufferLength < actualCopyBufferLength)
		{
			actualCopyBufferLength = remainBufferLength;
		}			

		System::MemoryCopy(ptr->GetMemory() + position, buffer, actualCopyBufferLength);

		return actualCopyBufferLength;
	}
	else
	{
		return 0;
	}
}

void CoreTools::BufferStreamImpl
	::Add(uint32_t data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Add(reinterpret_cast<const uint8_t*>(&data), sizeof(uint32_t));
}

void CoreTools::BufferStreamImpl
	::Add(int32_t data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Add(reinterpret_cast<const uint8_t*>(&data), sizeof(int32_t));
}

void CoreTools::BufferStreamImpl
	::Add(uint16_t data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Add(reinterpret_cast<const uint8_t*>(&data), sizeof(uint16_t));
}

void CoreTools::BufferStreamImpl
	::Add(int16_t data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Add(reinterpret_cast<const uint8_t*>(&data), sizeof(int16_t));
}

void CoreTools::BufferStreamImpl
	::Add(uint8_t data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Add(&data, sizeof(uint8_t));
}

void CoreTools::BufferStreamImpl
	::Add(int8_t data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return Add(reinterpret_cast<const uint8_t*>(&data), sizeof(int8_t));
}

void CoreTools::BufferStreamImpl
	::Add(bool data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	auto byteData = static_cast<uint8_t>(data ? 1 : 0);

	return Add(&byteData, 1);
}

void CoreTools::BufferStreamImpl
	::AddString(const string& data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	vector<uint8_t> byte{ data.begin(),data.end() };

	return Add(byte.data(), boost::numeric_cast<int>(byte.size()));
}

void CoreTools::BufferStreamImpl
	::AddTerminatedString(const string& data)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	vector<uint8_t> byte{ data.begin(),data.end() };
	byte.push_back(0);

	return Add(byte.data(), boost::numeric_cast<int>(byte.size()));
}

void CoreTools::BufferStreamImpl
	::Add(const uint8_t* buffer, int bufferLength)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	auto position = m_StartDataPosition + m_DataLength;

	auto exceedLength = position + bufferLength + 1 - m_TotalMemoryLength;

	if (0 < exceedLength)
	{
		Append(exceedLength);
	}

	m_DataLength += bufferLength;

	Set(position, buffer, bufferLength);
}

void CoreTools::BufferStreamImpl
	::InitRead() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_ReadPosition = m_StartDataPosition;

	m_ReadLength = m_DataLength;
}

void CoreTools::BufferStreamImpl
	::InitRead(int totalLength) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_0(totalLength <= m_DataLength, "读长度越界！");

	m_ReadPosition = m_StartDataPosition;

	m_ReadLength = totalLength;
}

int CoreTools::BufferStreamImpl
	::GetReadPosition() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_ReadPosition;
}

int CoreTools::BufferStreamImpl
	::GetReadableLength() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_ReadLength;
}

void CoreTools::BufferStreamImpl
	::SetReadPosition(int position)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_2(0 <= position && position < m_ReadLength, "设置的读位置为负数或越界！");

	m_ReadLength -= (m_StartDataPosition + position - m_ReadPosition);
	m_ReadPosition = m_StartDataPosition + position;
}

uint32_t CoreTools::BufferStreamImpl
	::ReadUInt32()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	uint32_t value{ 0 };

	Read(reinterpret_cast<uint8_t*>(&value), sizeof(uint32_t));

	return value;
}

int32_t CoreTools::BufferStreamImpl
	::ReadInt32()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	int32_t value{ 0 };

	Read(reinterpret_cast<uint8_t*>(&value), sizeof(int32_t));

	return value;
}

uint16_t CoreTools::BufferStreamImpl
	::ReadUInt16()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	uint16_t value{ 0 };

	Read(reinterpret_cast<uint8_t*>(&value), sizeof(uint16_t));

	return value;
}

int16_t CoreTools::BufferStreamImpl
	::ReadInt16()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	int16_t value{ 0 };

	Read(reinterpret_cast<uint8_t*>(&value), sizeof(int16_t));

	return value;
}

uint8_t CoreTools::BufferStreamImpl
	::ReadUInt8()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	uint8_t value{ 0 };

	Read(&value, sizeof(uint8_t));

	return value;
}

int8_t CoreTools::BufferStreamImpl
	::ReadInt8()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	int8_t value{ 0 };

	Read(reinterpret_cast<uint8_t*>(&value), sizeof(int8_t));

	return value;
}

bool CoreTools::BufferStreamImpl
	::ReadBool()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	uint8_t value{ 0 };

	Read(&value, 1);

	return value != 0;
}

void CoreTools::BufferStreamImpl
	::Read(uint8_t* buffer, int bufferLength)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	Peek(buffer, bufferLength);

	m_ReadPosition += bufferLength;
	m_ReadLength -= bufferLength;
}

uint32_t CoreTools::BufferStreamImpl
	::PeekUInt32()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	uint32_t value{ 0 };

	Peek(reinterpret_cast<uint8_t*>(&value), sizeof(uint32_t));

	return value;
}

int32_t CoreTools::BufferStreamImpl
	::PeekInt32()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	int32_t value{ 0 };

	Peek(reinterpret_cast<uint8_t*>(&value), sizeof(int32_t));

	return value;
}

uint16_t CoreTools::BufferStreamImpl
	::PeekUInt16()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	uint16_t value{ 0 };

	Peek(reinterpret_cast<uint8_t*>(&value), sizeof(uint16_t));

	return value;
}

int16_t CoreTools::BufferStreamImpl
	::PeekInt16()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	int16_t value{ 0 };

	Peek(reinterpret_cast<uint8_t*>(&value), sizeof(int16_t));

	return value;
}

uint8_t CoreTools::BufferStreamImpl
	::PeekUInt8()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	uint8_t value{ 0 };

	Peek(&value, sizeof(uint8_t));

	return value;
}

int8_t CoreTools::BufferStreamImpl
	::PeekInt8()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	int8_t value{ 0 };

	Peek(reinterpret_cast<uint8_t*>(&value), sizeof(int8_t));

	return value;
}

bool CoreTools::BufferStreamImpl
	::PeekBool()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	uint8_t value{ 0 };

	Peek(&value, 1);

	return value != 0;
}

void CoreTools::BufferStreamImpl
	::Peek(uint8_t* buffer, int bufferLength)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	auto position = m_ReadPosition;
	auto copyBufferLength = bufferLength;
	auto currentBuffer = buffer;

	for (const auto ptr : m_Buffer)
	{
		if (copyBufferLength <= 0)
			break;

		auto actualCopyBufferLength = DoPeek(ptr, position, currentBuffer, copyBufferLength);

		if (0 < actualCopyBufferLength)
		{
			currentBuffer += actualCopyBufferLength;
			copyBufferLength -= actualCopyBufferLength;
			position = 0;
		}
		else
		{
			position -= ptr->GetSize();
		}
	}
}

// private
int CoreTools::BufferStreamImpl
	::DoPeek(const Buffer* ptr, int position, uint8_t* buffer, int copyBufferLength)
{
	CORE_TOOLS_ASSERTION_2(0 < copyBufferLength, "要复制的数组大小小于或等于零！");

	if (0 <= position && position < ptr->GetSize())
	{
		auto actualCopyBufferLength = copyBufferLength;
		auto remainBufferLength = ptr->GetSize() - position;

		if (remainBufferLength < actualCopyBufferLength)
		{
			actualCopyBufferLength = remainBufferLength;
		}

		System::MemoryCopy(buffer, ptr->GetMemory() + position, actualCopyBufferLength);

		return actualCopyBufferLength;
	}
	else
	{
		return 0;
	}
}

