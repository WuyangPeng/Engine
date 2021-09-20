///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 14:00)

#include "DataAbstractionAndProblemSolvingWithCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/DataAbstractionAndProblemSolvingWithCpp/Helper/DataAbstractionAndProblemSolvingWithCppClassInvariantMacro.h"

BookAlgorithm::DataAbstractionAndProblemSolvingWithCpp::DataAbstractionAndProblemSolvingWithCppPlaceholderTesting::DataAbstractionAndProblemSolvingWithCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATA_ABSTRACTION_AND_PROBLEM_SOLVING_WITH_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::DataAbstractionAndProblemSolvingWithCpp, DataAbstractionAndProblemSolvingWithCppPlaceholderTesting)

void BookAlgorithm::DataAbstractionAndProblemSolvingWithCpp::DataAbstractionAndProblemSolvingWithCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::DataAbstractionAndProblemSolvingWithCpp::DataAbstractionAndProblemSolvingWithCppPlaceholderTesting::MainTest() noexcept
{
}
