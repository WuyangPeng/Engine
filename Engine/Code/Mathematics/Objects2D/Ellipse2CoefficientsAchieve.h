///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 10:55)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_ACHIEVE_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_ACHIEVE_H

#include "Ellipse2Coefficients.h"
#include "Detail/Ellipse2CoefficientsImplDetail.h" 
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h" 

template <typename Real>
Mathematics::Ellipse2Coefficients<Real>::Ellipse2Coefficients(const Matrix2& matrix, const Vector2D& vector, Real constants)
    : impl{  matrix, vector, constants  }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipse2Coefficients<Real>::Ellipse2Coefficients(const CoefficientsType& coefficient)
    : impl{ coefficient  }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ellipse2Coefficients<Real>::IsValid() const noexcept
{
  
        return true;
    
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Ellipse2Coefficients<Real>::GetMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetMatrix();
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Ellipse2Coefficients<Real>::GetVector() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetVector();
}

template <typename Real>
Real Mathematics::Ellipse2Coefficients<Real>::GetConstants() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetConstants();
}

template <typename Real>
typename const Mathematics::Ellipse2Coefficients<Real>::CoefficientsType Mathematics::Ellipse2Coefficients<Real>::GetCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetCoefficients();
}

#endif  // MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_ACHIEVE_H
