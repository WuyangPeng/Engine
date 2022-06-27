///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 11:14)

#include "ApplicationTraitTesting.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

Framework::ApplicationTraitTesting::ApplicationTraitTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ApplicationTraitTesting)

void Framework::ApplicationTraitTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ApplicationTraitTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(KeyIdentifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(KeyboardModifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MouseButtonsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MouseStateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MouseModifiersTest);
}

void Framework::ApplicationTraitTesting::KeyIdentifiersTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WindowKeyIdentifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GlutKeyIdentifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidKeyIdentifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LinuxKeyIdentifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MacintoshKeyIdentifiersTest);
}

void Framework::ApplicationTraitTesting::KeyboardModifiersTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WindowKeyboardModifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GlutKeyboardModifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidKeyboardModifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LinuxKeyboardModifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MacintoshKeyboardModifiersTest);
}

void Framework::ApplicationTraitTesting::MouseButtonsTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WindowMouseButtonsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GlutMouseButtonsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidMouseButtonsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LinuxMouseButtonsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MacintoshMouseButtonsTest);
}

void Framework::ApplicationTraitTesting::MouseStateTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WindowMouseStateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GlutMouseStateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidMouseStateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LinuxMouseStateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MacintoshMouseStateTest);
}

void Framework::ApplicationTraitTesting::MouseModifiersTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WindowMouseModifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GlutMouseModifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidMouseModifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LinuxMouseModifiersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MacintoshMouseModifiersTest);
}

void Framework::ApplicationTraitTesting::WindowKeyIdentifiersTest() noexcept
{
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyEscape == System::EnumCastUnderlying(System::WindowsKeyCodes::Escape));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyLeftArrow == System::EnumCastUnderlying(System::WindowsKeyCodes::Left));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyRightArrow == System::EnumCastUnderlying(System::WindowsKeyCodes::Right));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyUpArrow == System::EnumCastUnderlying(System::WindowsKeyCodes::Up));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyDownArrow == System::EnumCastUnderlying(System::WindowsKeyCodes::Down));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyHome == System::EnumCastUnderlying(System::WindowsKeyCodes::Home));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyEnd == System::EnumCastUnderlying(System::WindowsKeyCodes::End));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyPageUp == System::EnumCastUnderlying(System::WindowsKeyCodes::Prior));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyPageDown == System::EnumCastUnderlying(System::WindowsKeyCodes::Next));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyInsert == System::EnumCastUnderlying(System::WindowsKeyCodes::Insert));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyDelete == System::EnumCastUnderlying(System::WindowsKeyCodes::Delete));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyF1 == System::EnumCastUnderlying(System::WindowsKeyCodes::F1));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyF2 == System::EnumCastUnderlying(System::WindowsKeyCodes::F2));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyF3 == System::EnumCastUnderlying(System::WindowsKeyCodes::F3));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyF4 == System::EnumCastUnderlying(System::WindowsKeyCodes::F4));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyF5 == System::EnumCastUnderlying(System::WindowsKeyCodes::F5));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyF6 == System::EnumCastUnderlying(System::WindowsKeyCodes::F6));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyF7 == System::EnumCastUnderlying(System::WindowsKeyCodes::F7));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyF8 == System::EnumCastUnderlying(System::WindowsKeyCodes::F8));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyF9 == System::EnumCastUnderlying(System::WindowsKeyCodes::F9));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyF10 == System::EnumCastUnderlying(System::WindowsKeyCodes::F10));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyF11 == System::EnumCastUnderlying(System::WindowsKeyCodes::F11));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyF12 == System::EnumCastUnderlying(System::WindowsKeyCodes::F12));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyBackspace == System::EnumCastUnderlying(System::WindowsKeyCodes::Back));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyTab == System::EnumCastUnderlying(System::WindowsKeyCodes::Tab));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyEnter == System::EnumCastUnderlying(System::WindowsKeyCodes::Return));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyReturn == System::EnumCastUnderlying(System::WindowsKeyCodes::Return));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyTerminate == System::EnumCastUnderlying(System::WindowsKeyCodes::Escape));

    static_assert(WindowApplicationTrait::KeyIdentifiers::upperT == static_cast<int>('T'));
    static_assert(WindowApplicationTrait::KeyIdentifiers::upperR == static_cast<int>('R'));

    static_assert(WindowApplicationTrait::KeyIdentifiers::lowerT == static_cast<int>('t'));
    static_assert(WindowApplicationTrait::KeyIdentifiers::lowerR == static_cast<int>('r'));

    static_assert(WindowApplicationTrait::KeyIdentifiers::keyCode0 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode0));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyCode1 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode1));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyCode2 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode2));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyCode3 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode3));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyCode4 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode4));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyCode5 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode5));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyCode6 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode6));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyCode7 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode7));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyCode8 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode8));
    static_assert(WindowApplicationTrait::KeyIdentifiers::keyCode9 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode9));
}

