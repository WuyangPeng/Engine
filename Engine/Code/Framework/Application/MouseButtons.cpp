// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:23)

#include "Framework/FrameworkExport.h"

#include "MouseButtons.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"

const int Framework::WindowMouseButtons::sm_MouseLeftButton = 0;
const int Framework::WindowMouseButtons::sm_MouseMiddleButton= 1;
const int Framework::WindowMouseButtons::sm_MouseRightButton = 2;

const int Framework::GlutMouseButtons::sm_MouseLeftButton = static_cast<int>( System::GlutModifiersCodes::LeftButton);
const int Framework::GlutMouseButtons::sm_MouseMiddleButton = static_cast<int>(System::GlutModifiersCodes::MiddleButton);
const int Framework::GlutMouseButtons::sm_MouseRightButton = static_cast<int>(System::GlutModifiersCodes::RightButton);

const int Framework::AndroidMouseButtons::sm_MouseLeftButton = 0;
const int Framework::AndroidMouseButtons::sm_MouseMiddleButton= 1;
const int Framework::AndroidMouseButtons::sm_MouseRightButton = 2;

