///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:34)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderPrintFlagsExist.h"
#include "System/Helper/EnumOperator.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"

using System::operator&;

bool CoreTools::AppenderPrintFlagsExist::IsExist(AppenderPrint lhsAppenderPrintFlags, AppenderPrint rhsAppenderPrint) noexcept
{
    if ((lhsAppenderPrintFlags & rhsAppenderPrint) != AppenderPrint::None)
        return true;
    else
        return false;
}
