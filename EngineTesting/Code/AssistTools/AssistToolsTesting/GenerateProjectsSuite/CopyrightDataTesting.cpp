// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:51)

#include "CopyrightDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"

AssistTools::CopyrightDataTesting::CopyrightDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, CopyrightDataTesting)

void AssistTools::CopyrightDataTesting ::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::CopyrightDataTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
}

void AssistTools::CopyrightDataTesting ::AccessTest()
{
    int endYear = 2018;
    System::String versions(SYSTEM_TEXT("1.0.0.2"));
    System::String projectChineseName(SYSTEM_TEXT("“˝«Ê≤‚ ‘"));

    CopyrightData copyrightData(endYear, versions, projectChineseName);

    ASSERT_EQUAL(copyrightData.GetEndYear(), endYear);
    ASSERT_EQUAL(copyrightData.GetVersions(), versions);
    ASSERT_EQUAL(copyrightData.GetProjectChineseName(), projectChineseName);
}