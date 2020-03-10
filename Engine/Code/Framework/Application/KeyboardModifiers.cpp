// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:23)

#include "Framework/FrameworkExport.h"

#include "KeyboardModifiers.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"
#include "System/Window/Flags/WindowsKeyCodesFlags.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"

const int Framework::WindowKeyboardModifiers::sm_KeyShift = static_cast<int>(System::WindowsKeyCodes::Shift);
const int Framework::WindowKeyboardModifiers::sm_KeyControl = static_cast<int>(System::WindowsKeyCodes::Control);
const int Framework::WindowKeyboardModifiers::sm_KeyAlt = 0;
const int Framework::WindowKeyboardModifiers::sm_KeyCommand = 0;

const int Framework::GlutKeyboardModifiers::sm_KeyShift = static_cast<int>(System::GlutModifiersCodes::Shift);
const int Framework::GlutKeyboardModifiers::sm_KeyControl = static_cast<int>(System::GlutModifiersCodes::Control);
const int Framework::GlutKeyboardModifiers::sm_KeyAlt = 0;
const int Framework::GlutKeyboardModifiers::sm_KeyCommand = 0;

const int Framework::AndroidKeyboardModifiers::sm_KeyShift = 0;
const int Framework::AndroidKeyboardModifiers::sm_KeyControl = 0;
const int Framework::AndroidKeyboardModifiers::sm_KeyAlt = 0;
const int Framework::AndroidKeyboardModifiers::sm_KeyCommand = 0;


