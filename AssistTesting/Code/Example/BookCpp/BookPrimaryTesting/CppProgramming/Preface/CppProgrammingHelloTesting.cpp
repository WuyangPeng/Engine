///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.6.0.1 (2021/01/04 22:08)

#include "CppProgrammingHelloTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/CppProgramming/Helper/CppProgrammingClassInvariantMacro.h"
#include "Example/BookCpp/CppProgramming/Preface/Hello.h"

BookPrimary::CppProgramming::CppProgrammingHelloTesting::CppProgrammingHelloTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_PROGRAMMING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::CppProgramming, CppProgrammingHelloTesting)

void BookPrimary::CppProgramming::CppProgrammingHelloTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::CppProgramming::CppProgrammingHelloTesting::MainTest()
{
    const Hello hello{};

    ASSERT_EQUAL(0, hello.Main());

    GetStream() << '\n';
}
