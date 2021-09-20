// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/05 17:37)

#include "LogMessageTesting.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogMessageTesting)

void CoreTools::LogMessageTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(LogLevelTest);
	ASSERT_NOT_THROW_EXCEPTION_0(LogFilterTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void CoreTools::LogMessageTesting
	::LogLevelTest()
{
	LogMessage message{ LogLevel::Error,LogFilter::CoreTools,SYSTEM_TEXT("�׳��쳣��"), CORE_TOOLS_FUNCTION_DESCRIBED };

	ASSERT_ENUM_EQUAL(message.GetLogLevel(), LogLevel::Error);
}

void CoreTools::LogMessageTesting
	::LogFilterTest()
{
	LogMessage message{ LogLevel::Fatal,LogFilter::Rendering,SYSTEM_TEXT("ͼ����Ⱦʧ�ܣ�"), CORE_TOOLS_FUNCTION_DESCRIBED };

	ASSERT_ENUM_EQUAL(message.GetLogFilterType(), LogFilter::Rendering);
}

void CoreTools::LogMessageTesting
	::MessageTest()
{
	auto error = SYSTEM_TEXT("���Ӳ������磡"s);

	LogMessage message{ LogLevel::Warn,LogFilter::Network,error, CORE_TOOLS_FUNCTION_DESCRIBED };

	ASSERT_EQUAL(message.GetMessageDescribe(), error);
	ASSERT_EQUAL(message.GetMessageSize(), boost::numeric_cast<int>(error.size()));
}


