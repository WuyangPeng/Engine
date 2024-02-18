///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:05)

#include "OdeImplicitEulerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/OdeImplicitEulerDetail.h"
#include "Mathematics/NumericalAnalysis/OdeSolverDetail.h"

namespace Mathematics
{
    template class OdeImplicitEuler<float, OdeImplicitEulerTesting>;
    template class OdeImplicitEuler<double, OdeImplicitEulerTesting>;
}

Mathematics::OdeImplicitEulerTesting::OdeImplicitEulerTesting(const OStreamShared& stream)
    : ParentType{ stream }, dimension{ 10 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OdeImplicitEulerTesting)

void Mathematics::OdeImplicitEulerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::OdeImplicitEulerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SolverTest);
}

void Mathematics::OdeImplicitEulerTesting::SolverTest()
{
    OdeImplicitEuler<double, OdeImplicitEulerTesting> odeImplicitEulerTest(dimension, 5, OdeImplicitEulerTesting::OdeImplicitEulerFunction, OdeImplicitEulerTesting::OdeImplicitEulerDerivativeFunction, nullptr);

    ASSERT_EQUAL(odeImplicitEulerTest.GetDimension(), dimension);

    ASSERT_EQUAL(odeImplicitEulerTest.GetStepSize(), 5);
    ASSERT_EQUAL_NULL_PTR(odeImplicitEulerTest.GetUserData());

    odeImplicitEulerTest.SetStepSize(6);
    ASSERT_EQUAL(odeImplicitEulerTest.GetStepSize(), 6);

    odeImplicitEulerTest.SetUserData(this);
    ASSERT_EQUAL(odeImplicitEulerTest.GetUserData(), this);

    constexpr double tIn = 100;

    std::vector<double> xIn;

    for (int i = 0; i < dimension; ++i)
    {
        xIn.emplace_back(i);
    }

    auto data = odeImplicitEulerTest.Update(tIn, xIn);

    const double tOut = data.t;

    std::vector<double> xOut = data.x;

    std::vector<double> testXOut(dimension);

    std::vector<double> functionValue = OdeImplicitEulerFunction(tIn, xIn, this);

    VariableMatrixD derivativeFunctionMatrix = OdeImplicitEulerDerivativeFunction(tIn, xIn, this);
    VariableMatrixD identity(dimension, dimension);
    identity.MakeIdentity();
    VariableMatrixD derivative = identity - odeImplicitEulerTest.GetStepSize() * derivativeFunctionMatrix;

    VariableMatrixD derivativeInverse = LinearSystemD().Inverse(derivative);

    VariableLengthVectorD variableLengthVector(functionValue);
    functionValue = (derivativeInverse * variableLengthVector).GetContainer();

    for (int i = 0; i < dimension; ++i)
    {
        testXOut.at(i) = xIn.at(i) + functionValue.at(i) * odeImplicitEulerTest.GetStepSize();
    }

    const double testTOut = tIn + odeImplicitEulerTest.GetStepSize();

    ASSERT_APPROXIMATE(testTOut, tOut, 1e-10);

    for (int i = 0; i < dimension; ++i)
    {
        ASSERT_APPROXIMATE(testXOut.at(i), xOut.at(i), 1e-10);
    }
}

int Mathematics::OdeImplicitEulerTesting::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return dimension;
}

std::vector<double> Mathematics::OdeImplicitEulerTesting::OdeImplicitEulerFunction(double tIn, const std::vector<double>& xIn, const OdeImplicitEulerTesting* odeEulerTesting)
{
    if (odeEulerTesting != nullptr)
    {
        int dimension = odeEulerTesting->GetDimension();

        std::vector<double> out(dimension);

        for (int i = 0; i < dimension; i++)
        {
            out.at(i) = tIn * xIn.at(i) + dimension;
        }

        return out;
    }
    else
    {
        return std::vector<double>{};
    }
}

Mathematics::VariableMatrixD Mathematics::OdeImplicitEulerTesting::OdeImplicitEulerDerivativeFunction(double tIn, const std::vector<double>& xIn, const OdeImplicitEulerTesting* odeEulerTesting)
{
    if (odeEulerTesting == nullptr)
    {
        return VariableMatrixD{};
    }

    int dimension = odeEulerTesting->GetDimension();

    VariableMatrixD dervative(dimension, dimension);

    for (int i = 0; i < dimension; i++)
    {
        dervative(i, i) = tIn * xIn.at(i) + dimension;
    }

    return dervative;
}
