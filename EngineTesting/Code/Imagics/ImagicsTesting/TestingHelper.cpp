// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.3 (2019/09/09 17:51)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

Imagics::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "ͼ�����" }
{
    InitSuite();

    IMAGICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Imagics, TestingHelper)

// private
void Imagics::TestingHelper ::InitSuite()
{
    AddMacroSuite();
    AddBinaryOperationsSuite();
    AddExtractionSuite();
    AddFiltersSuite();
    AddImagesSuite();
    AddRasterDrawingSuite();
    AddSegmentersSuite();
    AddOpenCVSuite();
}

void Imagics::TestingHelper ::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("��");

    AddSuite(macroSuite);
}

void Imagics::TestingHelper ::AddBinaryOperationsSuite()
{
    auto binaryOperationsSuite = GenerateSuite("�����");

    AddSuite(binaryOperationsSuite);
}

void Imagics::TestingHelper ::AddExtractionSuite()
{
    auto extractionSuite = GenerateSuite("��ȡ");

    AddSuite(extractionSuite);
}

void Imagics::TestingHelper ::AddFiltersSuite()
{
    auto filtersSuite = GenerateSuite("������");

    AddSuite(filtersSuite);
}

void Imagics::TestingHelper ::AddImagesSuite()
{
    auto imagesSuite = GenerateSuite("ͼƬ");

    AddSuite(imagesSuite);
}

void Imagics::TestingHelper ::AddRasterDrawingSuite()
{
    auto rasterDrawingSuite = GenerateSuite("��դͼ");

    AddSuite(rasterDrawingSuite);
}

void Imagics::TestingHelper ::AddSegmentersSuite()
{
    auto segmentersSuite = GenerateSuite("�߶�");

    AddSuite(segmentersSuite);
}

void Imagics::TestingHelper ::AddOpenCVSuite()
{
    auto openCVSuite = GenerateSuite("OpenCV");

    AddSuite(openCVSuite);
}
