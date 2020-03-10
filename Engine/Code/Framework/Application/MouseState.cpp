// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:24)

#include "Framework/FrameworkExport.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"

#include "MouseState.h"

const int Framework::WindowMouseState::sm_MouseUp = 0;
const int Framework::WindowMouseState::sm_MouseDown = 1;

const int Framework::GlutMouseState::sm_MouseUp = static_cast<int>(System::GlutModifiersCodes::Up);
const int Framework::GlutMouseState::sm_MouseDown = static_cast<int>(System::GlutModifiersCodes::Down);

const int Framework::AndroidMouseState::sm_MouseUp = 0;
const int Framework::AndroidMouseState::sm_MouseDown = 1;


