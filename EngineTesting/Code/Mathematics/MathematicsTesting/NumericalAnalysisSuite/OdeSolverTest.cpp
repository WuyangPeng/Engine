///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:06)

#include "OdeSolverTest.h"
#include "OdeSolverTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/OdeSolverDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Mathematics::OdeSolverTest::OdeSolverTest(int dimension, double step, Function function, const OdeSolverTesting* userData)
    : ParentType{ dimension, step, function, userData }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OdeSolverTest)

Mathematics::OdeSolverTest::Data Mathematics::OdeSolverTest::Update(double tIn, const RealVector& xIn)
{
    CalculateFunctionValue(tIn, xIn);

    const auto tOut = tIn;

    const int dimension0 = GetDimension();
    RealVector xOut(dimension0);

    for (int i = 0; i < dimension0; i++)
    {
        xOut.at(i) = xIn.at(i);
    }

    return { tOut, xOut };
}

Mathematics::OdeSolverTest::RealVector Mathematics::OdeSolverTest::OdeSolverTestFunction(double tIn, const RealVector& xIn, const OdeSolverTesting* odeSolverTest)
{
    if (odeSolverTest != nullptr)
    {
        int dimension = odeSolverTest->GetDimension();

        RealVector out(dimension);

        for (int i = 0; i < dimension; i++)
        {
            out.at(i) = tIn * xIn.at(i) + dimension;
        }

        return out;
    }
    else
    {
        return RealVector{};
    }
}
