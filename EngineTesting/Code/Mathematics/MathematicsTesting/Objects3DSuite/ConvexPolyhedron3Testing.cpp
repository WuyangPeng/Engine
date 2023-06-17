///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:15)

#include "ConvexPolyhedron3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/ConvexPolyhedron3Detail.h"

#include <random>

namespace Mathematics
{
    template class ConvexPolyhedron3<float>;
    template class ConvexPolyhedron3<double>;
}

Mathematics::ConvexPolyhedron3Testing::ConvexPolyhedron3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, ConvexPolyhedron3Testing)

void Mathematics::ConvexPolyhedron3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::ConvexPolyhedron3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConvexPolyhedronTest);
}

void Mathematics::ConvexPolyhedron3Testing::ConvexPolyhedronTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0{ 0.0, 100.0 };
    const std::uniform_real<double> randomDistribution1(-100.0, 0.0);
    const std::uniform_real<double> thirdRandomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto positive = randomDistribution0(generator);
        auto negative = randomDistribution1(generator);

        Vector3D vector0(positive, negative, positive);

        Vector3D vector1(positive, negative, negative);

        Vector3D vector2(positive, positive, negative);

        Vector3D vector3(positive, positive, positive);

        Vector3D vector4(negative, negative, positive);

        Vector3D vector5(negative, negative, negative);

        Vector3D seventhVector(negative, positive, negative);

        Vector3D eighthVector(negative, positive, positive);

        constexpr int numVertices = 8;

        Polyhedron3D::VerticesType verticesType(numVertices);

        verticesType.at(0) = vector0;
        verticesType.at(1) = vector1;
        verticesType.at(2) = vector2;
        verticesType.at(3) = vector3;
        verticesType.at(4) = vector4;
        verticesType.at(5) = vector5;
        verticesType.at(6) = seventhVector;
        verticesType.at(7) = eighthVector;

        constexpr int numTriangles = 12;

        Polyhedron3D::IndicesType intPtr(numTriangles * 3);

        intPtr.at(0) = 0;
        intPtr.at(1) = 1;
        intPtr.at(2) = 2;

        intPtr.at(3) = 0;
        intPtr.at(4) = 2;
        intPtr.at(5) = 3;

        intPtr.at(6) = 4;
        intPtr.at(7) = 0;
        intPtr.at(8) = 3;

        intPtr.at(9) = 4;
        intPtr.at(10) = 3;
        intPtr.at(11) = 7;

        intPtr.at(12) = 5;
        intPtr.at(13) = 4;
        intPtr.at(14) = 7;

        intPtr.at(15) = 5;
        intPtr.at(16) = 7;
        intPtr.at(17) = 6;

        intPtr.at(18) = 6;
        intPtr.at(19) = 2;
        intPtr.at(20) = 1;

        intPtr.at(21) = 6;
        intPtr.at(22) = 1;
        intPtr.at(23) = 5;

        intPtr.at(24) = 3;
        intPtr.at(25) = 2;
        intPtr.at(26) = 6;

        intPtr.at(27) = 7;
        intPtr.at(28) = 3;
        intPtr.at(29) = 6;

        intPtr.at(30) = 5;
        intPtr.at(31) = 1;
        intPtr.at(32) = 0;

        intPtr.at(33) = 5;
        intPtr.at(34) = 0;
        intPtr.at(35) = 4;

        ConvexPolyhedron3D polyhedron{ verticesType, intPtr, {} };

        ASSERT_EQUAL(numVertices, polyhedron.GetNumVertices());
        ASSERT_EQUAL(verticesType, polyhedron.GetVertices());

        ASSERT_EQUAL(numTriangles, polyhedron.GetNumTriangles());
        ASSERT_EQUAL(numTriangles * 3, polyhedron.GetNumIndices());

        ASSERT_EQUAL(intPtr, polyhedron.GetIndices());

        const Vector3D ninthVector(negative, negative, negative);

        ASSERT_FALSE(polyhedron.IsUpdatePlanes());
        polyhedron.SetVertex(5, ninthVector);
        ASSERT_TRUE(polyhedron.IsUpdatePlanes());
        polyhedron.UpdatePlanes();
        ASSERT_FALSE(polyhedron.IsUpdatePlanes());

        ASSERT_TRUE(Vector3ToolsD::Approximate(ninthVector, polyhedron.GetVertex(5)));

        // Vector3Ptr的值也被SetVertex修改了
        Vector3D average = verticesType.at(0);
        for (auto m = 1; m < numVertices; ++m)
        {
            average += verticesType.at(m);
        }

        average /= static_cast<double>(numVertices);

        ASSERT_TRUE(Vector3ToolsD::Approximate(average, polyhedron.ComputeVertexAverage()));

        auto surfaceArea = 0.0;
        auto volume = 0.0;

        for (auto k = 0; k < numTriangles; ++k)
        {
            const auto k0 = k * 3;
            const auto k1 = k * 3 + 1;
            const auto k2 = k * 3 + 2;

            auto v0 = intPtr.at(k0);
            auto v1 = intPtr.at(k1);
            auto v2 = intPtr.at(k2);
            auto edge0 = verticesType.at(v1) - verticesType.at(v0);
            auto edge1 = verticesType.at(v2) - verticesType.at(v0);
            const auto cross = Vector3ToolsD::CrossProduct(edge0, edge1);
            surfaceArea += Vector3ToolsD::GetLength(cross);
            volume += Vector3ToolsD::DotProduct(verticesType.at(v0), cross);
        }

        surfaceArea *= 0.5;
        volume /= 6.0;

        ASSERT_APPROXIMATE(surfaceArea, polyhedron.ComputeSurfaceArea(), 1e-10);
        ASSERT_APPROXIMATE(volume, polyhedron.ComputeVolume(), 1e-8f);

        ASSERT_TRUE(polyhedron.IsConvex());

        for (auto k = 0; k < 2; ++k)
        {
            const Vector3D point(thirdRandomDistribution(generator),
                                 thirdRandomDistribution(generator),
                                 thirdRandomDistribution(generator));

            auto contains = true;

            for (auto j = 0; j < polyhedron.GetNumTriangles(); ++j)
            {
                const auto& plane = polyhedron.GetPlane(j);

                auto distance = plane.DistanceTo(point);

                if (distance < 0.0)
                {
                    contains = false;
                    break;
                }
            }

            ASSERT_EQUAL(polyhedron.Contains(point), contains);
        }
    }
}
