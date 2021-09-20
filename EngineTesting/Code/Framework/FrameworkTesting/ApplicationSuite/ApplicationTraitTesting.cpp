// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/11 21:29)

#include "ApplicationTraitTesting.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"
#include "System/Window/Flags/WindowsKeyCodesFlags.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/Application/Flags/ApplicationTrait.h" 

Framework::ApplicationTraitTesting
	::ApplicationTraitTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ApplicationTraitTesting)

void Framework::ApplicationTraitTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ApplicationTraitTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(KeyIdentifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(KeyboardModifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MouseButtonsTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MouseStateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MouseModifiersTest);
}

void Framework::ApplicationTraitTesting
	::KeyIdentifiersTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(WindowKeyIdentifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GlutKeyIdentifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AndroidKeyIdentifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(LinuxKeyIdentifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MacintoshKeyIdentifiersTest);
} 

void Framework::ApplicationTraitTesting
	::KeyboardModifiersTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(WindowKeyboardModifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GlutKeyboardModifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AndroidKeyboardModifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(LinuxKeyboardModifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MacintoshKeyboardModifiersTest);
}

void Framework::ApplicationTraitTesting
	::MouseButtonsTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(WindowMouseButtonsTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GlutMouseButtonsTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AndroidMouseButtonsTest);
	ASSERT_NOT_THROW_EXCEPTION_0(LinuxMouseButtonsTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MacintoshMouseButtonsTest);
}

void Framework::ApplicationTraitTesting
	::MouseStateTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(WindowMouseStateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GlutMouseStateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AndroidMouseStateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(LinuxMouseStateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MacintoshMouseStateTest);
}

void Framework::ApplicationTraitTesting
	::MouseModifiersTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(WindowMouseModifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GlutMouseModifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AndroidMouseModifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(LinuxMouseModifiersTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MacintoshMouseModifiersTest);
}

void Framework::ApplicationTraitTesting
	::WindowKeyIdentifiersTest() noexcept
{
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyEscape == System::EnumCastUnderlying(System::WindowsKeyCodes::Escape));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyLeftArrow == System::EnumCastUnderlying(System::WindowsKeyCodes::Left));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyRightArrow == System::EnumCastUnderlying(System::WindowsKeyCodes::Right));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyUpArrow == System::EnumCastUnderlying(System::WindowsKeyCodes::Up));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyDownArrow == System::EnumCastUnderlying(System::WindowsKeyCodes::Down));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyHome == System::EnumCastUnderlying(System::WindowsKeyCodes::Home));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyEnd == System::EnumCastUnderlying(System::WindowsKeyCodes::End));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyPageUp == System::EnumCastUnderlying(System::WindowsKeyCodes::Prior));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyPageDown == System::EnumCastUnderlying(System::WindowsKeyCodes::Next));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyInsert == System::EnumCastUnderlying(System::WindowsKeyCodes::Insert));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyDelete == System::EnumCastUnderlying(System::WindowsKeyCodes::Delete));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyF1 == System::EnumCastUnderlying(System::WindowsKeyCodes::F1));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyF2 == System::EnumCastUnderlying(System::WindowsKeyCodes::F2));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyF3 == System::EnumCastUnderlying(System::WindowsKeyCodes::F3));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyF4 == System::EnumCastUnderlying(System::WindowsKeyCodes::F4));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyF5 == System::EnumCastUnderlying(System::WindowsKeyCodes::F5));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyF6 == System::EnumCastUnderlying(System::WindowsKeyCodes::F6));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyF7 == System::EnumCastUnderlying(System::WindowsKeyCodes::F7));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyF8 == System::EnumCastUnderlying(System::WindowsKeyCodes::F8));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyF9 == System::EnumCastUnderlying(System::WindowsKeyCodes::F9));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyF10 == System::EnumCastUnderlying(System::WindowsKeyCodes::F10));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyF11 == System::EnumCastUnderlying(System::WindowsKeyCodes::F11));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyF12 == System::EnumCastUnderlying(System::WindowsKeyCodes::F12));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyBackspace == System::EnumCastUnderlying(System::WindowsKeyCodes::Back));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyTab == System::EnumCastUnderlying(System::WindowsKeyCodes::Tab));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyEnter == System::EnumCastUnderlying(System::WindowsKeyCodes::Return));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyReturn == System::EnumCastUnderlying(System::WindowsKeyCodes::Return));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyTerminate == System::EnumCastUnderlying(System::WindowsKeyCodes::Escape));

	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_UpperT == static_cast<int>('T'));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_UpperR == static_cast<int>('R'));

	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_LowerT == static_cast<int>('t'));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_LowerR == static_cast<int>('r'));

	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyCode0 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode0));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyCode1 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode1));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyCode2 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode2));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyCode3 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode3));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyCode4 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode4));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyCode5 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode5));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyCode6 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode6));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyCode7 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode7));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyCode8 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode8));
	static_assert(WindowApplicationTrait::KeyIdentifiers::sm_KeyCode9 == System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode9));
}

