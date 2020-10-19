//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/15 19:01)

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
