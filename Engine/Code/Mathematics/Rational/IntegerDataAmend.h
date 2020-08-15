// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 09:47)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <boost/noncopyable.hpp>
#include <vector>

namespace Mathematics
{
	// N是你想要元整数的32位字节的数目。
	template <int N>
	class IntegerDataAmend : boost::noncopyable
	{
	public:
		using ClassType = IntegerDataAmend<N>;
		using IntegerData = IntegerData<N>;

	public:
                explicit IntegerDataAmend(IntegerData& master) noexcept;

		CLASS_INVARIANT_DECLARE;

		void Negative();
		void FromUnsignedInt(int index, uint32_t value);
		void SetValue(int beginIndex, int endIndex, uint32_t value);

	private:
		static constexpr uint32_t sm_IntSize{ 2 * N };
		static constexpr uint32_t sm_Carry{ 0x00010000 };
		static constexpr uint32_t sm_Low{ 0x0000FFFF };

		IntegerData& m_Master;
	};
}

#endif // MATHEMATICS_RATIONAL_INTEGER_DATA_AMEND_H
