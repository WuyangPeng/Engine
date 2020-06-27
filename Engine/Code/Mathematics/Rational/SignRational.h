// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 09:50)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_H
#define MATHEMATICS_RATIONAL_RATIONAL_H

#include "Mathematics/MathematicsDll.h"

#include "Integer.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <iosfwd>

namespace Mathematics
{
	// N��ÿ����������/��ĸ��32λ�ֵ���Ŀ
	template <int N>
	class SignRational : private boost::arithmetic<SignRational<N>,
								 boost::totally_ordered<SignRational<N>,
								 boost::arithmetic<SignRational<N>, Integer<N>>>>
	{
	public:
		using ClassType = SignRational<N>;
		using Integer = Integer<N>;

	public:
		// Ĭ����������0/1
		SignRational();

		explicit SignRational(const Integer& numerator);
		SignRational(const Integer& numerator, const Integer& denominator);

		// ����ת����
		template<typename T>
		explicit SignRational(T numerator);

		template<typename T>
		SignRational(T numerator, T denominator);

		CLASS_INVARIANT_DECLARE;

		//��Ա����
		const Integer GetNumerator() const;
		const Integer GetDenominator() const;
		void Set(const Integer& numerator, const Integer& denominator);

		const SignRational operator- () const;
		SignRational& operator+= (const SignRational& rhs);
		SignRational& operator-= (const SignRational& rhs);
		SignRational& operator*= (const SignRational& rhs);
		SignRational& operator/= (const SignRational& rhs);

		SignRational& operator+= (const Integer& rhs);
		SignRational& operator-= (const Integer& rhs);
		SignRational& operator*= (const Integer& rhs);
		SignRational& operator/= (const Integer& rhs);

		template<typename T>
		T ConvertTo() const;

		// �����������ľ���ֵ��
		const SignRational Abs() const;

		NumericalValueSymbol GetSign() const;

	private:
		// �������Ӻͷ�ĸ���κ�2�ĳ��ݡ�
		void EliminatePowersOfTwo();
		int GetPowers() const;

		template<typename T>
		void ConvertToRational(T value);

	private:
		Integer m_Numerator;
		Integer m_Denominator;
	};

	template <int N>
	const SignRational<N> operator- (const Integer<N>& integer, const SignRational<N>& rational);

	template <int N>
	const SignRational<N> operator/ (const Integer<N>& integer, const SignRational<N>& rational);

	// �Ƚϡ�
	template <int N>
	bool operator== (const SignRational<N>& lhs, const SignRational<N>& rhs);
	template <int N>
	bool operator< (const SignRational<N>& lhs, const SignRational<N>& rhs);

	template <int N>
	std::ostream& operator<< (std::ostream& os, const SignRational<N>& rational);

}

#endif // MATHEMATICS_RATIONAL_RATIONAL_H
