///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.6.0.1 (2021/01/02 22:59)

#include "BeginningCpp17PlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/BeginningCpp17/Helper/BeginningCpp17ClassInvariantMacro.h"

BookPrimary::BeginningCpp17::BeginningCpp17PlaceholderTesting::BeginningCpp17PlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    BEGINNING_CPP_17_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::BeginningCpp17, BeginningCpp17PlaceholderTesting)

void BookPrimary::BeginningCpp17::BeginningCpp17PlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::BeginningCpp17::BeginningCpp17PlaceholderTesting::MainTest() noexcept
{
}
