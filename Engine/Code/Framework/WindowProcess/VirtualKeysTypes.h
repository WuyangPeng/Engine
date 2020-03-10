// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 09:53)

#ifndef FRAMEWORK_WINDOW_PROCESS_VIRTUAL_KEYS_TYPES_H
#define FRAMEWORK_WINDOW_PROCESS_VIRTUAL_KEYS_TYPES_H

#include "Framework/FrameworkDll.h" 

#include "MouseTypes.h"
#include "System/Window/Flags/WindowFlags.h"
#include "System/Window/Using/WindowUsing.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE VirtualKeysTypes
	{
	public:
		using ClassType = VirtualKeysTypes;
		using WParam = System::WindowWParam;

	public:
		// ֻ֧��GLUT
		VirtualKeysTypes();

		// ֻ֧��Window
		explicit VirtualKeysTypes(WParam wParam);

		CLASS_INVARIANT_DECLARE;

		bool IsCtrlKeyDown() const;
		bool IsLeftMouseDown() const;
		bool IsMiddleMouseDown() const;
		bool IsRightMouseDown() const;
		bool IsShiftKeyDown() const;
		bool IsMouseDown() const;

		// ֻ֧��GLUT
		void SetModifiers(int modifiers);
		void SetMouseButtonsTypes(int button);
		void ClearMouseButtonsTypes();

	private:
		bool m_IsCtrlKeyDown;
		bool m_IsLeftMouseDown;
		bool m_IsMiddleMouseDown;
		bool m_IsRightMouseDown;
		bool m_IsShiftKeyDown;
	};
}



#endif // FRAMEWORK_WINDOW_PROCESS_VIRTUAL_KEYS_TYPES_H
