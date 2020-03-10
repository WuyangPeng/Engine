// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 10:45)

#ifndef CORE_TOOLS_EXCEPTION_ERROR_FACTORY_H
#define CORE_TOOLS_EXCEPTION_ERROR_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"
#include "CoreTools/Exception/ExceptionFwd.h"
#include "CoreTools/ClassInvariant/ClassInvariantFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
	class ErrorImpl;

	class CORE_TOOLS_HIDDEN_DECLARE ErrorFactory
	{
	public:
		using ClassType = ErrorFactory;
		using String = System::String;
		using WindowError = System::WindowError;
		using ErrorImplPtr = std::shared_ptr<ErrorImpl>;

		static ErrorImplPtr CreateError(const FunctionDescribed& functionDescribed, const LastError& lastError, const String& message);
		static ErrorImplPtr CreateError(const FunctionDescribed& functionDescribed, WindowError lastError, const String& message);
	};
}

#endif // CORE_TOOLS_EXCEPTION_ERROR_FACTORY_H