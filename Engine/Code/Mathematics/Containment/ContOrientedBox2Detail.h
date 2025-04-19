/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 14:41)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ORIENTED_BOX2_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_ORIENTED_BOX2_DETAIL_H

#include "ContOrientedBox2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Approximation/ApproximationGaussian2.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::ContOrientedBox2<Real>::ContOrientedBox2() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ContOrientedBox2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ContOrientedBox2<Real>::GetContainer(const Vector2Container& points, OrientedBox2& box)
{
    const auto numPoints = boost::numeric_cast<int>(points.size());

    /// 用高斯分布拟合点。
    if (ApproximationGaussian2<Real> fitter{};
        fitter.Fit(points))
    {
        box = fitter.GetParameters();

        /// 设C为长方体中心，设U0和U1为长方体轴。
        /// 每个输入点的形式为X = C + y0*U0 + y1*U1。
        /// 以下代码计算min(y0), max(y0), min(y1), 和 max(y1)。
        /// 然后将箱中心调整为
        /// C' = C + 0.5*(min(y0)+max(y0))*U0 + 0.5*(min(y1)+max(y1))*U1

        auto diff = points.at(0) - box.GetCenter();
        Vector2 pMin{ Dot(diff, box.GetAxis(0)), Dot(diff, box.GetAxis(1)) };
        auto pMax = pMin;
        for (auto i = 1; i < numPoints; ++i)
        {
            diff = points.at(i) - box.GetCenter();
            for (auto j = 0; j < 2; ++j)
            {
                auto dot = Dot(diff, box.GetAxis(j));
                if (dot < pMin[j])
                {
                    pMin[j] = dot;
                }
                else if (dot > pMax[j])
                {
                    pMax[j] = dot;
                }
            }
        }

        for (auto j = 0; j < 2; ++j)
        {
            box.SetCenter(box.GetCenter() + MathType::GetRational(1, 2) * (pMin[j] + pMax[j]) * box.GetAxis(j));
            box.SetExtent(j, MathType::GetRational(1, 2) * (pMax[j] - pMin[j]));
        }

        return true;
    }

    return false;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ContOrientedBox2<Real>::InContainer(const Vector2& point, const OrientedBox2& box)
{
    const auto diff = point - box.GetCenter();
    for (auto i = 0; i < 2; ++i)
    {
        const auto coeff = Dot(diff, box.GetAxis(i));
        if (std::fabs(coeff) > box.GetExtent(i))
        {
            return false;
        }
    }
    return true;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ContOrientedBox2<Real>::MergeContainers(const OrientedBox2& box0, const OrientedBox2& box1, OrientedBox2& merge)
{
    /// 在方框中心的第一个猜测。
    /// 稍后，在将输入框顶点投影到由框轴的平均值确定的轴上之后，将更新此值。
    merge.SetCenter(MathType::GetRational(1, 2) * (box0.GetCenter() + box1.GetCenter()));

    /// 合并框轴是输入框轴的平均值。
    /// 如有必要，第二个长方体的轴被取反，因此它们与第一个长方体形成锐角。
    if (Dot(box0.GetAxis(0), box1.GetAxis(0)) >= Real{})
    {
        merge.SetAxis(0, MathType::GetRational(1, 2) * (box0.GetAxis(0) + box1.GetAxis(0)));
    }
    else
    {
        merge.SetAxis(0, MathType::GetRational(1, 2) * (box0.GetAxis(0) - box1.GetAxis(0)));
    }
    auto axis0 = merge.GetAxis(0);
    Normalize(axis0);
    merge.SetAxis(1, -Perp(axis0));

    //   e[i] = 0.5*(max[i]-min[i])
    /// 将输入框顶点投影到合并的框轴上。
    /// 包含当前中心C的每个轴D[i]具有最小投影值min[i]和最大投影值max[i]。
    /// 轴上对应的端点是C+min[i]*D[i]和C+max[i]*D[i]。
    /// 点C不一定是任何间隔的中点。
    /// 实际的盒子中心将从C调整到作为每个间隔的中点的点C’，
    /// C' = C + sum_{i=0}^1 0.5*(min[i]+max[i])*D[i]
    /// 方框范围为
    ///  e[i] = 0.5*(max[i]-min[i])

    std::array<Vector2, 4> vertex{};
    Vector2 pMin{};
    Vector2 pMax{};

    vertex = box0.GetVertices();
    for (auto i = 0; i < 4; ++i)
    {
        const auto diff = vertex.at(i) - merge.GetCenter();
        for (auto j = 0; j < 2; ++j)
        {
            auto dot = Dot(diff, merge.GetAxis(j));
            if (dot > pMax[j])
            {
                pMax[j] = dot;
            }
            else if (dot < pMin[j])
            {
                pMin[j] = dot;
            }
        }
    }

    vertex = box1.GetVertices();
    for (auto i = 0; i < 4; ++i)
    {
        const auto diff = vertex.at(i) - merge.GetCenter();
        for (auto j = 0; j < 2; ++j)
        {
            auto dot = Dot(diff, merge.GetAxis(j));
            if (dot > pMax[j])
            {
                pMax[j] = dot;
            }
            else if (dot < pMin[j])
            {
                pMin[j] = dot;
            }
        }
    }

    /// [min,max]是合并框轴坐标系中的轴对齐框。
    /// 将当前长方体中心更新为新长方体的中心。基于新中心计算范围。

    for (auto j = 0; j < 2; ++j)
    {
        merge.SetCenter(merge.GetCenter() + MathType::GetRational(1, 2) * (pMax[j] + pMin[j]) * merge.GetAxis(j));
        merge.SetExtent(j, MathType::GetRational(1, 2) * (pMax[j] - pMin[j]));
    }

    return true;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_ORIENTED_BOX2_DETAIL_H
