///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.6.0.1 (2021/01/03 13:07)

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
