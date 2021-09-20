///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 16:55)

#include "CppCookbookPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppCookbook/Helper/CppCookbookClassInvariantMacro.h"

BookIntermediate::CppCookbook::CppCookbookPlaceholderTesting::CppCookbookPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_COOKBOOK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::CppCookbook, CppCookbookPlaceholderTesting)

void BookIntermediate::CppCookbook::CppCookbookPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::CppCookbook::CppCookbookPlaceholderTesting::MainTest() noexcept
{
}
