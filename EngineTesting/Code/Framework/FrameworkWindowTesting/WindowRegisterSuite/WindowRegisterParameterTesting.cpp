// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/07 11:01)

#include "WindowRegisterParameterTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowRegister/WindowRegisterParameter.h"

namespace Framework
{
    using TestingType = WindowRegisterParameter;
}

Framework::WindowRegisterParameterTesting::WindowRegisterParameterTesting(const OStreamShared& stream, HInstance instance)
    : ParentType{ stream }, m_Instance{ instance }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowRegisterParameterTesting::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Instance != nullptr)
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
    const TestingType parameter{ m_Instance };

    ASSERT_EQUAL(parameter.GetHInstance(), m_Instance);
    ASSERT_ENUM_EQUAL(parameter.GetStyle(), System::WindowsClassStyle::CommonUse);
    ASSERT_EQUAL(parameter.GetWindowClassExtra(), 0);
    ASSERT_EQUAL(parameter.GetWindowExtra(), 0);
}

void Framework::WindowRegisterParameterTesting::FullyTest()
{
    const auto styles = System::WindowsClassStyle::CommonUse | System::WindowsClassStyle::NoClose;
    constexpr auto windowClassExtra = 5;
    constexpr auto windowExtra = 6;

    const TestingType parameter{ m_Instance, styles, windowClassExtra, windowExtra };

    ASSERT_EQUAL(parameter.GetHInstance(), m_Instance);
    ASSERT_ENUM_EQUAL(parameter.GetStyle(), styles);
    ASSERT_EQUAL(parameter.GetWindowClassExtra(), windowClassExtra);
    ASSERT_EQUAL(parameter.GetWindowExtra(), windowExtra);
}