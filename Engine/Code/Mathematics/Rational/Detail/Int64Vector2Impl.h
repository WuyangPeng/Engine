// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 09:43)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR2_IMPL_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/ConfigMacro.h"
#include "Mathematics/Rational/Int64Vector.h"

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE Int64Vector2Impl
	{
	public:
		using ClassType = Int64Vector2Impl;

	public:
		Int64Vector2Impl() noexcept;
		Int64Vector2Impl(const Int64Vector<2>& rhs) noexcept;
		Int64Vector2Impl(const int64_t& x, const int64_t& y);

		Int64Vector2Impl& operator= (const Int64Vector<2>& rhs) noexcept;

		CLASS_INVARIANT_DECLARE;

		int64_t GetX() const;
		void SetX(const int64_t& x);
		int64_t GetY() const;
		void SetY(const int64_t& y);

		// ���� (y,-x).
		const Int64Vector2Impl Perp() const;

		const Int64Vector2Impl operator-() const noexcept;

		Int64Vector2Impl& operator+= (const Int64Vector2Impl& rhs) noexcept;
		Int64Vector2Impl& operator-= (const Int64Vector2Impl& rhs) noexcept ;
		Int64Vector2Impl& operator*= (const int64_t& scalar) noexcept;
		Int64Vector2Impl& operator/= (const int64_t& scalar);

		int64_t SquaredLength() const noexcept;

	private:
		Int64Vector<2> m_Tuple;
	};

	// ���� Dot(lhs,rhs).
	int64_t Dot(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs);

	// ���� Cross((lhs.x,lhs.y,0),(rhs.x,rhs.y,0)) = lhs.x*rhs.y - lhs.y*rhs.x.
	int64_t DotPerp(const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs);

	bool operator== (const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs);

	bool operator<  (const Int64Vector2Impl& lhs, const Int64Vector2Impl& rhs);
}

#endif // MATHEMATICS_RATIONAL_INT64_VECTOR2_IMPL_H
