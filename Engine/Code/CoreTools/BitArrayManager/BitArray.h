// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 13:22)

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

		// ����λ����Ϊfalse��
		void Clear() noexcept;

		// ��������λΪtrue��
		void SetBit(int position) noexcept;

		// ��������λΪfalse��
		void ClearBit(int position) noexcept;

		// �л�����λ��
		void FlipBit(int position) noexcept;

		// ������λ����Ϊָ��ֵ��
		void Set(int position, bool value) noexcept;

		// ��������λ�Ƿ�Ϊtrue��
		bool IsBitSet(int position) const noexcept;

		// ��������λ�Ƿ�ȫΪfalse��
		bool AllBitsFalse() const noexcept;

		// �ı�����λ��ֵ��
		void FlipAllBits() noexcept;

		int GetNumBits() const noexcept;
		int GetLength() const noexcept;

	private:
		// ����һ�������ı�������ȡ������λƫ�ơ�������
		static int GetIndex(int bitNum) noexcept;

		// λƫ�ơ�
		static int GetOffset(int bitNum) noexcept;

		void Init();

		// ǿ��ʣ��λΪ0
		void Trim() noexcept;

		void Swap(BitArray& rhs) noexcept;

	private:
		static constexpr auto sm_BitsPerByte = 8;
		static constexpr auto sm_CellSize = sizeof(uint32_t) * sm_BitsPerByte;

	private:
		uint32_t* m_Store;
		// m_Length Ϊ1ʱʹ�ô˻�����
		uint32_t m_SingleWord;
		int m_Length;
		int m_NumBits;
	};

	bool CORE_TOOLS_DEFAULT_DECLARE operator==(const BitArray& lhs, const BitArray& rhs) noexcept;
}

#endif // CORE_TOOLS_BIT_ARRAY_BIT_ARRAY_H
