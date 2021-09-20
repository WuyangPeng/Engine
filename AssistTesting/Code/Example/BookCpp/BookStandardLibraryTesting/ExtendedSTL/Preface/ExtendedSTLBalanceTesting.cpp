///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/06 21:43)

#include "ExtendedSTLBalanceTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Example/BookCpp/ExtendedSTL/Helper/ExtendedSTLClassInvariantMacro.h"
#include "Example/BookCpp/ExtendedSTL/Preface/Balance.h"

BookStandardLibrary::ExtendedSTL::ExtendedSTLBalanceTesting::ExtendedSTLBalanceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EXTENDED_STL_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookStandardLibrary::ExtendedSTL, ExtendedSTLBalanceTesting)

void BookStandardLibrary::ExtendedSTL::ExtendedSTLBalanceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookStandardLibrary::ExtendedSTL::ExtendedSTLBalanceTesting::MainTest() noexcept
{
    const Balance balance{};

    balance.Main();
}