void Framework::ApplicationTraitTesting::WindowKeyboardModifiersTest() noexcept
{
    static_assert(WindowApplicationTrait::KeyboardModifiers::keyShift == System::EnumCastUnderlying(System::WindowsKeyCodes::Shift));
    static_assert(WindowApplicationTrait::KeyboardModifiers::keyControl == System::EnumCastUnderlying(System::WindowsKeyCodes::Control));
    static_assert(WindowApplicationTrait::KeyboardModifiers::keyAlt == System::EnumCastUnderlying(System::WindowsKeyCodes::Menu));
}

void Framework::ApplicationTraitTesting::WindowMouseButtonsTest() noexcept
{
    static_assert(WindowApplicationTrait::MouseButtons::mouseLeftButton == 0);
    static_assert(WindowApplicationTrait::MouseButtons::mouseMiddleButton == 1);
    static_assert(WindowApplicationTrait::MouseButtons::mouseRightButton == 2);
}

void Framework::ApplicationTraitTesting::WindowMouseStateTest() noexcept
{
    static_assert(WindowApplicationTrait::MouseState::mouseUp == 1);
    static_assert(WindowApplicationTrait::MouseState::mouseDown == 0);
}

void Framework::ApplicationTraitTesting::WindowMouseModifiersTest() noexcept
{
    static_assert(WindowApplicationTrait::MouseModifiers::modifierControl == System::EnumCastUnderlying(System::WindowsModifiersCodes::Control));
    static_assert(WindowApplicationTrait::MouseModifiers::modifierLeftButton == System::EnumCastUnderlying(System::WindowsModifiersCodes::LeftButton));
    static_assert(WindowApplicationTrait::MouseModifiers::modifierMiddleButton == System::EnumCastUnderlying(System::WindowsModifiersCodes::MiddleButton));
    static_assert(WindowApplicationTrait::MouseModifiers::modifierRightButton == System::EnumCastUnderlying(System::WindowsModifiersCodes::RightButton));
    static_assert(WindowApplicationTrait::MouseModifiers::modifierShift == System::EnumCastUnderlying(System::WindowsModifiersCodes::Shift));
}

