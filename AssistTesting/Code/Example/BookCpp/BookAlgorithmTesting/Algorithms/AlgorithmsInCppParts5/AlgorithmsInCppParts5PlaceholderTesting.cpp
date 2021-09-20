///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/15 1:33)

#include "AlgorithmsInCppParts5PlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/AlgorithmsInCppParts5/Helper/AlgorithmsInCppParts5ClassInvariantMacro.h"

BookAlgorithm::Algorithms::AlgorithmsInCppParts5PlaceholderTesting::AlgorithmsInCppParts5PlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ALGORITHMS_IN_CPP_PARTS_5_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::Algorithms, AlgorithmsInCppParts5PlaceholderTesting)

void BookAlgorithm::Algorithms::AlgorithmsInCppParts5PlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::Algorithms::AlgorithmsInCppParts5PlaceholderTesting::MainTest() noexcept
{
}
