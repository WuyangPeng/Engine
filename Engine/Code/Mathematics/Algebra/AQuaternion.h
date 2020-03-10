// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 10:12)

#ifndef MATHEMATICS_ALGEBRA_AQUATERNION_H
#define MATHEMATICS_ALGEBRA_AQUATERNION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/Math.h"

#include <boost/operators.hpp>
#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AQuaternion: private boost::additive<AQuaternion<Real>,		                          	
		                                                            boost::multiplicative<AQuaternion<Real>,Real,
							                                        boost::totally_ordered<AQuaternion<Real>>>> 
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = AQuaternion<Real>;
		using Math = Math<Real>;
		using Matrix = Matrix<Real>;
		using AVector = AVector<Real>;
		using AlgebraTraits = AlgebraTraits<Real>;

	public:
		// ��Ԫ��q = w + x * i + y * j + z * k
		// ����(w,x,y,z)��һ���ǵ�λ���ȵ���ά������

		AQuaternion ();  
		AQuaternion (Real w, Real x, Real y, Real z);
		AQuaternion (const AQuaternion& q);

		// ����Ϊ��ת��������Ԫ��
		AQuaternion (const Matrix& matrix);

		// ͨ����-�ǵ���ת������Ԫ��
		AQuaternion (const AVector& axis, Real angle);

		AQuaternion& operator= (const AQuaternion& rhs);

		CLASS_INVARIANT_DECLARE;

		// �����������������:  0 = w, 1 = x, 2 = y, 3 = z.
		const Real& operator[] (int index) const;
		Real& operator[] (int index);
		Real GetW () const;
		void SetW (Real w);
		Real GetX () const;
		void SetX (Real x);
		Real GetY () const;
		void SetY (Real y);
		Real GetZ () const;
		void SetZ (Real z);	

		// ��������
		AQuaternion& operator*= (const AQuaternion& rhs);

		const AQuaternion operator- () const;	

		AQuaternion& operator+= (const AQuaternion& rhs);
		AQuaternion& operator-= (const AQuaternion& rhs);
		AQuaternion& operator*= (Real scalar);
		AQuaternion& operator/= (Real scalar);		

		// ��Ԫ����������ᡪ����֮���ת����
		void FromRotationMatrix (const Matrix& matrix);
		const Matrix ToRotationMatrix () const;
		void FromAxisAngle (const AVector& axis, Real angle);
		const AVector ToAxis() const;
		Real ToAngle() const;

		// 4-tuple�ĳ���
		Real Length () const; 

		// 4-tuple�ĳ��ȵ�ƽ��
		Real SquaredLength () const;  

		void Normalize (Real epsilon = Math::sm_ZeroTolerance);

		// �����ڷ�����Ԫ��
		const AQuaternion Inverse () const;  

		// ȡ������ x, y, �� z ��
		const AQuaternion Conjugate () const;  

		// ��������Ԫ�� w = 0
		const AQuaternion Exp () const; 

		// �����ڵ�λ������Ԫ��
		const AQuaternion Log () const; 

		bool IsNormalize (Real epsilon = Math::sm_ZeroTolerance) const;   	

		// ����Ԫ����ת������
		const AVector Rotate (const AVector& vector) const;

		// �������Բ�ֵ
		void Slerp (Real t, const AQuaternion& firstQuaternion,const AQuaternion& secondQuaternion);

		// �м�����������β�ֵ 
		void Intermediate (const AQuaternion& firstQuaternion,const AQuaternion& secondQuaternion,const AQuaternion& thirdQuaternion);

		// ������β�ֵ��
		void Squad (Real t, const AQuaternion& q0, const AQuaternion& a0,
			        const AQuaternion& a1, const AQuaternion& q1);
	
		// ������Ԫ��
		static const AQuaternion sm_Zero;
		static const AQuaternion sm_Identity;

	private:
		// �洢��˳����(w,x,y,z)��
		Real m_Tuple[4];	
	};

	// �Ƚ� (��ʹ���� STL ����).
	template <typename Real>
	bool operator== (const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs);

	template <typename Real>
	bool operator<  (const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs);

	template <typename Real>
	const AQuaternion<Real> operator* (const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs);

	// 4Ԫ��ĵ��
	template <typename Real> 
	Real Dot (const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs); 

	template <typename Real>
	bool Approximate(const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs,const Real epsilon);

	template <typename Real>
	bool Approximate(const AQuaternion<Real>& lhs,const AQuaternion<Real>& rhs);

	// �������
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const AQuaternion<Real>& quaternion);

    using AQuaternionf = AQuaternion<float>;
	using AQuaterniond = AQuaternion<double>;
}

#endif // MATHEMATICS_ALGEBRA_AQUATERNION_H
