///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/03 14:21)

#include "CoreTools/CoreToolsExport.h"

#include "ReadBufferIOImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/FileManager/Flags/BufferIOFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

CoreTools::ReadBufferIOImpl::ReadBufferIOImpl(const ConstFileBufferSharedPtr& fileBuffer) noexcept
    : ParentType{}, buffer{ fileBuffer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ReadBufferIOImpl::IsValid() const noexcept
{
    if (ParentType::IsValid() && buffer != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void CoreTools::ReadBufferIOImpl::Read(size_t itemSize, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(data != nullptr, "数据无效");

    ReadFromBuffer(itemSize, 1, data);
}

void CoreTools::ReadBufferIOImpl::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "数据无效");

    ReadFromBuffer(itemSize, itemsNumber, data);
}

int CoreTools::ReadBufferIOImpl::ReadFromBuffer(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    CORE_TOOLS_ASSERTION_0(0 < itemsNumber && data != nullptr, "准备写入的数据无效！");
    CORE_TOOLS_ASSERTION_2(GetBufferIOType() == BufferIO::Read, "缓冲区不支持读取！");

    auto numberToCopy = boost::numeric_cast<int>(itemSize * itemsNumber);
    auto nextBytesProcessed = GetBytesProcessed() + numberToCopy;
    if (nextBytesProcessed <= GetBytesTotal())
    {
        // 获得缓冲区当前指针位置。
        auto source = buffer->GetBuffer(GetBytesProcessed());

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
        THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("要读取的字节数%1%超过了缓冲区大小%2%！原字节数为：%3%")) % numberToCopy % GetBytesTotal() % GetBytesProcessed()).str());
    }
}

std::string CoreTools::ReadBufferIOImpl::GetText(int length) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto nextProcessed = boost::numeric_cast<size_t>(GetBytesProcessed() + length);

    if (nextProcessed <= buffer->GetSize())
    {
        auto text = buffer->GetBuffer(GetBytesProcessed());
        std::string datum{ text, boost::numeric_cast<size_t>(length) };

        return datum;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("要读取的字节数超过了缓冲区大小！"s));
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