void Framework::ApplicationTraitTesting
	::WindowKeyboardModifiersTest() noexcept
{
	static_assert(WindowApplicationTrait::KeyboardModifiers::sm_KeyShift == System::EnumCastUnderlying(System::WindowsKeyCodes::Shift));
	static_assert(WindowApplicationTrait::KeyboardModifiers::sm_KeyControl == System::EnumCastUnderlying(System::WindowsKeyCodes::Control));
	static_assert(WindowApplicationTrait::KeyboardModifiers::sm_KeyAlt == System::EnumCastUnderlying(System::WindowsKeyCodes::Menu));
}

void Framework::ApplicationTraitTesting
	::WindowMouseButtonsTest() noexcept
{
	static_assert(WindowApplicationTrait::MouseButtons::sm_MouseLeftButton == 0);
	static_assert(WindowApplicationTrait::MouseButtons::sm_MouseMiddleButton == 1);
	static_assert(WindowApplicationTrait::MouseButtons::sm_MouseRightButton == 2);
}

void Framework::ApplicationTraitTesting
	::WindowMouseStateTest() noexcept
{
	static_assert(WindowApplicationTrait::MouseState::sm_MouseUp == 1);
	static_assert(WindowApplicationTrait::MouseState::sm_MouseDown == 0);
}

void Framework::ApplicationTraitTesting
	::WindowMouseModifiersTest() noexcept
{
	static_assert(WindowApplicationTrait::MouseModifiers::sm_ModifierControl == System::EnumCastUnderlying(System::WindowsModifiersCodes::Control));
	static_assert(WindowApplicationTrait::MouseModifiers::sm_ModifierLeftButton == System::EnumCastUnderlying(System::WindowsModifiersCodes::LeftButton));
	static_assert(WindowApplicationTrait::MouseModifiers::sm_ModifierMiddleButton == System::EnumCastUnderlying(System::WindowsModifiersCodes::MiddleButton));
	static_assert(WindowApplicationTrait::MouseModifiers::sm_ModifierRightButton == System::EnumCastUnderlying(System::WindowsModifiersCodes::RightButton));
	static_assert(WindowApplicationTrait::MouseModifiers::sm_ModifierShift == System::EnumCastUnderlying(System::WindowsModifiersCodes::Shift));
}

