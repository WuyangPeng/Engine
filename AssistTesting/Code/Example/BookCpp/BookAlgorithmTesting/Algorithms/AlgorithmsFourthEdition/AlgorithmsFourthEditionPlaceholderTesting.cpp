///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/15 1:33)

#include "AlgorithmsFourthEditionPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/AlgorithmsFourthEdition/Helper/AlgorithmsFourthEditionClassInvariantMacro.h"

BookAlgorithm::Algorithms::AlgorithmsFourthEditionPlaceholderTesting::AlgorithmsFourthEditionPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ALGORITHMS_FOURTH_EDITION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::Algorithms, AlgorithmsFourthEditionPlaceholderTesting)

void BookAlgorithm::Algorithms::AlgorithmsFourthEditionPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::Algorithms::AlgorithmsFourthEditionPlaceholderTesting::MainTest() noexcept
{
}
