///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 16:55)

#include "RuminationsOnCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/RuminationsOnCpp/Helper/RuminationsOnCppClassInvariantMacro.h"

BookIntermediate::RuminationsOnCpp::RuminationsOnCppPlaceholderTesting::RuminationsOnCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RUMINATIONS_ON_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::RuminationsOnCpp, RuminationsOnCppPlaceholderTesting)

void BookIntermediate::RuminationsOnCpp::RuminationsOnCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::RuminationsOnCpp::RuminationsOnCppPlaceholderTesting::MainTest() noexcept
{
}
