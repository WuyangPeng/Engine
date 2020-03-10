// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:53)

#ifndef IMAGICS_FILTERS_GAUSSIAN_BLUR2_H
#define IMAGICS_FILTERS_GAUSSIAN_BLUR2_H

#include "Imagics/ImagicsDll.h"

#include "PdeFilter2.h"

namespace Imagics
{
	class IMAGICS_DEFAULT_DECLARE GaussianBlur2 : public PdeFilter2
	{
	public:
		GaussianBlur2 (int xBound, int yBound, float xSpacing, float ySpacing,const float* data, const bool* mask, float borderValue,ScaleType scaleType);
		
		virtual ~GaussianBlur2 ();
		
		float GetMaximumTimeStep () const;

	protected:
		virtual void OnUpdate (int x, int y) override;
		
		float mMaximumTimeStep;
	};
}

#endif // IMAGICS_FILTERS_GAUSSIAN_BLUR2_H
