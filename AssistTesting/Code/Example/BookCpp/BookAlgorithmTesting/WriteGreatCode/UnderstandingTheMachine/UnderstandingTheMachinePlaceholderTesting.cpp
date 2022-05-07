///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 1:33)

#include "UnderstandingTheMachinePlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/UnderstandingTheMachine/Helper/UnderstandingTheMachineClassInvariantMacro.h"

BookAlgorithm::WriteGreatCode::UnderstandingTheMachinePlaceholderTesting::UnderstandingTheMachinePlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    UNDERSTANDING_THE_MACHINE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::WriteGreatCode, UnderstandingTheMachinePlaceholderTesting)

void BookAlgorithm::WriteGreatCode::UnderstandingTheMachinePlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::WriteGreatCode::UnderstandingTheMachinePlaceholderTesting::MainTest() noexcept
{
}