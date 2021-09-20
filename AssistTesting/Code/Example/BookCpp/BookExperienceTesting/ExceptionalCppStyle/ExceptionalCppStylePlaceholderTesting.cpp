///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.0 (2021/02/20 0:17)

#include "ExceptionalCppStylePlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/ExceptionalCppStyle/Helper/ExceptionalCppStyleClassInvariantMacro.h"

BookExperience::ExceptionalCppStyle::ExceptionalCppStylePlaceholderTesting::ExceptionalCppStylePlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EXCEPTIONAL_CPP_STYLE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::ExceptionalCppStyle, ExceptionalCppStylePlaceholderTesting)

void BookExperience::ExceptionalCppStyle::ExceptionalCppStylePlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::ExceptionalCppStyle::ExceptionalCppStylePlaceholderTesting::MainTest() noexcept
{
}
