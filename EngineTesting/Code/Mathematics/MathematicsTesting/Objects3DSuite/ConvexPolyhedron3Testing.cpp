///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/28 15:57)

#include "ConvexPolyhedron3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/ConvexPolyhedron3Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

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
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ 0.0, 100.0 };
    const uniform_real<double> secondRandomDistribution(-100.0, 0.0);
    const uniform_real<double> thirdRandomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto positive = firstRandomDistribution(generator);
        auto negative = secondRandomDistribution(generator);

        Vector3D firstVector(positive, negative, positive);

        Vector3D secondVector(positive, negative, negative);

        Vector3D thirdVector(positive, positive, negative);

        Vector3D fourthVector(positive, positive, positive);

        Vector3D fifthVector(negative, negative, positive);

        Vector3D sixthVector(negative, negative, negative);

        Vector3D seventhVector(negative, positive, negative);

        Vector3D eighthVector(negative, positive, positive);

        constexpr int numVertices = 8;

        Polyhedron3D::VerticesType verticesType(numVertices);

        verticesType.at(0) = firstVector;
        verticesType.at(1) = secondVector;
        verticesType.at(2) = thirdVector;
        verticesType.at(3) = fourthVector;
        verticesType.at(4) = fifthVector;
        verticesType.at(5) = sixthVector;
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

        // Vector3Ptr��ֵҲ��SetVertex�޸���
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
