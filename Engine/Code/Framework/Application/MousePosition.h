// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:09)

#ifndef FRAMEWORK_APPLICATION_MOUSE_POSITION_H
#define FRAMEWORK_APPLICATION_MOUSE_POSITION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Flags/WindowFlags.h"
#include "Framework/WindowCreate/WindowPoint.h"

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

		//  Û±ÍŒª÷√
		const WindowPoint GetMousePosition() const;
		void SetMousePosition (const WindowPoint& windowPoint);

	private:
		;
		IMPL_TYPE_DECLARE(MousePosition);
	};
}

#endif // FRAMEWORK_APPLICATION_MOUSE_POSITION_H
