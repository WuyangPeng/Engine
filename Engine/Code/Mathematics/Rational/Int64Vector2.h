// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 09:46)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR2_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR2_H

#include "Mathematics/MathematicsDll.h"

#include "Int64Vector.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <iosfwd>

MATHEMATICS_EXPORT_SHARED_PTR(Int64Vector2Impl);

namespace Mathematics
{
	class MATHEMATICS_DEFAULT_DECLARE Int64Vector2 : private boost::additive<Int64Vector2,
															 boost::totally_ordered<Int64Vector2,
															 boost::multiplicative<Int64Vector2, int64_t>>>
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Int64Vector2);

	public:
		Int64Vector2();
		Int64Vector2(const Int64Vector<2>& rhs);
		Int64Vector2(const int64_t& x, const int64_t& y);

		Int64Vector2& operator= (const Int64Vector<2>& rhs);

		CLASS_INVARIANT_DECLARE;

		int64_t GetX() const;
		void SetX(const int64_t& x);
		int64_t GetY() const;
		void SetY(const int64_t& y);

		// ∑µªÿ (y,-x).
		const Int64Vector2 Perp() const;

		const Int64Vector2 operator- () const;

		Int64Vector2& operator+= (const Int64Vector2& rhs);
		Int64Vector2& operator-= (const Int64Vector2& rhs);
		Int64Vector2& operator*= (const int64_t& scalar);
		Int64Vector2& operator/= (const int64_t& scalar);

		int64_t SquaredLength() const noexcept;

		// ∑µªÿ Dot(lhs,rhs).
		int64_t Dot(const Int64Vector2& rhs) const;

		// ∑µªÿ Cross((lhs.x,lhs.y,0),(rhs.x,rhs.y,0)) = lhs.x*rhs.y - lhs.y*rhs.x.
		int64_t DotPerp(const Int64Vector2& rhs) const;

		bool operator== (const Int64Vector2& rhs) const;
		bool operator<  (const Int64Vector2& rhs) const;

	private:
		IMPL_TYPE_DECLARE(Int64Vector2);
	};

	MATHEMATICS_DEFAULT_DECLARE std::ostream& operator<< (std::ostream& os, const Int64Vector2& rhs);
}

#endif // MATHEMATICS_RATIONAL_INT64_VECTOR2_H
