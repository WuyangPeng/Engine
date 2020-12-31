///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/04 15:39)

// 4D向量类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_4D_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_4D_DETAIL_H

#include "Vector4D.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR4D_ACHIEVE)

    #include "Vector4DAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR4D_ACHIEVE)

template <typename Real>
template <typename RhsType>
Mathematics::Vector4D<Real>::Vector4D(const Vector2D<RhsType>& vector)
    : m_X{ boost::numeric_cast<Real>(vector.GetX()) }, m_Y{ boost::numeric_cast<Real>(vector.GetY()) }, m_Z{}, m_W{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector4D<Real>::Vector4D(const Vector3D<RhsType>& vector)
    : m_X{ boost::numeric_cast<Real>(vector.GetX()) }, m_Y{ boost::numeric_cast<Real>(vector.GetY()) }, m_Z{ boost::numeric_cast<Real>(vector.GetZ()) }, m_W{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector4D<Real>::Vector4D(const Vector4D<RhsType>& vector)
    : m_X{ boost::numeric_cast<Real>(vector.GetX()) }, m_Y{ boost::numeric_cast<Real>(vector.GetY()) }, m_Z{ boost::numeric_cast<Real>(vector.GetZ()) }, m_W{ boost::numeric_cast<Real>(vector.GetW()) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_4D_DETAIL_H