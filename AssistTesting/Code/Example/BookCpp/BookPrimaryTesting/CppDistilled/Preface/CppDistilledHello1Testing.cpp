///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.6.0.1 (2021/01/04 22:08)

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
