///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 15:09)

// 2D向量工具类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_DETAIL_H

#include "Vector2DTools.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR2D_TOOLS_ACHIEVE)

    #include "Vector2DToolsAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR2D_TOOLS_ACHIEVE)

#include <iostream>

template <typename Real>
bool Mathematics::operator==(const Vector2D<Real>& lhs, const Vector2D<Real>& rhs)
{
    return lhs.GetCoordinate() == rhs.GetCoordinate();
}

template <typename Real>
bool Mathematics::operator<(const Vector2D<Real>& lhs, const Vector2D<Real>& rhs) noexcept
{
    if (lhs.GetX() < rhs.GetX())
        return true;
    else if (rhs.GetX() < lhs.GetX())
        return false;
    else
        return lhs.GetY() < rhs.GetY();
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Vector2D<Real>& vector)
{
    return outFile << "x=" << vector.GetX() << "　y=" << vector.GetY();
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_TOOLS_DETAIL_H