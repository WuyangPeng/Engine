///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 14:00)

#include "HowToSolvePlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/HowToSolve/Helper/HowToSolveClassInvariantMacro.h"

BookAlgorithm::HowToSolve::HowToSolvePlaceholderTesting::HowToSolvePlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    HOW_TO_SOLVE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::HowToSolve, HowToSolvePlaceholderTesting)

void BookAlgorithm::HowToSolve::HowToSolvePlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::HowToSolve::HowToSolvePlaceholderTesting::MainTest() noexcept
{
}
