//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/22 14:59)

#include "CoreTools/CoreToolsExport.h"

#include "BufferSourceDetail.h"
#include "ObjectInterface.h"
#include "StreamSize.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

CoreTools::BufferSource::BufferSource(const ConstFileBufferSharedPtr& fileBuffer)
    : m_Source{ fileBuffer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferSource)

bool CoreTools::BufferSource::ReadBool()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    uint32_t value{ 0 };

    Read(value);

    return (value != 0);
}

void CoreTools::BufferSource::Read(bool& value)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    value = ReadBool();
}

string CoreTools::BufferSource::ReadString()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    int32_t length{ 0 };
    Read(length);

    if (0 < length)
    {
        // �ַ�����д��Ϊ4�ֽڵı�����
        auto padding = (length % g_DefaultSize);
        if (0 < padding)
        {
            padding = g_DefaultSize - padding;
        }

        string datum = m_Source.GetText(length);

        m_Source.IncrementBytesProcessed(length + padding);

        return datum;
    }
    else
    {
        return string{};
    }
}

void CoreTools::BufferSource::Read(string& value)
{
    value = ReadString();
}

void CoreTools::BufferSource::ReadBoolContainer(int elementsNumber, std::set<bool>& container)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(ReadBool());
    }
}

void CoreTools::BufferSource::ReadStringContainer(int elementsNumber, std::set<std::string>& container)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(ReadString());
    }
}

int CoreTools::BufferSource::GetBytesRead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Source.GetBytesProcessed();
}

int CoreTools::BufferSource::GetBytesTotal() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Source.GetBytesTotal();
}

void CoreTools::BufferSource::IncrementBytesProcessed(int bytesNumber) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    m_Source.IncrementBytesProcessed(bytesNumber);
}

void CoreTools::BufferSource::ReadUniqueID(const ObjectInterfaceSharedPtr& object)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto modify = object;

    auto uniqueID = Read<uint64_t>();
    modify->SetUniqueID(uniqueID);
}

int32_t CoreTools::BufferSource::GetElementsNumber()
{
    return Read<int32_t>();
}
