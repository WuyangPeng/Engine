///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/03 14:39)

#include "OdeRungeKutta4Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/OdeRungeKutta4Detail.h"
#include "Mathematics/NumericalAnalysis/OdeSolverDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::ostream;
using std::vector;

namespace Mathematics
{
    template class OdeRungeKutta4<float, OdeRungeKutta4Testing>;
    template class OdeRungeKutta4<double, OdeRungeKutta4Testing>;
}

Mathematics::OdeRungeKutta4Testing::OdeRungeKutta4Testing(const OStreamShared& stream)
    : ParentType(stream), dimension(10)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OdeRungeKutta4Testing)

void Mathematics::OdeRungeKutta4Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::OdeRungeKutta4Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SolverTest);
}

void Mathematics::OdeRungeKutta4Testing::SolverTest()
{
    OdeRungeKutta4<double, OdeRungeKutta4Testing> odeRungeKutta4Test(dimension, 5, OdeRungeKutta4Testing::OdeRungeKutta4Function, nullptr);

    ASSERT_EQUAL(odeRungeKutta4Test.GetDimension(), dimension);

    ASSERT_EQUAL(odeRungeKutta4Test.GetStepSize(), 5);
    ASSERT_EQUAL_NULL_PTR(odeRungeKutta4Test.GetUserData());

    odeRungeKutta4Test.SetStepSize(6);
    ASSERT_EQUAL(odeRungeKutta4Test.GetStepSize(), 6);

    odeRungeKutta4Test.SetUserData(this);
    ASSERT_EQUAL(odeRungeKutta4Test.GetUserData(), this);

    constexpr double tIn = 100;

    vector<double> xIn;

    for (int i = 0; i < dimension; ++i)
    {
        xIn.push_back(i);
    }

    auto data = odeRungeKutta4Test.Update(tIn, xIn);

    const double tOut = data.t;

    vector<double> xOut = data.x;

    vector<double> testXOut(dimension);

    vector<double> firstStepFunctionValue = OdeRungeKutta4Function(tIn, xIn, this);

    for (int i = 0; i < dimension; ++i)
    {
        testXOut.at(i) = xIn.at(i) + firstStepFunctionValue.at(i) * odeRungeKutta4Test.GetStepSize() / 2;
    }

    const double halfT = tIn + odeRungeKutta4Test.GetStepSize() / 2;
    vector<double> secondStepFunctionValue = OdeRungeKutta4Function(halfT, testXOut, this);

    for (int i = 0; i < dimension; ++i)
    {
        testXOut.at(i) = xIn.at(i) + odeRungeKutta4Test.GetStepSize() / 2 * secondStepFunctionValue.at(i);
    }

    vector<double> thirdStepFunctionValue = OdeRungeKutta4Function(halfT, testXOut, this);

    for (int i = 0; i < dimension; ++i)
    {
        testXOut.at(i) = xIn.at(i) + odeRungeKutta4Test.GetStepSize() * thirdStepFunctionValue.at(i);
    }

    const double testTOut = tIn + odeRungeKutta4Test.GetStepSize();
    vector<double> fourthStepFunctionValue = OdeRungeKutta4Function(testTOut, testXOut, this);

    for (int i = 0; i < dimension; ++i)
    {
        testXOut.at(i) = xIn.at(i) + odeRungeKutta4Test.GetStepSize() / 6 * (firstStepFunctionValue.at(i) + 2.0 * (secondStepFunctionValue.at(i) + thirdStepFunctionValue.at(i)) + fourthStepFunctionValue.at(i));
    }

    ASSERT_APPROXIMATE(testTOut, tOut, 1e-10);

    for (int i = 0; i < dimension; ++i)
    {
        ASSERT_APPROXIMATE(testXOut.at(i), xOut.at(i), 1e-10);
    }
}

vector<double> Mathematics::OdeRungeKutta4Testing::OdeRungeKutta4Function(double tIn, const vector<double>& xIn, const OdeRungeKutta4Testing* odeEulerTesting)
{
    if (odeEulerTesting != nullptr)
    {
        int dimension = odeEulerTesting->GetDimension();

        vector<double> out(dimension);

        for (int i = 0; i < dimension; i++)
        {
            out.at(i) = tIn * xIn.at(i) + dimension;
        }

        return out;
    }
    else
    {
        return vector<double>{};
    }
}

int Mathematics::OdeRungeKutta4Testing::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return dimension;
}