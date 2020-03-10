// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:08)

#ifndef FRAMEWORK_APPLICATION_FONT_INFORMATION_H
#define FRAMEWORK_APPLICATION_FONT_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/Flags/WindowFlags.h"
#include "ApplicationTrait.h"
 
#include <string>

FRAMEWORK_EXPORT_SHARED_PTR(FontInformationImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE FontInformation
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(FontInformation);
		using HWnd = System::WindowHWnd;

	public:
		// GLUT 平台
		explicit FontInformation(PlatformTypes type);

		// Window 平台
		explicit FontInformation(HWnd hwnd);

		CLASS_INVARIANT_DECLARE;

		// 字体信息。这些是特定于平台的。
		int GetStringWidth (const System::String& text) const;
		int GetCharacterWidth (const System::TChar character) const;
		int GetFontHeight () const;

	private:
		IMPL_TYPE_DECLARE(FontInformation);
	};

}

#endif // FRAMEWORK_APPLICATION_FONT_INFORMATION_H
