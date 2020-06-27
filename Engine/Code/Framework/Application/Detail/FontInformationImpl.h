// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 13:38)

#ifndef FRAMEWORK_APPLICATION_FONT_INFORMATION_IMPL_H
#define FRAMEWORK_APPLICATION_FONT_INFORMATION_IMPL_H

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Flags/WindowFlags.h"
#include "System/Window/Using/WindowUsing.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

#include <memory>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE FontInformationImpl
	{
	public:
		using ClassType = FontInformationImpl;
		using FontInformationImplSharedPtr = std::shared_ptr<ClassType>;
		using TChar = System::TChar;
		using String = System::String;
		using HWnd = System::WindowHWnd;

	public:
		FontInformationImpl() noexcept = default;
		virtual ~FontInformationImpl() noexcept = default;
		FontInformationImpl(const FontInformationImpl&) noexcept = default;
		FontInformationImpl(FontInformationImpl&&) noexcept = default;
		FontInformationImpl& operator=(const FontInformationImpl&) noexcept = default;
		FontInformationImpl& operator=(FontInformationImpl&&) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// 字体信息。这些是特定于平台的。
		virtual int GetStringWidth(const String& text) const = 0;
		virtual int GetCharacterWidth(const TChar character) const = 0;
		virtual int GetFontHeight() const = 0;

		static FontInformationImplSharedPtr CreateWindowFontInformation(HWnd hwnd);
		static FontInformationImplSharedPtr CreateFontInformation(PlatformTypes type);
	};
}

#endif // FRAMEWORK_APPLICATION_FONT_INFORMATION_IMPL_H
