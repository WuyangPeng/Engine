///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 14:16)

#include "WindowInstanceParameterTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"

using namespace std::literals;

namespace Framework
{
    using TestingType = WindowInstanceParameter;
}

Framework::WindowInstanceParameterTesting::WindowInstanceParameterTesting(const OStreamShared& stream, HInstance instance)
    : ParentType{ stream }, instance{ instance }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowInstanceParameterTesting)

void Framework::WindowInstanceParameterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowInstanceParameterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
}

void Framework::WindowInstanceParameterTesting::ValueTest()
{
    const auto className = SYSTEM_TEXT("ClassName"s);

    TestingType parameter{ instance, className };

    ASSERT_EQUAL(instance, parameter.GetHInstance());
    ASSERT_EQUAL(className, parameter.GetWindowClassName());
}
