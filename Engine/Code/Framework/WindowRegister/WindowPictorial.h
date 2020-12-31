// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 11:53)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/Using/WindowPictorialUsing.h"
#include "System/Window/Flags/WindowPictorialFlags.h"

FRAMEWORK_EXPORT_SHARED_PTR(WindowPictorialImpl);

namespace Framework
{
	// 窗口图示类的声明
	class FRAMEWORK_DEFAULT_DECLARE WindowPictorial
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(WindowPictorial);
		using TChar = System::TChar;
		using HIcon = System::WindowHIcon;
		using HCursor = System::WindowHCursor;
		using HBrush = System::WindowHBrush;
		using HInstance = System::WindowHInstance;
		using WindowBrushTypes = System::WindowBrushTypes;

	public:
		explicit WindowPictorial(WindowBrushTypes background);
		WindowPictorial(const TChar* icon, const TChar* cursor, WindowBrushTypes background = WindowBrushTypes::WhiteBrush);
		WindowPictorial(HInstance instance, int icon, int cursor, WindowBrushTypes background = WindowBrushTypes::WhiteBrush);
		WindowPictorial(HInstance instance, int icon, const TChar* cursor, WindowBrushTypes background = WindowBrushTypes::WhiteBrush);
		WindowPictorial(HInstance instance, const TChar* icon, int cursor, WindowBrushTypes background = WindowBrushTypes::WhiteBrush);
		WindowPictorial(HInstance instance, bool isDefaultIcon, int icon, bool isDefaultCursor, int cursor, WindowBrushTypes background = WindowBrushTypes::WhiteBrush);

		CLASS_INVARIANT_DECLARE;

		HIcon GetHIcon() const noexcept;
		HCursor GetHCursor() const noexcept;
		HBrush GetHBrush() const noexcept;

	private:
		IMPL_TYPE_DECLARE(WindowsPictorial);
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_H