void Framework::ApplicationTraitTesting::GlutKeyIdentifiersTest() noexcept
{
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyEscape == System::EnumCastUnderlying(System::GlutKeyCodes::Escape));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyLeftArrow == System::EnumCastUnderlying(System::GlutKeyCodes::Left));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyRightArrow == System::EnumCastUnderlying(System::GlutKeyCodes::Right));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyUpArrow == System::EnumCastUnderlying(System::GlutKeyCodes::Up));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyDownArrow == System::EnumCastUnderlying(System::GlutKeyCodes::Down));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyHome == System::EnumCastUnderlying(System::GlutKeyCodes::Home));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyEnd == System::EnumCastUnderlying(System::GlutKeyCodes::End));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyPageUp == System::EnumCastUnderlying(System::GlutKeyCodes::PageUp));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyPageDown == System::EnumCastUnderlying(System::GlutKeyCodes::PageDown));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyInsert == System::EnumCastUnderlying(System::GlutKeyCodes::Insert));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyDelete == System::EnumCastUnderlying(System::GlutKeyCodes::Delete));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyF1 == System::EnumCastUnderlying(System::GlutKeyCodes::F1));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyF2 == System::EnumCastUnderlying(System::GlutKeyCodes::F2));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyF3 == System::EnumCastUnderlying(System::GlutKeyCodes::F3));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyF4 == System::EnumCastUnderlying(System::GlutKeyCodes::F4));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyF5 == System::EnumCastUnderlying(System::GlutKeyCodes::F5));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyF6 == System::EnumCastUnderlying(System::GlutKeyCodes::F6));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyF7 == System::EnumCastUnderlying(System::GlutKeyCodes::F7));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyF8 == System::EnumCastUnderlying(System::GlutKeyCodes::F8));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyF9 == System::EnumCastUnderlying(System::GlutKeyCodes::F9));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyF10 == System::EnumCastUnderlying(System::GlutKeyCodes::F10));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyF11 == System::EnumCastUnderlying(System::GlutKeyCodes::F11));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyF12 == System::EnumCastUnderlying(System::GlutKeyCodes::F12));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyBackspace == System::EnumCastUnderlying(System::GlutKeyCodes::Backspace));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyTab == System::EnumCastUnderlying(System::GlutKeyCodes::Tab));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyEnter == System::EnumCastUnderlying(System::GlutKeyCodes::Enter));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyReturn == System::EnumCastUnderlying(System::GlutKeyCodes::Return));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyTerminate == System::EnumCastUnderlying(System::GlutKeyCodes::Escape));

    static_assert(GlutApplicationTrait::KeyIdentifiers::upperT == static_cast<int>('T'));
    static_assert(GlutApplicationTrait::KeyIdentifiers::upperR == static_cast<int>('R'));

    static_assert(GlutApplicationTrait::KeyIdentifiers::lowerT == static_cast<int>('t'));
    static_assert(GlutApplicationTrait::KeyIdentifiers::lowerR == static_cast<int>('r'));

    static_assert(GlutApplicationTrait::KeyIdentifiers::keyCode0 == static_cast<int>('0'));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyCode1 == static_cast<int>('1'));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyCode2 == static_cast<int>('2'));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyCode3 == static_cast<int>('3'));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyCode4 == static_cast<int>('4'));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyCode5 == static_cast<int>('5'));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyCode6 == static_cast<int>('6'));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyCode7 == static_cast<int>('7'));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyCode8 == static_cast<int>('8'));
    static_assert(GlutApplicationTrait::KeyIdentifiers::keyCode9 == static_cast<int>('9'));
}

void Framework::ApplicationTraitTesting::GlutKeyboardModifiersTest() noexcept
{
    static_assert(GlutApplicationTrait::KeyboardModifiers::keyShift == System::EnumCastUnderlying(System::GlutModifiersCodes::Shift));
    static_assert(GlutApplicationTrait::KeyboardModifiers::keyControl == System::EnumCastUnderlying(System::GlutModifiersCodes::Control));
    static_assert(GlutApplicationTrait::KeyboardModifiers::keyAlt == System::EnumCastUnderlying(System::GlutModifiersCodes::Alt));
}

void Framework::ApplicationTraitTesting::GlutMouseButtonsTest() noexcept
{
    static_assert(GlutApplicationTrait::MouseButtons::mouseLeftButton == System::EnumCastUnderlying(System::GlutModifiersCodes::LeftButton));
    static_assert(GlutApplicationTrait::MouseButtons::mouseMiddleButton == System::EnumCastUnderlying(System::GlutModifiersCodes::MiddleButton));
    static_assert(GlutApplicationTrait::MouseButtons::mouseRightButton == System::EnumCastUnderlying(System::GlutModifiersCodes::RightButton));
}

void Framework::ApplicationTraitTesting::GlutMouseStateTest() noexcept
{
    static_assert(GlutApplicationTrait::MouseState::mouseUp == System::EnumCastUnderlying(System::GlutModifiersCodes::Up));
    static_assert(GlutApplicationTrait::MouseState::mouseDown == System::EnumCastUnderlying(System::GlutModifiersCodes::Down));
}

