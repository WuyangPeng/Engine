///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/20 20:24)

#include "CrossPlatformDevelopmentInCppFibonacciTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/CrossPlatformDevelopmentInCpp/Helper/CrossPlatformDevelopmentInCppClassInvariantMacro.h"
#include "Example/BookCpp/CrossPlatformDevelopmentInCpp/Preface/Fibonacci.h"

BookAdvanced::CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppFibonacciTesting::CrossPlatformDevelopmentInCppFibonacciTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CROSS_PLATFORM_DEVELOPMENT_IN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::CrossPlatformDevelopmentInCpp, CrossPlatformDevelopmentInCppFibonacciTesting)

void BookAdvanced::CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppFibonacciTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppFibonacciTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ZeroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LoopTest);
}

void BookAdvanced::CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppFibonacciTesting::ZeroTest()
{
    const Fibonacci fibonacci{};

    ASSERT_EQUAL(fibonacci.F(0), 0);
}

void BookAdvanced::CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppFibonacciTesting::OneTest()
{
    const Fibonacci fibonacci{};

    ASSERT_EQUAL(fibonacci.F(1), 1);
}

void BookAdvanced::CrossPlatformDevelopmentInCpp::CrossPlatformDevelopmentInCppFibonacciTesting::LoopTest()
{
    const Fibonacci fibonacci{};

    constexpr auto loopBegin = 2;
    const auto loopEnd = GetTestLoopCount() + loopBegin;
    for (auto i = loopBegin; i < loopEnd; ++i)
    {
        ASSERT_EQUAL(fibonacci.F(i), fibonacci.F(i - 1) + fibonacci.F(i - 2));
    }
}
