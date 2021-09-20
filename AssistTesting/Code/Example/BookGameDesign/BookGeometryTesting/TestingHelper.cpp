// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助测试版本：0.1.0.1 (2020/04/06 21:43)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookGameDesign/BookGeometry/Helper/BookGeometryClassInvariantMacro.h"

BookGeometry::TestingHelper ::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "【书籍·游戏设计·几何学】单元测试套件" }
{
    InitSuite();

    BOOK_GEOMETRY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookGeometry, TestingHelper)

void BookGeometry::TestingHelper ::InitSuite()
{
    Add3DMathPrimerForGraphicsAndGameDevelopmentSuite();
    AddMathematicsFor3DGameProgrammingAndComputerGraphicsSuite();
    AddGeometricToolsForComputerGraphicsSuite();
    AddProceduralElementsForComputerGraphicsSuite();
}

void BookGeometry::TestingHelper ::Add3DMathPrimerForGraphicsAndGameDevelopmentSuite()
{
    auto threeDMathPrimerForGraphicsAndGameDevelopmentSuite = GenerateSuite("3D数学基础：图形与游戏开发");

    ADD_TEST(threeDMathPrimerForGraphicsAndGameDevelopmentSuite, ThreeDMathPrimerForGraphicsAndGameDevelopmentMainTesting);
    ADD_TEST(threeDMathPrimerForGraphicsAndGameDevelopmentSuite, ThreeDMathPrimerForGraphicsAndGameDevelopmentCodeTesting);

    AddSuite(threeDMathPrimerForGraphicsAndGameDevelopmentSuite);
}

void BookGeometry::TestingHelper ::AddMathematicsFor3DGameProgrammingAndComputerGraphicsSuite()
{
    auto mathematicsFor3DGameProgrammingAndComputerGraphicsSuite = GenerateSuite("3D游戏与计算机图形学中的数学方法");

    ADD_TEST(mathematicsFor3DGameProgrammingAndComputerGraphicsSuite, MathematicsFor3DMainTesting);
    ADD_TEST(mathematicsFor3DGameProgrammingAndComputerGraphicsSuite, MathematicsFor3DCodeTesting);

    AddSuite(mathematicsFor3DGameProgrammingAndComputerGraphicsSuite);
}

void BookGeometry::TestingHelper ::AddGeometricToolsForComputerGraphicsSuite()
{
    auto geometricToolsForComputerGraphicsSuite = GenerateSuite("计算机图形学几何工具算法详解");

    ADD_TEST(geometricToolsForComputerGraphicsSuite, GeometricToolsForComputerGraphicsMainTesting);

    AddSuite(geometricToolsForComputerGraphicsSuite);
}

void BookGeometry::TestingHelper ::AddProceduralElementsForComputerGraphicsSuite()
{
    auto proceduralElementsForComputerGraphicsSuite = GenerateSuite("计算机图形学的算法基础");

    ADD_TEST(proceduralElementsForComputerGraphicsSuite, ProceduralElementsForComputerGraphicsMainTesting);

    AddSuite(proceduralElementsForComputerGraphicsSuite);
}
