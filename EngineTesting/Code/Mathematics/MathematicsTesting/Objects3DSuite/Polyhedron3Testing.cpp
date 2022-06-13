///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/30 11:33)

#include "Polyhedron3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Objects3D/Polyhedron3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Polyhedron3<float>;
    template class Polyhedron3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Polyhedron3Testing)

void Mathematics::Polyhedron3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PolyhedronTest);
}

void Mathematics::Polyhedron3Testing::PolyhedronTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution(0.0, 100.0);
    const uniform_real<double> secondRandomDistribution(-100.0, 0.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector3D firstVector(firstRandomDistribution(generator),
                                   secondRandomDistribution(generator),
                                   firstRandomDistribution(generator));

        const Vector3D secondVector(firstRandomDistribution(generator),
                                    secondRandomDistribution(generator),
                                    secondRandomDistribution(generator));

        const Vector3D thirdVector(firstRandomDistribution(generator),
                                   firstRandomDistribution(generator),
                                   secondRandomDistribution(generator));

        const Vector3D fourthVector(firstRandomDistribution(generator),
                                    firstRandomDistribution(generator),
                                    firstRandomDistribution(generator));

        const Vector3D fifthVector(secondRandomDistribution(generator),
                                   secondRandomDistribution(generator),
                                   firstRandomDistribution(generator));

        const Vector3D sixthVector(secondRandomDistribution(generator),
                                   secondRandomDistribution(generator),
                                   secondRandomDistribution(generator));

        const Vector3D seventhVector(secondRandomDistribution(generator),
                                     firstRandomDistribution(generator),
                                     secondRandomDistribution(generator));

        const Vector3D eighthVector(secondRandomDistribution(generator),
                                    firstRandomDistribution(generator),
                                    firstRandomDistribution(generator));

        constexpr int numVertices = 8;

        Polyhedron3D::VerticesType vector3{ firstVector, secondVector, thirdVector, fourthVector, fifthVector, sixthVector, seventhVector, eighthVector };

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

        Polyhedron3D polyhedron{ vector3, intPtr };

        ASSERT_EQUAL(numVertices, polyhedron.GetNumVertices());
        ASSERT_EQUAL(vector3, polyhedron.GetVertices());

        ASSERT_EQUAL(numTriangles, polyhedron.GetNumTriangles());
        ASSERT_EQUAL(numTriangles * 3, polyhedron.GetNumIndices());

        ASSERT_EQUAL(intPtr, polyhedron.GetIndices());

        const Vector3D ninthVector(secondRandomDistribution(generator), secondRandomDistribution(generator), secondRandomDistribution(generator));

        Vector3D average = vector3.at(0);
        for (int m = 1; m < numVertices; ++m)
        {
            average += vector3.at(m);
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
            const auto edge0 = vector3.at(v1) - vector3.at(v0);
            const auto edge1 = vector3.at(v2) - vector3.at(v0);
            const auto cross = Vector3ToolsD::CrossProduct(edge0, edge1);
            surfaceArea += Vector3ToolsD::GetLength(cross);
            volume += Vector3ToolsD::DotProduct(vector3.at(v0), cross);
        }

        surfaceArea *= 0.5;
        volume /= 6.0;

        ASSERT_APPROXIMATE(surfaceArea, polyhedron.ComputeSurfaceArea(), 1e-10);
        ASSERT_APPROXIMATE(volume, polyhedron.ComputeVolume(), 1e-9);
    }
}
