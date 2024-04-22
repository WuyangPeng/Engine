/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:43)

#include "CoreTools/CoreToolsExport.h"

#include "CheckItemSize.h"
#include "ReadBufferIOImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/FileManager/Flags/BufferIOFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ReadBufferIOImpl::ReadBufferIOImpl(const ConstFileBufferSharedPtr& fileBuffer) noexcept
    : ParentType{}, buffer{ fileBuffer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::ReadBufferIOImpl::IsValid() const noexcept
{
    return ParentType::IsValid() && buffer != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::ReadBufferIOImpl::Read(size_t itemSize, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CheckItemSize(itemSize);
    CORE_TOOLS_ASSERTION_0(data != nullptr, "数据无效");

    ReadFromBuffer(itemSize, 1, data);
}

void CoreTools::ReadBufferIOImpl::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CheckItemSize(itemSize);
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "数据无效");

    ReadFromBuffer(itemSize, itemsNumber, data);
}

int CoreTools::ReadBufferIOImpl::ReadFromBuffer(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CheckItemSize(itemSize);
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "准备写入的数据无效！");
    CORE_TOOLS_ASSERTION_2(GetBufferIOType() == BufferIO::Read, "缓冲区不支持读取！");

    const auto numberToCopy = boost::numeric_cast<int>(itemSize * itemsNumber);

    if (const auto nextBytesProcessed = GetBytesProcessed() + numberToCopy;
        nextBytesProcessed <= GetBytesTotal())
    {
        /// 获得缓冲区当前指针位置。
        const auto source = buffer->GetBuffer(GetBytesProcessed());

        SetBytesProcessed(nextBytesProcessed);

        System::MemoryCopy(data, source, numberToCopy);

#ifdef SYSTEM_BIG_ENDIAN

        if (1 < itemSize)
        {
            Endian::SwapByteOrder(itemSize, itemsNumber, data);
        }

#endif  // SYSTEM_BIG_ENDIAN

        return numberToCopy;
    }
    else
    {
        THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("要读取的字节数%1%超过了缓冲区大小%2%！原字节数为：%3%")) % numberToCopy % GetBytesTotal() % GetBytesProcessed()).str())
    }
}

std::string CoreTools::ReadBufferIOImpl::GetText(int length) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (const auto nextProcessed = GetBytesProcessed() + length;
        nextProcessed <= buffer->GetSize())
    {
        const auto text = buffer->GetBuffer(GetBytesProcessed());
        std::string datum{ text, boost::numeric_cast<size_t>(length) };

        return datum;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("要读取的字节数超过了缓冲区大小！"s))
    }
}

int CoreTools::ReadBufferIOImpl::GetBytesTotal() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(buffer->GetSize());
}

CoreTools::BufferIO CoreTools::ReadBufferIOImpl::GetBufferIOType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return BufferIO::Read;
}