void Framework::ApplicationTraitTesting
	::GlutKeyIdentifiersTest() noexcept
{
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyEscape == System::EnumCastUnderlying(System::GlutKeyCodes::Escape));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyLeftArrow == System::EnumCastUnderlying(System::GlutKeyCodes::Left));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyRightArrow == System::EnumCastUnderlying(System::GlutKeyCodes::Right));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyUpArrow == System::EnumCastUnderlying(System::GlutKeyCodes::Up));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyDownArrow == System::EnumCastUnderlying(System::GlutKeyCodes::Down));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyHome == System::EnumCastUnderlying(System::GlutKeyCodes::Home));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyEnd == System::EnumCastUnderlying(System::GlutKeyCodes::End));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyPageUp == System::EnumCastUnderlying(System::GlutKeyCodes::PageUp));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyPageDown == System::EnumCastUnderlying(System::GlutKeyCodes::PageDown));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyInsert == System::EnumCastUnderlying(System::GlutKeyCodes::Insert));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyDelete == System::EnumCastUnderlying(System::GlutKeyCodes::Delete));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyF1 == System::EnumCastUnderlying(System::GlutKeyCodes::F1));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyF2 == System::EnumCastUnderlying(System::GlutKeyCodes::F2));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyF3 == System::EnumCastUnderlying(System::GlutKeyCodes::F3));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyF4 == System::EnumCastUnderlying(System::GlutKeyCodes::F4));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyF5 == System::EnumCastUnderlying(System::GlutKeyCodes::F5));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyF6 == System::EnumCastUnderlying(System::GlutKeyCodes::F6));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyF7 == System::EnumCastUnderlying(System::GlutKeyCodes::F7));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyF8 == System::EnumCastUnderlying(System::GlutKeyCodes::F8));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyF9 == System::EnumCastUnderlying(System::GlutKeyCodes::F9));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyF10 == System::EnumCastUnderlying(System::GlutKeyCodes::F10));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyF11 == System::EnumCastUnderlying(System::GlutKeyCodes::F11));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyF12 == System::EnumCastUnderlying(System::GlutKeyCodes::F12));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyBackspace == System::EnumCastUnderlying(System::GlutKeyCodes::Backspace));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyTab == System::EnumCastUnderlying(System::GlutKeyCodes::Tab));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyEnter == System::EnumCastUnderlying(System::GlutKeyCodes::Enter));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyReturn == System::EnumCastUnderlying(System::GlutKeyCodes::Return));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyTerminate == System::EnumCastUnderlying(System::GlutKeyCodes::Escape));

	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_UpperT == static_cast<int>('T'));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_UpperR == static_cast<int>('R'));

	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_LowerT == static_cast<int>('t'));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_LowerR == static_cast<int>('r'));

	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyCode0 == static_cast<int>('0'));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyCode1 == static_cast<int>('1'));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyCode2 == static_cast<int>('2'));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyCode3 == static_cast<int>('3'));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyCode4 == static_cast<int>('4'));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyCode5 == static_cast<int>('5'));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyCode6 == static_cast<int>('6'));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyCode7 == static_cast<int>('7'));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyCode8 == static_cast<int>('8'));
	static_assert(GlutApplicationTrait::KeyIdentifiers::sm_KeyCode9 == static_cast<int>('9'));
}

void Framework::ApplicationTraitTesting
	::GlutKeyboardModifiersTest() noexcept
{
	static_assert(GlutApplicationTrait::KeyboardModifiers::sm_KeyShift == System::EnumCastUnderlying(System::GlutModifiersCodes::Shift));
	static_assert(GlutApplicationTrait::KeyboardModifiers::sm_KeyControl == System::EnumCastUnderlying(System::GlutModifiersCodes::Control));
	static_assert(GlutApplicationTrait::KeyboardModifiers::sm_KeyAlt == System::EnumCastUnderlying(System::GlutModifiersCodes::Alt));
}

void Framework::ApplicationTraitTesting
	::GlutMouseButtonsTest() noexcept
{
	static_assert(GlutApplicationTrait::MouseButtons::sm_MouseLeftButton == System::EnumCastUnderlying(System::GlutModifiersCodes::LeftButton));
	static_assert(GlutApplicationTrait::MouseButtons::sm_MouseMiddleButton == System::EnumCastUnderlying(System::GlutModifiersCodes::MiddleButton));
	static_assert(GlutApplicationTrait::MouseButtons::sm_MouseRightButton == System::EnumCastUnderlying(System::GlutModifiersCodes::RightButton));
}

void Framework::ApplicationTraitTesting
	::GlutMouseStateTest() noexcept
{
	static_assert(GlutApplicationTrait::MouseState::sm_MouseUp == System::EnumCastUnderlying(System::GlutModifiersCodes::Up));
	static_assert(GlutApplicationTrait::MouseState::sm_MouseDown == System::EnumCastUnderlying(System::GlutModifiersCodes::Down));
}

