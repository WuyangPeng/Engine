// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 17:24)

#ifndef MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_H
#define MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/DataTypes/TupleDetail.h"
#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Torus3Parameters
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Torus3Parameters<Real>;
		using Math = Math<Real>;

	public:
		Torus3Parameters(Real s, Real t) noexcept;

		CLASS_INVARIANT_DECLARE;

		Real GetS() const noexcept;
		Real GetT() const noexcept;

	private:
		Real m_S;
		Real m_T;
	};

	using Torus3Parametersf = Torus3Parameters<float>;
	using Torus3Parametersd = Torus3Parameters<double>;
}

#endif // MATHEMATICS_OBJECTS3D_TORUS3_PARAMETERS_H
