///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起测试版本：0.8.1.1 (2022/08/26 18:07)

#include "RiseOfHistory/Version.h"
#include "RiseOfHistoryTesting/Version.h"
#include "VersionTesting.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

RiseOfHistory::VersionTesting::VersionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RiseOfHistory, VersionTesting)

void RiseOfHistory::VersionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void RiseOfHistory::VersionTesting::MainTest()
{
    ASSERT_GREATER_EQUAL(gRiseOfHistoryVersion, gRiseOfHistoryTestingVersion);
}
