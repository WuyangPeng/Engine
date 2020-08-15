// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 16:36)

#include "Network/NetworkExport.h"

#include "MessageTargetDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <array>

using std::array;
using std::string;
using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26446)
Network::MessageTarget
	::MessageTarget(const MessageBufferSharedPtr& messageBuffer) noexcept
	:m_Target{ messageBuffer }, m_ParserStrategy{ messageBuffer->GetParserStrategy() }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageTarget
	::MessageTarget(MessageTarget&& rhs) noexcept
	:m_Target{ move(rhs.m_Target) }, m_ParserStrategy{ rhs.m_ParserStrategy }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageTarget& Network::MessageTarget
	::operator=(MessageTarget&& rhs) noexcept
{
	NETWORK_CLASS_IS_VALID_1;

	m_Target = move(rhs.m_Target);
	m_ParserStrategy = rhs.m_ParserStrategy;

	return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageTarget)

void Network::MessageTarget
	::WriteBool(const bool datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	const uint32_t value{ datum ? 0xFFFFFFFFu : 0u };
	Write(value);
}

void Network::MessageTarget
	::WriteBoolWithNumber(int32_t elementsNumber, const bool* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	Write(elementsNumber);
	WriteBoolWithoutNumber(elementsNumber, data);
}

void Network::MessageTarget
	::WriteBoolWithoutNumber(int32_t elementsNumber, const bool* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		WriteBool(data[i]);
	}
}

void Network::MessageTarget
	::WriteString(const string& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto length = boost::numeric_cast<int>(datum.size());
	Write(length);

	if (0 < length)
	{
		WriteWithoutNumber(boost::numeric_cast<int>(length), datum.c_str());

		// 字符串被写入为4字节的倍数。
		constexpr auto alignmentByte = 4;
		constexpr array<char, alignmentByte> zero{};
		auto padding = length % alignmentByte;
		if (0 < padding)
		{
			padding = alignmentByte - padding;
			WriteWithoutNumber(padding, zero.data());
		}
	}
}

void Network::MessageTarget
	::WriteStringWithNumber(int32_t elementsNumber, const string* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	Write(elementsNumber);
	WriteStringWithoutNumber(elementsNumber, data);
}

void Network::MessageTarget
	::WriteStringWithoutNumber(int32_t elementsNumber, const string* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	for (auto i = 0; i < elementsNumber; ++i)
	{
		WriteString(data[i]);
	}
}

int Network::MessageTarget
	::GetBytesWritten() const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Target->GetCurrentWriteIndex();
}

void Network::MessageTarget
	::Write(const vector<string>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto elementsNumber = boost::numeric_cast<int>(datum.size());

	Write(elementsNumber);
	if (0 < elementsNumber)
	{
		WriteStringWithoutNumber(elementsNumber, &datum[0]);
	}
}

void Network::MessageTarget
	::Write(const string& datum)
{
	return WriteString(datum);
}


#include STSTEM_WARNING_POP