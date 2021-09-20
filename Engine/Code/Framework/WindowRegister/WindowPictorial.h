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
#include "System/Windows/Using/WindowsUsing.h"
#include "System/Windows/Using/WindowsPictorialUsing.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
FRAMEWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(WindowPictorialImpl);

namespace Framework
{
	// 窗口图示类的声明
	class FRAMEWORK_DEFAULT_DECLARE WindowPictorial
	{
	public:
		PERFORMANCE_UNSHARED_TYPE_DECLARE(WindowPictorial);
		using TChar = System::TChar;
		using HIcon = System::WindowsHIcon;
		using HCursor = System::WindowsHCursor;
		using HBrush = System::WindowsHBrush;
		using HInstance = System::WindowsHInstance;
		using WindowBrushTypes = System::WindowsBrushTypes;

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
                PackageType impl;
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_H
