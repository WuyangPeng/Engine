// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/07 23:38)

#ifndef SYSTEM_HELPER_GL_20_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GL_20_EXTENSIONS_MACRO_H

#include "System/Helper/GLExtensionsMacro.h"

#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_POINT_SPRITE 0x8861
#define GL_COORD_REPLACE 0x8862
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_COORDS 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE 0x8B4F
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_DELETE_STATUS 0x8B80
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_VALIDATE_STATUS 0x8B83
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_LOWER_LEFT 0x8CA1
#define GL_UPPER_LEFT 0x8CA2
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5

#define glBlendEquationSeparate System::GlBlendEquationSeparate
#define glDrawBuffers System::GlDrawBuffers
#define glStencilOpSeparate System::GlStencilOpSeparate
#define glStencilFuncSeparate System::GlStencilFuncSeparate
#define glStencilMaskSeparate System::GlStencilMaskSeparate
#define glAttachShader System::GlAttachShader
#define glBindAttribLocation System::GlBindAttribLocation
#define glCompileShader System::GlCompileShader
#define glCreateProgram System::GlCreateProgram
#define glCreateShader System::GlCreateShader
#define glDeleteProgram System::GlDeleteProgram
#define glDeleteShader System::GlDeleteShader
#define glDetachShader System::GlDetachShader
#define glDisableVertexAttribArray System::GlDisableVertexAttribArray
#define glEnableVertexAttribArray System::GlEnableVertexAttribArray
#define glGetActiveAttrib System::GlGetActiveAttrib
#define glGetActiveUniform System::GlGetActiveUniform
#define glGetAttachedShaders System::GlGetAttachedShaders
#define glGetAttribLocation System::GlGetAttribLocation
#define glGetProgramiv System::GlGetProgramiv
#define glGetProgramInfoLog System::GlGetProgramInfoLog
#define glGetShaderiv System::GlGetShaderiv
#define glGetShaderInfoLog System::GlGetShaderInfoLog
#define glGetShaderSource System::GlGetShaderSource
#define glGetUniformLocation System::GlGetUniformLocation
#define glGetUniformfv System::GlGetUniformfv
#define glGetUniformiv System::GlGetUniformiv
#define glGetVertexAttribdv System::GlGetVertexAttribdv
#define glGetVertexAttribfv System::GlGetVertexAttribfv
#define glGetVertexAttribiv System::GlGetVertexAttribiv
#define glGetVertexAttribPointerv System::GlGetVertexAttribPointerv
#define glIsProgram System::GlIsProgram
#define glIsShader System::GlIsShader
#define glLinkProgram System::GlLinkProgram
#define glShaderSource System::GlShaderSource
#define glUseProgram System::GlUseProgram
#define glUniform1f System::GlUniform1f
#define glUniform2f System::GlUniform2f
#define glUniform3f System::GlUniform3f
#define glUniform4f System::GlUniform4f
#define glUniform1i System::GlUniform1i
#define glUniform2i System::GlUniform2i
#define glUniform3i System::GlUniform3i
#define glUniform4i System::GlUniform4i
#define glUniform1fv System::GlUniform1fv
#define glUniform2fv System::GlUniform2fv
#define glUniform3fv System::GlUniform3fv
#define glUniform4fv System::GlUniform4fv
#define glUniform1iv System::GlUniform1iv
#define glUniform2iv System::GlUniform2iv
#define glUniform3iv System::GlUniform3iv
#define glUniform4iv System::GlUniform4iv
#define glUniformMatrix2fv System::GlUniformMatrix2fv
#define glUniformMatrix3fv System::GlUniformMatrix3fv
#define glUniformMatrix4fv System::GlUniformMatrix4fv
#define glValidateProgram System::GlValidateProgram
#define glVertexAttrib1d System::GlVertexAttrib1d
#define glVertexAttrib1dv System::GlVertexAttrib1dv
#define glVertexAttrib1f System::GlVertexAttrib1f
#define glVertexAttrib1fv System::GlVertexAttrib1fv
#define glVertexAttrib1s System::GlVertexAttrib1s
#define glVertexAttrib1sv System::GlVertexAttrib1sv
#define glVertexAttrib2d System::GlVertexAttrib2d
#define glVertexAttrib2dv System::GlVertexAttrib2dv
#define glVertexAttrib2f System::GlVertexAttrib2f
#define glVertexAttrib2fv System::GlVertexAttrib2fv
#define glVertexAttrib2s System::GlVertexAttrib2s
#define glVertexAttrib2sv System::GlVertexAttrib2sv
#define glVertexAttrib3d System::GlVertexAttrib3d
#define glVertexAttrib3dv System::GlVertexAttrib3dv
#define glVertexAttrib3f System::GlVertexAttrib3f
#define glVertexAttrib3fv System::GlVertexAttrib3fv
#define glVertexAttrib3s System::GlVertexAttrib3s
#define glVertexAttrib3sv System::GlVertexAttrib3sv
#define glVertexAttrib4Nbv System::GlVertexAttrib4Nbv
#define glVertexAttrib4Niv System::GlVertexAttrib4Niv
#define glVertexAttrib4Nsv System::GlVertexAttrib4Nsv
#define glVertexAttrib4Nub System::GlVertexAttrib4Nub
#define glVertexAttrib4Nubv System::GlVertexAttrib4Nubv
#define glVertexAttrib4Nuiv System::GlVertexAttrib4Nuiv
#define glVertexAttrib4Nusv System::GlVertexAttrib4Nusv
#define glVertexAttrib4bv System::GlVertexAttrib4bv
#define glVertexAttrib4d System::GlVertexAttrib4d
#define glVertexAttrib4dv System::GlVertexAttrib4dv
#define glVertexAttrib4f System::GlVertexAttrib4f
#define glVertexAttrib4fv System::GlVertexAttrib4fv
#define glVertexAttrib4iv System::GlVertexAttrib4iv
#define glVertexAttrib4s System::GlVertexAttrib4s
#define glVertexAttrib4sv System::GlVertexAttrib4sv
#define glVertexAttrib4ubv System::GlVertexAttrib4ubv
#define glVertexAttrib4uiv System::GlVertexAttrib4uiv
#define glVertexAttrib4usv System::GlVertexAttrib4usv
#define glVertexAttribPointer System::GlVertexAttribPointer

#endif // SYSTEM_HELPER_GL_20_EXTENSIONS_MACRO_H
