//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 18:47)

#include "CoreTools/CoreToolsExport.h"

#include "OutputConsoleTextColorsManager.h"
#include "CoreTools/Console/ConsoleTextColorsManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::OutputConsoleTextColorsManager::OutputConsoleTextColorsManager(LogLevel logLevel)
    : ParentType{ logLevel }, m_ConsoleTextColorsManager{ GetTextColor(logLevel), GetIntensified(logLevel) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, OutputConsoleTextColorsManager)
