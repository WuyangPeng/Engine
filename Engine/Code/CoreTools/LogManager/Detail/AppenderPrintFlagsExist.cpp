///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:54)

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
