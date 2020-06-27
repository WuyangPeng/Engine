// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 13:34)

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
	MATHEMATICS_ASSERTION_1(beginPointX <= endPointX, "起点的X值比终点的X值大。");
	MATHEMATICS_ASSERTION_1(beginPointY <= endPointY, "起点的Y值比终点的Y值大。");

	// 测试的四个角的值。
	if (m_Bisect2Storage.TestFourCornerValues(beginPointX, beginPointY, endPointX, endPointY))
	{
		m_Bisect2Root = m_Bisect2Storage.GetBisect2RootPtr();

		return;
	}

	// 构建初始四边形。

	// 增加 N00。
	m_Graph = std::make_shared <Bisect2Node>(beginPointX, beginPointY, m_Bisect2Storage.GetBeginXAndBeginYFirstValue(), m_Bisect2Storage.GetBeginXAndBeginYSecondValue());


	// 增加 N10。
	m_Graph->AddXNextNode(endPointX, beginPointY, m_Bisect2Storage.GetEndXAndBeginYFirstValue(), m_Bisect2Storage.GetEndXAndBeginYSecondValue());

	// 增加 N01。
	m_Graph->AddYNextNode(beginPointX, endPointY, m_Bisect2Storage.GetBeginXAndEndYFirstValue(), m_Bisect2Storage.GetBeginXAndEndYSecondValue());

	// 增加 N11。
	m_Graph->GetXNext()->AddYNextNode(endPointX, endPointY, m_Bisect2Storage.GetEndXAndEndYFirstValue(), m_Bisect2Storage.GetEndXAndEndYSecondValue());
	m_Graph->GetYNext()->AddXNextNode(m_Graph->GetXNext()->GetYNext());


	auto result = BisectRecurse(m_Graph.get());

	if (result)
	{
		m_Bisect2Root = m_Bisect2Storage.GetBisect2RootPtr();
	}

	// 将剩下的四边形从m_Graph中移除。
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
		// 递归超出了次数，返回一个中间值。
		--m_Level;
		m_Bisect2Root = std::make_shared<Bisect2Root>(m_Bisect2Storage.GetMidpointX(), m_Bisect2Storage.GetMidpointY(), BisectRootType::Unknown);

		return false;
	}

	// 可优化：在某个区间无解时快速退出，而不仅仅判断边界点具有相同的符号。
	if (node->IsFirstFunctionResultSameSign() || node->IsSecondFunctionResultSameSign())
	{
		// FirstFunction具有相同的符号在边界点。
		// 或者GecondFunction具有相同的符号在边界点。

		// 方程在这个区间无解
		--m_Level;

		return false;
	}

	// 二等分四边形。
	m_Bisect2Storage.SetStorageValue(node);

	if (m_Bisect2Storage.TestEdgeValues())
	{
		return true;
	}

	// 将四边形分成四个四边形进行递归搜索。

	// 构建左上角的四边形

	// 原左上角点
	Bisect2Node leftUpper{ m_Bisect2Storage.GetBeginPointX(),m_Bisect2Storage.GetBeginPointY(),
						   m_Bisect2Storage.GetBeginXAndBeginYFirstValue(), m_Bisect2Storage.GetBeginXAndBeginYSecondValue() };

	// 顶部的平分线
	leftUpper.AddXNextNode(m_Bisect2Storage.GetMidpointX(),
						   m_Bisect2Storage.GetBeginPointY(),
						   m_Bisect2Storage.GetMidXAndBeginYFirstValue(),
						   m_Bisect2Storage.GetMidXAndBeginYSecondValue());

	// 左边的平分线
	leftUpper.AddYNextNode(m_Bisect2Storage.GetBeginPointX(),
						   m_Bisect2Storage.GetMidpointY(),
						   m_Bisect2Storage.GetBeginXAndMidYFirstValue(),
						   m_Bisect2Storage.GetBeginXAndMidYSecondValue());

	// 中间的平分线
	leftUpper.GetXNext()->AddYNextNode(m_Bisect2Storage.GetMidpointX(),
									   m_Bisect2Storage.GetMidpointY(),
									   m_Bisect2Storage.GetMidXAndMidYFirstValue(),
									   m_Bisect2Storage.GetMidXAndMidYSecondValue());

	leftUpper.GetYNext()->AddXNextNode(leftUpper.GetXNext()->GetYNext());

	// 构建右上角的四边形

	// 顶部的平分线
	Bisect2Node rightUpper{ m_Bisect2Storage.GetMidpointX(), m_Bisect2Storage.GetBeginPointY(),
							m_Bisect2Storage.GetMidXAndBeginYFirstValue(), m_Bisect2Storage.GetMidXAndBeginYSecondValue() };

	// 原右上角点
	rightUpper.AddXNextNode(m_Bisect2Storage.GetEndPointX(),
							m_Bisect2Storage.GetBeginPointY(),
							m_Bisect2Storage.GetEndXAndBeginYFirstValue(),
							m_Bisect2Storage.GetEndXAndBeginYSecondValue());

	// 中间的平分线
	rightUpper.AddYNextNode(m_Bisect2Storage.GetMidpointX(),
							m_Bisect2Storage.GetMidpointY(),
							m_Bisect2Storage.GetMidXAndMidYFirstValue(),
							m_Bisect2Storage.GetMidXAndMidYSecondValue());

	// 右边的平分线
	rightUpper.GetXNext()->AddYNextNode(m_Bisect2Storage.GetEndPointX(),
										m_Bisect2Storage.GetMidpointY(),
										m_Bisect2Storage.GetEndXAndMidYFirstValue(),
										m_Bisect2Storage.GetEndXAndMidYSecondValue());

	rightUpper.GetYNext()->AddXNextNode(rightUpper.GetXNext()->GetYNext());

	// 构建左下角的四边形

	// 左边的平分线
	Bisect2Node leftLower{ m_Bisect2Storage.GetBeginPointX(), m_Bisect2Storage.GetMidpointY(),
						   m_Bisect2Storage.GetBeginXAndMidYFirstValue(), m_Bisect2Storage.GetBeginXAndMidYSecondValue() };

	// 中间的平分线
	leftLower.AddXNextNode(m_Bisect2Storage.GetMidpointX(),
						   m_Bisect2Storage.GetMidpointY(),
						   m_Bisect2Storage.GetMidXAndMidYFirstValue(),
						   m_Bisect2Storage.GetMidXAndMidYSecondValue());

	// 原左下角点
	leftLower.AddYNextNode(m_Bisect2Storage.GetBeginPointX(),
						   m_Bisect2Storage.GetEndPointY(),
						   m_Bisect2Storage.GetBeginXAndEndYFirstValue(),
						   m_Bisect2Storage.GetBeginXAndEndYSecondValue());

	// 底部的平分线
	leftLower.GetXNext()->AddYNextNode(m_Bisect2Storage.GetMidpointX(),
									   m_Bisect2Storage.GetEndPointY(),
									   m_Bisect2Storage.GetMidXAndEndYFirstValue(),
									   m_Bisect2Storage.GetMidXAndEndYSecondValue());

	leftLower.GetYNext()->AddXNextNode(leftLower.GetXNext()->GetYNext());

	// 构建右下角的四边形

	// 中间的平分线
	Bisect2Node rightLower{ m_Bisect2Storage.GetMidpointX(), m_Bisect2Storage.GetMidpointY(),
							m_Bisect2Storage.GetMidXAndMidYFirstValue(), m_Bisect2Storage.GetMidXAndMidYSecondValue() };

	// 右边的平分线
	rightLower.AddXNextNode(m_Bisect2Storage.GetEndPointX(),
							m_Bisect2Storage.GetMidpointY(),
							m_Bisect2Storage.GetEndXAndMidYFirstValue(),
							m_Bisect2Storage.GetEndXAndMidYSecondValue());

	// 底部的平分线
	rightLower.AddYNextNode(m_Bisect2Storage.GetMidpointX(),
							m_Bisect2Storage.GetEndPointY(),
							m_Bisect2Storage.GetMidXAndEndYFirstValue(),
							m_Bisect2Storage.GetMidXAndEndYSecondValue());

	// 原右下角点
	rightLower.GetXNext()->AddYNextNode(m_Bisect2Storage.GetMidpointX(),
										m_Bisect2Storage.GetEndPointY(),
										m_Bisect2Storage.GetMidXAndEndYFirstValue(),
										m_Bisect2Storage.GetMidXAndEndYSecondValue());

	rightLower.GetYNext()->AddXNextNode(rightLower.GetXNext()->GetYNext());

	// 应该先构造四个四边形再进行递归，因为递归会修改m_Bisect2Storage里的值。
	// 搜索子四边形的根。
	auto result = BisectRecurse(&leftUpper) || BisectRecurse(&rightUpper) || BisectRecurse(&leftLower) || BisectRecurse(&rightLower);

	// 整个子四边形检查失败，删除添加的节点。    
	--m_Level;

	return result;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_CALCULATE_DETAIL_H

