// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:23)

#include "Framework/FrameworkExport.h"

#include "KeyIdentifiers.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"
#include "System/Window/Flags/WindowsKeyCodesFlags.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"

const int Framework::WindowKeyIdentifiers::sm_KeyEscape = static_cast<int>(System::WindowsKeyCodes::Escape);
const int Framework::WindowKeyIdentifiers::sm_KeyLeftArrow = static_cast<int>(System::WindowsKeyCodes::Left);
const int Framework::WindowKeyIdentifiers::sm_KeyRightArrow = static_cast<int>(System::WindowsKeyCodes::Right);
const int Framework::WindowKeyIdentifiers::sm_KeyUpArrow = static_cast<int>(System::WindowsKeyCodes::Up);
const int Framework::WindowKeyIdentifiers::sm_KeyDownArrow = static_cast<int>(System::WindowsKeyCodes::Down);
const int Framework::WindowKeyIdentifiers::sm_KeyHome = static_cast<int>(System::WindowsKeyCodes::Home);
const int Framework::WindowKeyIdentifiers::sm_KeyEnd = static_cast<int>(System::WindowsKeyCodes::End);
const int Framework::WindowKeyIdentifiers::sm_KeyPageUp = static_cast<int>(System::WindowsKeyCodes::Prior);
const int Framework::WindowKeyIdentifiers::sm_KeyPageDown = static_cast<int>(System::WindowsKeyCodes::Next);
const int Framework::WindowKeyIdentifiers::sm_KeyInsert = static_cast<int>(System::WindowsKeyCodes::Insert);
const int Framework::WindowKeyIdentifiers::sm_KeyDelete = static_cast<int>(System::WindowsKeyCodes::Delete);
const int Framework::WindowKeyIdentifiers::sm_KeyF1 = static_cast<int>(System::WindowsKeyCodes::F1);
const int Framework::WindowKeyIdentifiers::sm_KeyF2 = static_cast<int>(System::WindowsKeyCodes::F2);
const int Framework::WindowKeyIdentifiers::sm_KeyF3 = static_cast<int>(System::WindowsKeyCodes::F3);
const int Framework::WindowKeyIdentifiers::sm_KeyF4 = static_cast<int>(System::WindowsKeyCodes::F4);
const int Framework::WindowKeyIdentifiers::sm_KeyF5 = static_cast<int>(System::WindowsKeyCodes::F5);
const int Framework::WindowKeyIdentifiers::sm_KeyF6 = static_cast<int>(System::WindowsKeyCodes::F6);
const int Framework::WindowKeyIdentifiers::sm_KeyF7 = static_cast<int>(System::WindowsKeyCodes::F7);
const int Framework::WindowKeyIdentifiers::sm_KeyF8 = static_cast<int>(System::WindowsKeyCodes::F8);
const int Framework::WindowKeyIdentifiers::sm_KeyF9 = static_cast<int>(System::WindowsKeyCodes::F9);
const int Framework::WindowKeyIdentifiers::sm_KeyF10 = static_cast<int>(System::WindowsKeyCodes::F10);
const int Framework::WindowKeyIdentifiers::sm_KeyF11 = static_cast<int>(System::WindowsKeyCodes::F11);
const int Framework::WindowKeyIdentifiers::sm_KeyF12 = static_cast<int>(System::WindowsKeyCodes::F12);
const int Framework::WindowKeyIdentifiers::sm_KeyBackspace = static_cast<int>(System::WindowsKeyCodes::Back);
const int Framework::WindowKeyIdentifiers::sm_KeyTab = static_cast<int>(System::WindowsKeyCodes::Tab);
const int Framework::WindowKeyIdentifiers::sm_KeyEnter = static_cast<int>(System::WindowsKeyCodes::Return);
const int Framework::WindowKeyIdentifiers::sm_KeyReturn = static_cast<int>(System::WindowsKeyCodes::Return);
const int Framework::WindowKeyIdentifiers::sm_KeyTerminate = sm_KeyEscape;

const int Framework::WindowKeyIdentifiers::sm_UpperT = static_cast<int>('T');
const int Framework::WindowKeyIdentifiers::sm_UpperR = static_cast<int>('R');

const int Framework::WindowKeyIdentifiers::sm_LowerT = static_cast<int>('t');
const int Framework::WindowKeyIdentifiers::sm_LowerR = static_cast<int>('r');

