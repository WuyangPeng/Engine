// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 09:45)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_H

#include "Framework/FrameworkDll.h"

#include "WindowPoint.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Flags/WindowFlags.h"
#include "CoreTools/Helper/ExportMacro.h" 

#include <string>

FRAMEWORK_EXPORT_SHARED_PTR(WindowCreateParameterImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowCreateParameter
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(WindowCreateParameter);
		using String = System::String;
		using HWnd = System::WindowHWnd;
		using HMenu = System::WindowHMenu;
		using WindowStyles = System::WindowStyles;

	public:
		WindowCreateParameter(const String& windowsName, WindowStyles style, HWnd parent, HMenu menu, const WindowPoint& leftTopCorner);
		explicit WindowCreateParameter(const String& windowsName);
		WindowCreateParameter(const String& windowsName, WindowStyles style);

		CLASS_INVARIANT_DECLARE;

		const String GetWindowsName() const;
		WindowStyles GetStyle() const noexcept;
		const WindowPoint GetLeftTopCorner() const noexcept;
		HWnd GetParent() const noexcept;
		HMenu GetMenu() const noexcept;

	private:
		IMPL_TYPE_DECLARE(WindowCreateParameter);
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_PARAMETER_H
