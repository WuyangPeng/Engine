// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 13:43)

#ifndef FRAMEWORK_APPLICATION_KEY_IDENTIFIERS_H
#define FRAMEWORK_APPLICATION_KEY_IDENTIFIERS_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/EnumCast.h"
#include "System/Window/Flags/WindowsKeyCodesFlags.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h" 

// 按键标识符。这些是特定于平台的。
// 包含这个头文件需要考虑opengl的包含顺序。先包含这个头文件，再包含freeglut等opengl文件。
namespace Framework
{
	struct WindowKeyIdentifiers
	{
		static constexpr auto sm_KeyEscape = System::EnumCastUnderlying(System::WindowsKeyCodes::Escape);
		static constexpr auto sm_KeyLeftArrow = System::EnumCastUnderlying(System::WindowsKeyCodes::Left);
		static constexpr auto sm_KeyRightArrow = System::EnumCastUnderlying(System::WindowsKeyCodes::Right);
		static constexpr auto sm_KeyUpArrow = System::EnumCastUnderlying(System::WindowsKeyCodes::Up);
		static constexpr auto sm_KeyDownArrow = System::EnumCastUnderlying(System::WindowsKeyCodes::Down);
		static constexpr auto sm_KeyHome = System::EnumCastUnderlying(System::WindowsKeyCodes::Home);
		static constexpr auto sm_KeyEnd = System::EnumCastUnderlying(System::WindowsKeyCodes::End);
		static constexpr auto sm_KeyPageUp = System::EnumCastUnderlying(System::WindowsKeyCodes::Prior);
		static constexpr auto sm_KeyPageDown = System::EnumCastUnderlying(System::WindowsKeyCodes::Next);
		static constexpr auto sm_KeyInsert = System::EnumCastUnderlying(System::WindowsKeyCodes::Insert);
		static constexpr auto sm_KeyDelete = System::EnumCastUnderlying(System::WindowsKeyCodes::Delete);
		static constexpr auto sm_KeyF1 = System::EnumCastUnderlying(System::WindowsKeyCodes::F1);
		static constexpr auto sm_KeyF2 = System::EnumCastUnderlying(System::WindowsKeyCodes::F2);
		static constexpr auto sm_KeyF3 = System::EnumCastUnderlying(System::WindowsKeyCodes::F3);
		static constexpr auto sm_KeyF4 = System::EnumCastUnderlying(System::WindowsKeyCodes::F4);
		static constexpr auto sm_KeyF5 = System::EnumCastUnderlying(System::WindowsKeyCodes::F5);
		static constexpr auto sm_KeyF6 = System::EnumCastUnderlying(System::WindowsKeyCodes::F6);
		static constexpr auto sm_KeyF7 = System::EnumCastUnderlying(System::WindowsKeyCodes::F7);
		static constexpr auto sm_KeyF8 = System::EnumCastUnderlying(System::WindowsKeyCodes::F8);
		static constexpr auto sm_KeyF9 = System::EnumCastUnderlying(System::WindowsKeyCodes::F9);
		static constexpr auto sm_KeyF10 = System::EnumCastUnderlying(System::WindowsKeyCodes::F10);
		static constexpr auto sm_KeyF11 = System::EnumCastUnderlying(System::WindowsKeyCodes::F11);
		static constexpr auto sm_KeyF12 = System::EnumCastUnderlying(System::WindowsKeyCodes::F12);
		static constexpr auto sm_KeyBackspace = System::EnumCastUnderlying(System::WindowsKeyCodes::Back);
		static constexpr auto sm_KeyTab = System::EnumCastUnderlying(System::WindowsKeyCodes::Tab);
		static constexpr auto sm_KeyEnter = System::EnumCastUnderlying(System::WindowsKeyCodes::Return);
		static constexpr auto sm_KeyReturn = System::EnumCastUnderlying(System::WindowsKeyCodes::Return);
		static constexpr auto sm_KeyTerminate = sm_KeyEscape;

		static constexpr auto sm_UpperT = static_cast<int>('T');
		static constexpr auto sm_UpperR = static_cast<int>('R');

		static constexpr auto sm_LowerT = static_cast<int>('t');
		static constexpr auto sm_LowerR = static_cast<int>('r');

