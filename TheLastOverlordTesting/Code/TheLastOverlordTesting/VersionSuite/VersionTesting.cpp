/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 20:02)

#include "TheLastOverlord/Version.h"
#include "TheLastOverlordTesting/Version.h"
#include "VersionTesting.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

TheLastOverlordTesting::VersionTesting::VersionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(TheLastOverlordTesting, VersionTesting)

void TheLastOverlordTesting::VersionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void TheLastOverlordTesting::VersionTesting::MainTest()
{
    ASSERT_GREATER_EQUAL(gTheLastOverlordVersion, gTheLastOverlordTestingVersion);
}
