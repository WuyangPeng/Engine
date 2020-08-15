// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:54)

#ifndef IMAGICS_FILTERS_GAUSSIAN_BLUR3_H
#define IMAGICS_FILTERS_GAUSSIAN_BLUR3_H

#include "Imagics/ImagicsDll.h"

#include "PdeFilter3.h"

namespace Imagics
{
	class IMAGICS_DEFAULT_DECLARE GaussianBlur3 : public PdeFilter3
	{
	public:
		GaussianBlur3 (int xBound, int yBound, int zBound, float xSpacing,float ySpacing, float zSpacing, const float* data,const bool* mask, float borderValue, ScaleType scaleType);
		
	 
		
		float GetMaximumTimeStep () const noexcept;

	protected:
                void OnUpdate(int x, int y, int z) noexcept override;
		
		float mMaximumTimeStep;
	};
}

#endif // IMAGICS_FILTERS_GAUSSIAN_BLUR3_H
