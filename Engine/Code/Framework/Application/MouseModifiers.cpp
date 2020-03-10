// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:23)

#include "Framework/FrameworkExport.h"

#include "MouseModifiers.h"
#include "System/Window/Flags/WindowsKeyCodesFlags.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"

const int Framework::WindowMouseModifiers::sm_ModifierControl = static_cast<int>(System::WindowsModifiersCodes::Control);
const int Framework::WindowMouseModifiers::sm_ModifierLeftButton = static_cast<int>(System::WindowsModifiersCodes::LeftButton);
const int Framework::WindowMouseModifiers::sm_ModifierMiddleButton = static_cast<int>(System::WindowsModifiersCodes::MiddleButton);
const int Framework::WindowMouseModifiers::sm_ModifierRightButton = static_cast<int>(System::WindowsModifiersCodes::RightButton);
const int Framework::WindowMouseModifiers::sm_ModifierShift = static_cast<int>(System::WindowsModifiersCodes::Shift);

const int Framework::GlutMouseModifiers::sm_ModifierControl = static_cast<int>(System::GlutModifiersCodes::Control);
const int Framework::GlutMouseModifiers::sm_ModifierLeftButton = static_cast<int>(System::GlutModifiersCodes::LeftButton);
const int Framework::GlutMouseModifiers::sm_ModifierMiddleButton = static_cast<int>(System::GlutModifiersCodes::MiddleButton);
const int Framework::GlutMouseModifiers::sm_ModifierRightButton = static_cast<int>(System::GlutModifiersCodes::RightButton);
const int Framework::GlutMouseModifiers::sm_ModifierShift = static_cast<int>(System::GlutModifiersCodes::Shift);

const int Framework::AndroidMouseModifiers::sm_ModifierControl = 0x0008;
const int Framework::AndroidMouseModifiers::sm_ModifierLeftButton = 0x0001;
const int Framework::AndroidMouseModifiers::sm_ModifierMiddleButton = 0x0010;
const int Framework::AndroidMouseModifiers::sm_ModifierRightButton = 0x0002;
const int Framework::AndroidMouseModifiers::sm_ModifierShift = 0x0004;


