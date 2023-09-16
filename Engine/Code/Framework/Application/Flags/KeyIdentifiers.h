///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 14:45)

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
        static constexpr auto keyEscape = EnumCastUnderlying(System::WindowsKeyCodes::Escape);
        static constexpr auto keyLeftArrow = EnumCastUnderlying(System::WindowsKeyCodes::Left);
        static constexpr auto keyRightArrow = EnumCastUnderlying(System::WindowsKeyCodes::Right);
        static constexpr auto keyUpArrow = EnumCastUnderlying(System::WindowsKeyCodes::Up);
        static constexpr auto keyDownArrow = EnumCastUnderlying(System::WindowsKeyCodes::Down);
        static constexpr auto keyHome = EnumCastUnderlying(System::WindowsKeyCodes::Home);
        static constexpr auto keyEnd = EnumCastUnderlying(System::WindowsKeyCodes::End);
        static constexpr auto keyPageUp = EnumCastUnderlying(System::WindowsKeyCodes::Prior);
        static constexpr auto keyPageDown = EnumCastUnderlying(System::WindowsKeyCodes::Next);
        static constexpr auto keyInsert = EnumCastUnderlying(System::WindowsKeyCodes::Insert);
        static constexpr auto keyDelete = EnumCastUnderlying(System::WindowsKeyCodes::Delete);
        static constexpr auto keyF1 = EnumCastUnderlying(System::WindowsKeyCodes::F1);
        static constexpr auto keyF2 = EnumCastUnderlying(System::WindowsKeyCodes::F2);
        static constexpr auto keyF3 = EnumCastUnderlying(System::WindowsKeyCodes::F3);
        static constexpr auto keyF4 = EnumCastUnderlying(System::WindowsKeyCodes::F4);
        static constexpr auto keyF5 = EnumCastUnderlying(System::WindowsKeyCodes::F5);
        static constexpr auto keyF6 = EnumCastUnderlying(System::WindowsKeyCodes::F6);
        static constexpr auto keyF7 = EnumCastUnderlying(System::WindowsKeyCodes::F7);
        static constexpr auto keyF8 = EnumCastUnderlying(System::WindowsKeyCodes::F8);
        static constexpr auto keyF9 = EnumCastUnderlying(System::WindowsKeyCodes::F9);
        static constexpr auto keyF10 = EnumCastUnderlying(System::WindowsKeyCodes::F10);
        static constexpr auto keyF11 = EnumCastUnderlying(System::WindowsKeyCodes::F11);
        static constexpr auto keyF12 = EnumCastUnderlying(System::WindowsKeyCodes::F12);
        static constexpr auto keyBackspace = EnumCastUnderlying(System::WindowsKeyCodes::Back);
        static constexpr auto keyTab = EnumCastUnderlying(System::WindowsKeyCodes::Tab);
        static constexpr auto keyEnter = EnumCastUnderlying(System::WindowsKeyCodes::Return);
        static constexpr auto keyReturn = EnumCastUnderlying(System::WindowsKeyCodes::Return);
        static constexpr auto keyTerminate = keyEscape;

        static constexpr auto upperT = static_cast<int>('T');
        static constexpr auto upperR = static_cast<int>('R');

        static constexpr auto lowerT = static_cast<int>('t');
        static constexpr auto lowerR = static_cast<int>('r');

        static constexpr auto keyCode0 = EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode0);
        static constexpr auto keyCode1 = EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode1);
        static constexpr auto keyCode2 = EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode2);
        static constexpr auto keyCode3 = EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode3);
        static constexpr auto keyCode4 = EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode4);
        static constexpr auto keyCode5 = EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode5);
        static constexpr auto keyCode6 = EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode6);
        static constexpr auto keyCode7 = EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode7);
        static constexpr auto keyCode8 = EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode8);
        static constexpr auto keyCode9 = EnumCastUnderlying(System::WindowsKeyCodes::WindowsKeyCode9);
    };

    struct GlutKeyIdentifiers
    {
        static constexpr auto keyEscape = EnumCastUnderlying(System::GlutKeyCodes::Escape);
        static constexpr auto keyLeftArrow = EnumCastUnderlying(System::GlutKeyCodes::Left);
        static constexpr auto keyRightArrow = EnumCastUnderlying(System::GlutKeyCodes::Right);
        static constexpr auto keyUpArrow = EnumCastUnderlying(System::GlutKeyCodes::Up);
        static constexpr auto keyDownArrow = EnumCastUnderlying(System::GlutKeyCodes::Down);
        static constexpr auto keyHome = EnumCastUnderlying(System::GlutKeyCodes::Home);
        static constexpr auto keyEnd = EnumCastUnderlying(System::GlutKeyCodes::End);
        static constexpr auto keyPageUp = EnumCastUnderlying(System::GlutKeyCodes::PageUp);
        static constexpr auto keyPageDown = EnumCastUnderlying(System::GlutKeyCodes::PageDown);
        static constexpr auto keyInsert = EnumCastUnderlying(System::GlutKeyCodes::Insert);
        static constexpr auto keyDelete = EnumCastUnderlying(System::GlutKeyCodes::Delete);
        static constexpr auto keyF1 = EnumCastUnderlying(System::GlutKeyCodes::F1);
        static constexpr auto keyF2 = EnumCastUnderlying(System::GlutKeyCodes::F2);
        static constexpr auto keyF3 = EnumCastUnderlying(System::GlutKeyCodes::F3);
        static constexpr auto keyF4 = EnumCastUnderlying(System::GlutKeyCodes::F4);
        static constexpr auto keyF5 = EnumCastUnderlying(System::GlutKeyCodes::F5);
        static constexpr auto keyF6 = EnumCastUnderlying(System::GlutKeyCodes::F6);
        static constexpr auto keyF7 = EnumCastUnderlying(System::GlutKeyCodes::F7);
        static constexpr auto keyF8 = EnumCastUnderlying(System::GlutKeyCodes::F8);
        static constexpr auto keyF9 = EnumCastUnderlying(System::GlutKeyCodes::F9);
        static constexpr auto keyF10 = EnumCastUnderlying(System::GlutKeyCodes::F10);
        static constexpr auto keyF11 = EnumCastUnderlying(System::GlutKeyCodes::F11);
        static constexpr auto keyF12 = EnumCastUnderlying(System::GlutKeyCodes::F12);
        static constexpr auto keyBackspace = EnumCastUnderlying(System::GlutKeyCodes::Backspace);
        static constexpr auto keyTab = EnumCastUnderlying(System::GlutKeyCodes::Tab);
        static constexpr auto keyEnter = EnumCastUnderlying(System::GlutKeyCodes::Enter);
        static constexpr auto keyReturn = EnumCastUnderlying(System::GlutKeyCodes::Return);
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
        static constexpr auto keyEscape = EnumCastUnderlying(System::AndroidKeyCodes::Escape);
        static constexpr auto keyLeftArrow = EnumCastUnderlying(System::AndroidKeyCodes::DPadLeft);
        static constexpr auto keyRightArrow = EnumCastUnderlying(System::AndroidKeyCodes::DPadRight);
        static constexpr auto keyUpArrow = EnumCastUnderlying(System::AndroidKeyCodes::DPadUp);
        static constexpr auto keyDownArrow = EnumCastUnderlying(System::AndroidKeyCodes::DPadDown);
        static constexpr auto keyHome = EnumCastUnderlying(System::AndroidKeyCodes::MoveHome);
        static constexpr auto keyEnd = EnumCastUnderlying(System::AndroidKeyCodes::MoveEnd);
        static constexpr auto keyPageUp = EnumCastUnderlying(System::AndroidKeyCodes::PageUp);
        static constexpr auto keyPageDown = EnumCastUnderlying(System::AndroidKeyCodes::PageDown);
        static constexpr auto keyInsert = EnumCastUnderlying(System::AndroidKeyCodes::Insert);
        static constexpr auto keyDelete = EnumCastUnderlying(System::AndroidKeyCodes::Delete);
        static constexpr auto keyF1 = EnumCastUnderlying(System::AndroidKeyCodes::F1);
        static constexpr auto keyF2 = EnumCastUnderlying(System::AndroidKeyCodes::F2);
        static constexpr auto keyF3 = EnumCastUnderlying(System::AndroidKeyCodes::F3);
        static constexpr auto keyF4 = EnumCastUnderlying(System::AndroidKeyCodes::F4);
        static constexpr auto keyF5 = EnumCastUnderlying(System::AndroidKeyCodes::F5);
        static constexpr auto keyF6 = EnumCastUnderlying(System::AndroidKeyCodes::F6);
        static constexpr auto keyF7 = EnumCastUnderlying(System::AndroidKeyCodes::F7);
        static constexpr auto keyF8 = EnumCastUnderlying(System::AndroidKeyCodes::F8);
        static constexpr auto keyF9 = EnumCastUnderlying(System::AndroidKeyCodes::F9);
        static constexpr auto keyF10 = EnumCastUnderlying(System::AndroidKeyCodes::F10);
        static constexpr auto keyF11 = EnumCastUnderlying(System::AndroidKeyCodes::F11);
        static constexpr auto keyF12 = EnumCastUnderlying(System::AndroidKeyCodes::F12);
        static constexpr auto keyBackspace = EnumCastUnderlying(System::AndroidKeyCodes::Back);
        static constexpr auto keyTab = EnumCastUnderlying(System::AndroidKeyCodes::Tab);
        static constexpr auto keyEnter = EnumCastUnderlying(System::AndroidKeyCodes::Enter);
        static constexpr auto keyReturn = EnumCastUnderlying(System::AndroidKeyCodes::Enter);
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
