///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 09:34)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_DETAIL_H

#include "Bisect3Calculate.h"
#include "Bisect3Node.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect3.h"

template <typename Real>
Mathematics::Bisect3Calculate<Real>::Bisect3Calculate(const Bisect3& bisect,
                                                      Real beginPointX,
                                                      Real beginPointY,
                                                      Real beginPointZ,
                                                      Real endPointX,
                                                      Real endPointY,
                                                      Real endPointZ)
    : bisect3{ bisect },
      level{ 0 },
      bisect3Root(std::make_shared<Bisect3Root>()),
      bisect3Storage{ bisect },
      graph{}
{
    Calculate(beginPointX, beginPointY, beginPointZ, endPointX, endPointY, endPointZ);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>::Calculate(Real beginPointX,
                                                    Real beginPointY,
                                                    Real beginPointZ,
                                                    Real endPointX,
                                                    Real endPointY,
                                                    Real endPointZ)
{
    MATHEMATICS_ASSERTION_2(beginPointX <= endPointX, "起点的X值比终点的X值大。");
    MATHEMATICS_ASSERTION_2(beginPointY <= endPointY, "起点的Y值比终点的Y值大。");
    MATHEMATICS_ASSERTION_2(beginPointZ <= endPointZ, "起点的Z值比终点的Z值大。");

    // 测试的八个角的值。
    if (bisect3Storage.TestEightCornerValues(beginPointX, beginPointY, beginPointZ, endPointX, endPointY, endPointZ))
    {
        bisect3Root = bisect3Storage.GetBisect3Root();

        return;
    }

    // 构建初始八边形

    // 增加 N000。
    graph = std::make_shared<Bisect3Node>(beginPointX,
                                          beginPointY,
                                          beginPointZ,
                                          bisect3Storage.GetBeginXBeginYBeginZValue0(),
                                          bisect3Storage.GetBeginXBeginYBeginZValue1(),
                                          bisect3Storage.GetBeginXBeginYBeginZValue2());

    // 增加 N100。
    graph->AddXNextNode(endPointX,
                        beginPointY,
                        beginPointZ,
                        bisect3Storage.GetEndXBeginYBeginZValue0(),
                        bisect3Storage.GetEndXBeginYBeginZValue1(),
                        bisect3Storage.GetEndXBeginYBeginZValue2());

    // 增加 N010。
    graph->AddYNextNode(beginPointX,
                        endPointY,
                        beginPointZ,
                        bisect3Storage.GetBeginXEndYBeginZValue0(),
                        bisect3Storage.GetBeginXEndYBeginZValue1(),
                        bisect3Storage.GetBeginXEndYBeginZValue2());

    // 增加 N110。
    graph->GetXNext()->AddYNextNode(endPointX,
                                    endPointY,
                                    beginPointZ,
                                    bisect3Storage.GetEndXEndYBeginZValue0(),
                                    bisect3Storage.GetEndXEndYBeginZValue1(),
                                    bisect3Storage.GetEndXEndYBeginZValue2());

    graph->GetYNext()->AddXNextNode(graph->GetXNext()->GetYNext());

    // 增加 N001。
    graph->AddZNextNode(beginPointX,
                        beginPointY,
                        endPointZ,
                        bisect3Storage.GetBeginXBeginYEndZValue0(),
                        bisect3Storage.GetBeginXBeginYEndZValue1(),
                        bisect3Storage.GetBeginXBeginYEndZValue2());

    // 增加 N101。
    graph->GetXNext()->AddZNextNode(endPointX,
                                    beginPointY,
                                    endPointZ,
                                    bisect3Storage.GetEndXBeginYEndZValue0(),
                                    bisect3Storage.GetEndXBeginYEndZValue1(),
                                    bisect3Storage.GetEndXBeginYEndZValue2());

    graph->GetZNext()->AddXNextNode(graph->GetXNext()->GetZNext());

    // 增加 N011。
    graph->GetYNext()->AddZNextNode(beginPointX,
                                    endPointY,
                                    endPointZ,
                                    bisect3Storage.GetBeginXEndYEndZValue0(),
                                    bisect3Storage.GetBeginXEndYEndZValue1(),
                                    bisect3Storage.GetBeginXEndYEndZValue2());

    graph->GetZNext()->AddYNextNode(graph->GetYNext()->GetZNext());

    // 增加 N111。
    graph->GetXNext()->GetYNext()->AddZNextNode(endPointX,
                                                endPointY,
                                                endPointZ,
                                                bisect3Storage.GetEndXEndYEndZValue0(),
                                                bisect3Storage.GetEndXEndYEndZValue1(),
                                                bisect3Storage.GetEndXEndYEndZValue2());

    graph->GetYNext()->GetXNext()->AddZNextNode(graph->GetXNext()->GetYNext()->GetZNext());
    graph->GetXNext()->GetZNext()->AddYNextNode(graph->GetXNext()->GetYNext()->GetZNext());

    if (const auto result = BisectRecurse(graph);
        result)
    {
        bisect3Root = bisect3Storage.GetBisect3Root();
    }

    // 将剩下的四边形从m_Graph中移除。
    graph.reset();
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Bisect3Calculate<Real>::IsValid() const noexcept
{
    if (bisect3Root != nullptr && graph == nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::Bisect3Calculate<Real>::Bisect3Root Mathematics::Bisect3Calculate<Real>::GetRoot() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return *bisect3Root;
}

template <typename Real>
bool Mathematics::Bisect3Calculate<Real>::BisectRecurse(const Bisect3NodeSharedPtr& node)
{
    if (node == nullptr)
    {
        return false;
    }

    if (++level == bisect3.GetMaxLevel())
    {
        // 递归超出了次数，返回一个中间值。
        --level;
        bisect3Root = std::make_shared<Bisect3Root>(bisect3Storage.GetMidpointX(), bisect3Storage.GetMidpointY(), bisect3Storage.GetMidpointZ(), BisectRootType::Unknown);

        return false;
    }

    if (node->IsFunctionResult0SameSign() || node->IsFunctionResult1SameSign() || node->IsFunctionResult2SameSign())
    {
        // FirstFunction具有相同的符号在边界点。
        // 或者SecondFunction具有相同的符号在边界点。
        // 或者ThirdFunction具有相同的符号在边界点。

        // 方程在这个区间无解
        --level;

        return false;
    }

    // 二等分八边形。
    bisect3Storage.SetStorageValue(node);

    if (bisect3Storage.TestEdgeValues())
    {
        return true;
    }

    // 将立方体分成八个立方体进行递归搜索。

    // 构建左下内的立方体

    // 原左下内点
    auto leftLowerInside = std::make_shared<Bisect3Node>(bisect3Storage.GetBeginPointX(),
                                                         bisect3Storage.GetBeginPointY(),
                                                         bisect3Storage.GetBeginPointZ(),
                                                         bisect3Storage.GetBeginXBeginYBeginZValue0(),
                                                         bisect3Storage.GetBeginXBeginYBeginZValue1(),
                                                         bisect3Storage.GetBeginXBeginYBeginZValue2());

    BuildLeftLowerInside(leftLowerInside);

    // 构建右下内的立方体

    // 边 000, 100
    auto rightLowerInside = std::make_shared<Bisect3Node>(bisect3Storage.GetMidpointX(),
                                                          bisect3Storage.GetBeginPointY(),
                                                          bisect3Storage.GetBeginPointZ(),
                                                          bisect3Storage.GetMidXBeginYBeginZValue0(),
                                                          bisect3Storage.GetMidXBeginYBeginZValue1(),
                                                          bisect3Storage.GetMidXBeginYBeginZValue2());

    BuildRightLowerInside(rightLowerInside);

    // 构建左上内的立方体

    // 边 000, 010
    auto leftUpperInside = std::make_shared<Bisect3Node>(bisect3Storage.GetBeginPointX(),
                                                         bisect3Storage.GetMidpointY(),
                                                         bisect3Storage.GetBeginPointZ(),
                                                         bisect3Storage.GetBeginXMidYBeginZValue0(),
                                                         bisect3Storage.GetBeginXMidYBeginZValue1(),
                                                         bisect3Storage.GetBeginXMidYBeginZValue2());

    BuildLeftUpperInside(leftUpperInside);

    // 构建右上内的立方体

    // 面 000, 100, 110, 010
    auto rightUpperInside = std::make_shared<Bisect3Node>(bisect3Storage.GetMidpointX(),
                                                          bisect3Storage.GetMidpointY(),
                                                          bisect3Storage.GetBeginPointZ(),
                                                          bisect3Storage.GetMidXMidYBeginZValue0(),
                                                          bisect3Storage.GetMidXMidYBeginZValue1(),
                                                          bisect3Storage.GetMidXMidYBeginZValue2());

    BuildRightUpperInside(rightUpperInside);

    // 构建左下外的立方体

    // 边 000, 001
    auto leftLowerOutside = std::make_shared<Bisect3Node>(bisect3Storage.GetBeginPointX(),
                                                          bisect3Storage.GetBeginPointY(),
                                                          bisect3Storage.GetMidpointZ(),
                                                          bisect3Storage.GetBeginXBeginYMidZValue0(),
                                                          bisect3Storage.GetBeginXBeginYMidZValue1(),
                                                          bisect3Storage.GetBeginXBeginYMidZValue2());

    BuildLeftLowerOutside(leftLowerOutside);

    // 构建右下外的立方体

    // 面 000, 100, 001, 101
    auto rightLowerOutside = std::make_shared<Bisect3Node>(bisect3Storage.GetMidpointX(),
                                                           bisect3Storage.GetBeginPointY(),
                                                           bisect3Storage.GetMidpointZ(),
                                                           bisect3Storage.GetMidXBeginYMidZValue0(),
                                                           bisect3Storage.GetMidXBeginYMidZValue1(),
                                                           bisect3Storage.GetMidXBeginYMidZValue2());

    BuildRightLowerOutside(rightLowerOutside);

    // 构建左上外的立方体

    // 面 000, 010, 011, 001
    auto leftUpperOutside = std::make_shared<Bisect3Node>(bisect3Storage.GetBeginPointX(),
                                                          bisect3Storage.GetMidpointY(),
                                                          bisect3Storage.GetMidpointZ(),
                                                          bisect3Storage.GetBeginXMidYMidZValue0(),
                                                          bisect3Storage.GetBeginXMidYMidZValue1(),
                                                          bisect3Storage.GetBeginXMidYMidZValue2());

    BuildLeftUpperOutside(leftUpperOutside);

    // 构建右上外的立方体

    // 中心
    auto rightUpperOutside = std::make_shared<Bisect3Node>(bisect3Storage.GetMidpointX(),
                                                           bisect3Storage.GetMidpointY(),
                                                           bisect3Storage.GetMidpointZ(),
                                                           bisect3Storage.GetMidXMidYMidZValue0(),
                                                           bisect3Storage.GetMidXMidYMidZValue1(),
                                                           bisect3Storage.GetMidXMidYMidZValue2());

    BuildRightUpperOutside(rightUpperOutside);

    // 搜索子立方体的根。
    const auto result = BisectRecurse(leftLowerInside) ||
                        BisectRecurse(rightLowerInside) ||
                        BisectRecurse(leftUpperInside) ||
                        BisectRecurse(rightUpperInside) ||
                        BisectRecurse(leftLowerOutside) ||
                        BisectRecurse(rightLowerOutside) ||
                        BisectRecurse(leftUpperOutside) ||
                        BisectRecurse(rightUpperOutside);

    // 整个子八边形检查失败，删除添加的节点。

    --level;

    return result;
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>::BuildLeftLowerInside(const Bisect3NodeSharedPtr& node)
{
    if (node == nullptr)
    {
        return;
    }

    // 边 000, 100
    node->AddXNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetMidXBeginYBeginZValue0(),
                       bisect3Storage.GetMidXBeginYBeginZValue1(),
                       bisect3Storage.GetMidXBeginYBeginZValue2());

    // 边 000, 010
    node->AddYNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetBeginXMidYBeginZValue0(),
                       bisect3Storage.GetBeginXMidYBeginZValue1(),
                       bisect3Storage.GetBeginXMidYBeginZValue2());

    // 面 000, 100, 110, 010。
    node->GetXNext()->AddYNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetBeginPointZ(),
                                   bisect3Storage.GetMidXMidYBeginZValue0(),
                                   bisect3Storage.GetMidXMidYBeginZValue1(),
                                   bisect3Storage.GetMidXMidYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 边 000, 001。
    node->AddZNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetBeginXBeginYMidZValue0(),
                       bisect3Storage.GetBeginXBeginYMidZValue1(),
                       bisect3Storage.GetBeginXBeginYMidZValue2());

    // 面 000, 100, 001, 101。
    node->GetXNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetBeginPointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetMidXBeginYMidZValue0(),
                                   bisect3Storage.GetMidXBeginYMidZValue1(),
                                   bisect3Storage.GetMidXBeginYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 面 000, 010, 011, 001。
    node->GetYNext()->AddZNextNode(bisect3Storage.GetBeginPointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetBeginXMidYMidZValue0(),
                                   bisect3Storage.GetBeginXMidYMidZValue1(),
                                   bisect3Storage.GetBeginXMidYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 中心。
    node->GetXNext()->GetYNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                               bisect3Storage.GetMidpointY(),
                                               bisect3Storage.GetMidpointZ(),
                                               bisect3Storage.GetMidXMidYMidZValue0(),
                                               bisect3Storage.GetMidXMidYMidZValue1(),
                                               bisect3Storage.GetMidXMidYMidZValue2());

    node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
    node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>::BuildRightLowerInside(const Bisect3NodeSharedPtr& node)
{
    if (node == nullptr)
    {
        return;
    }

    // 原右下内点
    node->AddXNextNode(bisect3Storage.GetEndPointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetEndXBeginYBeginZValue0(),
                       bisect3Storage.GetEndXBeginYBeginZValue1(),
                       bisect3Storage.GetEndXBeginYBeginZValue2());

    // 面 000, 100, 110, 010
    node->AddYNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetMidXMidYBeginZValue0(),
                       bisect3Storage.GetMidXMidYBeginZValue1(),
                       bisect3Storage.GetMidXMidYBeginZValue2());

    // 边 100, 110
    node->GetXNext()->AddYNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetBeginPointZ(),
                                   bisect3Storage.GetEndXMidYBeginZValue0(),
                                   bisect3Storage.GetEndXMidYBeginZValue1(),
                                   bisect3Storage.GetEndXMidYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 面 000, 100, 001, 101
    node->AddZNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetMidXBeginYMidZValue0(),
                       bisect3Storage.GetMidXBeginYMidZValue1(),
                       bisect3Storage.GetMidXBeginYMidZValue2());

    // 边 100, 101
    node->GetXNext()->AddZNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetBeginPointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetEndXBeginYMidZValue0(),
                                   bisect3Storage.GetEndXBeginYMidZValue1(),
                                   bisect3Storage.GetEndXBeginYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 中心。
    node->GetYNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetMidXMidYMidZValue0(),
                                   bisect3Storage.GetMidXMidYMidZValue1(),
                                   bisect3Storage.GetMidXMidYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 面 110, 100, 101, 111
    node->GetXNext()->GetYNext()->AddZNextNode(bisect3Storage.GetEndPointX(),
                                               bisect3Storage.GetMidpointY(),
                                               bisect3Storage.GetMidpointZ(),
                                               bisect3Storage.GetEndXMidYMidZValue0(),
                                               bisect3Storage.GetEndXMidYMidZValue1(),
                                               bisect3Storage.GetEndXMidYMidZValue2());

    node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
    node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>::BuildLeftUpperInside(const Bisect3NodeSharedPtr& node)
{
    if (node == nullptr)
    {
        return;
    }

    // 面 000, 100，110，010
    node->AddXNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetMidXMidYBeginZValue0(),
                       bisect3Storage.GetMidXMidYBeginZValue1(),
                       bisect3Storage.GetMidXMidYBeginZValue2());

    // 原左上内点
    node->AddYNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetEndPointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetBeginXEndYBeginZValue0(),
                       bisect3Storage.GetBeginXEndYBeginZValue1(),
                       bisect3Storage.GetBeginXEndYBeginZValue2());

    // 边 110, 010。
    node->GetXNext()->AddYNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetBeginPointZ(),
                                   bisect3Storage.GetMidXEndYBeginZValue0(),
                                   bisect3Storage.GetMidXEndYBeginZValue1(),
                                   bisect3Storage.GetMidXEndYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 面  000，001，011，010
    node->AddZNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetBeginXMidYMidZValue0(),
                       bisect3Storage.GetBeginXMidYMidZValue1(),
                       bisect3Storage.GetBeginXMidYMidZValue2());

    // 中心
    node->GetXNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetMidXMidYMidZValue0(),
                                   bisect3Storage.GetMidXMidYMidZValue1(),
                                   bisect3Storage.GetMidXMidYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 边 011,010
    node->GetYNext()->AddZNextNode(bisect3Storage.GetBeginPointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetBeginXEndYMidZValue0(),
                                   bisect3Storage.GetBeginXEndYMidZValue1(),
                                   bisect3Storage.GetBeginXEndYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 面 010,110,111,011
    node->GetXNext()->GetYNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                               bisect3Storage.GetEndPointY(),
                                               bisect3Storage.GetMidpointZ(),
                                               bisect3Storage.GetMidXEndYMidZValue0(),
                                               bisect3Storage.GetMidXEndYMidZValue1(),
                                               bisect3Storage.GetMidXEndYMidZValue2());

    node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
    node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>::BuildRightUpperInside(const Bisect3NodeSharedPtr& node)
{
    if (node == nullptr)
    {
        return;
    }

    // 边 100 110
    node->AddXNextNode(bisect3Storage.GetEndPointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetEndXMidYBeginZValue0(),
                       bisect3Storage.GetEndXMidYBeginZValue1(),
                       bisect3Storage.GetEndXMidYBeginZValue2());

    // 边 110, 010
    node->AddYNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetEndPointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetMidXEndYBeginZValue0(),
                       bisect3Storage.GetMidXEndYBeginZValue1(),
                       bisect3Storage.GetMidXEndYBeginZValue2());

    // 原右上内点
    node->GetXNext()->AddYNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetBeginPointZ(),
                                   bisect3Storage.GetEndXEndYBeginZValue0(),
                                   bisect3Storage.GetEndXEndYBeginZValue1(),
                                   bisect3Storage.GetEndXEndYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 中心
    node->AddZNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetMidXBeginYMidZValue0(),
                       bisect3Storage.GetMidXBeginYMidZValue1(),
                       bisect3Storage.GetMidXBeginYMidZValue2());

    // 面 100, 110, 111, 101。
    node->GetXNext()->AddZNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetEndXMidYMidZValue0(),
                                   bisect3Storage.GetEndXMidYMidZValue1(),
                                   bisect3Storage.GetEndXMidYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 面 011,111,110,010
    node->GetYNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetMidXEndYMidZValue0(),
                                   bisect3Storage.GetMidXEndYMidZValue1(),
                                   bisect3Storage.GetMidXEndYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 边110，111
    node->GetXNext()->GetYNext()->AddZNextNode(bisect3Storage.GetEndPointX(),
                                               bisect3Storage.GetEndPointY(),
                                               bisect3Storage.GetMidpointZ(),
                                               bisect3Storage.GetEndXEndYMidZValue0(),
                                               bisect3Storage.GetEndXEndYMidZValue1(),
                                               bisect3Storage.GetEndXEndYMidZValue2());

    node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
    node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>::BuildLeftLowerOutside(const Bisect3NodeSharedPtr& node)
{
    if (node == nullptr)
    {
        return;
    }

    // 面 000, 100，101，001
    node->AddXNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetMidXBeginYMidZValue0(),
                       bisect3Storage.GetMidXBeginYMidZValue1(),
                       bisect3Storage.GetMidXBeginYMidZValue2());

    // 面 000, 001，011，010
    node->AddYNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetBeginXMidYMidZValue0(),
                       bisect3Storage.GetBeginXMidYMidZValue1(),
                       bisect3Storage.GetBeginXMidYMidZValue2());

    // 中心
    node->GetXNext()->AddYNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetMidXMidYMidZValue0(),
                                   bisect3Storage.GetMidXMidYMidZValue1(),
                                   bisect3Storage.GetMidXMidYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 原左下外点
    node->AddZNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetEndPointZ(),
                       bisect3Storage.GetBeginXBeginYEndZValue0(),
                       bisect3Storage.GetBeginXBeginYEndZValue1(),
                       bisect3Storage.GetBeginXBeginYEndZValue2());

    // 边001,101
    node->GetXNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetBeginPointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetMidXBeginYEndZValue0(),
                                   bisect3Storage.GetMidXBeginYEndZValue1(),
                                   bisect3Storage.GetMidXBeginYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 边001,011
    node->GetYNext()->AddZNextNode(bisect3Storage.GetBeginPointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetBeginXMidYEndZValue0(),
                                   bisect3Storage.GetBeginXMidYEndZValue1(),
                                   bisect3Storage.GetBeginXMidYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 面 001,101,111,011
    node->GetXNext()->GetYNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                               bisect3Storage.GetMidpointY(),
                                               bisect3Storage.GetEndPointZ(),
                                               bisect3Storage.GetMidXMidYEndZValue0(),
                                               bisect3Storage.GetMidXMidYEndZValue1(),
                                               bisect3Storage.GetMidXMidYEndZValue2());

    node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
    node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>::BuildRightLowerOutside(const Bisect3NodeSharedPtr& node)
{
    if (node == nullptr)
    {
        return;
    }

    // 边100,101
    node->AddXNextNode(bisect3Storage.GetEndPointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetEndXBeginYMidZValue0(),
                       bisect3Storage.GetEndXBeginYMidZValue1(),
                       bisect3Storage.GetEndXBeginYMidZValue2());

    // 中心
    node->AddYNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetMidXMidYMidZValue0(),
                       bisect3Storage.GetMidXMidYMidZValue1(),
                       bisect3Storage.GetMidXMidYMidZValue2());

    // 面100，101，111，110
    node->GetXNext()->AddYNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetEndXMidYMidZValue0(),
                                   bisect3Storage.GetEndXMidYMidZValue1(),
                                   bisect3Storage.GetEndXMidYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 边001,101
    node->AddZNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetEndPointZ(),
                       bisect3Storage.GetMidXBeginYEndZValue0(),
                       bisect3Storage.GetMidXBeginYEndZValue1(),
                       bisect3Storage.GetMidXBeginYEndZValue2());

    // 面001,101,111,011
    node->GetXNext()->AddZNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetBeginPointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetEndXBeginYEndZValue0(),
                                   bisect3Storage.GetEndXBeginYEndZValue1(),
                                   bisect3Storage.GetEndXBeginYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 面001，101，111，011
    node->GetYNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetMidXMidYEndZValue0(),
                                   bisect3Storage.GetMidXMidYEndZValue1(),
                                   bisect3Storage.GetMidXMidYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 边101,111
    node->GetXNext()->GetYNext()->AddZNextNode(bisect3Storage.GetEndPointX(),
                                               bisect3Storage.GetMidpointY(),
                                               bisect3Storage.GetEndPointZ(),
                                               bisect3Storage.GetEndXMidYEndZValue0(),
                                               bisect3Storage.GetEndXMidYEndZValue1(),
                                               bisect3Storage.GetEndXMidYEndZValue2());

    node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
    node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>::BuildLeftUpperOutside(const Bisect3NodeSharedPtr& node)
{
    if (node == nullptr)
    {
        return;
    }
    // 中心
    node->AddXNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetMidXMidYMidZValue0(),
                       bisect3Storage.GetMidXMidYMidZValue1(),
                       bisect3Storage.GetMidXMidYMidZValue2());

    // 边011,010
    node->AddYNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetEndPointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetBeginXEndYMidZValue0(),
                       bisect3Storage.GetBeginXEndYMidZValue1(),
                       bisect3Storage.GetBeginXEndYMidZValue2());

    // 面011，010，110，111
    node->GetXNext()->AddYNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetMidXEndYMidZValue0(),
                                   bisect3Storage.GetMidXEndYMidZValue1(),
                                   bisect3Storage.GetMidXEndYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 边 001,011
    node->AddZNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetEndPointZ(),
                       bisect3Storage.GetBeginXMidYEndZValue0(),
                       bisect3Storage.GetBeginXMidYEndZValue1(),
                       bisect3Storage.GetBeginXMidYEndZValue2());

    // 面001，101，111，011
    node->GetXNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetMidXMidYEndZValue0(),
                                   bisect3Storage.GetMidXMidYEndZValue1(),
                                   bisect3Storage.GetMidXMidYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 原左上外点
    node->GetYNext()->AddZNextNode(bisect3Storage.GetBeginPointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetBeginXEndYEndZValue0(),
                                   bisect3Storage.GetBeginXEndYEndZValue1(),
                                   bisect3Storage.GetBeginXEndYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 边011，111
    node->GetXNext()->GetYNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                               bisect3Storage.GetEndPointY(),
                                               bisect3Storage.GetEndPointZ(),
                                               bisect3Storage.GetMidXEndYEndZValue0(),
                                               bisect3Storage.GetMidXEndYEndZValue1(),
                                               bisect3Storage.GetMidXEndYEndZValue2());

    node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
    node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>::BuildRightUpperOutside(const Bisect3NodeSharedPtr& node)
{
    if (node == nullptr)
    {
        return;
    }

    // 面110,100,101,111
    node->AddXNextNode(bisect3Storage.GetEndPointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetEndXMidYMidZValue0(),
                       bisect3Storage.GetEndXMidYMidZValue1(),
                       bisect3Storage.GetEndXMidYMidZValue2());

    // 面010，110，111，011
    node->AddYNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetEndPointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetMidXEndYMidZValue0(),
                       bisect3Storage.GetMidXEndYMidZValue1(),
                       bisect3Storage.GetMidXEndYMidZValue2());

    // 边110,111
    node->GetXNext()->AddYNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetEndXEndYMidZValue0(),
                                   bisect3Storage.GetEndXEndYMidZValue1(),
                                   bisect3Storage.GetEndXEndYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 面011，111，101，001
    node->AddZNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetEndPointZ(),
                       bisect3Storage.GetMidXBeginYEndZValue0(),
                       bisect3Storage.GetMidXBeginYEndZValue1(),
                       bisect3Storage.GetMidXBeginYEndZValue2());

    // 面 100, 110, 100, 101。
    node->GetXNext()->AddZNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetEndXMidYEndZValue0(),
                                   bisect3Storage.GetEndXMidYEndZValue1(),
                                   bisect3Storage.GetEndXMidYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 边011，111
    node->GetYNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetMidXEndYEndZValue0(),
                                   bisect3Storage.GetMidXEndYEndZValue1(),
                                   bisect3Storage.GetMidXEndYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 原右上外点
    node->GetXNext()->GetYNext()->AddZNextNode(bisect3Storage.GetEndPointX(),
                                               bisect3Storage.GetEndPointY(),
                                               bisect3Storage.GetEndPointZ(),
                                               bisect3Storage.GetEndXEndYEndZValue0(),
                                               bisect3Storage.GetEndXEndYEndZValue1(),
                                               bisect3Storage.GetEndXEndYEndZValue2());

    node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
    node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_DETAIL_H
