// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/07 23:38)

#ifndef SYSTEM_HELPER_GL_21_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GL_21_EXTENSIONS_MACRO_H

#include "System/Helper/GLExtensionsMacro.h" 

#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_PIXEL_UNPACK_BUFFER 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#define GL_FLOAT_MAT2x3 0x8B65
#define GL_FLOAT_MAT2x4 0x8B66
#define GL_FLOAT_MAT3x2 0x8B67
#define GL_FLOAT_MAT3x4 0x8B68
#define GL_FLOAT_MAT4x2 0x8B69
#define GL_FLOAT_MAT4x3 0x8B6A
#define GL_SRGB 0x8C40
#define GL_SRGB8 0x8C41
#define GL_SRGB_ALPHA 0x8C42
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_SLUMINANCE_ALPHA 0x8C44
#define GL_SLUMINANCE8_ALPHA8 0x8C45
#define GL_SLUMINANCE 0x8C46
#define GL_SLUMINANCE8 0x8C47
#define GL_COMPRESSED_SRGB 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#define GL_COMPRESSED_SLUMINANCE 0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B

#define glUniformMatrix2x3fv System::GlUniformMatrix2x3fv
#define glUniformMatrix3x2fv System::GlUniformMatrix3x2fv
#define glUniformMatrix2x4fv System::GlUniformMatrix2x4fv
#define glUniformMatrix4x2fv System::GlUniformMatrix4x2fv
#define glUniformMatrix3x4fv System::GlUniformMatrix3x4fv
#define glUniformMatrix4x3fv System::GlUniformMatrix4x3fv

#endif // SYSTEM_HELPER_GL_21_EXTENSIONS_MACRO_H
