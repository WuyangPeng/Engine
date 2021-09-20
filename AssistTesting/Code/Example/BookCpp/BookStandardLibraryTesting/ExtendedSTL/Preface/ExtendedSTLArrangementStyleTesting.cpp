///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/06 21:43)

#include "ExtendedSTLArrangementStyleTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/ExtendedSTL/Helper/ExtendedSTLClassInvariantMacro.h"
#include "Example/BookCpp/ExtendedSTL/Preface/ArrangementStyle.h"

BookStandardLibrary::ExtendedSTL::ExtendedSTLArrangementStyleTesting::ExtendedSTLArrangementStyleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EXTENDED_STL_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookStandardLibrary::ExtendedSTL, ExtendedSTLArrangementStyleTesting)

void BookStandardLibrary::ExtendedSTL::ExtendedSTLArrangementStyleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookStandardLibrary::ExtendedSTL::ExtendedSTLArrangementStyleTesting::MainTest() noexcept
{
    const ArrangementStyle arrangementStyle{};

    arrangementStyle.Main();
}
