// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:46)

#ifndef FRAMEWORK_APPLICATION_MOUSE_STATE_H
#define FRAMEWORK_APPLICATION_MOUSE_STATE_H

#include "Framework/FrameworkDll.h"

#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"

namespace Framework
{
	struct WindowMouseState
	{
		static constexpr auto sm_MouseUp = 1;
		static constexpr auto sm_MouseDown = 0;
	};

	struct GlutMouseState
	{
		static constexpr auto sm_MouseUp = System::EnumCastUnderlying(System::GlutModifiersCodes::Up);
		static constexpr auto sm_MouseDown = System::EnumCastUnderlying(System::GlutModifiersCodes::Down);
	};

	struct AndroidMouseState
	{
		static constexpr auto sm_MouseUp = 1;
		static constexpr auto sm_MouseDown = 0;
	};

	struct LinuxMouseState
	{
		static constexpr auto sm_MouseUp = 1;
		static constexpr auto sm_MouseDown = 0;
	};

	struct MacintoshMouseState
	{
		static constexpr auto sm_MouseUp = 1;
		static constexpr auto sm_MouseDown = 0;
	};
}

#endif // FRAMEWORK_APPLICATION_MOUSE_STATE_H
