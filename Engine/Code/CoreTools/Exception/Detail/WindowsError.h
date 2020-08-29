// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 10:45)

#ifndef CORE_TOOLS_EXCEPTION_WINDOWS_ERROR_H
#define CORE_TOOLS_EXCEPTION_WINDOWS_ERROR_H

#include "ErrorImpl.h"
#include "System/Window/Fwd/WindowFlagsFwd.h" 

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE WindowsError : public ErrorImpl
	{
	public:
		using ClassType = WindowsError;
		using ParentType = ErrorImpl;
		using WindowError = System::WindowError;

	public:
		WindowsError(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message);
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const String GetError() const override;

	private:
		WindowError m_LastError;
		String m_WindowsErrorDescribed;
	};
}

#endif // CORE_TOOLS_EXCEPTION_WINDOWS_ERROR_H