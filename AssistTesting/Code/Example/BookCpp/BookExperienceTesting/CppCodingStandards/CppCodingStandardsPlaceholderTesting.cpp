///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.0 (2021/02/23 21:10)

#include "CppCodingStandardsPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppCodingStandards/Helper/CppCodingStandardsClassInvariantMacro.h"

BookExperience::CppCodingStandards::CppCodingStandardsPlaceholderTesting::CppCodingStandardsPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_CODING_STANDARDS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookExperience::CppCodingStandards, CppCodingStandardsPlaceholderTesting)

void BookExperience::CppCodingStandards::CppCodingStandardsPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookExperience::CppCodingStandards::CppCodingStandardsPlaceholderTesting::MainTest() noexcept
{
}
