// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/04 10:52)

#ifndef MATHEMATICS_ALGEBRA_HOMOGENEOUS_POINT_H
#define MATHEMATICS_ALGEBRA_HOMOGENEOUS_POINT_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/Math.h"

#include <boost/operators.hpp>
#include <type_traits>

// ����ε�洢��ֵΪ������ʱ���Ƚ�������ȣ�
// ��ʹ�ú���Approximate��������==��

namespace Mathematics
{
	template <typename T>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE HomogeneousPoint : private boost::totally_ordered<HomogeneousPoint<T>>
	{
	public:		
		static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

		using ClassType = HomogeneousPoint<T>;

	public:
		// Point��ʾһ���� (x,y,z,w)���������㡣
		// ����������Ϊw = 1������APoint����
		// ��������������Ϊw = 0������AVector���� 
		HomogeneousPoint ();  
		HomogeneousPoint (const HomogeneousPoint& rhs);
		HomogeneousPoint (T x, T y, T z, T w);
		~HomogeneousPoint ();
		
		HomogeneousPoint& operator= (const HomogeneousPoint& rhs);

		CLASS_INVARIANT_DECLARE;

		// �������
		const T* GetCoordinate() const;
		T* GetCoordinate();
		const T& operator[] (int index) const noexcept;
		T& operator[] (int index) noexcept;
		T GetX () const noexcept;
		void SetX (T x);
		T GetY () const noexcept;
		void SetY (T y);
		T GetZ () const noexcept;
		void SetZ (T y);
		T GetW () const noexcept;
		void SetW (T y);

		static int GetPointByte();	
		static int GetPointSize();

	private:
		static constexpr auto sm_PointSize = 4;

		T m_Tuple[sm_PointSize];
	};

	// �Ƚϣ�����STL����ʹ�ã�
	template <typename T>
	bool operator== (const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs);

	template <typename T>
	bool operator< (const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs);	

	template <typename T>
	bool Approximate(const HomogeneousPoint<T>& lhs,  const HomogeneousPoint<T>& rhs,const T epsilon = Math<T>::sm_ZeroTolerance);

	using HomogeneousPointf = HomogeneousPoint<float>;
	using HomogeneousPointd = HomogeneousPoint<double>;
}

#endif // MATHEMATICS_ALGEBRA_HOMOGENEOUS_POINT_H
