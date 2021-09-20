///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/15 14:00)

#include "IntroductionToTheDesignAndAnalysisOfAlgorithmsPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/IntroductionToTheDesignAndAnalysisOfAlgorithms/Helper/IntroductionToTheDesignAndAnalysisOfAlgorithmsClassInvariantMacro.h"

BookAlgorithm::IntroductionToTheDesignAndAnalysisOfAlgorithms::IntroductionToTheDesignAndAnalysisOfAlgorithmsPlaceholderTesting::IntroductionToTheDesignAndAnalysisOfAlgorithmsPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    INTRODUCTION_TO_THE_DESIGN_AND_ANALYSIS_OF_ALGORITHMS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::IntroductionToTheDesignAndAnalysisOfAlgorithms, IntroductionToTheDesignAndAnalysisOfAlgorithmsPlaceholderTesting)

void BookAlgorithm::IntroductionToTheDesignAndAnalysisOfAlgorithms::IntroductionToTheDesignAndAnalysisOfAlgorithmsPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::IntroductionToTheDesignAndAnalysisOfAlgorithms::IntroductionToTheDesignAndAnalysisOfAlgorithmsPlaceholderTesting::MainTest() noexcept
{
}
