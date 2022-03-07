// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 14:34)

#include "QuadraticFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Approximation/QuadraticFit3Detail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class QuadraticFit3<float>;
    template class QuadraticFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QuadraticFit3Testing)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
void Mathematics::QuadraticFit3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::QuadraticFit3Testing ::FitTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(3, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        int size = secondRandomDistribution(generator);

        for (int k = 0; k < size; ++k)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        QuadraticFit3D quadraticFit2(vertices);

        VariableLengthVectorD coeff = quadraticFit2.GetCoeff();
        double eigenValue = quadraticFit2.GetEigenValue();

        ASSERT_TRUE(0.0 <= eigenValue && eigenValue <= 1.0);

        ASSERT_TRUE(MathD::FAbs(coeff.Length() - 1.0) <= MathD::GetZeroTolerance());

        for (int i = 0; i < size; ++i)
        {
            double value = coeff[0] + coeff[1] * vertices[i].GetX() +
                           coeff[2] * vertices[i].GetY() +
                           coeff[3] * vertices[i].GetZ() +
                           coeff[4] * vertices[i].GetX() * vertices[i].GetX() +
                           coeff[5] * vertices[i].GetY() * vertices[i].GetY() +
                           coeff[6] * vertices[i].GetZ() * vertices[i].GetZ() +
                           coeff[7] * vertices[i].GetX() * vertices[i].GetY() +
                           coeff[8] * vertices[i].GetX() * vertices[i].GetZ() +
                           coeff[9] * vertices[i].GetY() * vertices[i].GetZ();

            if (eigenValue <= MathD::GetZeroTolerance())
            {
                ASSERT_APPROXIMATE(value, 0.0, 1e-8);
            }
            else if (eigenValue <= 0.6)
            {
                ASSERT_TRUE(MathD::FAbs(value) <= 1.2);
            }
            else if (eigenValue <= 1.0)
            {
                ASSERT_TRUE(MathD::FAbs(value) <= 1.5);
            }
        }
    }
}
