// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:42)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_HICON_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_HICON_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Flags/WindowFlags.h"
#include "System/Window/Flags/WindowPictorialFlags.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/Using/WindowPictorialUsing.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowHIcon
	{
	public:
		using ClassType = WindowHIcon;
		using HInstance = System::WindowHInstance;
		using HIcon = System::WindowHIcon;

	public:
		explicit WindowHIcon(const System::TChar* icon = IDI_APPLICATION);
		WindowHIcon(HInstance hInstance,int icon);

		CLASS_INVARIANT_DECLARE;

		HIcon GetHIcon() const;

	private:
		void CheckUpHIcon();

	private:
		HIcon m_HIcon;
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_HICON_H
