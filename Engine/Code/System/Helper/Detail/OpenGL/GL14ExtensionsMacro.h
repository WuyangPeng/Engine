// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:04)

#ifndef SYSTEM_HELPER_GL_14_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GL_14_EXTENSIONS_MACRO_H

#include "System/Helper/GLExtensionsMacro.h"

#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_POINT_SIZE_MIN 0x8126
#define GL_POINT_SIZE_MAX 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#define GL_GENERATE_MIPMAP 0x8191
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
#define GL_MIRRORED_REPEAT 0x8370
#define GL_FOG_COORDINATE_SOURCE 0x8450
#define GL_FOG_COORDINATE 0x8451
#define GL_FRAGMENT_DEPTH 0x8452
#define GL_CURRENT_FOG_COORDINATE 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
#define GL_FOG_COORDINATE_ARRAY 0x8457
#define GL_COLOR_SUM 0x8458
#define GL_CURRENT_SECONDARY_COLOR 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
#define GL_SECONDARY_COLOR_ARRAY 0x845E
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_TEXTURE_FILTER_CONTROL 0x8500
#define GL_TEXTURE_LOD_BIAS 0x8501
#define GL_INCR_WRAP 0x8507
#define GL_DECR_WRAP 0x8508
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_DEPTH_TEXTURE_MODE 0x884B
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#define GL_COMPARE_R_TO_TEXTURE 0x884E

#define glBlendFuncSeparate System::GlBlendFuncSeparate
#define glFogCoordd System::GlFogCoordd
#define glFogCoorddv System::GlFogCoorddv
#define glFogCoordf System::GlFogCoordf
#define glFogCoordfv System::GlFogCoordfv
#define glFogCoordPointer System::GlFogCoordPointer
#define glMultiDrawArrays System::GlMultiDrawArrays
#define glMultiDrawElements System::GlMultiDrawElements
#define glPointParameterf System::GlPointParameterf
#define glPointParameterfv System::GlPointParameterfv
#define glPointParameteri System::GlPointParameteri
#define glPointParameteriv System::GlPointParameteriv
#define glSecondaryColor3b System::GlSecondaryColor3b
#define glSecondaryColor3bv System::GlSecondaryColor3bv
#define glSecondaryColor3d System::GlSecondaryColor3d
#define glSecondaryColor3dv System::GlSecondaryColor3dv
#define glSecondaryColor3f System::GlSecondaryColor3f
#define glSecondaryColor3fv System::GlSecondaryColor3fv
#define glSecondaryColor3i System::GlSecondaryColor3i
#define glSecondaryColor3iv System::GlSecondaryColor3iv
#define glSecondaryColor3s System::GlSecondaryColor3s
#define glSecondaryColor3sv System::GlSecondaryColor3sv
#define glSecondaryColor3ub System::GlSecondaryColor3ub
#define glSecondaryColor3ubv System::GlSecondaryColor3ubv
#define glSecondaryColor3ui System::GlSecondaryColor3ui
#define glSecondaryColor3uiv System::GlSecondaryColor3uiv
#define glSecondaryColor3us System::GlSecondaryColor3us
#define glSecondaryColor3usv System::GlSecondaryColor3usv
#define glSecondaryColorPointer System::GlSecondaryColorPointer
#define glWindowPos2d System::GlWindowPos2d
#define glWindowPos2dv System::GlWindowPos2dv
#define glWindowPos2f System::GlWindowPos2f
#define glWindowPos2fv System::GlWindowPos2fv
#define glWindowPos2i System::GlWindowPos2i
#define glWindowPos2iv System::GlWindowPos2iv
#define glWindowPos2s System::GlWindowPos2s
#define glWindowPos2sv System::GlWindowPos2sv
#define glWindowPos3d System::GlWindowPos3d
#define glWindowPos3dv System::GlWindowPos3dv
#define glWindowPos3f System::GlWindowPos3f
#define glWindowPos3fv System::GlWindowPos3fv
#define glWindowPos3i System::GlWindowPos3i
#define glWindowPos3iv System::GlWindowPos3iv
#define glWindowPos3s System::GlWindowPos3s
#define glWindowPos3sv System::GlWindowPos3sv 

#endif // SYSTEM_HELPER_GL_14_EXTENSIONS_MACRO_H
