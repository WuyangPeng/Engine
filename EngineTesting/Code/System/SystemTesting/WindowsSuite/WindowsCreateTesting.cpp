///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/06 16:24)

#include "WindowsCreateTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int_distribution;

System::WindowsCreateTesting::WindowsCreateTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WindowsCreateTesting)

void System::WindowsCreateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WindowsCreateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LParamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WParamTest);

    // SystemWindowsTesting有其他windows函数的测试。
}

void System::WindowsCreateTesting::LParamTest()
{
    constexpr WindowsLParam minValue{ 0 };
    constexpr WindowsLParam maxValue{ 2048 };

    default_random_engine generator{ GetEngineRandomSeed() };
    const uniform_int_distribution<WindowsLParam> random{ minValue, maxValue };

    const auto low = random(generator);
    const auto high = random(generator);

    const WindowsLParam lParam{ low + (high << 16) };

    ASSERT_EQUAL(GetLowWord(lParam), low);
    ASSERT_EQUAL(GetHighWord(lParam), high);
}

void System::WindowsCreateTesting::WParamTest()
{
    constexpr WindowsWParam minValue{ 0 };
    constexpr WindowsWParam maxValue{ 2048 };

    default_random_engine generator{ GetEngineRandomSeed() };
    const uniform_int_distribution<WindowsWParam> random{ minValue, maxValue };

    const auto low = random(generator);
    const auto high = random(generator);

    const WindowsWParam wParam{ low + (high << 16) };

    ASSERT_EQUAL(GetLowWord(wParam), boost::numeric_cast<int>(low));
    ASSERT_EQUAL(GetHighWord(wParam), boost::numeric_cast<int>(high));
}