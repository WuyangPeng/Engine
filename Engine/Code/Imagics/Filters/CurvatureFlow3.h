// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 15:53)

#ifndef IMAGICS_FILTERS_CURVATURE_FLOW3_H
#define IMAGICS_FILTERS_CURVATURE_FLOW3_H

#include "Imagics/ImagicsDll.h"

#include "PdeFilter3.h"

namespace Imagics
{
    class IMAGICS_DEFAULT_DECLARE CurvatureFlow3 : public PdeFilter3
    {
    public:
        CurvatureFlow3(int xBound, int yBound, int zBound, float xSpacing, float ySpacing, float zSpacing, const float* data, const bool* mask, float borderValue, ScaleType scaleType);

    protected:
        void OnUpdate(int x, int y, int z) noexcept override;
    };
}

#endif  // IMAGICS_FILTERS_CURVATURE_FLOW3_H
