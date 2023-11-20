///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��1.0.0.0 (2023/11/08 09:10)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

AssistTools::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�������߿�" }
{
    InitSuite();

    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, TestingHelper)

void AssistTools::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddGenerateProjectsSuite();
}

void AssistTools::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("����");

    AddSuite(helperSuite);
}

void AssistTools::TestingHelper::AddGenerateProjectsSuite()
{
    auto generateProjectsSuite = GenerateSuite("������Ŀ");

    ADD_TEST(generateProjectsSuite, GameModuleTesting);
    ADD_TEST(generateProjectsSuite, MiddleLayerModuleTesting);
    ADD_TEST(generateProjectsSuite, GameParameterAnalysisTesting);
    generateProjectsSuite.AddSuite(GetProjectGenerationSuite());
    ADD_TEST(generateProjectsSuite, ReplaceTesting);
    ADD_TEST(generateProjectsSuite, GenerateEngineTesting);
    ADD_TEST(generateProjectsSuite, GenerateTestingEngineTesting);

    AddSuite(generateProjectsSuite);
}

CoreTools::Suite AssistTools::TestingHelper::GetProjectGenerationSuite()
{
    auto projectGenerationSuite = GenerateSuite("��������");

    ADD_TEST(projectGenerationSuite, DefaultProjectGenerationTesting);
    ADD_TEST(projectGenerationSuite, ClientProjectGenerationTesting);
    ADD_TEST(projectGenerationSuite, ReplaceProjectGenerationTesting);
    ADD_TEST(projectGenerationSuite, Utf8ReplaceProjectGenerationTesting);

    return projectGenerationSuite;
}
