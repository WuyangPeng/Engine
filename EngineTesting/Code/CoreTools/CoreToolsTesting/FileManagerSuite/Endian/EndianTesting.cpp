/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/30 22:37)

#include "EndianTesting.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>
#include <vector>

CoreTools::EndianTesting::EndianTesting(const OStreamShared& stream)
    : ParentType{ stream },
      originalUInt16{ 0x1234, 0x5678, 0x9ABC, 0xDEF0, 0x159D },
      swapUInt16{ 0x3412, 0x7856, 0xBC9A, 0xF0DE, 0x9D15 },
      originalUInt32{ 0x12345678, 0x9ABCDEF0, 0x159D26AE, 0x37BF48C0 },
      swapUInt32{ 0x78563412, 0xF0DEBC9A, 0xAE269D15, 0xC048BF37 },
      originalUInt64{ 0x123456789ABCDEF0, 0x159D26AE37BF48C0, 0x0FEDCBA987654321 },
      swapUInt64{ 0xF0DEBC9A78563412, 0xC048BF37AE269D15, 0x21436587A9CBED0F }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EndianTesting)

void CoreTools::EndianTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::EndianTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ByteOrderTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Swap2ByteOrderTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Swap4ByteOrderTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Swap8ByteOrderTest);
}

void CoreTools::EndianTesting::ByteOrderTest()
{
#ifdef SYSTEM_LITTLE_ENDIAN

    ASSERT_FALSE(Endian::IsBigEndian());
    ASSERT_TRUE(Endian::IsLittleEndian());

#else  // !SYSTEM_LITTLE_ENDIAN

    ASSERT_TRUE(Endian::IsBigEndian());
    ASSERT_FALSE(Endian::IsLittleEndian());

#endif  // SYSTEM_LITTLE_ENDIAN
}

void CoreTools::EndianTesting::Swap2ByteOrderTest()
{
    auto value = originalUInt16;

    ASSERT_NOT_THROW_EXCEPTION_1(Swap2ByteOrder0Test, value);
    ASSERT_NOT_THROW_EXCEPTION_1(Swap2ByteOrder1Test, value);
    ASSERT_NOT_THROW_EXCEPTION_1(Swap2ByteOrder2Test, value);
    ASSERT_NOT_THROW_EXCEPTION_1(Swap2ByteOrder3Test, value);
    ASSERT_NOT_THROW_EXCEPTION_1(Swap2ByteOrder4Test, value);
}

void CoreTools::EndianTesting::Swap2ByteOrder0Test(UInt16Array& value)
{
    Endian::Swap2ByteOrder(value.data());
    ASSERT_EQUAL(value.at(0), swapUInt16.at(0));
    for (auto i = 1u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(value.at(i), originalUInt16.at(i));
    }
}

void CoreTools::EndianTesting::Swap2ByteOrder1Test(UInt16Array& value)
{
    Endian::Swap2ByteOrder(uint16ArraySize, value.data());
    ASSERT_EQUAL(value.at(0), originalUInt16.at(0));
    for (auto i = 1u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(value.at(i), swapUInt16.at(i));
    }
}

void CoreTools::EndianTesting::Swap2ByteOrder2Test(UInt16Array& value)
{
    Endian::SwapByteOrder(sizeof(uint16_t), value.data());
    for (auto i = 0u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(value.at(i), swapUInt16.at(i));
    }
}

void CoreTools::EndianTesting::Swap2ByteOrder3Test(UInt16Array& value)
{
    Endian::SwapByteOrder(sizeof(uint16_t), uint16ArraySize, value.data());
    for (auto i = 0u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(value.at(i), originalUInt16.at(i));
    }
}

void CoreTools::EndianTesting::Swap2ByteOrder4Test(const UInt16Array& value)
{
    UInt16Array target{};
    Endian::Swap2ByteOrderToTarget(uint16ArraySize, value.data(), target.data());
    for (auto i = 0u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(target.at(i), swapUInt16.at(i));
        ASSERT_EQUAL(value.at(i), originalUInt16.at(i));
    }
}

