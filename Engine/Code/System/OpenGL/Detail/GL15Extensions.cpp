// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:40)

#include "System/SystemExport.h"

#include "GL15Extensions.h"
#include "GLUtility.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/Using/GL15ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"

// OpenGL 1.5

namespace System
{
	ExistsOpenGLExtensions g_ExistsOpenGL15{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsOpenGL15() noexcept
{
	return g_ExistsOpenGL15;
}

System::PgglGenQueries System::gglGenQueries{ nullptr };
System::PgglDeleteQueries System::gglDeleteQueries{ nullptr };
System::PgglIsQuery System::gglIsQuery{ nullptr };
System::PgglBeginQuery System::gglBeginQuery{ nullptr };
System::PgglEndQuery System::gglEndQuery{ nullptr };
System::PgglGetQueryiv System::gglGetQueryiv{ nullptr };
System::PgglGetQueryObjectiv System::gglGetQueryObjectiv{ nullptr };
System::PgglGetQueryObjectuiv System::gglGetQueryObjectuiv{ nullptr };
System::PgglBindBuffer System::gglBindBuffer{ nullptr };
System::PgglDeleteBuffers System::gglDeleteBuffers{ nullptr };
System::PgglGenBuffers System::gglGenBuffers{ nullptr };
System::PgglIsBuffer System::gglIsBuffer{ nullptr };
System::PgglBufferData System::gglBufferData{ nullptr };
System::PgglBufferSubData System::gglBufferSubData{ nullptr };
System::PgglGetBufferSubData System::gglGetBufferSubData{ nullptr };
System::PgglMapBuffer System::gglMapBuffer{ nullptr };
System::PgglUnmapBuffer System::gglUnmapBuffer{ nullptr };
System::PgglGetBufferParameteriv System::gglGetBufferParameteriv{ nullptr };
System::PgglGetBufferPointerv System::gglGetBufferPointerv{ nullptr };

void System
	::GlGenQueries(GLsizei numQueries, GLuint* id) noexcept
{
	SYSTEM_BODY_A2(gglGenQueries, numQueries, id);
}

void System
	::GlDeleteQueries(GLsizei numQueries, const GLuint* id) noexcept
{
	SYSTEM_BODY_A2(gglDeleteQueries, numQueries, id);
}

GLboolean System
	::GlIsQuery(GLuint id) noexcept
{
	SYSTEM_BODY_A1_RESULT(gglIsQuery, id, GLboolean, GL_FALSE);
}

void System
	::GlBeginQuery(GLenum target, GLuint id) noexcept
{
	SYSTEM_BODY_A2(gglBeginQuery, target, id);
}

void System
	::GlEndQuery(GLenum target) noexcept
{
	SYSTEM_BODY_A1(gglEndQuery, target);
}

void System
	::GlGetQueryiv(GLenum target, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_A3(gglGetQueryiv, target, name, param);
}

void System
	::GlGetQueryObjectiv(GLuint id, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_A3(gglGetQueryObjectiv, id, name, param);
}

void System
	::GlGetQueryObjectuiv(GLuint id, GLenum name, GLuint* param) noexcept
{
	SYSTEM_BODY_A3(gglGetQueryObjectuiv, id, name, param);
}

void System
	::GlBindBuffer(GLenum target, GLuint buffer) noexcept
{
	SYSTEM_BODY_A2(gglBindBuffer, target, buffer);
}

void System
	::GlDeleteBuffers(GLsizei numBuffers, const GLuint* buffer) noexcept
{
	SYSTEM_BODY_A2(gglDeleteBuffers, numBuffers, buffer);
}

void System
	::GlGenBuffers(GLsizei numBuffers, GLuint* buffer) noexcept
{
	SYSTEM_BODY_A2(gglGenBuffers, numBuffers, buffer);
}

GLboolean System
	::GlIsBuffer(GLuint buffer) noexcept
{
	SYSTEM_BODY_A1_RESULT(gglIsBuffer, buffer, GLboolean, GL_FALSE);
}

void System
	::GlBufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage) noexcept
{
	SYSTEM_BODY_A4(gglBufferData, target, size, data, usage);
}

void System
	::GlBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data) noexcept
{
	SYSTEM_BODY_A4(gglBufferSubData, target, offset, size, data);
}

void System
	::GlGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data) noexcept
{
	SYSTEM_BODY_A4(gglGetBufferSubData, target, offset, size, data);
}

GLvoid* System
	::GlMapBuffer(GLenum target, GLenum access) noexcept
{
	SYSTEM_BODY_A2_RESULT(gglMapBuffer, target, access, GLvoid*, nullptr);
}

GLboolean System
	::GlUnmapBuffer(GLenum target) noexcept
{
	SYSTEM_BODY_A1_RESULT(gglUnmapBuffer, target, GLboolean, GL_FALSE);
}

void System
	::GlGetBufferParameteriv(GLenum target, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_A3(gglGetBufferParameteriv, target, name, param);
}

void System
	::GlGetBufferPointerv(GLenum target, GLenum name, GLvoid** param) noexcept
{
	SYSTEM_BODY_A3(gglGetBufferPointerv, target, name, param);
}

void System
	::InitOpenGL15() noexcept
{
	if (System::OpenGLSystemVersion::Version15 <= System::GetOpenGLVersion())
	{
		g_ExistsOpenGL15 = ExistsOpenGLExtensions::Exists;

		// GL_ARB_occlusion_query

		SYSTEM_GET_FUNCTION(gglGenQueries);
		SYSTEM_GET_FUNCTION(gglDeleteQueries);
		SYSTEM_GET_FUNCTION(gglIsQuery);
		SYSTEM_GET_FUNCTION(gglBeginQuery);
		SYSTEM_GET_FUNCTION(gglEndQuery);
		SYSTEM_GET_FUNCTION(gglGetQueryiv);
		SYSTEM_GET_FUNCTION(gglGetQueryObjectiv);
		SYSTEM_GET_FUNCTION(gglGetQueryObjectuiv);

		// GL_ARB_vertex_buffer_object

		SYSTEM_GET_FUNCTION(gglBindBuffer);
		SYSTEM_GET_FUNCTION(gglDeleteBuffers);
		SYSTEM_GET_FUNCTION(gglGenBuffers);
		SYSTEM_GET_FUNCTION(gglIsBuffer);
		SYSTEM_GET_FUNCTION(gglBufferData);
		SYSTEM_GET_FUNCTION(gglBufferSubData);
		SYSTEM_GET_FUNCTION(gglGetBufferSubData);
		SYSTEM_GET_FUNCTION(gglMapBuffer);
		SYSTEM_GET_FUNCTION(gglUnmapBuffer);
		SYSTEM_GET_FUNCTION(gglGetBufferParameteriv);
		SYSTEM_GET_FUNCTION(gglGetBufferPointerv);
	}
	else
	{
		g_ExistsOpenGL15 = ExistsOpenGLExtensions::NotExist;
	}
}