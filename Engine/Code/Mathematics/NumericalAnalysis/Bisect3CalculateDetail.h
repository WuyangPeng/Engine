// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 13:39)

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
	MATHEMATICS_ASSERTION_2(beginPointX <= endPointX, "起点的X值比终点的X值大。");
	MATHEMATICS_ASSERTION_2(beginPointY <= endPointY, "起点的Y值比终点的Y值大。");
	MATHEMATICS_ASSERTION_2(beginPointZ <= endPointZ, "起点的Z值比终点的Z值大。");

	// 测试的八个角的值。
	if (m_Bisect3Storage.TestEightCornerValues(beginPointX, beginPointY, beginPointZ, endPointX, endPointY, endPointZ))
	{
		m_Bisect3Root = m_Bisect3Storage.GetBisect3RootPtr();

		return;
	}

	// 构建初始八边形

	// 增加 N000。
	m_Graph = std::make_shared<Bisect3Node>(beginPointX, beginPointY, beginPointZ,
											m_Bisect3Storage.GetBeginXBeginYBeginZFirstValue(),
											m_Bisect3Storage.GetBeginXBeginYBeginZSecondValue(),
											m_Bisect3Storage.GetBeginXBeginYBeginZThirdValue());

	// 增加 N100。
	m_Graph->AddXNextNode(endPointX, beginPointY, beginPointZ,
						  m_Bisect3Storage.GetEndXBeginYBeginZFirstValue(),
						  m_Bisect3Storage.GetEndXBeginYBeginZSecondValue(),
						  m_Bisect3Storage.GetEndXBeginYBeginZThirdValue());


	// 增加 N010。
	m_Graph->AddYNextNode(beginPointX, endPointY, beginPointZ,
						  m_Bisect3Storage.GetBeginXEndYBeginZFirstValue(),
						  m_Bisect3Storage.GetBeginXEndYBeginZSecondValue(),
						  m_Bisect3Storage.GetBeginXEndYBeginZThirdValue());


	// 增加 N110。
	m_Graph->GetXNext()->AddYNextNode(endPointX, endPointY, beginPointZ,
									  m_Bisect3Storage.GetEndXEndYBeginZFirstValue(),
									  m_Bisect3Storage.GetEndXEndYBeginZSecondValue(),
									  m_Bisect3Storage.GetEndXEndYBeginZThirdValue());

	m_Graph->GetYNext()->AddXNextNode(m_Graph->GetXNext()->GetYNext());



	// 增加 N001。
	m_Graph->AddZNextNode(beginPointX, beginPointY, endPointZ,
						  m_Bisect3Storage.GetBeginXBeginYEndZFirstValue(),
						  m_Bisect3Storage.GetBeginXBeginYEndZSecondValue(),
						  m_Bisect3Storage.GetBeginXBeginYEndZThirdValue());


	// 增加 N101。
	m_Graph->GetXNext()->AddZNextNode(endPointX, beginPointY, endPointZ,
									  m_Bisect3Storage.GetEndXBeginYEndZFirstValue(),
									  m_Bisect3Storage.GetEndXBeginYEndZSecondValue(),
									  m_Bisect3Storage.GetEndXBeginYEndZThirdValue());

	m_Graph->GetZNext()->AddXNextNode(m_Graph->GetXNext()->GetZNext());

	// 增加 N011。
	m_Graph->GetYNext()->AddZNextNode(beginPointX, endPointY, endPointZ,
									  m_Bisect3Storage.GetBeginXEndYEndZFirstValue(),
									  m_Bisect3Storage.GetBeginXEndYEndZSecondValue(),
									  m_Bisect3Storage.GetBeginXEndYEndZThirdValue());

	m_Graph->GetZNext()->AddYNextNode(m_Graph->GetYNext()->GetZNext());


	// 增加 N111。
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

	// 将剩下的四边形从m_Graph中移除。
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
		// 递归超出了次数，返回一个中间值。
		--m_Level;
		m_Bisect3Root = std::make_shared<Bisect3Root>(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetMidpointZ(), BisectRootType::Unknown);

		return false;
	}

	if (node->IsFirstFunctionResultSameSign() || node->IsSecondFunctionResultSameSign() || node->IsThirdFunctionResultSameSign())
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
	Bisect3Node leftLowerInside{ m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetBeginPointZ(),
								 m_Bisect3Storage.GetBeginXBeginYBeginZFirstValue(), m_Bisect3Storage.GetBeginXBeginYBeginZSecondValue(), m_Bisect3Storage.GetBeginXBeginYBeginZThirdValue() };

	BuildLeftLowerInside(&leftLowerInside);


	// 构建右下内的立方体

	// 边 000, 100
	Bisect3Node rightLowerInside{ m_Bisect3Storage.GetMidpointX(),m_Bisect3Storage.GetBeginPointY(),m_Bisect3Storage.GetBeginPointZ(),
								  m_Bisect3Storage.GetMidXBeginYBeginZFirstValue(),m_Bisect3Storage.GetMidXBeginYBeginZSecondValue(),m_Bisect3Storage.GetMidXBeginYBeginZThirdValue() };

	BuildRightLowerInside(&rightLowerInside);

	// 构建左上内的立方体

	// 边 000, 010
	Bisect3Node leftUpperInside{ m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetBeginPointZ(),
								 m_Bisect3Storage.GetBeginXMidYBeginZFirstValue(), m_Bisect3Storage.GetBeginXMidYBeginZSecondValue(), m_Bisect3Storage.GetBeginXMidYBeginZThirdValue() };

	BuildLeftUpperInside(&leftUpperInside);


	// 构建右上内的立方体

	// 面 000, 100, 110, 010
	Bisect3Node rightUpperInside{ m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetBeginPointZ(),
								  m_Bisect3Storage.GetMidXMidYBeginZFirstValue(),  m_Bisect3Storage.GetMidXMidYBeginZSecondValue(), m_Bisect3Storage.GetMidXMidYBeginZThirdValue() };

	BuildRightUpperInside(&rightUpperInside);

	// 构建左下外的立方体

	// 边 000, 001
	Bisect3Node leftLowerOutside{ m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetMidpointZ(),
								  m_Bisect3Storage.GetBeginXBeginYMidZFirstValue(),  m_Bisect3Storage.GetBeginXBeginYMidZSecondValue(), m_Bisect3Storage.GetBeginXBeginYMidZThirdValue() };

	BuildLeftLowerOutside(&leftLowerOutside);


	// 构建右下外的立方体

	// 面 000, 100, 001, 101
	Bisect3Node rightLowerOutside{ m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetBeginPointY(), m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXBeginYMidZFirstValue(), m_Bisect3Storage.GetMidXBeginYMidZSecondValue(), m_Bisect3Storage.GetMidXBeginYMidZThirdValue() };

	BuildRightLowerOutside(&rightLowerOutside);

	// 构建左上外的立方体

	// 面 000, 010, 011, 001
	Bisect3Node leftUpperOutside{ m_Bisect3Storage.GetBeginPointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetMidpointZ(),
								  m_Bisect3Storage.GetBeginXMidYMidZFirstValue(), m_Bisect3Storage.GetBeginXMidYMidZSecondValue(), m_Bisect3Storage.GetBeginXMidYMidZThirdValue() };

	BuildLeftUpperOutside(&leftUpperOutside);


	// 构建右上外的立方体

	// 中心
	Bisect3Node rightUpperOutside{ m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXMidYMidZFirstValue(), m_Bisect3Storage.GetMidXMidYMidZSecondValue(), m_Bisect3Storage.GetMidXMidYMidZThirdValue() };

	BuildRightUpperOutside(&rightUpperOutside);

	// 搜索子立方体的根。
	auto result = BisectRecurse(&leftLowerInside) || BisectRecurse(&rightLowerInside) ||
				  BisectRecurse(&leftUpperInside) || BisectRecurse(&rightUpperInside) ||
				  BisectRecurse(&leftLowerOutside) || BisectRecurse(&rightLowerOutside) ||
				  BisectRecurse(&leftUpperOutside) || BisectRecurse(&rightUpperOutside);

	// 整个子八边形检查失败，删除添加的节点。

	--m_Level;

	return result;
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>
	::BuildLeftLowerInside(Bisect3Node* node)
{
	// 边 000, 100
	node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetMidXBeginYBeginZFirstValue(),
					   m_Bisect3Storage.GetMidXBeginYBeginZSecondValue(),
					   m_Bisect3Storage.GetMidXBeginYBeginZThirdValue());

	// 边 000, 010
	node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetBeginXMidYBeginZFirstValue(),
					   m_Bisect3Storage.GetBeginXMidYBeginZSecondValue(),
					   m_Bisect3Storage.GetBeginXMidYBeginZThirdValue());

	// 面 000, 100, 110, 010。
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetBeginPointZ(),
								   m_Bisect3Storage.GetMidXMidYBeginZFirstValue(),
								   m_Bisect3Storage.GetMidXMidYBeginZSecondValue(),
								   m_Bisect3Storage.GetMidXMidYBeginZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());


	// 边 000, 001。
	node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetBeginXBeginYMidZFirstValue(),
					   m_Bisect3Storage.GetBeginXBeginYMidZSecondValue(),
					   m_Bisect3Storage.GetBeginXBeginYMidZThirdValue());

	// 面 000, 100, 001, 101。
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetBeginPointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXBeginYMidZFirstValue(),
								   m_Bisect3Storage.GetMidXBeginYMidZSecondValue(),
								   m_Bisect3Storage.GetMidXBeginYMidZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// 面 000, 010, 011, 001。
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetBeginXMidYMidZFirstValue(),
								   m_Bisect3Storage.GetBeginXMidYMidZSecondValue(),
								   m_Bisect3Storage.GetBeginXMidYMidZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// 中心。
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
	// 原右下内点
	node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetEndXBeginYBeginZFirstValue(),
					   m_Bisect3Storage.GetEndXBeginYBeginZSecondValue(),
					   m_Bisect3Storage.GetEndXBeginYBeginZThirdValue());

	// 面 000, 100, 110, 010
	node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetMidXMidYBeginZFirstValue(),
					   m_Bisect3Storage.GetMidXMidYBeginZSecondValue(),
					   m_Bisect3Storage.GetMidXMidYBeginZThirdValue());

	// 边 100, 110
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetBeginPointZ(),
								   m_Bisect3Storage.GetEndXMidYBeginZFirstValue(),
								   m_Bisect3Storage.GetEndXMidYBeginZSecondValue(),
								   m_Bisect3Storage.GetEndXMidYBeginZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());



	// 面 000, 100, 001, 101
	node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetMidXBeginYMidZFirstValue(),
					   m_Bisect3Storage.GetMidXBeginYMidZSecondValue(),
					   m_Bisect3Storage.GetMidXBeginYMidZThirdValue());

	// 边 100, 101
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetBeginPointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetEndXBeginYMidZFirstValue(),
								   m_Bisect3Storage.GetEndXBeginYMidZSecondValue(),
								   m_Bisect3Storage.GetEndXBeginYMidZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// 中心。
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXMidYMidZFirstValue(),
								   m_Bisect3Storage.GetMidXMidYMidZSecondValue(),
								   m_Bisect3Storage.GetMidXMidYMidZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// 面 110, 100, 101, 111
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
	// 面 000, 100，110，010
	node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetMidXMidYBeginZFirstValue(),
					   m_Bisect3Storage.GetMidXMidYBeginZSecondValue(),
					   m_Bisect3Storage.GetMidXMidYBeginZThirdValue());

	// 原左上内点
	node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetEndPointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetBeginXEndYBeginZFirstValue(),
					   m_Bisect3Storage.GetBeginXEndYBeginZSecondValue(),
					   m_Bisect3Storage.GetBeginXEndYBeginZThirdValue());

	// 边 110, 010。
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetBeginPointZ(),
								   m_Bisect3Storage.GetMidXEndYBeginZFirstValue(),
								   m_Bisect3Storage.GetMidXEndYBeginZSecondValue(),
								   m_Bisect3Storage.GetMidXEndYBeginZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());


	// 面  000，001，011，010
	node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetBeginXMidYMidZFirstValue(),
					   m_Bisect3Storage.GetBeginXMidYMidZSecondValue(),
					   m_Bisect3Storage.GetBeginXMidYMidZThirdValue());

	// 中心
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXMidYMidZFirstValue(),
								   m_Bisect3Storage.GetMidXMidYMidZSecondValue(),
								   m_Bisect3Storage.GetMidXMidYMidZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// 边 011,010
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetBeginXEndYMidZFirstValue(),
								   m_Bisect3Storage.GetBeginXEndYMidZSecondValue(),
								   m_Bisect3Storage.GetBeginXEndYMidZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// 面 010,110,111,011
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
	// 边 100 110
	node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetEndXMidYBeginZFirstValue(),
					   m_Bisect3Storage.GetEndXMidYBeginZSecondValue(),
					   m_Bisect3Storage.GetEndXMidYBeginZThirdValue());

	// 边 110, 010
	node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetEndPointY(),
					   m_Bisect3Storage.GetBeginPointZ(),
					   m_Bisect3Storage.GetMidXEndYBeginZFirstValue(),
					   m_Bisect3Storage.GetMidXEndYBeginZSecondValue(),
					   m_Bisect3Storage.GetMidXEndYBeginZThirdValue());

	// 原右上内点
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetBeginPointZ(),
								   m_Bisect3Storage.GetEndXEndYBeginZFirstValue(),
								   m_Bisect3Storage.GetEndXEndYBeginZSecondValue(),
								   m_Bisect3Storage.GetEndXEndYBeginZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

	// 中心
	node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetMidXBeginYMidZFirstValue(),
					   m_Bisect3Storage.GetMidXBeginYMidZSecondValue(),
					   m_Bisect3Storage.GetMidXBeginYMidZThirdValue());

	// 面 100, 110, 111, 101。
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetEndXMidYMidZFirstValue(),
								   m_Bisect3Storage.GetEndXMidYMidZSecondValue(),
								   m_Bisect3Storage.GetEndXMidYMidZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// 面 011,111,110,010
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXEndYMidZFirstValue(),
								   m_Bisect3Storage.GetMidXEndYMidZSecondValue(),
								   m_Bisect3Storage.GetMidXEndYMidZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// 边110，111
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
	// 面 000, 100，101，001
	node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetMidXBeginYMidZFirstValue(),
					   m_Bisect3Storage.GetMidXBeginYMidZSecondValue(),
					   m_Bisect3Storage.GetMidXBeginYMidZThirdValue());

	// 面 000, 001，011，010
	node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetBeginXMidYMidZFirstValue(),
					   m_Bisect3Storage.GetBeginXMidYMidZSecondValue(),
					   m_Bisect3Storage.GetBeginXMidYMidZThirdValue());

	// 中心
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXMidYMidZFirstValue(),
								   m_Bisect3Storage.GetMidXMidYMidZSecondValue(),
								   m_Bisect3Storage.GetMidXMidYMidZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());


	// 原左下外点
	node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetEndPointZ(),
					   m_Bisect3Storage.GetBeginXBeginYEndZFirstValue(),
					   m_Bisect3Storage.GetBeginXBeginYEndZSecondValue(),
					   m_Bisect3Storage.GetBeginXBeginYEndZThirdValue());

	// 边001,101
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetBeginPointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetMidXBeginYEndZFirstValue(),
								   m_Bisect3Storage.GetMidXBeginYEndZSecondValue(),
								   m_Bisect3Storage.GetMidXBeginYEndZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// 边001,011
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetBeginXMidYEndZFirstValue(),
								   m_Bisect3Storage.GetBeginXMidYEndZSecondValue(),
								   m_Bisect3Storage.GetBeginXMidYEndZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// 面 001,101,111,011
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
	// 边100,101
	node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetEndXBeginYMidZFirstValue(),
					   m_Bisect3Storage.GetEndXBeginYMidZSecondValue(),
					   m_Bisect3Storage.GetEndXBeginYMidZThirdValue());

	// 中心
	node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetMidXMidYMidZFirstValue(),
					   m_Bisect3Storage.GetMidXMidYMidZSecondValue(),
					   m_Bisect3Storage.GetMidXMidYMidZThirdValue());

	// 面100，101，111，110
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetEndXMidYMidZFirstValue(),
								   m_Bisect3Storage.GetEndXMidYMidZSecondValue(),
								   m_Bisect3Storage.GetEndXMidYMidZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());

	// 边001,101
	node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetBeginPointY(),
					   m_Bisect3Storage.GetEndPointZ(),
					   m_Bisect3Storage.GetMidXBeginYEndZFirstValue(),
					   m_Bisect3Storage.GetMidXBeginYEndZSecondValue(),
					   m_Bisect3Storage.GetMidXBeginYEndZThirdValue());

	// 面001,101,111,011
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetBeginPointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetEndXBeginYEndZFirstValue(),
								   m_Bisect3Storage.GetEndXBeginYEndZSecondValue(),
								   m_Bisect3Storage.GetEndXBeginYEndZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// 面001，101，111，011
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetMidXMidYEndZFirstValue(),
								   m_Bisect3Storage.GetMidXMidYEndZSecondValue(),
								   m_Bisect3Storage.GetMidXMidYEndZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// 边101,111
	node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(), m_Bisect3Storage.GetMidpointY(), m_Bisect3Storage.GetEndPointZ(),
											   m_Bisect3Storage.GetEndXMidYEndZFirstValue(), m_Bisect3Storage.GetEndXMidYEndZSecondValue(), m_Bisect3Storage.GetEndXMidYEndZThirdValue());

	node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
	node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>
	::BuildLeftUpperOutside(Bisect3Node* node)
{
	// 中心
	node->AddXNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetMidXMidYMidZFirstValue(),
					   m_Bisect3Storage.GetMidXMidYMidZSecondValue(),
					   m_Bisect3Storage.GetMidXMidYMidZThirdValue());

	// 边011,010
	node->AddYNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetEndPointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetBeginXEndYMidZFirstValue(),
					   m_Bisect3Storage.GetBeginXEndYMidZSecondValue(),
					   m_Bisect3Storage.GetBeginXEndYMidZThirdValue());

	// 面011，010，110，111
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetMidXEndYMidZFirstValue(),
								   m_Bisect3Storage.GetMidXEndYMidZSecondValue(),
								   m_Bisect3Storage.GetMidXEndYMidZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());


	// 边 001,011
	node->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetEndPointZ(),
					   m_Bisect3Storage.GetBeginXMidYEndZFirstValue(),
					   m_Bisect3Storage.GetBeginXMidYEndZSecondValue(),
					   m_Bisect3Storage.GetBeginXMidYEndZThirdValue());

	// 面001，101，111，011
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetMidXMidYEndZFirstValue(),
								   m_Bisect3Storage.GetMidXMidYEndZSecondValue(),
								   m_Bisect3Storage.GetMidXMidYEndZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// 原左上外点
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetBeginPointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetBeginXEndYEndZFirstValue(),
								   m_Bisect3Storage.GetBeginXEndYEndZSecondValue(),
								   m_Bisect3Storage.GetBeginXEndYEndZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// 边011，111
	node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(), m_Bisect3Storage.GetEndPointY(), m_Bisect3Storage.GetEndPointZ(),
											   m_Bisect3Storage.GetMidXEndYEndZFirstValue(), m_Bisect3Storage.GetMidXEndYEndZSecondValue(), m_Bisect3Storage.GetMidXEndYEndZThirdValue());

	node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
	node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

