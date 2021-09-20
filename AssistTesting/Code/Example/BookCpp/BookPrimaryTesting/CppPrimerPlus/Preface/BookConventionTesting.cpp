///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.6.0.1 (2021/01/03 13:07)

#include "BookConventionTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/CppPrimerPlus/Helper/CppPrimerPlusClassInvariantMacro.h"
#include "Example/BookCpp/CppPrimerPlus/Preface/BookConvention.h"

BookPrimary::CppPrimerPlus::BookConventionTesting::BookConventionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_PRIMER_PLUS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::CppPrimerPlus, BookConventionTesting)

void BookPrimary::CppPrimerPlus::BookConventionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::CppPrimerPlus::BookConventionTesting::MainTest()
{
    BookConvention bookConvention{};

    ASSERT_EQUAL(bookConvention.Main(), 0);
}
