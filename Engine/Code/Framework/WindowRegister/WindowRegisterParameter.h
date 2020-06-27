// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 11:53)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_PARAMETER_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_PARAMETER_H

#include "Framework/FrameworkDll.h"

#include "System/Window/Flags/WindowFlags.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/Flags/WindowClassStyleFlags.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowRegisterParameter
	{
	public:
		using ClassType = WindowRegisterParameter;
		using HInstance = System::WindowHInstance;
		using WindowClassStyle = System::WindowClassStyle;

	public:
		explicit WindowRegisterParameter(HInstance instance, WindowClassStyle styles = WindowClassStyle::CommonUse,
										 int windowClassExtra = 0, int windowExtra = 0);

		CLASS_INVARIANT_DECLARE;

		HInstance GetHInstance() const noexcept;
		WindowClassStyle GetStyle() const noexcept;
		int GetWindowClassExtra() const noexcept;
		int GetWindowExtra() const noexcept;

	private:
		HInstance m_Instance;
		WindowClassStyle m_Style;
		int m_WindowClassExtra;
		int m_WindowExtra;
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_WINDOW_REGISTER_PARAMETER_H