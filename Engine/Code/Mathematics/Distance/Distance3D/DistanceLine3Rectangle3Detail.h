///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:31)

#ifndef MATHEMATICS_DISTANCE_DIST_LINE3_RECTANGLE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DIST_LINE3_RECTANGLE3_DETAIL_H

#include "DistanceLine3Rectangle3.h"
#include "DistanceLine3Segment3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceLine3Rectangle3<Real>::DistanceLine3Rectangle3(const Line3& line, const Rectangle3& rectangle) noexcept
    : ParentType{}, line{ line }, rectangle{ rectangle }, rectCoord{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceLine3Rectangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::DistanceLine3Rectangle3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Rectangle3<Real> Mathematics::DistanceLine3Rectangle3<Real>::GetRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rectangle;
}

template <typename Real>
typename Mathematics::DistanceLine3Rectangle3<Real>::DistanceResult Mathematics::DistanceLine3Rectangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 测试线是否与矩形相交。 如果是这样，则平方距离为零。
    const auto crossProduct = Vector3Tools::CrossProduct(rectangle.GetAxis0(), rectangle.GetAxis1());

    if (const auto dot = Vector3Tools::DotProduct(crossProduct, line.GetDirection());
        MathType::GetZeroTolerance() < MathType::FAbs(dot))
    {
        // 线和矩形不平行，因此线与矩形的平面相交。
        const auto diff = line.GetOrigin() - rectangle.GetCenter();

        const auto vector3OrthonormalBasis = Vector3Tools::GenerateComplementBasis(line.GetDirection());
        const auto uVector = vector3OrthonormalBasis.GetUVector();
        const auto vVector = vector3OrthonormalBasis.GetVVector();
        const auto uVectorDotAxis0 = Vector3Tools::DotProduct(uVector, rectangle.GetAxis0());
        const auto uVectorDotAxis1 = Vector3Tools::DotProduct(uVector, rectangle.GetAxis1());
        const auto uVectorDotDiff = Vector3Tools::DotProduct(uVector, diff);
        const auto vVectorDotAxis0 = Vector3Tools::DotProduct(vVector, rectangle.GetAxis0());
        const auto vVectorDotAxis1 = Vector3Tools::DotProduct(vVector, rectangle.GetAxis1());
        const auto vVectorDotDiff = Vector3Tools::DotProduct(vVector, diff);
        const auto invDet = (MathType::GetValue(1)) / (uVectorDotAxis0 * vVectorDotAxis1 - uVectorDotAxis1 * vVectorDotAxis0);

        // 相交点的矩形坐标。
        const auto s0 = (vVectorDotAxis1 * uVectorDotDiff - uVectorDotAxis1 * vVectorDotDiff) * invDet;
        const auto s1 = (uVectorDotAxis0 * vVectorDotDiff - vVectorDotAxis0 * uVectorDotDiff) * invDet;

        if (MathType::FAbs(s0) <= rectangle.GetExtent0() && MathType::FAbs(s1) <= rectangle.GetExtent1())
        {
            // 相交点的线参数。
            const auto directionDotAxis0 = Vector3Tools::DotProduct(line.GetDirection(), rectangle.GetAxis0());
            const auto directionDotAxis1 = Vector3Tools::DotProduct(line.GetDirection(), rectangle.GetAxis1());
            const auto directionDotDiff = Vector3Tools::DotProduct(line.GetDirection(), diff);
            const auto lineParameter = s0 * directionDotAxis0 + s1 * directionDotAxis1 - directionDotDiff;

            // 相交点的矩形坐标。
            rectCoord[0] = s0;
            rectCoord[1] = s1;

            // 相交点在矩形的内部或上方。
            const auto closestPoint0 = line.GetOrigin() + lineParameter * line.GetDirection();

            const auto closestPoint1 = rectangle.GetCenter() + s0 * rectangle.GetAxis0() + s1 * rectangle.GetAxis1();

            return DistanceResult{ MathType::GetValue(0), MathType::GetValue(0), closestPoint0, closestPoint1, lineParameter, MathType::GetValue(0) };
        }
    }

    Vector3 closestPoint0{};
    Vector3 closestPoint1{};
    Real lineParameter{};

    /// （1）线不与矩形平行，且线和矩形平面的交点在矩形外部，或者（2）线和矩形平行。
    /// 无论如何，矩形上的最接近点在矩形的边缘上。 将线与矩形的所有四个边缘进行比较。

    auto sqrDist = MathType::maxReal;
    constexpr auto size = 2;
    std::array<Vector3, size> scaledDir{ rectangle.GetExtent0() * rectangle.GetAxis0(), rectangle.GetExtent1() * rectangle.GetAxis1() };

    for (auto outerIndex = 0; outerIndex < size; ++outerIndex)
    {
        for (auto innerIndex = 0; innerIndex < size; ++innerIndex)
        {
            const auto extent = rectangle.GetExtent(1 - outerIndex);
            const auto index = 2 * innerIndex - 1;
            const auto center = rectangle.GetCenter() + static_cast<Real>(index) * scaledDir.at(outerIndex);
            const auto direction = rectangle.GetAxis(1 - outerIndex);
            const Segment3<Real> segment{ extent, center, direction };

            DistanceLine3Segment3<Real> distanceLine3Segment3{ line, segment };

            if (auto squaredDistance = distanceLine3Segment3.GetSquared();
                squaredDistance.GetDistance() < sqrDist)
            {
                closestPoint0 = squaredDistance.GetLhsClosestPoint();
                closestPoint1 = squaredDistance.GetRhsClosestPoint();
                sqrDist = squaredDistance.GetDistance();

                lineParameter = squaredDistance.GetLhsParameter();
                const auto ratio = squaredDistance.GetRhsParameter() / segment.GetExtent();
                const auto extentIndex0 = (1 - outerIndex) * (2 * innerIndex - 1);
                const auto extentIndex1 = (1 - innerIndex) * (2 * outerIndex - 1);
                rectCoord[0] = rectangle.GetExtent0() * (extentIndex0 + outerIndex * ratio);
                rectCoord[1] = rectangle.GetExtent1() * (extentIndex1 + innerIndex * ratio);
            }
        }
    }

    return DistanceResult{ sqrDist, MathType::GetValue(0), closestPoint0, closestPoint1, lineParameter, MathType::GetValue(0) };
}

template <typename Real>
typename Mathematics::DistanceLine3Rectangle3<Real>::DistanceResult Mathematics::DistanceLine3Rectangle3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedLine = line.GetMove(t, lhsVelocity);
    const auto movedRectangle = rectangle.GetMove(t, rhsVelocity);

    ClassType distance{ movedLine, movedRectangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
Real Mathematics::DistanceLine3Rectangle3<Real>::GetRectangleCoordinate(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rectCoord[index];
}

#endif  // MATHEMATICS_DISTANCE_DIST_LINE3_RECTANGLE3_DETAIL_H