template <typename Real>
void Mathematics::Bisect3Calculate<Real>
	::BuildRightUpperOutside(Bisect3Node* node)
{
	// 面110,100,101,111
	node->AddXNextNode(m_Bisect3Storage.GetEndPointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetEndXMidYMidZFirstValue(),
					   m_Bisect3Storage.GetEndXMidYMidZSecondValue(),
					   m_Bisect3Storage.GetEndXMidYMidZThirdValue());

	// 面010，110，111，011
	node->AddYNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetEndPointY(),
					   m_Bisect3Storage.GetMidpointZ(),
					   m_Bisect3Storage.GetMidXEndYMidZFirstValue(),
					   m_Bisect3Storage.GetMidXEndYMidZSecondValue(),
					   m_Bisect3Storage.GetMidXEndYMidZThirdValue());

	// 边110,111
	node->GetXNext()->AddYNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetMidpointZ(),
								   m_Bisect3Storage.GetEndXEndYMidZFirstValue(),
								   m_Bisect3Storage.GetEndXEndYMidZSecondValue(),
								   m_Bisect3Storage.GetEndXEndYMidZThirdValue());

	node->GetYNext()->AddXNextNode(node->GetXNext()->GetYNext());


	// 面011，111，101，001
	node->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
					   m_Bisect3Storage.GetMidpointY(),
					   m_Bisect3Storage.GetEndPointZ(),
					   m_Bisect3Storage.GetMidXBeginYEndZFirstValue(),
					   m_Bisect3Storage.GetMidXBeginYEndZSecondValue(),
					   m_Bisect3Storage.GetMidXBeginYEndZThirdValue());

	// 面 100, 110, 100, 101。
	node->GetXNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(),
								   m_Bisect3Storage.GetMidpointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetEndXMidYEndZFirstValue(),
								   m_Bisect3Storage.GetEndXMidYEndZSecondValue(),
								   m_Bisect3Storage.GetEndXMidYEndZThirdValue());

	node->GetZNext()->AddXNextNode(node->GetXNext()->GetZNext());


	// 边011，111
	node->GetYNext()->AddZNextNode(m_Bisect3Storage.GetMidpointX(),
								   m_Bisect3Storage.GetEndPointY(),
								   m_Bisect3Storage.GetEndPointZ(),
								   m_Bisect3Storage.GetMidXEndYEndZFirstValue(),
								   m_Bisect3Storage.GetMidXEndYEndZSecondValue(),
								   m_Bisect3Storage.GetMidXEndYEndZThirdValue());

	node->GetZNext()->AddYNextNode(node->GetYNext()->GetZNext());

	// 原右上外点
	node->GetXNext()->GetYNext()->AddZNextNode(m_Bisect3Storage.GetEndPointX(), m_Bisect3Storage.GetEndPointY(), m_Bisect3Storage.GetEndPointZ(),
											   m_Bisect3Storage.GetEndXEndYEndZFirstValue(), m_Bisect3Storage.GetEndXEndYEndZSecondValue(), m_Bisect3Storage.GetEndXEndYEndZThirdValue());

	node->GetYNext()->GetXNext()->AddZNextNode(node->GetXNext()->GetYNext()->GetZNext());
	node->GetXNext()->GetZNext()->AddYNextNode(node->GetXNext()->GetYNext()->GetZNext());
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_CALCULATE_DETAIL_H

