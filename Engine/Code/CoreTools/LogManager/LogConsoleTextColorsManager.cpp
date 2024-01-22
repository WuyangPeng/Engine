/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:43)

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
