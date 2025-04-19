///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:51)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_ELLIPSOID_GEODESIC_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_ELLIPSOID_GEODESIC_DETAIL_H

#include "EllipsoidGeodesic.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::EllipsoidGeodesic<Real>::EllipsoidGeodesic(Real xExtent, Real yExtent, Real zExtent)
    : ParentType{ 2 }, xExtent{ xExtent }, yExtent{ yExtent }, zExtent{ zExtent }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::EllipsoidGeodesic<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::EllipsoidGeodesic<Real>::ComputePosition(const VariableLengthVector<Real>& point)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto cos0 = MathType::Cos(point[0]);
    auto sin0 = MathType::Sin(point[0]);
    auto cos1 = MathType::Cos(point[1]);
    auto sin1 = MathType::Sin(point[1]);

    return Vector3<Real>{ xExtent * cos0 * sin1, yExtent * sin0 * sin1, zExtent * cos1 };
}

template <typename Real>
void Mathematics::EllipsoidGeodesic<Real>::ComputeMetric(const VariableLengthVector<Real>& point)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto cos0 = MathType::Cos(point[0]);
    auto sin0 = MathType::Sin(point[0]);
    auto cos1 = MathType::Cos(point[1]);
    auto sin1 = MathType::Sin(point[1]);

    const Vector3<Real> der0{ -xExtent * sin0 * sin1, yExtent * cos0 * sin1, MathType::GetValue(0) };
    const Vector3<Real> der1{ xExtent * cos0 * cos1, yExtent * sin0 * cos1, -zExtent * sin1 };

    this->SetMetric(0, 0, Vector3Tools<Real>::DotProduct(der0, der0));
    this->SetMetric(0, 1, Vector3Tools<Real>::DotProduct(der0, der1));
    this->SetMetric(1, 0, this->GetMetric(0, 1));
    this->SetMetric(1, 1, Vector3Tools<Real>::DotProduct(der1, der1));
}

template <typename Real>
void Mathematics::EllipsoidGeodesic<Real>::ComputeChristoffel1(const VariableLengthVector<Real>& point)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto cos0 = MathType::Cos(point[0]);
    auto sin0 = MathType::Sin(point[0]);
    auto cos1 = MathType::Cos(point[1]);
    auto sin1 = MathType::Sin(point[1]);

    const Vector3<Real> der0{ -xExtent * sin0 * sin1, yExtent * cos0 * sin1, MathType::GetValue(0) };

    const Vector3<Real> der1{ xExtent * cos0 * cos1, yExtent * sin0 * cos1, -zExtent * sin1 };

    const Vector3<Real> der00{ -xExtent * cos0 * sin1, -yExtent * sin0 * sin1, MathType::GetValue(0) };

    const Vector3<Real> der01{ -xExtent * sin0 * cos1, yExtent * cos0 * cos1, MathType::GetValue(0) };

    const Vector3<Real> der11{ -xExtent * cos0 * sin1, -yExtent * sin0 * sin1, -zExtent * cos1 };

    this->SetChristoffel1(0, 0, 0, Vector3Tools<Real>::DotProduct(der00, der0));
    this->SetChristoffel1(0, 0, 1, Vector3Tools<Real>::DotProduct(der01, der0));
    this->SetChristoffel1(0, 1, 0, this->GeChristoffel1(0, 0, 1));
    this->SetChristoffel1(0, 1, 1, Vector3Tools<Real>::DotProduct(der11, der0));

    this->SetChristoffel1(1, 0, 0, Vector3Tools<Real>::DotProduct(der00, der1));
    this->SetChristoffel1(1, 0, 1, Vector3Tools<Real>::DotProduct(der01, der1));
    this->SetChristoffel1(1, 1, 0, this->GeChristoffel1(1, 0, 1));
    this->SetChristoffel1(1, 0, 1, Vector3Tools<Real>::DotProduct(der11, der1));
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_ELLIPSOID_GEODESIC_DETAIL_H