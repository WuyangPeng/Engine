///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.6.0.1 (2021/01/04 22:08)

#include "CppDistilledHello1Testing.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/CppDistilled/Helper/CppDistilledClassInvariantMacro.h"
#include "Example/BookCpp/CppDistilled/Preface/Hello1.h"

BookPrimary::CppDistilled::CppDistilledHello1Testing::CppDistilledHello1Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_DISTILLED_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::CppDistilled, CppDistilledHello1Testing)

void BookPrimary::CppDistilled::CppDistilledHello1Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::CppDistilled::CppDistilledHello1Testing::MainTest()
{
    const Hello1 hello{};

    ASSERT_EQUAL(0, hello.Main());
}
