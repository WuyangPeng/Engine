///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/20 16:15)

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
    MATHEMATICS_ASSERTION_2(beginPointX <= endPointX, "����Xֵ���յ��Xֵ��");
    MATHEMATICS_ASSERTION_2(beginPointY <= endPointY, "����Yֵ���յ��Yֵ��");
    MATHEMATICS_ASSERTION_2(beginPointZ <= endPointZ, "����Zֵ���յ��Zֵ��");

    // ���Եİ˸��ǵ�ֵ��
    if (m_Bisect3Storage.TestEightCornerValues(beginPointX, beginPointY, beginPointZ, endPointX, endPointY, endPointZ))
    {
        m_Bisect3Root = m_Bisect3Storage.GetBisect3Root();

        return;
    }

    // ������ʼ�˱���

    // ���� N000��
    m_Graph = std::make_shared<Bisect3Node>(beginPointX, beginPointY, beginPointZ,
                                            m_Bisect3Storage.GetBeginXBeginYBeginZValue0(),
                                            m_Bisect3Storage.GetBeginXBeginYBeginZValue1(),
                                            m_Bisect3Storage.GetBeginXBeginYBeginZValue2());

    // ���� N100��
    m_Graph->AddXNextNode(endPointX, beginPointY, beginPointZ,
                          m_Bisect3Storage.GetEndXBeginYBeginZValue0(),
                          m_Bisect3Storage.GetEndXBeginYBeginZValue1(),
                          m_Bisect3Storage.GetEndXBeginYBeginZValue2());

    // ���� N010��
    m_Graph->AddYNextNode(beginPointX, endPointY, beginPointZ,
                          m_Bisect3Storage.GetBeginXEndYBeginZValue0(),
                          m_Bisect3Storage.GetBeginXEndYBeginZValue1(),
                          m_Bisect3Storage.GetBeginXEndYBeginZValue2());

    // ���� N110��
    m_Graph->GetXNext()->AddYNextNode(endPointX, endPointY, beginPointZ,
                                      m_Bisect3Storage.GetEndXEndYBeginZValue0(),
                                      m_Bisect3Storage.GetEndXEndYBeginZValue1(),
                                      m_Bisect3Storage.GetEndXEndYBeginZValue2());

    m_Graph->GetYNext()->AddXNextNode(m_Graph->GetXNext()->GetYNext());

    // ���� N001��
    m_Graph->AddZNextNode(beginPointX, beginPointY, endPointZ,
                          m_Bisect3Storage.GetBeginXBeginYEndZValue0(),
                          m_Bisect3Storage.GetBeginXBeginYEndZValue1(),
                          m_Bisect3Storage.GetBeginXBeginYEndZValue2());

    // ���� N101��
    m_Graph->GetXNext()->AddZNextNode(endPointX, beginPointY, endPointZ,
                                      m_Bisect3Storage.GetEndXBeginYEndZValue0(),
                                      m_Bisect3Storage.GetEndXBeginYEndZValue1(),
                                      m_Bisect3Storage.GetEndXBeginYEndZValue2());

    m_Graph->GetZNext()->AddXNextNode(m_Graph->GetXNext()->GetZNext());

    // ���� N011��
    m_Graph->GetYNext()->AddZNextNode(beginPointX, endPointY, endPointZ,
                                      m_Bisect3Storage.GetBeginXEndYEndZValue0(),
                                      m_Bisect3Storage.GetBeginXEndYEndZValue1(),
                                      m_Bisect3Storage.GetBeginXEndYEndZValue2());

    m_Graph->GetZNext()->AddYNextNode(m_Graph->GetYNext()->GetZNext());

    // ���� N111��
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

    // ��ʣ�µ��ı��δ�m_Graph���Ƴ���
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
        // �ݹ鳬���˴���������һ���м�ֵ��
        --m_Level;
        m_Bisect3Root = std::make_shared<Bisect3Root>(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetMidpointZ(), BisectRootType::Unknown);

        return false;
    }

    if (node->IsFunctionResult0SameSign() || node->IsFunctionResult1SameSign() || node->IsFunctionResult2SameSign())
    {
        // FirstFunction������ͬ�ķ����ڱ߽�㡣
        // ����GecondFunction������ͬ�ķ����ڱ߽�㡣
        // ����ThirdFunction������ͬ�ķ����ڱ߽�㡣

        // ��������������޽�
        --m_Level;

        return false;
    }

    // ���ȷְ˱��Ρ�
    m_Bisect3Storage.SetStorageValue(node);

    if (m_Bisect3Storage.TestEdgeValues())
    {
        return true;
    }

    // ��������ֳɰ˸���������еݹ�������

    // ���������ڵ�������

    // ԭ�����ڵ�
    auto leftLowerInside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetBeginPointZ(),
                                                         m_Bisect3Storage.GetBeginXBeginYBeginZValue0(), m_Bisect3Storage.GetBeginXBeginYBeginZValue1(), m_Bisect3Storage.GetBeginXBeginYBeginZValue2());

    BuildLeftLowerInside(leftLowerInside);

    // ���������ڵ�������

    // �� 000, 100
    auto rightLowerInside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetBeginPointZ(),
                                                          m_Bisect3Storage.GetMidXBeginYBeginZValue0(), m_Bisect3Storage.GetMidXBeginYBeginZValue1(), m_Bisect3Storage.GetMidXBeginYBeginZValue2());

    BuildRightLowerInside(rightLowerInside);

    // ���������ڵ�������

    // �� 000, 010
    auto leftUpperInside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetBeginPointZ(),
                                                         m_Bisect3Storage.GetBeginXMidYBeginZValue0(), m_Bisect3Storage.GetBeginXMidYBeginZValue1(), m_Bisect3Storage.GetBeginXMidYBeginZValue2());

    BuildLeftUpperInside(leftUpperInside);

    // ���������ڵ�������

    // �� 000, 100, 110, 010
    auto rightUpperInside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetBeginPointZ(),
                                                          m_Bisect3Storage.GetMidXMidYBeginZValue0(), m_Bisect3Storage.GetMidXMidYBeginZValue1(), m_Bisect3Storage.GetMidXMidYBeginZValue2());

    BuildRightUpperInside(rightUpperInside);

    // �����������������

    // �� 000, 001
    auto leftLowerOutside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetMidpointZ(),
                                                          m_Bisect3Storage.GetBeginXBeginYMidZValue0(), m_Bisect3Storage.GetBeginXBeginYMidZValue1(), m_Bisect3Storage.GetBeginXBeginYMidZValue2());

    BuildLeftLowerOutside(leftLowerOutside);

    // �����������������

    // �� 000, 100, 001, 101
    auto rightLowerOutside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetMidpointZ(),
                                                           m_Bisect3Storage.GetMidXBeginYMidZValue0(), m_Bisect3Storage.GetMidXBeginYMidZValue1(), m_Bisect3Storage.GetMidXBeginYMidZValue2());

    BuildRightLowerOutside(rightLowerOutside);

    // �����������������

    // �� 000, 010, 011, 001
    auto leftUpperOutside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetMidpointZ(),
                                                          m_Bisect3Storage.GetBeginXMidYMidZValue0(), m_Bisect3Storage.GetBeginXMidYMidZValue1(), m_Bisect3Storage.GetBeginXMidYMidZValue2());

    BuildLeftUpperOutside(leftUpperOutside);

    // �����������������

    // ����
    auto rightUpperOutside = std::make_shared<Bisect3Node>(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetMidpointZ(),
                                                           m_Bisect3Storage.GetMidXMidYMidZValue0(), m_Bisect3Storage.GetMidXMidYMidZValue1(), m_Bisect3Storage.GetMidXMidYMidZValue2());

    BuildRightUpperOutside(rightUpperOutside);

    // ������������ĸ���
    const auto result = BisectRecurse(leftLowerInside) || BisectRecurse(rightLowerInside) ||
                        BisectRecurse(leftUpperInside) || BisectRecurse(rightUpperInside) ||
                        BisectRecurse(leftLowerOutside) || BisectRecurse(rightLowerOutside) ||
                        BisectRecurse(leftUpperOutside) || BisectRecurse(rightUpperOutside);

    // �����Ӱ˱��μ��ʧ�ܣ�ɾ����ӵĽڵ㡣

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

    // �� 000, 100
    node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetMidXBeginYBeginZValue0(),
                       m_Bisect3Storage.GetMidXBeginYBeginZValue1(),
                       m_Bisect3Storage.GetMidXBeginYBeginZValue2());

    // �� 000, 010
    node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetBeginXMidYBeginZValue0(),
                       m_Bisect3Storage.GetBeginXMidYBeginZValue1(),
                       m_Bisect3Storage.GetBeginXMidYBeginZValue2());

    // �� 000, 100, 110, 010��
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetBeginPointZ(),
                                   m_Bisect3Storage.GetMidXMidYBeginZValue0(),
                                   m_Bisect3Storage.GetMidXMidYBeginZValue1(),
                                   m_Bisect3Storage.GetMidXMidYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // �� 000, 001��
    node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetBeginXBeginYMidZValue0(),
                       m_Bisect3Storage.GetBeginXBeginYMidZValue1(),
                       m_Bisect3Storage.GetBeginXBeginYMidZValue2());

    // �� 000, 100, 001, 101��
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetBeginPointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetMidXBeginYMidZValue0(),
                                   m_Bisect3Storage.GetMidXBeginYMidZValue1(),
                                   m_Bisect3Storage.GetMidXBeginYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // �� 000, 010, 011, 001��
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetBeginXMidYMidZValue0(),
                                   m_Bisect3Storage.GetBeginXMidYMidZValue1(),
                                   m_Bisect3Storage.GetBeginXMidYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // ���ġ�
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

    // ԭ�����ڵ�
    node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetEndXBeginYBeginZValue0(),
                       m_Bisect3Storage.GetEndXBeginYBeginZValue1(),
                       m_Bisect3Storage.GetEndXBeginYBeginZValue2());

    // �� 000, 100, 110, 010
    node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetMidXMidYBeginZValue0(),
                       m_Bisect3Storage.GetMidXMidYBeginZValue1(),
                       m_Bisect3Storage.GetMidXMidYBeginZValue2());

    // �� 100, 110
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetBeginPointZ(),
                                   m_Bisect3Storage.GetEndXMidYBeginZValue0(),
                                   m_Bisect3Storage.GetEndXMidYBeginZValue1(),
                                   m_Bisect3Storage.GetEndXMidYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // �� 000, 100, 001, 101
    node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue0(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue1(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue2());

    // �� 100, 101
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetBeginPointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetEndXBeginYMidZValue0(),
                                   m_Bisect3Storage.GetEndXBeginYMidZValue1(),
                                   m_Bisect3Storage.GetEndXBeginYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // ���ġ�
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue0(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue1(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // �� 110, 100, 101, 111
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

    // �� 000, 100��110��010
    node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetMidXMidYBeginZValue0(),
                       m_Bisect3Storage.GetMidXMidYBeginZValue1(),
                       m_Bisect3Storage.GetMidXMidYBeginZValue2());

    // ԭ�����ڵ�
    node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetEndPointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetBeginXEndYBeginZValue0(),
                       m_Bisect3Storage.GetBeginXEndYBeginZValue1(),
                       m_Bisect3Storage.GetBeginXEndYBeginZValue2());

    // �� 110, 010��
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetBeginPointZ(),
                                   m_Bisect3Storage.GetMidXEndYBeginZValue0(),
                                   m_Bisect3Storage.GetMidXEndYBeginZValue1(),
                                   m_Bisect3Storage.GetMidXEndYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // ��  000��001��011��010
    node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetBeginXMidYMidZValue0(),
                       m_Bisect3Storage.GetBeginXMidYMidZValue1(),
                       m_Bisect3Storage.GetBeginXMidYMidZValue2());

    // ����
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue0(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue1(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // �� 011,010
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetBeginXEndYMidZValue0(),
                                   m_Bisect3Storage.GetBeginXEndYMidZValue1(),
                                   m_Bisect3Storage.GetBeginXEndYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // �� 010,110,111,011
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

    // �� 100 110
    node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetEndXMidYBeginZValue0(),
                       m_Bisect3Storage.GetEndXMidYBeginZValue1(),
                       m_Bisect3Storage.GetEndXMidYBeginZValue2());

    // �� 110, 010
    node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetEndPointY(),
                       m_Bisect3Storage.GetBeginPointZ(),
                       m_Bisect3Storage.GetMidXEndYBeginZValue0(),
                       m_Bisect3Storage.GetMidXEndYBeginZValue1(),
                       m_Bisect3Storage.GetMidXEndYBeginZValue2());

    // ԭ�����ڵ�
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetBeginPointZ(),
                                   m_Bisect3Storage.GetEndXEndYBeginZValue0(),
                                   m_Bisect3Storage.GetEndXEndYBeginZValue1(),
                                   m_Bisect3Storage.GetEndXEndYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // ����
    node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue0(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue1(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue2());

    // �� 100, 110, 111, 101��
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetEndXMidYMidZValue0(),
                                   m_Bisect3Storage.GetEndXMidYMidZValue1(),
                                   m_Bisect3Storage.GetEndXMidYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // �� 011,111,110,010
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetMidXEndYMidZValue0(),
                                   m_Bisect3Storage.GetMidXEndYMidZValue1(),
                                   m_Bisect3Storage.GetMidXEndYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // ��110��111
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

    // �� 000, 100��101��001
    node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue0(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue1(),
                       m_Bisect3Storage.GetMidXBeginYMidZValue2());

    // �� 000, 001��011��010
    node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetBeginXMidYMidZValue0(),
                       m_Bisect3Storage.GetBeginXMidYMidZValue1(),
                       m_Bisect3Storage.GetBeginXMidYMidZValue2());

    // ����
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue0(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue1(),
                                   m_Bisect3Storage.GetMidXMidYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // ԭ�������
    node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetEndPointZ(),
                       m_Bisect3Storage.GetBeginXBeginYEndZValue0(),
                       m_Bisect3Storage.GetBeginXBeginYEndZValue1(),
                       m_Bisect3Storage.GetBeginXBeginYEndZValue2());

    // ��001,101
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetBeginPointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetMidXBeginYEndZValue0(),
                                   m_Bisect3Storage.GetMidXBeginYEndZValue1(),
                                   m_Bisect3Storage.GetMidXBeginYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // ��001,011
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetBeginXMidYEndZValue0(),
                                   m_Bisect3Storage.GetBeginXMidYEndZValue1(),
                                   m_Bisect3Storage.GetBeginXMidYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // �� 001,101,111,011
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

    // ��100,101
    node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetEndXBeginYMidZValue0(),
                       m_Bisect3Storage.GetEndXBeginYMidZValue1(),
                       m_Bisect3Storage.GetEndXBeginYMidZValue2());

    // ����
    node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetMidXMidYMidZValue0(),
                       m_Bisect3Storage.GetMidXMidYMidZValue1(),
                       m_Bisect3Storage.GetMidXMidYMidZValue2());

    // ��100��101��111��110
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetEndXMidYMidZValue0(),
                                   m_Bisect3Storage.GetEndXMidYMidZValue1(),
                                   m_Bisect3Storage.GetEndXMidYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // ��001,101
    node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetBeginPointY(),
                       m_Bisect3Storage.GetEndPointZ(),
                       m_Bisect3Storage.GetMidXBeginYEndZValue0(),
                       m_Bisect3Storage.GetMidXBeginYEndZValue1(),
                       m_Bisect3Storage.GetMidXBeginYEndZValue2());

    // ��001,101,111,011
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetBeginPointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetEndXBeginYEndZValue0(),
                                   m_Bisect3Storage.GetEndXBeginYEndZValue1(),
                                   m_Bisect3Storage.GetEndXBeginYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // ��001��101��111��011
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetMidXMidYEndZValue0(),
                                   m_Bisect3Storage.GetMidXMidYEndZValue1(),
                                   m_Bisect3Storage.GetMidXMidYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // ��101,111
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
    // ����
    node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetMidXMidYMidZValue0(),
                       m_Bisect3Storage.GetMidXMidYMidZValue1(),
                       m_Bisect3Storage.GetMidXMidYMidZValue2());

    // ��011,010
    node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetEndPointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetBeginXEndYMidZValue0(),
                       m_Bisect3Storage.GetBeginXEndYMidZValue1(),
                       m_Bisect3Storage.GetBeginXEndYMidZValue2());

    // ��011��010��110��111
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetMidXEndYMidZValue0(),
                                   m_Bisect3Storage.GetMidXEndYMidZValue1(),
                                   m_Bisect3Storage.GetMidXEndYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // �� 001,011
    node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetEndPointZ(),
                       m_Bisect3Storage.GetBeginXMidYEndZValue0(),
                       m_Bisect3Storage.GetBeginXMidYEndZValue1(),
                       m_Bisect3Storage.GetBeginXMidYEndZValue2());

    // ��001��101��111��011
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetMidXMidYEndZValue0(),
                                   m_Bisect3Storage.GetMidXMidYEndZValue1(),
                                   m_Bisect3Storage.GetMidXMidYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // ԭ�������
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetBeginXEndYEndZValue0(),
                                   m_Bisect3Storage.GetBeginXEndYEndZValue1(),
                                   m_Bisect3Storage.GetBeginXEndYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // ��011��111
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

    // ��110,100,101,111
    node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetEndXMidYMidZValue0(),
                       m_Bisect3Storage.GetEndXMidYMidZValue1(),
                       m_Bisect3Storage.GetEndXMidYMidZValue2());

    // ��010��110��111��011
    node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetEndPointY(),
                       m_Bisect3Storage.GetMidpointZ(),
                       m_Bisect3Storage.GetMidXEndYMidZValue0(),
                       m_Bisect3Storage.GetMidXEndYMidZValue1(),
                       m_Bisect3Storage.GetMidXEndYMidZValue2());

    // ��110,111
    node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetMidpointZ(),
                                   m_Bisect3Storage.GetEndXEndYMidZValue0(),
                                   m_Bisect3Storage.GetEndXEndYMidZValue1(),
                                   m_Bisect3Storage.GetEndXEndYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // ��011��111��101��001
    node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                       m_Bisect3Storage.GetMidpointY(),
                       m_Bisect3Storage.GetEndPointZ(),
                       m_Bisect3Storage.GetMidXBeginYEndZValue0(),
                       m_Bisect3Storage.GetMidXBeginYEndZValue1(),
                       m_Bisect3Storage.GetMidXBeginYEndZValue2());

    // �� 100, 110, 100, 101��
    node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
                                   m_Bisect3Storage.GetMidpointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetEndXMidYEndZValue0(),
                                   m_Bisect3Storage.GetEndXMidYEndZValue1(),
                                   m_Bisect3Storage.GetEndXMidYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // ��011��111
    node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
                                   m_Bisect3Storage.GetEndPointY(),
                                   m_Bisect3Storage.GetEndPointZ(),
                                   m_Bisect3Storage.GetMidXEndYEndZValue0(),
                                   m_Bisect3Storage.GetMidXEndYEndZValue1(),
                                   m_Bisect3Storage.GetMidXEndYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // ԭ�������
    node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(), m_Bisect3Storage.GetEndPointY(), m_Bisect3Storage.GetEndPointZ(),
                                               m_Bisect3Storage.GetEndXEndYEndZValue0(), m_Bisect3Storage.GetEndXEndYEndZValue1(), m_Bisect3Storage.GetEndXEndYEndZValue2());

    node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
    node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_DETAIL_H
