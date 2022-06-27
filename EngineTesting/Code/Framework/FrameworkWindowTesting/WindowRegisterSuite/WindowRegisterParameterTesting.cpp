///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 13:50)

#include "WindowRegisterParameterTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowRegister/WindowRegisterParameter.h"

namespace Framework
{
    using TestingType = WindowRegisterParameter;
}

Framework::WindowRegisterParameterTesting::WindowRegisterParameterTesting(const OStreamShared& stream, HInstance instance)
    : ParentType{ stream }, instance{ instance }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowRegisterParameterTesting::IsValid() const noexcept
{
    if (ParentType::IsValid() && instance != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Framework::WindowRegisterParameterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowRegisterParameterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FullyTest);
}

void Framework::WindowRegisterParameterTesting::DefaultTest()
{
    const TestingType parameter{ instance };

    ASSERT_EQUAL(parameter.GetHInstance(), instance);
    ASSERT_ENUM_EQUAL(parameter.GetStyle(), System::WindowsClassStyle::CommonUse);
    ASSERT_EQUAL(parameter.GetWindowClassExtra(), 0);
    ASSERT_EQUAL(parameter.GetWindowExtra(), 0);
}

void Framework::WindowRegisterParameterTesting::FullyTest()
{
    const auto styles = System::WindowsClassStyle::CommonUse | System::WindowsClassStyle::NoClose;
    constexpr auto windowClassExtra = 5;
    constexpr auto windowExtra = 6;

    const TestingType parameter{ instance, styles, windowClassExtra, windowExtra };

    ASSERT_EQUAL(parameter.GetHInstance(), instance);
    ASSERT_ENUM_EQUAL(parameter.GetStyle(), styles);
    ASSERT_EQUAL(parameter.GetWindowClassExtra(), windowClassExtra);
    ASSERT_EQUAL(parameter.GetWindowExtra(), windowExtra);
}