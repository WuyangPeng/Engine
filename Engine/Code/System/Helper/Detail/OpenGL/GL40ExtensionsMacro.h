// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:05)

#ifndef SYSTEM_HELPER_GL_40_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GL_40_EXTENSIONS_MACRO_H

#include "System/Helper/GLExtensionsMacro.h" 

#define GL_SAMPLE_SHADING 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS 0x8F9F
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F

#define glBlendEquationSeparatei System::GlBlendEquationSeparatei
#define glBlendEquationi System::GlBlendEquationi
#define glBlendFuncSeparatei System::GlBlendFuncSeparatei
#define glBlendFunci System::GlBlendFunci
#define glMinSampleShading System::GlMinSampleShading

#endif // SYSTEM_HELPER_GL_40_EXTENSIONS_MACRO_H
