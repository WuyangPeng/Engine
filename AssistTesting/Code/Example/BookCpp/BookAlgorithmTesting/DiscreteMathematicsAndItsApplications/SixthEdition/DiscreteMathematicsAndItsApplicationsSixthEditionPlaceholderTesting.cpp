///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.1 (2021/02/15 1:28)

#include "DiscreteMathematicsAndItsApplicationsSixthEditionPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/DiscreteMathematicsAndItsApplicationsSixthEdition/Helper/DiscreteMathematicsAndItsApplicationsSixthEditionClassInvariantMacro.h"

BookAlgorithm::DiscreteMathematicsAndItsApplications::DiscreteMathematicsAndItsApplicationsSixthEditionPlaceholderTesting::DiscreteMathematicsAndItsApplicationsSixthEditionPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DISCRETE_MATHEMATICS_AND_ITS_APPLICATIONS_SIXTH_EDITION_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAlgorithm::DiscreteMathematicsAndItsApplications, DiscreteMathematicsAndItsApplicationsSixthEditionPlaceholderTesting)

void BookAlgorithm::DiscreteMathematicsAndItsApplications::DiscreteMathematicsAndItsApplicationsSixthEditionPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAlgorithm::DiscreteMathematicsAndItsApplications::DiscreteMathematicsAndItsApplicationsSixthEditionPlaceholderTesting::MainTest() noexcept
{
}
