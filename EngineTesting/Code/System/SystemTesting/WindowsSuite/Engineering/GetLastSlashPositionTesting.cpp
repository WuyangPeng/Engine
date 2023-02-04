///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 17:55)

#include "GetLastSlashPositionTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetLastSlashPositionTesting::GetLastSlashPositionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetLastSlashPositionTesting)

void System::GetLastSlashPositionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetLastSlashPositionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetLastSlashPositionTest);
}

void System::GetLastSlashPositionTesting::GetLastSlashPositionTest()
{
    const auto path0 = SYSTEM_TEXT("A\\B/C\\D");

    ASSERT_EQUAL(GetLastSlashPosition(path0), 5u);

    const auto path1 = SYSTEM_TEXT("A\\B/C\\D/E");

    ASSERT_EQUAL(GetLastSlashPosition(path1), 7u);
}
