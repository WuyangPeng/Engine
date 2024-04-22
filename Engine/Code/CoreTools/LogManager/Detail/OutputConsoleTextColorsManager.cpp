/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:05)

#include "CoreTools/CoreToolsExport.h"

#include "OutputConsoleTextColorsManager.h"
#include "CoreTools/Console/ConsoleInstanceDetail.h"
#include "CoreTools/Console/ConsoleTextColorsManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::OutputConsoleTextColorsManager::OutputConsoleTextColorsManager(LogLevel logLevel)
    : ParentType{ logLevel }, consoleTextColorsManager{ GetTextColor(logLevel), GetIntensified(logLevel) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, OutputConsoleTextColorsManager)
