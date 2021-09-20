///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������Ϸ���԰汾��0.7.0.1 (2021/02/17 15:19)

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
