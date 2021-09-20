///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 16:55)

#include "OptimizedCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/OptimizedCpp/Helper/OptimizedCppClassInvariantMacro.h"

BookIntermediate::OptimizedCpp::OptimizedCppPlaceholderTesting::OptimizedCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    OPTIMIZED_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::OptimizedCpp, OptimizedCppPlaceholderTesting)

void BookIntermediate::OptimizedCpp::OptimizedCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::OptimizedCpp::OptimizedCppPlaceholderTesting::MainTest() noexcept
{
}
