///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.0 (2021/02/20 0:17)

#include "ExceptionalCppStylePlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/ExceptionalCppStyle/Helper/ExceptionalCppStyleClassInvariantMacro.h"

BookExperience::ExceptionalCppStyle::ExceptionalCppStylePlaceholderTesting::ExceptionalCppStylePlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EXCEPTIONAL_CPP_STYLE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::ExceptionalCppStyle, ExceptionalCppStylePlaceholderTesting)

void BookExperience::ExceptionalCppStyle::ExceptionalCppStylePlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::ExceptionalCppStyle::ExceptionalCppStylePlaceholderTesting::MainTest() noexcept
{
}
