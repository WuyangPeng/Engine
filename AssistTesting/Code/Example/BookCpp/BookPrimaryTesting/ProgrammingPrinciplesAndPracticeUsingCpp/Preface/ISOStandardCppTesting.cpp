///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.6.0.1 (2021/01/03 13:07)

#include "ISOStandardCppTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/ProgrammingPrinciplesAndPracticeUsingCpp/Helper/ProgrammingPrinciplesAndPracticeUsingCppClassInvariantMacro.h"
#include "Example/BookCpp/ProgrammingPrinciplesAndPracticeUsingCpp/Preface/ISOStandardCpp.h"

BookPrimary::ProgrammingPrinciplesAndPracticeUsingCpp::ISOStandardCppTesting::ISOStandardCppTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::ProgrammingPrinciplesAndPracticeUsingCpp, ISOStandardCppTesting)

void BookPrimary::ProgrammingPrinciplesAndPracticeUsingCpp::ISOStandardCppTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::ProgrammingPrinciplesAndPracticeUsingCpp::ISOStandardCppTesting::MainTest()
{
    const ISOStandardCpp isoStandardCpp{};

    isoStandardCpp.ISOStandardCpp98();
    isoStandardCpp.ISOStandardCpp14();
}
