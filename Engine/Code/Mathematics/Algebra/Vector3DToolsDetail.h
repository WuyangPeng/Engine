///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/12 21:03)

// 3D�����������ʵ��
#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_DETAIL_H

#include "Vector3DTools.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR3D_TOOLS_ACHIEVE)

    #include "Vector3DToolsAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR3D_TOOLS_ACHIEVE)

#include <iostream>

template <typename Real>
bool Mathematics::operator==(const Vector3D<Real>& lhs, const Vector3D<Real>& rhs)
{
    return lhs.GetCoordinate() == rhs.GetCoordinate();
}

template <typename Real>
bool Mathematics::operator<(const Vector3D<Real>& lhs, const Vector3D<Real>& rhs)
{
    return lhs.GetCoordinate() < rhs.GetCoordinate();
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Vector3D<Real>& vector)
{
    return outFile << "x=" << vector.GetX() << "��y=" << vector.GetY() << "��z=" << vector.GetZ();
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_TOOLS_DETAIL_H
