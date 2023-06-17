///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:21)

#include "Tetrahedron3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Objects3D/Tetrahedron3Detail.h"

#include <random>

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
    std::default_random_engine generator{ GetEngineRandomSeed() };

    const std::uniform_real<double> randomDistribution0(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point0(randomDistribution0(generator),
                              randomDistribution0(generator),
                              -MathD::FAbs(randomDistribution0(generator)));

        const Vector3D point1(MathD::FAbs(randomDistribution0(generator)),
                              -MathD::FAbs(randomDistribution0(generator)),
                              0.0);

        const Vector3D point2(randomDistribution0(generator),
                              MathD::FAbs(randomDistribution0(generator)),
                              0.0);

        const Vector3D fourthPoint(-MathD::FAbs(randomDistribution0(generator)),
                                   -MathD::FAbs(randomDistribution0(generator)),
                                   0.0);

        const Tetrahedron3D tetrahedron(point0, point1, point2, fourthPoint);

        ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedron.GetVertex(0), point0));
        ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedron.GetVertex(1), point1));
        ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedron.GetVertex(2), point2));
        ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedron.GetVertex(3), fourthPoint));

        std::vector<Vector3D> Vector3dVector;
        Vector3dVector.emplace_back(point0);
        Vector3dVector.emplace_back(point1);
        Vector3dVector.emplace_back(point2);
        Vector3dVector.emplace_back(fourthPoint);

        const Tetrahedron3D secondTetrahedron(Vector3dVector);

        ASSERT_TRUE(Vector3ToolsD::Approximate(secondTetrahedron.GetVertex(0), point0));
        ASSERT_TRUE(Vector3ToolsD::Approximate(secondTetrahedron.GetVertex(1), point1));
        ASSERT_TRUE(Vector3ToolsD::Approximate(secondTetrahedron.GetVertex(2), point2));
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
