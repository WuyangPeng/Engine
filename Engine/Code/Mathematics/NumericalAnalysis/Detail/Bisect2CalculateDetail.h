///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 09:22)

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
    MATHEMATICS_ASSERTION_1(beginPointX <= endPointX, "����Xֵ���յ��Xֵ��");
    MATHEMATICS_ASSERTION_1(beginPointY <= endPointY, "����Yֵ���յ��Yֵ��");

    // ���Ե��ĸ��ǵ�ֵ��
    if (bisect2Storage.TestFourCornerValues(beginPointX, beginPointY, endPointX, endPointY))
    {
        bisect2Root = bisect2Storage.GetBisect2Root();

        return;
    }

    // ������ʼ�ı��Ρ�

    // ���� N00��
    graph = std::make_shared<Bisect2Node>(beginPointX, beginPointY, bisect2Storage.GetBeginXAndBeginYValue0(), bisect2Storage.GetBeginXAndBeginYValue1());

    // ���� N10��
    graph->AddXNextNode(endPointX, beginPointY, bisect2Storage.GetEndXAndBeginYValue0(), bisect2Storage.GetEndXAndBeginYValue1());

    // ���� N01��
    graph->AddYNextNode(beginPointX, endPointY, bisect2Storage.GetBeginXAndEndYValue0(), bisect2Storage.GetBeginXAndEndYValue1());

    // ���� N11��
    graph->GetXNext()->AddYNextNode(endPointX, endPointY, bisect2Storage.GetEndXAndEndYValue0(), bisect2Storage.GetEndXAndEndYValue1());
    graph->GetYNext()->AddXNextNode(graph->GetXNext()->GetYNext());

    if (const auto result = BisectRecurse(graph);
        result)
    {
        bisect2Root = bisect2Storage.GetBisect2Root();
    }

    // ��ʣ�µ��ı��δ�m_Graph���Ƴ���
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
        // �ݹ鳬���˴���������һ���м�ֵ��
        --level;
        bisect2Root = std::make_shared<Bisect2Root>(bisect2Storage.GetMidpointX(), bisect2Storage.GetMidpointY(), BisectRootType::Unknown);

        return false;
    }

    // ���Ż�����ĳ�������޽�ʱ�����˳������������жϱ߽�������ͬ�ķ��š�
    if (node->IsFunctionResult0SameSign() || node->IsFunctionResult1SameSign())
    {
        // FirstFunction������ͬ�ķ����ڱ߽�㡣
        // ����GecondFunction������ͬ�ķ����ڱ߽�㡣

        // ��������������޽�
        --level;

        return false;
    }

    // ���ȷ��ı��Ρ�
    bisect2Storage.SetStorageValue(node);

    if (bisect2Storage.TestEdgeValues())
    {
        return true;
    }

    // ���ı��ηֳ��ĸ��ı��ν��еݹ�������

    // �������Ͻǵ��ı���

    // ԭ���Ͻǵ�
    auto leftUpper = std::make_shared<Bisect2Node>(bisect2Storage.GetBeginPointX(),
                                                   bisect2Storage.GetBeginPointY(),
                                                   bisect2Storage.GetBeginXAndBeginYValue0(),
                                                   bisect2Storage.GetBeginXAndBeginYValue1());

    // ������ƽ����
    leftUpper->AddXNextNode(bisect2Storage.GetMidpointX(),
                            bisect2Storage.GetBeginPointY(),
                            bisect2Storage.GetMidXAndBeginYValue0(),
                            bisect2Storage.GetMidXAndBeginYValue1());

    // ��ߵ�ƽ����
    leftUpper->AddYNextNode(bisect2Storage.GetBeginPointX(),
                            bisect2Storage.GetMidpointY(),
                            bisect2Storage.GetBeginXAndMidYValue0(),
                            bisect2Storage.GetBeginXAndMidYValue1());

    // �м��ƽ����
    leftUpper->GetXNext()->AddYNextNode(bisect2Storage.GetMidpointX(),
                                        bisect2Storage.GetMidpointY(),
                                        bisect2Storage.GetMidXAndMidYValue0(),
                                        bisect2Storage.GetMidXAndMidYValue1());

    leftUpper->GetYNext()->AddXNextNode(leftUpper->GetXNext()->GetYNext());

    // �������Ͻǵ��ı���

    // ������ƽ����
    auto rightUpper = std::make_shared<Bisect2Node>(bisect2Storage.GetMidpointX(),
                                                    bisect2Storage.GetBeginPointY(),
                                                    bisect2Storage.GetMidXAndBeginYValue0(),
                                                    bisect2Storage.GetMidXAndBeginYValue1());

    // ԭ���Ͻǵ�
    rightUpper->AddXNextNode(bisect2Storage.GetEndPointX(),
                             bisect2Storage.GetBeginPointY(),
                             bisect2Storage.GetEndXAndBeginYValue0(),
                             bisect2Storage.GetEndXAndBeginYValue1());

    // �м��ƽ����
    rightUpper->AddYNextNode(bisect2Storage.GetMidpointX(),
                             bisect2Storage.GetMidpointY(),
                             bisect2Storage.GetMidXAndMidYValue0(),
                             bisect2Storage.GetMidXAndMidYValue1());

    // �ұߵ�ƽ����
    rightUpper->GetXNext()->AddYNextNode(bisect2Storage.GetEndPointX(),
                                         bisect2Storage.GetMidpointY(),
                                         bisect2Storage.GetEndXAndMidYValue0(),
                                         bisect2Storage.GetEndXAndMidYValue1());

    rightUpper->GetYNext()->AddXNextNode(rightUpper->GetXNext()->GetYNext());

    // �������½ǵ��ı���

    // ��ߵ�ƽ����
    auto leftLower = std::make_shared<Bisect2Node>(bisect2Storage.GetBeginPointX(),
                                                   bisect2Storage.GetMidpointY(),
                                                   bisect2Storage.GetBeginXAndMidYValue0(),
                                                   bisect2Storage.GetBeginXAndMidYValue1());

    // �м��ƽ����
    leftLower->AddXNextNode(bisect2Storage.GetMidpointX(),
                            bisect2Storage.GetMidpointY(),
                            bisect2Storage.GetMidXAndMidYValue0(),
                            bisect2Storage.GetMidXAndMidYValue1());

    // ԭ���½ǵ�
    leftLower->AddYNextNode(bisect2Storage.GetBeginPointX(),
                            bisect2Storage.GetEndPointY(),
                            bisect2Storage.GetBeginXAndEndYValue0(),
                            bisect2Storage.GetBeginXAndEndYValue1());

    // �ײ���ƽ����
    leftLower->GetXNext()->AddYNextNode(bisect2Storage.GetMidpointX(),
                                        bisect2Storage.GetEndPointY(),
                                        bisect2Storage.GetMidXAndEndYValue0(),
                                        bisect2Storage.GetMidXAndEndYValue1());

    leftLower->GetYNext()->AddXNextNode(leftLower->GetXNext()->GetYNext());

    // �������½ǵ��ı���

    // �м��ƽ����
    auto rightLower = std::make_shared<Bisect2Node>(bisect2Storage.GetMidpointX(),
                                                    bisect2Storage.GetMidpointY(),
                                                    bisect2Storage.GetMidXAndMidYValue0(),
                                                    bisect2Storage.GetMidXAndMidYValue1());

    // �ұߵ�ƽ����
    rightLower->AddXNextNode(bisect2Storage.GetEndPointX(),
                             bisect2Storage.GetMidpointY(),
                             bisect2Storage.GetEndXAndMidYValue0(),
                             bisect2Storage.GetEndXAndMidYValue1());

    // �ײ���ƽ����
    rightLower->AddYNextNode(bisect2Storage.GetMidpointX(),
                             bisect2Storage.GetEndPointY(),
                             bisect2Storage.GetMidXAndEndYValue0(),
                             bisect2Storage.GetMidXAndEndYValue1());

    // ԭ���½ǵ�
    rightLower->GetXNext()->AddYNextNode(bisect2Storage.GetMidpointX(),
                                         bisect2Storage.GetEndPointY(),
                                         bisect2Storage.GetMidXAndEndYValue0(),
                                         bisect2Storage.GetMidXAndEndYValue1());

    rightLower->GetYNext()->AddXNextNode(rightLower->GetXNext()->GetYNext());

    // Ӧ���ȹ����ĸ��ı����ٽ��еݹ飬��Ϊ�ݹ���޸�m_Bisect2Storage���ֵ��
    // �������ı��εĸ���
    const auto result = BisectRecurse(leftUpper) || BisectRecurse(rightUpper) || BisectRecurse(leftLower) || BisectRecurse(rightLower);

    // �������ı��μ��ʧ�ܣ�ɾ����ӵĽڵ㡣
    --level;

    return result;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_DETAIL_H
