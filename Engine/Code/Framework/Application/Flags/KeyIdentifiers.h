///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/05 19:01)

#ifndef FRAMEWORK_APPLICATION_KEY_IDENTIFIERS_H
#define FRAMEWORK_APPLICATION_KEY_IDENTIFIERS_H

#include "Framework/FrameworkDll.h"

#include "System/Android/Flags/AndroidKeyCodesFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"

// 按键标识符。这些是特定于平台的。
// 包含这个头文件需要考虑opengl的包含顺序。先包含这个头文件，再包含freeglut等opengl文件。
namespace Framework
{
    struct WindowKeyIdentifiers
    {
        static constexpr auto keyEscape = System::EnumCastUnderlying(System::WindowsKeyCodes::Escape);
        static constexpr auto keyLeftArrow = System::EnumCastUnderlying(System::WindowsKeyCodes::Left);
        static constexpr auto keyRightArrow = System::EnumCastUnderlying(System::WindowsKeyCodes::Right);
        static constexpr auto keyUpArrow = System::EnumCastUnderlying(System::WindowsKeyCodes::Up);
        static constexpr auto keyDownArrow = System::EnumCastUnderlying(System::WindowsKeyCodes::Down);
        static constexpr auto keyHome = System::EnumCastUnderlying(System::WindowsKeyCodes::Home);
        static constexpr auto keyEnd = System::EnumCastUnderlying(System::WindowsKeyCodes::End);
        static constexpr auto keyPageUp = System::EnumCastUnderlying(System::WindowsKeyCodes::Prior);
        static constexpr auto keyPageDown = System::EnumCastUnderlying(System::WindowsKeyCodes::Next);
        static constexpr auto keyInsert = System::EnumCastUnderlying(System::WindowsKeyCodes::Insert);
        static constexpr auto keyDelete = System::EnumCastUnderlying(System::WindowsKeyCodes::Delete);
        static constexpr auto keyF1 = System::EnumCastUnderlying(System::WindowsKeyCodes::F1);
        static constexpr auto keyF2 = System::EnumCastUnderlying(System::WindowsKeyCodes::F2);
        static constexpr auto keyF3 = System::EnumCastUnderlying(System::WindowsKeyCodes::F3);
        static constexpr auto keyF4 = System::EnumCastUnderlying(System::WindowsKeyCodes::F4);
        static constexpr auto keyF5 = System::EnumCastUnderlying(System::WindowsKeyCodes::F5);
        static constexpr auto keyF6 = System::EnumCastUnderlying(System::WindowsKeyCodes::F6);
        static constexpr auto keyF7 = System::EnumCastUnderlying(System::WindowsKeyCodes::F7);
        static constexpr auto keyF8 = System::EnumCastUnderlying(System::WindowsKeyCodes::F8);
        static constexpr auto keyF9 = System::EnumCastUnderlying(System::WindowsKeyCodes::F9);
        static constexpr auto keyF10 = System::EnumCastUnderlying(System::WindowsKeyCodes::F10);
        static constexpr auto keyF11 = System::EnumCastUnderlying(System::WindowsKeyCodes::F11);
        static constexpr auto keyF12 = System::EnumCastUnderlying(System::WindowsKeyCodes::F12);
        static constexpr auto keyBackspace = System::EnumCastUnderlying(System::WindowsKeyCodes::Back);
        static constexpr auto keyTab = System::EnumCastUnderlying(System::WindowsKeyCodes::Tab);
        static constexpr auto keyEnter = System::EnumCastUnderlying(System::WindowsKeyCodes::Return);
        static constexpr auto keyReturn = System::EnumCastUnderlying(System::WindowsKeyCodes::Return);
        static constexpr auto keyTerminate = keyEscape;

        static constexpr auto upperT = static_cast<int>('T');
        static constexpr auto upperR = static_cast<int>('R');

        static constexpr auto lowerT = static_cast<int>('t');
        static constexpr auto lowerR = static_cast<int>('r');

