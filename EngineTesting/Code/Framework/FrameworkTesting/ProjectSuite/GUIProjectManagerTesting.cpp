///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 14:11)

#include "GUIProjectManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/Project/GUIProjectManager.h"
#include "Framework/Project/ProjectName.h"

Framework::GUIProjectManagerTesting::GUIProjectManagerTesting(const OStreamShared& stream)
    : ParentType{ stream },
      environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, GUIProjectManagerTesting)

void Framework::GUIProjectManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::GUIProjectManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PrintSelectTest);
}

void Framework::GUIProjectManagerTesting::PrintSelectTest()
{
    const GUIProjectManager guiProjectManager{ MiddleLayerPlatform::Windows, environmentDirectory };

    const ProjectName projectName{ SYSTEM_TEXT("Project.json"), EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    guiProjectManager.PrintSelect(projectName);
    guiProjectManager.PrintEngineering(SYSTEM_TEXT("Engineering"));
}
