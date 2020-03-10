// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 10:46)

#ifndef CORE_TOOLS_EXCEPTION_LAST_ERROR_H
#define CORE_TOOLS_EXCEPTION_LAST_ERROR_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Window/Fwd/WindowFlagsFwd.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE LastError
	{
	public:
		using ClassType = LastError;
		using WindowError = System::WindowError;

	public:
		LastError();
		~LastError();

		CLASS_INVARIANT_DECLARE;

		WindowError GetLastError() const noexcept;

	private:
		WindowError m_LastError;
	};
}

#endif // CORE_TOOLS_EXCEPTION_LAST_ERROR_H