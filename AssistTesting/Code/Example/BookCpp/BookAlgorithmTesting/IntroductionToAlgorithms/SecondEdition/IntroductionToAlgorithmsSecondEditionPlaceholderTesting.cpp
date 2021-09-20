///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/15 1:33)

#include "IntroductionToAlgorithmsSecondEditionPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/IntroductionToAlgorithmsSecondEdition/Helper/IntroductionToAlgorithmsSecondEditionClassInvariantMacro.h"

BookAlgorithm::IntroductionToAlgorithms::IntroductionToAlgorithmsSecondEditionPlaceholderTesting::IntroductionToAlgorithmsSecondEditionPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    INTRODUCTION_TO_ALGORITHMS_SECOND_EDITION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::IntroductionToAlgorithms, IntroductionToAlgorithmsSecondEditionPlaceholderTesting)

void BookAlgorithm::IntroductionToAlgorithms::IntroductionToAlgorithmsSecondEditionPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::IntroductionToAlgorithms::IntroductionToAlgorithmsSecondEditionPlaceholderTesting::MainTest() noexcept
{
}
