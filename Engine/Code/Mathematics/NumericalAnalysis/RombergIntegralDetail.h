// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 15:19)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_DETAIL_H

#include "RombergIntegral.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename UserDataType>
Mathematics::RombergIntegral<Real, UserDataType>
	::RombergIntegral(int order, Real begin, Real end, Function function, const UserDataType* userData)
	:m_Order{ order }, m_Begin{ begin }, m_End{ end }, m_Function{ function },
	 m_UserData{ userData }, m_Value{}, m_Rom{ NEW2<Real>(m_Order, 2) }
{
	Calculate();
	DELETE2(m_Rom);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename UserDataType>
Mathematics::RombergIntegral<Real, UserDataType>
	::~RombergIntegral()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;

	DELETE2(m_Rom);
}

template <typename Real, typename UserDataType>
Mathematics::RombergIntegral<Real, UserDataType>
	::RombergIntegral(const RombergIntegral& rhs)
	:m_Order{ rhs.m_Order }, m_Begin{ rhs.m_Begin }, m_End{ rhs.m_End }, m_Function{ rhs.m_Function },
	 m_UserData{ rhs.m_UserData }, m_Value{ rhs.m_Value }, m_Rom{ nullptr }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename UserDataType>
Mathematics::RombergIntegral<Real, UserDataType>& Mathematics::RombergIntegral<Real, UserDataType>
	::operator=(const RombergIntegral& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Order = rhs.m_Order;
	m_Begin = rhs.m_Begin;
	m_End = rhs.m_End;
	m_Function = rhs.m_Function;
	m_UserData = rhs.m_UserData;
	m_Value = rhs.m_Value;
	m_Rom = nullptr;

	return *this;
}

// private
template <typename Real, typename UserDataType>
void Mathematics::RombergIntegral<Real, UserDataType>
	::Calculate()
{
	auto difference = m_End - m_Begin;

	m_Rom[0][0] = static_cast<Real>(0.5) * difference * (m_Function(m_Begin, m_UserData) + m_Function(m_End, m_UserData));

	auto p0 = 1;
	for (auto orderIndex = 2; orderIndex <= m_Order; ++orderIndex)
	{
		// 通过梯形规则逼近。
		auto sum = Math::sm_Zero;

		for (auto i = 1; i <= p0; ++i)
		{
			sum += m_Function(m_Begin + difference * (i - (static_cast<Real>(0.5))), m_UserData);
		}

		// Richardson 外推法。
		m_Rom[1][0] = (static_cast<Real>(0.5) * (m_Rom[0][0] + difference * sum));

		auto p2 = 4;
		for (auto i = 1; i < orderIndex; ++i)
		{
			auto temp1 = p2 * m_Rom[1][i - 1];
			auto temp2 = temp1 - m_Rom[0][i - 1];
			auto temp3 = p2 - 1;
			m_Rom[1][i] = (temp2) / (temp3);

			p2 *= 4;
		}

		for (auto i = 0; i < orderIndex; ++i)
		{
			m_Rom[0][i] = m_Rom[1][i];
		}

		p0 *= 2;
		difference *= static_cast<Real>(0.5);
	}

	m_Value = m_Rom[0][m_Order - 1];
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::RombergIntegral<Real, UserDataType>
	::IsValid() const noexcept
{
	if (m_Function != nullptr && 0 < m_Order && m_Rom == nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
Real Mathematics::RombergIntegral<Real, UserDataType>
	::GetValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Value;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_DETAIL_H
