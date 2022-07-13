///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助测试版本：0.8.0.10 (2022/07/13 13:56)

#include "ThreadingCoreRenderEngineAssist/Version.h"
#include "ThreadingCoreRenderEngineAssistTesting/Version.h"
#include "VersionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

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