const int Framework::GlutKeyIdentifiers::sm_KeyEscape = static_cast<int>(System::GlutKeyCodes::Escape);
const int Framework::GlutKeyIdentifiers::sm_KeyLeftArrow = static_cast<int>(System::GlutKeyCodes::Left);
const int Framework::GlutKeyIdentifiers::sm_KeyRightArrow = static_cast<int>(System::GlutKeyCodes::Right);
const int Framework::GlutKeyIdentifiers::sm_KeyUpArrow = static_cast<int>(System::GlutKeyCodes::Up);
const int Framework::GlutKeyIdentifiers::sm_KeyDownArrow = static_cast<int>(System::GlutKeyCodes::Down);
const int Framework::GlutKeyIdentifiers::sm_KeyHome = static_cast<int>(System::GlutKeyCodes::Home);
const int Framework::GlutKeyIdentifiers::sm_KeyEnd = static_cast<int>(System::GlutKeyCodes::End);
const int Framework::GlutKeyIdentifiers::sm_KeyPageUp = static_cast<int>(System::GlutKeyCodes::PageUp);
const int Framework::GlutKeyIdentifiers::sm_KeyPageDown = static_cast<int>(System::GlutKeyCodes::PageDown);
const int Framework::GlutKeyIdentifiers::sm_KeyInsert = static_cast<int>(System::GlutKeyCodes::Insert);
const int Framework::GlutKeyIdentifiers::sm_KeyDelete = static_cast<int>(System::GlutKeyCodes::Delete);
const int Framework::GlutKeyIdentifiers::sm_KeyF1 = static_cast<int>(System::GlutKeyCodes::F1);
const int Framework::GlutKeyIdentifiers::sm_KeyF2 = static_cast<int>(System::GlutKeyCodes::F2);
const int Framework::GlutKeyIdentifiers::sm_KeyF3 = static_cast<int>(System::GlutKeyCodes::F3);
const int Framework::GlutKeyIdentifiers::sm_KeyF4 = static_cast<int>(System::GlutKeyCodes::F4);
const int Framework::GlutKeyIdentifiers::sm_KeyF5 = static_cast<int>(System::GlutKeyCodes::F5);
const int Framework::GlutKeyIdentifiers::sm_KeyF6 = static_cast<int>(System::GlutKeyCodes::F6);
const int Framework::GlutKeyIdentifiers::sm_KeyF7 = static_cast<int>(System::GlutKeyCodes::F7);
const int Framework::GlutKeyIdentifiers::sm_KeyF8 = static_cast<int>(System::GlutKeyCodes::F8);
const int Framework::GlutKeyIdentifiers::sm_KeyF9 = static_cast<int>(System::GlutKeyCodes::F9);
const int Framework::GlutKeyIdentifiers::sm_KeyF10 = static_cast<int>(System::GlutKeyCodes::F10);
const int Framework::GlutKeyIdentifiers::sm_KeyF11 = static_cast<int>(System::GlutKeyCodes::F11);
const int Framework::GlutKeyIdentifiers::sm_KeyF12 = static_cast<int>(System::GlutKeyCodes::F12);
const int Framework::GlutKeyIdentifiers::sm_KeyBackspace = static_cast<int>(System::GlutKeyCodes::Backspace);
const int Framework::GlutKeyIdentifiers::sm_KeyTab = static_cast<int>(System::GlutKeyCodes::Tab);
const int Framework::GlutKeyIdentifiers::sm_KeyEnter = static_cast<int>(System::GlutKeyCodes::Enter);
const int Framework::GlutKeyIdentifiers::sm_KeyReturn = static_cast<int>(System::GlutKeyCodes::Return);
const int Framework::GlutKeyIdentifiers::sm_KeyTerminate = sm_KeyEscape;

const int Framework::GlutKeyIdentifiers::sm_UpperT = static_cast<int>('T');
const int Framework::GlutKeyIdentifiers::sm_UpperR = static_cast<int>('R');

const int Framework::GlutKeyIdentifiers::sm_LowerT = static_cast<int>('t');
const int Framework::GlutKeyIdentifiers::sm_LowerR = static_cast<int>('r');

