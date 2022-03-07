///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/19 10:26)

#include "Network/NetworkExport.h"

#include "MessageBuffer.h"
#include "MessageSourceDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;
using std::vector;

Network::MessageSource::MessageSource(const MessageBufferSharedPtr& messageBuffer) noexcept
    : source{ messageBuffer }, parserStrategy{ messageBuffer->GetParserStrategy() }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageSource::MessageSource(MessageSource&& rhs) noexcept
    : source{ std::move(rhs.source) }, parserStrategy{ rhs.parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageSource& Network::MessageSource::operator=(MessageSource&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    if (this != &rhs)
    {
        source = std::move(rhs.source);
        parserStrategy = rhs.parserStrategy;
    }

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

bool Network::MessageSource::IsValid() const noexcept
{
    if (source != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

bool Network::MessageSource::ReadBool()
{
    NETWORK_CLASS_IS_VALID_1;

    uint32_t value{ 0 };

    Read(value);

    return (value != 0);
}

void Network::MessageSource::ReadBool(int elementsNumber, bool* data)
{
    NETWORK_CLASS_IS_VALID_1;

    if (data != nullptr)
    {
        for (auto i = 0; i < elementsNumber; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            data[i] = ReadBool();
#include STSTEM_WARNING_POP
        }
    }
}

string Network::MessageSource::ReadString()
{
    NETWORK_CLASS_IS_VALID_1;

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

        const auto* const text = source->GetCurrentReadBufferedPtr();
        string datum(text, length);

        source->AddCurrentReadIndex(length + padding);

        return datum;
    }
    else
    {
        return string{};
    }
}

void Network::MessageSource::ReadString(int elementsNumber, string* data)
{
    NETWORK_CLASS_IS_VALID_1;

    if (data != nullptr)
    {
        for (auto i = 0; i < elementsNumber; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            data[i] = ReadString();
#include STSTEM_WARNING_POP
        }
    }
}

int Network::MessageSource::GetBytesRead() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return source->GetCurrentReadIndex();
}

int Network::MessageSource::GetBytesTotal() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return source->GetCurrentWriteIndex();
}

void Network::MessageSource::IncrementBytesProcessed(int bytesNumber)
{
    NETWORK_CLASS_IS_VALID_1;

    source->AddCurrentReadIndex(bytesNumber);
}

void Network::MessageSource::Read(vector<string>& datum)
{
    NETWORK_CLASS_IS_VALID_1;

    int32_t elementsNumber{ 0 };
    Read(elementsNumber);

    if (0 < elementsNumber)
    {
        datum.resize(elementsNumber);
        ReadString(elementsNumber, datum.data());
    }
}

void Network::MessageSource::Read(string& datum)
{
    NETWORK_CLASS_IS_VALID_1;

    datum = ReadString();
}
