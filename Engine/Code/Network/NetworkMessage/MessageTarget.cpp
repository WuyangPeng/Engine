///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/19 10:28)

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
    : target{ messageBuffer }, parserStrategy{ messageBuffer->GetParserStrategy() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageTarget::MessageTarget(MessageTarget&& rhs) noexcept
    : target{ std::move(rhs.target) }, parserStrategy{ rhs.parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageTarget& Network::MessageTarget::operator=(MessageTarget&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    if (this != &rhs)
    {
        target = std::move(rhs.target);
        parserStrategy = rhs.parserStrategy;
    }

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageTarget)

void Network::MessageTarget::WriteBool(const bool datum)
{
    NETWORK_CLASS_IS_VALID_1;

    const uint32_t value{ datum ? 1u : 0u };
    Write(value);
}

void Network::MessageTarget::WriteBoolWithNumber(int32_t elementsNumber, const bool* data)
{
    NETWORK_CLASS_IS_VALID_1;

    Write(elementsNumber);
    WriteBoolWithoutNumber(elementsNumber, data);
}

void Network::MessageTarget::WriteBoolWithoutNumber(int32_t elementsNumber, const bool* data)
{
    NETWORK_CLASS_IS_VALID_1;

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
    NETWORK_CLASS_IS_VALID_1;

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
    NETWORK_CLASS_IS_VALID_1;

    Write(elementsNumber);
    WriteStringWithoutNumber(elementsNumber, data);
}

void Network::MessageTarget::WriteStringWithoutNumber(int32_t elementsNumber, const string* data)
{
    NETWORK_CLASS_IS_VALID_1;

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
    NETWORK_CLASS_IS_VALID_CONST_1;

    return target->GetCurrentWriteIndex();
}

void Network::MessageTarget::Write(const vector<string>& datum)
{
    NETWORK_CLASS_IS_VALID_1;

    auto elementsNumber = boost::numeric_cast<int>(datum.size());

    Write(elementsNumber);
    if (0 < elementsNumber)
    {
        WriteStringWithoutNumber(elementsNumber, datum.data());
    }
}

void Network::MessageTarget::Write(const string& datum)
{
    NETWORK_CLASS_IS_VALID_1;

    return WriteString(datum);
}
