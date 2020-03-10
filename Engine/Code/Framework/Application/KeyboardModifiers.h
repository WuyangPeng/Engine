// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:09)

#ifndef FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H
#define FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H

#include "Framework/FrameworkDll.h"

namespace Framework
{
	struct FRAMEWORK_DEFAULT_DECLARE WindowKeyboardModifiers
	{
		static const int sm_KeyShift;
		static const int sm_KeyControl;
		static const int sm_KeyAlt; // 目前无法处理
		static const int sm_KeyCommand; // 目前无法处理
	};

	struct FRAMEWORK_DEFAULT_DECLARE GlutKeyboardModifiers
	{
		static const int sm_KeyShift;
		static const int sm_KeyControl;
		static const int sm_KeyAlt; // 目前无法处理
		static const int sm_KeyCommand; // 目前无法处理
	};

	struct FRAMEWORK_DEFAULT_DECLARE AndroidKeyboardModifiers
	{
		static const int sm_KeyShift; // 目前无法处理
		static const int sm_KeyControl; // 目前无法处理
		static const int sm_KeyAlt; // 目前无法处理
		static const int sm_KeyCommand; // 目前无法处理
	};
}

#endif // FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H
