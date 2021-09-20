///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 1:33)

#include "AlgorithmsInCppParts1_4PlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/AlgorithmsInCppParts1_4/Helper/AlgorithmsInCppParts1_4ClassInvariantMacro.h"

BookAlgorithm::Algorithms::AlgorithmsInCppParts1_4PlaceholderTesting::AlgorithmsInCppParts1_4PlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ALGORITHMS_IN_CPP_PARTS_1_4_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::Algorithms, AlgorithmsInCppParts1_4PlaceholderTesting)

void BookAlgorithm::Algorithms::AlgorithmsInCppParts1_4PlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::Algorithms::AlgorithmsInCppParts1_4PlaceholderTesting::MainTest() noexcept
{
}
