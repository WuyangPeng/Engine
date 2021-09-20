///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/06 21:44)

#include "BoostCppApplicationDevelopmentCookbookPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/BoostCppApplicationDevelopmentCookbook/Helper/BoostCppApplicationDevelopmentCookbookClassInvariantMacro.h"

BookBoost::BoostCppApplicationDevelopmentCookbook::BoostCppApplicationDevelopmentCookbookPlaceholderTesting::BoostCppApplicationDevelopmentCookbookPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    BOOST_CPP_APPLICATION_DEVELOPMENT_COOKBOOK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookBoost::BoostCppApplicationDevelopmentCookbook, BoostCppApplicationDevelopmentCookbookPlaceholderTesting)

void BookBoost::BoostCppApplicationDevelopmentCookbook::BoostCppApplicationDevelopmentCookbookPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookBoost::BoostCppApplicationDevelopmentCookbook::BoostCppApplicationDevelopmentCookbookPlaceholderTesting::MainTest() noexcept
{
}
