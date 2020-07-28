// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 10:45)

#ifndef CORE_TOOLS_EXCEPTION_NORMAL_ERROR_H
#define CORE_TOOLS_EXCEPTION_NORMAL_ERROR_H

#include "ErrorImpl.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE NormalError : public ErrorImpl
	{
	public:
		using ClassType = NormalError;
		using ParentType = ErrorImpl;

	public:
		explicit NormalError(const FunctionDescribed& functionDescribed, const String& message);
 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
	};
}

#endif // CORE_TOOLS_EXCEPTION_NORMAL_ERROR_H