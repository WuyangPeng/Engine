// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 10:47)

#ifndef FRAMEWORK_WINDOW_PROCESS_VIRTUAL_KEYS_TYPES_H
#define FRAMEWORK_WINDOW_PROCESS_VIRTUAL_KEYS_TYPES_H

#include "Framework/FrameworkDll.h" 

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
		VirtualKeysTypes() noexcept = default;

		// ֻ֧��Window
		explicit VirtualKeysTypes(WParam wParam) noexcept;

		CLASS_INVARIANT_DECLARE;

		bool IsCtrlKeyDown() const noexcept;
		bool IsLeftMouseDown() const noexcept;
		bool IsMiddleMouseDown() const noexcept;
		bool IsRightMouseDown() const noexcept;
		bool IsShiftKeyDown() const noexcept;
		bool IsMouseDown() const noexcept;

		// ֻ֧��GLUT
		void SetModifiers(int modifiers) noexcept;
		void SetMouseButtonsTypes(int button) noexcept;
		void ClearMouseButtonsTypes() noexcept;
		void ClearKeyDownTypes() noexcept;

	private:
		bool m_IsCtrlKeyDown{ false };
		bool m_IsLeftMouseDown{ false };
		bool m_IsMiddleMouseDown{ false };
		bool m_IsRightMouseDown{ false };
		bool m_IsShiftKeyDown{ false };
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_VIRTUAL_KEYS_TYPES_H
