///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.6.0.1 (2021/01/02 22:59)

#include "CppForTheImpatientPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppForTheImpatient/Helper/CppForTheImpatientClassInvariantMacro.h"

BookPrimary::CppForTheImpatient::CppForTheImpatientPlaceholderTesting::CppForTheImpatientPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_FOR_THE_IMPATIENT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::CppForTheImpatient, CppForTheImpatientPlaceholderTesting)

void BookPrimary::CppForTheImpatient::CppForTheImpatientPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::CppForTheImpatient::CppForTheImpatientPlaceholderTesting::MainTest() noexcept
{
}
