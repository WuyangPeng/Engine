///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 1:46)

#include "CoreTools/CoreToolsExport.h"

#include "Endian.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/span>
#include <algorithm>

using std::swap;

bool CoreTools::Endian::IsLittleEndian() noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    static constexpr auto one = 1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    static const auto isLittleEndian = (*reinterpret_cast<const char*>(&one) != 0);

#include STSTEM_WARNING_POP

#ifdef SYSTEM_LITTLE_ENDIAN

    CORE_TOOLS_ASSERTION_0(isLittleEndian, "�ⲻ��һ��С�˻�����");

#elif SYSTEM_BIG_ENDIAN

    CORE_TOOLS_ASSERTION_0(!isLittleEndian, "�ⲻ��һ����˻�����");

#endif  // SYSTEM_LITTLE_ENDIAN

    return isLittleEndian;
}

bool CoreTools::Endian::IsBigEndian() noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    return !IsLittleEndian();
}

void CoreTools::Endian::Swap2ByteOrder(void* data) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    SwapByteOrder(2, data);
}

void CoreTools::Endian::Swap2ByteOrder(size_t itemsNumber, void* data) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    if (data != nullptr && 0 < itemsNumber)
    {
        const gsl::span bytes{ static_cast<uint16_t*>(data), itemsNumber };
        for (auto& value : bytes)
        {
            Swap2ByteOrder(&value);
        }
    }
}

void CoreTools::Endian::Swap4ByteOrder(void* data) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    SwapByteOrder(4, data);
}

void CoreTools::Endian::Swap4ByteOrder(size_t itemsNumber, void* data) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    if (data != nullptr && 0 < itemsNumber)
    {
        const gsl::span bytes{ static_cast<uint32_t*>(data), itemsNumber };
        for (auto& value : bytes)
        {
            Swap4ByteOrder(&value);
        }
    }
}

void CoreTools::Endian::Swap8ByteOrder(void* data) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    SwapByteOrder(8, data);
}

void CoreTools::Endian::Swap8ByteOrder(size_t itemsNumber, void* data) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    if (data != nullptr && 0 < itemsNumber)
    {
        const gsl::span bytes{ static_cast<uint64_t*>(data), itemsNumber };
        for (auto& value : bytes)
        {
            Swap8ByteOrder(&value);
        }
    }
}

void CoreTools::Endian::SwapByteOrder(size_t itemSize, void* data) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    CORE_TOOLS_ASSERTION_0(data != nullptr, "ָ����Ч��");
    CORE_TOOLS_ASSERTION_2(itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ2��4��8\n");

    const gsl::span bytes{ static_cast<uint8_t*>(data), itemSize };

    const auto halfSize = itemSize / 2;

    for (size_t begin{ 0u }; begin < halfSize; ++begin)
    {
        swap(bytes[begin], bytes[itemSize - begin - 1]);
    }
}

void CoreTools::Endian::SwapByteOrder(size_t itemSize, size_t itemsNumber, void* data) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    CORE_TOOLS_ASSERTION_0(data != nullptr, "ָ����Ч��");
    CORE_TOOLS_ASSERTION_2(0 < itemsNumber, "itemsNumber��������㣡");
    CORE_TOOLS_ASSERTION_2(itemSize == 2 || itemSize == 4 || itemSize == 8, "��С����Ϊ2��4��8\n");

    const gsl::span bytes{ static_cast<uint8_t*>(data), itemsNumber * itemSize };

    for (auto index = 0u; index < itemsNumber; ++index)
    {
        SwapByteOrder(itemSize, &bytes[index * itemSize]);
    }
}

void CoreTools::Endian::Swap2ByteOrderToTarget(size_t itemsNumber, const uint16_t* source, uint16_t* target) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    CORE_TOOLS_ASSERTION_2(0 < itemsNumber, "itemsNumber��������㣡");
    CORE_TOOLS_ASSERTION_0(source != nullptr, "ָ����Ч��");
    CORE_TOOLS_ASSERTION_0(target != nullptr, "ָ����Ч��");

    System::MemoryCopy(target, source, boost::numeric_cast<uint32_t>(itemsNumber * sizeof(uint16_t)));

    Endian::Swap2ByteOrder(itemsNumber, target);
}

void CoreTools::Endian::Swap4ByteOrderToTarget(size_t itemsNumber, const uint32_t* source, uint32_t* target) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    CORE_TOOLS_ASSERTION_2(0 < itemsNumber, "itemsNumber��������㣡");
    CORE_TOOLS_ASSERTION_0(source != nullptr, "ָ����Ч��");
    CORE_TOOLS_ASSERTION_0(target != nullptr, "ָ����Ч��");

    System::MemoryCopy(target, source, boost::numeric_cast<uint32_t>(itemsNumber * sizeof(uint32_t)));

    Endian::Swap4ByteOrder(itemsNumber, target);
}

void CoreTools::Endian::Swap8ByteOrderToTarget(size_t itemsNumber, const uint64_t* source, uint64_t* target) noexcept(g_Assert < 0 || g_CoreToolsAssert < 0)
{
    CORE_TOOLS_ASSERTION_2(0 < itemsNumber, "itemsNumber��������㣡");
    CORE_TOOLS_ASSERTION_0(source != nullptr, "ָ����Ч��");
    CORE_TOOLS_ASSERTION_0(target != nullptr, "ָ����Ч��");

    System::MemoryCopy(target, source, boost::numeric_cast<uint32_t>(itemsNumber * sizeof(uint64_t)));

    Endian::Swap8ByteOrder(itemsNumber, target);
}
