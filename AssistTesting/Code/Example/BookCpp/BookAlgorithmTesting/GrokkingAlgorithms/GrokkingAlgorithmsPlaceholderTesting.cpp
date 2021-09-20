///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 14:00)

#include "GrokkingAlgorithmsPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/GrokkingAlgorithms/Helper/GrokkingAlgorithmsClassInvariantMacro.h"

BookAlgorithm::GrokkingAlgorithms::GrokkingAlgorithmsPlaceholderTesting::GrokkingAlgorithmsPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    GROKKING_ALGORITHMS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::GrokkingAlgorithms, GrokkingAlgorithmsPlaceholderTesting)

void BookAlgorithm::GrokkingAlgorithms::GrokkingAlgorithmsPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::GrokkingAlgorithms::GrokkingAlgorithmsPlaceholderTesting::MainTest() noexcept
{
}
