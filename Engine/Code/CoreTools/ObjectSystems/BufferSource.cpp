// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:50)

#include "CoreTools/CoreToolsExport.h"

#include "BufferSource.h"
#include "StreamSize.h"
#include "ObjectInterface.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;

CoreTools::BufferSource
	::BufferSource(const FileBufferPtr& fileBufferPtr)
	:m_Source{ boost::numeric_cast<int>(fileBufferPtr->GetSize()), fileBufferPtr->GetBufferBegin() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::BufferSource
	::~BufferSource()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferSource)

bool CoreTools::BufferSource
	::ReadBool()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	uint32_t value{ 0 };

	m_Source.Read(sizeof(uint32_t), &value);

	return (value != 0);
}

void CoreTools::BufferSource
	::ReadBool(int elementsNumber, bool* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		data[i] = ReadBool();
	}
}

string CoreTools::BufferSource
	::ReadString()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	int32_t length{ 0 };
	m_Source.Read(sizeof(int32_t), &length);
	if (0 < length)
	{
		// 字符串被写入为4字节的倍数。
		auto padding = (length % g_DefaultSize);
		if (0 < padding)
		{
			padding = g_DefaultSize - padding;
		}

		auto text = m_Source.GetBuffer() + m_Source.GetBytesProcessed();
		string datum{ text,boost::numeric_cast<size_t>(length) };

		m_Source.IncrementBytesProcessed(length + padding);

		return datum;
	}
	else
	{
		return "";
	}
}

void CoreTools::BufferSource
	::ReadString(int elementsNumber, string* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		data[i] = ReadString();
	}
}

int CoreTools::BufferSource
	::GetBytesRead() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Source.GetBytesProcessed();
}

int CoreTools::BufferSource
	::GetBytesTotal() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Source.GetBytesTotal();
}

void CoreTools::BufferSource
	::IncrementBytesProcessed(int bytesNumber)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_Source.IncrementBytesProcessed(bytesNumber);
}

void CoreTools::BufferSource
	::ReadUniqueID(ObjectInterfaceSmartPointer& object)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	uint64_t uniqueID{ 0 };
	m_Source.Read(sizeof(uint64_t), &uniqueID);
	object->SetUniqueID(uniqueID);
}

