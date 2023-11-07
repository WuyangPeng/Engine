///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:18)

#include "ParaboloidFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/ParaboloidFit3Detail.h"

#include <random>

namespace Mathematics
{
    template class ParaboloidFit3<float>;
    template class ParaboloidFit3<double>;
}

Mathematics::ParaboloidFit3Testing::ParaboloidFit3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, ParaboloidFit3Testing)

void Mathematics::ParaboloidFit3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::ParaboloidFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::ParaboloidFit3Testing::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(10, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const int size = randomDistribution1(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector3D(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator)));
        }

        ParaboloidFit3D paraboloidFit3(vertices);

        ASSERT_TRUE(paraboloidFit3.GetIsFitSuccess());

        VariableLengthVectorD variableLengthVector = paraboloidFit3.GetCoeff();

        for (int i = 0; i < size; ++i)
        {
            const double value = variableLengthVector[0] * vertices.at(i).GetX() * vertices.at(i).GetX() +
                                 variableLengthVector[1] * vertices.at(i).GetX() * vertices.at(i).GetY() +
                                 variableLengthVector[2] * vertices.at(i).GetY() * vertices.at(i).GetY() +
                                 variableLengthVector[3] * vertices.at(i).GetX() +
                                 variableLengthVector[4] * vertices.at(i).GetY() + variableLengthVector[5];

            ASSERT_TRUE(MathD::FAbs(value - vertices.at(i).GetZ()) <= 200.0f);
        }
    }
}