		static constexpr auto sm_KeyCode0 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode0);
		static constexpr auto sm_KeyCode1 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode1);
		static constexpr auto sm_KeyCode2 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode2);
		static constexpr auto sm_KeyCode3 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode3);
		static constexpr auto sm_KeyCode4 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode4);
		static constexpr auto sm_KeyCode5 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode5);
		static constexpr auto sm_KeyCode6 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode6);
		static constexpr auto sm_KeyCode7 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode7);
		static constexpr auto sm_KeyCode8 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode8);
		static constexpr auto sm_KeyCode9 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode9);
	};

	struct GlutKeyIdentifiers
	{
		static constexpr auto sm_KeyEscape = System::EnumCastUnderlying(System::GlutKeyCodes::Escape);
		static constexpr auto sm_KeyLeftArrow = System::EnumCastUnderlying(System::GlutKeyCodes::Left);
		static constexpr auto sm_KeyRightArrow = System::EnumCastUnderlying(System::GlutKeyCodes::Right);
		static constexpr auto sm_KeyUpArrow = System::EnumCastUnderlying(System::GlutKeyCodes::Up);
		static constexpr auto sm_KeyDownArrow = System::EnumCastUnderlying(System::GlutKeyCodes::Down);
		static constexpr auto sm_KeyHome = System::EnumCastUnderlying(System::GlutKeyCodes::Home);
		static constexpr auto sm_KeyEnd = System::EnumCastUnderlying(System::GlutKeyCodes::End);
		static constexpr auto sm_KeyPageUp = System::EnumCastUnderlying(System::GlutKeyCodes::PageUp);
		static constexpr auto sm_KeyPageDown = System::EnumCastUnderlying(System::GlutKeyCodes::PageDown);
		static constexpr auto sm_KeyInsert = System::EnumCastUnderlying(System::GlutKeyCodes::Insert);
		static constexpr auto sm_KeyDelete = System::EnumCastUnderlying(System::GlutKeyCodes::Delete);
		static constexpr auto sm_KeyF1 = System::EnumCastUnderlying(System::GlutKeyCodes::F1);
		static constexpr auto sm_KeyF2 = System::EnumCastUnderlying(System::GlutKeyCodes::F2);
		static constexpr auto sm_KeyF3 = System::EnumCastUnderlying(System::GlutKeyCodes::F3);
		static constexpr auto sm_KeyF4 = System::EnumCastUnderlying(System::GlutKeyCodes::F4);
		static constexpr auto sm_KeyF5 = System::EnumCastUnderlying(System::GlutKeyCodes::F5);
		static constexpr auto sm_KeyF6 = System::EnumCastUnderlying(System::GlutKeyCodes::F6);
		static constexpr auto sm_KeyF7 = System::EnumCastUnderlying(System::GlutKeyCodes::F7);
		static constexpr auto sm_KeyF8 = System::EnumCastUnderlying(System::GlutKeyCodes::F8);
		static constexpr auto sm_KeyF9 = System::EnumCastUnderlying(System::GlutKeyCodes::F9);
		static constexpr auto sm_KeyF10 = System::EnumCastUnderlying(System::GlutKeyCodes::F10);
		static constexpr auto sm_KeyF11 = System::EnumCastUnderlying(System::GlutKeyCodes::F11);
		static constexpr auto sm_KeyF12 = System::EnumCastUnderlying(System::GlutKeyCodes::F12);
		static constexpr auto sm_KeyBackspace = System::EnumCastUnderlying(System::GlutKeyCodes::Backspace);
		static constexpr auto sm_KeyTab = System::EnumCastUnderlying(System::GlutKeyCodes::Tab);
		static constexpr auto sm_KeyEnter = System::EnumCastUnderlying(System::GlutKeyCodes::Enter);
		static constexpr auto sm_KeyReturn = System::EnumCastUnderlying(System::GlutKeyCodes::Return);
		static constexpr auto sm_KeyTerminate = sm_KeyEscape;

		static constexpr auto sm_UpperT = static_cast<int>('T');
		static constexpr auto sm_UpperR = static_cast<int>('R');

		static constexpr auto sm_LowerT = static_cast<int>('t');
		static constexpr auto sm_LowerR = static_cast<int>('r');

		static constexpr auto sm_KeyCode0 = static_cast<int>('0');
		static constexpr auto sm_KeyCode1 = static_cast<int>('1');
		static constexpr auto sm_KeyCode2 = static_cast<int>('2');
		static constexpr auto sm_KeyCode3 = static_cast<int>('3');
		static constexpr auto sm_KeyCode4 = static_cast<int>('4');
		static constexpr auto sm_KeyCode5 = static_cast<int>('5');
		static constexpr auto sm_KeyCode6 = static_cast<int>('6');
		static constexpr auto sm_KeyCode7 = static_cast<int>('7');
		static constexpr auto sm_KeyCode8 = static_cast<int>('8');
		static constexpr auto sm_KeyCode9 = static_cast<int>('9');
	};

	struct AndroidKeyIdentifiers
	{
		static constexpr auto sm_KeyEscape = System::EnumCastUnderlying(System::AndroidKeyCodes::Escape);
		static constexpr auto sm_KeyLeftArrow = System::EnumCastUnderlying(System::AndroidKeyCodes::DpadLeft);
		static constexpr auto sm_KeyRightArrow = System::EnumCastUnderlying(System::AndroidKeyCodes::DpadRight);
		static constexpr auto sm_KeyUpArrow = System::EnumCastUnderlying(System::AndroidKeyCodes::DpadUp);
		static constexpr auto sm_KeyDownArrow = System::EnumCastUnderlying(System::AndroidKeyCodes::DpadDown);
		static constexpr auto sm_KeyHome = System::EnumCastUnderlying(System::AndroidKeyCodes::MoveHome);
		static constexpr auto sm_KeyEnd = System::EnumCastUnderlying(System::AndroidKeyCodes::MoveEnd);
		static constexpr auto sm_KeyPageUp = System::EnumCastUnderlying(System::AndroidKeyCodes::PageUp);
		static constexpr auto sm_KeyPageDown = System::EnumCastUnderlying(System::AndroidKeyCodes::PageDown);
		static constexpr auto sm_KeyInsert = System::EnumCastUnderlying(System::AndroidKeyCodes::Insert);
		static constexpr auto sm_KeyDelete = System::EnumCastUnderlying(System::AndroidKeyCodes::Del);
		static constexpr auto sm_KeyF1 = System::EnumCastUnderlying(System::AndroidKeyCodes::F1);
		static constexpr auto sm_KeyF2 = System::EnumCastUnderlying(System::AndroidKeyCodes::F2);
		static constexpr auto sm_KeyF3 = System::EnumCastUnderlying(System::AndroidKeyCodes::F3);
		static constexpr auto sm_KeyF4 = System::EnumCastUnderlying(System::AndroidKeyCodes::F4);
		static constexpr auto sm_KeyF5 = System::EnumCastUnderlying(System::AndroidKeyCodes::F5);
		static constexpr auto sm_KeyF6 = System::EnumCastUnderlying(System::AndroidKeyCodes::F6);
		static constexpr auto sm_KeyF7 = System::EnumCastUnderlying(System::AndroidKeyCodes::F7);
		static constexpr auto sm_KeyF8 = System::EnumCastUnderlying(System::AndroidKeyCodes::F8);
		static constexpr auto sm_KeyF9 = System::EnumCastUnderlying(System::AndroidKeyCodes::F9);
		static constexpr auto sm_KeyF10 = System::EnumCastUnderlying(System::AndroidKeyCodes::F10);
		static constexpr auto sm_KeyF11 = System::EnumCastUnderlying(System::AndroidKeyCodes::F11);
		static constexpr auto sm_KeyF12 = System::EnumCastUnderlying(System::AndroidKeyCodes::F12);
		static constexpr auto sm_KeyBackspace = System::EnumCastUnderlying(System::AndroidKeyCodes::Back);
		static constexpr auto sm_KeyTab = System::EnumCastUnderlying(System::AndroidKeyCodes::Tab);
		static constexpr auto sm_KeyEnter = System::EnumCastUnderlying(System::AndroidKeyCodes::Enter);
		static constexpr auto sm_KeyReturn = System::EnumCastUnderlying(System::AndroidKeyCodes::Enter);
		static constexpr auto sm_KeyTerminate = sm_KeyEscape;

		static constexpr auto sm_UpperT = static_cast<int>('T');
		static constexpr auto sm_UpperR = static_cast<int>('R');

		static constexpr auto sm_LowerT = static_cast<int>('t');
		static constexpr auto sm_LowerR = static_cast<int>('r');

		static constexpr auto sm_KeyCode0 = static_cast<int>('0');
		static constexpr auto sm_KeyCode1 = static_cast<int>('1');
		static constexpr auto sm_KeyCode2 = static_cast<int>('2');
		static constexpr auto sm_KeyCode3 = static_cast<int>('3');
		static constexpr auto sm_KeyCode4 = static_cast<int>('4');
		static constexpr auto sm_KeyCode5 = static_cast<int>('5');
		static constexpr auto sm_KeyCode6 = static_cast<int>('6');
		static constexpr auto sm_KeyCode7 = static_cast<int>('7');
		static constexpr auto sm_KeyCode8 = static_cast<int>('8');
		static constexpr auto sm_KeyCode9 = static_cast<int>('9');
	};

	struct LinuxKeyIdentifiers
	{
		static constexpr auto sm_KeyEscape = 0;
		static constexpr auto sm_KeyLeftArrow = 0;
		static constexpr auto sm_KeyRightArrow = 0;
		static constexpr auto sm_KeyUpArrow = 0;
		static constexpr auto sm_KeyDownArrow = 0;
		static constexpr auto sm_KeyHome = 0;
		static constexpr auto sm_KeyEnd = 0;
		static constexpr auto sm_KeyPageUp = 0;
		static constexpr auto sm_KeyPageDown = 0;
		static constexpr auto sm_KeyInsert = 0;
		static constexpr auto sm_KeyDelete = 0;
		static constexpr auto sm_KeyF1 = 0;
		static constexpr auto sm_KeyF2 = 0;
		static constexpr auto sm_KeyF3 = 0;
		static constexpr auto sm_KeyF4 = 0;
		static constexpr auto sm_KeyF5 = 0;
		static constexpr auto sm_KeyF6 = 0;
		static constexpr auto sm_KeyF7 = 0;
		static constexpr auto sm_KeyF8 = 0;
		static constexpr auto sm_KeyF9 = 0;
		static constexpr auto sm_KeyF10 = 0;
		static constexpr auto sm_KeyF11 = 0;
		static constexpr auto sm_KeyF12 = 0;
		static constexpr auto sm_KeyBackspace = 0;
		static constexpr auto sm_KeyTab = 0;
		static constexpr auto sm_KeyEnter = 0;
		static constexpr auto sm_KeyReturn = 0;
		static constexpr auto sm_KeyTerminate = sm_KeyEscape;

		static constexpr auto sm_UpperT = static_cast<int>('T');
		static constexpr auto sm_UpperR = static_cast<int>('R');

		static constexpr auto sm_LowerT = static_cast<int>('t');
		static constexpr auto sm_LowerR = static_cast<int>('r');

		static constexpr auto sm_KeyCode0 = static_cast<int>('0');
		static constexpr auto sm_KeyCode1 = static_cast<int>('1');
		static constexpr auto sm_KeyCode2 = static_cast<int>('2');
		static constexpr auto sm_KeyCode3 = static_cast<int>('3');
		static constexpr auto sm_KeyCode4 = static_cast<int>('4');
		static constexpr auto sm_KeyCode5 = static_cast<int>('5');
		static constexpr auto sm_KeyCode6 = static_cast<int>('6');
		static constexpr auto sm_KeyCode7 = static_cast<int>('7');
		static constexpr auto sm_KeyCode8 = static_cast<int>('8');
		static constexpr auto sm_KeyCode9 = static_cast<int>('9');
	};

	struct MacintoshKeyIdentifiers
	{
		static constexpr auto sm_KeyEscape = 0;
		static constexpr auto sm_KeyLeftArrow = 0;
		static constexpr auto sm_KeyRightArrow = 0;
		static constexpr auto sm_KeyUpArrow = 0;
		static constexpr auto sm_KeyDownArrow = 0;
		static constexpr auto sm_KeyHome = 0;
		static constexpr auto sm_KeyEnd = 0;
		static constexpr auto sm_KeyPageUp = 0;
		static constexpr auto sm_KeyPageDown = 0;
		static constexpr auto sm_KeyInsert = 0;
		static constexpr auto sm_KeyDelete = 0;
		static constexpr auto sm_KeyF1 = 0;
		static constexpr auto sm_KeyF2 = 0;
		static constexpr auto sm_KeyF3 = 0;
		static constexpr auto sm_KeyF4 = 0;
		static constexpr auto sm_KeyF5 = 0;
		static constexpr auto sm_KeyF6 = 0;
		static constexpr auto sm_KeyF7 = 0;
		static constexpr auto sm_KeyF8 = 0;
		static constexpr auto sm_KeyF9 = 0;
		static constexpr auto sm_KeyF10 = 0;
		static constexpr auto sm_KeyF11 = 0;
		static constexpr auto sm_KeyF12 = 0;
		static constexpr auto sm_KeyBackspace = 0;
		static constexpr auto sm_KeyTab = 0;
		static constexpr auto sm_KeyEnter = 0;
		static constexpr auto sm_KeyReturn = 0;
		static constexpr auto sm_KeyTerminate = sm_KeyEscape;

		static constexpr auto sm_UpperT = static_cast<int>('T');
		static constexpr auto sm_UpperR = static_cast<int>('R');

		static constexpr auto sm_LowerT = static_cast<int>('t');
		static constexpr auto sm_LowerR = static_cast<int>('r');

		static constexpr auto sm_KeyCode0 = static_cast<int>('0');
		static constexpr auto sm_KeyCode1 = static_cast<int>('1');
		static constexpr auto sm_KeyCode2 = static_cast<int>('2');
		static constexpr auto sm_KeyCode3 = static_cast<int>('3');
		static constexpr auto sm_KeyCode4 = static_cast<int>('4');
		static constexpr auto sm_KeyCode5 = static_cast<int>('5');
		static constexpr auto sm_KeyCode6 = static_cast<int>('6');
		static constexpr auto sm_KeyCode7 = static_cast<int>('7');
		static constexpr auto sm_KeyCode8 = static_cast<int>('8');
		static constexpr auto sm_KeyCode9 = static_cast<int>('9');
	};
}

#endif // FRAMEWORK_APPLICATION_KEY_IDENTIFIERS_H
