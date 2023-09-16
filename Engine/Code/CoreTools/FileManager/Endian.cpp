///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:40)

#include "CoreTools/CoreToolsExport.h"

#include "Endian.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/span>
#include <algorithm>

bool CoreTools::Endian::IsLittleEndian() noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    static constexpr auto one = 1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    static const auto isLittleEndian = (*reinterpret_cast<const char*>(&one) != 0);

#include SYSTEM_WARNING_POP

#ifdef SYSTEM_LITTLE_ENDIAN

    CORE_TOOLS_ASSERTION_0(isLittleEndian, "这不是一个小端机器！");

#elif SYSTEM_BIG_ENDIAN

    CORE_TOOLS_ASSERTION_0(!isLittleEndian, "这不是一个大端机器！");

#endif  // SYSTEM_LITTLE_ENDIAN

    return isLittleEndian;
}

bool CoreTools::Endian::IsBigEndian() noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    return !IsLittleEndian();
}

void CoreTools::Endian::Swap2ByteOrder(void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    SwapByteOrder(2, data);
}

void CoreTools::Endian::Swap2ByteOrder(size_t itemsNumber, void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    if (data != nullptr && 0 < itemsNumber)
    {
        for (const gsl::span bytes{ static_cast<uint16_t*>(data), itemsNumber }; auto& value : bytes)
        {
            Swap2ByteOrder(&value);
        }
    }
}

void CoreTools::Endian::Swap4ByteOrder(void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    SwapByteOrder(4, data);
}

void CoreTools::Endian::Swap4ByteOrder(size_t itemsNumber, void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    if (data != nullptr && 0 < itemsNumber)
    {
        for (const gsl::span bytes{ static_cast<uint32_t*>(data), itemsNumber }; auto& value : bytes)
        {
            Swap4ByteOrder(&value);
        }
    }
}

void CoreTools::Endian::Swap8ByteOrder(void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    SwapByteOrder(8, data);
}

void CoreTools::Endian::Swap8ByteOrder(size_t itemsNumber, void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    if (data != nullptr && 0 < itemsNumber)
    {
        for (const gsl::span bytes{ static_cast<uint64_t*>(data), itemsNumber }; auto& value : bytes)
        {
            Swap8ByteOrder(&value);
        }
    }
}

void CoreTools::Endian::SwapByteOrder(size_t itemSize, void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    CORE_TOOLS_ASSERTION_0(data != nullptr, "指针无效！");
    CORE_TOOLS_ASSERTION_2(itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为2，4或8\n");

    const gsl::span bytes{ static_cast<uint8_t*>(data), itemSize };

    const auto halfSize = itemSize / 2;

    for (size_t begin{ 0u }; begin < halfSize; ++begin)
    {
        std::swap(bytes[begin], bytes[itemSize - begin - 1]);
    }
}

void CoreTools::Endian::SwapByteOrder(size_t itemSize, size_t itemsNumber, void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    CORE_TOOLS_ASSERTION_0(data != nullptr, "指针无效！");
    CORE_TOOLS_ASSERTION_2(0 < itemsNumber, "itemsNumber必须大于零！");
    CORE_TOOLS_ASSERTION_2(itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为2，4或8\n");

    const gsl::span bytes{ static_cast<uint8_t*>(data), itemsNumber * itemSize };

    for (auto index = 0u; index < itemsNumber; ++index)
    {
        SwapByteOrder(itemSize, &bytes[index * itemSize]);
    }
}

void CoreTools::Endian::Swap2ByteOrderToTarget(size_t itemsNumber, const uint16_t* source, uint16_t* target) noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    CORE_TOOLS_ASSERTION_2(0 < itemsNumber, "itemsNumber必须大于零！");
    CORE_TOOLS_ASSERTION_0(source != nullptr, "指针无效！");
    CORE_TOOLS_ASSERTION_0(target != nullptr, "指针无效！");

    System::MemoryCopy(target, source, boost::numeric_cast<uint32_t>(itemsNumber * sizeof(uint16_t)));

    Swap2ByteOrder(itemsNumber, target);
}

void CoreTools::Endian::Swap4ByteOrderToTarget(size_t itemsNumber, const uint32_t* source, uint32_t* target) noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    CORE_TOOLS_ASSERTION_2(0 < itemsNumber, "itemsNumber必须大于零！");
    CORE_TOOLS_ASSERTION_0(source != nullptr, "指针无效！");
    CORE_TOOLS_ASSERTION_0(target != nullptr, "指针无效！");

    System::MemoryCopy(target, source, boost::numeric_cast<uint32_t>(itemsNumber * sizeof(uint32_t)));

    Swap4ByteOrder(itemsNumber, target);
}

void CoreTools::Endian::Swap8ByteOrderToTarget(size_t itemsNumber, const uint64_t* source, uint64_t* target) noexcept(gAssert < 0 || gCoreToolsAssert < 0)
{
    CORE_TOOLS_ASSERTION_2(0 < itemsNumber, "itemsNumber必须大于零！");
    CORE_TOOLS_ASSERTION_0(source != nullptr, "指针无效！");
    CORE_TOOLS_ASSERTION_0(target != nullptr, "指针无效！");

    System::MemoryCopy(target, source, boost::numeric_cast<uint32_t>(itemsNumber * sizeof(uint64_t)));

    Swap8ByteOrder(itemsNumber, target);
}
