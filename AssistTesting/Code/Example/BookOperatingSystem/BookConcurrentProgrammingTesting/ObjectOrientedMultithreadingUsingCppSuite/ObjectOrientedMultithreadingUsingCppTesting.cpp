///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.5 (2021/11/03 21:08)

#include "ObjectOrientedMultithreadingUsingCppTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/ObjectOrientedMultithreadingUsingCpp/Helper/ObjectOrientedMultithreadingUsingCppClassInvariantMacro.h"

BookConcurrentProgramming::ObjectOrientedMultithreadingUsingCpp::ObjectOrientedMultithreadingUsingCppTesting::ObjectOrientedMultithreadingUsingCppTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    OBJECT_ORIENTED_MULTITHREADING_USING_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookConcurrentProgramming::ObjectOrientedMultithreadingUsingCpp, ObjectOrientedMultithreadingUsingCppTesting)

void BookConcurrentProgramming::ObjectOrientedMultithreadingUsingCpp::ObjectOrientedMultithreadingUsingCppTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookConcurrentProgramming::ObjectOrientedMultithreadingUsingCpp::ObjectOrientedMultithreadingUsingCppTesting::MainTest() noexcept
{
}
