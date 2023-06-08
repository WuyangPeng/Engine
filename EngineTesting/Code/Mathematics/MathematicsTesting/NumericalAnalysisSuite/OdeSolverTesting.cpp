///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/03 15:11)

#include "OdeSolverTest.h"
#include "OdeSolverTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/OdeSolverDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::vector;

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

    vector<double> xIn;

    for (int i = 0; i < dimension; ++i)
    {
        xIn.push_back(i);
    }

    auto result = odeSolverTest.Update(tIn, xIn);

    const double tOut = result.t;

    vector<double> xOut = result.x;

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
