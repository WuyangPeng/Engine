///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 16:12)

#include "CoreTools/CoreToolsExport.h"

#include "LogLevelManager.h"
#include "Flags/LogManagerFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

using namespace std::literals;

System::String CoreTools::LogLevelManager::GetLogLevelDescribe(LogLevel logLevelType)
{
    switch (logLevelType)
    {
        case LogLevel::Disabled:
            return SYSTEM_TEXT("����"s);
        case LogLevel::Trace:
            return SYSTEM_TEXT("����"s);
        case LogLevel::Debug:
            return SYSTEM_TEXT("����"s);
        case LogLevel::Info:
            return SYSTEM_TEXT("һ��"s);
        case LogLevel::Warn:
            return SYSTEM_TEXT("����"s);
        case LogLevel::Error:
            return SYSTEM_TEXT("����"s);
        case LogLevel::Fatal:
            return SYSTEM_TEXT("��������"s);
        default:
            CORE_TOOLS_ASSERTION_2(false, "δ�ҵ���־�ȼ������������");
            return SYSTEM_TEXT(""s);
    }
}
