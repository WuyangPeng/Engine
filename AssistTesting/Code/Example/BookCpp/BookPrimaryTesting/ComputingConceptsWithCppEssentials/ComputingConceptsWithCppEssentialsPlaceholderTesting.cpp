///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.6.0.1 (2021/01/04 22:40)

#include "ComputingConceptsWithCppEssentialsPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/ComputingConceptsWithCppEssentials/Helper/ComputingConceptsWithCppEssentialsClassInvariantMacro.h"

BookPrimary::ComputingConceptsWithCppEssentials::ComputingConceptsWithCppEssentialsPlaceholderTesting::ComputingConceptsWithCppEssentialsPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::ComputingConceptsWithCppEssentials, ComputingConceptsWithCppEssentialsPlaceholderTesting)

void BookPrimary::ComputingConceptsWithCppEssentials::ComputingConceptsWithCppEssentialsPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::ComputingConceptsWithCppEssentials::ComputingConceptsWithCppEssentialsPlaceholderTesting::MainTest() noexcept
{
}
