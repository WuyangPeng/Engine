// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 16:38)

#include "EllipsoidFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/EllipsoidFit3Detail.h"
#include "Mathematics/Objects3D/Box3Detail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, EllipsoidFit3Testing)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
void Mathematics::EllipsoidFit3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::EllipsoidFit3Testing ::FitTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(0.0, 100.0);
    uniform_int<> secondRandomDistribution(15, 20);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        EllipsoidFit3D ellipseFit(vertices);

        Vector3D center = ellipseFit.GetCenter();
        Matrix3D matrix = ellipseFit.GetRotate();
        double firstExtent = ellipseFit.GetExtent0();
        double secondExtent = ellipseFit.GetExtent1();
        double thirdExtent = ellipseFit.GetExtent2();

        Ellipsoid3D ellipsoid(center, matrix * Vector3D::GetUnitX(), matrix * Vector3D::GetUnitY(), matrix * Vector3D::GetUnitZ(), firstExtent, secondExtent, thirdExtent);

        for (int i = 0; i < size; ++i)
        {
            ASSERT_LESS(ellipsoid.Evaluate(vertices[i]), 22.0);
        }
    }
}
