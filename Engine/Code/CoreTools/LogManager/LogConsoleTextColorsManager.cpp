//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/15 18:57)

#include "CoreTools/CoreToolsExport.h"

#include "LogConsoleTextColorsManager.h"
#include "Detail/LogConsoleTextColorsManagerFactory.h"
#include "Detail/LogConsoleTextColorsManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::ostream;

CoreTools::LogConsoleTextColorsManager::LogConsoleTextColorsManager(LogLevel logLevel)
    : m_Impl{ LogConsoleTextColorsManagerFactory::Create(logLevel) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogConsoleTextColorsManager::LogConsoleTextColorsManager(const OStreamShared& osPtr, LogLevel logLevel)
    : m_Impl{ LogConsoleTextColorsManagerFactory::Create(osPtr, logLevel) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, LogConsoleTextColorsManager)
