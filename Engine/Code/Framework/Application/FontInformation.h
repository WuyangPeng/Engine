// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 13:43)

#ifndef FRAMEWORK_APPLICATION_FONT_INFORMATION_H
#define FRAMEWORK_APPLICATION_FONT_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "Flags/ApplicationTrait.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
FRAMEWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(FontInformationImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE FontInformation
	{
	public:
            PERFORMANCE_UNSHARED_TYPE_DECLARE(FontInformation);
		using TChar = System::TChar;
		using String = System::String;
		using HWnd = System::WindowsHWnd;

	public:
		// GLUT 平台
		explicit FontInformation(PlatformTypes type);

		// Window 平台
		explicit FontInformation(HWnd hwnd);

		CLASS_INVARIANT_DECLARE;

		// 字体信息。这些是特定于平台的。
		int GetStringWidth(const String& text) const;
		int GetCharacterWidth(const TChar character) const;
		int GetFontHeight() const;

	private:
                PackageType impl;
	};
}

#endif // FRAMEWORK_APPLICATION_FONT_INFORMATION_H
