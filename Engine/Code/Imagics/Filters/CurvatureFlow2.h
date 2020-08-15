// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:53)

#ifndef IMAGICS_FILTERS_CURVATURE_FLOW2_H
#define IMAGICS_FILTERS_CURVATURE_FLOW2_H

#include "Imagics/ImagicsDll.h"

#include "PdeFilter2.h"

namespace Imagics
{
	class IMAGICS_DEFAULT_DECLARE CurvatureFlow2 : public PdeFilter2
	{
	public:
		CurvatureFlow2 (int xBound, int yBound, float xSpacing, float ySpacing, const float* data, const bool* mask, float borderValue, ScaleType scaleType);
 
		
	protected:
		  void OnUpdate (int x, int y) noexcept override;
	};
}

#endif // IMAGICS_FILTERS_CURVATURE_FLOW2_H
