// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/04 13:45)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H
#define MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/Math.h"

#include <boost/operators.hpp>
#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE VariableLengthVector : private boost::additive<VariableLengthVector<Real>,		                          	
		                                                                      boost::multiplicative<VariableLengthVector<Real>,Real,
										                                      boost::totally_ordered<VariableLengthVector<Real> > > > 
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType= VariableLengthVector<Real>;
		using Math = Math<Real>;

	public:
		explicit VariableLengthVector (int size = 0);
		explicit VariableLengthVector (const std::vector<Real>& tuple);
		VariableLengthVector (int size,const Real* data);
		VariableLengthVector (const VariableLengthVector& rhs);
		~VariableLengthVector ();

		VariableLengthVector& operator= (const VariableLengthVector& rhs);

		CLASS_INVARIANT_DECLARE;

		// 坐标访问		
		int GetSize () const;

		const Real* GetElements() const;
		Real* GetElements();
		const Real& operator[] (int index) const;
		Real& operator[] (int index);

		// 重新设置大小会清空原有数据。
		void ResetSize (int size);		

		const VariableLengthVector operator- () const;

		VariableLengthVector& operator+= (const VariableLengthVector& rhs);
		VariableLengthVector& operator-= (const VariableLengthVector& rhs);
		VariableLengthVector& operator*= (Real scalar);
		VariableLengthVector& operator/= (Real scalar);

		// 向量运算
		Real Length () const;
		Real SquaredLength () const;	
		void Normalize (Real epsilon = Math::sm_ZeroTolerance);

		const std::vector<Real> GetValue() const;

	private:
		void Swap(VariableLengthVector& rhs);

	private:
		int m_Size;
		Real* m_Tuple;
	};		

	// STL
	template <typename Real>
	bool operator== (const VariableLengthVector<Real>& lhs,const VariableLengthVector<Real>& rhs);	

	template <typename Real>
	bool operator< (const VariableLengthVector<Real>& lhs,const VariableLengthVector<Real>& rhs);	
	
	template <typename Real>
	Real Dot (const VariableLengthVector<Real>& lhs,const VariableLengthVector<Real>& rhs);

	template <typename Real>
	bool Approximate(const VariableLengthVector<Real>& lhs,const VariableLengthVector<Real>& rhs,
					 const Real epsilon = Math<Real>::sm_ZeroTolerance);
	
	// 调试输出。
	template <typename Real>
	std::ostream& operator<< (std::ostream& outFile, const VariableLengthVector<Real>& vector);
	
	using VariableLengthVectorf = VariableLengthVector<float>;
	using VariableLengthVectord = VariableLengthVector<double>;
}

#endif // MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H