        static constexpr auto keyCode0 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode0);
        static constexpr auto keyCode1 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode1);
        static constexpr auto keyCode2 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode2);
        static constexpr auto keyCode3 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode3);
        static constexpr auto keyCode4 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode4);
        static constexpr auto keyCode5 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode5);
        static constexpr auto keyCode6 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode6);
        static constexpr auto keyCode7 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode7);
        static constexpr auto keyCode8 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode8);
        static constexpr auto keyCode9 = System::EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode9);
    };

    struct GlutKeyIdentifiers
    {
        static constexpr auto keyEscape = System::EnumCastUnderlying(System::GlutKeyCodes::Escape);
        static constexpr auto keyLeftArrow = System::EnumCastUnderlying(System::GlutKeyCodes::Left);
        static constexpr auto keyRightArrow = System::EnumCastUnderlying(System::GlutKeyCodes::Right);
        static constexpr auto keyUpArrow = System::EnumCastUnderlying(System::GlutKeyCodes::Up);
        static constexpr auto keyDownArrow = System::EnumCastUnderlying(System::GlutKeyCodes::Down);
        static constexpr auto keyHome = System::EnumCastUnderlying(System::GlutKeyCodes::Home);
        static constexpr auto keyEnd = System::EnumCastUnderlying(System::GlutKeyCodes::End);
        static constexpr auto keyPageUp = System::EnumCastUnderlying(System::GlutKeyCodes::PageUp);
        static constexpr auto keyPageDown = System::EnumCastUnderlying(System::GlutKeyCodes::PageDown);
        static constexpr auto keyInsert = System::EnumCastUnderlying(System::GlutKeyCodes::Insert);
        static constexpr auto keyDelete = System::EnumCastUnderlying(System::GlutKeyCodes::Delete);
        static constexpr auto keyF1 = System::EnumCastUnderlying(System::GlutKeyCodes::F1);
        static constexpr auto keyF2 = System::EnumCastUnderlying(System::GlutKeyCodes::F2);
        static constexpr auto keyF3 = System::EnumCastUnderlying(System::GlutKeyCodes::F3);
        static constexpr auto keyF4 = System::EnumCastUnderlying(System::GlutKeyCodes::F4);
        static constexpr auto keyF5 = System::EnumCastUnderlying(System::GlutKeyCodes::F5);
        static constexpr auto keyF6 = System::EnumCastUnderlying(System::GlutKeyCodes::F6);
        static constexpr auto keyF7 = System::EnumCastUnderlying(System::GlutKeyCodes::F7);
        static constexpr auto keyF8 = System::EnumCastUnderlying(System::GlutKeyCodes::F8);
        static constexpr auto keyF9 = System::EnumCastUnderlying(System::GlutKeyCodes::F9);
        static constexpr auto keyF10 = System::EnumCastUnderlying(System::GlutKeyCodes::F10);
        static constexpr auto keyF11 = System::EnumCastUnderlying(System::GlutKeyCodes::F11);
        static constexpr auto keyF12 = System::EnumCastUnderlying(System::GlutKeyCodes::F12);
        static constexpr auto keyBackspace = System::EnumCastUnderlying(System::GlutKeyCodes::Backspace);
        static constexpr auto keyTab = System::EnumCastUnderlying(System::GlutKeyCodes::Tab);
        static constexpr auto keyEnter = System::EnumCastUnderlying(System::GlutKeyCodes::Enter);
        static constexpr auto keyReturn = System::EnumCastUnderlying(System::GlutKeyCodes::Return);
        static constexpr auto keyTerminate = keyEscape;

        static constexpr auto upperT = static_cast<int>('T');
        static constexpr auto upperR = static_cast<int>('R');

        static constexpr auto lowerT = static_cast<int>('t');
        static constexpr auto lowerR = static_cast<int>('r');

        static constexpr auto keyCode0 = static_cast<int>('0');
        static constexpr auto keyCode1 = static_cast<int>('1');
        static constexpr auto keyCode2 = static_cast<int>('2');
        static constexpr auto keyCode3 = static_cast<int>('3');
        static constexpr auto keyCode4 = static_cast<int>('4');
        static constexpr auto keyCode5 = static_cast<int>('5');
        static constexpr auto keyCode6 = static_cast<int>('6');
        static constexpr auto keyCode7 = static_cast<int>('7');
        static constexpr auto keyCode8 = static_cast<int>('8');
        static constexpr auto keyCode9 = static_cast<int>('9');
    };

    struct AndroidKeyIdentifiers
    {
        static constexpr auto keyEscape = System::EnumCastUnderlying(System::AndroidKeyCodes::Escape);
        static constexpr auto keyLeftArrow = System::EnumCastUnderlying(System::AndroidKeyCodes::DpadLeft);
        static constexpr auto keyRightArrow = System::EnumCastUnderlying(System::AndroidKeyCodes::DpadRight);
        static constexpr auto keyUpArrow = System::EnumCastUnderlying(System::AndroidKeyCodes::DpadUp);
        static constexpr auto keyDownArrow = System::EnumCastUnderlying(System::AndroidKeyCodes::DpadDown);
        static constexpr auto keyHome = System::EnumCastUnderlying(System::AndroidKeyCodes::MoveHome);
        static constexpr auto keyEnd = System::EnumCastUnderlying(System::AndroidKeyCodes::MoveEnd);
        static constexpr auto keyPageUp = System::EnumCastUnderlying(System::AndroidKeyCodes::PageUp);
        static constexpr auto keyPageDown = System::EnumCastUnderlying(System::AndroidKeyCodes::PageDown);
        static constexpr auto keyInsert = System::EnumCastUnderlying(System::AndroidKeyCodes::Insert);
        static constexpr auto keyDelete = System::EnumCastUnderlying(System::AndroidKeyCodes::Delete);
        static constexpr auto keyF1 = System::EnumCastUnderlying(System::AndroidKeyCodes::F1);
        static constexpr auto keyF2 = System::EnumCastUnderlying(System::AndroidKeyCodes::F2);
        static constexpr auto keyF3 = System::EnumCastUnderlying(System::AndroidKeyCodes::F3);
        static constexpr auto keyF4 = System::EnumCastUnderlying(System::AndroidKeyCodes::F4);
        static constexpr auto keyF5 = System::EnumCastUnderlying(System::AndroidKeyCodes::F5);
        static constexpr auto keyF6 = System::EnumCastUnderlying(System::AndroidKeyCodes::F6);
        static constexpr auto keyF7 = System::EnumCastUnderlying(System::AndroidKeyCodes::F7);
        static constexpr auto keyF8 = System::EnumCastUnderlying(System::AndroidKeyCodes::F8);
        static constexpr auto keyF9 = System::EnumCastUnderlying(System::AndroidKeyCodes::F9);
        static constexpr auto keyF10 = System::EnumCastUnderlying(System::AndroidKeyCodes::F10);
        static constexpr auto keyF11 = System::EnumCastUnderlying(System::AndroidKeyCodes::F11);
        static constexpr auto keyF12 = System::EnumCastUnderlying(System::AndroidKeyCodes::F12);
        static constexpr auto keyBackspace = System::EnumCastUnderlying(System::AndroidKeyCodes::Back);
        static constexpr auto keyTab = System::EnumCastUnderlying(System::AndroidKeyCodes::Tab);
        static constexpr auto keyEnter = System::EnumCastUnderlying(System::AndroidKeyCodes::Enter);
        static constexpr auto keyReturn = System::EnumCastUnderlying(System::AndroidKeyCodes::Enter);
        static constexpr auto keyTerminate = keyEscape;

        static constexpr auto upperT = static_cast<int>('T');
        static constexpr auto upperR = static_cast<int>('R');

        static constexpr auto lowerT = static_cast<int>('t');
        static constexpr auto lowerR = static_cast<int>('r');

        static constexpr auto keyCode0 = static_cast<int>('0');
        static constexpr auto keyCode1 = static_cast<int>('1');
        static constexpr auto keyCode2 = static_cast<int>('2');
        static constexpr auto keyCode3 = static_cast<int>('3');
        static constexpr auto keyCode4 = static_cast<int>('4');
        static constexpr auto keyCode5 = static_cast<int>('5');
        static constexpr auto keyCode6 = static_cast<int>('6');
        static constexpr auto keyCode7 = static_cast<int>('7');
        static constexpr auto keyCode8 = static_cast<int>('8');
        static constexpr auto keyCode9 = static_cast<int>('9');
    };

    struct LinuxKeyIdentifiers
    {
        static constexpr auto keyEscape = 0;
        static constexpr auto keyLeftArrow = 0;
        static constexpr auto keyRightArrow = 0;
        static constexpr auto keyUpArrow = 0;
        static constexpr auto keyDownArrow = 0;
        static constexpr auto keyHome = 0;
        static constexpr auto keyEnd = 0;
        static constexpr auto keyPageUp = 0;
        static constexpr auto keyPageDown = 0;
        static constexpr auto keyInsert = 0;
        static constexpr auto keyDelete = 0;
        static constexpr auto keyF1 = 0;
        static constexpr auto keyF2 = 0;
        static constexpr auto keyF3 = 0;
        static constexpr auto keyF4 = 0;
        static constexpr auto keyF5 = 0;
        static constexpr auto keyF6 = 0;
        static constexpr auto keyF7 = 0;
        static constexpr auto keyF8 = 0;
        static constexpr auto keyF9 = 0;
        static constexpr auto keyF10 = 0;
        static constexpr auto keyF11 = 0;
        static constexpr auto keyF12 = 0;
        static constexpr auto keyBackspace = 0;
        static constexpr auto keyTab = 0;
        static constexpr auto keyEnter = 0;
        static constexpr auto keyReturn = 0;
        static constexpr auto keyTerminate = keyEscape;

        static constexpr auto upperT = static_cast<int>('T');
        static constexpr auto upperR = static_cast<int>('R');

        static constexpr auto lowerT = static_cast<int>('t');
        static constexpr auto lowerR = static_cast<int>('r');

        static constexpr auto keyCode0 = static_cast<int>('0');
        static constexpr auto keyCode1 = static_cast<int>('1');
        static constexpr auto keyCode2 = static_cast<int>('2');
        static constexpr auto keyCode3 = static_cast<int>('3');
        static constexpr auto keyCode4 = static_cast<int>('4');
        static constexpr auto keyCode5 = static_cast<int>('5');
        static constexpr auto keyCode6 = static_cast<int>('6');
        static constexpr auto keyCode7 = static_cast<int>('7');
        static constexpr auto keyCode8 = static_cast<int>('8');
        static constexpr auto keyCode9 = static_cast<int>('9');
    };

    struct MacintoshKeyIdentifiers
    {
        static constexpr auto keyEscape = 0;
        static constexpr auto keyLeftArrow = 0;
        static constexpr auto keyRightArrow = 0;
        static constexpr auto keyUpArrow = 0;
        static constexpr auto keyDownArrow = 0;
        static constexpr auto keyHome = 0;
        static constexpr auto keyEnd = 0;
        static constexpr auto keyPageUp = 0;
        static constexpr auto keyPageDown = 0;
        static constexpr auto keyInsert = 0;
        static constexpr auto keyDelete = 0;
        static constexpr auto keyF1 = 0;
        static constexpr auto keyF2 = 0;
        static constexpr auto keyF3 = 0;
        static constexpr auto keyF4 = 0;
        static constexpr auto keyF5 = 0;
        static constexpr auto keyF6 = 0;
        static constexpr auto keyF7 = 0;
        static constexpr auto keyF8 = 0;
        static constexpr auto keyF9 = 0;
        static constexpr auto keyF10 = 0;
        static constexpr auto keyF11 = 0;
        static constexpr auto keyF12 = 0;
        static constexpr auto keyBackspace = 0;
        static constexpr auto keyTab = 0;
        static constexpr auto keyEnter = 0;
        static constexpr auto keyReturn = 0;
        static constexpr auto keyTerminate = keyEscape;

        static constexpr auto upperT = static_cast<int>('T');
        static constexpr auto upperR = static_cast<int>('R');

        static constexpr auto lowerT = static_cast<int>('t');
        static constexpr auto lowerR = static_cast<int>('r');

        static constexpr auto keyCode0 = static_cast<int>('0');
        static constexpr auto keyCode1 = static_cast<int>('1');
        static constexpr auto keyCode2 = static_cast<int>('2');
        static constexpr auto keyCode3 = static_cast<int>('3');
        static constexpr auto keyCode4 = static_cast<int>('4');
        static constexpr auto keyCode5 = static_cast<int>('5');
        static constexpr auto keyCode6 = static_cast<int>('6');
        static constexpr auto keyCode7 = static_cast<int>('7');
        static constexpr auto keyCode8 = static_cast<int>('8');
        static constexpr auto keyCode9 = static_cast<int>('9');
    };
}

#endif  // FRAMEWORK_APPLICATION_KEY_IDENTIFIERS_H
