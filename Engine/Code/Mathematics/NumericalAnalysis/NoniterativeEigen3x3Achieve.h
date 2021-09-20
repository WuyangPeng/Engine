///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/26 17:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_ACHIEVE_H

#include "NoniterativeEigen3x3.h"
#include "Detail/NoniterativeEigen3x3ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::NoniterativeEigen3x3<Real>::NoniterativeEigen3x3(const Matrix3& matrix)
    : impl{  matrix  }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::NoniterativeEigen3x3<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::NoniterativeEigen3x3<Real>::GetEigenvalue(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetEigenvalue(index);
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::NoniterativeEigen3x3<Real>::GetEigenvector(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return impl->GetEigenvector(index);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_ACHIEVE_H
