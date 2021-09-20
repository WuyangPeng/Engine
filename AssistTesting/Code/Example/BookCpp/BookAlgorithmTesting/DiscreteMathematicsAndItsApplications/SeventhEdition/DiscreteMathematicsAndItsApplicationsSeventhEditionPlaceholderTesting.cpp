///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/15 1:33)

#include "DiscreteMathematicsAndItsApplicationsSeventhEditionPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/DiscreteMathematicsAndItsApplicationsSeventhEdition/Helper/DiscreteMathematicsAndItsApplicationsSeventhEditionClassInvariantMacro.h"

BookAlgorithm::DiscreteMathematicsAndItsApplications::DiscreteMathematicsAndItsApplicationsSeventhEditionPlaceholderTesting::DiscreteMathematicsAndItsApplicationsSeventhEditionPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SEVENTH_EDITION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::DiscreteMathematicsAndItsApplications, DiscreteMathematicsAndItsApplicationsSeventhEditionPlaceholderTesting)

void BookAlgorithm::DiscreteMathematicsAndItsApplications::DiscreteMathematicsAndItsApplicationsSeventhEditionPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::DiscreteMathematicsAndItsApplications::DiscreteMathematicsAndItsApplicationsSeventhEditionPlaceholderTesting::MainTest() noexcept
{
}
