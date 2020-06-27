// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 13:34)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_DETAIL_H

#include "Bisect2Calculate.h"
#include "Math.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect2Calculate<Real>
	::Bisect2Calculate(const Bisect2& bisect, Real beginPointX, Real beginPointY, Real endPointX, Real endPointY)
	: m_Bisect2{ bisect }, m_Level{ 0 }, m_Bisect2Root{ std::make_shared<Bisect2Root>() }, m_Bisect2Storage{ bisect }, m_Graph{ nullptr }
{
	Calculate(beginPointX, beginPointY, endPointX, endPointY);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::Bisect2Calculate<Real>
	::Calculate(Real beginPointX, Real beginPointY, Real endPointX, Real endPointY)
{
	MATHEMATICS_ASSERTION_1(beginPointX <= endPointX, "����Xֵ���յ��Xֵ��");
	MATHEMATICS_ASSERTION_1(beginPointY <= endPointY, "����Yֵ���յ��Yֵ��");

	// ���Ե��ĸ��ǵ�ֵ��
	if (m_Bisect2Storage.TestFourCornerValues(beginPointX, beginPointY, endPointX, endPointY))
	{
		m_Bisect2Root = m_Bisect2Storage.GetBisect2RootPtr();

		return;
	}

	// ������ʼ�ı��Ρ�

	// ���� N00��
	m_Graph = std::make_shared <Bisect2Node>(beginPointX, beginPointY, m_Bisect2Storage.GetBeginXAndBeginYFirstValue(), m_Bisect2Storage.GetBeginXAndBeginYSecondValue());


	// ���� N10��
	m_Graph->AddXNextNode(endPointX, beginPointY, m_Bisect2Storage.GetEndXAndBeginYFirstValue(), m_Bisect2Storage.GetEndXAndBeginYSecondValue());

	// ���� N01��
	m_Graph->AddYNextNode(beginPointX, endPointY, m_Bisect2Storage.GetBeginXAndEndYFirstValue(), m_Bisect2Storage.GetBeginXAndEndYSecondValue());

	// ���� N11��
	m_Graph->GetXNext()->AddYNextNode(endPointX, endPointY, m_Bisect2Storage.GetEndXAndEndYFirstValue(), m_Bisect2Storage.GetEndXAndEndYSecondValue());
	m_Graph->GetYNext()->AddXNextNode(m_Graph->GetXNext()->GetYNext());


	auto result = BisectRecurse(m_Graph.get());

	if (result)
	{
		m_Bisect2Root = m_Bisect2Storage.GetBisect2RootPtr();
	}

	// ��ʣ�µ��ı��δ�m_Graph���Ƴ���
	m_Graph.reset();
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect2Calculate<Real>
	::IsValid() const noexcept
{
	if (m_Bisect2Root != nullptr && m_Graph == nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Bisect2Calculate<Real>::Bisect2Root Mathematics::Bisect2Calculate<Real>
	::GetRoot() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return *m_Bisect2Root;
}

// private
template <typename Real>
bool Mathematics::Bisect2Calculate<Real>
	::BisectRecurse(Bisect2Node* node)
{
	if (++m_Level == m_Bisect2.GetMaxLevel())
	{
		// �ݹ鳬���˴���������һ���м�ֵ��
		--m_Level;
		m_Bisect2Root = std::make_shared<Bisect2Root>(m_Bisect2Storage.GetMidpointX(), m_Bisect2Storage.GetMidpointY(), BisectRootType::Unknown);

		return false;
	}

	// ���Ż�����ĳ�������޽�ʱ�����˳������������жϱ߽�������ͬ�ķ��š�
	if (node->IsFirstFunctionResultSameSign() || node->IsSecondFunctionResultSameSign())
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
	Bisect2Node leftUpper{ m_Bisect2Storage.GetBeginPointX(),m_Bisect2Storage.GetBeginPointY(),
						   m_Bisect2Storage.GetBeginXAndBeginYFirstValue(), m_Bisect2Storage.GetBeginXAndBeginYSecondValue() };

	// ������ƽ����
	leftUpper.AddXNextNode(m_Bisect2Storage.GetMidpointX(),
						   m_Bisect2Storage.GetBeginPointY(),
						   m_Bisect2Storage.GetMidXAndBeginYFirstValue(),
						   m_Bisect2Storage.GetMidXAndBeginYSecondValue());

	// ��ߵ�ƽ����
	leftUpper.AddYNextNode(m_Bisect2Storage.GetBeginPointX(),
						   m_Bisect2Storage.GetMidpointY(),
						   m_Bisect2Storage.GetBeginXAndMidYFirstValue(),
						   m_Bisect2Storage.GetBeginXAndMidYSecondValue());

	// �м��ƽ����
	leftUpper.GetXNext()->AddYNextNode(m_Bisect2Storage.GetMidpointX(),
									   m_Bisect2Storage.GetMidpointY(),
									   m_Bisect2Storage.GetMidXAndMidYFirstValue(),
									   m_Bisect2Storage.GetMidXAndMidYSecondValue());

	leftUpper.GetYNext()->AddXNextNode(leftUpper.GetXNext()->GetYNext());

	// �������Ͻǵ��ı���

	// ������ƽ����
	Bisect2Node rightUpper{ m_Bisect2Storage.GetMidpointX(), m_Bisect2Storage.GetBeginPointY(),
							m_Bisect2Storage.GetMidXAndBeginYFirstValue(), m_Bisect2Storage.GetMidXAndBeginYSecondValue() };

	// ԭ���Ͻǵ�
	rightUpper.AddXNextNode(m_Bisect2Storage.GetEndPointX(),
							m_Bisect2Storage.GetBeginPointY(),
							m_Bisect2Storage.GetEndXAndBeginYFirstValue(),
							m_Bisect2Storage.GetEndXAndBeginYSecondValue());

	// �м��ƽ����
	rightUpper.AddYNextNode(m_Bisect2Storage.GetMidpointX(),
							m_Bisect2Storage.GetMidpointY(),
							m_Bisect2Storage.GetMidXAndMidYFirstValue(),
							m_Bisect2Storage.GetMidXAndMidYSecondValue());

	// �ұߵ�ƽ����
	rightUpper.GetXNext()->AddYNextNode(m_Bisect2Storage.GetEndPointX(),
										m_Bisect2Storage.GetMidpointY(),
										m_Bisect2Storage.GetEndXAndMidYFirstValue(),
										m_Bisect2Storage.GetEndXAndMidYSecondValue());

	rightUpper.GetYNext()->AddXNextNode(rightUpper.GetXNext()->GetYNext());

	// �������½ǵ��ı���

	// ��ߵ�ƽ����
	Bisect2Node leftLower{ m_Bisect2Storage.GetBeginPointX(), m_Bisect2Storage.GetMidpointY(),
						   m_Bisect2Storage.GetBeginXAndMidYFirstValue(), m_Bisect2Storage.GetBeginXAndMidYSecondValue() };

	// �м��ƽ����
	leftLower.AddXNextNode(m_Bisect2Storage.GetMidpointX(),
						   m_Bisect2Storage.GetMidpointY(),
						   m_Bisect2Storage.GetMidXAndMidYFirstValue(),
						   m_Bisect2Storage.GetMidXAndMidYSecondValue());

	// ԭ���½ǵ�
	leftLower.AddYNextNode(m_Bisect2Storage.GetBeginPointX(),
						   m_Bisect2Storage.GetEndPointY(),
						   m_Bisect2Storage.GetBeginXAndEndYFirstValue(),
						   m_Bisect2Storage.GetBeginXAndEndYSecondValue());

	// �ײ���ƽ����
	leftLower.GetXNext()->AddYNextNode(m_Bisect2Storage.GetMidpointX(),
									   m_Bisect2Storage.GetEndPointY(),
									   m_Bisect2Storage.GetMidXAndEndYFirstValue(),
									   m_Bisect2Storage.GetMidXAndEndYSecondValue());

	leftLower.GetYNext()->AddXNextNode(leftLower.GetXNext()->GetYNext());

	// �������½ǵ��ı���

	// �м��ƽ����
	Bisect2Node rightLower{ m_Bisect2Storage.GetMidpointX(), m_Bisect2Storage.GetMidpointY(),
							m_Bisect2Storage.GetMidXAndMidYFirstValue(), m_Bisect2Storage.GetMidXAndMidYSecondValue() };

	// �ұߵ�ƽ����
	rightLower.AddXNextNode(m_Bisect2Storage.GetEndPointX(),
							m_Bisect2Storage.GetMidpointY(),
							m_Bisect2Storage.GetEndXAndMidYFirstValue(),
							m_Bisect2Storage.GetEndXAndMidYSecondValue());

	// �ײ���ƽ����
	rightLower.AddYNextNode(m_Bisect2Storage.GetMidpointX(),
							m_Bisect2Storage.GetEndPointY(),
							m_Bisect2Storage.GetMidXAndEndYFirstValue(),
							m_Bisect2Storage.GetMidXAndEndYSecondValue());

	// ԭ���½ǵ�
	rightLower.GetXNext()->AddYNextNode(m_Bisect2Storage.GetMidpointX(),
										m_Bisect2Storage.GetEndPointY(),
										m_Bisect2Storage.GetMidXAndEndYFirstValue(),
										m_Bisect2Storage.GetMidXAndEndYSecondValue());

	rightLower.GetYNext()->AddXNextNode(rightLower.GetXNext()->GetYNext());

	// Ӧ���ȹ����ĸ��ı����ٽ��еݹ飬��Ϊ�ݹ���޸�m_Bisect2Storage���ֵ��
	// �������ı��εĸ���
	auto result = BisectRecurse(&leftUpper) || BisectRecurse(&rightUpper) || BisectRecurse(&leftLower) || BisectRecurse(&rightLower);

	// �������ı��μ��ʧ�ܣ�ɾ����ӵĽڵ㡣    
	--m_Level;

	return result;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_DETAIL_H

