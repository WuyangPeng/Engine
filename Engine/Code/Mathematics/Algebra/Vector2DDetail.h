///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/03 19:22)

// 2D向量类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_DETAIL_H

#include "Vector2D.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR2D_ACHIEVE)

    #include "Vector2DAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR2D_ACHIEVE)

template <typename Real>
template <typename RhsType>
Mathematics::Vector2D<Real>::Vector2D(const Vector2D<RhsType>& vector)
    : m_X{ boost::numeric_cast<Real>(vector.GetX()) }, m_Y{ boost::numeric_cast<Real>(vector.GetY()) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector2D<Real>::Vector2D(const Vector3D<RhsType>& vector)
    : m_X{ boost::numeric_cast<Real>(vector.GetX()) }, m_Y{ boost::numeric_cast<Real>(vector.GetY()) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector2D<Real>::Vector2D(const Vector4D<RhsType>& vector)
    : m_X{ boost::numeric_cast<Real>(vector.GetX()) }, m_Y{ boost::numeric_cast<Real>(vector.GetY()) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_DETAIL_H
