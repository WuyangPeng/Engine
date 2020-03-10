// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:28)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_SURFACE_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_SURFACE_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	template <typename Real>
	class Surface
	{
	public:
		// Abstract base class.
		virtual ~Surface();

	protected:
		Surface();
	};

	using Surfacef = Surface<float>;
	using Surfaced = Surface<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_SURFACE_H
