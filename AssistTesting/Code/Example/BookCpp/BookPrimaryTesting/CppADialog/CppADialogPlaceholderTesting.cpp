///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.6.0.1 (2021/01/02 22:59)

#include "CppADialogPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppADialog/Helper/CppADialogClassInvariantMacro.h"

BookPrimary::CppADialog::CppADialogPlaceholderTesting::CppADialogPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_A_DIALOG_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::CppADialog, CppADialogPlaceholderTesting)

void BookPrimary::CppADialog::CppADialogPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::CppADialog::CppADialogPlaceholderTesting::MainTest() noexcept
{
}
