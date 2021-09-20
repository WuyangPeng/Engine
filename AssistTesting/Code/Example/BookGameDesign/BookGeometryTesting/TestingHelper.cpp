// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.1.0.1 (2020/04/06 21:43)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookGameDesign/BookGeometry/Helper/BookGeometryClassInvariantMacro.h"

BookGeometry::TestingHelper ::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���鼮����Ϸ��ơ�����ѧ����Ԫ�����׼�" }
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
    auto threeDMathPrimerForGraphicsAndGameDevelopmentSuite = GenerateSuite("3D��ѧ������ͼ������Ϸ����");

    ADD_TEST(threeDMathPrimerForGraphicsAndGameDevelopmentSuite, ThreeDMathPrimerForGraphicsAndGameDevelopmentMainTesting);
    ADD_TEST(threeDMathPrimerForGraphicsAndGameDevelopmentSuite, ThreeDMathPrimerForGraphicsAndGameDevelopmentCodeTesting);

    AddSuite(threeDMathPrimerForGraphicsAndGameDevelopmentSuite);
}

void BookGeometry::TestingHelper ::AddMathematicsFor3DGameProgrammingAndComputerGraphicsSuite()
{
    auto mathematicsFor3DGameProgrammingAndComputerGraphicsSuite = GenerateSuite("3D��Ϸ������ͼ��ѧ�е���ѧ����");

    ADD_TEST(mathematicsFor3DGameProgrammingAndComputerGraphicsSuite, MathematicsFor3DMainTesting);
    ADD_TEST(mathematicsFor3DGameProgrammingAndComputerGraphicsSuite, MathematicsFor3DCodeTesting);

    AddSuite(mathematicsFor3DGameProgrammingAndComputerGraphicsSuite);
}

void BookGeometry::TestingHelper ::AddGeometricToolsForComputerGraphicsSuite()
{
    auto geometricToolsForComputerGraphicsSuite = GenerateSuite("�����ͼ��ѧ���ι����㷨���");

    ADD_TEST(geometricToolsForComputerGraphicsSuite, GeometricToolsForComputerGraphicsMainTesting);

    AddSuite(geometricToolsForComputerGraphicsSuite);
}

void BookGeometry::TestingHelper ::AddProceduralElementsForComputerGraphicsSuite()
{
    auto proceduralElementsForComputerGraphicsSuite = GenerateSuite("�����ͼ��ѧ���㷨����");

    ADD_TEST(proceduralElementsForComputerGraphicsSuite, ProceduralElementsForComputerGraphicsMainTesting);

    AddSuite(proceduralElementsForComputerGraphicsSuite);
}
