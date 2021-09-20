///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 16:55)

#include "CppGotchasPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppGotchas/Helper/CppGotchasClassInvariantMacro.h"

BookIntermediate::CppGotchas::CppGotchasPlaceholderTesting::CppGotchasPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_GOTCHAS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::CppGotchas, CppGotchasPlaceholderTesting)

void BookIntermediate::CppGotchas::CppGotchasPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::CppGotchas::CppGotchasPlaceholderTesting::MainTest() noexcept
{
}
