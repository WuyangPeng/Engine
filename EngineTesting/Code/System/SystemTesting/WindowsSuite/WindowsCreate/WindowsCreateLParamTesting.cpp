/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:20)

#include "WindowsCreateLParamTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WindowsCreateLParamTesting::WindowsCreateLParamTesting(const OStreamShared& stream)
    : ParentType{ stream },
      generator{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WindowsCreateLParamTesting)

void System::WindowsCreateLParamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WindowsCreateLParamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LParamTest);
}

void System::WindowsCreateLParamTesting::LParamTest()
{
    std::uniform_int_distribution<WindowsLParam> random{ minValue, maxValue };

    const auto low = random(generator);
    const auto high = random(generator);

    const WindowsLParam lParam{ low + (high << 16) };

    ASSERT_EQUAL(GetLowWord(lParam), low);
    ASSERT_EQUAL(GetHighWord(lParam), high);
}
