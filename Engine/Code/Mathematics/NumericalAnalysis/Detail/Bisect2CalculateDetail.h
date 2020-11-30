///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/19 16:18)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_DETAIL_H

#include "Bisect2Calculate.h"
#include "Bisect2Node.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect2Calculate<Real>::Bisect2Calculate(const Bisect2& bisect, Real beginPointX, Real beginPointY, Real endPointX, Real endPointY)
    : m_Bisect2{ bisect }, m_Level{ 0 }, m_Bisect2Root{ std::make_shared<Bisect2Root>() }, m_Bisect2Storage{ bisect }, m_Graph{}
{
    Calculate(beginPointX, beginPointY, endPointX, endPointY);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::Bisect2Calculate<Real>::Calculate(Real beginPointX, Real beginPointY, Real endPointX, Real endPointY)
{
    MATHEMATICS_ASSERTION_1(beginPointX <= endPointX, "����Xֵ���յ��Xֵ��");
    MATHEMATICS_ASSERTION_1(beginPointY <= endPointY, "����Yֵ���յ��Yֵ��");

    // ���Ե��ĸ��ǵ�ֵ��
    if (m_Bisect2Storage.TestFourCornerValues(beginPointX, beginPointY, endPointX, endPointY))
    {
        m_Bisect2Root = m_Bisect2Storage.GetBisect2Root();

        return;
    }

    // ������ʼ�ı��Ρ�

    // ���� N00��
    m_Graph = std::make_shared<Bisect2Node>(beginPointX, beginPointY, m_Bisect2Storage.GetBeginXAndBeginYValue0(), m_Bisect2Storage.GetBeginXAndBeginYValue1());

    // ���� N10��
    m_Graph->AddXNextNode(endPointX, beginPointY, m_Bisect2Storage.GetEndXAndBeginYValue0(), m_Bisect2Storage.GetEndXAndBeginYValue1());

    // ���� N01��
    m_Graph->AddYNextNode(beginPointX, endPointY, m_Bisect2Storage.GetBeginXAndEndYValue0(), m_Bisect2Storage.GetBeginXAndEndYValue1());

    // ���� N11��
    m_Graph->GetXNext()->AddYNextNode(endPointX, endPointY, m_Bisect2Storage.GetEndXAndEndYValue0(), m_Bisect2Storage.GetEndXAndEndYValue1());
    m_Graph->GetYNext()->AddXNextNode(m_Graph->GetXNext()->GetYNext());

    const auto result = BisectRecurse(m_Graph);

    if (result)
    {
        m_Bisect2Root = m_Bisect2Storage.GetBisect2Root();
    }

    // ��ʣ�µ��ı��δ�m_Graph���Ƴ���
    m_Graph.reset();
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect2Calculate<Real>::IsValid() const noexcept
{
    if (m_Bisect2Root != nullptr && m_Graph == nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Bisect2Calculate<Real>::Bisect2Root Mathematics::Bisect2Calculate<Real>::GetRoot() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return *m_Bisect2Root;
}

// private
template <typename Real>
bool Mathematics::Bisect2Calculate<Real>::BisectRecurse(const Bisect2NodeSharedPtr& node)
{
    if (node == nullptr)
    {
        return false;
    }

    if (++m_Level == m_Bisect2.GetMaxLevel())
    {
        // �ݹ鳬���˴���������һ���м�ֵ��
        --m_Level;
        m_Bisect2Root = std::make_shared<Bisect2Root>(m_Bisect2Storage.GetMidpointX(), m_Bisect2Storage.GetMidpointY(), BisectRootType::Unknown);

        return false;
    }

    // ���Ż�����ĳ�������޽�ʱ�����˳������������жϱ߽�������ͬ�ķ��š�
    if (node->IsFunctionResult0SameSign() || node->IsFunctionResult1SameSign())
    {
        // FirstFunction������ͬ�ķ����ڱ߽�㡣
        // ����GecondFunction������ͬ�ķ����ڱ߽�㡣

        // ��������������޽�
        --m_Level;

        return false;
    }

    // ���ȷ��ı��Ρ�
    m_Bisect2Storage.SetStorageValue(node);

    if (m_Bisect2Storage.TestEdgeValues())
    {
        return true;
    }

    // ���ı��ηֳ��ĸ��ı��ν��еݹ�������

    // �������Ͻǵ��ı���

    // ԭ���Ͻǵ�
    auto leftUpper = std::make_shared<Bisect2Node>(m_Bisect2Storage.GetBeginPointX(), m_Bisect2Storage.GetBeginPointY(),
                                                   m_Bisect2Storage.GetBeginXAndBeginYValue0(), m_Bisect2Storage.GetBeginXAndBeginYValue1());

    // ������ƽ����
    leftUpper->AddXNextNode(m_Bisect2Storage.GetMidpointX(),
                            m_Bisect2Storage.GetBeginPointY(),
                            m_Bisect2Storage.GetMidXAndBeginYValue0(),
                            m_Bisect2Storage.GetMidXAndBeginYValue1());

    // ��ߵ�ƽ����
    leftUpper->AddYNextNode(m_Bisect2Storage.GetBeginPointX(),
                            m_Bisect2Storage.GetMidpointY(),
                            m_Bisect2Storage.GetBeginXAndMidYValue0(),
                            m_Bisect2Storage.GetBeginXAndMidYValue1());

    // �м��ƽ����
    leftUpper->GetXNext()->AddYNextNode(m_Bisect2Storage.GetMidpointX(),
                                        m_Bisect2Storage.GetMidpointY(),
                                        m_Bisect2Storage.GetMidXAndMidYValue0(),
                                        m_Bisect2Storage.GetMidXAndMidYValue1());

    leftUpper->GetYNext()->AddXNextNode(leftUpper->GetXNext()->GetYNext());

    // �������Ͻǵ��ı���

    // ������ƽ����
    auto rightUpper = std::make_shared<Bisect2Node>(m_Bisect2Storage.GetMidpointX(), m_Bisect2Storage.GetBeginPointY(),
                                                    m_Bisect2Storage.GetMidXAndBeginYValue0(), m_Bisect2Storage.GetMidXAndBeginYValue1());

    // ԭ���Ͻǵ�
    rightUpper->AddXNextNode(m_Bisect2Storage.GetEndPointX(),
                             m_Bisect2Storage.GetBeginPointY(),
                             m_Bisect2Storage.GetEndXAndBeginYValue0(),
                             m_Bisect2Storage.GetEndXAndBeginYValue1());

    // �м��ƽ����
    rightUpper->AddYNextNode(m_Bisect2Storage.GetMidpointX(),
                             m_Bisect2Storage.GetMidpointY(),
                             m_Bisect2Storage.GetMidXAndMidYValue0(),
                             m_Bisect2Storage.GetMidXAndMidYValue1());

    // �ұߵ�ƽ����
    rightUpper->GetXNext()->AddYNextNode(m_Bisect2Storage.GetEndPointX(),
                                         m_Bisect2Storage.GetMidpointY(),
                                         m_Bisect2Storage.GetEndXAndMidYValue0(),
                                         m_Bisect2Storage.GetEndXAndMidYValue1());

    rightUpper->GetYNext()->AddXNextNode(rightUpper->GetXNext()->GetYNext());

    // �������½ǵ��ı���

    // ��ߵ�ƽ����
    auto leftLower = std::make_shared<Bisect2Node>(m_Bisect2Storage.GetBeginPointX(), m_Bisect2Storage.GetMidpointY(),
                                                   m_Bisect2Storage.GetBeginXAndMidYValue0(), m_Bisect2Storage.GetBeginXAndMidYValue1());

    // �м��ƽ����
    leftLower->AddXNextNode(m_Bisect2Storage.GetMidpointX(),
                            m_Bisect2Storage.GetMidpointY(),
                            m_Bisect2Storage.GetMidXAndMidYValue0(),
                            m_Bisect2Storage.GetMidXAndMidYValue1());

    // ԭ���½ǵ�
    leftLower->AddYNextNode(m_Bisect2Storage.GetBeginPointX(),
                            m_Bisect2Storage.GetEndPointY(),
                            m_Bisect2Storage.GetBeginXAndEndYValue0(),
                            m_Bisect2Storage.GetBeginXAndEndYValue1());

    // �ײ���ƽ����
    leftLower->GetXNext()->AddYNextNode(m_Bisect2Storage.GetMidpointX(),
                                        m_Bisect2Storage.GetEndPointY(),
                                        m_Bisect2Storage.GetMidXAndEndYValue0(),
                                        m_Bisect2Storage.GetMidXAndEndYValue1());

    leftLower->GetYNext()->AddXNextNode(leftLower->GetXNext()->GetYNext());

    // �������½ǵ��ı���

    // �м��ƽ����
    auto rightLower = std::make_shared<Bisect2Node>(m_Bisect2Storage.GetMidpointX(), m_Bisect2Storage.GetMidpointY(),
                                                    m_Bisect2Storage.GetMidXAndMidYValue0(), m_Bisect2Storage.GetMidXAndMidYValue1());

    // �ұߵ�ƽ����
    rightLower->AddXNextNode(m_Bisect2Storage.GetEndPointX(),
                             m_Bisect2Storage.GetMidpointY(),
                             m_Bisect2Storage.GetEndXAndMidYValue0(),
                             m_Bisect2Storage.GetEndXAndMidYValue1());

    // �ײ���ƽ����
    rightLower->AddYNextNode(m_Bisect2Storage.GetMidpointX(),
                             m_Bisect2Storage.GetEndPointY(),
                             m_Bisect2Storage.GetMidXAndEndYValue0(),
                             m_Bisect2Storage.GetMidXAndEndYValue1());

    // ԭ���½ǵ�
    rightLower->GetXNext()->AddYNextNode(m_Bisect2Storage.GetMidpointX(),
                                         m_Bisect2Storage.GetEndPointY(),
                                         m_Bisect2Storage.GetMidXAndEndYValue0(),
                                         m_Bisect2Storage.GetMidXAndEndYValue1());

    rightLower->GetYNext()->AddXNextNode(rightLower->GetXNext()->GetYNext());

    // Ӧ���ȹ����ĸ��ı����ٽ��еݹ飬��Ϊ�ݹ���޸�m_Bisect2Storage���ֵ��
    // �������ı��εĸ���
    const auto result = BisectRecurse(leftUpper) || BisectRecurse(rightUpper) || BisectRecurse(leftLower) || BisectRecurse(rightLower);

    // �������ı��μ��ʧ�ܣ�ɾ����ӵĽڵ㡣
    --m_Level;

    return result;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_DETAIL_H
