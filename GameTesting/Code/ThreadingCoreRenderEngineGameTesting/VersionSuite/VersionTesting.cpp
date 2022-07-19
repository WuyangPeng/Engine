///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ���԰汾��0.8.0.11 (2022/07/19 15:41)

#include "ThreadingCoreRenderEngineGame/Version.h"
#include "ThreadingCoreRenderEngineGameTesting/Version.h"
#include "VersionTesting.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

ThreadingCoreRenderEngineGame::VersionTesting::VersionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ThreadingCoreRenderEngineGame, VersionTesting)

void ThreadingCoreRenderEngineGame::VersionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void ThreadingCoreRenderEngineGame::VersionTesting::MainTest()
{
    ASSERT_GREATER_EQUAL(g_TCREGameVersion, g_TCREGameTestingVersion);
}
