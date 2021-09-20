///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.2 (2021/03/28 13:02)

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
