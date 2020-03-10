// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 10:54)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <boost/operators.hpp>
#include <vector>
#include <iosfwd>

namespace Mathematics
{
	// N������ҪԪ������32λ�ֽڵ���Ŀ��
	template <int N>
	class IntegerData : private boost::totally_ordered<IntegerData<N>>
	{
	public:		
		using ClassType = IntegerData<N>;

	public:
		IntegerData();
		explicit IntegerData(const std::vector<uint16_t>& data);
		IntegerData(int count,const uint16_t* data);

		template<typename T>
		explicit IntegerData(T value);

		IntegerData(const IntegerData& rhs);
		IntegerData& operator=(const IntegerData& rhs);

		template <int Other>
		IntegerData(const IntegerData<Other>& rhs);

		CLASS_INVARIANT_DECLARE;

		bool IsZero() const;
		void SetZero();
		NumericalValueSymbol GetSign () const;	

		void SwapBigEndian();

		void SetBit(int index, bool on);
		bool GetBit(int index) const;

		uint16_t& operator[](int index);
		const uint16_t& operator[](int index) const;

		// ֧�ֱȽϡ��Ƚϵķ���ֵ��
		//   -1 �� lhs < rhs,
		//    0 �� lhs == rhs,
		//   +1 �� lhs > rhs.
		// ����ȽϽ�����==��<ʹ�ã�ʹ���޷������Ƚϡ�
		static NumericalValueSymbol UnsignedDataCompare(const IntegerData& lhs,const IntegerData& rhs);

	private:		
		void Init(int count,const uint16_t* data);

		template<typename T>
		void Init(T value);

	private:
		static constexpr uint32_t sm_IntSize{ 2 * N };
		static constexpr uint32_t sm_IntBytes{ sm_IntSize * sizeof(uint16_t) };
		static constexpr uint32_t sm_IntLast{ sm_IntSize - 1 };

		// ���λ����������0��
		uint16_t m_Buffer[sm_IntSize];
	};		

	// �Ƚ�
	template <int N>
	bool operator== (const IntegerData<N>& lhs, const IntegerData<N>& rhs);

	template <int N>
	bool operator< (const IntegerData<N>& lhs, const IntegerData<N>& rhs);

	template <int N>
	std::ostream& operator<< (std::ostream& os,const IntegerData<N>& integerData);
}

#endif // MATHEMATICS_RATIONAL_INTEGER_DATA_H
