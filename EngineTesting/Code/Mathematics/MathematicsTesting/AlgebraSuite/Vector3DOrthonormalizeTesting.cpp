///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:44)

#include "Vector3DOrthonormalizeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3OrthonormalizeDetail.h"
#include "Mathematics/Algebra/Vector3Tools.h"

#include <random>

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
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real<double> randomDistribution0{ -10.0, 10.0 };
    std::uniform_real<float> randomDistribution1{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector3D vector0(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));
        Vector3D vector1(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));
        Vector3D vector2(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));

        Vector3F vector3(randomDistribution1(generator),
                         randomDistribution1(generator),
                         randomDistribution1(generator));
        Vector3F vector4(randomDistribution1(generator),
                         randomDistribution1(generator),
                         randomDistribution1(generator));
        Vector3F vector5(randomDistribution1(generator),
                         randomDistribution1(generator),
                         randomDistribution1(generator));

        const Vector3OrthonormalizeD firstOrthonormalize(vector0, vector1, vector2, 1e-10);

        vector0.Normalize();
        double dot0 = Vector3ToolsD::DotProduct(vector0, vector1);
        vector1 -= vector0 * dot0;
        vector1.Normalize();
        dot0 = Vector3ToolsD::DotProduct(vector0, vector2);
        vector2 -= vector0 * dot0;
        dot0 = Vector3ToolsD::DotProduct(vector1, vector2);
        vector2 -= vector1 * dot0;
        vector2.Normalize();

        ASSERT_TRUE(Vector3ToolsD::Approximate(vector0, firstOrthonormalize.GetUVector(), 1e-10));

        ASSERT_TRUE(Vector3ToolsD::Approximate(vector1, firstOrthonormalize.GetVVector(), 1e-10));

        ASSERT_TRUE(Vector3ToolsD::Approximate(vector2, firstOrthonormalize.GetWVector(), 1e-10));

        const Vector3OrthonormalizeF secondOrthonormalize(vector3, vector4, vector5, 1e-4f);

        vector3.Normalize();
        float dot1 = Vector3ToolsF::DotProduct(vector3, vector4);
        vector4 -= vector3 * dot1;
        vector4.Normalize();

        dot1 = Vector3ToolsF::DotProduct(vector3, vector5);
        vector5 -= vector3 * dot1;
        dot1 = Vector3ToolsF::DotProduct(vector4, vector5);
        vector5 -= vector4 * dot1;
        vector5.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector3, secondOrthonormalize.GetUVector(), 1e-8f));

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector4, secondOrthonormalize.GetVVector(), 1e-6f));

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector5, secondOrthonormalize.GetWVector(), 1e-4f));
    }
}
