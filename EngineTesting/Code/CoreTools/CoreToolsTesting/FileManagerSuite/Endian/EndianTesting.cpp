/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:41)

#include "EndianTesting.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>
#include <vector>

CoreTools::EndianTesting::EndianTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    constexpr auto arraySize = 5;
    std::array<uint16_t, arraySize> value{ 0x1234, 0x5678, 0x9012, 0x3456, 0x7890 };

    Endian::Swap2ByteOrder(value.data());
    ASSERT_EQUAL(value.at(0), uint16_t{ 0x3412 });

    Endian::Swap2ByteOrder(arraySize, value.data());
    ASSERT_EQUAL(value.at(0), uint16_t{ 0x1234 });
    ASSERT_EQUAL(value.at(1), uint16_t{ 0x7856 });
    ASSERT_EQUAL(value.at(2), uint16_t{ 0x1290 });
    ASSERT_EQUAL(value.at(3), uint16_t{ 0x5634 });
    ASSERT_EQUAL(value.at(4), uint16_t{ 0x9078 });

    Endian::SwapByteOrder(sizeof(uint16_t), value.data());
    ASSERT_EQUAL(value.at(0), uint16_t{ 0x3412 });

    Endian::SwapByteOrder(sizeof(uint16_t), arraySize, value.data());
    ASSERT_EQUAL(value.at(0), uint16_t{ 0x1234 });
    ASSERT_EQUAL(value.at(1), uint16_t{ 0x5678 });
    ASSERT_EQUAL(value.at(2), uint16_t{ 0x9012 });
    ASSERT_EQUAL(value.at(3), uint16_t{ 0x3456 });
    ASSERT_EQUAL(value.at(4), uint16_t{ 0x7890 });

    std::vector<uint16_t> target(arraySize);
    Endian::Swap2ByteOrderToTarget(arraySize, value.data(), target.data());
    ASSERT_EQUAL(target.at(0), uint16_t{ 0x3412 });
    ASSERT_EQUAL(target.at(1), uint16_t{ 0x7856 });
    ASSERT_EQUAL(target.at(2), uint16_t{ 0x1290 });
    ASSERT_EQUAL(target.at(3), uint16_t{ 0x5634 });
    ASSERT_EQUAL(target.at(4), uint16_t{ 0x9078 });
    ASSERT_EQUAL(value.at(0), uint16_t{ 0x1234 });
    ASSERT_EQUAL(value.at(1), uint16_t{ 0x5678 });
    ASSERT_EQUAL(value.at(2), uint16_t{ 0x9012 });
    ASSERT_EQUAL(value.at(3), uint16_t{ 0x3456 });
    ASSERT_EQUAL(value.at(4), uint16_t{ 0x7890 });
}

void CoreTools::EndianTesting::Swap4ByteOrderTest()
{
    constexpr auto arraySize = 4;
    std::array<uint32_t, arraySize> value{ 0x12345678, 0x56789012, 0x90123456, 0x34567890 };

    Endian::Swap4ByteOrder(value.data());
    ASSERT_EQUAL(value.at(0), 0x78563412u);

    Endian::Swap4ByteOrder(arraySize, value.data());
    ASSERT_EQUAL(value.at(0), 0x12345678u);
    ASSERT_EQUAL(value.at(1), 0x12907856u);
    ASSERT_EQUAL(value.at(2), 0x56341290u);
    ASSERT_EQUAL(value.at(3), 0x90785634u);

    Endian::SwapByteOrder(sizeof(uint32_t), value.data());
    ASSERT_EQUAL(value.at(0), 0x78563412u);

    Endian::SwapByteOrder(sizeof(uint32_t), arraySize, value.data());
    ASSERT_EQUAL(value.at(0), 0x12345678u);
    ASSERT_EQUAL(value.at(1), 0x56789012u);
    ASSERT_EQUAL(value.at(2), 0x90123456u);
    ASSERT_EQUAL(value.at(3), 0x34567890u);

    std::vector<uint32_t> target(arraySize);
    Endian::Swap4ByteOrderToTarget(arraySize, value.data(), target.data());
    ASSERT_EQUAL(target.at(0), 0x78563412u);
    ASSERT_EQUAL(target.at(1), 0x12907856u);
    ASSERT_EQUAL(target.at(2), 0x56341290u);
    ASSERT_EQUAL(target.at(3), 0x90785634u);
    ASSERT_EQUAL(value.at(0), 0x12345678u);
    ASSERT_EQUAL(value.at(1), 0x56789012u);
    ASSERT_EQUAL(value.at(2), 0x90123456u);
    ASSERT_EQUAL(value.at(3), 0x34567890u);
}

void CoreTools::EndianTesting::Swap8ByteOrderTest()
{
    constexpr auto arraySize = 3;
    std::array<uint64_t, arraySize> value{ 0x1234567890123456, 0x5678901234567890, 0x9012345678901234 };

    Endian::Swap8ByteOrder(value.data());
    ASSERT_EQUAL(value.at(0), 0x5634129078563412u);

    Endian::Swap8ByteOrder(arraySize, value.data());
    ASSERT_EQUAL(value.at(0), 0x1234567890123456u);
    ASSERT_EQUAL(value.at(1), 0x9078563412907856u);
    ASSERT_EQUAL(value.at(2), 0x3412907856341290u);

    Endian::SwapByteOrder(sizeof(uint64_t), value.data());
    ASSERT_EQUAL(value.at(0), 0x5634129078563412u);

    Endian::SwapByteOrder(sizeof(uint64_t), arraySize, value.data());
    ASSERT_EQUAL(value.at(0), 0x1234567890123456u);
    ASSERT_EQUAL(value.at(1), 0x5678901234567890u);
    ASSERT_EQUAL(value.at(2), 0x9012345678901234u);

    std::vector<uint64_t> target(arraySize);
    Endian::Swap8ByteOrderToTarget(arraySize, value.data(), target.data());
    ASSERT_EQUAL(target.at(0), 0x5634129078563412u);
    ASSERT_EQUAL(target.at(1), 0x9078563412907856u);
    ASSERT_EQUAL(target.at(2), 0x3412907856341290u);
    ASSERT_EQUAL(value.at(0), 0x1234567890123456u);
    ASSERT_EQUAL(value.at(1), 0x5678901234567890u);
    ASSERT_EQUAL(value.at(2), 0x9012345678901234u);
}
