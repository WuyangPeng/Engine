///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:59)

#include "Vector3DOrthonormalizeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3OrthonormalizeDetail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Vector3Orthonormalize<float>;
    template class Vector3Orthonormalize<double>;
}

Mathematics::Vector3OrthonormalizeTesting::Vector3OrthonormalizeTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Vector3OrthonormalizeTesting)

void Mathematics::Vector3OrthonormalizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Vector3OrthonormalizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalizeTest);
}

void Mathematics::Vector3OrthonormalizeTesting::OrthonormalizeTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution{ -10.0, 10.0 };
    const uniform_real<float> secondRandomDistribution{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector3D firstVector(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             firstRandomDistribution(generator));
        Vector3D secondVector(firstRandomDistribution(generator),
                              firstRandomDistribution(generator),
                              firstRandomDistribution(generator));
        Vector3D thirdVector(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             firstRandomDistribution(generator));

        Vector3F fourthVector(secondRandomDistribution(generator),
                              secondRandomDistribution(generator),
                              secondRandomDistribution(generator));
        Vector3F fifthVector(secondRandomDistribution(generator),
                             secondRandomDistribution(generator),
                             secondRandomDistribution(generator));
        Vector3F sixthVector(secondRandomDistribution(generator),
                             secondRandomDistribution(generator),
                             secondRandomDistribution(generator));

        const Vector3OrthonormalizeD firstOrthonormalize(firstVector, secondVector, thirdVector, 1e-10);

        firstVector.Normalize();
        double dot0 = Vector3ToolsD::DotProduct(firstVector, secondVector);
        secondVector -= firstVector * dot0;
        secondVector.Normalize();
        dot0 = Vector3ToolsD::DotProduct(firstVector, thirdVector);
        thirdVector -= firstVector * dot0;
        dot0 = Vector3ToolsD::DotProduct(secondVector, thirdVector);
        thirdVector -= secondVector * dot0;
        thirdVector.Normalize();

        ASSERT_TRUE(Vector3ToolsD::Approximate(firstVector, firstOrthonormalize.GetUVector(), 1e-10));

        ASSERT_TRUE(Vector3ToolsD::Approximate(secondVector, firstOrthonormalize.GetVVector(), 1e-10));

        ASSERT_TRUE(Vector3ToolsD::Approximate(thirdVector, firstOrthonormalize.GetWVector(), 1e-10));

        const Vector3OrthonormalizeF secondOrthonormalize(fourthVector, fifthVector, sixthVector, 1e-4f);

        fourthVector.Normalize();
        float dot1 = Vector3ToolsF::DotProduct(fourthVector, fifthVector);
        fifthVector -= fourthVector * dot1;
        fifthVector.Normalize();

        dot1 = Vector3ToolsF::DotProduct(fourthVector, sixthVector);
        sixthVector -= fourthVector * dot1;
        dot1 = Vector3ToolsF::DotProduct(fifthVector, sixthVector);
        sixthVector -= fifthVector * dot1;
        sixthVector.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(fourthVector, secondOrthonormalize.GetUVector(), 1e-8f));

        ASSERT_TRUE(Vector3ToolsF::Approximate(fifthVector, secondOrthonormalize.GetVVector(), 1e-6f));

        ASSERT_TRUE(Vector3ToolsF::Approximate(sixthVector, secondOrthonormalize.GetWVector(), 1e-4f));
    }
}
