///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.6.0.1 (2021/01/02 22:59)

#include "CAndCppCodeCapsulesPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CAndCppCodeCapsules/Helper/CAndCppCodeCapsulesClassInvariantMacro.h"

BookPrimary::CAndCppCodeCapsules::CAndCppCodeCapsulesPlaceholderTesting::CAndCppCodeCapsulesPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    C_AND_CPP_CODE_CAPSULES_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::CAndCppCodeCapsules, CAndCppCodeCapsulesPlaceholderTesting)

void BookPrimary::CAndCppCodeCapsules::CAndCppCodeCapsulesPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::CAndCppCodeCapsules::CAndCppCodeCapsulesPlaceholderTesting::MainTest() noexcept
{
}
