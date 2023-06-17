///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 10:53)

#include "CopyrightDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"

AssistTools::CopyrightDataTesting::CopyrightDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, CopyrightDataTesting)

void AssistTools::CopyrightDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::CopyrightDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
}

void AssistTools::CopyrightDataTesting::AccessTest()
{
    constexpr int endYear = 2018;
    System::String versions(SYSTEM_TEXT("1.0.0.2"));
    System::String projectChineseName(SYSTEM_TEXT("引擎测试"));

    CopyrightData copyrightData(endYear, versions, projectChineseName);

    ASSERT_EQUAL(copyrightData.GetEndYear(), endYear);
    ASSERT_EQUAL(copyrightData.GetVersions(), versions);
    ASSERT_EQUAL(copyrightData.GetProjectChineseName(), projectChineseName);
}