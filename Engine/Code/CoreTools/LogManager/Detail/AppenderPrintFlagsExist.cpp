//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 18:31)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderPrintFlagsExist.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"

bool CoreTools::AppenderPrintFlagsExist::IsExist(AppenderPrint lhsAppenderPrintFlags, AppenderPrint rhsAppenderPrint) noexcept
{
    if ((lhsAppenderPrintFlags & rhsAppenderPrint) != AppenderPrint::None)
        return true;
    else
        return false;
}
