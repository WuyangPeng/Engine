// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:38)

#include "EndianTesting.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <array>
#include <vector>

using std::array;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, EndianTesting)

void CoreTools::EndianTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ByteOrderTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Swap2ByteOrderTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Swap4ByteOrderTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Swap8ByteOrderTest);
}

void CoreTools::EndianTesting ::ByteOrderTest()
{
#ifdef SYSTEM_LITTLE_ENDIAN
    ASSERT_FALSE(Endian::IsBigEndian());
    ASSERT_TRUE(Endian::IsLittleEndian());
#else  // !SYSTEM_LITTLE_ENDIAN
    ASSERT_TRUE(Endian::IsBigEndian());
    ASSERT_FALSE(Endian::IsLittleEndian());
#endif  // SYSTEM_LITTLE_ENDIAN
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
void CoreTools::EndianTesting ::Swap2ByteOrderTest()
{
    constexpr auto arraySize = 5;
    array<uint16_t, arraySize> value{ 0x1234, 0x5678, 0x9012, 0x3456, 0x7890 };

    Endian::Swap2ByteOrder(value.data());
    ASSERT_EQUAL(value[0], uint16_t(0x3412));

    Endian::Swap2ByteOrder(arraySize, value.data());
    ASSERT_EQUAL(value[0], uint16_t(0x1234));
    ASSERT_EQUAL(value[1], uint16_t(0x7856));
    ASSERT_EQUAL(value[2], uint16_t(0x1290));
    ASSERT_EQUAL(value[3], uint16_t(0x5634));
    ASSERT_EQUAL(value[4], uint16_t(0x9078));

    Endian::SwapByteOrder(sizeof(uint16_t), value.data());
    ASSERT_EQUAL(value[0], uint16_t(0x3412));

    Endian::SwapByteOrder(sizeof(uint16_t), arraySize, value.data());
    ASSERT_EQUAL(value[0], uint16_t(0x1234));
    ASSERT_EQUAL(value[1], uint16_t(0x5678));
    ASSERT_EQUAL(value[2], uint16_t(0x9012));
    ASSERT_EQUAL(value[3], uint16_t(0x3456));
    ASSERT_EQUAL(value[4], uint16_t(0x7890));

    vector<uint16_t> target(arraySize);
    Endian::Swap2ByteOrderToTarget(arraySize, value.data(), target.data());
    ASSERT_EQUAL(target[0], uint16_t(0x3412));
    ASSERT_EQUAL(target[1], uint16_t(0x7856));
    ASSERT_EQUAL(target[2], uint16_t(0x1290));
    ASSERT_EQUAL(target[3], uint16_t(0x5634));
    ASSERT_EQUAL(target[4], uint16_t(0x9078));
    ASSERT_EQUAL(value[0], uint16_t(0x1234));
    ASSERT_EQUAL(value[1], uint16_t(0x5678));
    ASSERT_EQUAL(value[2], uint16_t(0x9012));
    ASSERT_EQUAL(value[3], uint16_t(0x3456));
    ASSERT_EQUAL(value[4], uint16_t(0x7890));
}

void CoreTools::EndianTesting ::Swap4ByteOrderTest()
{
    constexpr auto arraySize = 4;
    array<uint32_t, arraySize> value{ 0x12345678, 0x56789012, 0x90123456, 0x34567890 };

    Endian::Swap4ByteOrder(value.data());
    ASSERT_EQUAL(value[0], uint32_t(0x78563412));

    Endian::Swap4ByteOrder(arraySize, value.data());
    ASSERT_EQUAL(value[0], uint32_t(0x12345678));
    ASSERT_EQUAL(value[1], uint32_t(0x12907856));
    ASSERT_EQUAL(value[2], uint32_t(0x56341290));
    ASSERT_EQUAL(value[3], uint32_t(0x90785634));

    Endian::SwapByteOrder(sizeof(uint32_t), value.data());
    ASSERT_EQUAL(value[0], uint32_t(0x78563412));

    Endian::SwapByteOrder(sizeof(uint32_t), arraySize, value.data());
    ASSERT_EQUAL(value[0], uint32_t(0x12345678));
    ASSERT_EQUAL(value[1], uint32_t(0x56789012));
    ASSERT_EQUAL(value[2], uint32_t(0x90123456));
    ASSERT_EQUAL(value[3], uint32_t(0x34567890));

    vector<uint32_t> target(arraySize);
    Endian::Swap4ByteOrderToTarget(arraySize, value.data(), target.data());
    ASSERT_EQUAL(target[0], uint32_t(0x78563412));
    ASSERT_EQUAL(target[1], uint32_t(0x12907856));
    ASSERT_EQUAL(target[2], uint32_t(0x56341290));
    ASSERT_EQUAL(target[3], uint32_t(0x90785634));
    ASSERT_EQUAL(value[0], uint32_t(0x12345678));
    ASSERT_EQUAL(value[1], uint32_t(0x56789012));
    ASSERT_EQUAL(value[2], uint32_t(0x90123456));
    ASSERT_EQUAL(value[3], uint32_t(0x34567890));
}

void CoreTools::EndianTesting ::Swap8ByteOrderTest()
{
    constexpr auto arraySize = 3;
    array<uint64_t, arraySize> value{ 0x1234567890123456, 0x5678901234567890, 0x9012345678901234 };

    Endian::Swap8ByteOrder(value.data());
    ASSERT_EQUAL(value[0], uint64_t(0x5634129078563412));

    Endian::Swap8ByteOrder(arraySize, value.data());
    ASSERT_EQUAL(value[0], uint64_t(0x1234567890123456));
    ASSERT_EQUAL(value[1], uint64_t(0x9078563412907856));
    ASSERT_EQUAL(value[2], uint64_t(0x3412907856341290));

    Endian::SwapByteOrder(sizeof(uint64_t), value.data());
    ASSERT_EQUAL(value[0], uint64_t(0x5634129078563412));

    Endian::SwapByteOrder(sizeof(uint64_t), arraySize, value.data());
    ASSERT_EQUAL(value[0], uint64_t(0x1234567890123456));
    ASSERT_EQUAL(value[1], uint64_t(0x5678901234567890));
    ASSERT_EQUAL(value[2], uint64_t(0x9012345678901234));

    vector<uint64_t> target(arraySize);
    Endian::Swap8ByteOrderToTarget(arraySize, value.data(), target.data());
    ASSERT_EQUAL(target[0], uint64_t(0x5634129078563412));
    ASSERT_EQUAL(target[1], uint64_t(0x9078563412907856));
    ASSERT_EQUAL(target[2], uint64_t(0x3412907856341290));
    ASSERT_EQUAL(value[0], uint64_t(0x1234567890123456));
    ASSERT_EQUAL(value[1], uint64_t(0x5678901234567890));
    ASSERT_EQUAL(value[2], uint64_t(0x9012345678901234));
}

#include STSTEM_WARNING_POP