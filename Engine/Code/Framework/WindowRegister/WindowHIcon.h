// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 11:52)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_HICON_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_HICON_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/Using/WindowRegistryUsing.h"
#include "System/Window/Using/WindowPictorialUsing.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowHIcon
	{
	public:
		using ClassType = WindowHIcon;
		using TChar = System::TChar;
		using HIcon = System::WindowHIcon;
		using HInstance = System::WindowHInstance;

	public:
		explicit WindowHIcon(const TChar* icon = System::g_Application) noexcept;
		WindowHIcon(HInstance instance, int icon); 

		static WindowHIcon Create(HInstance instance, bool isDefaultIcon, int icon);

		CLASS_INVARIANT_DECLARE;

		HIcon GetHIcon() const noexcept;

	private:
		void CheckUpHIcon() noexcept;

	private:
		HIcon m_HIcon;
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_HICON_H
