// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:54)

#ifndef IMAGICS_FILTERS_GRADIENT_ANISOTROPIC3_H
#define IMAGICS_FILTERS_GRADIENT_ANISOTROPIC3_H

#include "Imagics/ImagicsDll.h"

#include "PdeFilter3.h"

namespace Imagics
{
	class IMAGICS_DEFAULT_DECLARE GradientAnisotropic3 : public PdeFilter3
	{
	public:
		GradientAnisotropic3 (int xBound, int yBound, int zBound, float xSpacing,float ySpacing, float zSpacing, 
							  const float* data, const bool* mask,float borderValue, ScaleType scaleType, float K);
		
		virtual ~GradientAnisotropic3 ();
		
	protected:
		void ComputeParam ();
		virtual void OnPreUpdate ();
		virtual void OnUpdate (int x, int y, int z);
		
		float mK;           // k
		
		// These are updated on each iteration, since they depend on the current
		// average of the squared length of the gradients at the pixels.
		float mParam;       // 1/(k^2*average(gradMagSqr))
		float mMHalfParam;  // -0.5*mParam;
	};
}

#endif // IMAGICS_FILTERS_GRADIENT_ANISOTROPIC3_H
