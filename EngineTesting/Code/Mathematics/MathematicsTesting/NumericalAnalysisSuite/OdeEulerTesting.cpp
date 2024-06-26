///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:04)

#include "OdeEulerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/NumericalAnalysis/OdeEulerDetail.h"

namespace Mathematics
{
    template class OdeEuler<float, OdeEulerTesting>;
    template class OdeEuler<double, OdeEulerTesting>;
}

Mathematics::OdeEulerTesting::OdeEulerTesting(const OStreamShared& stream)
    : ParentType{ stream }, dimension{ 10 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OdeEulerTesting)

void Mathematics::OdeEulerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::OdeEulerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SolverTest);
}

void Mathematics::OdeEulerTesting::SolverTest()
{
    OdeEuler<double, OdeEulerTesting> odeSolverTest(dimension, 5, OdeEulerTesting::OdeEulerFunction, nullptr);

    ASSERT_EQUAL(odeSolverTest.GetDimension(), dimension);

    ASSERT_EQUAL(odeSolverTest.GetStepSize(), 5);
    ASSERT_EQUAL_NULL_PTR(odeSolverTest.GetUserData());

    odeSolverTest.SetStepSize(6);
    ASSERT_EQUAL(odeSolverTest.GetStepSize(), 6);

    odeSolverTest.SetUserData(this);
    ASSERT_EQUAL(odeSolverTest.GetUserData(), this);

    constexpr double tIn = 100;

    std::vector<double> xIn;

    for (int i = 0; i < dimension; ++i)
    {
        xIn.emplace_back(i);
    }

    auto result = odeSolverTest.Update(tIn, xIn);

    auto tOut = result.t;

    auto xOut = result.x;

    std::vector<double> testXOut(dimension);

    std::vector<double> functionValue = OdeEulerFunction(tIn, xIn, this);

    for (int i = 0; i < dimension; ++i)
    {
        testXOut.at(i) = xIn.at(i) + functionValue.at(i) * odeSolverTest.GetStepSize();
    }

    const double testTOut = tIn + odeSolverTest.GetStepSize();

    ASSERT_APPROXIMATE(testTOut, tOut, 1e-10);

    for (int i = 0; i < dimension; ++i)
    {
        ASSERT_APPROXIMATE(testXOut.at(i), xOut.at(i), 1e-10);
    }
}

std::vector<double> Mathematics::OdeEulerTesting::OdeEulerFunction(double tIn, const std::vector<double>& xIn, const OdeEulerTesting* odeEulerTesting)
{
    if (odeEulerTesting != nullptr)
    {
        auto dimension = odeEulerTesting->GetDimension();

        std::vector<double> out(dimension);

        for (auto i = 0; i < dimension; i++)
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

int Mathematics::OdeEulerTesting::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return dimension;
}
