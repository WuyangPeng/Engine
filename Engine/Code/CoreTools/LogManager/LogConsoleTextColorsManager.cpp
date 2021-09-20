//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 18:57)

#include "CoreTools/CoreToolsExport.h"

#include "LogConsoleTextColorsManager.h"
#include "Detail/LogConsoleTextColorsManagerFactory.h"
#include "Detail/LogConsoleTextColorsManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "../Contract/Flags/ImplFlags.h"

using std::ostream;

CoreTools::LogConsoleTextColorsManager::LogConsoleTextColorsManager(LogLevel logLevel)
    : impl{ CoreTools::ImplCreateUseFactory::Default, logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogConsoleTextColorsManager::LogConsoleTextColorsManager(const OStreamShared& osPtr, LogLevel logLevel)
    : impl{ CoreTools::ImplCreateUseFactory::Default, osPtr, logLevel  }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogConsoleTextColorsManager)
