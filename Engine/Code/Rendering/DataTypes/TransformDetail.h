//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/09/06 10:46)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_DETAIL_H
#define RENDERING_DATA_TYPES_TRANSFORM_DETAIL_H

#include "Transform.h"

#if !defined(RENDERING_EXPORT_TEMPLATE) || defined(RENDERING_INCLUDED_TRANSFORM_ACHIEVE)

    #include "TransformAchieve.h"

#endif  // !defined(RENDERING_EXPORT_TEMPLATE) || defined(RENDERING_INCLUDED_TRANSFORM_ACHIEVE)

template <typename Real>
const Rendering::Transform<Real> Rendering::operator*(const Transform<Real>& lhs, const Transform<Real>& rhs)
{
    Transform<Real> result{ lhs };

    result *= rhs;

    return result;
}

template <typename Real>
bool Rendering::Approximate(const Transform<Real>& lhs, const Transform<Real>& rhs, const Real epsilon)
{
    const auto lhsIsIdentity = lhs.IsIdentity();
    const auto lhsIsRotationOrScaleMatrix = lhs.IsRotationOrScaleMatrix();
    const auto lhsIsUniformScale = lhs.IsUniformScale();

    const auto rhsIsIdentity = rhs.IsIdentity();
    const auto rhsIsRotationOrScaleMatrix = rhs.IsRotationOrScaleMatrix();
    const auto rhsIsUniformScale = rhs.IsUniformScale();

    if (lhsIsIdentity != rhsIsIdentity || lhsIsRotationOrScaleMatrix != rhsIsRotationOrScaleMatrix || lhsIsUniformScale != rhsIsUniformScale)
    {
        return false;
    }
    else if (lhsIsIdentity && rhsIsIdentity)
    {
        return true;
    }
    else if (lhsIsRotationOrScaleMatrix && rhsIsRotationOrScaleMatrix)
    {
        if (lhsIsUniformScale && rhsIsUniformScale)
        {
            if (Approximate(lhs.GetRotate(), rhs.GetRotate(), epsilon) && Mathematics::Math<Real>::Approximate(lhs.GetUniformScale(), rhs.GetUniformScale(), epsilon) &&
                Approximate(lhs.GetTranslate(), rhs.GetTranslate(), epsilon))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (Approximate(lhs.GetRotate(), rhs.GetRotate(), epsilon) && Approximate(lhs.GetScale(), rhs.GetScale(), epsilon) && Approximate(lhs.GetTranslate(), rhs.GetTranslate(), epsilon))
                return true;
            else
                return false;
        }
    }
    else
    {
        if (Approximate(lhs.GetMatrix(), rhs.GetMatrix(), epsilon) && Approximate(lhs.GetTranslate(), rhs.GetTranslate(), epsilon))
            return true;
        else
            return false;
    }
}

template <typename Real>
std::ostream& Rendering ::operator<<(std::ostream& out, const Transform<Real>& transform)
{
    if (transform.IsRotationOrScaleMatrix())
    {
        out << "Rotate:" << transform.GetRotate() << "　";
        out << "Translate:" << transform.GetTranslate() << "　";
        out << "Scale:" << transform.GetScale() << "　";
    }
    else
    {
        out << "Rotate:" << transform.GetMatrix() << "　";
        out << "Translate:" << transform.GetTranslate() << "　";
    }

    return out;
}

#endif  // RENDERING_DATA_TYPES_TRANSFORM_DETAIL_H
