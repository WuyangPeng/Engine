///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 09:34)

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
    MATHEMATICS_ASSERTION_2(beginPointX <= endPointX, "����Xֵ���յ��Xֵ��");
    MATHEMATICS_ASSERTION_2(beginPointY <= endPointY, "����Yֵ���յ��Yֵ��");
    MATHEMATICS_ASSERTION_2(beginPointZ <= endPointZ, "����Zֵ���յ��Zֵ��");

    // ���Եİ˸��ǵ�ֵ��
    if (bisect3Storage.TestEightCornerValues(beginPointX, beginPointY, beginPointZ, endPointX, endPointY, endPointZ))
    {
        bisect3Root = bisect3Storage.GetBisect3Root();

        return;
    }

    // ������ʼ�˱���

    // ���� N000��
    graph = std::make_shared<Bisect3Node>(beginPointX,
                                          beginPointY,
                                          beginPointZ,
                                          bisect3Storage.GetBeginXBeginYBeginZValue0(),
                                          bisect3Storage.GetBeginXBeginYBeginZValue1(),
                                          bisect3Storage.GetBeginXBeginYBeginZValue2());

    // ���� N100��
    graph->AddXNextNode(endPointX,
                        beginPointY,
                        beginPointZ,
                        bisect3Storage.GetEndXBeginYBeginZValue0(),
                        bisect3Storage.GetEndXBeginYBeginZValue1(),
                        bisect3Storage.GetEndXBeginYBeginZValue2());

    // ���� N010��
    graph->AddYNextNode(beginPointX,
                        endPointY,
                        beginPointZ,
                        bisect3Storage.GetBeginXEndYBeginZValue0(),
                        bisect3Storage.GetBeginXEndYBeginZValue1(),
                        bisect3Storage.GetBeginXEndYBeginZValue2());

    // ���� N110��
    graph->GetXNext()->AddYNextNode(endPointX,
                                    endPointY,
                                    beginPointZ,
                                    bisect3Storage.GetEndXEndYBeginZValue0(),
                                    bisect3Storage.GetEndXEndYBeginZValue1(),
                                    bisect3Storage.GetEndXEndYBeginZValue2());

    graph->GetYNext()->AddXNextNode(graph->GetXNext()->GetYNext());

    // ���� N001��
    graph->AddZNextNode(beginPointX,
                        beginPointY,
                        endPointZ,
                        bisect3Storage.GetBeginXBeginYEndZValue0(),
                        bisect3Storage.GetBeginXBeginYEndZValue1(),
                        bisect3Storage.GetBeginXBeginYEndZValue2());

    // ���� N101��
    graph->GetXNext()->AddZNextNode(endPointX,
                                    beginPointY,
                                    endPointZ,
                                    bisect3Storage.GetEndXBeginYEndZValue0(),
                                    bisect3Storage.GetEndXBeginYEndZValue1(),
                                    bisect3Storage.GetEndXBeginYEndZValue2());

    graph->GetZNext()->AddXNextNode(graph->GetXNext()->GetZNext());

    // ���� N011��
    graph->GetYNext()->AddZNextNode(beginPointX,
                                    endPointY,
                                    endPointZ,
                                    bisect3Storage.GetBeginXEndYEndZValue0(),
                                    bisect3Storage.GetBeginXEndYEndZValue1(),
                                    bisect3Storage.GetBeginXEndYEndZValue2());

    graph->GetZNext()->AddYNextNode(graph->GetYNext()->GetZNext());

    // ���� N111��
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

    // ��ʣ�µ��ı��δ�m_Graph���Ƴ���
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
        // �ݹ鳬���˴���������һ���м�ֵ��
        --level;
        bisect3Root = std::make_shared<Bisect3Root>(bisect3Storage.GetMidpointX(), bisect3Storage.GetMidpointY(), bisect3Storage.GetMidpointZ(), BisectRootType::Unknown);

        return false;
    }

    if (node->IsFunctionResult0SameSign() || node->IsFunctionResult1SameSign() || node->IsFunctionResult2SameSign())
    {
        // FirstFunction������ͬ�ķ����ڱ߽�㡣
        // ����SecondFunction������ͬ�ķ����ڱ߽�㡣
        // ����ThirdFunction������ͬ�ķ����ڱ߽�㡣

        // ��������������޽�
        --level;

        return false;
    }

    // ���ȷְ˱��Ρ�
    bisect3Storage.SetStorageValue(node);

    if (bisect3Storage.TestEdgeValues())
    {
        return true;
    }

    // ��������ֳɰ˸���������еݹ�������

    // ���������ڵ�������

    // ԭ�����ڵ�
    auto leftLowerInside = std::make_shared<Bisect3Node>(bisect3Storage.GetBeginPointX(),
                                                         bisect3Storage.GetBeginPointY(),
                                                         bisect3Storage.GetBeginPointZ(),
                                                         bisect3Storage.GetBeginXBeginYBeginZValue0(),
                                                         bisect3Storage.GetBeginXBeginYBeginZValue1(),
                                                         bisect3Storage.GetBeginXBeginYBeginZValue2());

    BuildLeftLowerInside(leftLowerInside);

    // ���������ڵ�������

    // �� 000, 100
    auto rightLowerInside = std::make_shared<Bisect3Node>(bisect3Storage.GetMidpointX(),
                                                          bisect3Storage.GetBeginPointY(),
                                                          bisect3Storage.GetBeginPointZ(),
                                                          bisect3Storage.GetMidXBeginYBeginZValue0(),
                                                          bisect3Storage.GetMidXBeginYBeginZValue1(),
                                                          bisect3Storage.GetMidXBeginYBeginZValue2());

    BuildRightLowerInside(rightLowerInside);

    // ���������ڵ�������

    // �� 000, 010
    auto leftUpperInside = std::make_shared<Bisect3Node>(bisect3Storage.GetBeginPointX(),
                                                         bisect3Storage.GetMidpointY(),
                                                         bisect3Storage.GetBeginPointZ(),
                                                         bisect3Storage.GetBeginXMidYBeginZValue0(),
                                                         bisect3Storage.GetBeginXMidYBeginZValue1(),
                                                         bisect3Storage.GetBeginXMidYBeginZValue2());

    BuildLeftUpperInside(leftUpperInside);

    // ���������ڵ�������

    // �� 000, 100, 110, 010
    auto rightUpperInside = std::make_shared<Bisect3Node>(bisect3Storage.GetMidpointX(),
                                                          bisect3Storage.GetMidpointY(),
                                                          bisect3Storage.GetBeginPointZ(),
                                                          bisect3Storage.GetMidXMidYBeginZValue0(),
                                                          bisect3Storage.GetMidXMidYBeginZValue1(),
                                                          bisect3Storage.GetMidXMidYBeginZValue2());

    BuildRightUpperInside(rightUpperInside);

    // �����������������

    // �� 000, 001
    auto leftLowerOutside = std::make_shared<Bisect3Node>(bisect3Storage.GetBeginPointX(),
                                                          bisect3Storage.GetBeginPointY(),
                                                          bisect3Storage.GetMidpointZ(),
                                                          bisect3Storage.GetBeginXBeginYMidZValue0(),
                                                          bisect3Storage.GetBeginXBeginYMidZValue1(),
                                                          bisect3Storage.GetBeginXBeginYMidZValue2());

    BuildLeftLowerOutside(leftLowerOutside);

    // �����������������

    // �� 000, 100, 001, 101
    auto rightLowerOutside = std::make_shared<Bisect3Node>(bisect3Storage.GetMidpointX(),
                                                           bisect3Storage.GetBeginPointY(),
                                                           bisect3Storage.GetMidpointZ(),
                                                           bisect3Storage.GetMidXBeginYMidZValue0(),
                                                           bisect3Storage.GetMidXBeginYMidZValue1(),
                                                           bisect3Storage.GetMidXBeginYMidZValue2());

    BuildRightLowerOutside(rightLowerOutside);

    // �����������������

    // �� 000, 010, 011, 001
    auto leftUpperOutside = std::make_shared<Bisect3Node>(bisect3Storage.GetBeginPointX(),
                                                          bisect3Storage.GetMidpointY(),
                                                          bisect3Storage.GetMidpointZ(),
                                                          bisect3Storage.GetBeginXMidYMidZValue0(),
                                                          bisect3Storage.GetBeginXMidYMidZValue1(),
                                                          bisect3Storage.GetBeginXMidYMidZValue2());

    BuildLeftUpperOutside(leftUpperOutside);

    // �����������������

    // ����
    auto rightUpperOutside = std::make_shared<Bisect3Node>(bisect3Storage.GetMidpointX(),
                                                           bisect3Storage.GetMidpointY(),
                                                           bisect3Storage.GetMidpointZ(),
                                                           bisect3Storage.GetMidXMidYMidZValue0(),
                                                           bisect3Storage.GetMidXMidYMidZValue1(),
                                                           bisect3Storage.GetMidXMidYMidZValue2());

    BuildRightUpperOutside(rightUpperOutside);

    // ������������ĸ���
    const auto result = BisectRecurse(leftLowerInside) ||
                        BisectRecurse(rightLowerInside) ||
                        BisectRecurse(leftUpperInside) ||
                        BisectRecurse(rightUpperInside) ||
                        BisectRecurse(leftLowerOutside) ||
                        BisectRecurse(rightLowerOutside) ||
                        BisectRecurse(leftUpperOutside) ||
                        BisectRecurse(rightUpperOutside);

    // �����Ӱ˱��μ��ʧ�ܣ�ɾ����ӵĽڵ㡣

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

    // �� 000, 100
    node->AddXNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetMidXBeginYBeginZValue0(),
                       bisect3Storage.GetMidXBeginYBeginZValue1(),
                       bisect3Storage.GetMidXBeginYBeginZValue2());

    // �� 000, 010
    node->AddYNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetBeginXMidYBeginZValue0(),
                       bisect3Storage.GetBeginXMidYBeginZValue1(),
                       bisect3Storage.GetBeginXMidYBeginZValue2());

    // �� 000, 100, 110, 010��
    node->GetXNext()->AddYNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetBeginPointZ(),
                                   bisect3Storage.GetMidXMidYBeginZValue0(),
                                   bisect3Storage.GetMidXMidYBeginZValue1(),
                                   bisect3Storage.GetMidXMidYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // �� 000, 001��
    node->AddZNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetBeginXBeginYMidZValue0(),
                       bisect3Storage.GetBeginXBeginYMidZValue1(),
                       bisect3Storage.GetBeginXBeginYMidZValue2());

    // �� 000, 100, 001, 101��
    node->GetXNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetBeginPointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetMidXBeginYMidZValue0(),
                                   bisect3Storage.GetMidXBeginYMidZValue1(),
                                   bisect3Storage.GetMidXBeginYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // �� 000, 010, 011, 001��
    node->GetYNext()->AddZNextNode(bisect3Storage.GetBeginPointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetBeginXMidYMidZValue0(),
                                   bisect3Storage.GetBeginXMidYMidZValue1(),
                                   bisect3Storage.GetBeginXMidYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // ���ġ�
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

    // ԭ�����ڵ�
    node->AddXNextNode(bisect3Storage.GetEndPointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetEndXBeginYBeginZValue0(),
                       bisect3Storage.GetEndXBeginYBeginZValue1(),
                       bisect3Storage.GetEndXBeginYBeginZValue2());

    // �� 000, 100, 110, 010
    node->AddYNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetMidXMidYBeginZValue0(),
                       bisect3Storage.GetMidXMidYBeginZValue1(),
                       bisect3Storage.GetMidXMidYBeginZValue2());

    // �� 100, 110
    node->GetXNext()->AddYNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetBeginPointZ(),
                                   bisect3Storage.GetEndXMidYBeginZValue0(),
                                   bisect3Storage.GetEndXMidYBeginZValue1(),
                                   bisect3Storage.GetEndXMidYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // �� 000, 100, 001, 101
    node->AddZNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetMidXBeginYMidZValue0(),
                       bisect3Storage.GetMidXBeginYMidZValue1(),
                       bisect3Storage.GetMidXBeginYMidZValue2());

    // �� 100, 101
    node->GetXNext()->AddZNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetBeginPointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetEndXBeginYMidZValue0(),
                                   bisect3Storage.GetEndXBeginYMidZValue1(),
                                   bisect3Storage.GetEndXBeginYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // ���ġ�
    node->GetYNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetMidXMidYMidZValue0(),
                                   bisect3Storage.GetMidXMidYMidZValue1(),
                                   bisect3Storage.GetMidXMidYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // �� 110, 100, 101, 111
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

    // �� 000, 100��110��010
    node->AddXNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetMidXMidYBeginZValue0(),
                       bisect3Storage.GetMidXMidYBeginZValue1(),
                       bisect3Storage.GetMidXMidYBeginZValue2());

    // ԭ�����ڵ�
    node->AddYNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetEndPointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetBeginXEndYBeginZValue0(),
                       bisect3Storage.GetBeginXEndYBeginZValue1(),
                       bisect3Storage.GetBeginXEndYBeginZValue2());

    // �� 110, 010��
    node->GetXNext()->AddYNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetBeginPointZ(),
                                   bisect3Storage.GetMidXEndYBeginZValue0(),
                                   bisect3Storage.GetMidXEndYBeginZValue1(),
                                   bisect3Storage.GetMidXEndYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // ��  000��001��011��010
    node->AddZNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetBeginXMidYMidZValue0(),
                       bisect3Storage.GetBeginXMidYMidZValue1(),
                       bisect3Storage.GetBeginXMidYMidZValue2());

    // ����
    node->GetXNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetMidXMidYMidZValue0(),
                                   bisect3Storage.GetMidXMidYMidZValue1(),
                                   bisect3Storage.GetMidXMidYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // �� 011,010
    node->GetYNext()->AddZNextNode(bisect3Storage.GetBeginPointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetBeginXEndYMidZValue0(),
                                   bisect3Storage.GetBeginXEndYMidZValue1(),
                                   bisect3Storage.GetBeginXEndYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // �� 010,110,111,011
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

    // �� 100 110
    node->AddXNextNode(bisect3Storage.GetEndPointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetEndXMidYBeginZValue0(),
                       bisect3Storage.GetEndXMidYBeginZValue1(),
                       bisect3Storage.GetEndXMidYBeginZValue2());

    // �� 110, 010
    node->AddYNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetEndPointY(),
                       bisect3Storage.GetBeginPointZ(),
                       bisect3Storage.GetMidXEndYBeginZValue0(),
                       bisect3Storage.GetMidXEndYBeginZValue1(),
                       bisect3Storage.GetMidXEndYBeginZValue2());

    // ԭ�����ڵ�
    node->GetXNext()->AddYNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetBeginPointZ(),
                                   bisect3Storage.GetEndXEndYBeginZValue0(),
                                   bisect3Storage.GetEndXEndYBeginZValue1(),
                                   bisect3Storage.GetEndXEndYBeginZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // ����
    node->AddZNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetMidXBeginYMidZValue0(),
                       bisect3Storage.GetMidXBeginYMidZValue1(),
                       bisect3Storage.GetMidXBeginYMidZValue2());

    // �� 100, 110, 111, 101��
    node->GetXNext()->AddZNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetEndXMidYMidZValue0(),
                                   bisect3Storage.GetEndXMidYMidZValue1(),
                                   bisect3Storage.GetEndXMidYMidZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // �� 011,111,110,010
    node->GetYNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetMidXEndYMidZValue0(),
                                   bisect3Storage.GetMidXEndYMidZValue1(),
                                   bisect3Storage.GetMidXEndYMidZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // ��110��111
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

    // �� 000, 100��101��001
    node->AddXNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetMidXBeginYMidZValue0(),
                       bisect3Storage.GetMidXBeginYMidZValue1(),
                       bisect3Storage.GetMidXBeginYMidZValue2());

    // �� 000, 001��011��010
    node->AddYNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetBeginXMidYMidZValue0(),
                       bisect3Storage.GetBeginXMidYMidZValue1(),
                       bisect3Storage.GetBeginXMidYMidZValue2());

    // ����
    node->GetXNext()->AddYNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetMidXMidYMidZValue0(),
                                   bisect3Storage.GetMidXMidYMidZValue1(),
                                   bisect3Storage.GetMidXMidYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // ԭ�������
    node->AddZNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetEndPointZ(),
                       bisect3Storage.GetBeginXBeginYEndZValue0(),
                       bisect3Storage.GetBeginXBeginYEndZValue1(),
                       bisect3Storage.GetBeginXBeginYEndZValue2());

    // ��001,101
    node->GetXNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetBeginPointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetMidXBeginYEndZValue0(),
                                   bisect3Storage.GetMidXBeginYEndZValue1(),
                                   bisect3Storage.GetMidXBeginYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // ��001,011
    node->GetYNext()->AddZNextNode(bisect3Storage.GetBeginPointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetBeginXMidYEndZValue0(),
                                   bisect3Storage.GetBeginXMidYEndZValue1(),
                                   bisect3Storage.GetBeginXMidYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // �� 001,101,111,011
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

    // ��100,101
    node->AddXNextNode(bisect3Storage.GetEndPointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetEndXBeginYMidZValue0(),
                       bisect3Storage.GetEndXBeginYMidZValue1(),
                       bisect3Storage.GetEndXBeginYMidZValue2());

    // ����
    node->AddYNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetMidXMidYMidZValue0(),
                       bisect3Storage.GetMidXMidYMidZValue1(),
                       bisect3Storage.GetMidXMidYMidZValue2());

    // ��100��101��111��110
    node->GetXNext()->AddYNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetEndXMidYMidZValue0(),
                                   bisect3Storage.GetEndXMidYMidZValue1(),
                                   bisect3Storage.GetEndXMidYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // ��001,101
    node->AddZNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetBeginPointY(),
                       bisect3Storage.GetEndPointZ(),
                       bisect3Storage.GetMidXBeginYEndZValue0(),
                       bisect3Storage.GetMidXBeginYEndZValue1(),
                       bisect3Storage.GetMidXBeginYEndZValue2());

    // ��001,101,111,011
    node->GetXNext()->AddZNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetBeginPointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetEndXBeginYEndZValue0(),
                                   bisect3Storage.GetEndXBeginYEndZValue1(),
                                   bisect3Storage.GetEndXBeginYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // ��001��101��111��011
    node->GetYNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetMidXMidYEndZValue0(),
                                   bisect3Storage.GetMidXMidYEndZValue1(),
                                   bisect3Storage.GetMidXMidYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // ��101,111
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
    // ����
    node->AddXNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetMidXMidYMidZValue0(),
                       bisect3Storage.GetMidXMidYMidZValue1(),
                       bisect3Storage.GetMidXMidYMidZValue2());

    // ��011,010
    node->AddYNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetEndPointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetBeginXEndYMidZValue0(),
                       bisect3Storage.GetBeginXEndYMidZValue1(),
                       bisect3Storage.GetBeginXEndYMidZValue2());

    // ��011��010��110��111
    node->GetXNext()->AddYNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetMidXEndYMidZValue0(),
                                   bisect3Storage.GetMidXEndYMidZValue1(),
                                   bisect3Storage.GetMidXEndYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // �� 001,011
    node->AddZNextNode(bisect3Storage.GetBeginPointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetEndPointZ(),
                       bisect3Storage.GetBeginXMidYEndZValue0(),
                       bisect3Storage.GetBeginXMidYEndZValue1(),
                       bisect3Storage.GetBeginXMidYEndZValue2());

    // ��001��101��111��011
    node->GetXNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetMidXMidYEndZValue0(),
                                   bisect3Storage.GetMidXMidYEndZValue1(),
                                   bisect3Storage.GetMidXMidYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // ԭ�������
    node->GetYNext()->AddZNextNode(bisect3Storage.GetBeginPointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetBeginXEndYEndZValue0(),
                                   bisect3Storage.GetBeginXEndYEndZValue1(),
                                   bisect3Storage.GetBeginXEndYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // ��011��111
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

    // ��110,100,101,111
    node->AddXNextNode(bisect3Storage.GetEndPointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetEndXMidYMidZValue0(),
                       bisect3Storage.GetEndXMidYMidZValue1(),
                       bisect3Storage.GetEndXMidYMidZValue2());

    // ��010��110��111��011
    node->AddYNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetEndPointY(),
                       bisect3Storage.GetMidpointZ(),
                       bisect3Storage.GetMidXEndYMidZValue0(),
                       bisect3Storage.GetMidXEndYMidZValue1(),
                       bisect3Storage.GetMidXEndYMidZValue2());

    // ��110,111
    node->GetXNext()->AddYNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetMidpointZ(),
                                   bisect3Storage.GetEndXEndYMidZValue0(),
                                   bisect3Storage.GetEndXEndYMidZValue1(),
                                   bisect3Storage.GetEndXEndYMidZValue2());

    node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

    // ��011��111��101��001
    node->AddZNextNode(bisect3Storage.GetMidpointX(),
                       bisect3Storage.GetMidpointY(),
                       bisect3Storage.GetEndPointZ(),
                       bisect3Storage.GetMidXBeginYEndZValue0(),
                       bisect3Storage.GetMidXBeginYEndZValue1(),
                       bisect3Storage.GetMidXBeginYEndZValue2());

    // �� 100, 110, 100, 101��
    node->GetXNext()->AddZNextNode(bisect3Storage.GetEndPointX(),
                                   bisect3Storage.GetMidpointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetEndXMidYEndZValue0(),
                                   bisect3Storage.GetEndXMidYEndZValue1(),
                                   bisect3Storage.GetEndXMidYEndZValue2());

    node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());

    // ��011��111
    node->GetYNext()->AddZNextNode(bisect3Storage.GetMidpointX(),
                                   bisect3Storage.GetEndPointY(),
                                   bisect3Storage.GetEndPointZ(),
                                   bisect3Storage.GetMidXEndYEndZValue0(),
                                   bisect3Storage.GetMidXEndYEndZValue1(),
                                   bisect3Storage.GetMidXEndYEndZValue2());

    node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

    // ԭ�������
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
