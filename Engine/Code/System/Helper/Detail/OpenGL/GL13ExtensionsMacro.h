//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:46)

#ifndef SYSTEM_HELPER_GL_13_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GL_13_EXTENSIONS_MACRO_H

#include "System/Helper/GLExtensionsMacro.h"

#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_MAX_TEXTURE_UNITS 0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
#define GL_MULTISAMPLE 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLES 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_MULTISAMPLE_BIT 0x20000000
#define GL_NORMAL_MAP 0x8511
#define GL_REFLECTION_MAP 0x8512
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_COMPRESSED_ALPHA 0x84E9
#define GL_COMPRESSED_LUMINANCE 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#define GL_COMPRESSED_INTENSITY 0x84EC
#define GL_COMPRESSED_RGB 0x84ED
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_CLAMP_TO_BORDER 0x812D
#define GL_COMBINE 0x8570
#define GL_COMBINE_RGB 0x8571
#define GL_COMBINE_ALPHA 0x8572
#define GL_SOURCE0_RGB 0x8580
#define GL_SOURCE1_RGB 0x8581
#define GL_SOURCE2_RGB 0x8582
#define GL_SOURCE0_ALPHA 0x8588
#define GL_SOURCE1_ALPHA 0x8589
#define GL_SOURCE2_ALPHA 0x858A
#define GL_OPERAND0_RGB 0x8590
#define GL_OPERAND1_RGB 0x8591
#define GL_OPERAND2_RGB 0x8592
#define GL_OPERAND0_ALPHA 0x8598
#define GL_OPERAND1_ALPHA 0x8599
#define GL_OPERAND2_ALPHA 0x859A
#define GL_RGB_SCALE 0x8573
#define GL_ADD_SIGNED 0x8574
#define GL_INTERPOLATE 0x8575
#define GL_SUBTRACT 0x84E7
#define GL_CONSTANT 0x8576
#define GL_PRIMARY_COLOR 0x8577
#define GL_PREVIOUS 0x8578
#define GL_DOT3_RGB 0x86AE
#define GL_DOT3_RGBA 0x86AF

#define glActiveTexture System::GlActiveTexture
#define glClientActiveTexture System::GlClientActiveTexture
#define glMultiTexCoord1d System::GlMultiTexCoord1d
#define glMultiTexCoord1dv System::GlMultiTexCoord1dv
#define glMultiTexCoord1f System::GlMultiTexCoord1f
#define glMultiTexCoord1fv System::GlMultiTexCoord1fv
#define glMultiTexCoord1i System::GlMultiTexCoord1i
#define glMultiTexCoord1iv System::GlMultiTexCoord1iv
#define glMultiTexCoord1s System::GlMultiTexCoord1s
#define glMultiTexCoord1sv System::GlMultiTexCoord1sv
#define glMultiTexCoord2d System::GlMultiTexCoord2d
#define glMultiTexCoord2dv System::GlMultiTexCoord2dv
#define glMultiTexCoord2f System::GlMultiTexCoord2f
#define glMultiTexCoord2fv System::GlMultiTexCoord2fv
#define glMultiTexCoord2i System::GlMultiTexCoord2i
#define glMultiTexCoord2iv System::GlMultiTexCoord2iv
#define glMultiTexCoord2s System::GlMultiTexCoord2s
#define glMultiTexCoord2sv System::GlMultiTexCoord2sv
#define glMultiTexCoord3d System::GlMultiTexCoord3d
#define glMultiTexCoord3dv System::GlMultiTexCoord3dv
#define glMultiTexCoord3f System::GlMultiTexCoord3f
#define glMultiTexCoord3fv System::GlMultiTexCoord3fv
#define glMultiTexCoord3i System::GlMultiTexCoord3i
#define glMultiTexCoord3iv System::GlMultiTexCoord3iv
#define glMultiTexCoord3s System::GlMultiTexCoord3s
#define glMultiTexCoord3sv System::GlMultiTexCoord3sv
#define glMultiTexCoord4d System::GlMultiTexCoord4d
#define glMultiTexCoord4dv System::GlMultiTexCoord4dv
#define glMultiTexCoord4f System::GlMultiTexCoord4f
#define glMultiTexCoord4fv System::GlMultiTexCoord4fv
#define glMultiTexCoord4i System::GlMultiTexCoord4i
#define glMultiTexCoord4iv System::GlMultiTexCoord4iv
#define glMultiTexCoord4s System::GlMultiTexCoord4s
#define glMultiTexCoord4sv System::GlMultiTexCoord4sv
#define glLoadTransposeMatrixd System::GlLoadTransposeMatrixd
#define glLoadTransposeMatrixf System::GlLoadTransposeMatrixf
#define glMultTransposeMatrixd System::GlMultTransposeMatrixd
#define glMultTransposeMatrixf System::GlMultTransposeMatrixf
#define glSampleCoverage System::GlSampleCoverage
#define glCompressedTexImage1D System::GlCompressedTexImage1D
#define glCompressedTexImage2D System::GlCompressedTexImage2D
#define glCompressedTexImage3D System::GlCompressedTexImage3D
#define glCompressedTexSubImage1D System::GlCompressedTexSubImage1D
#define glCompressedTexSubImage2D System::GlCompressedTexSubImage2D
#define glCompressedTexSubImage3D System::GlCompressedTexSubImage3D
#define glGetCompressedTexImage System::GlGetCompressedTexImage

#endif  // SYSTEM_HELPER_GL_13_EXTENSIONS_MACRO_H
