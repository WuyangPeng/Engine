// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 10:53)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR3_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR3_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Int64Vector.h"

#include <boost/operators.hpp>
#include <iosfwd>

MATHEMATICS_EXPORT_SHARED_PTR(Int64Vector3Impl);

namespace Mathematics 
{
	class MATHEMATICS_DEFAULT_DECLARE Int64Vector3 : private boost::additive<Int64Vector3,
															 boost::totally_ordered<Int64Vector3,
															 boost::multiplicative<Int64Vector3,int64_t>>> 
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Int64Vector3);

	public:
		Int64Vector3 ();			
		Int64Vector3 (const Int64Vector<3>& rhs);
		Int64Vector3 (const int64_t& x, const int64_t& y, const int64_t& z);

		Int64Vector3& operator= (const Int64Vector<3>& rhs); 

		CLASS_INVARIANT_DECLARE;

		int64_t GetX () const;
		void SetX (const int64_t& x);
		int64_t GetY () const;
		void SetY (const int64_t& y);	
		int64_t GetZ () const;
		void SetZ (const int64_t& z);		

		const Int64Vector3 operator- () const;

		Int64Vector3& operator+= (const Int64Vector3& rhs);
		Int64Vector3& operator-= (const Int64Vector3& rhs);
		Int64Vector3& operator*= (const int64_t& scalar);
		Int64Vector3& operator/= (const int64_t& scalar);

		int64_t SquaredLength () const;	

		// ∑µªÿ Dot(lhs,rhs).
		int64_t Dot (const Int64Vector3& rhs) const;
		
		// ∑µªÿ Cross(this,V)
		Int64Vector3 Cross (const Int64Vector3& rhs) const;
		
		// ∑µªÿ Dot(this,Cross(U,V))
		int64_t TripleScalar (const Int64Vector3& mhs,const Int64Vector3& rhs) const;
		
		bool operator== (const Int64Vector3& rhs) const;		
		bool operator<  (const Int64Vector3& rhs) const;

	private:
		IMPL_TYPE_DECLARE(Int64Vector3);
	};

	MATHEMATICS_DEFAULT_DECLARE std::ostream& operator<< (std::ostream& os, const Int64Vector3& rhs);
}

#endif // MATHEMATICS_RATIONAL_INT64_VECTOR3_H
