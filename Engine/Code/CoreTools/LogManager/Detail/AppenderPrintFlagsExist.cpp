/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:40)

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
