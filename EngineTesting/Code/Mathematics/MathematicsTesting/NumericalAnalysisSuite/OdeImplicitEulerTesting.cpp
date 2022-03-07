// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:15)

#include "OdeImplicitEulerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/OdeImplicitEulerDetail.h"
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
    template class OdeImplicitEuler<float, OdeImplicitEulerTesting>;
    template class OdeImplicitEuler<double, OdeImplicitEulerTesting>;
}

Mathematics::OdeImplicitEulerTesting ::OdeImplicitEulerTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_Dimension{ 10 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OdeImplicitEulerTesting)

void Mathematics::OdeImplicitEulerTesting ::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::OdeImplicitEulerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SolverTest);
}

void Mathematics::OdeImplicitEulerTesting ::SolverTest()
{
    OdeImplicitEuler<double, OdeImplicitEulerTesting> odeImplicitEulerTest(m_Dimension, 5, OdeImplicitEulerTesting::OdeImplicitEulerFunction, OdeImplicitEulerTesting::OdeImplicitEulerDerivativeFunction, nullptr);

    ASSERT_EQUAL(odeImplicitEulerTest.GetDimension(), m_Dimension);

    ASSERT_EQUAL(odeImplicitEulerTest.GetStepSize(), 5);
    ASSERT_EQUAL_NULL_PTR(odeImplicitEulerTest.GetUserData());

    odeImplicitEulerTest.SetStepSize(6);
    ASSERT_EQUAL(odeImplicitEulerTest.GetStepSize(), 6);

    odeImplicitEulerTest.SetUserData(this);
    ASSERT_EQUAL(odeImplicitEulerTest.GetUserData(), this);

    double tIn = 100;

    vector<double> xIn;

    for (int i = 0; i < m_Dimension; ++i)
    {
        xIn.push_back(i);
    }

    auto data = odeImplicitEulerTest.Update(tIn, xIn);

    double tOut = data.t;

    vector<double> xOut = data.x;

    vector<double> testXOut(m_Dimension);

    vector<double> functionValue = OdeImplicitEulerFunction(tIn, xIn, this);

    VariableMatrixD derivativeFunctionMatrix = OdeImplicitEulerDerivativeFunction(tIn, xIn, this);
    VariableMatrixD identity(m_Dimension, m_Dimension);
    identity.SetIdentity();
    VariableMatrixD derivative = identity - odeImplicitEulerTest.GetStepSize() * derivativeFunctionMatrix;

    VariableMatrixD derivativeInverse = LinearSystemD().Inverse(derivative);

    VariableLengthVectorD variableLengthVector(functionValue);
    functionValue = (derivativeInverse * variableLengthVector).GetContainer();

    for (int i = 0; i < m_Dimension; ++i)
    {
        testXOut[i] = xIn[i] + functionValue[i] * odeImplicitEulerTest.GetStepSize();
    }

    double testTOut = tIn + odeImplicitEulerTest.GetStepSize();

    ASSERT_APPROXIMATE(testTOut, tOut, 1e-10);

    for (int i = 0; i < m_Dimension; ++i)
    {
        ASSERT_APPROXIMATE(testXOut[i], xOut[i], 1e-10);
    }
}

int Mathematics::OdeImplicitEulerTesting ::GetDimension() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Dimension;
}

const vector<double> Mathematics::OdeImplicitEulerTesting ::OdeImplicitEulerFunction(double tIn, const vector<double>& xIn, const OdeImplicitEulerTesting* odeEulerTesting)
{
    int dimension = odeEulerTesting->GetDimension();

    vector<double> out(dimension);

    for (int i = 0; i < dimension; i++)
    {
        out[i] = tIn * xIn[i] + dimension;
    }

    return out;
}

const Mathematics::VariableMatrixD Mathematics::OdeImplicitEulerTesting ::OdeImplicitEulerDerivativeFunction(double tIn, const vector<double>& xIn, const OdeImplicitEulerTesting* odeEulerTesting)
{
    int dimension = odeEulerTesting->GetDimension();

    VariableMatrixD dervative(dimension, dimension);

    for (int i = 0; i < dimension; i++)
    {
        dervative(i, i) = tIn * xIn[i] + dimension;
    }

    return dervative;
}
