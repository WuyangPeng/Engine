///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.0 (2021/02/23 21:10)

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
