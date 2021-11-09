///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.5 (2021/11/03 21:08)

#include "CppMultithreadingCookbookTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/CppMultithreadingCookbook/Helper/CppMultithreadingCookbookClassInvariantMacro.h"

BookConcurrentProgramming::CppMultithreadingCookbook::CppMultithreadingCookbookTesting::CppMultithreadingCookbookTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_MULTITHREADING_COOKBOOK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookConcurrentProgramming::CppMultithreadingCookbook, CppMultithreadingCookbookTesting)

void BookConcurrentProgramming::CppMultithreadingCookbook::CppMultithreadingCookbookTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookConcurrentProgramming::CppMultithreadingCookbook::CppMultithreadingCookbookTesting::MainTest() noexcept
{
}
