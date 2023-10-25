///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:54)

#include "CoreTools/CoreToolsExport.h"

#include "ErrorConsoleTextColorsManager.h"
#include "CoreTools/Console/ConsoleTextColorsManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ErrorConsoleTextColorsManager::ErrorConsoleTextColorsManager(LogLevel logLevel)
    : ParentType{ logLevel }, consoleTextColorsManager{ GetTextColor(logLevel), GetIntensified(logLevel) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ErrorConsoleTextColorsManager)
