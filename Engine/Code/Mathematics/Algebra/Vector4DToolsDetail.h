///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 16:02)

// 4D向量工具类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_DETAIL_H

#include "Vector4DTools.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR4D_TOOLS_ACHIEVE)

    #include "Vector4DToolsAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR4D_TOOLS_ACHIEVE)

#include <iostream>

template <typename Real>
bool Mathematics::operator==(const Vector4D<Real>& lhs, const Vector4D<Real>& rhs)
{
    return lhs.GetCoordinate() == rhs.GetCoordinate();
}

template <typename Real>
bool Mathematics::operator<(const Vector4D<Real>& lhs, const Vector4D<Real>& rhs)
{
    return lhs.GetCoordinate() < rhs.GetCoordinate();
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Vector4D<Real>& vector)
{
    return outFile << "x = " << vector.GetX() << " y = " << vector.GetY()
                   << " z = " << vector.GetZ() << " w = " << vector.GetW();
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_4D_TOOLS_DETAIL_H
