///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/20 20:10)

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
