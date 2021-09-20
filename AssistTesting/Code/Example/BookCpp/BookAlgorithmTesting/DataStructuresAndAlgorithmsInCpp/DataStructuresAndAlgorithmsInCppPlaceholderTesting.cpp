///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 14:00)

#include "DataStructuresAndAlgorithmsInCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/DataStructuresAndAlgorithmsInCpp/Helper/DataStructuresAndAlgorithmsInCppClassInvariantMacro.h"

BookAlgorithm::DataStructuresAndAlgorithmsInCpp::DataStructuresAndAlgorithmsInCppPlaceholderTesting::DataStructuresAndAlgorithmsInCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::DataStructuresAndAlgorithmsInCpp, DataStructuresAndAlgorithmsInCppPlaceholderTesting)

void BookAlgorithm::DataStructuresAndAlgorithmsInCpp::DataStructuresAndAlgorithmsInCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::DataStructuresAndAlgorithmsInCpp::DataStructuresAndAlgorithmsInCppPlaceholderTesting::MainTest() noexcept
{
}
