///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/06 21:44)

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
