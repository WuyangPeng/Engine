/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:20)

#include "WindowsCreateWParamTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WindowsCreateWParamTesting::WindowsCreateWParamTesting(const OStreamShared& stream)
    : ParentType{ stream },
      generator{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WindowsCreateWParamTesting)

void System::WindowsCreateWParamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WindowsCreateWParamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WParamTest);
}

void System::WindowsCreateWParamTesting::WParamTest()
{
    std::uniform_int_distribution<WindowsWParam> random{ minValue, maxValue };

    const auto low = random(generator);
    const auto high = random(generator);

    const WindowsWParam wParam{ low + (high << 16) };

    ASSERT_EQUAL(GetLowWord(wParam), boost::numeric_cast<int>(low));
    ASSERT_EQUAL(GetHighWord(wParam), boost::numeric_cast<int>(high));
}