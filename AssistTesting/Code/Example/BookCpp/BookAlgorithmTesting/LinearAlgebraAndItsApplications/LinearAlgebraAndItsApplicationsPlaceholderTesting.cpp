///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/15 14:00)

#include "LinearAlgebraAndItsApplicationsPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/LinearAlgebraAndItsApplications/Helper/LinearAlgebraAndItsApplicationsClassInvariantMacro.h"

BookAlgorithm::LinearAlgebraAndItsApplications::LinearAlgebraAndItsApplicationsPlaceholderTesting::LinearAlgebraAndItsApplicationsPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::LinearAlgebraAndItsApplications, LinearAlgebraAndItsApplicationsPlaceholderTesting)

void BookAlgorithm::LinearAlgebraAndItsApplications::LinearAlgebraAndItsApplicationsPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::LinearAlgebraAndItsApplications::LinearAlgebraAndItsApplicationsPlaceholderTesting::MainTest() noexcept
{
}
