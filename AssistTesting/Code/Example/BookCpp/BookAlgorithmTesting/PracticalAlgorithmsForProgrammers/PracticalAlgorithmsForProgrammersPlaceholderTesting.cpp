///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 2:10)

#include "PracticalAlgorithmsForProgrammersPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/PracticalAlgorithmsForProgrammers/Helper/PracticalAlgorithmsForProgrammersClassInvariantMacro.h"

BookAlgorithm::PracticalAlgorithmsForProgrammers::PracticalAlgorithmsForProgrammersPlaceholderTesting::PracticalAlgorithmsForProgrammersPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::PracticalAlgorithmsForProgrammers, PracticalAlgorithmsForProgrammersPlaceholderTesting)

void BookAlgorithm::PracticalAlgorithmsForProgrammers::PracticalAlgorithmsForProgrammersPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::PracticalAlgorithmsForProgrammers::PracticalAlgorithmsForProgrammersPlaceholderTesting::MainTest() noexcept
{
}
