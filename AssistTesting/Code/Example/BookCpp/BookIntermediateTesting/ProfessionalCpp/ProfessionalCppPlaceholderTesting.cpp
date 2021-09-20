///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 16:55)

#include "ProfessionalCppPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/ProfessionalCpp/Helper/ProfessionalCppClassInvariantMacro.h"

BookIntermediate::ProfessionalCpp::ProfessionalCppPlaceholderTesting::ProfessionalCppPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    PROFESSIONAL_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::ProfessionalCpp, ProfessionalCppPlaceholderTesting)

void BookIntermediate::ProfessionalCpp::ProfessionalCppPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::ProfessionalCpp::ProfessionalCppPlaceholderTesting::MainTest() noexcept
{
}
