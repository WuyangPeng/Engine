///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/20 20:10)

#include "MultiParadigmDesignForCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/MultiParadigmDesignForCpp/Helper/MultiParadigmDesignForCppClassInvariantMacro.h"

BookAdvanced::MultiParadigmDesignForCpp::MultiParadigmDesignForCppPlaceholderTesting::MultiParadigmDesignForCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    MULTI_PARADIGM_DESIGN_FOR_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::MultiParadigmDesignForCpp, MultiParadigmDesignForCppPlaceholderTesting)

void BookAdvanced::MultiParadigmDesignForCpp::MultiParadigmDesignForCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::MultiParadigmDesignForCpp::MultiParadigmDesignForCppPlaceholderTesting::MainTest() noexcept
{
}
