///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.5 (2021/11/03 21:08)

#include "CppConcurrencyInActionTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/CppConcurrencyInAction/Helper/CppConcurrencyInActionClassInvariantMacro.h"

BookConcurrentProgramming::CppConcurrencyInAction::CppConcurrencyInActionTesting::CppConcurrencyInActionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_CONCURRENCY_IN_ACTION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookConcurrentProgramming::CppConcurrencyInAction, CppConcurrencyInActionTesting)

void BookConcurrentProgramming::CppConcurrencyInAction::CppConcurrencyInActionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookConcurrentProgramming::CppConcurrencyInAction::CppConcurrencyInActionTesting::MainTest() noexcept
{
}
