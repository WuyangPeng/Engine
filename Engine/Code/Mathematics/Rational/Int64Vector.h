// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 09:45)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <iosfwd>

namespace Mathematics
{
	template <int VectorSize>
	class Int64Vector : private boost::additive<Int64Vector<VectorSize>,
								boost::totally_ordered<Int64Vector<VectorSize>,
								boost::multiplicative<Int64Vector<VectorSize>, int64_t>>>
	{
	public:
		using ClassType = Int64Vector<VectorSize>;

	public:
		Int64Vector();
		Int64Vector(const Int64Vector& rhs);

		Int64Vector& operator= (const Int64Vector& rhs);

		CLASS_INVARIANT_DECLARE;

		// ◊¯±Í∑√Œ 
		const int64_t& operator[] (int index) const;
		int64_t& operator[] (int index);

		const Int64Vector operator- () const;

		Int64Vector& operator+= (const Int64Vector& rhs);
		Int64Vector& operator-= (const Int64Vector& rhs);
		Int64Vector& operator*= (const int64_t& scalar);
		Int64Vector& operator/= (const int64_t& scalar);

		int64_t SquaredLength() const;

	private:
		int64_t m_Tuple[VectorSize];
	};

	template <int VectorSize>
	bool operator== (const Int64Vector<VectorSize>& lhs, const Int64Vector<VectorSize>& rhs);

	template <int VectorSize>
	bool operator<  (const Int64Vector<VectorSize>& lhs, const Int64Vector<VectorSize>& rhs);

	template <int VectorSize>
	int64_t Dot(const Int64Vector<VectorSize>& lhs, const Int64Vector<VectorSize>& rhs);

	template <int VectorSize>
	std::ostream& operator<< (std::ostream& os, const Int64Vector<VectorSize>& rhs);
}

#endif // MATHEMATICS_RATIONAL_INT64_VECTOR_H
