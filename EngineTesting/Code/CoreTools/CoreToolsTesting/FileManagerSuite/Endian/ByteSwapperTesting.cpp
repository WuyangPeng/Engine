/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/30 20:49)

#include "ByteSwapperTesting.h"
#include "CoreTools/FileManager/ByteSwapper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ByteSwapperTesting::ByteSwapperTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ByteSwapperTesting)

void CoreTools::ByteSwapperTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ByteSwapperTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ByteSwap2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ByteSwap4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ByteSwap8Test);
}

void CoreTools::ByteSwapperTesting::ByteSwap2Test()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoByteSwap2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ByteSwap2Original);
}

void CoreTools::ByteSwapperTesting::DoByteSwap2Test()
{
    ASSERT_EQUAL(ByteSwap(static_cast<uint16_t>(0x1234)), 0x3412);
    ASSERT_EQUAL(ByteSwap(static_cast<uint16_t>(0x5678)), 0x7856);
    ASSERT_EQUAL(ByteSwap(static_cast<uint16_t>(0x9012)), 0x1290);
    ASSERT_EQUAL(ByteSwap(static_cast<uint16_t>(0x3456)), 0x5634);
    ASSERT_EQUAL(ByteSwap(static_cast<uint16_t>(0x7890)), 0x9078);
}

void CoreTools::ByteSwapperTesting::ByteSwap2Original()
{
    ASSERT_EQUAL(ByteSwap(ByteSwap(static_cast<uint16_t>(0x1234))), 0x1234);
    ASSERT_EQUAL(ByteSwap(ByteSwap(static_cast<uint16_t>(0x5678))), 0x5678);
    ASSERT_EQUAL(ByteSwap(ByteSwap(static_cast<uint16_t>(0x9012))), 0x9012);
    ASSERT_EQUAL(ByteSwap(ByteSwap(static_cast<uint16_t>(0x3456))), 0x3456);
    ASSERT_EQUAL(ByteSwap(ByteSwap(static_cast<uint16_t>(0x7890))), 0x7890);
}

void CoreTools::ByteSwapperTesting::ByteSwap4Test()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoByteSwap4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ByteSwap4Original);
}

void CoreTools::ByteSwapperTesting::DoByteSwap4Test()
{
    ASSERT_EQUAL(ByteSwap(0x12345678u), 0x78563412u);
    ASSERT_EQUAL(ByteSwap(0x12907856u), 0x56789012u);
    ASSERT_EQUAL(ByteSwap(0x90123456u), 0x56341290u);
    ASSERT_EQUAL(ByteSwap(0x34567890u), 0x90785634u);
    ASSERT_EQUAL(ByteSwap(0x78901234u), 0x34129078u);
}

void CoreTools::ByteSwapperTesting::ByteSwap4Original()
{
    ASSERT_EQUAL(ByteSwap(ByteSwap(0x12345678u)), 0x12345678u);
    ASSERT_EQUAL(ByteSwap(ByteSwap(0x12907856u)), 0x12907856u);
    ASSERT_EQUAL(ByteSwap(ByteSwap(0x90123456u)), 0x90123456u);
    ASSERT_EQUAL(ByteSwap(ByteSwap(0x34567890u)), 0x34567890u);
    ASSERT_EQUAL(ByteSwap(ByteSwap(0x78901234u)), 0x78901234u);
}

void CoreTools::ByteSwapperTesting::ByteSwap8Test()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoByteSwap8Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ByteSwap8Original);
}

void CoreTools::ByteSwapperTesting::DoByteSwap8Test()
{
    ASSERT_EQUAL(ByteSwap(0x1234567890123456u), 0x5634129078563412u);
    ASSERT_EQUAL(ByteSwap(0x5678901234567890u), 0x9078563412907856u);
    ASSERT_EQUAL(ByteSwap(0x9012345678901234u), 0x3412907856341290u);
    ASSERT_EQUAL(ByteSwap(0x3456789012345678u), 0x7856341290785634u);
    ASSERT_EQUAL(ByteSwap(0x7890123456781234u), 0x3412785634129078u);
}

void CoreTools::ByteSwapperTesting::ByteSwap8Original()
{
    ASSERT_EQUAL(ByteSwap(ByteSwap(0x1234567890123456u)), 0x1234567890123456u);
    ASSERT_EQUAL(ByteSwap(ByteSwap(0x5678901234567890u)), 0x5678901234567890u);
    ASSERT_EQUAL(ByteSwap(ByteSwap(0x9012345678901234u)), 0x9012345678901234u);
    ASSERT_EQUAL(ByteSwap(ByteSwap(0x3456789012345678u)), 0x3456789012345678u);
    ASSERT_EQUAL(ByteSwap(ByteSwap(0x7890123456781234u)), 0x7890123456781234u);
}