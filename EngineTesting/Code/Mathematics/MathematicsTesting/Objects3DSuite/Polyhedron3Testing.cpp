///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:20)

#include "Polyhedron3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Objects3D/Polyhedron3Detail.h"

#include <random>

namespace Mathematics
{
    template class Polyhedron3<float>;
    template class Polyhedron3<double>;
}

Mathematics::Polyhedron3Testing::Polyhedron3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Polyhedron3Testing)

void Mathematics::Polyhedron3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Polyhedron3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PolyhedronTest);
}

void Mathematics::Polyhedron3Testing::PolyhedronTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    const std::uniform_real<double> randomDistribution0(0.0, 100.0);
    const std::uniform_real<double> randomDistribution1(-100.0, 0.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D vector0(randomDistribution0(generator),
                               randomDistribution1(generator),
                               randomDistribution0(generator));

        const Vector3D vector1(randomDistribution0(generator),
                               randomDistribution1(generator),
                               randomDistribution1(generator));

        const Vector3D vector2(randomDistribution0(generator),
                               randomDistribution0(generator),
                               randomDistribution1(generator));

        const Vector3D vector3(randomDistribution0(generator),
                               randomDistribution0(generator),
                               randomDistribution0(generator));

        const Vector3D vector4(randomDistribution1(generator),
                               randomDistribution1(generator),
                               randomDistribution0(generator));

        const Vector3D vector5(randomDistribution1(generator),
                               randomDistribution1(generator),
                               randomDistribution1(generator));

        const Vector3D seventhVector(randomDistribution1(generator),
                                     randomDistribution0(generator),
                                     randomDistribution1(generator));

        const Vector3D eighthVector(randomDistribution1(generator),
                                    randomDistribution0(generator),
                                    randomDistribution0(generator));

        constexpr int numVertices = 8;

        Polyhedron3D::VerticesType vertices{ vector0, vector1, vector2, vector3, vector4, vector5, seventhVector, eighthVector };

        constexpr int numTriangles = 12;

        Polyhedron3D::IndicesType intPtr{
            0,
            1,
            2,

            0,
            2,
            3,

            4,
            0,
            3,

            4,
            3,
            7,

            5,
            4,
            7,

            5,
            7,
            6,

            6,
            2,
            1,

            6,
            1,
            5,

            3,
            2,
            6,

            7,
            3,
            6,

            5,
            1,
            0,

            5,
            0,
            4
        };

        Polyhedron3D polyhedron{ vertices, intPtr };

        ASSERT_EQUAL(numVertices, polyhedron.GetNumVertices());
        ASSERT_EQUAL(vertices, polyhedron.GetVertices());

        ASSERT_EQUAL(numTriangles, polyhedron.GetNumTriangles());
        ASSERT_EQUAL(numTriangles * 3, polyhedron.GetNumIndices());

        ASSERT_EQUAL(intPtr, polyhedron.GetIndices());

        const Vector3D ninthVector(randomDistribution1(generator), randomDistribution1(generator), randomDistribution1(generator));

        Vector3D average = vertices.at(0);
        for (int m = 1; m < numVertices; ++m)
        {
            average += vertices.at(m);
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

            const auto v0 = intPtr.at(k0);
            const auto v1 = intPtr.at(k1);
            const auto v2 = intPtr.at(k2);
            const auto edge0 = vertices.at(v1) - vertices.at(v0);
            const auto edge1 = vertices.at(v2) - vertices.at(v0);
            const auto cross = Vector3ToolsD::CrossProduct(edge0, edge1);
            surfaceArea += Vector3ToolsD::GetLength(cross);
            volume += Vector3ToolsD::DotProduct(vertices.at(v0), cross);
        }

        surfaceArea *= 0.5;
        volume /= 6.0;

        ASSERT_APPROXIMATE(surfaceArea, polyhedron.ComputeSurfaceArea(), 1e-10);
        ASSERT_APPROXIMATE(volume, polyhedron.ComputeVolume(), 1e-9);
    }
}