void Framework::ApplicationTraitTesting::GlutMouseModifiersTest() noexcept
{
    static_assert(GlutApplicationTrait::MouseModifiers::modifierControl == System::EnumCastUnderlying(System::GlutModifiersCodes::Control));
    static_assert(GlutApplicationTrait::MouseModifiers::modifierLeftButton == System::EnumCastUnderlying(System::GlutModifiersCodes::LeftButton));
    static_assert(GlutApplicationTrait::MouseModifiers::modifierMiddleButton == System::EnumCastUnderlying(System::GlutModifiersCodes::MiddleButton));
    static_assert(GlutApplicationTrait::MouseModifiers::modifierRightButton == System::EnumCastUnderlying(System::GlutModifiersCodes::RightButton));
    static_assert(GlutApplicationTrait::MouseModifiers::modifierShift == System::EnumCastUnderlying(System::GlutModifiersCodes::Shift));
}

void Framework::ApplicationTraitTesting::AndroidKeyIdentifiersTest() noexcept
{
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyEscape == System::EnumCastUnderlying(System::AndroidKeyCodes::Escape));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyLeftArrow == System::EnumCastUnderlying(System::AndroidKeyCodes::DpadLeft));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyRightArrow == System::EnumCastUnderlying(System::AndroidKeyCodes::DpadRight));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyUpArrow == System::EnumCastUnderlying(System::AndroidKeyCodes::DpadUp));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyDownArrow == System::EnumCastUnderlying(System::AndroidKeyCodes::DpadDown));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyHome == System::EnumCastUnderlying(System::AndroidKeyCodes::MoveHome));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyEnd == System::EnumCastUnderlying(System::AndroidKeyCodes::MoveEnd));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyPageUp == System::EnumCastUnderlying(System::AndroidKeyCodes::PageUp));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyPageDown == System::EnumCastUnderlying(System::AndroidKeyCodes::PageDown));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyInsert == System::EnumCastUnderlying(System::AndroidKeyCodes::Insert));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyDelete == System::EnumCastUnderlying(System::AndroidKeyCodes::Del));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyF1 == System::EnumCastUnderlying(System::AndroidKeyCodes::F1));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyF2 == System::EnumCastUnderlying(System::AndroidKeyCodes::F2));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyF3 == System::EnumCastUnderlying(System::AndroidKeyCodes::F3));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyF4 == System::EnumCastUnderlying(System::AndroidKeyCodes::F4));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyF5 == System::EnumCastUnderlying(System::AndroidKeyCodes::F5));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyF6 == System::EnumCastUnderlying(System::AndroidKeyCodes::F6));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyF7 == System::EnumCastUnderlying(System::AndroidKeyCodes::F7));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyF8 == System::EnumCastUnderlying(System::AndroidKeyCodes::F8));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyF9 == System::EnumCastUnderlying(System::AndroidKeyCodes::F9));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyF10 == System::EnumCastUnderlying(System::AndroidKeyCodes::F10));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyF11 == System::EnumCastUnderlying(System::AndroidKeyCodes::F11));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyF12 == System::EnumCastUnderlying(System::AndroidKeyCodes::F12));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyBackspace == System::EnumCastUnderlying(System::AndroidKeyCodes::Back));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyTab == System::EnumCastUnderlying(System::AndroidKeyCodes::Tab));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyEnter == System::EnumCastUnderlying(System::AndroidKeyCodes::Enter));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyReturn == System::EnumCastUnderlying(System::AndroidKeyCodes::Enter));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyTerminate == System::EnumCastUnderlying(System::AndroidKeyCodes::Escape));

    static_assert(AndroidApplicationTrait::KeyIdentifiers::upperT == static_cast<int>('T'));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::upperR == static_cast<int>('R'));

    static_assert(AndroidApplicationTrait::KeyIdentifiers::lowerT == static_cast<int>('t'));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::lowerR == static_cast<int>('r'));

    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyCode0 == static_cast<int>('0'));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyCode1 == static_cast<int>('1'));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyCode2 == static_cast<int>('2'));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyCode3 == static_cast<int>('3'));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyCode4 == static_cast<int>('4'));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyCode5 == static_cast<int>('5'));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyCode6 == static_cast<int>('6'));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyCode7 == static_cast<int>('7'));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyCode8 == static_cast<int>('8'));
    static_assert(AndroidApplicationTrait::KeyIdentifiers::keyCode9 == static_cast<int>('9'));
}

