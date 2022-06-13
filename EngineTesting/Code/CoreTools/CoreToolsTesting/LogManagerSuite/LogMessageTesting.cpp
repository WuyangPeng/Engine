///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:11)

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
    LogMessage message{ LogLevel::Error, LogFilter::CoreTools, SYSTEM_TEXT("抛出异常！"), CORE_TOOLS_FUNCTION_DESCRIBED };

    ASSERT_ENUM_EQUAL(message.GetLogLevel(), LogLevel::Error);
}

void CoreTools::LogMessageTesting::LogFilterTest()
{
    LogMessage message{ LogLevel::Fatal, LogFilter::Rendering, SYSTEM_TEXT("图像渲染失败！"), CORE_TOOLS_FUNCTION_DESCRIBED };

    ASSERT_ENUM_EQUAL(message.GetLogFilterType(), LogFilter::Rendering);
}

void CoreTools::LogMessageTesting::MessageTest()
{
    auto error = SYSTEM_TEXT("连接不上网络！"s);

    LogMessage message{ LogLevel::Warn, LogFilter::Network, error, CORE_TOOLS_FUNCTION_DESCRIBED };

    ASSERT_EQUAL(message.GetMessageDescribe(), error);
    ASSERT_EQUAL(message.GetMessageSize(), boost::numeric_cast<int>(error.size()));
}
