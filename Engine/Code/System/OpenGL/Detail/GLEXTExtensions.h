//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:40)

#ifndef SYSTEM_OPENGL_GL_EXT_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_EXT_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL15ExtensionsUsing.h"
#include "System/OpenGL/Using/GL20ExtensionsUsing.h"
#include "System/OpenGL/Using/GL32ExtensionsUsing.h"
#include "System/OpenGL/Using/GLARBExtensionsUsing.h"

namespace System
{
    // EXT 扩展

    // (EXT 001) GL_EXT_abgr

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtABGR() noexcept;

    // (EXT 002) GL_EXT_blend_color

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtBlendColor() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBlendColorEXT(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) noexcept;

    // (EXT 003) GL_EXT_polygon_offset

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtPolygonOffset() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlPolygonOffsetEXT(GLfloat scale, GLfloat bias) noexcept;

    // (EXT 004) GL_EXT_texture

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTexture() noexcept;

    // (EXT 006) GL_EXT_texture3D

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTexture3D() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlTexImage3DEXT(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height,
                                               GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexSubImage3DEXT(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width,
                                                  GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* data) noexcept;

    // (EXT 009) GL_EXT_subtexture

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtSubtexture() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlTexSubImage1DEXT(GLenum target, GLint level, GLint xOffset, GLsizei width, GLenum format, GLenum type, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexSubImage2DEXT(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLsizei width,
                                                  GLsizei height, GLenum format, GLenum type, const GLvoid* data) noexcept;

    // (EXT 010) GL_EXT_copy_texture

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtCopyTexture() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlCopyTexImage1DEXT(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyTexImage2DEXT(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyTexSubImage1DEXT(GLenum target, GLint level, GLint xOffset, GLint x, GLint y, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyTexSubImage2DEXT(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;

    // (EXT 011) GL_EXT_histogram

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtHistogram() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetHistogramParameterfvEXT(GLenum target, GLenum name, GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetHistogramParameterivEXT(GLenum target, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMinmaxParameterfvEXT(GLenum target, GLenum name, GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMinmaxParameterivEXT(GLenum target, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlHistogramEXT(GLenum target, GLsizei width, GLenum internalFormat, GLboolean sink) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMinmaxEXT(GLenum target, GLenum internalFormat, GLboolean sink) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlResetHistogramEXT(GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlResetMinmaxEXT(GLenum target) noexcept;

    // (EXT 012) GL_EXT_convolution

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtConvolution() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlConvolutionFilter1DEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid* image) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlConvolutionFilter2DEXT(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* image) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlConvolutionParameterfEXT(GLenum target, GLenum name, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlConvolutionParameterfvEXT(GLenum target, GLenum name, const GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlConvolutionParameteriEXT(GLenum target, GLenum name, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlConvolutionParameterivEXT(GLenum target, GLenum name, const GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyConvolutionFilter1DEXT(GLenum target, GLenum internalFormat, GLint x, GLint y, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyConvolutionFilter2DEXT(GLenum target, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid* image) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetConvolutionParameterfvEXT(GLenum target, GLenum name, GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetConvolutionParameterivEXT(GLenum target, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid* row, GLvoid* column, GLvoid* span) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSeparableFilter2DEXT(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height,
                                                      GLenum format, GLenum type, const GLvoid* row, const GLvoid* column) noexcept;

    // (EXT 018) GL_EXT_cmyka

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtCMYKA() noexcept;

    // (EXT 020) GL_EXT_texture_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureObject() noexcept;

    SYSTEM_HIDDEN_DECLARE GLboolean GlAreTexturesResidentEXT(GLsizei numTextures, const GLuint* textures, GLboolean* residences) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindTextureEXT(GLenum target, GLuint texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteTexturesEXT(GLsizei numTextures, const GLuint* textures) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenTexturesEXT(GLsizei numTextures, GLuint* texture) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsTextureEXT(GLuint texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlPrioritizeTexturesEXT(GLsizei numTextures, const GLuint* textures, const GLclampf* priorities) noexcept;

    // (EXT 023) GL_EXT_packed_pixels

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtPackedPixels() noexcept;

    // (EXT 027) GL_EXT_rescale_normal

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtRescaleNormal() noexcept;

    // (EXT 030) GL_EXT_vertex_array

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtVertexArray() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlArrayElementEXT(GLint i) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDrawArraysEXT(GLenum mode, GLint first, GLsizei count) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEdgeFlagPointerEXT(GLsizei stride, GLsizei count, const GLboolean* pointer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetPointervEXT(GLenum name, GLvoid** param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer) noexcept;

    // (EXT 031) GL_EXT_misc_attribute

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtMiscAttribute() noexcept;

    // (EXT 035) GL_EXT_texture_edge_clamp

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureEdgeClamp() noexcept;

    // (EXT 037) GL_EXT_blend_minmax

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtBlendMinMax() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBlendEquationEXT(GLenum mode) noexcept;

    // (EXT 038) GL_EXT_blend_subtract

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtBlendSubtract() noexcept;

    // (EXT 039) GL_EXT_blend_logic_op

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtBlendLogicOp() noexcept;

    // (EXT 054) GL_EXT_point_parameters

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtPointParameters() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlPointParameterfEXT(GLenum name, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlPointParameterfvEXT(GLenum name, const GLfloat* param) noexcept;

    // (EXT 074) GL_EXT_color_subtable

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtColorSubtable() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) noexcept;

    // (EXT 078) GL_EXT_paletted_texture

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtPalettedTexture() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid* table) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetColorTableEXT(GLenum target, GLenum format, GLenum type, GLvoid* table) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetColorTableParameterfvEXT(GLenum target, GLenum name, GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetColorTableParameterivEXT(GLenum target, GLenum name, GLint* param) noexcept;

    // (EXT 079) GL_EXT_clip_volume_hint

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtClipVolumeHint() noexcept;

    // (EXT 093) GL_EXT_index_texture

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtIndexTexture() noexcept;

    // (EXT 094) GL_EXT_index_material

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtIndexMaterial() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlIndexMaterialEXT(GLenum face, GLenum mode) noexcept;

    // (EXT 095) GL_EXT_index_func

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtIndexFunc() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlIndexFuncEXT(GLenum eFunction, GLclampf fReference) noexcept;

    // (EXT 096) GL_EXT_index_array_formats

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtIndexArrayFormats() noexcept;

    // (EXT 097) GL_EXT_compiled_vertex_array

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtCompiledVertexArray() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlLockArraysEXT(GLint first, GLsizei count) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUnlockArraysEXT() noexcept;

    // (EXT 098) GL_EXT_cull_vertex

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtCullVertex() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlCullParameterdvEXT(GLenum name, GLdouble* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCullParameterfvEXT(GLenum name, GLfloat* param) noexcept;

    // (EXT 102) GL_EXT_fragment_lighting

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtFragmentLighting() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlFragmentColorMaterialEXT(GLenum face, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFragmentLightModelfEXT(GLenum parameterName, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFragmentLightModelfvEXT(GLenum parameterName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFragmentLightModeliEXT(GLenum parameterName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFragmentLightModelivEXT(GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFragmentLightfEXT(GLenum light, GLenum parameterName, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFragmentLightfvEXT(GLenum light, GLenum parameterName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFragmentLightiEXT(GLenum light, GLenum parameterName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFragmentLightivEXT(GLenum light, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFragmentMaterialfEXT(GLenum face, GLenum parameterName, const GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFragmentMaterialfvEXT(GLenum face, GLenum parameterName, const GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFragmentMaterialiEXT(GLenum face, GLenum parameterName, const GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFragmentMaterialivEXT(GLenum face, GLenum parameterName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetFragmentLightfvEXT(GLenum light, GLenum parameterName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetFragmentLightivEXT(GLenum light, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetFragmentMaterialfvEXT(GLenum face, GLenum parameterName, const GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetFragmentMaterialivEXT(GLenum face, GLenum parameterName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlLightEnviEXT(GLenum parameterName, GLint param) noexcept;

    // (EXT 112) GL_EXT_draw_range_elements

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtDrawRangeElements() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices) noexcept;

    // (EXT 117) GL_EXT_light_texture

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtLightTexture() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlApplyTextureEXT(GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureLightEXT(GLenum name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureMaterialEXT(GLenum face, GLenum mode) noexcept;

    // (EXT 120) GL_EXT_scene_marker

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtSceneMarker() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBeginSceneEXT(void) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEndSceneEXT(void) noexcept;

    // (EXT 129) GL_EXT_bgra

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtBGRA() noexcept;

    // (EXT 138) GL_EXT_pixel_transform

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtPixelTransform() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlPixelTransformParameteriEXT(GLenum target, GLenum name, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlPixelTransformParameterfEXT(GLenum target, GLenum name, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlPixelTransformParameterivEXT(GLenum target, GLenum name, const GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlPixelTransformParameterfvEXT(GLenum target, GLenum name, const GLfloat* param) noexcept;

    // (EXT 139) GL_EXT_pixel_transform_color_table

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtPixelTransformColorTable() noexcept;

    // (EXT 141) GL_EXT_shared_texture_palette

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtSharedTexturePalette() noexcept;

    // (EXT 144) GL_EXT_separate_specular_color

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtSeparateSpecularColor() noexcept;

    // (EXT 145) GL_EXT_secondary_color

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtSecondaryColor() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3bEXT(GLbyte r, GLbyte g, GLbyte b) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3bvEXT(const GLbyte* rgb) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3dEXT(GLdouble r, GLdouble g, GLdouble b) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3dvEXT(const GLdouble* rgb) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3fEXT(GLfloat r, GLfloat g, GLfloat b) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3fvEXT(const GLfloat* rgb) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3iEXT(GLint r, GLint g, GLint b) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3ivEXT(const GLint* rgb) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3sEXT(GLshort r, GLshort g, GLshort b) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3svEXT(const GLshort* rgb) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3ubEXT(GLubyte ucR, GLubyte g, GLubyte b) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3ubvEXT(const GLubyte* rgb) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3uiEXT(GLuint uiR, GLuint g, GLuint b) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3uivEXT(const GLuint* rgb) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3usEXT(GLushort usR, GLushort g, GLushort b) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3usvEXT(const GLushort* rgb) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept;

    // (EXT 146) GL_EXT_texture_env

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureEnv() noexcept;

    // (EXT 147) GL_EXT_texture_perturb_normal

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTexturePerturbNormal() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlTextureNormalEXT(GLenum mode) noexcept;

    // (EXT 148) GL_EXT_multi_draw_arrays

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtMultidrawArrays() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlMultiDrawArraysEXT(GLenum mode, GLint* first, GLsizei* count, GLsizei primitiveCount) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiDrawElementsEXT(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei primitiveCount) noexcept;

    // (EXT 149) GL_EXT_fog_coord

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtFogCoord() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlFogCoorddEXT(GLdouble coord) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFogCoorddvEXT(const GLdouble* coord) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFogCoordfEXT(GLfloat coord) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFogCoordfvEXT(const GLfloat* coord) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFogCoordPointerEXT(GLenum type, GLsizei stride, const GLvoid* pointer) noexcept;

    // (EXT 156) GL_EXT_coordinate_frame

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtCoordinateFrame() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlTangent3bEXT(GLbyte x, GLbyte y, GLbyte z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTangent3bvEXT(const GLbyte* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTangent3dEXT(GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTangent3dvEXT(const GLdouble* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTangent3fEXT(GLfloat x, GLfloat y, GLfloat z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTangent3fvEXT(const GLfloat* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTangent3iEXT(GLint x, GLint y, GLint z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTangent3ivEXT(const GLint* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTangent3sEXT(GLshort x, GLshort y, GLshort z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTangent3svEXT(const GLshort* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBinormal3bEXT(GLbyte x, GLbyte y, GLbyte z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBinormal3bvEXT(const GLbyte* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBinormal3dEXT(GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBinormal3dvEXT(const GLdouble* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBinormal3fEXT(GLfloat x, GLfloat y, GLfloat z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBinormal3fvEXT(const GLfloat* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBinormal3iEXT(GLint x, GLint y, GLint z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBinormal3ivEXT(const GLint* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBinormal3sEXT(GLshort x, GLshort y, GLshort z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBinormal3svEXT(const GLshort* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTangentPointerEXT(GLenum type, GLsizei stride, const GLvoid* pointer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBinormalPointerEXT(GLenum type, GLsizei stride, const GLvoid* pointer) noexcept;

    // (EXT 158) GL_EXT_texture_env_combine

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureEnvCombine() noexcept;

    // (EXT 173) GL_EXT_blend_func_separate

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtBlendFuncSeparate() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBlendFuncSeparateEXT(GLenum srcFactorRGB, GLenum dstFactorRGB, GLenum srcFactorA, GLenum dstFactorA) noexcept;

    // (EXT 176) GL_EXT_stencil_wrap

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtStencilWrap() noexcept;

    // (EXT 178) GL_EXT_422_pixels

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExt422Pixels() noexcept;

    // (EXT 179) GL_EXT_texture_cube_map

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureCubeMap() noexcept;

    // (EXT 185) GL_EXT_texture_env_add

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureEnvAdd() noexcept;

    // (EXT 186) GL_EXT_texture_lod_bias

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureLodBias() noexcept;

    // (EXT 187) GL_EXT_texture_filter_anisotropic

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureFilterAnisotropic() noexcept;

    // (EXT 188) GL_EXT_vertex_weighting

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtVertexWeighting() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlVertexWeightfEXT(GLfloat weight) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexWeightfvEXT(const GLfloat* weight) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexWeightPointerEXT(GLsizei size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept;

    // (EXT 198) GL_EXT_texture_compression_s3tc

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureCompressionS3TC() noexcept;

    // (EXT 209) GL_EXT_multisample

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtMultisample() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlSampleMaskEXT(GLclampf value, GLboolean invert) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSamplePatternEXT(GLenum pattern) noexcept;

    // (EXT 220) GL_EXT_texture_env_dot3

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureEnvDot3() noexcept;

    // (EXT 229) GL_EXT_texture_rectangle

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureRectangle() noexcept;

    // (EXT 248) GL_EXT_vertex_shader

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtVertexShader() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBeginVertexShaderEXT(void) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlBindLightParameterEXT(GLenum light, GLenum value) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlBindMaterialParameterEXT(GLenum face, GLenum value) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlBindParameterEXT(GLenum value) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlBindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlBindTextureUnitParameterEXT(GLenum unit, GLenum value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindVertexShaderEXT(GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteVertexShaderEXT(GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDisableVariantClientStateEXT(GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEnableVariantClientStateEXT(GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEndVertexShaderEXT() noexcept;
    SYSTEM_HIDDEN_DECLARE void GlExtractComponentEXT(GLuint res, GLuint src, GLuint num) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlGenSymbolsEXT(GLenum dataType, GLenum storageType, GLenum range, GLuint components) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlGenVertexShadersEXT(GLuint range) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetInvariantIntegervEXT(GLuint id, GLenum value, GLint* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVariantFloatvEXT(GLuint id, GLenum value, GLfloat* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVariantIntegervEXT(GLuint id, GLenum value, GLint* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVariantPointervEXT(GLuint id, GLenum value, void** data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlInsertComponentEXT(GLuint res, GLuint src, GLuint num) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsVariantEnabledEXT(GLuint id, GLenum cap) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSetInvariantEXT(GLuint id, GLenum type, void* addr) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSetLocalConstantEXT(GLuint id, GLenum type, void* addr) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlShaderOp1EXT(GLenum op, GLuint res, GLuint arg1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlSwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVariantPointerEXT(GLuint id, GLenum type, GLuint stride, void* addr) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVariantbvEXT(GLuint id, GLbyte* addr) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVariantdvEXT(GLuint id, GLdouble* addr) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVariantfvEXT(GLuint id, GLfloat* addr) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVariantivEXT(GLuint id, GLint* addr) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVariantsvEXT(GLuint id, GLshort* addr) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVariantubvEXT(GLuint id, GLubyte* addr) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVariantuivEXT(GLuint id, GLuint* addr) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVariantusvEXT(GLuint id, GLushort* addr) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlWriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) noexcept;

    // (EXT 267) GL_EXT_shadow_funcs

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtShadowFuncs() noexcept;

    // (EXT 268) GL_EXT_stencil_two_side

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtStencilTwoSide() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlActiveStencilFaceEXT(GLenum face) noexcept;

    // (EXT 297) GL_EXT_depth_bounds_test

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtDepthBoundsTest() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDepthBoundsEXT(GLclampd min, GLclampd max) noexcept;

    // (EXT 298) GL_EXT_texture_mirror_clamp

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureMirrorClamp() noexcept;

    // (EXT 299) GL_EXT_blend_equation_separate

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtBlendEquationSeparate() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha) noexcept;

    // (EXT 302) GL_EXT_pixel_buffer_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtPixelBufferObject() noexcept;

    // (EXT 309) GL_EXT_texture_compression_dxt1

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureCompressionDXT1() noexcept;

    // (EXT 310) GL_EXT_framebuffer_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtFrameBufferObject() noexcept;

    SYSTEM_HIDDEN_DECLARE GLboolean GlIsRenderbufferEXT(GLuint renderBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindRenderbufferEXT(GLenum target, GLuint renderBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteRenderbuffersEXT(GLsizei numBuffers, const GLuint* renderBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenRenderbuffersEXT(GLsizei numBuffers, GLuint* renderBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlRenderbufferStorageEXT(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetRenderbufferParameterivEXT(GLenum target, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsFramebufferEXT(GLuint frameBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindFramebufferEXT(GLenum target, GLuint frameBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteFramebuffersEXT(GLsizei numBuffers, const GLuint* frameBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenFramebuffersEXT(GLsizei numBuffers, GLuint* frameBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE GLenum GlCheckFramebufferStatusEXT(GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textureTarget, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textureTarget, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textureTarget, GLuint texture, GLint level, GLint zOffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderBufferTarget, GLuint renderBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenerateMipmapEXT(GLenum target) noexcept;

    // (EXT 312) GL_EXT_packed_depth_stencil

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtPackedDepthStencil() noexcept;

    // (EXT 314) GL_EXT_stencil_clear_tag

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtStencilClearTag() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlStencilClearTagEXT(GLsizei stencilTagBits, GLuint stencilClearTag) noexcept;

    // (EXT 315) GL_EXT_texture_sRGB

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureSRGB() noexcept;

    // (EXT 316) GL_EXT_framebuffer_blit

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtFrameBufferBlit() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0,
                                                    GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept;

    // (EXT 317) GL_EXT_framebuffer_multisample

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtFrameBufferMultisample() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height) noexcept;

    // (EXT 319) GL_EXT_timer_query

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTimerQuery() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetQueryObjecti64vEXT(GLuint id, GLenum parameterName, GLint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetQueryObjectui64vEXT(GLuint id, GLenum parameterName, GLuint64* params) noexcept;

    // (EXT 320) GL_EXT_gpu_program_parameters

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtGpuProgramParameters() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat* params) noexcept;

    // (EXT 324) GL_EXT_geometry_shader4

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtGeometryShader4() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramParameteriEXT(GLuint program, GLenum parameterName, GLint value) noexcept;

    // (EXT 326) GL_EXT_gpu_shader4

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtGpuShader4() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindFragDataLocationEXT(GLuint program, GLuint color, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE GLint GlGetFragDataLocationEXT(GLuint program, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetUniformuivEXT(GLuint program, GLint location, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribIivEXT(GLuint index, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribIuivEXT(GLuint index, GLenum parameterName, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1uiEXT(GLint location, GLuint v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1uivEXT(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2uiEXT(GLint location, GLuint v0, GLuint v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2uivEXT(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3uivEXT(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4uivEXT(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI1iEXT(GLuint index, GLint x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI1ivEXT(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI1uiEXT(GLuint index, GLuint x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI1uivEXT(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI2iEXT(GLuint index, GLint x, GLint y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI2ivEXT(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI2uivEXT(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI3ivEXT(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI3uivEXT(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4bvEXT(GLuint index, const GLbyte* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4ivEXT(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4svEXT(GLuint index, const GLshort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4ubvEXT(GLuint index, const GLubyte* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4uivEXT(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4usvEXT(GLuint index, const GLushort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) noexcept;

    // (EXT 327) GL_EXT_draw_instanced

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtDrawInstanced() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount) noexcept;

    // (EXT 328) GL_EXT_packed_float

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtPackedFloat() noexcept;

    // (EXT 329) GL_EXT_texture_array

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureArray() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept;

    // (EXT 330) GL_EXT_texture_buffer_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureBufferObject() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer) noexcept;

    // (EXT 331) GL_EXT_texture_compression_latc

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureCompressionLatc() noexcept;

    // (EXT 332) GL_EXT_texture_compression_rgtc

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureCompressionRgtc() noexcept;

    // (EXT 333) GL_EXT_texture_shared_exponent

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureSharedExponent() noexcept;

    // (EXT 337) GL_EXT_framebuffer_sRGB

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtFramebufferSRGB() noexcept;

    // (EXT 340) GL_EXT_draw_buffers2

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtDrawBuffers2() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlColorMaskIndexedEXT(GLuint buf, GLboolean r, GLboolean g, GLboolean b, GLboolean a) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDisableIndexedEXT(GLenum target, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEnableIndexedEXT(GLenum target, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetBooleanIndexedvEXT(GLenum value, GLuint index, GLboolean* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetIntegerIndexedvEXT(GLenum value, GLuint index, GLint* data) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsEnabledIndexedEXT(GLenum target, GLuint index) noexcept;

    // (EXT 342) GL_EXT_bindable_uniform

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtBindableUniform() noexcept;

    SYSTEM_HIDDEN_DECLARE GLint GlGetUniformBufferSizeEXT(GLuint program, GLint location) noexcept;
    SYSTEM_HIDDEN_DECLARE GLintptr GlGetUniformOffsetEXT(GLuint program, GLint location) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformBufferEXT(GLuint program, GLint location, GLuint buffer) noexcept;

    // (EXT 343) GL_EXT_texture_integer

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureInteger() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTexParameterIivEXT(GLenum target, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTexParameterIuivEXT(GLenum target, GLenum parameterName, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexParameterIivEXT(GLenum target, GLenum parameterName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexParameterIuivEXT(GLenum target, GLenum parameterName, const GLuint* params) noexcept;

    // (EXT 352) GL_EXT_transform_feedback

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTransformFeedback() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBeginTransformFeedbackEXT(GLenum primitiveMode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEndTransformFeedbackEXT(void) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTransformFeedbackVaryingsEXT(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode) noexcept;

    // (EXT 353) GL_EXT_direct_state_access

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtDirectStateAccess() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture) noexcept;
    SYSTEM_HIDDEN_DECLARE GLenum GlCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClientAttribDefaultEXT(GLbitfield mask) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat,
                                                              GLsizei width, GLint border, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width,
                                                              GLsizei height, GLint border, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width,
                                                              GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset,
                                                                 GLsizei width, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset,
                                                                 GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
                                                                 GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat,
                                                             GLsizei width, GLint border, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width,
                                                             GLsizei height, GLint border, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width,
                                                             GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset,
                                                                GLsizei width, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset,
                                                                GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
                                                                GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x,
                                                       GLint y, GLsizei width, GLsizei height, GLint border) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset,
                                                          GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDisableClientStateIndexedEXT(GLenum array, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDisableClientStateiEXT(GLenum array, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDisableVertexArrayEXT(GLuint vaobj, GLenum array) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEnableClientStateIndexedEXT(GLenum array, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEnableClientStateiEXT(GLenum array, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEnableVertexArrayEXT(GLuint vaobj, GLenum array) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, const GLenum* bufs) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGenerateTextureMipmapEXT(GLuint texture, GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, void* img) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint level, void* img) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetDoublei_vEXT(GLenum parameterName, GLuint index, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetFloati_vEXT(GLenum parameterName, GLuint index, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetFramebufferParameterivEXT(GLuint framebuffer, GLenum parameterName, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum parameterName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum parameterName, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum parameterName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum parameterName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum parameterName, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum parameterName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedBufferParameterivEXT(GLuint buffer, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedBufferPointervEXT(GLuint buffer, GLenum parameterName, void** params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum parameterName, void* programString) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedProgramivEXT(GLuint program, GLenum target, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetPointerIndexedvEXT(GLenum target, GLuint index, void** params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetPointeri_vEXT(GLenum parameterName, GLuint index, void** params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum parameterName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum parameterName, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum parameterName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum parameterName, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexArrayIntegervEXT(GLuint vaobj, GLenum parameterName, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum parameterName, void** param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexArrayPointervEXT(GLuint vaobj, GLenum parameterName, void** param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMapNamedBufferEXT(GLuint buffer, GLenum access) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixFrustumEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixLoadIdentityEXT(GLenum matrixMode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixLoadTransposedEXT(GLenum matrixMode, const GLdouble* m) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixLoadTransposefEXT(GLenum matrixMode, const GLfloat* m) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixLoaddEXT(GLenum matrixMode, const GLdouble* m) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixLoadfEXT(GLenum matrixMode, const GLfloat* m) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixMultTransposedEXT(GLenum matrixMode, const GLdouble* m) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixMultTransposefEXT(GLenum matrixMode, const GLfloat* m) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixMultdEXT(GLenum matrixMode, const GLdouble* m) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixMultfEXT(GLenum matrixMode, const GLfloat* m) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixOrthoEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixPopEXT(GLenum matrixMode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixPushEXT(GLenum matrixMode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixRotatedEXT(GLenum matrixMode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixRotatefEXT(GLenum matrixMode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixScaledEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixScalefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixTranslatedEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMatrixTranslatefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void* pointer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum parameterName, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum parameterName, const GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum parameterName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum parameterName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum parameterName, GLdouble param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum parameterName, const GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum parameterName, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum parameterName, const GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum parameterName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum parameterName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width,
                                                    GLint border, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width,
                                                    GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height,
                                                    GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum parameterName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum parameterName, const GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum parameterName, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum parameterName, const GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum parameterName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum parameterName, const GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset,
                                                       GLsizei width, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset,
                                                       GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
                                                       GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, const GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, const GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, const GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const void* programString) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples,
                                                                                GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1iEXT(GLuint program, GLint location, GLint v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlPushClientAttribDefaultEXT(GLbitfield mask) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width,
                                                   GLint border, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width,
                                                   GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height,
                                                   GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureParameterIivEXT(GLuint texture, GLenum target, GLenum parameterName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum parameterName, const GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureParameterfEXT(GLuint texture, GLenum target, GLenum parameterName, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureParameterfvEXT(GLuint texture, GLenum target, GLenum parameterName, const GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureParameteriEXT(GLuint texture, GLenum target, GLenum parameterName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureParameterivEXT(GLuint texture, GLenum target, GLenum parameterName, const GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset,
                                                      GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
                                                      GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlUnmapNamedBufferEXT(GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArraySecondaryColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayVertexAttribDivisorEXT(GLuint vaobj, GLuint index, GLuint divisor) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayVertexAttribIOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayVertexAttribOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size,
                                                                  GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept;

    // (EXT 354) GL_EXT_vertex_array_bgra

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtVertexArrayBgra() noexcept;

    // (EXT 356) GL_EXT_texture_swizzle

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureSwizzle() noexcept;

    // (EXT 364) GL_EXT_provoking_vertex

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtProvokingVertex() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlProvokingVertexEXT(GLenum mode) noexcept;

    // (EXT 365) GL_EXT_texture_snorm

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureSnorm() noexcept;

    // (EXT 377) GL_EXT_separate_shader_objects

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtSeparateShaderObjects() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlActiveProgramEXT(GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlCreateShaderProgramEXT(GLenum type, const GLchar* programString) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUseShaderProgramEXT(GLenum type, GLuint program) noexcept;

    // (EXT 386) GL_EXT_shader_image_load_store

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtShaderImageLoadStore() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlMemoryBarrierEXT(GLbitfield barriers) noexcept;

    // (EXT 387) GL_EXT_vertex_attrib_64bit

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtVertexAttrib64bit() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribLdvEXT(GLuint index, GLenum parameterName, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL1dEXT(GLuint index, GLdouble x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL1dvEXT(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL2dEXT(GLuint index, GLdouble x, GLdouble y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL2dvEXT(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL3dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL3dvEXT(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL4dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribL4dvEXT(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) noexcept;

    // (EXT 402) GL_EXT_texture_sRGB_decode

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureSRGBDecode() noexcept;

    // (EXT 406) GL_EXT_x11_sync_object

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtX11SynObject() noexcept;

    SYSTEM_HIDDEN_DECLARE GLsync GlImportSyncEXT(GLenum externalSyncType, GLintptr externalSync, GLbitfield flags) noexcept;

    // (EXT 409) GL_EXT_framebuffer_multisample_blit_scaled

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtFramebufferMultisampleBlitScaled() noexcept;

    // (EXT 437) GL_EXT_shader_integer_mix

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtShaderIntegerMix() noexcept;

    // (EXT 439) GL_EXT_debug_label

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtDebugLabel() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei* length, GLchar* label) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlLabelObjectEXT(GLenum type, GLuint object, GLsizei length, const GLchar* label) noexcept;

    // (EXT 440) GL_EXT_debug_marker

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtDebugMarker() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlInsertEventMarkerEXT(GLsizei length, const GLchar* marker) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlPopGroupMarkerEXT() noexcept;
    SYSTEM_HIDDEN_DECLARE void GlPushGroupMarkerEXT(GLsizei length, const GLchar* marker) noexcept;

    // (EXT 449) GL_EXT_shader_image_load_formatted

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtShaderImageLoadFormatted() noexcept;

    // (EXT 460) GL_EXT_polygon_offset_clamp

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtPolygonOffsetClamp() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp) noexcept;

    // (EXT 461) GL_EXT_post_depth_coverage

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtPostDepthCoverage() noexcept;

    // (EXT 462) GL_EXT_raster_multisample

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtRasterMultisample() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlCoverageModulationNV(GLenum components) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCoverageModulationTableNV(GLsizei n, const GLfloat* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetCoverageModulationTableNV(GLsizei bufsize, GLfloat* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations) noexcept;

    // (EXT 463) GL_EXT_sparse_texture2

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtSparseTexture2() noexcept;

    // (EXT 464) GL_EXT_texture_filter_minmax

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtTextureFilterMinmax() noexcept;

    // GL_EXT_Cg_shader

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlExtCgShader() noexcept;

    void InitGlExtABGR();
    void InitGlExtBlendColor();
    void InitGlExtPolygonOffset();
    void InitGlExtTexture();
    void InitGlExtTexture3D();
    void InitGlExtSubtexture();
    void InitGlExtCopyTexture();
    void InitGlExtHistogram();
    void InitGlExtConvolution();
    void InitGlExtCMYKA();
    void InitGlExtTextureObject();
    void InitGlExtPackedPixels();
    void InitGlExtRescaleNormal();
    void InitGlExtVertexArray();
    void InitGlExtMiscAttribute();
    void InitGlExtTextureEdgeClamp();
    void InitGlExtBlendMinMax();
    void InitGlExtBlendSubtract();
    void InitGlExtBlendLogicOp();
    void InitGlExtPointParameters();
    void InitGlExtColorSubtable();
    void InitGlExtPalettedTexture();
    void InitGlExtClipVolumeHint();
    void InitGlExtIndexTexture();
    void InitGlExtIndexMaterial();
    void InitGlExtIndexFunc();
    void InitGlExtIndexArrayFormats();
    void InitGlExtCompiledVertexArray();
    void InitGlExtCullVertex();
    void InitGlExtFragmentLighting();
    void InitGlExtDrawRangeElements();
    void InitGlExtLightTexture();
    void InitGlExtSceneMarker();
    void InitGlExtBGRA();
    void InitGlExtPixelTransform();
    void InitGlExtPixelTransformColorTable();
    void InitGlExtSharedTexturePalette();
    void InitGlExtSeparateSpecularColor();
    void InitGlExtSecondaryColor();
    void InitGlExtTextureEnv();
    void InitGlExtTexturePerturbNormal();
    void InitGlExtMultidrawArrays();
    void InitGlExtFogCoord();
    void InitGlExtCoordinateFrame();
    void InitGlExtTextureEnvCombine();
    void InitGlExtBlendFuncSeparate();
    void InitGlExtStencilWrap();
    void InitGlExt422Pixels();
    void InitGlExtTextureCubeMap();
    void InitGlExtTextureEnvAdd();
    void InitGlExtTextureLodBias();
    void InitGlExtTextureFilterAnisotropic();
    void InitGlExtVertexWeighting();
    void InitGlExtTextureCompressionS3TC();
    void InitGlExtMultisample();
    void InitGlExtTextureEnvDot3();
    void InitGlExtTextureRectangle();
    void InitGlExtVertexShader();
    void InitGlExtShadowFuncs();
    void InitGlExtStencilTwoSide();
    void InitGlExtDepthBoundsTest();
    void InitGlExtTextureMirrorClamp();
    void InitGlExtBlendEquationSeparate();
    void InitGlExtPixelBufferObject();
    void InitGlExtTextureCompressionDXT1();
    void InitGlExtFrameBufferObject();
    void InitGlExtPackedDepthStencil();
    void InitGlExtStencilClearTag();
    void InitGlExtTextureSRGB();
    void InitGlExtFrameBufferBlit();
    void InitGlExtFrameBufferMultisample();
    void InitGlExtTimerQuery();
    void InitGlExtGpuProgramParameters();
    void InitGlExtGeometryShader4();
    void InitGlExtGpuShader4();
    void InitGlExtDrawInstanced();
    void InitGlExtPackedFloat();
    void InitGlExtTextureArray();
    void InitGlExtTextureBufferObject();
    void InitGlExtTextureCompressionLatc();
    void InitGlExtTextureCompressionRgtc();
    void InitGlExtTextureSharedExponent();
    void InitGlExtFramebufferSRGB();
    void InitGlExtDrawBuffers2();
    void InitGlExtBindableUniform();
    void InitGlExtTextureInteger();
    void InitGlExtTransformFeedback();
    void InitGlExtDirectStateAccess();
    void InitGlExtVertexArrayBgra();
    void InitGlExtTextureSwizzle();
    void InitGlExtProvokingVertex();
    void InitGlExtTextureSnorm();
    void InitGlExtSeparateShaderObjects();
    void InitGlExtShaderImageLoadStore();
    void InitGlExtVertexAttrib64bit();
    void InitGlExtTextureSRGBDecode();
    void InitGlExtX11SynObject();
    void InitGlExtFramebufferMultisampleBlitScaled();
    void InitGlExtShaderIntegerMix();
    void InitGlExtDebugLabel();
    void InitGlExtDebugMarker();
    void InitGlExtShaderImageLoadFormatted();
    void InitGlExtPolygonOffsetClamp();
    void InitGlExtPostDepthCoverage();
    void InitGlExtRasterMultisample();
    void InitGlExtSparseTexture2();
    void InitGlExtFilterMinmax();
    void InitGlExtCgShader();

    void InitGlExt();
}

#endif  // SYSTEM_OPENGL_GL_EXT_EXTENSIONS_H
