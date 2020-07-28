// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.1 (2020/01/20 10:21)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderPrintFlagsExist.h" 
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"

bool CoreTools::AppenderPrintFlagsExist
	::IsExist(AppenderPrint lhsAppenderPrintFlags, AppenderPrint rhsAppenderPrint) noexcept
{
	if ((lhsAppenderPrintFlags & rhsAppenderPrint) != AppenderPrint::None)
		return true;
	else
		return false;
}
