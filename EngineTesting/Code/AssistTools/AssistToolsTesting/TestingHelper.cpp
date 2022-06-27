///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/22 15:35)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

AssistTools::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�������߿�" }
{
    InitSuite();

    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, TestingHelper)

// private
void AssistTools::TestingHelper::InitSuite()
{
    AddMacroSuite();
    AddGenerateProjectsSuite();
    AddFeaturesImporterSuite();
    AddBmpColorToGraySuite();
    AddBmpToWmtfSuite();
    AddWmfxCompilerSuite();
}

void AssistTools::TestingHelper::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("��");

    AddSuite(macroSuite);
}

void AssistTools::TestingHelper::AddGenerateProjectsSuite()
{
    auto generateProjectsSuite = GenerateSuite("������Ŀ");

    ADD_TEST(generateProjectsSuite, GenerateTemplateSolutionTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateVcxprojTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateVcxprojFiltersTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateMiddleLayerVcxprojTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateMiddleLayerVcxprojFiltersTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateModuleVcxprojTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateModuleVcxprojFiltersTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateLogJsonTesting);
    ADD_TEST(generateProjectsSuite, CopyrightDataTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateHeaderTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateHelperTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateMessageTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateLibTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateMainTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateManagerTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateManagerLibTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateDllMainTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateDllLibTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateMacroTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateEngineTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateEngineDirectoryTesting);
    ADD_TEST(generateProjectsSuite, GenerateTemplateCodeDirectoryTesting);
    ADD_TEST(generateProjectsSuite, GenerateTestingTemplateSolutionTesting);
    ADD_TEST(generateProjectsSuite, GenerateTestingTemplateVcxprojTesting);
    ADD_TEST(generateProjectsSuite, GenerateTestingTemplateVcxprojFiltersTesting);
    ADD_TEST(generateProjectsSuite, GenerateTestingTemplateEngineTesting);
    ADD_TEST(generateProjectsSuite, GenerateTestingTemplateEngineDirectoryTesting);
    ADD_TEST(generateProjectsSuite, GenerateTestingTemplateCodeDirectoryTesting);

    AddSuite(generateProjectsSuite);
}

void AssistTools::TestingHelper::AddFeaturesImporterSuite()
{
    auto featuresImporterSuite = GenerateSuite("��������");

    AddSuite(featuresImporterSuite);
}

void AssistTools::TestingHelper::AddBmpColorToGraySuite()
{
    auto bmpColorToGraySuite = GenerateSuite("��̬Bmp��ɫ");

    AddSuite(bmpColorToGraySuite);
}

void AssistTools::TestingHelper::AddBmpToWmtfSuite()
{
    auto bmpToWmtfSuite = GenerateSuite("Bmpת��Wmtf");

    AddSuite(bmpToWmtfSuite);
}

void AssistTools::TestingHelper::AddWmfxCompilerSuite()
{
    auto wmfxCompilerSuite = GenerateSuite("Wmfx������");

    AddSuite(wmfxCompilerSuite);
}
