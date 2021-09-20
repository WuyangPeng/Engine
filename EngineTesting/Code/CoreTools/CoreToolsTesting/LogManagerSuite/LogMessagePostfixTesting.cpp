// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 17:36)

#include "LogMessagePostfixTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogMessagePostfix.h" 
#include "CoreTools/CharacterString/StringConversion.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogMessagePostfixTesting)

void CoreTools::LogMessagePostfixTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(PostfixFunctionDescribedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(NoPostfixTest);
}

void CoreTools::LogMessagePostfixTesting
	::PostfixFunctionDescribedTest()
{
    const FunctionDescribed functionDescribed{ CORE_TOOLS_FUNCTION_DESCRIBED };
	LogMessagePostfix postfix{ AppenderPrint::PostfixFunctionDescribed,LogLevel::Debug, functionDescribed };

	auto postfixDescribe = postfix.GetPostfix();

	ASSERT_UNEQUAL(postfixDescribe.find(StringConversion::MultiByteConversionStandard(functionDescribed.GetCurrentFunction())), System::String::npos);
	ASSERT_UNEQUAL(postfixDescribe.find(StringConversion::MultiByteConversionStandard(functionDescribed.GetFileName())), System::String::npos);

	ASSERT_LESS(0, postfix.GetPostfixSize());
}

void CoreTools::LogMessagePostfixTesting
	::NoPostfixTest()
{
    const FunctionDescribed functionDescribed{ CORE_TOOLS_FUNCTION_DESCRIBED };
	LogMessagePostfix postfix{ AppenderPrint::PrefixTimestamp,LogLevel::Debug, functionDescribed };

	auto postfixDescribe = postfix.GetPostfix();

	ASSERT_EQUAL(postfixDescribe.find(StringConversion::MultiByteConversionStandard(functionDescribed.GetCurrentFunction())), System::String::npos);
	ASSERT_EQUAL(postfixDescribe.find(StringConversion::MultiByteConversionStandard(functionDescribed.GetFileName())), System::String::npos);

	ASSERT_EQUAL(1, postfix.GetPostfixSize());
}

