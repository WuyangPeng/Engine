///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 17:36)

#include "EfficientCppPerformanceProgrammingTechniquesPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/EfficientCppPerformanceProgrammingTechniques/Helper/EfficientCppPerformanceProgrammingTechniquesClassInvariantMacro.h"

BookIntermediate::EfficientCppPerformanceProgrammingTechniques::EfficientCppPerformanceProgrammingTechniquesPlaceholderTesting::EfficientCppPerformanceProgrammingTechniquesPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EFFICIENT_CPP_PERFORMANCE_PROGRAMMING_TECHNIQUES_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::EfficientCppPerformanceProgrammingTechniques, EfficientCppPerformanceProgrammingTechniquesPlaceholderTesting)

void BookIntermediate::EfficientCppPerformanceProgrammingTechniques::EfficientCppPerformanceProgrammingTechniquesPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::EfficientCppPerformanceProgrammingTechniques::EfficientCppPerformanceProgrammingTechniquesPlaceholderTesting::MainTest() noexcept
{
}
