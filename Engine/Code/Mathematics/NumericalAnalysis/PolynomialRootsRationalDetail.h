// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 15:15)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_DETAIL_H

#include "PolynomialRootsRational.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <memory>

template <typename Real>
typename const Mathematics::PolynomialRootsRational<Real>::PolynomialRational Mathematics::PolynomialRootsRational<Real>
	::sm_Zero{};

template <typename Real>
typename const Mathematics::PolynomialRootsRational<Real>::PolynomialRational Mathematics::PolynomialRootsRational<Real>
	::sm_One{ Math::sm_One };

template <typename Real>
Mathematics::PolynomialRootsRational<Real>
	::PolynomialRootsRational(Real epsilon)
	:m_Quantity{ 0 }, m_Epsilon{ epsilon }, m_Root{}, m_Multiplicity{}
{
	for (auto i = 0; i < sm_MaxRoot; ++i)
	{
		m_Root[i] = Math::sm_Zero;
		m_Multiplicity[i] = 0;
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::PolynomialRootsRational<Real>
	::~PolynomialRootsRational()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::PolynomialRootsRational<Real>
	::PolynomialRootsRational(const PolynomialRootsRational& rhs)
	:m_Quantity{ rhs.m_Quantity }, m_Epsilon{ rhs.m_Epsilon }, m_Root{}, m_Multiplicity{}
{
	for (auto i = 0; i < sm_MaxRoot; ++i)
	{
		m_Root[i] = rhs.m_Root[i];
		m_Multiplicity[i] = rhs.m_Multiplicity[i];
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::PolynomialRootsRational<Real>& Mathematics::PolynomialRootsRational<Real>
	::operator=(const PolynomialRootsRational& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Quantity = rhs.m_Quantity;
	m_Epsilon = rhs.m_Epsilon;

	for (auto i = 0; i < sm_MaxRoot; ++i)
	{
		m_Root[i] = rhs.m_Root[i];
		m_Multiplicity[i] = rhs.m_Multiplicity[i];
	}

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>
	::IsValid() const noexcept
{
	if (0 <= m_Quantity)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::PolynomialRootsRational<Real>
	::GetQuantity() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Quantity;
}

template <typename Real>
Real Mathematics::PolynomialRootsRational<Real>
	::GetRoot(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (0 <= index && index < m_Quantity)
	{
		return m_Root[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("无效索引\n"));
	}
}

template <typename Real>
int Mathematics::PolynomialRootsRational<Real>
	::GetMultiplicity(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (0 <= index && index < m_Quantity)
	{
		return m_Multiplicity[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("无效索引\n"));
	}
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>
	::Linear(Real constant, Real once)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	if (m_Epsilon < Math::FAbs(once))
	{
		// 方程是 once * x + constant = 0,这里once不是零。
		auto rationalRoot = PolynomialRational{ -constant } / PolynomialRational{ once };

		m_Quantity = 1;
		m_Root[0] = rationalRoot.ConvertTo<Real>();
		m_Multiplicity[0] = 1;

		return true;
	}

	if (m_Epsilon < Math::FAbs(constant))
	{
		// 方程是 c0 = 0, 这里constant不是零,所以方程无解 。

		m_Quantity = 0;

		return false;
	}

	// 该多项式方程是重言式，0 = 0，所以有无穷多的解决方案。
	m_Quantity = System::EnumCastUnderlying(QuantityType::Infinite);

	return true;
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>
	::Linear(const PolynomialRational& constant, const PolynomialRational& once)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	if (once != sm_Zero)
	{
		// 方程是 once * x + constant = 0,这里once不是零。
		auto rationalRoot = constant / once;
		m_Quantity = 1;
		m_Root[0] = -rationalRoot.ConvertTo<Real>();
		m_Multiplicity[0] = 1;

		return true;
	}

	if (constant != sm_Zero)
	{
		// 方程是 c0 = 0, 这里constant不是零,所以方程无解 。

		m_Quantity = 0;

		return false;
	}

	// 该多项式方程是重言式，0 = 0，所以有无穷多的解决方案。
	m_Quantity = System::EnumCastUnderlying(QuantityType::Infinite);

	return true;
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>
	::Quadratic(Real constant, Real once, Real secondary)
{
	if (Math::FAbs(secondary) <= m_Epsilon)
	{
		return Linear(constant, once);
	}

	// 方程是 secondary * x^2 + once * x + constant = 0, 这里secondary是非零
	PolynomialRational rationalConstant{ constant };
	PolynomialRational rationalOnce{ once };
	PolynomialRational rationalSecondary{ secondary };

	// 创建一个首一方程, x^2 + once * x + constant = 0.
	auto rationalSecondaryInverse = sm_One / rationalSecondary;

	// 解这个方程
	return Quadratic(rationalConstant * rationalSecondaryInverse, rationalOnce * rationalSecondaryInverse);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>
	::Quadratic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary)
{
	if (secondary == sm_Zero)
	{
		return Linear(constant, once);
	}

	// 方程是 secondary * x^2 + once * x + constant = 0, 这里secondary是非零
	// 创建一个首一方程, x^2 + once * x + constant = 0.
	auto rationalSecondaryInverse = sm_One / secondary;

	// 解这个方程
	return Quadratic(constant * rationalSecondaryInverse, once * rationalSecondaryInverse);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>
	::Quadratic(const PolynomialRational& constant, const PolynomialRational& once)
{
	PolynomialRational rationalMinusHalf{ -1,2 };
	auto rationalMinusOnceDivided2 = rationalMinusHalf * once;
	auto rationalDiscriminant = rationalMinusOnceDivided2 * rationalMinusOnceDivided2 - constant;
	if (sm_Zero < rationalDiscriminant)
	{
		// 两个不同的实数根。
		m_Quantity = 2;

		// 估算判别式。
		auto discriminant = rationalDiscriminant.ConvertTo<Real>();

		MATHEMATICS_ASSERTION_3(Math::sm_Zero < discriminant, "意外情况\n");

		discriminant = Math::Sqrt(discriminant);

		rationalDiscriminant = PolynomialRational(discriminant);

		auto rationalRoot0 = rationalMinusOnceDivided2 - rationalDiscriminant;
		auto rationalRoot1 = rationalMinusOnceDivided2 + rationalDiscriminant;

		m_Root[0] = rationalRoot0.ConvertTo<Real>();
		m_Root[1] = rationalRoot1.ConvertTo<Real>();
		m_Multiplicity[0] = 1;
		m_Multiplicity[1] = 1;
	}
	else if (rationalDiscriminant == sm_Zero)
	{
		// 一个实数根。
		m_Quantity = 1;

		m_Root[0] = rationalMinusOnceDivided2.ConvertTo<Real>();
		m_Multiplicity[0] = 2;
	}
	else
	{
		// 没有实数根
		m_Quantity = 0;
	}

	return 0 < m_Quantity;
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>
	::Cubic(Real constant, Real once, Real secondary, Real thrice)
{
	if (Math::FAbs(thrice) <= m_Epsilon)
	{
		return Quadratic(constant, once, secondary);
	}

	// 这方程是thrice * x^3 + secondary * x^2 + once * x + constant = 0,
	// 这里 thrice就非零。
	PolynomialRational rationalConstant{ constant };
	PolynomialRational rationalOnce{ once };
	PolynomialRational rationalSecondary{ secondary };
	PolynomialRational rationalThrice{ thrice };

	// 创建一个首一多项式, x^3 + secondary * x^2 + once * x + constant = 0.
	auto rationalThriceInverse = sm_One / rationalThrice;

	// 解这个方程
	return Cubic(rationalConstant * rationalThriceInverse, rationalOnce * rationalThriceInverse, rationalSecondary * rationalThriceInverse);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>
	::Cubic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary, const PolynomialRational& thrice)
{
	if (thrice == sm_Zero)
	{
		return Quadratic(constant, once, secondary);
	}

	// 这方程是thrice * x^3 + secondary * x^2 + once * x + constant = 0,
	// 这里 thrice就非零。
	// 创建一个首一多项式, x^3 + secondary * x^2 + once * x + constant = 0.
	auto rationalThriceInverse = sm_One / thrice;

	// 解这个方程
	return Cubic(constant * rationalThriceInverse, once * rationalThriceInverse, secondary * rationalThriceInverse);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>
	::Cubic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary)
{
	// 减少方程为y^3 + b1 * y + b0 = 0。
	static const PolynomialRational rationalHalf{ 1,2 };
	static const PolynomialRational rationalThird{ 1,3 };
	static const PolynomialRational rationalTwo{ 2 };

	auto rationalSecondaryDivide3 = rationalThird * secondary;
	auto rationalSecondaryDivide3Square = rationalSecondaryDivide3 * rationalSecondaryDivide3;
	auto rationalSecondaryDivide3Cube = rationalSecondaryDivide3 * rationalSecondaryDivide3Square;
	auto rationalB1 = once - rationalSecondaryDivide3 * secondary;
	auto rationalB0 = constant - once * rationalSecondaryDivide3 + rationalTwo * rationalSecondaryDivide3Cube;

	// 解这个方程
	auto rationalQ = rationalThird * rationalB1;
	auto rationalR = rationalHalf * rationalB0;
	auto rationalDiscriminant = rationalR * rationalR + rationalQ * rationalQ * rationalQ;
	if (sm_Zero < rationalDiscriminant)
	{
		// 一个实数根，两个复数共轭根。
		m_Quantity = 1;

		// 估计判别式 
		auto discriminant = rationalDiscriminant.ConvertTo<Real>();
		MATHEMATICS_ASSERTION_3(Math::sm_Zero < discriminant, "意外情况\n");
		auto discriminantSqrt = Math::Sqrt(discriminant);

		rationalDiscriminant = PolynomialRational{ discriminantSqrt };

		auto rationalSum0 = -rationalR + rationalDiscriminant;
		auto sum0 = rationalSum0.ConvertTo<Real>();
		sum0 = Math::CubeRoot(sum0);

		rationalSum0 = PolynomialRational(sum0);

		auto rationalSum1 = -rationalR - rationalDiscriminant;
		auto sum1 = rationalSum1.ConvertTo<Real>();
		sum1 = Math::CubeRoot(sum1);

		rationalSum1 = PolynomialRational{ sum1 };

		auto rationalRoot = rationalSum0 + rationalSum1 - rationalSecondaryDivide3;

		m_Root[0] = rationalRoot.ConvertTo<Real>();
		m_Multiplicity[0] = 1;
	}
	else if (rationalDiscriminant < sm_Zero)
	{
		// 三个不同的实数根。
		m_Quantity = 3;
		m_Multiplicity[0] = 1;
		m_Multiplicity[1] = 1;
		m_Multiplicity[2] = 1;

		// 通过计算的特征值求解该多项式的根。
		auto negativeQ = -rationalQ.ConvertTo<Real>();
		MATHEMATICS_ASSERTION_3(Math::sm_Zero < negativeQ, "意外情况\n");

		auto negativeR = -rationalR.ConvertTo<Real>();
		auto negativeDiscriminant = -rationalDiscriminant.ConvertTo<Real>();
		auto negativeSecondaryDivide3 = -rationalSecondaryDivide3.ConvertTo<Real>();

		auto sqrt3 = Math::Sqrt(static_cast<Real>(3));
		auto magnitude = Math::Sqrt(negativeQ);
		auto angle = Math::ATan2(Math::Sqrt(negativeDiscriminant), negativeR) / static_cast<Real>(3);
		auto cosValue = Math::Cos(angle);
		auto sinValue = Math::Sin(angle);
		auto root0 = negativeSecondaryDivide3 + static_cast<Real>(2) * magnitude * cosValue;
		auto root1 = negativeSecondaryDivide3 - magnitude * (cosValue + sqrt3 * sinValue);
		auto root2 = negativeSecondaryDivide3 - magnitude * (cosValue - sqrt3 * sinValue);

		// 以递增顺序排序
		if (root0 <= root1)
		{
			m_Root[0] = root0;
			m_Root[1] = root1;
		}
		else
		{
			m_Root[0] = root1;
			m_Root[1] = root0;
		}

		if (m_Root[1] <= root2)
		{
			m_Root[2] = root2;
		}
		else
		{
			m_Root[2] = m_Root[1];
			if (m_Root[0] <= root2)
			{
				m_Root[1] = root2;
			}
			else
			{
				m_Root[1] = m_Root[0];
				m_Root[0] = root2;
			}
		}
	}
	else
	{
		// 三个实数根，其中至少两个是相等的。
		if (rationalQ != sm_Zero)
		{
			// 两个实值的根，一个重复。
			m_Quantity = 2;

			auto r = rationalR.ConvertTo<Real>();
			r = Math::CubeRoot(r);
			rationalR = PolynomialRational(r);

			auto rationalRoot0 = rationalSecondaryDivide3 - rationalR;
			m_Root[0] = -rationalRoot0.ConvertTo<Real>();
			m_Multiplicity[0] = 2;

			auto rationalRoot1 = rationalSecondaryDivide3 + rationalTwo * rationalR;
			m_Root[1] = -rationalRoot1.ConvertTo<Real>();
			m_Multiplicity[1] = 1;

			if (m_Root[1] < m_Root[0])
			{
				std::swap(m_Root[0], m_Root[1]);
				std::swap(m_Multiplicity[0], m_Multiplicity[1]);
			}
		}
		else
		{
			// 一个实数根，所有重复
			m_Quantity = 1;
			m_Root[0] = -rationalSecondaryDivide3.ConvertTo<Real>();
			m_Multiplicity[0] = 3;
		}
	}

	return true;
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>
	::Quartic(Real constant, Real once, Real secondary, Real thrice, Real quartic)
{
	if (Math::FAbs(quartic) <= m_Epsilon)
	{
		return Cubic(constant, once, secondary, thrice);
	}

	// 方程是 quartic * x^4 + thrice * x^3 + secondary * x^2 + once * x + constant = 0, 
	// 这里quartic是非零
	PolynomialRational rationalConstant{ constant };
	PolynomialRational rationalOnce{ once };
	PolynomialRational rationalSecondary{ secondary };
	PolynomialRational rationalThrice{ thrice };
	PolynomialRational rationalQuartic{ quartic };

	// 创建首一多项式, x^4 + thrice * x^3 + secondary * x^2 + once * x + constant = 0.
	auto rationalQuarticInverse = sm_One / rationalQuartic;

	// 解这个方程
	return Quartic(rationalConstant * rationalQuarticInverse, rationalOnce * rationalQuarticInverse, rationalSecondary * rationalQuarticInverse, rationalThrice * rationalQuarticInverse);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>
	::Quartic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary, const PolynomialRational& thrice, const PolynomialRational& quartic)
{
	if (quartic == sm_Zero)
	{
		return Cubic(constant, once, secondary, thrice);
	}

	// 方程是 quartic * x^4 + thrice * x^3 + secondary * x^2 + once * x + constant = 0, 
	// 这里quartic是非零
	// 创建首一多项式, x^4 + thrice * x^3 + secondary * x^2 + once * x + constant = 0.
	auto rationalQuarticInverse = sm_One / quartic;

	// 解这个方程
	return Quartic(constant * rationalQuarticInverse, once * rationalQuarticInverse, secondary * rationalQuarticInverse, thrice * rationalQuarticInverse);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>
	::Quartic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary, const PolynomialRational& thrice)
{
	m_Quantity = 0;

	// 减至化解三次多项式 y^3 + secondary * y^2 + once * y + constant = 0
	std::shared_ptr<PolynomialRational> rationalHalf{ std::make_shared<PolynomialRational>(1, 2) };
	std::shared_ptr<PolynomialRational> rationalFourth{ std::make_shared<PolynomialRational>(1, 4) };
	std::shared_ptr<PolynomialRational> rationalEighth{ std::make_shared<PolynomialRational>(1, 8) };
	PolynomialRational rationalFour{ 4 };
	PolynomialRational rationalTwo{ 2 };
	auto rationalR2 = -*rationalHalf * secondary;
	auto rationalR1 = *rationalFourth * once * thrice - constant;
	auto rationalR0 = -*rationalEighth * (once * once + constant * (thrice * thrice - rationalFour * secondary));

	// 这总是至少产生一个根。
	PolynomialRootsRational<Real> polynomial;
	polynomial.Cubic(rationalR0, rationalR1, rationalR2);
	PolynomialRational rationalY{ polynomial.GetRoot(0) };

	auto rationalAlphaSqr = *rationalFourth * thrice * thrice - secondary + rationalTwo * rationalY;
	auto alphaSqr = rationalAlphaSqr.ConvertTo<Real>();

	if (alphaSqr < -m_Epsilon)
	{
		return false;
	}

	if (m_Epsilon < alphaSqr)
	{
		auto alpha = Math::Sqrt(alphaSqr);
		auto rationalAlpha = PolynomialRational{ alpha };
		auto rationalBeta = *rationalHalf * (thrice * rationalY - once) / rationalAlpha;

		auto rationalB0 = rationalY - rationalBeta;
		auto rationalB1 = *rationalHalf * thrice - rationalAlpha;
		polynomial.Quadratic(rationalB0, rationalB1);
		for (auto i = 0; i < polynomial.GetQuantity(); ++i)
		{
			m_Root[m_Quantity] = polynomial.GetRoot(i);
			m_Multiplicity[m_Quantity] = polynomial.GetMultiplicity(i);
			++m_Quantity;
		}

		rationalB0 = rationalY + rationalBeta;
		rationalB1 = *rationalHalf * thrice + rationalAlpha;
		polynomial.Quadratic(rationalB0, rationalB1);
		for (auto i = 0; i < polynomial.GetQuantity(); ++i)
		{
			m_Root[m_Quantity] = polynomial.GetRoot(i);
			m_Multiplicity[m_Quantity] = polynomial.GetMultiplicity(i);
			++m_Quantity;
		}

		SortRoots();
		return 0 < m_Quantity;
	}

	auto rationalBetaSqr = rationalY * rationalY - constant;
	auto betaSqr = rationalBetaSqr.ConvertTo<Real>();
	if (betaSqr < -m_Epsilon)
	{
		return false;
	}

	if (m_Epsilon < betaSqr)
	{
		auto beta = Math::Sqrt(betaSqr);
		PolynomialRational rationalBeta{ beta };

		auto rationalB0 = rationalY - rationalBeta;
		auto rationalB1 = *rationalHalf * thrice;
		polynomial.Quadratic(rationalB0, rationalB1);
		for (auto i = 0; i < polynomial.GetQuantity(); ++i)
		{
			m_Root[m_Quantity] = polynomial.GetRoot(i);
			m_Multiplicity[m_Quantity] = polynomial.GetMultiplicity(i);
			++m_Quantity;
		}

		rationalB0 = rationalY + rationalBeta;
		polynomial.Quadratic(rationalB0, rationalB1);
		for (auto i = 0; i < polynomial.GetQuantity(); ++i)
		{
			m_Root[m_Quantity] = polynomial.GetRoot(i);
			m_Multiplicity[m_Quantity] = polynomial.GetMultiplicity(i);
			++m_Quantity;
		}

		SortRoots();
		return 0 < m_Quantity;
	}

	polynomial.Quadratic(rationalY, *rationalHalf * thrice);
	for (auto i = 0; i < polynomial.GetQuantity(); ++i)
	{
		m_Root[m_Quantity] = polynomial.GetRoot(i);
		m_Multiplicity[m_Quantity] = 2 * polynomial.GetMultiplicity(i);
		++m_Quantity;
	}

	return 0 < m_Quantity;
}

template <typename Real>
void Mathematics::PolynomialRootsRational<Real>
	::SortRoots()
{
	// 排序根就像: root[0] <= ... <= root[quantity - 1].
	for (auto i0 = 0; i0 <= m_Quantity - 2; ++i0)
	{
		// 找到最小的根。
		auto i1 = i0;
		auto minRoot = m_Root[i1];
		auto minMultiplicity = m_Multiplicity[i1];
		for (auto i2 = i0 + 1; i2 < m_Quantity; ++i2)
		{
			if (m_Root[i2] < minRoot)
			{
				i1 = i2;
				minRoot = m_Root[i1];
				minMultiplicity = m_Multiplicity[i1];
			}
		}

		if (i1 != i0)
		{
			// 交换根和多重性。
			m_Root[i1] = m_Root[i0];
			m_Root[i0] = minRoot;
			m_Multiplicity[i1] = m_Multiplicity[i0];
			m_Multiplicity[i0] = minMultiplicity;
		}
	}

	// 如果需要的话，合并多重性
	for (auto i0 = 0; i0 < m_Quantity - 1;)
	{
		if (m_Root[i0] == m_Root[i0 + 1])
		{
			// 合并多重性
			m_Multiplicity[i0] += m_Multiplicity[i0 + 1];

			// 通过平移数组元素消除多余的根。
			--m_Quantity;
			for (auto i1 = i0 + 1; i1 < m_Quantity; i1++)
			{
				m_Root[i1] = m_Root[i1 + 1];
				m_Multiplicity[i1] = m_Multiplicity[i1 + 1];
			}
		}
		else
		{
			++i0;
		}
	}
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_DETAIL_H