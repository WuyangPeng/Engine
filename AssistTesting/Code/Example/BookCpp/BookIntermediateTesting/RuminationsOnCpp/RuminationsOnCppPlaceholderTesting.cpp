///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.0 (2021/01/24 16:55)

#include "RuminationsOnCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/RuminationsOnCpp/Helper/RuminationsOnCppClassInvariantMacro.h"

BookIntermediate::RuminationsOnCpp::RuminationsOnCppPlaceholderTesting::RuminationsOnCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RUMINATIONS_ON_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::RuminationsOnCpp, RuminationsOnCppPlaceholderTesting)

void BookIntermediate::RuminationsOnCpp::RuminationsOnCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::RuminationsOnCpp::RuminationsOnCppPlaceholderTesting::MainTest() noexcept
{
}
