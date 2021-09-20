///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/21 12:34)

#include "TheArtOfCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/TheArtOfCpp/Helper/TheArtOfCppClassInvariantMacro.h"

BookAdvanced::TheArtOfCpp::TheArtOfCppPlaceholderTesting::TheArtOfCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    THE_ART_OF_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::TheArtOfCpp, TheArtOfCppPlaceholderTesting)

void BookAdvanced::TheArtOfCpp::TheArtOfCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::TheArtOfCpp::TheArtOfCppPlaceholderTesting::MainTest() noexcept
{
}
