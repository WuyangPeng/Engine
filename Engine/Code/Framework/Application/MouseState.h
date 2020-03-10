// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:09)

#ifndef FRAMEWORK_APPLICATION_MOUSE_STATE_H
#define FRAMEWORK_APPLICATION_MOUSE_STATE_H

#include "Framework/FrameworkDll.h"

namespace Framework
{
	struct FRAMEWORK_DEFAULT_DECLARE WindowMouseState
	{
		static const int sm_MouseUp;
		static const int sm_MouseDown;
	};

	struct FRAMEWORK_DEFAULT_DECLARE GlutMouseState
	{
		static const int sm_MouseUp;
		static const int sm_MouseDown;
	};

	struct FRAMEWORK_DEFAULT_DECLARE AndroidMouseState
	{
		static const int sm_MouseUp;
		static const int sm_MouseDown;
	};
}

#endif // FRAMEWORK_APPLICATION_MOUSE_STATE_H
