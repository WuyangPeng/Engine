// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.4 (2019/09/10 10:03)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(AssistTools, TestingHelper, "辅助工具库")

// private
void AssistTools::TestingHelper ::AddSuites()
{
    AddMacroSuite();
    AddGenerateProjectsSuite();
    AddFeaturesImporterSuite();
    AddBmpColorToGraySuite();
    AddBmpToWmtfSuite();
    AddWmfxCompilerSuite();
}

void AssistTools::TestingHelper ::AddMacroSuite()
{
    ADD_TEST_BEGIN(macroSuite, "宏");

    ADD_TEST_END(macroSuite);
}

void AssistTools::TestingHelper ::AddGenerateProjectsSuite()
{
    ADD_TEST_BEGIN(generateProjectsSuite, "生成项目");

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

    ADD_TEST_END(generateProjectsSuite);
}

void AssistTools::TestingHelper ::AddFeaturesImporterSuite()
{
    ADD_TEST_BEGIN(featuresImporterSuite, "特征导入");

    ADD_TEST_END(featuresImporterSuite);
}

void AssistTools::TestingHelper ::AddBmpColorToGraySuite()
{
    ADD_TEST_BEGIN(bmpColorToGraySuite, "灰态Bmp颜色");

    ADD_TEST_END(bmpColorToGraySuite);
}

void AssistTools::TestingHelper ::AddBmpToWmtfSuite()
{
    ADD_TEST_BEGIN(bmpToWmtfSuite, "Bmp转换Wmtf");

    ADD_TEST_END(bmpToWmtfSuite);
}

void AssistTools::TestingHelper ::AddWmfxCompilerSuite()
{
    ADD_TEST_BEGIN(wmfxCompilerSuite, "Wmfx编译器");

    ADD_TEST_END(wmfxCompilerSuite);
}
