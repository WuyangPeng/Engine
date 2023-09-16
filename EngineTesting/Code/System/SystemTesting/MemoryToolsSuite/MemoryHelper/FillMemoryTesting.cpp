///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:06)

#include "FillMemoryTesting.h"
#include "System/Console/Using/ConsoleFontUsing.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FillMemoryTesting::FillMemoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FillMemoryTesting)

void System::FillMemoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FillMemoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FillMemoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FillConsoleFontInfoTest);
}

void System::FillMemoryTesting::FillMemoryTest()
{
    int32_t fillValue = 1;

    FillMemoryToZero(fillValue);

    ASSERT_EQUAL(fillValue, 0);
}

void System::FillMemoryTesting::FillConsoleFontInfoTest()
{
    auto consoleFontInfoEx = GetWindowsStructDefaultSize<ConsoleFontInfoEx>();

    FillMemoryToZero(consoleFontInfoEx);

    ASSERT_EQUAL(consoleFontInfoEx.cbSize, 0u);
    ASSERT_EQUAL(consoleFontInfoEx.nFont, 0u);
    ASSERT_EQUAL(consoleFontInfoEx.dwFontSize.X, 0);
    ASSERT_EQUAL(consoleFontInfoEx.dwFontSize.Y, 0);
    ASSERT_EQUAL(consoleFontInfoEx.FontFamily, 0u);
    ASSERT_EQUAL(consoleFontInfoEx.FontWeight, 0u);
}