void Framework::ApplicationTraitTesting
	::GlutMouseModifiersTest() noexcept
{
	static_assert(GlutApplicationTrait::MouseModifiers::sm_ModifierControl == System::EnumCastUnderlying(System::GlutModifiersCodes::Control));
	static_assert(GlutApplicationTrait::MouseModifiers::sm_ModifierLeftButton == System::EnumCastUnderlying(System::GlutModifiersCodes::LeftButton));
	static_assert(GlutApplicationTrait::MouseModifiers::sm_ModifierMiddleButton == System::EnumCastUnderlying(System::GlutModifiersCodes::MiddleButton));
	static_assert(GlutApplicationTrait::MouseModifiers::sm_ModifierRightButton == System::EnumCastUnderlying(System::GlutModifiersCodes::RightButton));
	static_assert(GlutApplicationTrait::MouseModifiers::sm_ModifierShift == System::EnumCastUnderlying(System::GlutModifiersCodes::Shift));
}

void Framework::ApplicationTraitTesting
	::AndroidKeyIdentifiersTest() noexcept
{
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyEscape == System::EnumCastUnderlying(System::AndroidKeyCodes::Escape));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyLeftArrow == System::EnumCastUnderlying(System::AndroidKeyCodes::DpadLeft));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyRightArrow == System::EnumCastUnderlying(System::AndroidKeyCodes::DpadRight));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyUpArrow == System::EnumCastUnderlying(System::AndroidKeyCodes::DpadUp));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyDownArrow == System::EnumCastUnderlying(System::AndroidKeyCodes::DpadDown));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyHome == System::EnumCastUnderlying(System::AndroidKeyCodes::MoveHome));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyEnd == System::EnumCastUnderlying(System::AndroidKeyCodes::MoveEnd));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyPageUp == System::EnumCastUnderlying(System::AndroidKeyCodes::PageUp));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyPageDown == System::EnumCastUnderlying(System::AndroidKeyCodes::PageDown));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyInsert == System::EnumCastUnderlying(System::AndroidKeyCodes::Insert));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyDelete == System::EnumCastUnderlying(System::AndroidKeyCodes::Del));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyF1 == System::EnumCastUnderlying(System::AndroidKeyCodes::F1));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyF2 == System::EnumCastUnderlying(System::AndroidKeyCodes::F2));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyF3 == System::EnumCastUnderlying(System::AndroidKeyCodes::F3));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyF4 == System::EnumCastUnderlying(System::AndroidKeyCodes::F4));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyF5 == System::EnumCastUnderlying(System::AndroidKeyCodes::F5));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyF6 == System::EnumCastUnderlying(System::AndroidKeyCodes::F6));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyF7 == System::EnumCastUnderlying(System::AndroidKeyCodes::F7));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyF8 == System::EnumCastUnderlying(System::AndroidKeyCodes::F8));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyF9 == System::EnumCastUnderlying(System::AndroidKeyCodes::F9));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyF10 == System::EnumCastUnderlying(System::AndroidKeyCodes::F10));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyF11 == System::EnumCastUnderlying(System::AndroidKeyCodes::F11));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyF12 == System::EnumCastUnderlying(System::AndroidKeyCodes::F12));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyBackspace == System::EnumCastUnderlying(System::AndroidKeyCodes::Back));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyTab == System::EnumCastUnderlying(System::AndroidKeyCodes::Tab));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyEnter == System::EnumCastUnderlying(System::AndroidKeyCodes::Enter));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyReturn == System::EnumCastUnderlying(System::AndroidKeyCodes::Enter));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyTerminate == System::EnumCastUnderlying(System::AndroidKeyCodes::Escape));

	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_UpperT == static_cast<int>('T'));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_UpperR == static_cast<int>('R'));

	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_LowerT == static_cast<int>('t'));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_LowerR == static_cast<int>('r'));

	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyCode0 == static_cast<int>('0'));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyCode1 == static_cast<int>('1'));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyCode2 == static_cast<int>('2'));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyCode3 == static_cast<int>('3'));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyCode4 == static_cast<int>('4'));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyCode5 == static_cast<int>('5'));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyCode6 == static_cast<int>('6'));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyCode7 == static_cast<int>('7'));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyCode8 == static_cast<int>('8'));
	static_assert(AndroidApplicationTrait::KeyIdentifiers::sm_KeyCode9 == static_cast<int>('9'));
}

