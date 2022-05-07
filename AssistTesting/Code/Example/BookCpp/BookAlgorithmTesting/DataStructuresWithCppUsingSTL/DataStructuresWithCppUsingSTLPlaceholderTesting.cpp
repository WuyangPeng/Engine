///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 14:00)

#include "DataStructuresWithCppUsingSTLPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/DataStructuresWithCppUsingSTL/Helper/DataStructuresWithCppUsingSTLClassInvariantMacro.h"

BookAlgorithm::DataStructuresWithCppUsingSTL::DataStructuresWithCppUsingSTLPlaceholderTesting::DataStructuresWithCppUsingSTLPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATA_STRUCTURES_WITH_CPP_USING_STL_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::DataStructuresWithCppUsingSTL, DataStructuresWithCppUsingSTLPlaceholderTesting)

void BookAlgorithm::DataStructuresWithCppUsingSTL::DataStructuresWithCppUsingSTLPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::DataStructuresWithCppUsingSTL::DataStructuresWithCppUsingSTLPlaceholderTesting::MainTest() noexcept
{
}