///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ������԰汾��0.8.0.12 (2022/08/02 12:58)

#include "TheLastOverlord/Version.h"
#include "TheLastOverlordTesting/Version.h"
#include "VersionTesting.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

TheLastOverlord::VersionTesting::VersionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(TheLastOverlord, VersionTesting)

void TheLastOverlord::VersionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void TheLastOverlord::VersionTesting::MainTest()
{
    ASSERT_GREATER_EQUAL(g_TheLastOverlordVersion, g_TheLastOverlordTestingVersion);
}
