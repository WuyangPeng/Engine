///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 17:10)

#ifndef MATHEMATICS_OBJECTS_3D_ELLIPSE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS_3D_ELLIPSE3_ACHIEVE_H

#include "Ellipse3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Ellipse3<Real>::Ellipse3(const Vector3& center,
                                      const Vector3& normal,
                                      const Vector3& major,
                                      const Vector3& minor,
                                      Real majorLength,
                                      Real minorLength,
                                      const Real epsilon) noexcept
    : center{ center },
      normal{ normal },
      major{ major },
      minor{ minor },
      majorLength{ majorLength },
      minorLength{ minorLength },
      epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Ellipse3<Real>::IsValid() const noexcept
{
    try
    {
        if (normal.IsNormalize(epsilon) &&
            major.IsNormalize(epsilon) &&
            minor.IsNormalize(epsilon) &&
            Math::GetValue(0) <= majorLength &&
            Math::GetValue(0) <= minorLength)
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
Mathematics::Vector3<Real> Mathematics::Ellipse3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Ellipse3<Real>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return normal;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Ellipse3<Real>::GetMajor() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return major;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Ellipse3<Real>::GetMinor() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return minor;
}

template <typename Real>
Real Mathematics::Ellipse3<Real>::GetMajorLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return majorLength;
}

template <typename Real>
Real Mathematics::Ellipse3<Real>::GetMinorLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return minorLength;
}

#endif  // MATHEMATICS_OBJECTS_3D_ELLIPSE3_ACHIEVE_H