const int Framework::AndroidKeyIdentifiers::sm_KeyEscape = static_cast<int>(System::AndroidKeyCodes::Escape);
const int Framework::AndroidKeyIdentifiers::sm_KeyLeftArrow = static_cast<int>(System::AndroidKeyCodes::DpadLeft);
const int Framework::AndroidKeyIdentifiers::sm_KeyRightArrow = static_cast<int>(System::AndroidKeyCodes::DpadRight);
const int Framework::AndroidKeyIdentifiers::sm_KeyUpArrow = static_cast<int>(System::AndroidKeyCodes::DpadUp);
const int Framework::AndroidKeyIdentifiers::sm_KeyDownArrow = static_cast<int>(System::AndroidKeyCodes::DpadDown);
const int Framework::AndroidKeyIdentifiers::sm_KeyHome = static_cast<int>(System::AndroidKeyCodes::MoveHome);
const int Framework::AndroidKeyIdentifiers::sm_KeyEnd = static_cast<int>(System::AndroidKeyCodes::MoveEnd);
const int Framework::AndroidKeyIdentifiers::sm_KeyPageUp = static_cast<int>(System::AndroidKeyCodes::PageUp);
const int Framework::AndroidKeyIdentifiers::sm_KeyPageDown = static_cast<int>(System::AndroidKeyCodes::PageDown);
const int Framework::AndroidKeyIdentifiers::sm_KeyInsert = static_cast<int>(System::AndroidKeyCodes::Insert);
const int Framework::AndroidKeyIdentifiers::sm_KeyDelete = static_cast<int>(System::AndroidKeyCodes::Del);
const int Framework::AndroidKeyIdentifiers::sm_KeyF1 = static_cast<int>(System::AndroidKeyCodes::F1);
const int Framework::AndroidKeyIdentifiers::sm_KeyF2 = static_cast<int>(System::AndroidKeyCodes::F2);
const int Framework::AndroidKeyIdentifiers::sm_KeyF3 = static_cast<int>(System::AndroidKeyCodes::F3);
const int Framework::AndroidKeyIdentifiers::sm_KeyF4 = static_cast<int>(System::AndroidKeyCodes::F4);
const int Framework::AndroidKeyIdentifiers::sm_KeyF5 = static_cast<int>(System::AndroidKeyCodes::F5);
const int Framework::AndroidKeyIdentifiers::sm_KeyF6 = static_cast<int>(System::AndroidKeyCodes::F6);
const int Framework::AndroidKeyIdentifiers::sm_KeyF7 = static_cast<int>(System::AndroidKeyCodes::F7);
const int Framework::AndroidKeyIdentifiers::sm_KeyF8 = static_cast<int>(System::AndroidKeyCodes::F8);
const int Framework::AndroidKeyIdentifiers::sm_KeyF9 = static_cast<int>(System::AndroidKeyCodes::F9);
const int Framework::AndroidKeyIdentifiers::sm_KeyF10 = static_cast<int>(System::AndroidKeyCodes::F10);
const int Framework::AndroidKeyIdentifiers::sm_KeyF11 = static_cast<int>(System::AndroidKeyCodes::F11);
const int Framework::AndroidKeyIdentifiers::sm_KeyF12 = static_cast<int>(System::AndroidKeyCodes::F12);
const int Framework::AndroidKeyIdentifiers::sm_KeyBackspace = static_cast<int>(System::AndroidKeyCodes::Back);
const int Framework::AndroidKeyIdentifiers::sm_KeyTab = static_cast<int>(System::AndroidKeyCodes::Tab);
const int Framework::AndroidKeyIdentifiers::sm_KeyEnter = static_cast<int>(System::AndroidKeyCodes::Enter);
const int Framework::AndroidKeyIdentifiers::sm_KeyReturn = static_cast<int>(System::AndroidKeyCodes::Enter);
const int Framework::AndroidKeyIdentifiers::sm_KeyTerminate = sm_KeyEscape;

const int Framework::AndroidKeyIdentifiers::sm_UpperT = static_cast<int>('T');
const int Framework::AndroidKeyIdentifiers::sm_UpperR = static_cast<int>('R');

const int Framework::AndroidKeyIdentifiers::sm_LowerT = static_cast<int>('t');
const int Framework::AndroidKeyIdentifiers::sm_LowerR = static_cast<int>('r');


