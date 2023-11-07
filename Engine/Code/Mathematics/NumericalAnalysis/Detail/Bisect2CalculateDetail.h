///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 09:22)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_DETAIL_H

#include "Bisect2Calculate.h"
#include "Bisect2Node.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect2.h"
#include "Mathematics/NumericalAnalysis/Bisect2Root.h"

template <typename Real>
Mathematics::Bisect2Calculate<Real>::Bisect2Calculate(const Bisect2& bisect, Real beginPointX, Real beginPointY, Real endPointX, Real endPointY)
    : bisect2{ bisect }, level{ 0 }, bisect2Root{ std::make_shared<Bisect2Root>() }, bisect2Storage{ bisect }, graph{}
{
    Calculate(beginPointX, beginPointY, endPointX, endPointY);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Bisect2Calculate<Real>::Calculate(Real beginPointX, Real beginPointY, Real endPointX, Real endPointY)
{
    MATHEMATICS_ASSERTION_1(beginPointX <= endPointX, "起点的X值比终点的X值大。");
    MATHEMATICS_ASSERTION_1(beginPointY <= endPointY, "起点的Y值比终点的Y值大。");

    // 测试的四个角的值。
    if (bisect2Storage.TestFourCornerValues(beginPointX, beginPointY, endPointX, endPointY))
    {
        bisect2Root = bisect2Storage.GetBisect2Root();

        return;
    }

    // 构建初始四边形。

    // 增加 N00。
    graph = std::make_shared<Bisect2Node>(beginPointX, beginPointY, bisect2Storage.GetBeginXAndBeginYValue0(), bisect2Storage.GetBeginXAndBeginYValue1());

    // 增加 N10。
    graph->AddXNextNode(endPointX, beginPointY, bisect2Storage.GetEndXAndBeginYValue0(), bisect2Storage.GetEndXAndBeginYValue1());

    // 增加 N01。
    graph->AddYNextNode(beginPointX, endPointY, bisect2Storage.GetBeginXAndEndYValue0(), bisect2Storage.GetBeginXAndEndYValue1());

    // 增加 N11。
    graph->GetXNext()->AddYNextNode(endPointX, endPointY, bisect2Storage.GetEndXAndEndYValue0(), bisect2Storage.GetEndXAndEndYValue1());
    graph->GetYNext()->AddXNextNode(graph->GetXNext()->GetYNext());

    if (const auto result = BisectRecurse(graph);
        result)
    {
        bisect2Root = bisect2Storage.GetBisect2Root();
    }

    // 将剩下的四边形从m_Graph中移除。
    graph.reset();
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Bisect2Calculate<Real>::IsValid() const noexcept
{
    if (bisect2Root != nullptr && graph == nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::Bisect2Calculate<Real>::Bisect2Root Mathematics::Bisect2Calculate<Real>::GetRoot() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return *bisect2Root;
}

template <typename Real>
bool Mathematics::Bisect2Calculate<Real>::BisectRecurse(const Bisect2NodeSharedPtr& node)
{
    if (node == nullptr)
    {
        return false;
    }

    if (++level == bisect2.GetMaxLevel())
    {
        // 递归超出了次数，返回一个中间值。
        --level;
        bisect2Root = std::make_shared<Bisect2Root>(bisect2Storage.GetMidpointX(), bisect2Storage.GetMidpointY(), BisectRootType::Unknown);

        return false;
    }

    // 可优化：在某个区间无解时快速退出，而不仅仅判断边界点具有相同的符号。
    if (node->IsFunctionResult0SameSign() || node->IsFunctionResult1SameSign())
    {
        // FirstFunction具有相同的符号在边界点。
        // 或者GecondFunction具有相同的符号在边界点。

        // 方程在这个区间无解
        --level;

        return false;
    }

    // 二等分四边形。
    bisect2Storage.SetStorageValue(node);

    if (bisect2Storage.TestEdgeValues())
    {
        return true;
    }

    // 将四边形分成四个四边形进行递归搜索。

    // 构建左上角的四边形

    // 原左上角点
    auto leftUpper = std::make_shared<Bisect2Node>(bisect2Storage.GetBeginPointX(),
                                                   bisect2Storage.GetBeginPointY(),
                                                   bisect2Storage.GetBeginXAndBeginYValue0(),
                                                   bisect2Storage.GetBeginXAndBeginYValue1());

    // 顶部的平分线
    leftUpper->AddXNextNode(bisect2Storage.GetMidpointX(),
                            bisect2Storage.GetBeginPointY(),
                            bisect2Storage.GetMidXAndBeginYValue0(),
                            bisect2Storage.GetMidXAndBeginYValue1());

    // 左边的平分线
    leftUpper->AddYNextNode(bisect2Storage.GetBeginPointX(),
                            bisect2Storage.GetMidpointY(),
                            bisect2Storage.GetBeginXAndMidYValue0(),
                            bisect2Storage.GetBeginXAndMidYValue1());

    // 中间的平分线
    leftUpper->GetXNext()->AddYNextNode(bisect2Storage.GetMidpointX(),
                                        bisect2Storage.GetMidpointY(),
                                        bisect2Storage.GetMidXAndMidYValue0(),
                                        bisect2Storage.GetMidXAndMidYValue1());

    leftUpper->GetYNext()->AddXNextNode(leftUpper->GetXNext()->GetYNext());

    // 构建右上角的四边形

    // 顶部的平分线
    auto rightUpper = std::make_shared<Bisect2Node>(bisect2Storage.GetMidpointX(),
                                                    bisect2Storage.GetBeginPointY(),
                                                    bisect2Storage.GetMidXAndBeginYValue0(),
                                                    bisect2Storage.GetMidXAndBeginYValue1());

    // 原右上角点
    rightUpper->AddXNextNode(bisect2Storage.GetEndPointX(),
                             bisect2Storage.GetBeginPointY(),
                             bisect2Storage.GetEndXAndBeginYValue0(),
                             bisect2Storage.GetEndXAndBeginYValue1());

    // 中间的平分线
    rightUpper->AddYNextNode(bisect2Storage.GetMidpointX(),
                             bisect2Storage.GetMidpointY(),
                             bisect2Storage.GetMidXAndMidYValue0(),
                             bisect2Storage.GetMidXAndMidYValue1());

    // 右边的平分线
    rightUpper->GetXNext()->AddYNextNode(bisect2Storage.GetEndPointX(),
                                         bisect2Storage.GetMidpointY(),
                                         bisect2Storage.GetEndXAndMidYValue0(),
                                         bisect2Storage.GetEndXAndMidYValue1());

    rightUpper->GetYNext()->AddXNextNode(rightUpper->GetXNext()->GetYNext());

    // 构建左下角的四边形

    // 左边的平分线
    auto leftLower = std::make_shared<Bisect2Node>(bisect2Storage.GetBeginPointX(),
                                                   bisect2Storage.GetMidpointY(),
                                                   bisect2Storage.GetBeginXAndMidYValue0(),
                                                   bisect2Storage.GetBeginXAndMidYValue1());

    // 中间的平分线
    leftLower->AddXNextNode(bisect2Storage.GetMidpointX(),
                            bisect2Storage.GetMidpointY(),
                            bisect2Storage.GetMidXAndMidYValue0(),
                            bisect2Storage.GetMidXAndMidYValue1());

    // 原左下角点
    leftLower->AddYNextNode(bisect2Storage.GetBeginPointX(),
                            bisect2Storage.GetEndPointY(),
                            bisect2Storage.GetBeginXAndEndYValue0(),
                            bisect2Storage.GetBeginXAndEndYValue1());

    // 底部的平分线
    leftLower->GetXNext()->AddYNextNode(bisect2Storage.GetMidpointX(),
                                        bisect2Storage.GetEndPointY(),
                                        bisect2Storage.GetMidXAndEndYValue0(),
                                        bisect2Storage.GetMidXAndEndYValue1());

    leftLower->GetYNext()->AddXNextNode(leftLower->GetXNext()->GetYNext());

    // 构建右下角的四边形

    // 中间的平分线
    auto rightLower = std::make_shared<Bisect2Node>(bisect2Storage.GetMidpointX(),
                                                    bisect2Storage.GetMidpointY(),
                                                    bisect2Storage.GetMidXAndMidYValue0(),
                                                    bisect2Storage.GetMidXAndMidYValue1());

    // 右边的平分线
    rightLower->AddXNextNode(bisect2Storage.GetEndPointX(),
                             bisect2Storage.GetMidpointY(),
                             bisect2Storage.GetEndXAndMidYValue0(),
                             bisect2Storage.GetEndXAndMidYValue1());

    // 底部的平分线
    rightLower->AddYNextNode(bisect2Storage.GetMidpointX(),
                             bisect2Storage.GetEndPointY(),
                             bisect2Storage.GetMidXAndEndYValue0(),
                             bisect2Storage.GetMidXAndEndYValue1());

    // 原右下角点
    rightLower->GetXNext()->AddYNextNode(bisect2Storage.GetMidpointX(),
                                         bisect2Storage.GetEndPointY(),
                                         bisect2Storage.GetMidXAndEndYValue0(),
                                         bisect2Storage.GetMidXAndEndYValue1());

    rightLower->GetYNext()->AddXNextNode(rightLower->GetXNext()->GetYNext());

    // 应该先构造四个四边形再进行递归，因为递归会修改m_Bisect2Storage里的值。
    // 搜索子四边形的根。
    const auto result = BisectRecurse(leftUpper) || BisectRecurse(rightUpper) || BisectRecurse(leftLower) || BisectRecurse(rightLower);

    // 整个子四边形检查失败，删除添加的节点。
    --level;

    return result;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_DETAIL_H
