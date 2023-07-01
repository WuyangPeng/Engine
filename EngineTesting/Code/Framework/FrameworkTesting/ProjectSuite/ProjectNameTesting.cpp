///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/18 20:32)

#include "ProjectNameTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/Project/ProjectName.h"

Framework::ProjectNameTesting::ProjectNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ProjectNameTesting)

void Framework::ProjectNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ProjectNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectNameTest);
}

void Framework::ProjectNameTesting::ProjectNameTest()
{
    const ProjectName projectName{ SYSTEM_TEXT("Project.json"), EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") } };

    ASSERT_EQUAL(projectName.GetContainerPrintWidth(), 2);
    ASSERT_TRUE(projectName.IsSelectValid(0));
    ASSERT_TRUE(projectName.IsSelectValid(1));
    ASSERT_FALSE(projectName.IsSelectValid(11));
    ASSERT_EQUAL(projectName.GetEngineeringName(0), SYSTEM_TEXT("FrameworkTesting"));
    ASSERT_EQUAL(projectName.GetEngineeringName(1), SYSTEM_TEXT("FrameworkWindowTesting"));

    const auto describe = projectName.GetSelectDescribe();

    ASSERT_UNEQUAL(describe.find(SYSTEM_TEXT("WindowsAPIFrameTesting")), std::string::npos);
    ASSERT_UNEQUAL(describe.find(SYSTEM_TEXT("AndroidFrameBuildTesting")), std::string::npos);
    ASSERT_EQUAL(describe.find(SYSTEM_TEXT("FrameworkAndroidTesting")), std::string::npos);

    ASSERT_UNEQUAL(describe.find(SYSTEM_TEXT('0')), std::string::npos);
}
