//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 14:10)

#include "Network/NetworkExport.h"

#include "MessageTargetDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <array>

using std::array;
using std::string;
using std::vector;

Network::MessageTarget::MessageTarget(const MessageBufferSharedPtr& messageBuffer) noexcept
    : m_Target{ messageBuffer }, m_ParserStrategy{ messageBuffer->GetParserStrategy() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageTarget::MessageTarget(MessageTarget&& rhs) noexcept
    : m_Target{ std::move(rhs.m_Target) }, m_ParserStrategy{ rhs.m_ParserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageTarget& Network::MessageTarget::operator=(MessageTarget&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    m_Target = std::move(rhs.m_Target);
    m_ParserStrategy = rhs.m_ParserStrategy;

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageTarget)

void Network::MessageTarget::WriteBool(const bool datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const uint8_t value{ datum ? 1u : 0u };
    Write(value);
}

void Network::MessageTarget::WriteBoolWithNumber(int32_t elementsNumber, const bool* data)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(elementsNumber);
    WriteBoolWithoutNumber(elementsNumber, data);
}

void Network::MessageTarget::WriteBoolWithoutNumber(int32_t elementsNumber, const bool* data)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (data != nullptr)
    {
        for (auto i = 0; i < elementsNumber; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            WriteBool(data[i]);
#include STSTEM_WARNING_POP
        }
    }
}

void Network::MessageTarget::WriteString(const string& datum)
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

void Network::MessageTarget::WriteStringWithNumber(int32_t elementsNumber, const string* data)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    Write(elementsNumber);
    WriteStringWithoutNumber(elementsNumber, data);
}

void Network::MessageTarget::WriteStringWithoutNumber(int32_t elementsNumber, const string* data)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (data != nullptr)
    {
        for (auto i = 0; i < elementsNumber; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            WriteString(data[i]);
#include STSTEM_WARNING_POP
        }
    }
}

int Network::MessageTarget::GetBytesWritten() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Target->GetCurrentWriteIndex();
}

void Network::MessageTarget::Write(const vector<string>& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto elementsNumber = boost::numeric_cast<int>(datum.size());

    Write(elementsNumber);
    if (0 < elementsNumber)
    {
        WriteStringWithoutNumber(elementsNumber, datum.data());
    }
}

void Network::MessageTarget::Write(const string& datum)
{
    return WriteString(datum);
}
