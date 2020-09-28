//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 17:40)

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

#endif  // SYSTEM_HELPER_GL_ARB_IMAGING_FLAGS_H
