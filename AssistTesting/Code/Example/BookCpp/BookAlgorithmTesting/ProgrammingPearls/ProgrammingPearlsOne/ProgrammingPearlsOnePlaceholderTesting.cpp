///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 1:33)

#include "ProgrammingPearlsOnePlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/ProgrammingPearls/Helper/ProgrammingPearlsClassInvariantMacro.h"

BookAlgorithm::ProgrammingPearls::ProgrammingPearlsOnePlaceholderTesting::ProgrammingPearlsOnePlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    PROGRAMMING_PEARLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::ProgrammingPearls, ProgrammingPearlsOnePlaceholderTesting)

void BookAlgorithm::ProgrammingPearls::ProgrammingPearlsOnePlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::ProgrammingPearls::ProgrammingPearlsOnePlaceholderTesting::MainTest() noexcept
{
}
