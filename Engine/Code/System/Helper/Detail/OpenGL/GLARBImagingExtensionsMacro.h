// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/07 23:41)

#ifndef SYSTEM_HELPER_GL_ARB_IMAGING_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GL_ARB_IMAGING_EXTENSIONS_MACRO_H

#include "System/Helper/GLExtensionsMacro.h"

// ≥…œÒ◊”ºØ (GL_ARB_imaging)

#define GL_CONSTANT_COLOR 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_BLEND_COLOR 0x8005
#define GL_FUNC_ADD 0x8006
#define GL_MIN 0x8007
#define GL_MAX 0x8008
#define GL_BLEND_EQUATION 0x8009
#define GL_FUNC_SUBTRACT 0x800A
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_CONVOLUTION_1D 0x8010
#define GL_CONVOLUTION_2D 0x8011
#define GL_SEPARABLE_2D 0x8012
#define GL_CONVOLUTION_BORDER_MODE 0x8013
#define GL_CONVOLUTION_FILTER_SCALE 0x8014
#define GL_CONVOLUTION_FILTER_BIAS 0x8015
#define GL_REDUCE 0x8016
#define GL_CONVOLUTION_FORMAT 0x8017
#define GL_CONVOLUTION_WIDTH 0x8018
#define GL_CONVOLUTION_HEIGHT 0x8019
#define GL_MAX_CONVOLUTION_WIDTH 0x801A
#define GL_MAX_CONVOLUTION_HEIGHT 0x801B
#define GL_POST_CONVOLUTION_RED_SCALE 0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE 0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE 0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE 0x801F
#define GL_POST_CONVOLUTION_RED_BIAS 0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS 0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS 0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS 0x8023
#define GL_HISTOGRAM 0x8024
#define GL_PROXY_HISTOGRAM 0x8025
#define GL_HISTOGRAM_WIDTH 0x8026
#define GL_HISTOGRAM_FORMAT 0x8027
#define GL_HISTOGRAM_RED_SIZE 0x8028
#define GL_HISTOGRAM_GREEN_SIZE 0x8029
#define GL_HISTOGRAM_BLUE_SIZE 0x802A
#define GL_HISTOGRAM_ALPHA_SIZE 0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE 0x802C
#define GL_HISTOGRAM_SINK 0x802D
#define GL_MINMAX 0x802E
#define GL_MINMAX_FORMAT 0x802F
#define GL_MINMAX_SINK 0x8030
#define GL_TABLE_TOO_LARGE 0x8031
#define GL_COLOR_MATRIX 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH 0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH 0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE 0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE 0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE 0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE 0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS 0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS 0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS 0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS 0x80BB
#define GL_COLOR_TABLE 0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE 0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE 0x80D2
#define GL_PROXY_COLOR_TABLE 0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
#define GL_COLOR_TABLE_SCALE 0x80D6
#define GL_COLOR_TABLE_BIAS 0x80D7
#define GL_COLOR_TABLE_FORMAT 0x80D8
#define GL_COLOR_TABLE_WIDTH 0x80D9
#define GL_COLOR_TABLE_RED_SIZE 0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE 0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE 0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE 0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE 0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE 0x80DF
#define GL_IGNORE_BORDER 0x8150
#define GL_CONSTANT_BORDER 0x8151
#define GL_WRAP_BORDER 0x8152
#define GL_REPLICATE_BORDER 0x8153
#define GL_CONVOLUTION_BORDER_COLOR 0x8154

#define glBlendColor System::GlBlendColor
#define glBlendEquation System::GlBlendEquation
#define glColorTable System::GlColorTable
#define glColorTableParameterfv System::GlColorTableParameterfv
#define glColorTableParameteriv System::GlColorTableParameteriv
#define glCopyColorTable System::GlCopyColorTable
#define glGetColorTable System::GlGetColorTable
#define glGetColorTableParameterfv System::GlGetColorTableParameterfv
#define glGetColorTableParameteriv System::GlGetColorTableParameteriv
#define glColorSubTable System::GlColorSubTable
#define glCopyColorSubTable System::GlCopyColorSubTable
#define glConvolutionFilter1D System::GlConvolutionFilter1D
#define glConvolutionFilter2D System::GlConvolutionFilter2D
#define glConvolutionParameterf System::GlConvolutionParameterf
#define glConvolutionParameterfv System::GlConvolutionParameterfv
#define glConvolutionParameteri System::GlConvolutionParameteri
#define glConvolutionParameteriv System::GlConvolutionParameteriv
#define glCopyConvolutionFilter1D System::GlCopyConvolutionFilter1D
#define glCopyConvolutionFilter2D System::GlCopyConvolutionFilter2D
#define glGetConvolutionFilter System::GlGetConvolutionFilter
#define glGetConvolutionParameterfv System::GlGetConvolutionParameterfv
#define glGetConvolutionParameteriv System::GlGetConvolutionParameteriv
#define glGetSeparableFilter System::GlGetSeparableFilter
#define glSeparableFilter2D System::GlSeparableFilter2D
#define glGetHistogram System::GlGetHistogram
#define glGetHistogramParameterfv System::GlGetHistogramParameterfv
#define glGetHistogramParameteriv System::GlGetHistogramParameteriv
#define glGetMinmax System::GlGetMinmax
#define glGetMinmaxParameterfv System::GlGetMinmaxParameterfv
#define glGetMinmaxParameteriv System::GlGetMinmaxParameteriv
#define glHistogram System::GlHistogram
#define glMinmax System::GlMinmax
#define glResetHistogram System::GlResetHistogram
#define glResetMinmax System::GlResetMinmax 

#endif // SYSTEM_HELPER_GL_ARB_IMAGING_EXTENSIONS_MACRO_H
