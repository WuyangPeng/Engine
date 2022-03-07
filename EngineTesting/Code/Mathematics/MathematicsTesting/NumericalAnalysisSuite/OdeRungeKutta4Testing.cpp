// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:17)

#include "OdeRungeKutta4Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/OdeRungeKutta4Detail.h"
#include "Mathematics/NumericalAnalysis/OdeSolverDetail.h"

using std::ostream;
using std::vector;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26481)
namespace Mathematics
{
    template class OdeRungeKutta4<float, OdeRungeKutta4Testing>;
    template class OdeRungeKutta4<double, OdeRungeKutta4Testing>;
}

Mathematics::OdeRungeKutta4Testing ::OdeRungeKutta4Testing(const OStreamShared& osPtr)
    : ParentType(osPtr), m_Dimension(10)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OdeRungeKutta4Testing)

void Mathematics::OdeRungeKutta4Testing ::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::OdeRungeKutta4Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SolverTest);
}

void Mathematics::OdeRungeKutta4Testing ::SolverTest()
{
    OdeRungeKutta4<double, OdeRungeKutta4Testing> odeRungeKutta4Test(m_Dimension, 5, OdeRungeKutta4Testing::OdeRungeKutta4Function, nullptr);

    ASSERT_EQUAL(odeRungeKutta4Test.GetDimension(), m_Dimension);

    ASSERT_EQUAL(odeRungeKutta4Test.GetStepSize(), 5);
    ASSERT_EQUAL_NULL_PTR(odeRungeKutta4Test.GetUserData());

    odeRungeKutta4Test.SetStepSize(6);
    ASSERT_EQUAL(odeRungeKutta4Test.GetStepSize(), 6);

    odeRungeKutta4Test.SetUserData(this);
    ASSERT_EQUAL(odeRungeKutta4Test.GetUserData(), this);

    double tIn = 100;

    vector<double> xIn;

    for (int i = 0; i < m_Dimension; ++i)
    {
        xIn.push_back(i);
    }

    auto data = odeRungeKutta4Test.Update(tIn, xIn);

    double tOut = data.t;

    vector<double> xOut = data.x;

    vector<double> testXOut(m_Dimension);

    vector<double> firstStepFunctionValue = OdeRungeKutta4Function(tIn, xIn, this);

    int dimension = GetDimension();

    for (int i = 0; i < dimension; ++i)
    {
        testXOut[i] = xIn[i] + firstStepFunctionValue[i] * odeRungeKutta4Test.GetStepSize() / 2;
    }

    double halfT = tIn + odeRungeKutta4Test.GetStepSize() / 2;
    vector<double> secondStepFunctionValue = OdeRungeKutta4Function(halfT, testXOut, this);

    for (int i = 0; i < dimension; ++i)
    {
        testXOut[i] = xIn[i] + odeRungeKutta4Test.GetStepSize() / 2 * secondStepFunctionValue[i];
    }

    vector<double> thirdStepFunctionValue = OdeRungeKutta4Function(halfT, testXOut, this);

    for (int i = 0; i < dimension; ++i)
    {
        testXOut[i] = xIn[i] + odeRungeKutta4Test.GetStepSize() * thirdStepFunctionValue[i];
    }

    double testTOut = tIn + odeRungeKutta4Test.GetStepSize();
    vector<double> fourthStepFunctionValue = OdeRungeKutta4Function(testTOut, testXOut, this);

    for (int i = 0; i < dimension; ++i)
    {
        testXOut[i] = xIn[i] + odeRungeKutta4Test.GetStepSize() / 6 * (firstStepFunctionValue[i] + 2.0 * (secondStepFunctionValue[i] + thirdStepFunctionValue[i]) + fourthStepFunctionValue[i]);
    }

    ASSERT_APPROXIMATE(testTOut, tOut, 1e-10);

    for (int i = 0; i < m_Dimension; ++i)
    {
        ASSERT_APPROXIMATE(testXOut[i], xOut[i], 1e-10);
    }
}

const vector<double> Mathematics::OdeRungeKutta4Testing ::OdeRungeKutta4Function(double tIn, const vector<double>& xIn, const OdeRungeKutta4Testing* odeEulerTesting)
{
    int dimension = odeEulerTesting->GetDimension();

    vector<double> out(dimension);

    for (int i = 0; i < dimension; i++)
    {
        out[i] = tIn * xIn[i] + dimension;
    }

    return out;
}

int Mathematics::OdeRungeKutta4Testing ::GetDimension() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Dimension;
}