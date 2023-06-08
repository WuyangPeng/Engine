///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 16:41)

#include "PolynomialFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/PolynomialDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/PolynomialFit2Detail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class PolynomialFit2<float>;
    template class PolynomialFit2<double>;
}

Mathematics::PolynomialFit2Testing::PolynomialFit2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, PolynomialFit2Testing)

void Mathematics::PolynomialFit2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::PolynomialFit2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit2Testing::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-50.0, 50.0);
    const uniform_int<> secondRandomDistribution(10, 50);
    const uniform_int<> thirdRandomDistribution(3, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<double> x;
        std::vector<double> w;
        const int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            x.push_back(firstRandomDistribution(generator));
            w.push_back(firstRandomDistribution(generator));
        }

        PolynomialFit2D polynomialFit2(x, w, thirdRandomDistribution(generator));

        if (polynomialFit2.IsSolveSucceed())
        {
            PolynomialD polynomial = polynomialFit2.GetCoeff();

            for (int i = 0; i < size; ++i)
            {
                const double value = polynomial(x.at(i)) - w.at(i);

                ASSERT_LESS_EQUAL(MathD::FAbs(value), 75.0);
            }
        }
    }
}
