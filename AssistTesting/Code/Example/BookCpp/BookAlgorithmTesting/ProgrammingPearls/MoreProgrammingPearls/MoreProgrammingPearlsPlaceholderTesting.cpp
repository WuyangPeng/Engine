///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 1:33)

#include "MoreProgrammingPearlsPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/MoreProgrammingPearls/Helper/MoreProgrammingPearlsClassInvariantMacro.h"

BookAlgorithm::ProgrammingPearls::MoreProgrammingPearlsPlaceholderTesting::MoreProgrammingPearlsPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    MORE_PROGRAMMING_PEARLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::ProgrammingPearls, MoreProgrammingPearlsPlaceholderTesting)

void BookAlgorithm::ProgrammingPearls::MoreProgrammingPearlsPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::ProgrammingPearls::MoreProgrammingPearlsPlaceholderTesting::MainTest() noexcept
{
}