void Framework::ApplicationTraitTesting::AndroidKeyboardModifiersTest() noexcept
{
    static_assert(AndroidApplicationTrait::KeyboardModifiers::keyShift == 0);
    static_assert(AndroidApplicationTrait::KeyboardModifiers::keyControl == 0);
    static_assert(AndroidApplicationTrait::KeyboardModifiers::keyAlt == 0);
}

void Framework::ApplicationTraitTesting::AndroidMouseButtonsTest() noexcept
{
    static_assert(AndroidApplicationTrait::MouseButtons::mouseLeftButton == 0);
    static_assert(AndroidApplicationTrait::MouseButtons::mouseMiddleButton == 1);
    static_assert(AndroidApplicationTrait::MouseButtons::mouseRightButton == 2);
}

void Framework::ApplicationTraitTesting::AndroidMouseStateTest() noexcept
{
    static_assert(AndroidApplicationTrait::MouseState::mouseUp == 1);
    static_assert(AndroidApplicationTrait::MouseState::mouseDown == 0);
}

void Framework::ApplicationTraitTesting::AndroidMouseModifiersTest() noexcept
{
    static_assert(AndroidApplicationTrait::MouseModifiers::modifierControl == 0x0008);
    static_assert(AndroidApplicationTrait::MouseModifiers::modifierLeftButton == 0x0001);
    static_assert(AndroidApplicationTrait::MouseModifiers::modifierMiddleButton == 0x0010);
    static_assert(AndroidApplicationTrait::MouseModifiers::modifierRightButton == 0x0002);
    static_assert(AndroidApplicationTrait::MouseModifiers::modifierShift == 0x0004);
}

void Framework::ApplicationTraitTesting::LinuxKeyIdentifiersTest() noexcept
{
}

void Framework::ApplicationTraitTesting::LinuxKeyboardModifiersTest() noexcept
{
}

void Framework::ApplicationTraitTesting::LinuxMouseButtonsTest() noexcept
{
    static_assert(LinuxApplicationTrait::MouseButtons::mouseLeftButton == 0);
    static_assert(LinuxApplicationTrait::MouseButtons::mouseMiddleButton == 1);
    static_assert(LinuxApplicationTrait::MouseButtons::mouseRightButton == 2);
}

void Framework::ApplicationTraitTesting::LinuxMouseStateTest() noexcept
{
    static_assert(LinuxApplicationTrait::MouseState::mouseUp == 1);
    static_assert(LinuxApplicationTrait::MouseState::mouseDown == 0);
}

void Framework::ApplicationTraitTesting::LinuxMouseModifiersTest() noexcept
{
}

void Framework::ApplicationTraitTesting::MacintoshKeyIdentifiersTest() noexcept
{
}

void Framework::ApplicationTraitTesting::MacintoshKeyboardModifiersTest() noexcept
{
}

void Framework::ApplicationTraitTesting::MacintoshMouseButtonsTest() noexcept
{
    static_assert(MacintoshApplicationTrait::MouseButtons::mouseLeftButton == 0);
    static_assert(MacintoshApplicationTrait::MouseButtons::mouseMiddleButton == 1);
    static_assert(MacintoshApplicationTrait::MouseButtons::mouseRightButton == 2);
}

void Framework::ApplicationTraitTesting::MacintoshMouseStateTest() noexcept
{
    static_assert(MacintoshApplicationTrait::MouseState::mouseUp == 1);
    static_assert(MacintoshApplicationTrait::MouseState::mouseDown == 0);
}

void Framework::ApplicationTraitTesting::MacintoshMouseModifiersTest() noexcept
{
}
