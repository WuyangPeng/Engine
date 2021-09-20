///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.2 (2021/03/28 13:02)

#include "AlgorithmsSanjoyDasguptaPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/Algorithms/Helper/AlgorithmsClassInvariantMacro.h"

BookAlgorithm::AlgorithmsSanjoyDasgupta::AlgorithmsSanjoyDasguptaPlaceholderTesting::AlgorithmsSanjoyDasguptaPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ALGORITHMS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::AlgorithmsSanjoyDasgupta, AlgorithmsSanjoyDasguptaPlaceholderTesting)

void BookAlgorithm::AlgorithmsSanjoyDasgupta::AlgorithmsSanjoyDasguptaPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::AlgorithmsSanjoyDasgupta::AlgorithmsSanjoyDasguptaPlaceholderTesting::MainTest() noexcept
{
}
