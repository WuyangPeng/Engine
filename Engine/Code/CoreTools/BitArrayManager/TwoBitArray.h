// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 13:26)

#ifndef CORE_TOOLS_BIT_ARRAY_TWO_BIT_ARRAY_H
#define CORE_TOOLS_BIT_ARRAY_TWO_BIT_ARRAY_H

#include "CoreTools/CoreToolsDll.h"

#include "BitArray.h"
#include "TwoBitProxy.h"
#include "ConstTwoBitProxy.h"

#include "System/Helper/PragmaWarning/Operators.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE TwoBitArray : private boost::equality_comparable<TwoBitArray, boost::bitwise<TwoBitArray> >
	{
	public:
		using ClassType = TwoBitArray;

	public:
		explicit TwoBitArray(int size);

		CLASS_INVARIANT_DECLARE;

		TwoBitProxy operator[](int position) noexcept;
		ConstTwoBitProxy operator[](int position) const noexcept;

		bool operator==(const TwoBitArray& rhs) const noexcept;

		TwoBitArray& operator&=(const TwoBitArray& that) noexcept;
		TwoBitArray& operator|=(const TwoBitArray& that) noexcept;
		TwoBitArray& operator^=(const TwoBitArray& that) noexcept;

		const TwoBitArray operator~() const;

		void Clear() noexcept;

		// 切换位置pos的bits
		void FlipBits(int position) noexcept;

		// 设置给定位置为指定值。
		void Set(int position, uint32_t value) noexcept;

		// 如果位置pos的bits是true，则返回true
		uint32_t Get(int position) const noexcept;

		bool AllZero() const noexcept;

		void FlipAllBits() noexcept;

	private:
		constexpr static auto sm_TwoSize = 2;

	private:
		BitArray m_Array;
	};
}

#endif // CORE_TOOLS_BIT_ARRAY_TWO_BIT_ARRAY_H
