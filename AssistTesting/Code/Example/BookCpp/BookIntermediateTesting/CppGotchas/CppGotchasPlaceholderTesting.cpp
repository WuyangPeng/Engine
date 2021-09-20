///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.0 (2021/01/24 16:55)

#include "CppGotchasPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppGotchas/Helper/CppGotchasClassInvariantMacro.h"

BookIntermediate::CppGotchas::CppGotchasPlaceholderTesting::CppGotchasPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_GOTCHAS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::CppGotchas, CppGotchasPlaceholderTesting)

void BookIntermediate::CppGotchas::CppGotchasPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::CppGotchas::CppGotchasPlaceholderTesting::MainTest() noexcept
{
}
