///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:30)

#include "Matrix3ExtractTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AxisAngleDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector3Tools.h"

#include <random>

namespace Mathematics
{
    template class AxisAngle<float>;
    template class AxisAngle<double>;
}

Mathematics::Matrix3ExtractTesting::Matrix3ExtractTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Matrix3ExtractTesting)

void Mathematics::Matrix3ExtractTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Matrix3ExtractTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ExtractTest);
}

void Mathematics::Matrix3ExtractTesting::ExtractTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution{ -10.0, 10.0 };
    std::uniform_real_distribution<double> angleDistribution(0.0, MathD::GetPI());

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Vector3D vector0{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };
        vector0.Normalize();

        const double angle = angleDistribution(generator);

        const Matrix3D matrix0(vector0, angle);

        const auto matrix3Extract = matrix0.ExtractAngleAxis();

        ASSERT_APPROXIMATE(matrix3Extract.GetAngle(), angle, 1e-10);

        ASSERT_TRUE(Vector3ToolsD::Approximate(matrix3Extract.GetAxis(), vector0));
    }
}
