// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 13:46)

#ifndef FRAMEWORK_APPLICATION_MOUSE_POSITION_H
#define FRAMEWORK_APPLICATION_MOUSE_POSITION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"

FRAMEWORK_EXPORT_SHARED_PTR(MousePositionImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE MousePosition
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(MousePosition);
		using HWnd = System::WindowHWnd;

	public:
		explicit MousePosition(HWnd hwnd);

		CLASS_INVARIANT_DECLARE;

		// ���λ��
		const WindowPoint GetMousePosition() const;
		void SetMousePosition(const WindowPoint& windowPoint);

	private:		
		IMPL_TYPE_DECLARE(MousePosition);
	};
}

#endif // FRAMEWORK_APPLICATION_MOUSE_POSITION_H
