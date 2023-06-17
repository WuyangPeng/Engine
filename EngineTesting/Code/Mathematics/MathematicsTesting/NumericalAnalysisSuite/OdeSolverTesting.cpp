///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:06)

#include "OdeSolverTest.h"
#include "OdeSolverTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/NumericalAnalysis/OdeSolverDetail.h"

namespace Mathematics
{
    template class OdeSolver<float, OdeSolverTesting>;
    template class OdeSolver<double, OdeSolverTesting>;
}

Mathematics::OdeSolverTesting::OdeSolverTesting(const OStreamShared& stream)
    : ParentType{ stream }, dimension{ 10 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OdeSolverTesting)

void Mathematics::OdeSolverTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::OdeSolverTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SolverTest);
}

void Mathematics::OdeSolverTesting::SolverTest()
{
    OdeSolverTest odeSolverTest(dimension, 5, OdeSolverTest::OdeSolverTestFunction, nullptr);

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
        xIn.push_back(i);
    }

    auto result = odeSolverTest.Update(tIn, xIn);

    const double tOut = result.t;

    std::vector<double> xOut = result.x;

    ASSERT_APPROXIMATE(tIn, tOut, 1e-10);

    for (int i = 0; i < dimension; ++i)
    {
        ASSERT_APPROXIMATE(xIn.at(i), xOut.at(i), 1e-10);
    }
}

int Mathematics::OdeSolverTesting::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return dimension;
}
