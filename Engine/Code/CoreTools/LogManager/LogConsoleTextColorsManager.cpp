/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:43)

#include "CoreTools/CoreToolsExport.h"

#include "LogConsoleTextColorsManager.h"
#include "Detail/LogConsoleTextColorsManagerFactory.h"
#include "Detail/LogConsoleTextColorsManagerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::LogConsoleTextColorsManager::LogConsoleTextColorsManager(LogLevel logLevel)
    : impl{ CoreTools::ImplCreateUseFactory::Default, logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogConsoleTextColorsManager::LogConsoleTextColorsManager(const OStreamShared& streamShared, LogLevel logLevel)
    : impl{ CoreTools::ImplCreateUseFactory::Default, streamShared, logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogConsoleTextColorsManager)
