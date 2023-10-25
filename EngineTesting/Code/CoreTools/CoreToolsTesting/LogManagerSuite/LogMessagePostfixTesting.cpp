///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:25)

#include "LogMessagePostfixTesting.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogMessagePostfix.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LogMessagePostfixTesting::LogMessagePostfixTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogMessagePostfixTesting)

void CoreTools::LogMessagePostfixTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogMessagePostfixTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PostfixFunctionDescribedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoPostfixTest);
}

void CoreTools::LogMessagePostfixTesting::PostfixFunctionDescribedTest()
{
    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;
    const LogMessagePostfix postfix{ AppenderPrint::PostfixFunctionDescribed, LogLevel::Debug, functionDescribed };

    const auto postfixDescribe = postfix.GetPostfix();

    ASSERT_UNEQUAL(postfixDescribe.find(StringConversion::MultiByteConversionStandard(functionDescribed.GetCurrentFunction())), System::String::npos);
    ASSERT_UNEQUAL(postfixDescribe.find(StringConversion::MultiByteConversionStandard(functionDescribed.GetFileName())), System::String::npos);

    ASSERT_LESS(0, postfix.GetPostfixSize());
}

void CoreTools::LogMessagePostfixTesting::NoPostfixTest()
{
    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;
    const LogMessagePostfix postfix{ AppenderPrint::PrefixTimestamp, LogLevel::Debug, functionDescribed };

    const auto postfixDescribe = postfix.GetPostfix();

    ASSERT_EQUAL(postfixDescribe.find(StringConversion::MultiByteConversionStandard(functionDescribed.GetCurrentFunction())), System::String::npos);
    ASSERT_EQUAL(postfixDescribe.find(StringConversion::MultiByteConversionStandard(functionDescribed.GetFileName())), System::String::npos);

    ASSERT_EQUAL(1, postfix.GetPostfixSize());
}
