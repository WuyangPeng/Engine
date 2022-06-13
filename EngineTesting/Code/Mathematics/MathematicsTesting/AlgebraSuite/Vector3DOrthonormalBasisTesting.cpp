///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 22:59)

#include "Vector3DOrthonormalBasisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3OrthonormalBasisDetail.h"

#include "Mathematics/Algebra/Vector3Tools.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Vector3OrthonormalBasis<float>;
    template class Vector3OrthonormalBasis<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Vector3OrthonormalBasisTesting)

void Mathematics::Vector3OrthonormalBasisTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalBasisTest);
}

void Mathematics::Vector3OrthonormalBasisTesting::OrthonormalBasisTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution{ -10.0, 10.0 };
    const uniform_real<float> secondRandomDistribution{ -10.0f, 10.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D firstVector(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             firstRandomDistribution(generator));

        Vector3F secondVector(secondRandomDistribution(generator),
                              secondRandomDistribution(generator),
                              secondRandomDistribution(generator));

        const Vector3OrthonormalBasisD firstOrthonormalBasis(firstVector, false);

        firstVector.Normalize();

        ASSERT_TRUE(Vector3ToolsD::Approximate(firstVector, firstOrthonormalBasis.GetWVector(), 1e-10));

        const Vector3OrthonormalBasisF secondOrthonormalBasis(secondVector, false);

        secondVector.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(secondVector, secondOrthonormalBasis.GetWVector(), 1e-8f));
    }
}
