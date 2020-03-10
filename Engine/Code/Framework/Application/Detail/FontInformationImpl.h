// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 10:59)

#ifndef FRAMEWORK_APPLICATION_FONT_INFORMATION_IMPL_H
#define FRAMEWORK_APPLICATION_FONT_INFORMATION_IMPL_H

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Flags/WindowFlags.h"
#include "System/Window/Using/WindowUsing.h"
#include "Framework/Application/ApplicationTrait.h"
 
#include <string>

namespace Framework
{
	class FontInformationImpl
	{
	public:
		using ClassType = FontInformationImpl;
		using FontInformationImplPtr = std::shared_ptr<ClassType>;
		using HWnd = System::WindowHWnd;

	public:
		FontInformationImpl();
		virtual ~FontInformationImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// 字体信息。这些是特定于平台的。
		virtual int GetStringWidth (const System::String& text) const = 0;
		virtual int GetCharacterWidth (const System::TChar character) const = 0;
		virtual int GetFontHeight () const = 0;

		static FontInformationImplPtr CreateWindowFontInformation(HWnd hwnd);

		static FontInformationImplPtr CreateFontInformation(PlatformTypes type);
	};
}

#endif // FRAMEWORK_APPLICATION_FONT_INFORMATION_IMPL_H
