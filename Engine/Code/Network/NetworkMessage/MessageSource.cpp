//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 14:08)

#include "Network/NetworkExport.h"

#include "MessageBuffer.h"
#include "MessageSourceDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;
using std::vector;

Network::MessageSource::MessageSource(const MessageBufferSharedPtr& messageBuffer) noexcept
    : m_Source{ messageBuffer }, m_ParserStrategy{ messageBuffer->GetParserStrategy() }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageSource::MessageSource(MessageSource&& rhs) noexcept
    : m_Source{ std::move(rhs.m_Source) }, m_ParserStrategy{ rhs.m_ParserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageSource& Network::MessageSource::operator=(MessageSource&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    m_Source = std::move(rhs.m_Source);
    m_ParserStrategy = rhs.m_ParserStrategy;

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
bool Network::MessageSource::IsValid() const noexcept
{
    if (m_Source != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

bool Network::MessageSource::ReadBool()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    uint32_t value{ 0 };

    Read(value);

    return (value != 0);
}

void Network::MessageSource::ReadBool(int elementsNumber, bool* data)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

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
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

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

        const auto* const text = m_Source->GetCurrentReadBufferedPtr();
        string datum(text, length);

        m_Source->AddCurrentReadIndex(length + padding);

        return datum;
    }
    else
    {
        return string{};
    }
}

void Network::MessageSource::ReadString(int elementsNumber, string* data)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

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
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Source->GetCurrentReadIndex();
}

int Network::MessageSource::GetBytesTotal() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Source->GetCurrentWriteIndex();
}

void Network::MessageSource::IncrementBytesProcessed(int bytesNumber)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    m_Source->AddCurrentReadIndex(bytesNumber);
}

void Network::MessageSource::Read(vector<string>& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

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
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    datum = ReadString();
}
