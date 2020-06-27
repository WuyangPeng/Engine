// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 09:44)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR3_IMPL_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/ConfigMacro.h"
#include "Mathematics/Rational/Int64Vector.h"

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE Int64Vector3Impl
	{
	public:
		typedef Int64Vector3Impl ClassType;

	public:
		Int64Vector3Impl();
		Int64Vector3Impl(const Int64Vector<3>& rhs);
		Int64Vector3Impl(const int64_t& x, const int64_t& y, const int64_t& z);

		Int64Vector3Impl& operator= (const Int64Vector<3>& rhs);

		CLASS_INVARIANT_DECLARE;

		int64_t GetX() const;
		void SetX(const int64_t& x);
		int64_t GetY() const;
		void SetY(const int64_t& y);
		int64_t GetZ() const;
		void SetZ(const int64_t& y);

		const Int64Vector3Impl operator- () const;

		Int64Vector3Impl& operator+= (const Int64Vector3Impl& rhs);
		Int64Vector3Impl& operator-= (const Int64Vector3Impl& rhs);
		Int64Vector3Impl& operator*= (const int64_t& scalar);
		Int64Vector3Impl& operator/= (const int64_t& scalar);

		int64_t SquaredLength() const;

	private:
		Int64Vector<3> m_Tuple;
	};

	// ∑µªÿ Dot(lhs,rhs).
	int64_t Dot(const Int64Vector3Impl& lhs, const Int64Vector3Impl& rhs);

	// ∑µªÿ Cross(this,V)
	Int64Vector3Impl Cross(const Int64Vector3Impl& lhs, const Int64Vector3Impl& rhs);

	// ∑µªÿ Dot(this,Cross(U,V))
	int64_t TripleScalar(const Int64Vector3Impl& lhs, const Int64Vector3Impl& mhs, const Int64Vector3Impl& rhs);

	bool operator== (const Int64Vector3Impl& lhs, const Int64Vector3Impl& rhs);

	bool operator<  (const Int64Vector3Impl& lhs, const Int64Vector3Impl& rhs);

}

#endif // MATHEMATICS_RATIONAL_INT64_VECTOR3_IMPL_H
