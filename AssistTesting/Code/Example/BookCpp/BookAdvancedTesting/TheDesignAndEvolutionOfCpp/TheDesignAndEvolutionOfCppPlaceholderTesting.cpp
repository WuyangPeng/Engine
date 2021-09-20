///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/20 20:10)

#include "TheDesignAndEvolutionOfCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/TheDesignAndEvolutionOfCpp/Helper/TheDesignAndEvolutionOfCppClassInvariantMacro.h"

BookAdvanced::TheDesignAndEvolutionOfCpp::TheDesignAndEvolutionOfCppPlaceholderTesting::TheDesignAndEvolutionOfCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    THE_DESIGN_AND_EVOLUTION_OF_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::TheDesignAndEvolutionOfCpp, TheDesignAndEvolutionOfCppPlaceholderTesting)

void BookAdvanced::TheDesignAndEvolutionOfCpp::TheDesignAndEvolutionOfCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::TheDesignAndEvolutionOfCpp::TheDesignAndEvolutionOfCppPlaceholderTesting::MainTest() noexcept
{
}
