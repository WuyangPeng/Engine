// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 12:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real, typename UserDataType>
	class RombergIntegral
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = RombergIntegral<Real, UserDataType>;

		// 最后一个参数是用户定义的数据。
		using Function = Real(*)(Real, const UserDataType*);
		using Math = Math<Real>;

	public:
		RombergIntegral(int order, Real begin, Real end, Function function, const UserDataType* userData);
		~RombergIntegral();
		RombergIntegral(const RombergIntegral& rhs);
		RombergIntegral& operator=(const RombergIntegral& rhs);
		RombergIntegral(RombergIntegral&& rhs) = default;
		RombergIntegral& operator=(RombergIntegral&& rhs) = default;
		
		CLASS_INVARIANT_DECLARE;

		Real GetValue() const noexcept;

	private:
		void Calculate() noexcept;

	private:
		int m_Order;
		Real m_Begin;
		Real m_End;
		Function m_Function;
		const UserDataType* m_UserData;
		Real m_Value;
		Real** m_Rom;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_ROMBERG_INTEGRAL_H
