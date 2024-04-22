/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:46)

#include "CoreTools/CoreToolsExport.h"

#include "CheckItemSize.h"
#include "WriteBufferIOImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/FileManager/Flags/BufferIOFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::WriteBufferIOImpl::WriteBufferIOImpl(int bufferSize)
    : ParentType{}, buffer{ std::make_shared<FileBuffer>(bufferSize) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::WriteBufferIOImpl::IsValid() const noexcept
{
    return ParentType::IsValid() && buffer != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::WriteBufferIOImpl::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CheckItemSize(itemSize);
    CORE_TOOLS_ASSERTION_0(data != nullptr, "数据无效");

    WriteToBuffer(itemSize, 1, data);
}

void CoreTools::WriteBufferIOImpl::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CheckItemSize(itemSize);
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "数据无效");

    WriteToBuffer(itemSize, itemsNumber, data);
}

uint32_t CoreTools::WriteBufferIOImpl::WriteToBuffer(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CheckItemSize(itemSize);
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "准备读取的数据无效！");
    CORE_TOOLS_ASSERTION_2(GetBufferIOType() == BufferIO::Write, "缓冲区不支持写入！");

    const auto numberToCopy = boost::numeric_cast<int>(itemSize * itemsNumber);

    if (const auto nextBytesProcessed = GetBytesProcessed() + numberToCopy;
        nextBytesProcessed <= GetBytesTotal())
    {
        /// 获得缓冲区当前指针位置。
        auto target = buffer->GetBuffer(GetBytesProcessed());

        SetBytesProcessed(nextBytesProcessed);
        System::MemoryCopy(target, data, numberToCopy);

#ifdef SYSTEM_BIG_ENDIAN

        if (1 < itemSize)
        {
            Endian::SwapByteOrder(itemSize, itemsNumber, target);
        }

#endif  // SYSTEM_BIG_ENDIAN

        return numberToCopy;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("要写入的字节数超过了缓冲区大小！"s))
    }
}

int CoreTools::WriteBufferIOImpl::GetBytesTotal() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(buffer->GetSize());
}

CoreTools::BufferIO CoreTools::WriteBufferIOImpl::GetBufferIOType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return BufferIO::Write;
}

CoreTools::ConstFileBufferSharedPtr CoreTools::WriteBufferIOImpl::GetFileBuffer() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return buffer;
}
