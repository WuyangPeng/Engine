//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 14:21)

#include "CoreTools/CoreToolsExport.h"

#include "Endian.h"
#include "System/Helper/PragmaWarning/Span.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <algorithm>

using std::swap;

bool CoreTools::Endian::IsLittleEndian()
{
    static constexpr auto g_One = 1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    static const bool sm_IsLittleEndian{ (*reinterpret_cast<const char*>(&g_One) != 0) };
#include STSTEM_WARNING_POP

#ifdef SYSTEM_LITTLE_ENDIAN
    CORE_TOOLS_ASSERTION_0(sm_IsLittleEndian, "这不是一个小端机器！");
#elif SYSTEM_BIG_ENDIAN
    CORE_TOOLS_ASSERTION_0(!sm_IsLittleEndian, "这不是一个大端机器！");
#endif  // SYSTEM_LITTLE_ENDIAN

    return sm_IsLittleEndian;
}

bool CoreTools::Endian::IsBigEndian()
{
    return !IsLittleEndian();
}

void CoreTools::Endian::Swap2ByteOrder(void* data) noexcept
{
    auto bytes = static_cast<uint8_t*>(data);

    if (bytes != nullptr)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        swap(bytes[0], bytes[1]);
#include STSTEM_WARNING_POP
    }
}

void CoreTools::Endian::Swap2ByteOrder(size_t itemsNumber, void* data) noexcept
{
    if (data != nullptr && 0 < itemsNumber)
    {
        const gsl::span<uint16_t> bytes{ static_cast<uint16_t*>(data), itemsNumber };
        for (auto& value : bytes)
        {
            Swap2ByteOrder(&value);
        }
    }
}

void CoreTools::Endian::Swap4ByteOrder(void* data) noexcept
{
    auto bytes = static_cast<uint8_t*>(data);

    if (bytes != nullptr)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        swap(bytes[0], bytes[3]);
        swap(bytes[1], bytes[2]);
#include STSTEM_WARNING_POP
    }
}

void CoreTools::Endian::Swap4ByteOrder(size_t itemsNumber, void* data) noexcept
{
    if (data != nullptr && 0 < itemsNumber)
    {
        const gsl::span<uint32_t> bytes{ static_cast<uint32_t*>(data), itemsNumber };
        for (auto& value : bytes)
        {
            Swap4ByteOrder(&value);
        }
    }
}

void CoreTools::Endian::Swap8ByteOrder(void* data) noexcept
{
    auto bytes = static_cast<uint8_t*>(data);

    if (bytes != nullptr)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        swap(bytes[0], bytes[7]);
        swap(bytes[1], bytes[6]);
        swap(bytes[2], bytes[5]);
        swap(bytes[3], bytes[4]);
#include STSTEM_WARNING_POP
    }
}

void CoreTools::Endian::Swap8ByteOrder(size_t itemsNumber, void* data) noexcept
{
    if (data != nullptr && 0 < itemsNumber)
    {
        const gsl::span<uint64_t> bytes{ static_cast<uint64_t*>(data), itemsNumber };
        for (auto& value : bytes)
        {
            Swap8ByteOrder(&value);
        }
    }
}

void CoreTools::Endian::SwapByteOrder(int itemSize, void* data)
{
    CORE_TOOLS_ASSERTION_0(data != nullptr, "指针无效！");
    CORE_TOOLS_ASSERTION_2(itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为2，4或8\n");

    const auto halfSize = itemSize / 2;
    auto bytes = static_cast<char*>(data);

    for (auto begin = 0, end = itemSize - 1; begin < halfSize; ++begin, --end)
    {
        if (bytes != nullptr)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
            swap(bytes[begin], bytes[end]);
#include STSTEM_WARNING_POP
        }
    }
}

void CoreTools::Endian::SwapByteOrder(int itemSize, int itemsNumber, void* data)
{
    CORE_TOOLS_ASSERTION_0(data != nullptr, "指针无效！");
    CORE_TOOLS_ASSERTION_2(0 < itemsNumber, "itemsNumber必须大于零！");
    CORE_TOOLS_ASSERTION_2(itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为2，4或8\n");

    auto bytes = static_cast<char*>(data);

    for (auto i = 0; i < itemsNumber; ++i)
    {
        SwapByteOrder(itemSize, bytes);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        bytes += itemSize;
#include STSTEM_WARNING_POP
    }
}

void CoreTools::Endian::Swap2ByteOrderToTarget(int itemsNumber, const uint16_t* source, uint16_t* target)
{
    CORE_TOOLS_ASSERTION_0(source != nullptr, "指针无效！");
    CORE_TOOLS_ASSERTION_2(0 < itemsNumber, "itemsNumber必须大于零！");
    CORE_TOOLS_ASSERTION_0(target != nullptr, "指针无效！");

    System::MemoryCopy(target, source, itemsNumber * sizeof(uint16_t));

    Endian::Swap2ByteOrder(itemsNumber, target);
}

void CoreTools::Endian::Swap4ByteOrderToTarget(int itemsNumber, const uint32_t* source, uint32_t* target)
{
    CORE_TOOLS_ASSERTION_0(source != nullptr, "指针无效！");
    CORE_TOOLS_ASSERTION_2(0 < itemsNumber, "itemsNumber必须大于零！");
    CORE_TOOLS_ASSERTION_0(target != nullptr, "指针无效！");

    System::MemoryCopy(target, source, itemsNumber * sizeof(uint32_t));

    Endian::Swap4ByteOrder(itemsNumber, target);
}

void CoreTools::Endian::Swap8ByteOrderToTarget(int itemsNumber, const uint64_t* source, uint64_t* target)
{
    CORE_TOOLS_ASSERTION_0(source != nullptr, "指针无效！");
    CORE_TOOLS_ASSERTION_2(0 < itemsNumber, "itemsNumber必须大于零！");
    CORE_TOOLS_ASSERTION_0(target != nullptr, "指针无效！");

    System::MemoryCopy(target, source, itemsNumber * sizeof(uint64_t));

    Endian::Swap8ByteOrder(itemsNumber, target);
}
