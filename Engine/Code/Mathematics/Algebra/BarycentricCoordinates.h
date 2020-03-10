// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/04 10:39)

#ifndef MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_H
#define MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/Math.h"
#include "CoreTools/DataTypes/TupleDetail.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real,int WindowSize>
	class BarycentricCoordinates  
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");
		static_assert((WindowSize == 3 || WindowSize == 4), "WindowSize must be 3 or 4.");

		using ClassType = BarycentricCoordinates<Real,WindowSize>;
		using Tuple = CoreTools::Tuple<WindowSize,Real>;
		using Math = Math<Real>;
		using AlgebraTraits = AlgebraTraits<Real>;

	public:
		BarycentricCoordinates (bool isValid,const Tuple& tuple); 
		BarycentricCoordinates ();		

		CLASS_INVARIANT_DECLARE;

		// ◊¯±Í∑√Œ 
		const Real& operator[] (unsigned int index) const;
		bool IsBarycentricCoordinatesValid() const;	
		
	private:
		bool m_IsValid;
		Tuple m_Tuple;
	};		
}

#endif // MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_H
