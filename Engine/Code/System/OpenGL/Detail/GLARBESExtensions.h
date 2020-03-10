// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:34)

#ifndef SYSTEM_OPENGL_GL_ARB_ES_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_ARB_ES_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/OpenGL/Using/GL11ExtensionsUsing.h" 
#include "System/Helper/Detail/OpenGL/GLARBESExtensionsMacro.h"

namespace System
{
	// GL_ARB_ES2_compatibility

	enum class ExistsOpenGLExtensions;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbEs2Compatibility() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlClearDepthf(GLclampf d) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlDepthRangef(GLclampf n, GLclampf f) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlReleaseShaderCompiler() noexcept;
	SYSTEM_HIDDEN_DECLARE void GlShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryformat, const void* binary, GLsizei length) noexcept;

	// GL_ARB_ES3_1_compatibility

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbEs31Compatibility() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlMemoryBarrierByRegion(GLbitfield barriers) noexcept;

	// GL_ARB_ES3_compatibility

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbEs3Compatibility() noexcept;

	void InitGlArbEs2Compatibility() noexcept;
	void InitGlArbEs31Compatibility() noexcept;
	void InitGlArbEs3Compatibility() noexcept;

	void InitGlArbEs() noexcept;
}

#endif // SYSTEM_OPENGL_GL_ARB_ES_EXTENSIONS_H
