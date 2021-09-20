///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.0 (2021/01/24 16:55)

#include "AdvancedCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/AdvancedCpp/Helper/AdvancedCppClassInvariantMacro.h"

BookIntermediate::AdvancedCpp::AdvancedCppPlaceholderTesting::AdvancedCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ADVANCED_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::AdvancedCpp, AdvancedCppPlaceholderTesting)

void BookIntermediate::AdvancedCpp::AdvancedCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::AdvancedCpp::AdvancedCppPlaceholderTesting::MainTest() noexcept
{
}
