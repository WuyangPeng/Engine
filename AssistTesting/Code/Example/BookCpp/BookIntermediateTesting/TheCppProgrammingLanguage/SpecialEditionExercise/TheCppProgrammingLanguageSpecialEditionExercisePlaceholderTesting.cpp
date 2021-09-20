///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 16:45)

#include "TheCppProgrammingLanguageSpecialEditionExercisePlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/TheCppProgrammingLanguageSpecialEditionExercise/Helper/TheCppProgrammingLanguageSpecialEditionExerciseClassInvariantMacro.h"

BookIntermediate::TheCppProgrammingLanguage::TheCppProgrammingLanguageSpecialEditionExercisePlaceholderTesting::TheCppProgrammingLanguageSpecialEditionExercisePlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_EXERCISE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::TheCppProgrammingLanguage, TheCppProgrammingLanguageSpecialEditionExercisePlaceholderTesting)

void BookIntermediate::TheCppProgrammingLanguage::TheCppProgrammingLanguageSpecialEditionExercisePlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::TheCppProgrammingLanguage::TheCppProgrammingLanguageSpecialEditionExercisePlaceholderTesting::MainTest() noexcept
{
}
