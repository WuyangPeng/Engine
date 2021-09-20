///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/05/05 21:50)

#include "CppTemplateMetaprogrammingLambdaMainTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Chapter3/LambdaMain.h"
#include "Example/BookCpp/CppTemplateMetaprogramming/Helper/CppTemplateMetaprogrammingClassInvariantMacro.h"

BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingLambdaMainTesting::CppTemplateMetaprogrammingLambdaMainTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATE_METAPROGRAMMING_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplateMetaprogramming, CppTemplateMetaprogrammingLambdaMainTesting)

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingLambdaMainTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplateMetaprogramming::CppTemplateMetaprogrammingLambdaMainTesting::MainTest() noexcept
{
    const LambdaMain lambdaMain{};

    lambdaMain.Main();
}
