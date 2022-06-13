///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 16:35)

#include "ParaboloidFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/ParaboloidFit3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class ParaboloidFit3<float>;
    template class ParaboloidFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, ParaboloidFit3Testing)

void Mathematics::ParaboloidFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::ParaboloidFit3Testing::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const uniform_int<> secondRandomDistribution(10, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
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
