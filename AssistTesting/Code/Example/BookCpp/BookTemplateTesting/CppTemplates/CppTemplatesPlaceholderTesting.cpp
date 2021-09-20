///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/06 21:44)

#include "CppTemplatesPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppTemplates/Helper/CppTemplatesClassInvariantMacro.h"

BookTemplate::CppTemplates::CppTemplatesPlaceholderTesting::CppTemplatesPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_TEMPLATES_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookTemplate::CppTemplates, CppTemplatesPlaceholderTesting)

void BookTemplate::CppTemplates::CppTemplatesPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookTemplate::CppTemplates::CppTemplatesPlaceholderTesting::MainTest() noexcept
{
}
