/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:22)

#include "CoreTools/CoreToolsExport.h"

#include "BufferSourceDetail.h"
#include "ObjectInterface.h"
#include "StreamSize.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::BufferSource::BufferSource(const ConstFileBufferSharedPtr& fileBuffer)
    : source{ fileBuffer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferSource)

bool CoreTools::BufferSource::ReadBool()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    uint32_t value{ 0 };

    Read(value);

    return (value != 0);
}

void CoreTools::BufferSource::Read(bool& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = ReadBool();
}

std::string CoreTools::BufferSource::ReadString()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    int32_t length{ 0 };
    Read(length);

    if (0 < length)
    {
        /// 字符串被写入为4字节的倍数。
        auto padding = (length % gDefaultSize);
        if (0 < padding)
        {
            padding = gDefaultSize - padding;
        }

        auto datum = source.GetText(length);

        source.IncrementBytesProcessed(length + padding);

        return datum;
    }
    else
    {
        return std::string{};
    }
}

void CoreTools::BufferSource::Read(std::string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = ReadString();
}

void CoreTools::BufferSource::ReadBoolContainer(int elementsNumber, std::set<bool>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(ReadBool());
    }
}

void CoreTools::BufferSource::ReadStringContainer(int elementsNumber, std::set<std::string>& container)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    container.clear();

    for (auto i = 0; i < elementsNumber; ++i)
    {
        container.emplace(ReadString());
    }
}

int CoreTools::BufferSource::GetBytesRead() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return source.GetBytesProcessed();
}

int CoreTools::BufferSource::GetBytesTotal() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return source.GetBytesTotal();
}

void CoreTools::BufferSource::IncrementBytesProcessed(int bytesNumber)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    source.IncrementBytesProcessed(bytesNumber);
}

void CoreTools::BufferSource::ReadUniqueId(ObjectInterface& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto uniqueId = Read<int64_t>();
    object.SetUniqueId(uniqueId);
}

int32_t CoreTools::BufferSource::GetElementsNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return Read<int32_t>();
}
