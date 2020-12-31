///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/25 13:14)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_ACHIEVE_H

#include "IntersectorUtility3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
typename Mathematics::IntersectorUtility3<Real>::Container Mathematics::IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(const Vector3D& normal, Real constant, const Container& point)
{
    /// 假定输入顶点为逆时针顺序。 顺序是此函数的不变式。

    // 测试线的哪一侧是顶点
    auto result = point;
    auto quantity = boost::numeric_cast<int>(result.size());
    auto positive = 0;
    auto negative = 0;
    auto index = -1;

    using DotType = std::array<Real, 8>;

    DotType dotProduct{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    for (auto i = 0; i < quantity; ++i)
    {
        /// 这里使用epsilon是因为点积和“常数”可能彼此完全相等（理论上），但由于浮点问题而略有不同。
        /// 因此，在测试数上加一点，以将实际上相等的数推向正数。

        // 可能是一个相对的容忍度。 乘以常数可能不是做到这一点的最佳方法。
        dotProduct[i] = Vector3DTools<Real>::DotProduct(normal, result[i]) - constant + Math<Real>::FAbs(constant) * Math<Real>::GetZeroTolerance();

        if (Math<Real>::GetValue(0) <= dotProduct[i])
        {
            ++positive;
            if (index < 0)
            {
                index = i;
            }
        }
        else
        {
            ++negative;
        }
    }

    if (quantity == 2)
    {
        // 线有些不同，剪裁线段无法创建新的线段，就像剪裁多边形一样
        if (0 < positive)
        {
            if (0 < negative)
            {
                auto clip = 0;

                if (index == 0)
                {
                    // vertex0为正，vertex1被裁剪
                    clip = 1;
                }
                else  // pIndex == 1
                {
                    // vertex1为正， vertex0被裁剪
                    clip = 0;
                }

                auto t = dotProduct[index] / (dotProduct[index] - dotProduct[clip]);
                auto value = result[clip];
                value -= result[index];
                result[clip] = result[index] + t * (value);
            }
            // 否则两者都是正的，没有裁剪
        }
        else
        {
            // 断言：整个行都已剪切，但我们不应该到达此处。
            result.clear();
        }
    }
    else
    {
        if (0 < positive)
        {
            if (0 < negative)
            {
                // 平面与多边形相交
                Container container{};

                if (0 < index)
                {
                    // 在线的第一个剪辑顶点
                    auto curIndex = index;
                    auto prvIndex = curIndex - 1;
                    auto t = dotProduct[curIndex] / (dotProduct[curIndex] - dotProduct[prvIndex]);
                    container.emplace_back(result[curIndex] + t * (result[prvIndex] - result[curIndex]));

                    // 线正侧的顶点
                    while (curIndex < quantity && dotProduct[curIndex] >= Math<Real>::GetValue(0))
                    {
                        container.emplace_back(result[curIndex++]);
                    }

                    // 在线上的最后一个剪辑顶点
                    if (curIndex < quantity)
                    {
                        prvIndex = curIndex - 1;
                    }
                    else
                    {
                        curIndex = 0;
                        prvIndex = quantity - 1;
                    }
                    t = dotProduct[curIndex] / (dotProduct[curIndex] - dotProduct[prvIndex]);
                    container.emplace_back(result[curIndex] + t * (result[prvIndex] - result[curIndex]));
                }
                else  // index is 0
                {
                    // 线正侧的顶点
                    auto curIndex = 0;
                    while (curIndex < quantity && Math<Real>::GetValue(0) <= dotProduct[curIndex])
                    {
                        container.emplace_back(result[curIndex++]);
                    }

                    // 在线上的最后一个剪辑顶点
                    auto prvIndex = curIndex - 1;
                    auto t = dotProduct[curIndex] / (dotProduct[curIndex] - dotProduct[prvIndex]);
                    container.emplace_back(result[curIndex] + t * (result[prvIndex] - result[curIndex]));

                    // 在负侧跳过顶点
                    while (curIndex < quantity && Math<Real>::GetValue(0) < dotProduct[curIndex])
                    {
                        curIndex++;
                    }

                    // 在线的第一个剪辑顶点
                    if (curIndex < quantity)
                    {
                        prvIndex = curIndex - 1;
                        t = dotProduct[curIndex] / (dotProduct[curIndex] - dotProduct[prvIndex]);
                        container.emplace_back(result[curIndex] + t * (result[prvIndex] - result[curIndex]));

                        // 线正侧的顶点
                        while (curIndex < quantity && Math<Real>::GetValue(0) <= dotProduct[curIndex])
                        {
                            container.emplace_back(result[curIndex++]);
                        }
                    }
                    else
                    {
                        // curIndex = 0
                        prvIndex = quantity - 1;
                        t = dotProduct[0] / (dotProduct[0] - dotProduct[prvIndex]);
                        container.emplace_back(result[0] + t * (result[prvIndex] - result[0]));
                    }
                }
                result = container;
            }
            // else 多边形完全位于平面的正侧，无需执行任何操作
        }
        else
        {
            // 多边形不与平面的正侧相交，请全部剪切。 如果在确定相交之后由findintersect例程调用，则永远不会发生这种情况。

            result.clear();
        }
    }

#include STSTEM_WARNING_POP

    return result;
}

template <typename Real>
Mathematics::Vector3D<Real> Mathematics::IntersectorUtility3<Real>::GetPointFromIndex(int index, const Box3& box)
{
    auto point = box.GetCenter();

    if (index & 4)
    {
        point += box.GetExtent(2) * box.GetAxis(2);
    }
    else
    {
        point -= box.GetExtent(2) * box.GetAxis(2);
    }

    if (index & 2)
    {
        point += box.GetExtent(1) * box.GetAxis(1);
    }
    else
    {
        point -= box.GetExtent(1) * box.GetAxis(1);
    }

    if (index & 1)
    {
        point += box.GetExtent(0) * box.GetAxis(0);
    }
    else
    {
        point -= box.GetExtent(0) * box.GetAxis(0);
    }

    return point;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_ACHIEVE_H
