///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 09:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_DETAIL_H

#include "BrentsMethod.h"
#include "BrentsMethodCalculateDetail.h"
#include "BrentsMethodRootDetail.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename UserDataType>
Mathematics::BrentsMethod<Real, UserDataType>::BrentsMethod(Function function,
                                                            int maxIterations,
                                                            Real negativeFTolerance,
                                                            Real positiveFTolerance,
                                                            Real stepXTolerance,
                                                            Real convXTolerance,
                                                            const UserDataType* userData) noexcept
    : function{ function },
      maxIterations{ maxIterations },
      negativeFTolerance{ negativeFTolerance },
      positiveFTolerance{ positiveFTolerance },
      stepXTolerance{ stepXTolerance },
      convXTolerance{ convXTolerance },
      userData{ userData }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
bool Mathematics::BrentsMethod<Real, UserDataType>::IsValid() const noexcept
{
    if (function != nullptr &&
        1 <= maxIterations &&
        negativeFTolerance <= MathType::GetValue(0) &&
        MathType::GetValue(0) <= positiveFTolerance &&
        MathType::GetValue(0) <= stepXTolerance &&
        MathType::GetValue(0) <= convXTolerance)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetFunction(Function newFunction)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(newFunction != nullptr, "无效 function。\n");

    function = newFunction;
}

template <typename Real, typename UserDataType>
typename Mathematics::BrentsMethod<Real, UserDataType>::Function Mathematics::BrentsMethod<Real, UserDataType>::GetFunction() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return function;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetMaxIterations(int newMaxIterations) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(1 <= newMaxIterations, "无效 maxIterations。\n");

    maxIterations = newMaxIterations;
}

template <typename Real, typename UserDataType>
int Mathematics::BrentsMethod<Real, UserDataType>::GetMaxIterations() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return maxIterations;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetNegativeFTolerance(Real newNegativeFTolerance) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(newNegativeFTolerance <= MathType::GetValue(0), "无效 negativeFTolerance。\n");

    negativeFTolerance = newNegativeFTolerance;
}

template <typename Real, typename UserDataType>
Real Mathematics::BrentsMethod<Real, UserDataType>::GetNegativeFTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return negativeFTolerance;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetPositiveFTolerance(Real newPositiveFTolerance) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(MathType::GetValue(0) <= positiveFTolerance, "无效 positiveFTolerance。\n");

    positiveFTolerance = newPositiveFTolerance;
}

template <typename Real, typename UserDataType>
Real Mathematics::BrentsMethod<Real, UserDataType>::GetPositiveFTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return positiveFTolerance;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetStepXTolerance(Real newStepXTolerance) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(MathType::GetValue(0) <= newStepXTolerance, "无效 stepXTolerance。\n");

    stepXTolerance = newStepXTolerance;
}

template <typename Real, typename UserDataType>
Real Mathematics::BrentsMethod<Real, UserDataType>::GetStepXTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return stepXTolerance;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetConvXTolerance(Real newConvXTolerance) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(MathType::GetValue(0) <= newConvXTolerance, "无效 convXTolerance。\n");

    convXTolerance = newConvXTolerance;
}

template <typename Real, typename UserDataType>
Real Mathematics::BrentsMethod<Real, UserDataType>::GetConvXTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return convXTolerance;
}

template <typename Real, typename UserDataType>
void Mathematics::BrentsMethod<Real, UserDataType>::SetUserData(const UserDataType* newUserData) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    userData = newUserData;
}

template <typename Real, typename UserDataType>
const UserDataType* Mathematics::BrentsMethod<Real, UserDataType>::GetUserData() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return userData;
}

template <typename Real, typename UserDataType>
typename Mathematics::BrentsMethod<Real, UserDataType>::BrentsMethodRootType Mathematics::BrentsMethod<Real, UserDataType>::GetRoot(Real begin, Real end)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(begin <= end, "间隔是无效在GetRoot。\n");

    BrentsMethodCalculate<Real, UserDataType> calculate{ *this, begin, end };

    return calculate.GetRoot();
}

template <typename Real, typename UserDataType>
Real Mathematics::BrentsMethod<Real, UserDataType>::GetFunctionValue(Real value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoreTools::DisableNoexcept();

    return function(value, userData);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_DETAIL_H
