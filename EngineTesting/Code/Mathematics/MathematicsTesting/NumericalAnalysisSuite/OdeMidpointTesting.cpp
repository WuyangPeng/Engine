///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:05)

#include "OdeMidpointTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/NumericalAnalysis/OdeMidpointDetail.h"
#include "Mathematics/NumericalAnalysis/OdeSolverDetail.h"

Mathematics::OdeMidpointTesting::OdeMidpointTesting(const OStreamShared& stream)
    : ParentType{ stream }, dimension{ 10 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OdeMidpointTesting)

void Mathematics::OdeMidpointTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::OdeMidpointTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SolverTest);
}

void Mathematics::OdeMidpointTesting::SolverTest()
{
    OdeMidpoint<double, OdeMidpointTesting> odeMidpointTest(dimension, 5, OdeMidpointTesting::OdeMidpointFunction, nullptr);

    ASSERT_EQUAL(odeMidpointTest.GetDimension(), dimension);

    ASSERT_EQUAL(odeMidpointTest.GetStepSize(), 5);
    ASSERT_EQUAL_NULL_PTR(odeMidpointTest.GetUserData());

    odeMidpointTest.SetStepSize(6);
    ASSERT_EQUAL(odeMidpointTest.GetStepSize(), 6);

    odeMidpointTest.SetUserData(this);
    ASSERT_EQUAL(odeMidpointTest.GetUserData(), this);

    constexpr double tIn = 100;

    std::vector<double> xIn;

    for (int i = 0; i < dimension; ++i)
    {
        xIn.push_back(i);
    }

    auto result = odeMidpointTest.Update(tIn, xIn);

    auto tOut = result.t;

    auto xOut = result.x;

    std::vector<double> testXOut(dimension);

    std::vector<double> functionValue = OdeMidpointFunction(tIn, xIn, this);

    for (int i = 0; i < dimension; ++i)
    {
        testXOut.at(i) = xIn.at(i) + functionValue.at(i) * odeMidpointTest.GetStepSize() / 2;
    }

    const double halfT = tIn + odeMidpointTest.GetStepSize() / 2;

    functionValue = OdeMidpointFunction(halfT, testXOut, this);

    for (int i = 0; i < dimension; ++i)
    {
        testXOut.at(i) = xIn.at(i) + functionValue.at(i) * odeMidpointTest.GetStepSize();
    }

    const double testTOut = tIn + odeMidpointTest.GetStepSize();

    ASSERT_APPROXIMATE(testTOut, tOut, 1e-10);

    for (int i = 0; i < dimension; ++i)
    {
        ASSERT_APPROXIMATE(testXOut.at(i), xOut.at(i), 1e-10);
    }
}

std::vector<double> Mathematics::OdeMidpointTesting::OdeMidpointFunction(double tIn, const std::vector<double>& xIn, const OdeMidpointTesting* odeEulerTesting)
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

int Mathematics::OdeMidpointTesting::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return dimension;
}
