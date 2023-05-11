///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 14:53)

#include "CoreTools/CoreToolsExport.h"

#include "Log.h"
#include "LogHelperDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogHelper)

void CoreTools::LogHelper::Process(const LogMessage& logMessage)
{
    LOG_SINGLETON.Write(logMessage);
}