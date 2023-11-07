///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 15:41)

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
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WindowsCreateLParamTesting)

void System::WindowsCreateLParamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WindowsCreateLParamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LParamTest);

    // SystemWindowsTesting������windows�����Ĳ��ԡ�
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
