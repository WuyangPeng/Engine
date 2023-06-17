///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助测试版本：0.9.0.12 (2023/06/15 19:17)

#include "ThreadingCoreRenderEngineAssist/Version.h"
#include "ThreadingCoreRenderEngineAssistTesting/Version.h"
#include "VersionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

ThreadingCoreRenderEngineAssist::VersionTesting::VersionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ThreadingCoreRenderEngineAssist, VersionTesting)

void ThreadingCoreRenderEngineAssist::VersionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void ThreadingCoreRenderEngineAssist::VersionTesting::MainTest()
{
    ASSERT_GREATER_EQUAL(g_TCREAssistVersion, g_TCREAssistTestingVersion);
}
