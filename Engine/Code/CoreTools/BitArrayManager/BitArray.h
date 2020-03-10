// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 13:22)

#ifndef CORE_TOOLS_BIT_ARRAY_BIT_ARRAY_H
#define CORE_TOOLS_BIT_ARRAY_BIT_ARRAY_H

#include "CoreTools/CoreToolsDll.h"

#include "BitArrayManagerFwd.h"

#include <boost/operators.hpp>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE BitArray : private boost::equality_comparable<BitArray, boost::bitwise<BitArray>>
	{
	public:
		using ClassType = BitArray;

	public:
		explicit BitArray(int size);

		BitArray(const BitArray& rhs);
		~BitArray();

		BitArray& operator=(const BitArray& rhs);

		CLASS_INVARIANT_DECLARE;

		BitProxy operator[](int position);
		ConstBitProxy operator[](int position) const;

		BitArray& operator&=(const BitArray& rhs) noexcept;
		BitArray& operator|=(const BitArray& rhs) noexcept;
		BitArray& operator^=(const BitArray& rhs) noexcept;

		const BitArray operator~() const;

		// 所有位设置为false。
		void Clear() noexcept;

		// 设置所在位为true。
		void SetBit(int position) noexcept;

		// 设置所在位为false。
		void ClearBit(int position) noexcept;

		// 切换所在位。
		void FlipBit(int position) noexcept;

		// 将所在位设置为指定值。
		void Set(int position, bool value) noexcept;

		// 返回所在位是否为true。
		bool IsBitSet(int position) const noexcept;

		// 返回所有位是否全为false。
		bool AllBitsFalse() const noexcept;

		// 改变所有位的值。
		void FlipAllBits() noexcept;

		int GetNumBits() const noexcept;
		int GetLength() const noexcept;

	private:
		// 对于一个给定的比特数获取索引和位偏移。索引。
		static int GetIndex(int bitNum) noexcept;

		// 位偏移。
		static int GetOffset(int bitNum) noexcept;

		void Init();

		// 强制剩余位为0
		void Trim() noexcept;

		void Swap(BitArray& rhs) noexcept;

	private:
		static constexpr auto sm_BitsPerByte = 8;
		static constexpr auto sm_CellSize = sizeof(uint32_t) * sm_BitsPerByte;

	private:
		uint32_t* m_Store;
		// m_Length 为1时使用此缓冲区
		uint32_t m_SingleWord;
		int m_Length;
		int m_NumBits;
	};

	bool CORE_TOOLS_DEFAULT_DECLARE operator==(const BitArray& lhs, const BitArray& rhs) noexcept;
}

#endif // CORE_TOOLS_BIT_ARRAY_BIT_ARRAY_H
