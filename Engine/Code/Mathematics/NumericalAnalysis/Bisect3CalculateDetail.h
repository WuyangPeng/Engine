// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 13:39)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_DETAIL_H

#include "Bisect3Calculate.h"
#include "Bisect3Node.h"
#include "Bisect3.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect3Calculate<Real>
	::Bisect3Calculate(const Bisect3& bisect, Real beginPointX, Real beginPointY, Real beginPointZ,
				   Real endPointX, Real endPointY, Real endPointZ)
	: m_Bisect3{ bisect }, m_Level{ 0 }, m_Bisect3Root(std::make_shared<Bisect3Root>()),
	  m_Bisect3Storage{ bisect }, m_Graph{ nullptr }
{
	Calculate(beginPointX, beginPointY, beginPointZ, endPointX, endPointY, endPointZ);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::Bisect3Calculate<Real>
	::Calculate(Real beginPointX, Real beginPointY, Real beginPointZ,
				Real endPointX, Real endPointY, Real endPointZ)
{
	MATHEMATICS_ASSERTION_2(beginPointX <= endPointX, "����Xֵ���յ��Xֵ��");
	MATHEMATICS_ASSERTION_2(beginPointY <= endPointY, "����Yֵ���յ��Yֵ��");
	MATHEMATICS_ASSERTION_2(beginPointZ <= endPointZ, "����Zֵ���յ��Zֵ��");

	// ���Եİ˸��ǵ�ֵ��
	if (m_Bisect3Storage.TestEightCornerValues(beginPointX, beginPointY, beginPointZ, endPointX, endPointY, endPointZ))
	{
		m_Bisect3Root = m_Bisect3Storage.GetBisect3RootPtr();

		return;
	}

	// ������ʼ�˱���

	// ���� N000��
	m_Graph = std::make_shared<Bisect3Node>(beginPointX, beginPointY, beginPointZ,
											m_Bisect3Storage.GetBeginXBeginYBeginZFirstValue(),
											m_Bisect3Storage.GetBeginXBeginYBeginZSecondValue(),
											m_Bisect3Storage.GetBeginXBeginYBeginZThirdValue());

	// ���� N100��
	m_Graph->AddXNextNode(endPointX, beginPointY, beginPointZ,
						  m_Bisect3Storage.GetEndXBeginYBeginZFirstValue(),
						  m_Bisect3Storage.GetEndXBeginYBeginZSecondValue(),
						  m_Bisect3Storage.GetEndXBeginYBeginZThirdValue());


	// ���� N010��
	m_Graph->AddYNextNode(beginPointX, endPointY, beginPointZ,
						  m_Bisect3Storage.GetBeginXEndYBeginZFirstValue(),
						  m_Bisect3Storage.GetBeginXEndYBeginZSecondValue(),
						  m_Bisect3Storage.GetBeginXEndYBeginZThirdValue());


	// ���� N110��
	m_Graph->GetXNext()->AddYNextNode(endPointX, endPointY, beginPointZ,
									  m_Bisect3Storage.GetEndXEndYBeginZFirstValue(),
									  m_Bisect3Storage.GetEndXEndYBeginZSecondValue(),
									  m_Bisect3Storage.GetEndXEndYBeginZThirdValue());

	m_Graph->GetYNext()->AddXNextNode(m_Graph->GetXNext()->GetYNext());



	// ���� N001��
	m_Graph->AddZNextNode(beginPointX, beginPointY, endPointZ,
						  m_Bisect3Storage.GetBeginXBeginYEndZFirstValue(),
						  m_Bisect3Storage.GetBeginXBeginYEndZSecondValue(),
						  m_Bisect3Storage.GetBeginXBeginYEndZThirdValue());


	// ���� N101��
	m_Graph->GetXNext()->AddZNextNode(endPointX, beginPointY, endPointZ,
									  m_Bisect3Storage.GetEndXBeginYEndZFirstValue(),
									  m_Bisect3Storage.GetEndXBeginYEndZSecondValue(),
									  m_Bisect3Storage.GetEndXBeginYEndZThirdValue());

	m_Graph->GetZNext()->AddXNextNode(m_Graph->GetXNext()->GetZNext());

	// ���� N011��
	m_Graph->GetYNext()->AddZNextNode(beginPointX, endPointY, endPointZ,
									  m_Bisect3Storage.GetBeginXEndYEndZFirstValue(),
									  m_Bisect3Storage.GetBeginXEndYEndZSecondValue(),
									  m_Bisect3Storage.GetBeginXEndYEndZThirdValue());

	m_Graph->GetZNext()->AddYNextNode(m_Graph->GetYNext()->GetZNext());


	// ���� N111��
	m_Graph->GetXNext()->GetYNext()->AddZNextNode(endPointX, endPointY, endPointZ,
												  m_Bisect3Storage.GetEndXEndYEndZFirstValue(),
												  m_Bisect3Storage.GetEndXEndYEndZSecondValue(),
												  m_Bisect3Storage.GetEndXEndYEndZThirdValue());

	m_Graph->GetYNext()->GetXNext()->AddZNextNode(m_Graph->GetXNext()->GetYNext()->GetZNext());
	m_Graph->GetXNext()->GetZNext()->AddYNextNode(m_Graph->GetXNext()->GetYNext()->GetZNext());


	auto result = BisectRecurse(m_Graph.get());

	if (result)
	{
		m_Bisect3Root = m_Bisect3Storage.GetBisect3RootPtr();
	}

	// ��ʣ�µ��ı��δ�m_Graph���Ƴ���
	m_Graph.reset();
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect3Calculate<Real>
	::IsValid() const noexcept
{
	if (m_Bisect3Root != nullptr && m_Graph == nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Bisect3Calculate<Real>::Bisect3Root Mathematics::Bisect3Calculate<Real>
	::GetRoot() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return *m_Bisect3Root;
}

// private
template <typename Real>
bool Mathematics::Bisect3Calculate<Real>
	::BisectRecurse(Bisect3Node* node)
{
	if (++m_Level == m_Bisect3.GetMaxLevel())
	{
		// �ݹ鳬���˴���������һ���м�ֵ��
		--m_Level;
		m_Bisect3Root = std::make_shared<Bisect3Root>(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetMidpointZ(), BisectRootType::Unknown);

		return false;
	}

	if (node->IsFirstFunctionResultSameSign() || node->IsSecondFunctionResultSameSign() || node->IsThirdFunctionResultSameSign())
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
	Bisect3Node leftLowerInside{ m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetBeginPointZ(),
								 m_Bisect3Storage.GetBeginXBeginYBeginZFirstValue(), m_Bisect3Storage.GetBeginXBeginYBeginZSecondValue(), m_Bisect3Storage.GetBeginXBeginYBeginZThirdValue() };

	BuildLeftLowerInside(&leftLowerInside);


	// ���������ڵ�������

	// �� 000, 100
	Bisect3Node rightLowerInside{ m_Bisect3Storage.GetMidpointX(),m_Bisect3Storage.GetBeginPointY(),m_Bisect3Storage.GetBeginPointZ(),
								  m_Bisect3Storage.GetMidXBeginYBeginZFirstValue(),m_Bisect3Storage.GetMidXBeginYBeginZSecondValue(),m_Bisect3Storage.GetMidXBeginYBeginZThirdValue() };

	BuildRightLowerInside(&rightLowerInside);

	// ���������ڵ�������

	// �� 000, 010
	Bisect3Node leftUpperInside{ m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetBeginPointZ(),
								 m_Bisect3Storage.GetBeginXMidYBeginZFirstValue(), m_Bisect3Storage.GetBeginXMidYBeginZSecondValue(), m_Bisect3Storage.GetBeginXMidYBeginZThirdValue() };

	BuildLeftUpperInside(&leftUpperInside);


	// ���������ڵ�������

	// �� 000, 100, 110, 010
	Bisect3Node rightUpperInside{ m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetBeginPointZ(),
								  m_Bisect3Storage.GetMidXMidYBeginZFirstValue(),  m_Bisect3Storage.GetMidXMidYBeginZSecondValue(), m_Bisect3Storage.GetMidXMidYBeginZThirdValue() };

	BuildRightUpperInside(&rightUpperInside);

	// �����������������

	// �� 000, 001
	Bisect3Node leftLowerOutside{ m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetMidpointZ(),
								  m_Bisect3Storage.GetBeginXBeginYMidZFirstValue(),  m_Bisect3Storage.GetBeginXBeginYMidZSecondValue(), m_Bisect3Storage.GetBeginXBeginYMidZThirdValue() };

	BuildLeftLowerOutside(&leftLowerOutside);


	// �����������������

	// �� 000, 100, 001, 101
	Bisect3Node rightLowerOutside{ m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXBeginYMidZFirstValue(), m_Bisect3Storage.GetMidXBeginYMidZSecondValue(), m_Bisect3Storage.GetMidXBeginYMidZThirdValue() };

	BuildRightLowerOutside(&rightLowerOutside);

	// �����������������

	// �� 000, 010, 011, 001
	Bisect3Node leftUpperOutside{ m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetMidpointZ(),
								  m_Bisect3Storage.GetBeginXMidYMidZFirstValue(), m_Bisect3Storage.GetBeginXMidYMidZSecondValue(), m_Bisect3Storage.GetBeginXMidYMidZThirdValue() };

	BuildLeftUpperOutside(&leftUpperOutside);


	// �����������������

	// ����
	Bisect3Node rightUpperOutside{ m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXMidYMidZFirstValue(), m_Bisect3Storage.GetMidXMidYMidZSecondValue(), m_Bisect3Storage.GetMidXMidYMidZThirdValue() };

	BuildRightUpperOutside(&rightUpperOutside);

	// ������������ĸ���
	auto result = BisectRecurse(&leftLowerInside) || BisectRecurse(&rightLowerInside) ||
				  BisectRecurse(&leftUpperInside) || BisectRecurse(&rightUpperInside) ||
				  BisectRecurse(&leftLowerOutside) || BisectRecurse(&rightLowerOutside) ||
				  BisectRecurse(&leftUpperOutside) || BisectRecurse(&rightUpperOutside);

	// �����Ӱ˱��μ��ʧ�ܣ�ɾ����ӵĽڵ㡣

	--m_Level;

	return result;
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>
	::BuildLeftLowerInside(Bisect3Node* node)
{
	// �� 000, 100
	node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetMidXBeginYBeginZFirstValue(),
					   m_Bisect3Storage.GetMidXBeginYBeginZSecondValue(),
					   m_Bisect3Storage.GetMidXBeginYBeginZThirdValue());

	// �� 000, 010
	node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetBeginXMidYBeginZFirstValue(),
					   m_Bisect3Storage.GetBeginXMidYBeginZSecondValue(),
					   m_Bisect3Storage.GetBeginXMidYBeginZThirdValue());

	// �� 000, 100, 110, 010��
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetBeginPointZ(),
								   m_Bisect3Storage.GetMidXMidYBeginZFirstValue(),
								   m_Bisect3Storage.GetMidXMidYBeginZSecondValue(),
								   m_Bisect3Storage.GetMidXMidYBeginZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());


	// �� 000, 001��
	node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetBeginXBeginYMidZFirstValue(),
					   m_Bisect3Storage.GetBeginXBeginYMidZSecondValue(),
					   m_Bisect3Storage.GetBeginXBeginYMidZThirdValue());

	// �� 000, 100, 001, 101��
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetBeginPointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXBeginYMidZFirstValue(),
								   m_Bisect3Storage.GetMidXBeginYMidZSecondValue(),
								   m_Bisect3Storage.GetMidXBeginYMidZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// �� 000, 010, 011, 001��
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetBeginXMidYMidZFirstValue(),
								   m_Bisect3Storage.GetBeginXMidYMidZSecondValue(),
								   m_Bisect3Storage.GetBeginXMidYMidZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// ���ġ�
	node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
											   m_Bisect3Storage.GetMidpointY(),
											   m_Bisect3Storage.GetMidpointZ(),
											   m_Bisect3Storage.GetMidXMidYMidZFirstValue(),
											   m_Bisect3Storage.GetMidXMidYMidZSecondValue(),
											   m_Bisect3Storage.GetMidXMidYMidZThirdValue());

	node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
	node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>
	::BuildRightLowerInside(Bisect3Node* node)
{
	// ԭ�����ڵ�
	node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetEndXBeginYBeginZFirstValue(),
					   m_Bisect3Storage.GetEndXBeginYBeginZSecondValue(),
					   m_Bisect3Storage.GetEndXBeginYBeginZThirdValue());

	// �� 000, 100, 110, 010
	node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetMidXMidYBeginZFirstValue(),
					   m_Bisect3Storage.GetMidXMidYBeginZSecondValue(),
					   m_Bisect3Storage.GetMidXMidYBeginZThirdValue());

	// �� 100, 110
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetBeginPointZ(),
								   m_Bisect3Storage.GetEndXMidYBeginZFirstValue(),
								   m_Bisect3Storage.GetEndXMidYBeginZSecondValue(),
								   m_Bisect3Storage.GetEndXMidYBeginZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());



	// �� 000, 100, 001, 101
	node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetMidXBeginYMidZFirstValue(),
					   m_Bisect3Storage.GetMidXBeginYMidZSecondValue(),
					   m_Bisect3Storage.GetMidXBeginYMidZThirdValue());

	// �� 100, 101
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetBeginPointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetEndXBeginYMidZFirstValue(),
								   m_Bisect3Storage.GetEndXBeginYMidZSecondValue(),
								   m_Bisect3Storage.GetEndXBeginYMidZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// ���ġ�
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXMidYMidZFirstValue(),
								   m_Bisect3Storage.GetMidXMidYMidZSecondValue(),
								   m_Bisect3Storage.GetMidXMidYMidZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// �� 110, 100, 101, 111
	node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
											   m_Bisect3Storage.GetMidpointY(),
											   m_Bisect3Storage.GetMidpointZ(),
											   m_Bisect3Storage.GetEndXMidYMidZFirstValue(),
											   m_Bisect3Storage.GetEndXMidYMidZSecondValue(),
											   m_Bisect3Storage.GetEndXMidYMidZThirdValue());

	node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
	node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>
	::BuildLeftUpperInside(Bisect3Node* node)
{
	// �� 000, 100��110��010
	node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetMidXMidYBeginZFirstValue(),
					   m_Bisect3Storage.GetMidXMidYBeginZSecondValue(),
					   m_Bisect3Storage.GetMidXMidYBeginZThirdValue());

	// ԭ�����ڵ�
	node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetEndPointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetBeginXEndYBeginZFirstValue(),
					   m_Bisect3Storage.GetBeginXEndYBeginZSecondValue(),
					   m_Bisect3Storage.GetBeginXEndYBeginZThirdValue());

	// �� 110, 010��
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetBeginPointZ(),
								   m_Bisect3Storage.GetMidXEndYBeginZFirstValue(),
								   m_Bisect3Storage.GetMidXEndYBeginZSecondValue(),
								   m_Bisect3Storage.GetMidXEndYBeginZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());


	// ��  000��001��011��010
	node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetBeginXMidYMidZFirstValue(),
					   m_Bisect3Storage.GetBeginXMidYMidZSecondValue(),
					   m_Bisect3Storage.GetBeginXMidYMidZThirdValue());

	// ����
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXMidYMidZFirstValue(),
								   m_Bisect3Storage.GetMidXMidYMidZSecondValue(),
								   m_Bisect3Storage.GetMidXMidYMidZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// �� 011,010
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetBeginXEndYMidZFirstValue(),
								   m_Bisect3Storage.GetBeginXEndYMidZSecondValue(),
								   m_Bisect3Storage.GetBeginXEndYMidZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// �� 010,110,111,011
	node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
											   m_Bisect3Storage.GetEndPointY(),
											   m_Bisect3Storage.GetMidpointZ(),
											   m_Bisect3Storage.GetMidXEndYMidZFirstValue(),
											   m_Bisect3Storage.GetMidXEndYMidZSecondValue(),
											   m_Bisect3Storage.GetMidXEndYMidZThirdValue());

	node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
	node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>
	::BuildRightUpperInside(Bisect3Node* node)
{
	// �� 100 110
	node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetEndXMidYBeginZFirstValue(),
					   m_Bisect3Storage.GetEndXMidYBeginZSecondValue(),
					   m_Bisect3Storage.GetEndXMidYBeginZThirdValue());

	// �� 110, 010
	node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetEndPointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetMidXEndYBeginZFirstValue(),
					   m_Bisect3Storage.GetMidXEndYBeginZSecondValue(),
					   m_Bisect3Storage.GetMidXEndYBeginZThirdValue());

	// ԭ�����ڵ�
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetBeginPointZ(),
								   m_Bisect3Storage.GetEndXEndYBeginZFirstValue(),
								   m_Bisect3Storage.GetEndXEndYBeginZSecondValue(),
								   m_Bisect3Storage.GetEndXEndYBeginZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

	// ����
	node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetMidXBeginYMidZFirstValue(),
					   m_Bisect3Storage.GetMidXBeginYMidZSecondValue(),
					   m_Bisect3Storage.GetMidXBeginYMidZThirdValue());

	// �� 100, 110, 111, 101��
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetEndXMidYMidZFirstValue(),
								   m_Bisect3Storage.GetEndXMidYMidZSecondValue(),
								   m_Bisect3Storage.GetEndXMidYMidZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// �� 011,111,110,010
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXEndYMidZFirstValue(),
								   m_Bisect3Storage.GetMidXEndYMidZSecondValue(),
								   m_Bisect3Storage.GetMidXEndYMidZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// ��110��111
	node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
											   m_Bisect3Storage.GetEndPointY(),
											   m_Bisect3Storage.GetMidpointZ(),
											   m_Bisect3Storage.GetEndXEndYMidZFirstValue(),
											   m_Bisect3Storage.GetEndXEndYMidZSecondValue(),
											   m_Bisect3Storage.GetEndXEndYMidZThirdValue());

	node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
	node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>
	::BuildLeftLowerOutside(Bisect3Node* node)
{
	// �� 000, 100��101��001
	node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetMidXBeginYMidZFirstValue(),
					   m_Bisect3Storage.GetMidXBeginYMidZSecondValue(),
					   m_Bisect3Storage.GetMidXBeginYMidZThirdValue());

	// �� 000, 001��011��010
	node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetBeginXMidYMidZFirstValue(),
					   m_Bisect3Storage.GetBeginXMidYMidZSecondValue(),
					   m_Bisect3Storage.GetBeginXMidYMidZThirdValue());

	// ����
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXMidYMidZFirstValue(),
								   m_Bisect3Storage.GetMidXMidYMidZSecondValue(),
								   m_Bisect3Storage.GetMidXMidYMidZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());


	// ԭ�������
	node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetEndPointZ(),
					   m_Bisect3Storage.GetBeginXBeginYEndZFirstValue(),
					   m_Bisect3Storage.GetBeginXBeginYEndZSecondValue(),
					   m_Bisect3Storage.GetBeginXBeginYEndZThirdValue());

	// ��001,101
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetBeginPointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetMidXBeginYEndZFirstValue(),
								   m_Bisect3Storage.GetMidXBeginYEndZSecondValue(),
								   m_Bisect3Storage.GetMidXBeginYEndZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// ��001,011
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetBeginXMidYEndZFirstValue(),
								   m_Bisect3Storage.GetBeginXMidYEndZSecondValue(),
								   m_Bisect3Storage.GetBeginXMidYEndZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// �� 001,101,111,011
	node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(),
											   m_Bisect3Storage.GetEndPointZ(), m_Bisect3Storage.GetMidXMidYEndZFirstValue(),
											   m_Bisect3Storage.GetMidXMidYEndZSecondValue(), m_Bisect3Storage.GetMidXMidYEndZThirdValue());

	node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
	node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>
	::BuildRightLowerOutside(Bisect3Node* node)
{
	// ��100,101
	node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetEndXBeginYMidZFirstValue(),
					   m_Bisect3Storage.GetEndXBeginYMidZSecondValue(),
					   m_Bisect3Storage.GetEndXBeginYMidZThirdValue());

	// ����
	node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetMidXMidYMidZFirstValue(),
					   m_Bisect3Storage.GetMidXMidYMidZSecondValue(),
					   m_Bisect3Storage.GetMidXMidYMidZThirdValue());

	// ��100��101��111��110
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetEndXMidYMidZFirstValue(),
								   m_Bisect3Storage.GetEndXMidYMidZSecondValue(),
								   m_Bisect3Storage.GetEndXMidYMidZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

	// ��001,101
	node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetEndPointZ(),
					   m_Bisect3Storage.GetMidXBeginYEndZFirstValue(),
					   m_Bisect3Storage.GetMidXBeginYEndZSecondValue(),
					   m_Bisect3Storage.GetMidXBeginYEndZThirdValue());

	// ��001,101,111,011
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetBeginPointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetEndXBeginYEndZFirstValue(),
								   m_Bisect3Storage.GetEndXBeginYEndZSecondValue(),
								   m_Bisect3Storage.GetEndXBeginYEndZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// ��001��101��111��011
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetMidXMidYEndZFirstValue(),
								   m_Bisect3Storage.GetMidXMidYEndZSecondValue(),
								   m_Bisect3Storage.GetMidXMidYEndZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// ��101,111
	node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetEndPointZ(),
											   m_Bisect3Storage.GetEndXMidYEndZFirstValue(), m_Bisect3Storage.GetEndXMidYEndZSecondValue(), m_Bisect3Storage.GetEndXMidYEndZThirdValue());

	node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
	node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>
	::BuildLeftUpperOutside(Bisect3Node* node)
{
	// ����
	node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetMidXMidYMidZFirstValue(),
					   m_Bisect3Storage.GetMidXMidYMidZSecondValue(),
					   m_Bisect3Storage.GetMidXMidYMidZThirdValue());

	// ��011,010
	node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetEndPointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetBeginXEndYMidZFirstValue(),
					   m_Bisect3Storage.GetBeginXEndYMidZSecondValue(),
					   m_Bisect3Storage.GetBeginXEndYMidZThirdValue());

	// ��011��010��110��111
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXEndYMidZFirstValue(),
								   m_Bisect3Storage.GetMidXEndYMidZSecondValue(),
								   m_Bisect3Storage.GetMidXEndYMidZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());


	// �� 001,011
	node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetEndPointZ(),
					   m_Bisect3Storage.GetBeginXMidYEndZFirstValue(),
					   m_Bisect3Storage.GetBeginXMidYEndZSecondValue(),
					   m_Bisect3Storage.GetBeginXMidYEndZThirdValue());

	// ��001��101��111��011
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetMidXMidYEndZFirstValue(),
								   m_Bisect3Storage.GetMidXMidYEndZSecondValue(),
								   m_Bisect3Storage.GetMidXMidYEndZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// ԭ�������
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetBeginXEndYEndZFirstValue(),
								   m_Bisect3Storage.GetBeginXEndYEndZSecondValue(),
								   m_Bisect3Storage.GetBeginXEndYEndZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// ��011��111
	node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetEndPointY(), m_Bisect3Storage.GetEndPointZ(),
											   m_Bisect3Storage.GetMidXEndYEndZFirstValue(), m_Bisect3Storage.GetMidXEndYEndZSecondValue(), m_Bisect3Storage.GetMidXEndYEndZThirdValue());

	node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
	node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>
	::BuildRightUpperOutside(Bisect3Node* node)
{
	// ��110,100,101,111
	node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetEndXMidYMidZFirstValue(),
					   m_Bisect3Storage.GetEndXMidYMidZSecondValue(),
					   m_Bisect3Storage.GetEndXMidYMidZThirdValue());

	// ��010��110��111��011
	node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetEndPointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetMidXEndYMidZFirstValue(),
					   m_Bisect3Storage.GetMidXEndYMidZSecondValue(),
					   m_Bisect3Storage.GetMidXEndYMidZThirdValue());

	// ��110,111
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetEndXEndYMidZFirstValue(),
								   m_Bisect3Storage.GetEndXEndYMidZSecondValue(),
								   m_Bisect3Storage.GetEndXEndYMidZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());


	// ��011��111��101��001
	node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetEndPointZ(),
					   m_Bisect3Storage.GetMidXBeginYEndZFirstValue(),
					   m_Bisect3Storage.GetMidXBeginYEndZSecondValue(),
					   m_Bisect3Storage.GetMidXBeginYEndZThirdValue());

	// �� 100, 110, 100, 101��
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetEndXMidYEndZFirstValue(),
								   m_Bisect3Storage.GetEndXMidYEndZSecondValue(),
								   m_Bisect3Storage.GetEndXMidYEndZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// ��011��111
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetMidXEndYEndZFirstValue(),
								   m_Bisect3Storage.GetMidXEndYEndZSecondValue(),
								   m_Bisect3Storage.GetMidXEndYEndZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// ԭ�������
	node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(), m_Bisect3Storage.GetEndPointY(), m_Bisect3Storage.GetEndPointZ(),
											   m_Bisect3Storage.GetEndXEndYEndZFirstValue(), m_Bisect3Storage.GetEndXEndYEndZSecondValue(), m_Bisect3Storage.GetEndXEndYEndZThirdValue());

	node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
	node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_DETAIL_H

