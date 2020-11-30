///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/20 16:15)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_DETAIL_H

#include "Bisect3Calculate.h"
#include "Bisect3Node.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect3.h"

template <typename Real>
Mathematics::Bisect3Calculate<Real>::Bisect3Calculate(const Bisect3& bisect, Real beginPointX, Real beginPointY, Real beginPointZ,
                                                      Real endPointX, Real endPointY, Real endPointZ)
    : m_Bisect3{ bisect },
      m_Level{ 0 },
      m_Bisect3Root(std::make_shared<Bisect3Root>()),
      m_Bisect3Storage{ bisect },
      m_Graph{}
{
    Calculate(beginPointX, beginPointY, beginPointZ, endPointX, endPointY, endPointZ);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::Bisect3Calculate<Real>::Calculate(Real beginPointX, Real beginPointY, Real beginPointZ,
                                                    Real endPointX, Real endPointY, Real endPointZ)
{
    MATHEMATICS_ASSERTION_2(beginPointX <= endPointX, "起点的X值比终点的X值大。");
    MATHEMATICS_ASSERTION_2(beginPointY <= endPointY, "起点的Y值比终点的Y值大。");
    MATHEMATICS_ASSERTION_2(beginPointZ <= endPointZ, "起点的Z值比终点的Z值大。");

    // 测试的八个角的值。
    if (m_Bisect3Storage.TestEightCornerValues(beginPointX, beginPointY, beginPointZ, endPointX, endPointY, endPointZ))
    {
        m_Bisect3Root = m_Bisect3Storage.GetBisect3Root();

        return;
    }

    // 构建初始八边形

    // 增加 N000。
    m_Graph = std::make_shared<Bisect3Node>(beginPointX, beginPointY, beginPointZ,
                                            m_Bisect3Storage.GetBeginXBeginYBeginZValue0(),
                                            m_Bisect3Storage.GetBeginXBeginYBeginZValue1(),
                                            m_Bisect3Storage.GetBeginXBeginYBeginZValue2());

    // 增加 N100。
    m_Graph->AddXNextNode(endPointX, beginPointY, beginPointZ,
                          m_Bisect3Storage.GetEndXBeginYBeginZValue0(),
                          m_Bisect3Storage.GetEndXBeginYBeginZValue1(),
                          m_Bisect3Storage.GetEndXBeginYBeginZValue2());

    // 增加 N010。
    m_Graph->AddYNextNode(beginPointX, endPointY, beginPointZ,
                          m_Bisect3Storage.GetBeginXEndYBeginZValue0(),
                          m_Bisect3Storage.GetBeginXEndYBeginZValue1(),
                          m_Bisect3Storage.GetBeginXEndYBeginZValue2());

    // 增加 N110。
    m_Graph->GetXNext()->AddYNextNode(endPointX, endPointY, beginPointZ,
                                      m_Bisect3Storage.GetEndXEndYBeginZValue0(),
                                      m_Bisect3Storage.GetEndXEndYBeginZValue1(),
                                      m_Bisect3Storage.GetEndXEndYBeginZValue2());

    m_Graph->GetYNext()->AddXNextNode(m_Graph->GetXNext()->GetYNext());

    // 增加 N001。
    m_Graph->AddZNextNode(beginPointX, beginPointY, endPointZ,
                          m_Bisect3Storage.GetBeginXBeginYEndZValue0(),
                          m_Bisect3Storage.GetBeginXBeginYEndZValue1(),
                          m_Bisect3Storage.GetBeginXBeginYEndZValue2());

    // 增加 N101。
    m_Graph->GetXNext()->AddZNextNode(endPointX, beginPointY, endPointZ,
                                      m_Bisect3Storage.GetEndXBeginYEndZValue0(),
                                      m_Bisect3Storage.GetEndXBeginYEndZValue1(),
                                      m_Bisect3Storage.GetEndXBeginYEndZValue2());

    m_Graph->GetZNext()->AddXNextNode(m_Graph->GetXNext()->GetZNext());

    // 增加 N011。
    m_Graph->GetYNext()->AddZNextNode(beginPointX, endPointY, endPointZ,
                                      m_Bisect3Storage.GetBeginXEndYEndZValue0(),
                                      m_Bisect3Storage.GetBeginXEndYEndZValue1(),
                                      m_Bisect3Storage.GetBeginXEndYEndZValue2());

    m_Graph->GetZNext()->AddYNextNode(m_Graph->GetYNext()->GetZNext());

    // 增加 N111。
    m_Graph->GetXNext()->GetYNext()->AddZNextNode(endPointX, endPointY, endPointZ,
                                                  m_Bisect3Storage.GetEndXEndYEndZValue0(),
                                                  m_Bisect3Storage.GetEndXEndYEndZValue1(),
                                                  m_Bisect3Storage.GetEndXEndYEndZValue2());

    m_Graph->GetYNext()->GetXNext()->AddZNextNode(m_Graph->GetXNext()->GetYNext()->GetZNext());
    m_Graph->GetXNext()->GetZNext()->AddYNextNode(m_Graph->GetXNext()->GetYNext()->GetZNext());

    const auto result = BisectRecurse(m_Graph);

    if (result)
    {
        m_Bisect3Root = m_Bisect3Storage.GetBisect3Root();
    }

    // 将剩下的四边形从m_Graph中移除。
    m_Graph.reset();
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect3Calculate<Real>::IsValid() const noexcept
{
    if (m_Bisect3Root != nullptr && m_Graph == nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Bisect3Calculate<Real>::Bisect3Root Mathematics::Bisect3Calculate<Real>::GetRoot() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return *m_Bisect3Root;
}

// private
template <typename Real>
bool Mathematics::Bisect3Calculate<Real>::BisectRecurse(const Bisect3NodeSharedPtr& node)
{
    if (node == nullptr)
    {
        return false;
    }

    if (++m_Level == m_Bisect3.GetMaxLevel())
    {
        // 递归超出了次数，返回一个中间值。
        --m_Level;
        m_Bisect3Root = std::make_shared<Bisect3Root>(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetMidpointZ(), BisectRootType::Unknown);

        return false;
    }

    if (node->IsFunctionResult0SameSign() || node->IsFunctionResult1SameSign() || node->IsFunctionResult2SameSign())
    {
        // FirstFunction具有相同的符号在边界点。
        // 或者GecondFunction具有相同的符号在边界点。
        // 或者ThirdFunction具有相同的符号在边界点。

        // 方程在这个区间无解
        --m_Level;

        return false;
    }

    // 二等分八边形。
    m_Bisect3Storage.SetStorageValue(node);

    if (m_Bisect3Storage.TestEdgeValues())
    {
        return true;
    }

    // 将立方体分成八个立方体进行递归搜索。

    // 构建左下内的立方体

    // 原左下内点
    auto leftLowerInside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetBeginPointZ(),
                                                         m_Bisect3Storage.GetBeginXBeginYBeginZValue0(), m_Bisect3Storage.GetBeginXBeginYBeginZValue1(), m_Bisect3Storage.GetBeginXBeginYBeginZValue2());

    BuildLeftLowerInside(leftLowerInside);

    // 构建右下内的立方体

    // 边 000, 100
    auto rightLowerInside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetBeginPointZ(),
                                                          m_Bisect3Storage.GetMidXBeginYBeginZValue0(), m_Bisect3Storage.GetMidXBeginYBeginZValue1(), m_Bisect3Storage.GetMidXBeginYBeginZValue2());

    BuildRightLowerInside(rightLowerInside);

    // 构建左上内的立方体

    // 边 000, 010
    auto leftUpperInside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetBeginPointZ(),
                                                         m_Bisect3Storage.GetBeginXMidYBeginZValue0(), m_Bisect3Storage.GetBeginXMidYBeginZValue1(), m_Bisect3Storage.GetBeginXMidYBeginZValue2());

    BuildLeftUpperInside(leftUpperInside);

    // 构建右上内的立方体

    // 面 000, 100, 110, 010
    auto rightUpperInside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetBeginPointZ(),
                                                          m_Bisect3Storage.GetMidXMidYBeginZValue0(), m_Bisect3Storage.GetMidXMidYBeginZValue1(), m_Bisect3Storage.GetMidXMidYBeginZValue2());

    BuildRightUpperInside(rightUpperInside);

    // 构建左下外的立方体

    // 边 000, 001
    auto leftLowerOutside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetMidpointZ(),
                                                          m_Bisect3Storage.GetBeginXBeginYMidZValue0(), m_Bisect3Storage.GetBeginXBeginYMidZValue1(), m_Bisect3Storage.GetBeginXBeginYMidZValue2());

    BuildLeftLowerOutside(leftLowerOutside);

    // 构建右下外的立方体

    // 面 000, 100, 001, 101
    auto rightLowerOutside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetMidpointZ(),
                                                           m_Bisect3Storage.GetMidXBeginYMidZValue0(), m_Bisect3Storage.GetMidXBeginYMidZValue1(), m_Bisect3Storage.GetMidXBeginYMidZValue2());

    BuildRightLowerOutside(rightLowerOutside);

    // 构建左上外的立方体

    // 面 000, 010, 011, 001
    auto leftUpperOutside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetMidpointZ(),
                                                          m_Bisect3Storage.GetBeginXMidYMidZValue0(), m_Bisect3Storage.GetBeginXMidYMidZValue1(), m_Bisect3Storage.GetBeginXMidYMidZValue2());

    BuildLeftUpperOutside(leftUpperOutside);

    // 构建右上外的立方体

    // 中心
    auto rightUpperOutside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetMidpointZ(),
                                                           m_Bisect3Storage.GetMidXMidYMidZValue0(), m_Bisect3Storage.GetMidXMidYMidZValue1(), m_Bisect3Storage.GetMidXMidYMidZValue2());

    BuildRightUpperOutside(rightUpperOutside);

    // 搜索子立方体的根。
    const auto result = BisectRecurse(leftLowerInside) || BisectRecurse(rightLowerInside) ||
                        BisectRecurse(leftUpperInside) || BisectRecurse(rightUpperInside) ||
                        BisectRecurse(leftLowerOutside) || BisectRecurse(rightLowerOutside) ||
                        BisectRecurse(leftUpperOutside) || BisectRecurse(rightUpperOutside);

    // 整个子八边形检查失败，删除添加的节点。

    --m_Level;

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
    node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetMidXBeginYBeginZValue0(),
                       m_Bisect3Storage.GetMidXBeginYBeginZValue1(),
                       m_Bisect3Storage.GetMidXBeginYBeginZValue2());

    // 边 000, 010
    node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetBeginXMidYBeginZValue0(),
                       m_Bisect3Storage.GetBeginXMidYBeginZValue1(),
                       m_Bisect3Storage.GetBeginXMidYBeginZValue2());

    // 面 000, 100, 110, 010。
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetBeginPointZ(),
                                   m_Bisect3Storage.GetMidXMidYBeginZValue0(),
                                   m_Bisect3Storage.GetMidXMidYBeginZValue1(),
                                   m_Bisect3Storage.GetMidXMidYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 边 000, 001。
    node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetBeginXBeginYMidZValue0(),
                       m_Bisect3Storage.GetBeginXBeginYMidZValue1(),
                       m_Bisect3Storage.GetBeginXBeginYMidZValue2());

    // 面 000, 100, 001, 101。
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetBeginPointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetMidXBeginYMidZValue0(),
                                   m_Bisect3Storage.GetMidXBeginYMidZValue1(),
                                   m_Bisect3Storage.GetMidXBeginYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 面 000, 010, 011, 001。
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetBeginXMidYMidZValue0(),
                                   m_Bisect3Storage.GetBeginXMidYMidZValue1(),
                                   m_Bisect3Storage.GetBeginXMidYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 中心。
    node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                               m_Bisect3Storage.GetMidpointY(),
                                               m_Bisect3Storage.GetMidpointZ(),
                                               m_Bisect3Storage.GetMidXMidYMidZValue0(),
                                               m_Bisect3Storage.GetMidXMidYMidZValue1(),
                                               m_Bisect3Storage.GetMidXMidYMidZValue2());

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
    node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetEndXBeginYBeginZValue0(),
                       m_Bisect3Storage.GetEndXBeginYBeginZValue1(),
                       m_Bisect3Storage.GetEndXBeginYBeginZValue2());

    // 面 000, 100, 110, 010
    node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetMidXMidYBeginZValue0(),
                       m_Bisect3Storage.GetMidXMidYBeginZValue1(),
                       m_Bisect3Storage.GetMidXMidYBeginZValue2());

    // 边 100, 110
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetBeginPointZ(),
                                   m_Bisect3Storage.GetEndXMidYBeginZValue0(),
                                   m_Bisect3Storage.GetEndXMidYBeginZValue1(),
                                   m_Bisect3Storage.GetEndXMidYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 面 000, 100, 001, 101
    node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue0(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue1(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue2());

    // 边 100, 101
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetBeginPointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetEndXBeginYMidZValue0(),
                                   m_Bisect3Storage.GetEndXBeginYMidZValue1(),
                                   m_Bisect3Storage.GetEndXBeginYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 中心。
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue0(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue1(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 面 110, 100, 101, 111
    node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
                                               m_Bisect3Storage.GetMidpointY(),
                                               m_Bisect3Storage.GetMidpointZ(),
                                               m_Bisect3Storage.GetEndXMidYMidZValue0(),
                                               m_Bisect3Storage.GetEndXMidYMidZValue1(),
                                               m_Bisect3Storage.GetEndXMidYMidZValue2());

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
    node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetMidXMidYBeginZValue0(),
                       m_Bisect3Storage.GetMidXMidYBeginZValue1(),
                       m_Bisect3Storage.GetMidXMidYBeginZValue2());

    // 原左上内点
    node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetEndPointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetBeginXEndYBeginZValue0(),
                       m_Bisect3Storage.GetBeginXEndYBeginZValue1(),
                       m_Bisect3Storage.GetBeginXEndYBeginZValue2());

    // 边 110, 010。
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetBeginPointZ(),
                                   m_Bisect3Storage.GetMidXEndYBeginZValue0(),
                                   m_Bisect3Storage.GetMidXEndYBeginZValue1(),
                                   m_Bisect3Storage.GetMidXEndYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 面  000，001，011，010
    node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetBeginXMidYMidZValue0(),
                       m_Bisect3Storage.GetBeginXMidYMidZValue1(),
                       m_Bisect3Storage.GetBeginXMidYMidZValue2());

    // 中心
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue0(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue1(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 边 011,010
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetBeginXEndYMidZValue0(),
                                   m_Bisect3Storage.GetBeginXEndYMidZValue1(),
                                   m_Bisect3Storage.GetBeginXEndYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 面 010,110,111,011
    node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                               m_Bisect3Storage.GetEndPointY(),
                                               m_Bisect3Storage.GetMidpointZ(),
                                               m_Bisect3Storage.GetMidXEndYMidZValue0(),
                                               m_Bisect3Storage.GetMidXEndYMidZValue1(),
                                               m_Bisect3Storage.GetMidXEndYMidZValue2());

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
    node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetEndXMidYBeginZValue0(),
                       m_Bisect3Storage.GetEndXMidYBeginZValue1(),
                       m_Bisect3Storage.GetEndXMidYBeginZValue2());

    // 边 110, 010
    node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetEndPointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetMidXEndYBeginZValue0(),
                       m_Bisect3Storage.GetMidXEndYBeginZValue1(),
                       m_Bisect3Storage.GetMidXEndYBeginZValue2());

    // 原右上内点
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetBeginPointZ(),
                                   m_Bisect3Storage.GetEndXEndYBeginZValue0(),
                                   m_Bisect3Storage.GetEndXEndYBeginZValue1(),
                                   m_Bisect3Storage.GetEndXEndYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 中心
    node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue0(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue1(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue2());

    // 面 100, 110, 111, 101。
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetEndXMidYMidZValue0(),
                                   m_Bisect3Storage.GetEndXMidYMidZValue1(),
                                   m_Bisect3Storage.GetEndXMidYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 面 011,111,110,010
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetMidXEndYMidZValue0(),
                                   m_Bisect3Storage.GetMidXEndYMidZValue1(),
                                   m_Bisect3Storage.GetMidXEndYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 边110，111
    node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
                                               m_Bisect3Storage.GetEndPointY(),
                                               m_Bisect3Storage.GetMidpointZ(),
                                               m_Bisect3Storage.GetEndXEndYMidZValue0(),
                                               m_Bisect3Storage.GetEndXEndYMidZValue1(),
                                               m_Bisect3Storage.GetEndXEndYMidZValue2());

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
    node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue0(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue1(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue2());

    // 面 000, 001，011，010
    node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetBeginXMidYMidZValue0(),
                       m_Bisect3Storage.GetBeginXMidYMidZValue1(),
                       m_Bisect3Storage.GetBeginXMidYMidZValue2());

    // 中心
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue0(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue1(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 原左下外点
    node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetEndPointZ(),
                       m_Bisect3Storage.GetBeginXBeginYEndZValue0(),
                       m_Bisect3Storage.GetBeginXBeginYEndZValue1(),
                       m_Bisect3Storage.GetBeginXBeginYEndZValue2());

    // 边001,101
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetBeginPointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetMidXBeginYEndZValue0(),
                                   m_Bisect3Storage.GetMidXBeginYEndZValue1(),
                                   m_Bisect3Storage.GetMidXBeginYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 边001,011
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetBeginXMidYEndZValue0(),
                                   m_Bisect3Storage.GetBeginXMidYEndZValue1(),
                                   m_Bisect3Storage.GetBeginXMidYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 面 001,101,111,011
    node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(),
                                               m_Bisect3Storage.GetEndPointZ(), m_Bisect3Storage.GetMidXMidYEndZValue0(),
                                               m_Bisect3Storage.GetMidXMidYEndZValue1(), m_Bisect3Storage.GetMidXMidYEndZValue2());

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
    node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetEndXBeginYMidZValue0(),
                       m_Bisect3Storage.GetEndXBeginYMidZValue1(),
                       m_Bisect3Storage.GetEndXBeginYMidZValue2());

    // 中心
    node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetMidXMidYMidZValue0(),
                       m_Bisect3Storage.GetMidXMidYMidZValue1(),
                       m_Bisect3Storage.GetMidXMidYMidZValue2());

    // 面100，101，111，110
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetEndXMidYMidZValue0(),
                                   m_Bisect3Storage.GetEndXMidYMidZValue1(),
                                   m_Bisect3Storage.GetEndXMidYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 边001,101
    node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetEndPointZ(),
                       m_Bisect3Storage.GetMidXBeginYEndZValue0(),
                       m_Bisect3Storage.GetMidXBeginYEndZValue1(),
                       m_Bisect3Storage.GetMidXBeginYEndZValue2());

    // 面001,101,111,011
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetBeginPointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetEndXBeginYEndZValue0(),
                                   m_Bisect3Storage.GetEndXBeginYEndZValue1(),
                                   m_Bisect3Storage.GetEndXBeginYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 面001，101，111，011
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetMidXMidYEndZValue0(),
                                   m_Bisect3Storage.GetMidXMidYEndZValue1(),
                                   m_Bisect3Storage.GetMidXMidYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 边101,111
    node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetEndPointZ(),
                                               m_Bisect3Storage.GetEndXMidYEndZValue0(), m_Bisect3Storage.GetEndXMidYEndZValue1(), m_Bisect3Storage.GetEndXMidYEndZValue2());

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
    node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetMidXMidYMidZValue0(),
                       m_Bisect3Storage.GetMidXMidYMidZValue1(),
                       m_Bisect3Storage.GetMidXMidYMidZValue2());

    // 边011,010
    node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetEndPointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetBeginXEndYMidZValue0(),
                       m_Bisect3Storage.GetBeginXEndYMidZValue1(),
                       m_Bisect3Storage.GetBeginXEndYMidZValue2());

    // 面011，010，110，111
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetMidXEndYMidZValue0(),
                                   m_Bisect3Storage.GetMidXEndYMidZValue1(),
                                   m_Bisect3Storage.GetMidXEndYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 边 001,011
    node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetEndPointZ(),
                       m_Bisect3Storage.GetBeginXMidYEndZValue0(),
                       m_Bisect3Storage.GetBeginXMidYEndZValue1(),
                       m_Bisect3Storage.GetBeginXMidYEndZValue2());

    // 面001，101，111，011
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetMidXMidYEndZValue0(),
                                   m_Bisect3Storage.GetMidXMidYEndZValue1(),
                                   m_Bisect3Storage.GetMidXMidYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 原左上外点
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetBeginXEndYEndZValue0(),
                                   m_Bisect3Storage.GetBeginXEndYEndZValue1(),
                                   m_Bisect3Storage.GetBeginXEndYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 边011，111
    node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetEndPointY(), m_Bisect3Storage.GetEndPointZ(),
                                               m_Bisect3Storage.GetMidXEndYEndZValue0(), m_Bisect3Storage.GetMidXEndYEndZValue1(), m_Bisect3Storage.GetMidXEndYEndZValue2());

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
    node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetEndXMidYMidZValue0(),
                       m_Bisect3Storage.GetEndXMidYMidZValue1(),
                       m_Bisect3Storage.GetEndXMidYMidZValue2());

    // 面010，110，111，011
    node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetEndPointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetMidXEndYMidZValue0(),
                       m_Bisect3Storage.GetMidXEndYMidZValue1(),
                       m_Bisect3Storage.GetMidXEndYMidZValue2());

    // 边110,111
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetEndXEndYMidZValue0(),
                                   m_Bisect3Storage.GetEndXEndYMidZValue1(),
                                   m_Bisect3Storage.GetEndXEndYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // 面011，111，101，001
    node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetEndPointZ(),
                       m_Bisect3Storage.GetMidXBeginYEndZValue0(),
                       m_Bisect3Storage.GetMidXBeginYEndZValue1(),
                       m_Bisect3Storage.GetMidXBeginYEndZValue2());

    // 面 100, 110, 100, 101。
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetEndXMidYEndZValue0(),
                                   m_Bisect3Storage.GetEndXMidYEndZValue1(),
                                   m_Bisect3Storage.GetEndXMidYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // 边011，111
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetMidXEndYEndZValue0(),
                                   m_Bisect3Storage.GetMidXEndYEndZValue1(),
                                   m_Bisect3Storage.GetMidXEndYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // 原右上外点
    node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(), m_Bisect3Storage.GetEndPointY(), m_Bisect3Storage.GetEndPointZ(),
                                               m_Bisect3Storage.GetEndXEndYEndZValue0(), m_Bisect3Storage.GetEndXEndYEndZValue1(), m_Bisect3Storage.GetEndXEndYEndZValue2());

    node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
    node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_DETAIL_H
