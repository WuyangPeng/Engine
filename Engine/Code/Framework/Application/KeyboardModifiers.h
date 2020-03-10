// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:09)

#ifndef FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H
#define FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H

#include "Framework/FrameworkDll.h"

namespace Framework
{
	struct FRAMEWORK_DEFAULT_DECLARE WindowKeyboardModifiers
	{
		static const int sm_KeyShift;
		static const int sm_KeyControl;
		static const int sm_KeyAlt; // Ŀǰ�޷�����
		static const int sm_KeyCommand; // Ŀǰ�޷�����
	};

	struct FRAMEWORK_DEFAULT_DECLARE GlutKeyboardModifiers
	{
		static const int sm_KeyShift;
		static const int sm_KeyControl;
		static const int sm_KeyAlt; // Ŀǰ�޷�����
		static const int sm_KeyCommand; // Ŀǰ�޷�����
	};

	struct FRAMEWORK_DEFAULT_DECLARE AndroidKeyboardModifiers
	{
		static const int sm_KeyShift; // Ŀǰ�޷�����
		static const int sm_KeyControl; // Ŀǰ�޷�����
		static const int sm_KeyAlt; // Ŀǰ�޷�����
		static const int sm_KeyCommand; // Ŀǰ�޷�����
	};
}

#endif // FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H