void CoreTools::EndianTesting::Swap4ByteOrderTest()
{
    auto value = originalUInt32;

    ASSERT_NOT_THROW_EXCEPTION_1(Swap4ByteOrder0Test, value);
    ASSERT_NOT_THROW_EXCEPTION_1(Swap4ByteOrder1Test, value);
    ASSERT_NOT_THROW_EXCEPTION_1(Swap4ByteOrder2Test, value);
    ASSERT_NOT_THROW_EXCEPTION_1(Swap4ByteOrder3Test, value);
    ASSERT_NOT_THROW_EXCEPTION_1(Swap4ByteOrder4Test, value);
}

void CoreTools::EndianTesting::Swap4ByteOrder0Test(UInt32Array& value)
{
    Endian::Swap4ByteOrder(value.data());
    ASSERT_EQUAL(value.at(0), swapUInt32.at(0));
    for (auto i = 1u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(value.at(i), originalUInt32.at(i));
    }
}

void CoreTools::EndianTesting::Swap4ByteOrder1Test(UInt32Array& value)
{
    Endian::Swap4ByteOrder(uint32ArraySize, value.data());
    ASSERT_EQUAL(value.at(0), originalUInt32.at(0));
    for (auto i = 1u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(value.at(i), swapUInt32.at(i));
    }
}

void CoreTools::EndianTesting::Swap4ByteOrder2Test(UInt32Array& value)
{
    Endian::SwapByteOrder(sizeof(uint32_t), value.data());
    for (auto i = 0u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(value.at(i), swapUInt32.at(i));
    }
}

void CoreTools::EndianTesting::Swap4ByteOrder3Test(UInt32Array& value)
{
    Endian::SwapByteOrder(sizeof(uint32_t), uint32ArraySize, value.data());
    for (auto i = 0u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(value.at(i), originalUInt32.at(i));
    }
}

void CoreTools::EndianTesting::Swap4ByteOrder4Test(const UInt32Array& value)
{
    UInt32Array target{};
    Endian::Swap4ByteOrderToTarget(uint32ArraySize, value.data(), target.data());
    for (auto i = 0u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(target.at(i), swapUInt32.at(i));
        ASSERT_EQUAL(value.at(i), originalUInt32.at(i));
    }
}

void CoreTools::EndianTesting::Swap8ByteOrderTest()
{
    auto value = originalUInt64;

    ASSERT_NOT_THROW_EXCEPTION_1(Swap8ByteOrder0Test, value);
    ASSERT_NOT_THROW_EXCEPTION_1(Swap8ByteOrder1Test, value);
    ASSERT_NOT_THROW_EXCEPTION_1(Swap8ByteOrder2Test, value);
    ASSERT_NOT_THROW_EXCEPTION_1(Swap8ByteOrder3Test, value);
    ASSERT_NOT_THROW_EXCEPTION_1(Swap8ByteOrder4Test, value);
}

void CoreTools::EndianTesting::Swap8ByteOrder0Test(UInt64Array& value)
{
    Endian::Swap8ByteOrder(value.data());
    ASSERT_EQUAL(value.at(0), swapUInt64.at(0));
    for (auto i = 1u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(value.at(i), originalUInt64.at(i));
    }
}

void CoreTools::EndianTesting::Swap8ByteOrder1Test(UInt64Array& value)
{
    Endian::Swap8ByteOrder(uint64ArraySize, value.data());
    ASSERT_EQUAL(value.at(0), originalUInt64.at(0));
    for (auto i = 1u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(value.at(i), swapUInt64.at(i));
    }
}

void CoreTools::EndianTesting::Swap8ByteOrder2Test(UInt64Array& value)
{
    Endian::SwapByteOrder(sizeof(uint64_t), value.data());
    for (auto i = 0u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(value.at(i), swapUInt64.at(i));
    }
}

void CoreTools::EndianTesting::Swap8ByteOrder3Test(UInt64Array& value)
{
    Endian::SwapByteOrder(sizeof(uint64_t), uint64ArraySize, value.data());
    for (auto i = 0u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(value.at(i), originalUInt64.at(i));
    }
}

void CoreTools::EndianTesting::Swap8ByteOrder4Test(const UInt64Array& value)
{
    UInt64Array target{};
    Endian::Swap8ByteOrderToTarget(uint64ArraySize, value.data(), target.data());
    for (auto i = 0u; i < value.size(); ++i)
    {
        ASSERT_EQUAL(target.at(i), swapUInt64.at(i));
        ASSERT_EQUAL(value.at(i), originalUInt64.at(i));
    }
}