void Framework::ApplicationTraitTesting
	::AndroidKeyboardModifiersTest() noexcept
{
	static_assert(AndroidApplicationTrait::KeyboardModifiers::sm_KeyShift == 0);
	static_assert(AndroidApplicationTrait::KeyboardModifiers::sm_KeyControl == 0);
	static_assert(AndroidApplicationTrait::KeyboardModifiers::sm_KeyAlt == 0);
}

void Framework::ApplicationTraitTesting
	::AndroidMouseButtonsTest() noexcept
{
	static_assert(AndroidApplicationTrait::MouseButtons::sm_MouseLeftButton == 0);
	static_assert(AndroidApplicationTrait::MouseButtons::sm_MouseMiddleButton == 1);
	static_assert(AndroidApplicationTrait::MouseButtons::sm_MouseRightButton == 2);
}

void Framework::ApplicationTraitTesting
	::AndroidMouseStateTest() noexcept
{
	static_assert(AndroidApplicationTrait::MouseState::sm_MouseUp == 1);
	static_assert(AndroidApplicationTrait::MouseState::sm_MouseDown == 0);
}

void Framework::ApplicationTraitTesting
	::AndroidMouseModifiersTest() noexcept
{
	static_assert(AndroidApplicationTrait::MouseModifiers::sm_ModifierControl == 0x0008);
	static_assert(AndroidApplicationTrait::MouseModifiers::sm_ModifierLeftButton == 0x0001);
	static_assert(AndroidApplicationTrait::MouseModifiers::sm_ModifierMiddleButton == 0x0010);
	static_assert(AndroidApplicationTrait::MouseModifiers::sm_ModifierRightButton == 0x0002);
	static_assert(AndroidApplicationTrait::MouseModifiers::sm_ModifierShift == 0x0004);
}

void Framework::ApplicationTraitTesting
	::LinuxKeyIdentifiersTest() noexcept
{ 
	 
}

void Framework::ApplicationTraitTesting
	::LinuxKeyboardModifiersTest() noexcept
{
 
}

void Framework::ApplicationTraitTesting
	::LinuxMouseButtonsTest() noexcept
{
	static_assert(LinuxApplicationTrait::MouseButtons::sm_MouseLeftButton == 0);
	static_assert(LinuxApplicationTrait::MouseButtons::sm_MouseMiddleButton == 1);
	static_assert(LinuxApplicationTrait::MouseButtons::sm_MouseRightButton == 2);
}

void Framework::ApplicationTraitTesting
	::LinuxMouseStateTest() noexcept
{
	static_assert(LinuxApplicationTrait::MouseState::sm_MouseUp == 1);
	static_assert(LinuxApplicationTrait::MouseState::sm_MouseDown == 0);
}

void Framework::ApplicationTraitTesting
	::LinuxMouseModifiersTest() noexcept
{
	 
}

void Framework::ApplicationTraitTesting
	::MacintoshKeyIdentifiersTest() noexcept
{
	 
}

void Framework::ApplicationTraitTesting
	::MacintoshKeyboardModifiersTest() noexcept
{
	 
}

void Framework::ApplicationTraitTesting
	::MacintoshMouseButtonsTest() noexcept
{
	static_assert(MacintoshApplicationTrait::MouseButtons::sm_MouseLeftButton == 0);
	static_assert(MacintoshApplicationTrait::MouseButtons::sm_MouseMiddleButton == 1);
	static_assert(MacintoshApplicationTrait::MouseButtons::sm_MouseRightButton == 2);
}

void Framework::ApplicationTraitTesting
	::MacintoshMouseStateTest() noexcept
{
	static_assert(MacintoshApplicationTrait::MouseState::sm_MouseUp == 1);
	static_assert(MacintoshApplicationTrait::MouseState::sm_MouseDown == 0);
}

void Framework::ApplicationTraitTesting
	::MacintoshMouseModifiersTest() noexcept
{
	 
}

