// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:03)

#ifndef SYSTEM_HELPER_GL_ARB_IMAGING_FLAGS_H
#define SYSTEM_HELPER_GL_ARB_IMAGING_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
	enum class GLARBImagingFlags
	{
		BlendColor,
		BlendEquation,
		ColorTable,
		ColorTableParameterfv,
		ColorTableParameteriv,
		CopyColorTable,
		GetColorTable,
		GetColorTableParameterfv,
		GetColorTableParameteriv,
		ColorSubTable,
		CopyColorSubTable,
		ConvolutionFilter1D,
		ConvolutionFilter2D,
		ConvolutionParameterf,
		ConvolutionParameterfv,
		ConvolutionParameteri,
		ConvolutionParameteriv,
		CopyConvolutionFilter1D,
		CopyConvolutionFilter2D,
		GetConvolutionFilter,
		GetConvolutionParameterfv,
		GetConvolutionParameteriv,
		GetSeparableFilter,
		SeparableFilter2D,
		GetHistogram,
		GetHistogramParameterfv,
		GetHistogramParameteriv,
		GetMinmax,
		GetMinmaxParameterfv,
		GetMinmaxParameteriv,
		Histogram,
		Minmax,
		ResetHistogram,
		ResetMinmax,
	};
}

#endif // SYSTEM_HELPER_GL_ARB_IMAGING_FLAGS_H
