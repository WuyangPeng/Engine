///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 10:39)

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

// private
void AssistTools::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddGenerateProjectsSuite();
    AddFeaturesImporterSuite();
    AddBmpColorToGraySuite();
    AddBmpToWmtfSuite();
    AddWmfxCompilerSuite();
}

void AssistTools::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("��");

    AddSuite(helperSuite);
}

void AssistTools::TestingHelper::AddGenerateProjectsSuite()
{
    auto generateProjectsSuite = GenerateSuite("������Ŀ");

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
