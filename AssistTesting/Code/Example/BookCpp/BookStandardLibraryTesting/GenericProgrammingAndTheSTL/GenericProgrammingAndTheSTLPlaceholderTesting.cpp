///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/06 21:43)

#include "GenericProgrammingAndTheSTLPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/GenericProgrammingAndTheSTL/Helper/GenericProgrammingAndTheSTLClassInvariantMacro.h"

BookStandardLibrary::GenericProgrammingAndTheSTL::GenericProgrammingAndTheSTLPlaceholderTesting::GenericProgrammingAndTheSTLPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    GENERIC_PROGRAMMING_AND_THE_STL_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookStandardLibrary::GenericProgrammingAndTheSTL, GenericProgrammingAndTheSTLPlaceholderTesting)

void BookStandardLibrary::GenericProgrammingAndTheSTL::GenericProgrammingAndTheSTLPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookStandardLibrary::GenericProgrammingAndTheSTL::GenericProgrammingAndTheSTLPlaceholderTesting::MainTest() noexcept
{
}
