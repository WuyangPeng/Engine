///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 18:26)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_ELLIPSE3_ACHIEVE_H

#include "Ellipse3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Ellipse3<Real>::Ellipse3(const Vector3D& center, const Vector3D& normal, const Vector3D& major, const Vector3D& minor,
                                      Real majorLength, Real minorLength, const Real epsilon) noexcept
    : m_Center{ center }, m_Normal{ normal }, m_Major{ major }, m_Minor{ minor },
      m_MajorLength{ majorLength }, m_MinorLength{ minorLength }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ellipse3<Real>::IsValid() const noexcept
{
    try
    {
        if (m_Normal.IsNormalize(m_Epsilon) && m_Major.IsNormalize(m_Epsilon) && m_Minor.IsNormalize(m_Epsilon) &&
            Math::GetValue(0) <= m_MajorLength && Math::GetValue(0) <= m_MinorLength)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Ellipse3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Ellipse3<Real>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Normal;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Ellipse3<Real>::GetMajor() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Major;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Ellipse3<Real>::GetMinor() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Minor;
}

template <typename Real>
Real Mathematics::Ellipse3<Real>::GetMajorLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MajorLength;
}

template <typename Real>
Real Mathematics::Ellipse3<Real>::GetMinorLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MinorLength;
}

#endif  // MATHEMATICS_OBJECTS3D_ELLIPSE3_ACHIEVE_H