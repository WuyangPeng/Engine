/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 10:37)

#ifndef MATHEMATICS_OBJECTS_3D_RAY3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_RAY3_DETAIL_H

#include "Ray3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_RAY3_ACHIEVE)

    #include "Ray3Achieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_RAY3_ACHIEVE)

template <typename Real>
bool Mathematics::Approximate(const Ray3<Real>& lhs, const Ray3<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    return Vector3Tools<Real>::Approximate(lhs.GetOrigin(), rhs.GetOrigin(), epsilon) &&
           Vector3Tools<Real>::Approximate(lhs.GetDirection(), rhs.GetDirection(), epsilon);
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Ray3<Real>& ray)
{
    outFile << "origin=" << ray.GetOrigin() << ",direction=" << ray.GetDirection();

    return outFile;
}

#endif  // MATHEMATICS_OBJECTS_3D_RAY3_DETAIL_H