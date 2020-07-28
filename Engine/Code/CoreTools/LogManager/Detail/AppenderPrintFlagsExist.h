// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 18:05)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_PRINT_FLAGS_EXIST_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_PRINT_FLAGS_EXIST_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/LogManager/LogManagerFwd.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE AppenderPrintFlagsExist
	{
	public:
		static bool IsExist(AppenderPrint lhsAppenderPrintFlags, AppenderPrint rhsAppenderPrintFlags) noexcept;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_APPENDER_PRINT_FLAGS_EXIST_H
