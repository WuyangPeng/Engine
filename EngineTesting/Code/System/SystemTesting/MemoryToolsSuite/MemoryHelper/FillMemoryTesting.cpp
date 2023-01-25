///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/04 21:16)

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
