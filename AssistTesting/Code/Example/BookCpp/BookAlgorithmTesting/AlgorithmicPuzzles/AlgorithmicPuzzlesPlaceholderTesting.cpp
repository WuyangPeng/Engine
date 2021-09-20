///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.2 (2021/03/28 13:02)

#include "AlgorithmicPuzzlesPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/AlgorithmicPuzzles/Helper/AlgorithmicPuzzlesClassInvariantMacro.h"

BookAlgorithm::AlgorithmicPuzzles::AlgorithmicPuzzlesPlaceholderTesting::AlgorithmicPuzzlesPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ALGORITHMIC_PUZZLES_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::AlgorithmicPuzzles, AlgorithmicPuzzlesPlaceholderTesting)

void BookAlgorithm::AlgorithmicPuzzles::AlgorithmicPuzzlesPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::AlgorithmicPuzzles::AlgorithmicPuzzlesPlaceholderTesting::MainTest() noexcept
{
}
