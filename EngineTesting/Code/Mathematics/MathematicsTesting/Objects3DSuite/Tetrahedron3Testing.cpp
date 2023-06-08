///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/31 11:25)

#include "Tetrahedron3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Objects3D/Tetrahedron3Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class Tetrahedron3<float>;
    template class Tetrahedron3<double>;
}

Mathematics::Tetrahedron3Testing::Tetrahedron3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Tetrahedron3Testing)

void Mathematics::Tetrahedron3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Tetrahedron3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TetrahedronTest);
}

void Mathematics::Tetrahedron3Testing::TetrahedronTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D firstPoint(firstRandomDistribution(generator),
                                  firstRandomDistribution(generator),
                                  -MathD::FAbs(firstRandomDistribution(generator)));

        const Vector3D secondPoint(MathD::FAbs(firstRandomDistribution(generator)),
                                   -MathD::FAbs(firstRandomDistribution(generator)),
                                   0.0);

        const Vector3D thirdPoint(firstRandomDistribution(generator),
                                  MathD::FAbs(firstRandomDistribution(generator)),
                                  0.0);

        const Vector3D fourthPoint(-MathD::FAbs(firstRandomDistribution(generator)),
                                   -MathD::FAbs(firstRandomDistribution(generator)),
                                   0.0);

        const Tetrahedron3D tetrahedron(firstPoint, secondPoint, thirdPoint, fourthPoint);

        ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedron.GetVertex(0), firstPoint));
        ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedron.GetVertex(1), secondPoint));
        ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedron.GetVertex(2), thirdPoint));
        ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedron.GetVertex(3), fourthPoint));

        vector<Vector3D> Vector3dVector;
        Vector3dVector.emplace_back(firstPoint);
        Vector3dVector.emplace_back(secondPoint);
        Vector3dVector.emplace_back(thirdPoint);
        Vector3dVector.emplace_back(fourthPoint);

        const Tetrahedron3D secondTetrahedron(Vector3dVector);

        ASSERT_TRUE(Vector3ToolsD::Approximate(secondTetrahedron.GetVertex(0), firstPoint));
        ASSERT_TRUE(Vector3ToolsD::Approximate(secondTetrahedron.GetVertex(1), secondPoint));
        ASSERT_TRUE(Vector3ToolsD::Approximate(secondTetrahedron.GetVertex(2), thirdPoint));
        ASSERT_TRUE(Vector3ToolsD::Approximate(secondTetrahedron.GetVertex(3), fourthPoint));

        auto faceIndices = Tetrahedron3D::GetFaceIndices(0);

        ASSERT_EQUAL(faceIndices.size(), 3u);

        ASSERT_EQUAL(faceIndices.at(0), 0);
        ASSERT_EQUAL(faceIndices.at(1), 2);
        ASSERT_EQUAL(faceIndices.at(2), 1);

        faceIndices = Tetrahedron3D::GetFaceIndices(1);

        ASSERT_EQUAL(faceIndices.size(), 3u);

        ASSERT_EQUAL(faceIndices.at(0), 0);
        ASSERT_EQUAL(faceIndices.at(1), 1);
        ASSERT_EQUAL(faceIndices.at(2), 3);

        faceIndices = Tetrahedron3D::GetFaceIndices(2);

        ASSERT_EQUAL(faceIndices.size(), 3u);

        ASSERT_EQUAL(faceIndices.at(0), 0);
        ASSERT_EQUAL(faceIndices.at(1), 3);
        ASSERT_EQUAL(faceIndices.at(2), 2);

        faceIndices = Tetrahedron3D::GetFaceIndices(3);

        ASSERT_EQUAL(faceIndices.size(), 3u);

        ASSERT_EQUAL(faceIndices.at(0), 1);
        ASSERT_EQUAL(faceIndices.at(1), 2);
        ASSERT_EQUAL(faceIndices.at(2), 3);

        auto firstPlaneVector = secondTetrahedron.GetPlanes();
        auto secondPlaneVector = tetrahedron.GetPlanes();

        ASSERT_EQUAL(firstPlaneVector.size(), 4u);
        ASSERT_EQUAL(secondPlaneVector.size(), 4u);

        for (auto m = 0; m < 4; ++m)
        {
            ASSERT_APPROXIMATE(firstPlaneVector.at(m).GetConstant(), secondPlaneVector.at(m).GetConstant(), 1e-10);
            ASSERT_TRUE(Vector3ToolsD::Approximate(firstPlaneVector.at(m).GetNormal(), secondPlaneVector.at(m).GetNormal()));

            faceIndices = Tetrahedron3D::GetFaceIndices(m);

            ASSERT_ENUM_EQUAL(firstPlaneVector.at(m).WhichSide(tetrahedron.GetVertex(faceIndices.at(0))), NumericalValueSymbol::Zero);

            ASSERT_ENUM_EQUAL(firstPlaneVector.at(m).WhichSide(tetrahedron.GetVertex(faceIndices.at(1))), NumericalValueSymbol::Zero);

            ASSERT_ENUM_EQUAL(firstPlaneVector.at(m).WhichSide(tetrahedron.GetVertex(faceIndices.at(2))), NumericalValueSymbol::Zero);
        }

        ASSERT_ENUM_EQUAL(firstPlaneVector.at(0).WhichSide(tetrahedron.GetVertex(3)), NumericalValueSymbol::Negative);

        ASSERT_ENUM_EQUAL(firstPlaneVector.at(1).WhichSide(tetrahedron.GetVertex(2)), NumericalValueSymbol::Negative);

        ASSERT_ENUM_EQUAL(firstPlaneVector.at(2).WhichSide(tetrahedron.GetVertex(1)), NumericalValueSymbol::Negative);

        ASSERT_ENUM_EQUAL(firstPlaneVector.at(3).WhichSide(tetrahedron.GetVertex(0)), NumericalValueSymbol::Negative);
    }
}
