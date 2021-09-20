///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.0 (2021/01/24 16:40)

#include "TheCppProgrammingLanguageFourthEditionPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/TheCppProgrammingLanguageFourthEdition/Helper/TheCppProgrammingLanguageFourthEditionClassInvariantMacro.h"

BookIntermediate::TheCppProgrammingLanguage::TheCppProgrammingLanguageFourthEditionPlaceholderTesting::TheCppProgrammingLanguageFourthEditionPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    THE_CPP_PROGRAMMING_LANGUAGE_FOURTH_EDITION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::TheCppProgrammingLanguage, TheCppProgrammingLanguageFourthEditionPlaceholderTesting)

void BookIntermediate::TheCppProgrammingLanguage::TheCppProgrammingLanguageFourthEditionPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::TheCppProgrammingLanguage::TheCppProgrammingLanguageFourthEditionPlaceholderTesting::MainTest() noexcept
{
}
