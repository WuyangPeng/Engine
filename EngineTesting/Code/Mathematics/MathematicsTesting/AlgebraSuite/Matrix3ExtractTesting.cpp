///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 21:54)

#include "Matrix3ExtractTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Matrix3ExtractDetail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Matrix3Extract<float>;
    template class Matrix3Extract<double>;
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
    default_random_engine generator{};
    const uniform_real<double> randomDistribution{ -10.0, 10.0 };
    const uniform_real<double> angleDistribution(0.0, MathD::GetPI());

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Vector3D firstVector{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };
        firstVector.Normalize();

        const double angle = angleDistribution(generator);

        const Matrix3D firstMatrix(firstVector, angle);

        const Matrix3ExtractD matrix3Extract = firstMatrix.ExtractAngleAxis();

        ASSERT_APPROXIMATE(matrix3Extract.GetAngle(), angle, 1e-10);

        ASSERT_TRUE(Vector3ToolsD::Approximate(matrix3Extract.GetAxis(), firstVector));
    }
}
