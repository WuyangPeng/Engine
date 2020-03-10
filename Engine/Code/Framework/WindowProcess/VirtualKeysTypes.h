// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 09:53)

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
		// 只支持GLUT
		VirtualKeysTypes();

		// 只支持Window
		explicit VirtualKeysTypes(WParam wParam);

		CLASS_INVARIANT_DECLARE;

		bool IsCtrlKeyDown() const;
		bool IsLeftMouseDown() const;
		bool IsMiddleMouseDown() const;
		bool IsRightMouseDown() const;
		bool IsShiftKeyDown() const;
		bool IsMouseDown() const;

		// 只支持GLUT
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
