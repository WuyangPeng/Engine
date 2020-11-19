// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 19:06)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_DETAIL_H 

#include "DistancePoint2Ellipse2Tool.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DistancePoint2Ellipse2Tool<Real>
	::DistancePoint2Ellipse2Tool(Real firstExtent, Real secondExtent, const Vector2D& vector, Real zeroThreshold)
	:m_Extent{ firstExtent,secondExtent }, m_InputVector{ vector }, m_OutputVector{}, m_SquaredDistance{ Math<Real>::GetValue(0) }, m_ZeroThreshold{ zeroThreshold }
{
	ComputeSquaredDistance();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::DistancePoint2Ellipse2Tool<Real>
	::ComputeSquaredDistance()
{
	// 确定m_InputVector的反射到第一象限。
	bool reflect[2]{ m_InputVector.GetX() < Math<Real>::GetValue(0),m_InputVector.GetY() < Math<Real>::GetValue(0) };

	// 确定递减辐度轴顺序。
	int permute[2]{};
	if (m_Extent[0] < m_Extent[1])
	{
		permute[0] = 1;
		permute[1] = 0;
	}
	else
	{
		permute[0] = 0;
		permute[1] = 1;
	}

	int invPermute[2]{};
	for (auto index = 0; index < 2; ++index)
	{
		invPermute[permute[index]] = index;
	}

	Vector2D localExtent;
	Vector2D localQueryPoint;
	for (auto index = 0; index < 2; ++index)
	{
		auto permuteIndex = permute[index];
		localExtent[index] = m_Extent[permuteIndex];
		localQueryPoint[index] = m_InputVector[permuteIndex];
		if (reflect[permuteIndex])
		{
			localQueryPoint[index] = -localQueryPoint[index];
		}
	}

	ComputeSquaredDistanceSpecial(localExtent, localQueryPoint);

	auto local = m_OutputVector;

	// 恢复轴顺序和反射。
	for (auto index = 0; index < 2; ++index)
	{
		auto invPermuteIndex = invPermute[index];
		if (reflect[index])
		{
			local[invPermuteIndex] = -local[invPermuteIndex];
		}
		m_OutputVector[index] = local[invPermuteIndex];
	}
}

// private
template <typename Real>
void Mathematics::DistancePoint2Ellipse2Tool<Real>
	::ComputeSquaredDistanceSpecial(const Vector2D& extent, const Vector2D& queryPoint)
{
	if (m_ZeroThreshold < queryPoint[1])
	{
		if (m_ZeroThreshold < queryPoint[0])
		{
			// 平分计算F(t)的根t >= -e1 * e1。
			Vector2D extentSquared{ extent[0] * extent[0], extent[1] * extent[1] };
			Vector2D extentMultiplyQueryPoint{ extent[0] * queryPoint[0],extent[1] * queryPoint[1] };
			auto beginT = -extentSquared[1] + extentMultiplyQueryPoint[1];
			auto endT = -extentSquared[1] + Vector2DTools<Real>::VectorMagnitude(extentMultiplyQueryPoint);
			auto middleT = beginT;
			const auto maxLoop = 2 * std::numeric_limits<Real>::max_exponent;
			for (auto i = 0; i < maxLoop; ++i)
			{
				middleT =  Math::GetRational(1,2) * (beginT + endT);
				if (Math<Real>::FAbs(middleT - beginT) <= m_ZeroThreshold || Math<Real>::FAbs(middleT - endT) <= m_ZeroThreshold)
				{
					break;
				}

				Vector2D r{ extentMultiplyQueryPoint[0] / (middleT + extentSquared[0]),
							extentMultiplyQueryPoint[1] / (middleT + extentSquared[1]) };
				auto lenghtSquaredMinusOne = Vector2DTools<Real>::VectorMagnitudeSquared(r) - Math::GetValue(1);

				if (Math<Real>::GetValue(0) < lenghtSquaredMinusOne)
				{
					beginT = middleT;
				}
				else if (lenghtSquaredMinusOne < Math<Real>::GetValue(0))
				{
					endT = middleT;
				}
				else
				{
					break;
				}
			}

			m_OutputVector[0] = extentSquared[0] * queryPoint[0] / (middleT + extentSquared[0]);
			m_OutputVector[1] = extentSquared[1] * queryPoint[1] / (middleT + extentSquared[1]);
			Vector2D distance{ m_OutputVector[0] - queryPoint[0], m_OutputVector[1] - queryPoint[1] };
			m_SquaredDistance = Vector2DTools<Real>::VectorMagnitudeSquared(distance);
		}
		else  // y0 == 0
		{
			m_OutputVector[0] = Math<Real>::GetValue(0);
			m_OutputVector[1] = extent[1];
			Real difference = queryPoint[1] - extent[1];
			m_SquaredDistance = difference * difference;
		}
	}
	else  // y1 == 0
	{
		auto denom = extent[0] * extent[0] - extent[1] * extent[1];
		auto extentMultiplyQueryPoint = extent[0] * queryPoint[0];
		if (extentMultiplyQueryPoint < denom)
		{
			// queryPoint.y为子区间内。
			auto xDividedExtent = extentMultiplyQueryPoint / denom;
			auto x0de0squared = xDividedExtent * xDividedExtent;
			m_OutputVector[0] = extent[0] * xDividedExtent;
			m_OutputVector[1] = extent[1] * Math<Real>::Sqrt(Math<Real>::FAbs(Math::GetValue(1) - x0de0squared));
			auto xDifference = m_OutputVector[0] - queryPoint[0];
			m_SquaredDistance = xDifference * xDifference + m_OutputVector[1] * m_OutputVector[1];
		}
		else
		{
			// queryPoint.y为子区间外。
			// 最近的椭圆点有m_OutputVector.y == 0，
			// 在域边界间隔(x0/e0)^2 = 1。			 
			m_OutputVector[0] = extent[0];
			m_OutputVector[1] = Math<Real>::GetValue(0);
			auto difference = queryPoint[0] - extent[0];
			m_SquaredDistance = difference * difference;
		}
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint2Ellipse2Tool<Real>
	::IsValid() const noexcept
{
	if (Math<Real>::GetValue(0) <= m_SquaredDistance)
		return true;
	else
		return false;
}

#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::DistancePoint2Ellipse2Tool<Real>
	::GetSquaredDistance() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_SquaredDistance;
}

template <typename Real>
typename const Mathematics::DistancePoint2Ellipse2Tool<Real>::Vector2D Mathematics::DistancePoint2Ellipse2Tool<Real>
	::GetOutputVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_OutputVector;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_TOOL_DETAIL_H
