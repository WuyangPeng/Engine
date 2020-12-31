//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:39)

#ifndef SYSTEM_OPENGL_GL_ARB_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_ARB_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GLARBExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/OpenGL/Using/GL15ExtensionsUsing.h"
#include "System/OpenGL/Using/GL20ExtensionsUsing.h"
#include "System/OpenGL/Using/GL32ExtensionsUsing.h"
#include "System/OpenGL/Using/GLARBExtensionsUsing.h"

namespace System
{
    // ARB 扩展

    // (ARB 01) GL_ARB_multitexture

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbMultitexture() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlActiveTextureARB(GLenum texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClientActiveTextureARB(GLenum texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1dARB(GLenum target, GLdouble s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1dvARB(GLenum target, const GLdouble* s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1fARB(GLenum target, GLfloat s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1fvARB(GLenum target, const GLfloat* s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1iARB(GLenum target, GLint s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1ivARB(GLenum target, const GLint* s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1sARB(GLenum target, GLshort s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord1svARB(GLenum target, const GLshort* s) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2dvARB(GLenum target, const GLdouble* st) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2fvARB(GLenum target, const GLfloat* st) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2iARB(GLenum target, GLint s, GLint t) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2ivARB(GLenum target, const GLint* st) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2sARB(GLenum target, GLshort s, GLshort st) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord2svARB(GLenum target, const GLshort* st) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3dvARB(GLenum target, const GLdouble* str) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3fvARB(GLenum target, const GLfloat* str) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3ivARB(GLenum target, const GLint* str) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3sARB(GLenum target, GLshort s, GLshort st, GLshort r) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord3svARB(GLenum target, const GLshort* str) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4dvARB(GLenum target, const GLdouble* strq) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4fvARB(GLenum target, const GLfloat* strq) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4ivARB(GLenum target, const GLint* strq) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4sARB(GLenum target, GLshort s, GLshort st, GLshort r, GLshort q) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoord4svARB(GLenum target, const GLshort* strq) noexcept;

    // (ARB 03) GL_ARB_transpose_matrix

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTransposeMatrix() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlLoadTransposeMatrixdARB(const GLdouble* matrix) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlLoadTransposeMatrixfARB(const GLfloat* matrix) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultTransposeMatrixdARB(const GLdouble* matrix) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultTransposeMatrixfARB(const GLfloat* matrix) noexcept;

    // (ARB 05) GL_ARB_multisample

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbMultisample() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlSampleCoverageARB(GLclampf value, GLboolean invert) noexcept;

    // (ARB 06) GL_ARB_texture_env_add

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureEnvAdd() noexcept;

    // (ARB 07) GL_ARB_texture_cube_map

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureCubeMap() noexcept;

    // (ARB 12) GL_ARB_texture_compression

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureCompression() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalFormat, GLsizei width,
                                                         GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLsizei height,
                                                         GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xOffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLsizei width,
                                                            GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width,
                                                            GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetCompressedTexImageARB(GLenum target, GLint level, GLvoid* data) noexcept;

    // (ARB 13) GL_ARB_texture_border_clamp

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureBorderClamp() noexcept;

    // (ARB 14) GL_ARB_point_parameters

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbPointParameters() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlPointParameterfARB(GLenum name, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlPointParameterfvARB(GLenum name, const GLfloat* param) noexcept;

    // (ARB 15) GL_ARB_vertex_blend

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbVertexBlend() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlWeightbvARB(GLint size, const GLbyte* weight) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWeightsvARB(GLint size, const GLshort* weight) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWeightivARB(GLint size, const GLint* weight) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWeightfvARB(GLint size, const GLfloat* weight) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWeightdvARB(GLint size, const GLdouble* weight) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWeightubvARB(GLint size, const GLubyte* weight) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWeightusvARB(GLint size, const GLushort* weight) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWeightuivARB(GLint size, const GLuint* weight) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWeightPointerARB(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexBlendARB(GLint count) noexcept;

    // (ARB 16) GL_ARB_matrix_palette

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbMatrixPalette() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlCurrentPaletteMatrixARB(GLint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixIndexubvARB(GLint size, const GLubyte* index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixIndexusvARB(GLint size, const GLushort* index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixIndexuivARB(GLint size, const GLuint* index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept;

    // (ARB 17) GL_ARB_texture_env_combine

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureEnvCombine() noexcept;

    // (ARB 18) GL_ARB_texture_env_crossbar

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureEnvCrossbar() noexcept;

    // (ARB 19) GL_ARB_texture_env_dot3

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureEnvDot3() noexcept;

    // (ARB 21) GL_ARB_texture_mirrored_repeat

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureMirroredRepeat() noexcept;

    // (ARB 22) GL_ARB_depth_texture

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbDepthTexture() noexcept;

    // (ARB 23) GL_ARB_shadow

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShadow() noexcept;

    // (ARB 24) GL_ARB_shadow_ambient

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShadowAmbient() noexcept;

    // (ARB 25) GL_ARB_window_pos

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbWindowPos() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlWindowPos2dARB(GLdouble x, GLdouble y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos2dvARB(const GLdouble* xy) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos2fARB(GLfloat x, GLfloat y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos2fvARB(const GLfloat* xy) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos2iARB(GLint x, GLint y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos2ivARB(const GLint* xy) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos2sARB(GLshort x, GLshort y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos2svARB(const GLshort* xy) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos3dvARB(const GLdouble* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos3fvARB(const GLfloat* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos3iARB(GLint x, GLint y, GLint z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos3ivARB(const GLint* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos3sARB(GLshort x, GLshort y, GLshort z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWindowPos3svARB(const GLshort* xyz) noexcept;

    // (ARB 26) GL_ARB_vertex_program

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbVertexProgram() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindProgramARB(GLenum target, GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteProgramsARB(GLsizei numPrograms, const GLuint* programs) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDisableVertexAttribArrayARB(GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEnableVertexAttribArrayARB(GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenProgramsARB(GLsizei numPrograms, GLuint* programs) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetProgramivARB(GLenum target, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetProgramStringARB(GLenum target, GLenum name, GLvoid* programString) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribdvARB(GLuint index, GLenum name, GLdouble* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribfvARB(GLuint index, GLenum name, GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribivARB(GLuint index, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribPointervARB(GLuint index, GLenum name, GLvoid** pointer) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsProgramARB(GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramEnvParameter4dvARB(GLenum target, GLuint index, const GLdouble* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramEnvParameter4fvARB(GLenum target, GLuint index, const GLfloat* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramLocalParameter4dvARB(GLenum target, GLuint index, const GLdouble* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramLocalParameter4fvARB(GLenum target, GLuint index, const GLfloat* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramStringARB(GLenum target, GLenum format, GLsizei length, const GLvoid* programString) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib1dARB(GLuint index, GLdouble x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib1dvARB(GLuint index, const GLdouble* x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib1fARB(GLuint index, GLfloat x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib1fvARB(GLuint index, const GLfloat* x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib1sARB(GLuint index, GLshort x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib1svARB(GLuint index, const GLshort* x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib2dvARB(GLuint index, const GLdouble* xy) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib2fvARB(GLuint index, const GLfloat* xy) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib2sARB(GLuint index, GLshort x, GLshort y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib2svARB(GLuint index, const GLshort* xy) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib3dvARB(GLuint index, const GLdouble* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib3fvARB(GLuint index, const GLfloat* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib3svARB(GLuint index, const GLshort* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4NbvARB(GLuint index, const GLbyte* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4NivARB(GLuint index, const GLint* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4NsvARB(GLuint index, const GLshort* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4NubvARB(GLuint index, const GLubyte* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4NuivARB(GLuint index, const GLuint* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4NusvARB(GLuint index, const GLushort* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4bvARB(GLuint index, const GLbyte* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4dvARB(GLuint index, const GLdouble* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4fvARB(GLuint index, const GLfloat* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4ivARB(GLuint index, const GLint* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4svARB(GLuint index, const GLshort* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4ubvARB(GLuint index, const GLubyte* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4uivARB(GLuint index, const GLuint* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4usvARB(GLuint index, const GLushort* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer) noexcept;

    // (ARB 27) GL_ARB_fragment_program

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbFragmentProgram() noexcept;

    // (ARB 28) GL_ARB_vertex_buffer_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbVertexBufferObject() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindBufferARB(GLenum target, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteBuffersARB(GLsizei numBuffers, const GLuint* buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenBuffersARB(GLsizei numBuffers, GLuint* buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsBufferARB(GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBufferDataARB(GLenum target, GLsizeiptrARB size, const GLvoid* data, GLenum usage) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE GLvoid* GlMapBufferARB(GLenum target, GLenum access) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlUnmapBufferARB(GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetBufferParameterivARB(GLenum target, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetBufferPointervARB(GLenum target, GLenum name, GLvoid** param) noexcept;

    // (ARB 29) GL_ARB_occlusion_query

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbOcclusionQuery() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGenQueriesARB(GLsizei numQueries, GLuint* id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteQueriesARB(GLsizei numQueries, const GLuint* id) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsQueryARB(GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBeginQueryARB(GLenum target, GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEndQueryARB(GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetQueryivARB(GLenum target, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetQueryObjectivARB(GLuint id, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetQueryObjectuivARB(GLuint id, GLenum name, GLuint* param) noexcept;

    // (ARB 30) GL_ARB_shader_objects

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShaderObjects() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlAttachObjectARB(GLhandleARB container, GLhandleARB object) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompileShaderARB(GLhandleARB shader) noexcept;
    SYSTEM_HIDDEN_DECLARE GLhandleARB GlCreateProgramObjectARB() noexcept;
    SYSTEM_HIDDEN_DECLARE GLhandleARB GlCreateShaderObjectARB(GLenum type) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteObjectARB(GLhandleARB object) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDetachObjectARB(GLhandleARB container, GLhandleARB object) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetActiveUniformARB(GLhandleARB program, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLcharARB* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetAttachedObjectsARB(GLhandleARB container, GLsizei maxCount, GLsizei* count, GLhandleARB* object) noexcept;
    SYSTEM_HIDDEN_DECLARE GLhandleARB GlGetHandleARB(GLenum name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetInfoLogARB(GLhandleARB object, GLsizei maxLength, GLsizei* length, GLcharARB* infoLog) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetObjectParameterfvARB(GLhandleARB object, GLenum name, GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetObjectParameterivARB(GLhandleARB object, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetShaderSourceARB(GLhandleARB object, GLsizei maxLength, GLsizei* length, GLcharARB* source) noexcept;
    SYSTEM_HIDDEN_DECLARE GLint GlGetUniformLocationARB(GLhandleARB program, const GLcharARB* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetUniformfvARB(GLhandleARB program, GLint location, GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetUniformivARB(GLhandleARB program, GLint location, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlLinkProgramARB(GLhandleARB program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlShaderSourceARB(GLhandleARB shader, GLsizei count, const GLcharARB** shaderString, const GLint* length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1fARB(GLint location, GLfloat v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2fARB(GLint location, GLfloat v0, GLfloat v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1iARB(GLint location, GLint v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2iARB(GLint location, GLint v0, GLint v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1fvARB(GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2fvARB(GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3fvARB(GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4fvARB(GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1ivARB(GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2ivARB(GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3ivARB(GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4ivARB(GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUseProgramObjectARB(GLhandleARB program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlValidateProgramARB(GLhandleARB program) noexcept;

    // (ARB 31) GL_ARB_vertex_shader

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbVertexShader() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindAttribLocationARB(GLhandleARB program, GLuint index, const GLcharARB* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetActiveAttribARB(GLhandleARB program, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLcharARB* name) noexcept;
    SYSTEM_HIDDEN_DECLARE GLint GlGetAttribLocationARB(GLhandleARB program, const GLcharARB* name) noexcept;

    // (ARB 32) GL_ARB_fragment_shader

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbFragmentShader() noexcept;

    // (ARB 33) GL_ARB_shading_language_100

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShadingLanguage100() noexcept;

    // (ARB 34) GL_ARB_texture_non_power_of_two

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureNonpowerOfTwo() noexcept;

    // (ARB 35) GL_ARB_point_sprite

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbPointSprite() noexcept;

    // (ARB 36) GL_ARB_fragment_program_shadow

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbFragmentProgramShadow() noexcept;

    // (ARB 37) GL_ARB_draw_buffers

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbDrawBuffers() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDrawBuffersARB(GLsizei numBuffers, const GLenum* buffer) noexcept;

    // (ARB 38) GL_ARB_texture_rectangle

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureRectangle() noexcept;

    // (ARB 39) GL_ARB_color_buffer_float

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbColorBufferFloat() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlClampColorARB(GLenum target, GLenum clamp) noexcept;

    // (ARB 40) GL_ARB_half_float_pixel

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbHalfFloatPixel() noexcept;

    // (ARB 41) GL_ARB_texture_float

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureFloat() noexcept;

    // (ARB 42) GL_ARB_pixel_buffer_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbPixelBufferObject() noexcept;

    // (ARB 43) GL_ARB_depth_buffer_float

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbDepthBufferFloat() noexcept;

    // (ARB 44) GL_ARB_draw_instanced

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbDrawInstanced() noexcept;

    // (ARB 45) GL_ARB_framebuffer_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbFramebufferObject() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindFramebuffer(GLenum target, GLuint framebuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindRenderbuffer(GLenum target, GLuint renderbuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept;
    SYSTEM_HIDDEN_DECLARE GLenum GlCheckFramebufferStatus(GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteFramebuffers(GLsizei n, const GLuint* framebuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint layer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenFramebuffers(GLsizei n, GLuint* framebuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenRenderbuffers(GLsizei n, GLuint* renderbuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenerateMipmap(GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetRenderbufferParameteriv(GLenum target, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsFramebuffer(GLuint framebuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsRenderbuffer(GLuint renderbuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) noexcept;

    // (ARB 46) GL_ARB_framebuffer_sRGB

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbFramebufferSRGB() noexcept;

    // (ARB 47) GL_ARB_geometry_shader4

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbGeometryShader4() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramParameteriARB(GLuint program, GLenum parameterName, GLint value) noexcept;

    // (ARB 48) GL_ARB_half_float_vertex

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbHalfFloatVertex() noexcept;

    // (ARB 49) GL_ARB_instanced_arrays

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbInstancedArrays() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribDivisorARB(GLuint index, GLuint divisor) noexcept;

    // (ARB 50) GL_ARB_map_buffer_range

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbMapBufferRange() noexcept;

    SYSTEM_HIDDEN_DECLARE GLvoid* GlMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) noexcept;

    // (ARB 51) GL_ARB_texture_buffer_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureBufferObject() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer) noexcept;

    // (ARB 52) GL_ARB_texture_compression_rgtc

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureCompressionRgtc() noexcept;

    // (ARB 53) GL_ARB_texture_rg

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureRg() noexcept;

    // (ARB 54) GL_ARB_vertex_array_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbVertexArrayObject() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindVertexArray(GLuint array) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteVertexArrays(GLsizei n, const GLuint* arrays) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenVertexArrays(GLsizei n, GLuint* arrays) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsVertexArray(GLuint array) noexcept;

    // (ARB 57) GL_ARB_uniform_buffer_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbUniformBufferObject() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) noexcept;

    // (ARB 58) GL_ARB_compatibility

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbCompatibility() noexcept;

    // (ARB 59) GL_ARB_copy_buffer

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbCopyBuffer() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlCopyBufferSubData(GLenum readtarget, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size) noexcept;

    // (ARB 60) GL_ARB_shader_texture_lod

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShaderTextureLod() noexcept;

    // (ARB 61) GL_ARB_depth_clamp

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbDepthClamp() noexcept;

    // (ARB 62) GL_ARB_draw_elements_base_vertex

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbDrawElementsBaseVertex() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount, GLint basevertex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei primcount, const GLint* basevertex) noexcept;

    // (ARB 63) GL_ARB_fragment_coord_conventions

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbFragmentCoordConventions() noexcept;

    // (ARB 64) GL_ARB_provoking_vertex

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbProvokingVertex() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlProvokingVertex(GLenum mode) noexcept;

    // (ARB 65) GL_ARB_seamless_cube_map

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbSeamlessCubeMap() noexcept;

    // (ARB 66) GL_ARB_sync

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbSync() noexcept;

    SYSTEM_HIDDEN_DECLARE GLenum GlClientWaitSync(GLsync glSync, GLbitfield flags, GLuint64 timeout) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteSync(GLsync glSync) noexcept;
    SYSTEM_HIDDEN_DECLARE GLsync GlFenceSync(GLenum condition, GLbitfield flags) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetInteger64v(GLenum parameterName, GLint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetSynciv(GLsync glSync, GLenum parameterName, GLsizei bufSize, GLsizei* length, GLint* values) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsSync(GLsync glSync) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWaitSync(GLsync glSync, GLbitfield flags, GLuint64 timeout) noexcept;

    // (ARB 67) GL_ARB_texture_multisample

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureMultisample() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetMultisamplefv(GLenum parameterName, GLuint index, GLfloat* val) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSampleMaski(GLuint index, GLbitfield mask) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width,
                                                       GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) noexcept;

    // (ARB 68) GL_ARB_vertex_array_bgra

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbVertexArrayBgra() noexcept;

    // (ARB 69) GL_ARB_draw_buffers_blend

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbDrawBuffersBlend() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBlendEquationiARB(GLuint buf, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBlendFunciARB(GLuint buf, GLenum src, GLenum dst) noexcept;

    // (ARB 70) GL_ARB_sample_shading

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbSampleShading() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlMinSampleShadingARB(GLclampf value) noexcept;

    // (ARB 71) GL_ARB_texture_cube_map_array

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureCubeMapArray() noexcept;

    // (ARB 72) GL_ARB_texture_gather

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureGather() noexcept;

    // (ARB 73) GL_ARB_texture_query_lod

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureQueryLod() noexcept;

    // (ARB 76) GL_ARB_shading_language_include

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShadingLanguageInclude() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlCompileShaderIncludeARB(GLuint shader, GLsizei count, const GLchar* const* path, const GLint* length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteNamedStringARB(GLint namelen, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedStringARB(GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* namedString) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedStringivARB(GLint namelen, const GLchar* name, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsNamedStringARB(GLint namelen, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedStringARB(GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* namedString) noexcept;

    // (ARB 77) GL_ARB_texture_compression_bptc

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureCompressionBptc() noexcept;

    // (ARB 78) GL_ARB_blend_func_extended

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbBlendFuncExtended() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE GLint GlGetFragDataIndex(GLuint program, const GLchar* name) noexcept;

    // (ARB 79) GL_ARB_explicit_attrib_location

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbExplicitAttribLocation() noexcept;

    // (ARB 80) GL_ARB_occlusion_query2

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbOcclusionQuery2() noexcept;

    // (ARB 81) GL_ARB_sampler_objects

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbSamplerObjects() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindSampler(GLuint unit, GLuint sampler) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteSamplers(GLsizei count, const GLuint* samplers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenSamplers(GLsizei count, GLuint* samplers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetSamplerParameterIiv(GLuint sampler, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetSamplerParameterIuiv(GLuint sampler, GLenum parameterName, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetSamplerParameterfv(GLuint sampler, GLenum parameterName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetSamplerParameteriv(GLuint sampler, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsSampler(GLuint sampler) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSamplerParameterIiv(GLuint sampler, GLenum parameterName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSamplerParameterIuiv(GLuint sampler, GLenum parameterName, const GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSamplerParameterf(GLuint sampler, GLenum parameterName, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSamplerParameterfv(GLuint sampler, GLenum parameterName, const GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSamplerParameteri(GLuint sampler, GLenum parameterName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSamplerParameteriv(GLuint sampler, GLenum parameterName, const GLint* params) noexcept;

    // (ARB 82) GL_ARB_shader_bit_encoding

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShaderBitEncoding() noexcept;

    // (ARB 83) GL_ARB_texture_rgb10_a2ui

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureRgb10A2ui() noexcept;

    // (ARB 84) GL_ARB_texture_swizzle

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureSwizzle() noexcept;

    // (ARB 85) GL_ARB_timer_query

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTimerQuery() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetQueryObjecti64v(GLuint id, GLenum parameterName, GLint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetQueryObjectui64v(GLuint id, GLenum parameterName, GLuint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlQueryCounter(GLuint id, GLenum target) noexcept;

    // (ARB 86) GL_ARB_vertex_type_2_10_10_10_rev

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbVertexType2_10_10_10Rev() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlColorP3ui(GLenum type, GLuint color) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlColorP3uiv(GLenum type, const GLuint* color) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlColorP4ui(GLenum type, GLuint color) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlColorP4uiv(GLenum type, const GLuint* color) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint* coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint* coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint* coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint* coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNormalP3ui(GLenum type, GLuint coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNormalP3uiv(GLenum type, const GLuint* coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColorP3ui(GLenum type, GLuint color) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColorP3uiv(GLenum type, const GLuint* color) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexCoordP1ui(GLenum type, GLuint coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexCoordP1uiv(GLenum type, const GLuint* coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexCoordP2ui(GLenum type, GLuint coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexCoordP2uiv(GLenum type, const GLuint* coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexCoordP3ui(GLenum type, GLuint coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexCoordP3uiv(GLenum type, const GLuint* coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexCoordP4ui(GLenum type, GLuint coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexCoordP4uiv(GLenum type, const GLuint* coords) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexP2ui(GLenum type, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexP2uiv(GLenum type, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexP3ui(GLenum type, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexP3uiv(GLenum type, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexP4ui(GLenum type, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexP4uiv(GLenum type, const GLuint* value) noexcept;

    // (ARB 87) GL_ARB_draw_indirect

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbDrawIndirect() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDrawArraysIndirect(GLenum mode, const void* indirect) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect) noexcept;

    // (ARB 88) GL_ARB_gpu_shader5

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbGpuShader5() noexcept;

    // (ARB 89) GL_ARB_gpu_shader_fp64

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbGpuShaderFp64() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetUniformdv(GLuint program, GLint location, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1d(GLint location, GLdouble x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1dv(GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2d(GLint location, GLdouble x, GLdouble y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2dv(GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3dv(GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4dv(GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;

    // (ARB 90) GL_ARB_shader_subroutine

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShaderSubroutin() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum parameterName, GLint* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetProgramStageiv(GLuint program, GLenum shadertype, GLenum parameterName, GLint* values) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE GLint GlGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices) noexcept;

    // (ARB 91) GL_ARB_tessellation_shader

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTessellationShader() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlPatchParameterfv(GLenum parameterName, const GLfloat* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlPatchParameteri(GLenum parameterName, GLint value) noexcept;

    // (ARB 92) GL_ARB_texture_buffer_object_rgb32

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureBufferObjectRgb32() noexcept;

    // (ARB 93) GL_ARB_transform_feedback2

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTransformFeedback2() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindTransformFeedback(GLenum target, GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteTransformFeedbacks(GLsizei n, const GLuint* ids) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDrawTransformFeedback(GLenum mode, GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenTransformFeedbacks(GLsizei n, GLuint* ids) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsTransformFeedback(GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlPauseTransformFeedback() noexcept;
    SYSTEM_HIDDEN_DECLARE void GlResumeTransformFeedback() noexcept;

    // (ARB 94) GL_ARB_transform_feedback3

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTransformFeedback3() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBeginQueryIndexed(GLenum target, GLuint index, GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEndQueryIndexed(GLenum target, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetQueryIndexediv(GLenum target, GLuint index, GLenum parameterName, GLint* params) noexcept;

    // (ARB 96) GL_ARB_get_program_binary

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbGetProgramBinary() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid* binary, GLsizei length) noexcept;

    // (ARB 97) GL_ARB_separate_shader_objects

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbSeparateShaderObjects() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlActiveShaderProgram(GLuint pipeline, GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindProgramPipeline(GLuint pipeline) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlCreateShaderProgramv(GLenum type, GLsizei count, const GLchar** strings) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteProgramPipelines(GLsizei n, const GLuint* pipelines) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenProgramPipelines(GLsizei n, GLuint* pipelines) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetProgramPipelineiv(GLuint pipeline, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsProgramPipeline(GLuint pipeline) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1d(GLuint program, GLint location, GLdouble x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1f(GLuint program, GLint location, GLfloat x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1i(GLuint program, GLint location, GLint x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1ui(GLuint program, GLint location, GLuint x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2d(GLuint program, GLint location, GLdouble x, GLdouble y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2f(GLuint program, GLint location, GLfloat x, GLfloat y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2i(GLuint program, GLint location, GLint x, GLint y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2ui(GLuint program, GLint location, GLuint x, GLuint y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3d(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3f(GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3i(GLuint program, GLint location, GLint x, GLint y, GLint z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3ui(GLuint program, GLint location, GLuint x, GLuint y, GLuint z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4d(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4f(GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4i(GLuint program, GLint location, GLint x, GLint y, GLint z, GLint w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4ui(GLuint program, GLint location, GLuint x, GLuint y, GLuint z, GLuint w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlValidateProgramPipeline(GLuint pipeline) noexcept;

    // (ARB 98) GL_ARB_shader_precision

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShaderPrecision() noexcept;

    // (ARB 99) GL_ARB_vertex_attrib_64bit

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbVertexAttrib64bit() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribLdv(GLuint index, GLenum parameterName, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL1d(GLuint index, GLdouble x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL1dv(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL2dv(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL3dv(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL4dv(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) noexcept;

    // (ARB 100) GL_ARB_viewport_array

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbViewportArray() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDepthRangeArrayv(GLuint first, GLsizei count, const GLclampd* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDepthRangeIndexed(GLuint index, GLclampd n, GLclampd f) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetDoublei_v(GLenum target, GLuint index, GLdouble* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetFloati_v(GLenum target, GLuint index, GLfloat* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlScissorArrayv(GLuint first, GLsizei count, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlScissorIndexedv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlViewportArrayv(GLuint first, GLsizei count, const GLfloat* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlViewportIndexedfv(GLuint index, const GLfloat* v) noexcept;

    // (ARB 103) GL_ARB_cl_event

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbClEvent() noexcept;

    SYSTEM_HIDDEN_DECLARE GLsync GlCreateSyncFromCLeventARB(cl_context context, cl_event event, GLbitfield flags) noexcept;

    // (ARB 104) GL_ARB_debug_output

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbDebugOutput() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDebugMessageCallbackARB(GlDebugProcARB callback, const GLvoid* userParam) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlGetDebugMessageLogARB(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types,
                                                         GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog) noexcept;

    // (ARB 105) GL_ARB_robustness

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbRobustness() noexcept;

    SYSTEM_HIDDEN_DECLARE GLenum GlGetGraphicsResetStatusARB(void) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, void* img) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* image) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnPolygonStippleARB(GLsizei bufSize, GLubyte* pattern) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void* row, GLsizei columnBufSize, GLvoid* column, GLvoid* span) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* img) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data) noexcept;

    // (ARB 106) GL_ARB_shader_stencil_export

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShaderStencilExport() noexcept;

    // (ARB 107) GL_ARB_base_instance

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbBaseInstance() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLuint baseinstance) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount, GLuint baseinstance) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices,
                                                                             GLsizei primcount, GLint basevertex, GLuint baseinstance) noexcept;

    // (ARB 108) GL_ARB_shading_language_420pack

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShadingLanguage420pack() noexcept;

    // (ARB 109) GL_ARB_transform_feedback_instanced

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTransformFeedbackInstanced() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei primcount) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei primcount) noexcept;

    // (ARB 110) GL_ARB_compressed_texture_pixel_storage

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbCompressedTexturePixelStorage() noexcept;

    // (ARB 111) GL_ARB_conservative_depth

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbConservativeDepth() noexcept;

    // (ARB 112) GL_ARB_internalformat_query

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbInternalformatQuery() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetInternalformativ(GLenum target, GLenum internalformat, GLenum parameterName, GLsizei bufSize, GLint* params) noexcept;

    // (ARB 113) GL_ARB_map_buffer_alignment

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbMapBufferAlignment() noexcept;

    // (ARB 114) GL_ARB_shader_atomic_counters

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShaderAtomicCounters() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum parameterName, GLint* params) noexcept;

    // (ARB 115) GL_ARB_shader_image_load_store

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShaderImageLoadStore() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMemoryBarrier(GLbitfield barriers) noexcept;

    // (ARB 116) GL_ARB_shading_language_packing

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShadingLanguagePacking() noexcept;

    // (ARB 117) GL_ARB_texture_storage

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureStorage() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) noexcept;

    // (ARB 120) GL_ARB_arrays_of_arrays

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbArraysOfArrays() noexcept;

    // (ARB 121) GL_ARB_clear_buffer_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbClearBufferObject() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data) noexcept;

    // (ARB 122) GL_ARB_compute_shader

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbComputeShader() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDispatchCompute(GLuint numGroupsX, GLuint numGroupsY, GLuint numGroupsZ) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDispatchComputeIndirect(GLintptr indirect) noexcept;

    // (ARB 123) GL_ARB_copy_image

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbCopyImage() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY,
                                                  GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX,
                                                  GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) noexcept;

    // (ARB 124) GL_ARB_texture_view

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureView() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) noexcept;

    // (ARB 125) GL_ARB_vertex_attrib_binding

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbVertexAttribBinding() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribBinding(GLuint attribindex, GLuint bindingindex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexBindingDivisor(GLuint bindingindex, GLuint divisor) noexcept;

    // (ARB 128) GL_ARB_explicit_uniform_location

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbExplicitUniformLocation() noexcept;

    // (ARB 129) GL_ARB_fragment_layer_viewport

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbFragmentLayerViewport() noexcept;

    // (ARB 130) GL_ARB_framebuffer_no_attachments

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbFramebufferNoAttachments() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlFramebufferParameteri(GLenum target, GLenum parameterName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetFramebufferParameteriv(GLenum target, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum parameterName, GLint param) noexcept;

    // (ARB 131) GL_ARB_internalformat_query2

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbInternalformatQuery2() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetInternalformati64v(GLenum target, GLenum internalformat, GLenum parameterName, GLsizei bufSize, GLint64* params) noexcept;

    // (ARB 132) GL_ARB_invalidate_subdata

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbInvalidateSubdata() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlInvalidateBufferData(GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlInvalidateTexImage(GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) noexcept;

    // (ARB 133) GL_ARB_multi_draw_indirect

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbMultiDrawIndirect() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlMultiDrawArraysIndirect(GLenum mode, const GLvoid* indirect, GLsizei primcount, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid* indirect, GLsizei primcount, GLsizei stride) noexcept;

    // (ARB 134) GL_ARB_program_interface_query

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbProgramInterfaceQuery() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE GLint GlGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE GLint GlGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount,
                                                      const GLenum* props, GLsizei bufSize, GLsizei* length, GLint* params) noexcept;

    // (ARB 135) GL_ARB_robust_buffer_access_behavior

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbRobustBufferAccessBehavior() noexcept;

    // (ARB 136) GL_ARB_shader_image_size

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShaderImageSize() noexcept;

    // (ARB 137) GL_ARB_shader_storage_buffer_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShaderStorageBufferObject() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) noexcept;

    // (ARB 138) GL_ARB_stencil_texturing

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbStencilTexturing() noexcept;

    // (ARB 139) GL_ARB_texture_buffer_range

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureBufferRange() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept;

    // (ARB 140) GL_ARB_texture_query_levels
    //SYSTEM_HIDDEN_DECLARE int g_ExistsGlArbTextureQueryLevels;

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureQueryLevels() noexcept;

    // (ARB 141) GL_ARB_texture_storage_multisample

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureStorageMultisample() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width,
                                                         GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureStorage2DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat,
                                                                GLsizei width, GLsizei height, GLboolean fixedsamplelocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureStorage3DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat,
                                                                GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) noexcept;

    // (ARB 144) GL_ARB_buffer_storage

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbBufferStorage() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBufferStorage(GLenum target, GLsizeiptr size, const GLvoid* data, GLbitfield flags) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedBufferStorageEXT(GLuint buffer, GLsizeiptr size, const GLvoid* data, GLbitfield flags) noexcept;

    // (ARB 145) GL_ARB_clear_texture

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbClearTexture() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
                                                  GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* data) noexcept;

    // (ARB 146) GL_ARB_enhanced_layouts

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbEnhancedLayouts() noexcept;

    // (ARB 147) GL_ARB_multi_bind

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbMultiBind() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindImageTextures(GLuint first, GLsizei count, const GLuint* textures) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindSamplers(GLuint first, GLsizei count, const GLuint* samplers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindTextures(GLuint first, GLsizei count, const GLuint* textures) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides) noexcept;

    // (ARB 148) GL_ARB_query_buffer_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbQueryBufferObject() noexcept;

    // (ARB 149) GL_ARB_texture_mirror_clamp_to_edge

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureMirrorClampToEdge() noexcept;

    // (ARB 150) GL_ARB_texture_stencil8

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureStencil8() noexcept;

    // (ARB 151) GL_ARB_vertex_type_10f_11f_11f_rev

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbVertexType10f11f11fRev() noexcept;

    // (ARB 152) GL_ARB_bindless_texture

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbBindlessTexture() noexcept;

    SYSTEM_HIDDEN_DECLARE GLuint64 GlGetImageHandleARB(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint64 GlGetTextureHandleARB(GLuint texture) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint64 GlGetTextureSamplerHandleARB(GLuint texture, GLuint sampler) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribLui64vARB(GLuint index, GLenum parameterName, GLuint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsImageHandleResidentARB(GLuint64 handle) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsTextureHandleResidentARB(GLuint64 handle) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMakeImageHandleNonResidentARB(GLuint64 handle) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMakeImageHandleResidentARB(GLuint64 handle, GLenum access) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMakeTextureHandleNonResidentARB(GLuint64 handle) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMakeTextureHandleResidentARB(GLuint64 handle) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformHandleui64ARB(GLuint program, GLint location, GLuint64 value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformHandleui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformHandleui64ARB(GLint location, GLuint64 value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformHandleui64vARB(GLint location, GLsizei count, const GLuint64* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL1ui64ARB(GLuint index, GLuint64 x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL1ui64vARB(GLuint index, const GLuint64* v) noexcept;

    // (ARB 153) GL_ARB_compute_variable_group_size

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbComputeCariableGroupSize() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDispatchComputeGroupSizeARB(GLuint numGroupsX, GLuint numGroupsY, GLuint numGroupsZ, GLuint groupSizeX, GLuint groupSizeY, GLuint groupSizeZ) noexcept;

    // (ARB 154) GL_ARB_indirect_parameters

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbIndirectParameters() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlMultiDrawArraysIndirectCountARB(GLenum mode, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiDrawElementsIndirectCountARB(GLenum mode, GLenum type, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) noexcept;

    // (ARB 155) GL_ARB_seamless_cubemap_per_texture

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbSeamlessCubemapPerTexture() noexcept;

    // (ARB 156) GL_ARB_shader_draw_parameters

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShaderDrawParameters() noexcept;

    // (ARB 157) GL_ARB_shader_group_vote

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShaderGroupVote() noexcept;

    // (ARB 158) GL_ARB_sparse_texture

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbSparseTexture() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlTexPageCommitmentARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
                                                      GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexturePageCommitmentEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset,
                                                          GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) noexcept;

    // (ARB 160) GL_ARB_clip_control

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbClipControl() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlClipControl(GLenum origin, GLenum depth) noexcept;

    // (ARB 161) GL_ARB_conditional_render_inverted

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbConditionalRenderInverted() noexcept;

    // (ARB 162) GL_ARB_cull_distance

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbCullDistance() noexcept;

    // (ARB 163) GL_ARB_derivative_control

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbDerivativeControl() noexcept;

    // (ARB 164) GL_ARB_direct_state_access

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbDirectStateAccess() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindTextureUnit(GLuint unit, GLuint texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1,
                                                      GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept;
    SYSTEM_HIDDEN_DECLARE GLenum GlCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLfloat depth, GLint stencil) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width,
                                                             GLsizei height, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
                                                             GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCreateBuffers(GLsizei n, GLuint* buffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCreateFramebuffers(GLsizei n, GLuint* framebuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCreateProgramPipelines(GLsizei n, GLuint* pipelines) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCreateQueries(GLenum target, GLsizei n, GLuint* ids) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCreateRenderbuffers(GLsizei n, GLuint* renderbuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCreateSamplers(GLsizei n, GLuint* samplers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCreateTextures(GLenum target, GLsizei n, GLuint* textures) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCreateTransformFeedbacks(GLsizei n, GLuint* ids) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCreateVertexArrays(GLsizei n, GLuint* arrays) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDisableVertexArrayAttrib(GLuint vaobj, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEnableVertexArrayAttrib(GLuint vaobj, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenerateTextureMipmap(GLuint texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedBufferParameteri64v(GLuint buffer, GLenum parameterName, GLint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedBufferParameteriv(GLuint buffer, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedBufferPointerv(GLuint buffer, GLenum parameterName, void** params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum parameterName, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum parameterName, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum parameterName, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum parameterName, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum parameterName, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum parameterName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureParameterIiv(GLuint texture, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureParameterIuiv(GLuint texture, GLenum parameterName, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureParameterfv(GLuint texture, GLenum parameterName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureParameteriv(GLuint texture, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTransformFeedbacki64_v(GLuint xfb, GLenum parameterName, GLuint index, GLint64* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTransformFeedbacki_v(GLuint xfb, GLenum parameterName, GLuint index, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTransformFeedbackiv(GLuint xfb, GLenum parameterName, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum parameterName, GLint64* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum parameterName, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexArrayiv(GLuint vaobj, GLenum parameterName, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMapNamedBuffer(GLuint buffer, GLenum access) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedBufferData(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferParameteri(GLuint framebuffer, GLenum parameterName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferReadBuffer(GLuint framebuffer, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureParameterIiv(GLuint texture, GLenum parameterName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureParameterIuiv(GLuint texture, GLenum parameterName, const GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureParameterf(GLuint texture, GLenum parameterName, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureParameterfv(GLuint texture, GLenum parameterName, const GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureParameteri(GLuint texture, GLenum parameterName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureParameteriv(GLuint texture, GLenum parameterName, const GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width,
                                                             GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width,
                                                   GLsizei height, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
                                                   GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlUnmapNamedBuffer(GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides) noexcept;

    // (ARB 165) GL_ARB_get_texture_sub_image

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbGetTextureSubImage() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
                                                              GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
                                                    GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept;

    // (ARB 166) GL_ARB_shader_texture_image_samples

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbShaderTextureImageSamples() noexcept;

    // (ARB 167) GL_ARB_texture_barrier

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTextureBarrier() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlTextureBarrier(void) noexcept;

    // (ARB 171) GL_ARB_pipeline_statistics_query

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbPipelineStatisticsQuery() noexcept;

    // (ARB 172) GL_ARB_sparse_buffer

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbSparseBuffer() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBufferPageCommitmentARB(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit) noexcept;

    // (ARB 173) GL_ARB_transform_feedback_overflow_query

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbTransformFeedbackOverflowQuery() noexcept;

    void InitGlArbMultitexture();
    void InitGlArbTransposeMatrix();
    void InitGlArbMultisample();
    void InitGlArbTextureEnvAdd();
    void InitGlArbTextureCubeMap();
    void InitGlArbTextureCompression();
    void InitGlArbTextureBorderClamp();
    void InitGlArbPointParameters();
    void InitGlArbVertexBlend();
    void InitGlArbMatrixPalette();
    void InitGlArbTextureEnvCombine();
    void InitGlArbTextureEnvCrossbar();
    void InitGlArbTextureEnvDot3();
    void InitGlArbTextureMirroredRepeat();
    void InitGlArbDepthTexture();
    void InitGlArbShadow();
    void InitGlArbShadowAmbient();
    void InitGlArbWindowPos();
    void InitGlArbVertexProgram();
    void InitGlArbFragmentProgram();
    void InitGlArbVertexBufferObject();
    void InitGlArbOcclusionQuery();
    void InitGlArbShaderObjects();
    void InitGlArbVertexShader();
    void InitGlArbFragmentShader();
    void InitGlArbShadingLanguage100();
    void InitGlArbTextureNonpowerOfTwo();
    void InitGlArbPointSprite();
    void InitGlArbFragmentProgramShadow();
    void InitGlArbDrawBuffers();
    void InitGlArbTextureRectangle();
    void InitGlArbColorBufferFloat();
    void InitGlArbHalfFloatPixel();
    void InitGlArbTextureFloat();
    void InitGlArbPixelBufferObject();
    void InitGlArbDepthBufferFloat();
    void InitGlArbDrawInstanced();
    void InitGlArbFramebufferObject();
    void InitGlArbFramebufferSRGB();
    void InitGlArbGeometryShader4();
    void InitGlArbHalfFloatVertex();
    void InitGlArbInstancedArrays();
    void InitGlArbMapBufferRange();
    void InitGlArbTextureBufferObject();
    void InitGlArbTextureCompressionRgtc();
    void InitGlArbTextureRg();
    void InitGlArbVertexArrayObject();
    void InitGlArbUniformBufferObject();
    void InitGlArbCompatibility();
    void InitGlArbCopyBuffer();
    void InitGlArbShaderTextureLod();
    void InitGlArbDepthClamp();
    void InitGlArbDrawElementsBaseVertex();
    void InitGlArbFragmentCoordConventions();
    void InitGlArbProvokingVertex();
    void InitGlArbSeamlessCubeMap();
    void InitGlArbSync();
    void InitGlArbTextureMultisample();
    void InitGlArbVertexArrayBgra();
    void InitGlArbDrawBuffersBlend();
    void InitGlArbSampleShading();
    void InitGlArbTextureCubeMapArray();
    void InitGlArbTextureGather();
    void InitGlArbTextureQueryLod();
    void InitGlArbShadingLanguageInclude();
    void InitGlArbTextureCompressionBptc();
    void InitGlArbBlendFuncExtended();
    void InitGlArbExplicitAttribLocation();
    void InitGlArbOcclusionQuery2();
    void InitGlArbSamplerObjects();
    void InitGlArbShaderBitEncoding();
    void InitGlArbTextureRgb10A2ui();
    void InitGlArbTextureSwizzle();
    void InitGlArbTimerQuery();
    void InitGlArbVertexType2_10_10_10Rev();
    void InitGlArbDrawIndirect();
    void InitGlArbGpuShader5();
    void InitGlArbGpuShaderFp64();
    void InitGlArbShaderSubroutin();
    void InitGlArbTessellationShader();
    void InitGlArbTextureBufferObjectRgb32();
    void InitGlArbTransformFeedback2();
    void InitGlArbTransformFeedback3();
    void InitGlArbGetProgramBinary();
    void InitGlArbSeparateShaderObjects();
    void InitGlArbShaderPrecision();
    void InitGlArbVertexAttrib64bit();
    void InitGlArbViewportArray();
    void InitGlArbClEvent();
    void InitGlArbDebugOutput();
    void InitGlArbRobustness();
    void InitGlArbShaderStencilExport();
    void InitGlArbBaseInstance();
    void InitGlArbShadingLanguage420pack();
    void InitGlArbTransformFeedbackInstanced();
    void InitGlArbCompressedTexturePixelStorage();
    void InitGlArbConservativeDepth();
    void InitGlArbInternalformatQuery();
    void InitGlArbMapBufferAlignment();
    void InitGlArbShaderAtomicCounters();
    void InitGlArbShaderImageLoadStore();
    void InitGlArbShadingLanguagePacking();
    void InitGlArbTextureStorage();
    void InitGlArbArraysOfArrays();
    void InitGlArbClearBufferObject();
    void InitGlArbComputeShader();
    void InitGlArbCopyImage();
    void InitGlArbTextureView();
    void InitGlArbVertexAttribBinding();
    void InitGlArbExplicitUniformLocation();
    void InitGlArbFragmentLayerViewport();
    void InitGlArbFramebufferNoAttachments();
    void InitGlArbInternalformatQuery2();
    void InitGlArbInvalidateSubdata();
    void InitGlArbMultiDrawIndirect();
    void InitGlArbProgramInterfaceQuery();
    void InitGlArbRobustBufferAccessBehavior();
    void InitGlArbShaderImageSize();
    void InitGlArbShaderStorageBufferObject();
    void InitGlArbStencilTexturing();
    void InitGlArbTextureBufferRange();
    void InitGlArbTextureQueryLevels();
    void InitGlArbTextureStorageMultisample();
    void InitGlArbBufferStorage();
    void InitGlArbClearTexture();
    void InitGlArbEnhancedLayouts();
    void InitGlArbMultiBind();
    void InitGlArbQueryBufferObject();
    void InitGlArbTextureMirrorClampToEdge();
    void InitGlArbTextureStencil8();
    void InitGlArbVertexType10f11f11fRev();
    void InitGlArbBindlessTexture();
    void InitGlArbComputeCariableGroupSize();
    void InitGlArbIndirectParameters();
    void InitGlArbSeamlessCubemapPerTexture();
    void InitGlArbShaderDrawParameters();
    void InitGlArbShaderGroupVote();
    void InitGlArbSparseTexture();
    void InitGlArbClipControl();
    void InitGlArbConditionalRenderInverted();
    void InitGlArbCullDistance();
    void InitGlArbDerivativeControl();
    void InitGlArbDirectStateAccess();
    void InitGlArbGetTextureSubImage();
    void InitGlArbShaderTextureImageSamples();
    void InitGlArbTextureBarrier();
    void InitGlArbPipelineStatisticsQuery();
    void InitGlArbSparseBuffer();
    void InitGlArbTransformFeedbackOverflowQuery();

    void InitGlArb();
}

#endif  // SYSTEM_OPENGL_GL_ARB_EXTENSIONS_H
