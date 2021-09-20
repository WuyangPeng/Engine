// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 09:44)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_IMPL_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <string>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowInstanceParameterImpl
	{
	public:
		using ClassType = WindowInstanceParameterImpl;
		using String = System::String;
		using HInstance = System::WindowsHInstance;

	public:
		WindowInstanceParameterImpl(HInstance instance, const String& className);

		CLASS_INVARIANT_DECLARE;

		HInstance GetHInstance() const noexcept;
		String GetWindowClassName() const;

	private:
		HInstance m_HInstance;
		String m_ClassName;
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_INSTANCE_PARAMETER_IMPL_H