///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:54)

#include "Network/NetworkExport.h"

#include "MessageBuffer.h"
#include "MessageSourceDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::MessageSource::MessageSource(MessageBuffer& messageBuffer) noexcept
    : source{ messageBuffer }, parserStrategy{ messageBuffer.GetParserStrategy() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageSource::MessageSource(MessageSource&& rhs) noexcept
    : source{ rhs.source }, parserStrategy{ rhs.parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::MessageSource& Network::MessageSource::operator=(MessageSource&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        source = std::move(rhs.source);
        parserStrategy = rhs.parserStrategy;
    }

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageSource)

bool Network::MessageSource::ReadBool()
{
    NETWORK_CLASS_IS_VALID_9;

    int32_t value{ 0 };
    Read(value);

    return (value != 0);
}

void Network::MessageSource::ReadBool(int elementsNumber, bool* data)
{
    NETWORK_CLASS_IS_VALID_9;

    if (data != nullptr)
    {
        for (auto i = 0; i < elementsNumber; ++i)
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            data[i] = ReadBool();

#include SYSTEM_WARNING_POP
        }
    }
}

std::string Network::MessageSource::ReadString()
{
    NETWORK_CLASS_IS_VALID_9;

    int32_t length{ 0 };
    Read(length);
    if (0 < length)
    {
        // 字符串被写入为4字节的倍数。
        auto padding = (length % 4);
        if (0 < padding)
        {
            padding = 4 - padding;
        }

        const auto* const text = source.GetCurrentReadBufferedPtr();
        std::string datum(text, length);

        source.AddCurrentReadIndex(length + padding);

        return datum;
    }
    else
    {
        return std::string{};
    }
}

void Network::MessageSource::ReadString(int elementsNumber, std::string* data)
{
    NETWORK_CLASS_IS_VALID_9;

    if (data != nullptr)
    {
        for (auto i = 0; i < elementsNumber; ++i)
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            data[i] = ReadString();

#include SYSTEM_WARNING_POP
        }
    }
}

int Network::MessageSource::GetBytesRead() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return source.GetCurrentReadIndex();
}

int Network::MessageSource::GetBytesTotal() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return source.GetCurrentWriteIndex();
}

void Network::MessageSource::IncrementBytesProcessed(int bytesNumber)
{
    NETWORK_CLASS_IS_VALID_9;

    source.AddCurrentReadIndex(bytesNumber);
}

void Network::MessageSource::Read(std::vector<std::string>& datum)
{
    NETWORK_CLASS_IS_VALID_9;

    int32_t elementsNumber{ 0 };
    Read(elementsNumber);

    if (0 < elementsNumber)
    {
        datum.resize(elementsNumber);
        ReadString(elementsNumber, datum.data());
    }
}

void Network::MessageSource::Read(std::string& datum)
{
    NETWORK_CLASS_IS_VALID_9;

    datum = ReadString();
}
