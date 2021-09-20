///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.6.0.1 (2021/01/02 22:59)

#include "CAndCppCodeCapsulesPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CAndCppCodeCapsules/Helper/CAndCppCodeCapsulesClassInvariantMacro.h"

BookPrimary::CAndCppCodeCapsules::CAndCppCodeCapsulesPlaceholderTesting::CAndCppCodeCapsulesPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    C_AND_CPP_CODE_CAPSULES_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::CAndCppCodeCapsules, CAndCppCodeCapsulesPlaceholderTesting)

void BookPrimary::CAndCppCodeCapsules::CAndCppCodeCapsulesPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::CAndCppCodeCapsules::CAndCppCodeCapsulesPlaceholderTesting::MainTest() noexcept
{
}
