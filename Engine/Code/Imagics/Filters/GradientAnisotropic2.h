// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:54)

#ifndef IMAGICS_FILTERS_GRADIENT_ANISOTROPIC2_H
#define IMAGICS_FILTERS_GRADIENT_ANISOTROPIC2_H

#include "Imagics/ImagicsDll.h"

#include "PdeFilter2.h"

namespace Imagics
{
	class IMAGICS_DEFAULT_DECLARE GradientAnisotropic2 : public PdeFilter2
	{
	public:
		GradientAnisotropic2 (int xBound, int yBound, float xSpacing,float ySpacing, const float* data, const bool* mask,float borderValue, ScaleType scaleType, float K);
		
		virtual ~GradientAnisotropic2 ();
		
	protected:
		void ComputeParam ();
		virtual void OnPreUpdate () override;
		virtual void OnUpdate (int x, int y) override;
		
		float mK;           // k
		
		// These are updated on each iteration, since they depend on the current
		// average of the squared length of the gradients at the pixels.
		float mParam;       // 1/(k^2*average(gradMagSqr))
		float mMHalfParam;  // -0.5*mParam;
	};
}

#endif // IMAGICS_FILTERS_GRADIENT_ANISOTROPIC2_H
