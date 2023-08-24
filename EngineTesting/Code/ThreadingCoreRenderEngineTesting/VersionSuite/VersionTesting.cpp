///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/01 09:41)

#include "ThreadingCoreRenderEngineTesting/Version.h"
#include "VersionTesting.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite//UnitTestDetail.h"

namespace ThreadingCoreRenderEngine
{
    using TestingType = CoreTools::Version;
}

ThreadingCoreRenderEngine::VersionTesting::VersionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ThreadingCoreRenderEngine, VersionTesting)

void ThreadingCoreRenderEngine::VersionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void ThreadingCoreRenderEngine::VersionTesting::MainTest()
{
    TestingType version{};

    ASSERT_GREATER_EQUAL(version.GetTCREFullVersion(), gTCRETestingVersion);
}
