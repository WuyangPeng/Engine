///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:11)

#include "LogMessageTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogMessage.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogMessageTesting)

void CoreTools::LogMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LogLevelTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LogFilterTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void CoreTools::LogMessageTesting::LogLevelTest()
{
    LogMessage message{ LogLevel::Error, LogFilter::CoreTools, SYSTEM_TEXT("�׳��쳣��"), CORE_TOOLS_FUNCTION_DESCRIBED };

    ASSERT_ENUM_EQUAL(message.GetLogLevel(), LogLevel::Error);
}

void CoreTools::LogMessageTesting::LogFilterTest()
{
    LogMessage message{ LogLevel::Fatal, LogFilter::Rendering, SYSTEM_TEXT("ͼ����Ⱦʧ�ܣ�"), CORE_TOOLS_FUNCTION_DESCRIBED };

    ASSERT_ENUM_EQUAL(message.GetLogFilterType(), LogFilter::Rendering);
}

void CoreTools::LogMessageTesting::MessageTest()
{
    auto error = SYSTEM_TEXT("���Ӳ������磡"s);

    LogMessage message{ LogLevel::Warn, LogFilter::Network, error, CORE_TOOLS_FUNCTION_DESCRIBED };

    ASSERT_EQUAL(message.GetMessageDescribe(), error);
    ASSERT_EQUAL(message.GetMessageSize(), boost::numeric_cast<int>(error.size()));
}
