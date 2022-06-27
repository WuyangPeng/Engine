///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/21 15:45)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/ImagicsClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

Imagics::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "图像分析" }
{
    InitSuite();

    IMAGICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Imagics, TestingHelper)

// private
void Imagics::TestingHelper::InitSuite()
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

void Imagics::TestingHelper::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("宏");

    AddSuite(macroSuite);
}

void Imagics::TestingHelper::AddBinaryOperationsSuite()
{
    auto binaryOperationsSuite = GenerateSuite("运算符");

    AddSuite(binaryOperationsSuite);
}

void Imagics::TestingHelper::AddExtractionSuite()
{
    auto extractionSuite = GenerateSuite("提取");

    AddSuite(extractionSuite);
}

void Imagics::TestingHelper::AddFiltersSuite()
{
    auto filtersSuite = GenerateSuite("过滤器");

    AddSuite(filtersSuite);
}

void Imagics::TestingHelper::AddImagesSuite()
{
    auto imagesSuite = GenerateSuite("图片");

    AddSuite(imagesSuite);
}

void Imagics::TestingHelper::AddRasterDrawingSuite()
{
    auto rasterDrawingSuite = GenerateSuite("光栅图");

    AddSuite(rasterDrawingSuite);
}

void Imagics::TestingHelper::AddSegmentersSuite()
{
    auto segmentersSuite = GenerateSuite("线段");

    AddSuite(segmentersSuite);
}

void Imagics::TestingHelper::AddOpenCVSuite()
{
    auto openCVSuite = GenerateSuite("OpenCV");

    AddSuite(openCVSuite);
}
