///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:19)

#include "QuadraticFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Approximation/QuadraticFit3Detail.h"

#include <random>

namespace Mathematics
{
    template class QuadraticFit3<float>;
    template class QuadraticFit3<double>;
}

Mathematics::QuadraticFit3Testing::QuadraticFit3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, QuadraticFit3Testing)

void Mathematics::QuadraticFit3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::QuadraticFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::QuadraticFit3Testing::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(3, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const int size = randomDistribution1(generator);

        for (int k = 0; k < size; ++k)
        {
            vertices.push_back(Vector3D(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator)));
        }

        QuadraticFit3D quadraticFit2(vertices);

        VariableLengthVectorD coeff = quadraticFit2.GetCoeff();
        const double eigenValue = quadraticFit2.GetEigenValue();

        ASSERT_TRUE(0.0 <= eigenValue && eigenValue <= 1.0);

        ASSERT_TRUE(MathD::FAbs(coeff.Length() - 1.0) <= MathD::GetZeroTolerance());

        for (int i = 0; i < size; ++i)
        {
            const double value = coeff[0] + coeff[1] * vertices.at(i).GetX() +
                                 coeff[2] * vertices.at(i).GetY() +
                                 coeff[3] * vertices.at(i).GetZ() +
                                 coeff[4] * vertices.at(i).GetX() * vertices.at(i).GetX() +
                                 coeff[5] * vertices.at(i).GetY() * vertices.at(i).GetY() +
                                 coeff[6] * vertices.at(i).GetZ() * vertices.at(i).GetZ() +
                                 coeff[7] * vertices.at(i).GetX() * vertices.at(i).GetY() +
                                 coeff[8] * vertices.at(i).GetX() * vertices.at(i).GetZ() +
                                 coeff[9] * vertices.at(i).GetY() * vertices.at(i).GetZ();

            if (eigenValue <= MathD::GetZeroTolerance())
            {
                ASSERT_APPROXIMATE(value, 0.0, 1e-7);
            }
            else if (eigenValue <= 0.6)
            {
                ASSERT_TRUE(MathD::FAbs(value) <= 1.4);
            }
            else if (eigenValue <= 1.0)
            {
                ASSERT_TRUE(MathD::FAbs(value) <= 1.5);
            }
        }
    }
}
