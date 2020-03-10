// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:48)

#include "System/SystemExport.h"

#include "GL11Test.h"  
#include "System/Helper/UnusedMacro.h"
#include "System/OpenGL/Detail/GL11Extensions.h"

using std::any_cast;

namespace System
{
	bool SYSTEM_HIDDEN_DECLARE GL11TestParameter0(GL11Flags gl11) noexcept;
	bool SYSTEM_HIDDEN_DECLARE GL11TestParameter1(GL11Flags gl11, const Parameter& parameter);
	bool SYSTEM_HIDDEN_DECLARE GL11TestParameter2(GL11Flags gl11, const Parameter& parameter);
	bool SYSTEM_HIDDEN_DECLARE GL11TestParameter3(GL11Flags gl11, const Parameter& parameter);
	bool SYSTEM_HIDDEN_DECLARE GL11TestParameter4(GL11Flags gl11, const Parameter& parameter);
	bool SYSTEM_HIDDEN_DECLARE GL11TestParameter5(GL11Flags gl11, const Parameter& parameter);
	bool SYSTEM_HIDDEN_DECLARE GL11TestParameter6(GL11Flags gl11, const Parameter& parameter);
	bool SYSTEM_HIDDEN_DECLARE GL11TestParameter7(GL11Flags gl11, const Parameter& parameter);
	bool SYSTEM_HIDDEN_DECLARE GL11TestParameter8(GL11Flags gl11, const Parameter& parameter);
	bool SYSTEM_HIDDEN_DECLARE GL11TestParameter9(GL11Flags gl11, const Parameter& parameter);
	bool SYSTEM_HIDDEN_DECLARE GL11TestParameter10(GL11Flags gl11, const Parameter& parameter);

	GLboolean SYSTEM_HIDDEN_DECLARE GL11TestParameter1ReturnBoolean(GL11Flags gl11, const Parameter& parameter);
	GLboolean SYSTEM_HIDDEN_DECLARE GL11TestParameter3ReturnBoolean(GL11Flags gl11, const Parameter& parameter);

	const GLubyte* SYSTEM_HIDDEN_DECLARE GL11TestParameter1ReturnConstGLubytePtr(GL11Flags gl11, const Parameter& parameter);

	GLint SYSTEM_HIDDEN_DECLARE GL11TestParameter1ReturnGLint(GL11Flags gl11, const Parameter& parameter);
}

bool System
	::GL11Test(GL11Flags gl11, const Parameter& parameter)
{
	switch (parameter.size())
	{
	case 0:
		return GL11TestParameter0(gl11);
	case 1:
		return GL11TestParameter1(gl11, parameter);
	case 2:
		return GL11TestParameter2(gl11, parameter);
	case 3:
		return GL11TestParameter3(gl11, parameter);
	case 4:
		return GL11TestParameter4(gl11, parameter);
	case 5:
		return GL11TestParameter5(gl11, parameter);
	case 6:
		return GL11TestParameter6(gl11, parameter);
	case 7:
		return GL11TestParameter7(gl11, parameter);
	case 8:
		return GL11TestParameter8(gl11, parameter);	
	case 9:
		return GL11TestParameter9(gl11, parameter);
	case 10:
		return GL11TestParameter10(gl11, parameter);
	default:
		break;
	}

	return false;
}

GLboolean System
	::GL11TestReturnBoolean(GL11Flags gl11, const Parameter& parameter)
{
	switch (parameter.size())
	{
	case 1:
		return GL11TestParameter1ReturnBoolean(gl11, parameter);
	case 3:
		return GL11TestParameter3ReturnBoolean(gl11, parameter); 
	default:
		break;
	}

	return GL_FALSE;
}

const GLubyte* System
	::GL11TestReturnConstGLubytePtr(GL11Flags gl11, const Parameter& parameter)
{
	switch (parameter.size())
	{
	case 1:
		return GL11TestParameter1ReturnConstGLubytePtr(gl11, parameter);
	default:
		break;
	}

	return nullptr;
}

GLint System
	::GL11TestReturnGLint(GL11Flags gl11, const Parameter& parameter)
{
	switch (parameter.size())
	{
	case 1:
		return GL11TestParameter1ReturnGLint(gl11, parameter);
	default:
		break;
	}

	return 0;
}

bool System
	::GL11TestParameter0(GL11Flags gl11) noexcept
{
	switch (gl11)
	{
	case GL11Flags::End:
	{
		GLEnd();

		return true;
	}
	case GL11Flags::EndList:
	{
		GLEndList();

		return true;
	}
	case GL11Flags::Finish:
	{
		GLFinish();

		return true;
	}
	case GL11Flags::Flush:
	{
		GLFlush();

		return true;
	}
	case GL11Flags::GetError:
	{
		GLGetError();

		return true;
	}
	case GL11Flags::InitNames:
	{
		GLInitNames();

		return true;
	}
	case GL11Flags::LoadIdentity:
	{
		GLLoadIdentity();

		return true;
	}
	case GL11Flags::PopAttrib:
	{
		GLPopAttrib();

		return true;
	}
	case GL11Flags::PopClientAttrib:
	{
		GLPopClientAttrib();

		return true;
	}
	case GL11Flags::PopMatrix:
	{
		GLPopMatrix();

		return true;
	}
	case GL11Flags::PopName:
	{
		GLPopName();

		return true;
	}
	case GL11Flags::PushMatrix:
	{
		GLPushMatrix();

		return true;
	}
	default:
		return false;
	}	
} 
 
bool System
	::GL11TestParameter1(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::ArrayElement:
	{
		GLArrayElement(any_cast<GLint>(parameter[0]));

		return true;
	}
	case GL11Flags::Begin:
	{
		GLBegin(any_cast<GLenum>(parameter[0]));

		return true;
	}
	case GL11Flags::CallList:
	{
		GLCallList(any_cast<GLuint>(parameter[0]));

		return true;
	}
	case GL11Flags::Clear:
	{
		GLClear(any_cast<GLbitfield>(parameter[0]));

		return true;
	}
	case GL11Flags::ClearDepth:
	{
		GLClearDepth(any_cast<GLclampd>(parameter[0]));

		return true;
	}
	case GL11Flags::ClearIndex:
	{
		GLClearIndex(any_cast<GLfloat>(parameter[0]));

		return true;
	}
	case GL11Flags::ClearStencil:
	{
		GLClearStencil(any_cast<GLint>(parameter[0]));

		return true;
	}
	case GL11Flags::Color3bv:
	{
		GLColor3bv(any_cast<const GLbyte*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color3dv:
	{
		GLColor3dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color3fv:
	{
		GLColor3fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color3iv:
	{
		GLColor3iv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color3sv:
	{
		GLColor3sv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color3ubv:
	{
		GLColor3ubv(any_cast<const GLubyte*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color3uiv:
	{
		GLColor3uiv(any_cast<const GLuint*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color3usv:
	{
		GLColor3usv(any_cast<const GLushort*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color4bv:
	{
		GLColor4bv(any_cast<const GLbyte*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color4dv:
	{
		GLColor4dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color4fv:
	{
		GLColor4fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color4iv:
	{
		GLColor4iv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color4sv:
	{
		GLColor4sv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color4ubv:
	{
		GLColor4ubv(any_cast<const GLubyte*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color4uiv:
	{
		GLColor4uiv(any_cast<const GLuint*>(parameter[0]));

		return true;
	}
	case GL11Flags::Color4usv:
	{
		GLColor4usv(any_cast<const GLushort*>(parameter[0]));

		return true;
	}
	case GL11Flags::CullFace:
	{
		GLCullFace(any_cast<GLenum>(parameter[0]));

		return true;
	}
	case GL11Flags::DepthFunc:
	{
		GLDepthFunc(any_cast<GLenum>(parameter[0]));

		return true;
	}
	case GL11Flags::DepthMask:
	{
		GLDepthMask(any_cast<GLboolean>(parameter[0]));

		return true;
	}
	case GL11Flags::Disable:
	{
		GLDisable(any_cast<GLenum>(parameter[0]));

		return true;
	}
	case GL11Flags::DisableClientState:
	{
		GLDisableClientState(any_cast<GLenum>(parameter[0]));

		return true;
	}
	case GL11Flags::DrawBuffer:
	{
		GLDrawBuffer(any_cast<GLenum>(parameter[0]));

		return true;
	}
	case GL11Flags::EdgeFlag:
	{
		GLEdgeFlag(any_cast<GLboolean>(parameter[0]));

		return true;
	}
	case GL11Flags::EdgeFlagv:
	{
		GLEdgeFlagv(any_cast<const GLboolean*>(parameter[0]));

		return true;
	}
	case GL11Flags::Enable:
	{
		GLEnable(any_cast<GLenum>(parameter[0]));

		return true;
	}
	case GL11Flags::EnableClientState:
	{
		GLEnableClientState(any_cast<GLenum>(parameter[0]));

		return true;
	}
	case GL11Flags::EvalCoord1d:
	{
		GLEvalCoord1d(any_cast<GLdouble>(parameter[0]));

		return true;
	}
	case GL11Flags::EvalCoord1dv:
	{
		GLEvalCoord1dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::EvalCoord1f:
	{
		GLEvalCoord1f(any_cast<GLfloat>(parameter[0]));

		return true;
	}
	case GL11Flags::EvalCoord1fv:
	{
		GLEvalCoord1fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::EvalCoord2dv:
	{
		GLEvalCoord2dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::EvalCoord2fv:
	{
		GLEvalCoord2fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::EvalPoint1:
	{
		GLEvalPoint1(any_cast<GLint>(parameter[0]));

		return true;
	}
	case GL11Flags::FrontFace:
	{
		GLFrontFace(any_cast<GLenum>(parameter[0]));

		return true;
	}
	case GL11Flags::GenLists:
	{
		GLGenLists(any_cast<GLsizei>(parameter[0]));

		return true;
	}
	case GL11Flags::GetPolygonStipple:
	{
		GLGetPolygonStipple(any_cast<GLubyte*>(parameter[0]));

		return true;
	}
	case GL11Flags::IndexMask:
	{
		GLIndexMask(any_cast<GLuint>(parameter[0]));

		return true;
	}
	case GL11Flags::Indexd:
	{
		GLIndexd(any_cast<GLdouble>(parameter[0]));

		return true;
	}
	case GL11Flags::Indexdv:
	{
		GLIndexdv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::Indexf:
	{
		GLIndexf(any_cast<GLfloat>(parameter[0]));

		return true;
	}
	case GL11Flags::Indexfv:
	{
		GLIndexfv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::Indexi:
	{
		GLIndexi(any_cast<GLint>(parameter[0]));

		return true;
	}
	case GL11Flags::Indexiv:
	{
		GLIndexiv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::Indexs:
	{
		GLIndexs(any_cast<GLshort>(parameter[0]));

		return true;
	}
	case GL11Flags::Indexsv:
	{
		GLIndexsv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	case GL11Flags::Indexub:
	{
		GLIndexub(any_cast<GLubyte>(parameter[0]));

		return true;
	}
	case GL11Flags::Indexubv:
	{
		GLIndexubv(any_cast<const GLubyte*>(parameter[0]));

		return true;
	}
	case GL11Flags::LineWidth:
	{
		GLLineWidth(any_cast<GLfloat>(parameter[0]));

		return true;
	}
	case GL11Flags::ListBase:
	{
		GLListBase(any_cast<GLuint>(parameter[0]));

		return true;
	}
	case GL11Flags::LoadMatrixd:
	{
		GLLoadMatrixd(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::LoadMatrixf:
	{
		GLLoadMatrixf(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::LoadName:
	{
		GLLoadName(any_cast<GLuint>(parameter[0]));

		return true;
	}
	case GL11Flags::LogicOp:
	{
		GLLogicOp(any_cast<GLenum>(parameter[0]));

		return true;
	}
	case GL11Flags::MatrixMode:
	{
		GLMatrixMode(any_cast<GLenum>(parameter[0]));

		return true;
	}
	case GL11Flags::MultMatrixd:
	{
		GLMultMatrixd(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::MultMatrixf:
	{
		GLMultMatrixf(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::Normal3bv:
	{
		GLNormal3bv(any_cast<const GLbyte*>(parameter[0]));

		return true;
	}
	case GL11Flags::Normal3dv:
	{
		GLNormal3dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::Normal3fv:
	{
		GLNormal3fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::Normal3iv:
	{
		GLNormal3iv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::Normal3sv:
	{
		GLNormal3sv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	case GL11Flags::PassThrough:
	{
		GLPassThrough(any_cast<GLfloat>(parameter[0]));

		return true;
	}
	case GL11Flags::PointSize:
	{
		GLPointSize(any_cast<GLfloat>(parameter[0]));

		return true;
	}
	case GL11Flags::PolygonStipple:
	{
		GLPolygonStipple(any_cast<const GLubyte*>(parameter[0]));

		return true;
	}
	case GL11Flags::PushAttrib:
	{
		GLPushAttrib(any_cast<GLbitfield>(parameter[0]));

		return true;
	}
	case GL11Flags::PushClientAttrib:
	{
		GLPushClientAttrib(any_cast<GLbitfield>(parameter[0]));

		return true;
	}
	case GL11Flags::PushName:
	{
		GLPushName(any_cast<GLuint>(parameter[0]));

		return true;
	}
	case GL11Flags::RasterPos2dv:
	{
		GLRasterPos2dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::RasterPos2fv:
	{
		GLRasterPos2fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::RasterPos2iv:
	{
		GLRasterPos2iv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::RasterPos2sv:
	{
		GLRasterPos2sv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	case GL11Flags::RasterPos3dv:
	{
		GLRasterPos3dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::RasterPos3fv:
	{
		GLRasterPos3fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::RasterPos3iv:
	{
		GLRasterPos3iv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::RasterPos3sv:
	{
		GLRasterPos3sv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	case GL11Flags::RasterPos4dv:
	{
		GLRasterPos4dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::RasterPos4fv:
	{
		GLRasterPos4fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::RasterPos4iv:
	{
		GLRasterPos4iv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::RasterPos4sv:
	{
		GLRasterPos4sv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	case GL11Flags::ReadBuffer:
	{
		GLReadBuffer(any_cast<GLenum>(parameter[0]));

		return true;
	}
	case GL11Flags::ShadeModel:
	{
		GLShadeModel(any_cast<GLenum>(parameter[0]));

		return true;
	}
	case GL11Flags::StencilMask:
	{
		GLStencilMask(any_cast<GLuint>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord1d:
	{
		GLTexCoord1d(any_cast<GLdouble>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord1dv:
	{
		GLTexCoord1dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord1f:
	{
		GLTexCoord1f(any_cast<GLfloat>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord1fv:
	{
		GLTexCoord1fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord1i:
	{
		GLTexCoord1i(any_cast<GLint>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord1iv:
	{
		GLTexCoord1iv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord1s:
	{
		GLTexCoord1s(any_cast<GLshort>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord1sv:
	{
		GLTexCoord1sv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord2dv:
	{
		GLTexCoord2dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord2fv:
	{
		GLTexCoord2fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord2iv:
	{
		GLTexCoord2iv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord2sv:
	{
		GLTexCoord2sv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord3dv:
	{
		GLTexCoord3dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord3fv:
	{
		GLTexCoord3fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord3iv:
	{
		GLTexCoord3iv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord3sv:
	{
		GLTexCoord3sv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord4dv:
	{
		GLTexCoord4dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord4fv:
	{
		GLTexCoord4fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord4iv:
	{
		GLTexCoord4iv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::TexCoord4sv:
	{
		GLTexCoord4sv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	case GL11Flags::Vertex2dv:
	{
		GLVertex2dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::Vertex2fv:
	{
		GLVertex2fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::Vertex2iv:
	{
		GLVertex2iv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::Vertex2sv:
	{
		GLVertex2sv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	case GL11Flags::Vertex3dv:
	{
		GLVertex3dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::Vertex3fv:
	{
		GLVertex3fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::Vertex3iv:
	{
		GLVertex3iv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::Vertex3sv:
	{
		GLVertex3sv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	case GL11Flags::Vertex4dv:
	{
		GLVertex4dv(any_cast<const GLdouble*>(parameter[0]));

		return true;
	}
	case GL11Flags::Vertex4fv:
	{
		GLVertex4fv(any_cast<const GLfloat*>(parameter[0]));

		return true;
	}
	case GL11Flags::Vertex4iv:
	{
		GLVertex4iv(any_cast<const GLint*>(parameter[0]));

		return true;
	}
	case GL11Flags::Vertex4sv:
	{
		GLVertex4sv(any_cast<const GLshort*>(parameter[0]));

		return true;
	}
	default:
		return false;
	}
}   

bool System
	::GL11TestParameter2(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::Accum:
	{
		GLAccum(any_cast<GLenum>(parameter[0]), any_cast<GLfloat>(parameter[1]));

		return true;
	}
	case GL11Flags::AlphaFunc:
	{
		GLAlphaFunc(any_cast<GLenum>(parameter[0]), any_cast<GLclampf>(parameter[1]));

		return true;
	}
	case GL11Flags::BindTexture:
	{
		GLBindTexture(any_cast<GLenum>(parameter[0]), any_cast<GLuint>(parameter[1]));

		return true;
	}
	case GL11Flags::BlendFunc:
	{
		GLBlendFunc(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]));

		return true;
	}
	case GL11Flags::ClipPlane:
	{
		GLClipPlane(any_cast<GLenum>(parameter[0]), any_cast<const GLdouble*>(parameter[1]));

		return true;
	}
	case GL11Flags::ColorMaterial:
	{
		GLColorMaterial(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]));

		return true;
	}
	case GL11Flags::DeleteLists:
	{
		GLDeleteLists(any_cast<GLuint>(parameter[0]), any_cast<GLsizei>(parameter[1]));

		return true;
	}
	case GL11Flags::DeleteTextures:
	{
		GLDeleteTextures(any_cast<GLsizei>(parameter[0]), any_cast<const GLuint*>(parameter[1]));

		return true;
	}
	case GL11Flags::DepthRange:
	{
		GLDepthRange(any_cast<GLclampd>(parameter[0]), any_cast<GLclampd>(parameter[1]));

		return true;
	}
	case GL11Flags::EdgeFlagPointer:
	{
		GLEdgeFlagPointer(any_cast<GLsizei>(parameter[0]), any_cast<const GLvoid*>(parameter[1]));

		return true;
	}
	case GL11Flags::EvalCoord2d:
	{
		GLEvalCoord2d(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]));

		return true;
	}
	case GL11Flags::EvalCoord2f:
	{
		GLEvalCoord2f(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]));

		return true;
	}
	case GL11Flags::EvalPoint2:
	{
		GLEvalPoint2(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]));

		return true;
	}
	case GL11Flags::Fogf:
	{
		GLFogf(any_cast<GLenum>(parameter[0]), any_cast<GLfloat>(parameter[1]));

		return true;
	}
	case GL11Flags::Fogfv:
	{
		GLFogfv(any_cast<GLenum>(parameter[0]), any_cast<const GLfloat*>(parameter[1]));

		return true;
	}
	case GL11Flags::Fogi:
	{
		GLFogi(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]));

		return true;
	}
	case GL11Flags::Fogiv:
	{
		GLFogiv(any_cast<GLenum>(parameter[0]), any_cast<const GLint*>(parameter[1]));

		return true;
	}
	case GL11Flags::GenTextures:
	{
		GLGenTextures(any_cast<GLsizei>(parameter[0]), any_cast<GLuint*>(parameter[1]));

		return true;
	}
	case GL11Flags::GetBooleanv:
	{
		GLGetBooleanv(any_cast<GLenum>(parameter[0]), any_cast<GLboolean*>(parameter[1]));

		return true;
	}
	case GL11Flags::GetClipPlane:
	{
		GLGetClipPlane(any_cast<GLenum>(parameter[0]), any_cast<GLdouble*>(parameter[1]));

		return true;
	}
	case GL11Flags::GetDoublev:
	{
		GLGetDoublev(any_cast<GLenum>(parameter[0]), any_cast<GLdouble*>(parameter[1]));

		return true;
	}
	case GL11Flags::GetFloatv:
	{
		GLGetFloatv(any_cast<GLenum>(parameter[0]), any_cast<GLfloat*>(parameter[1]));

		return true;
	}
	case GL11Flags::GetIntegerv:
	{
		GLGetIntegerv(any_cast<GLenum>(parameter[0]), any_cast<GLint*>(parameter[1]));

		return true;
	}
	case GL11Flags::GetPixelMapfv:
	{
		GLGetPixelMapfv(any_cast<GLenum>(parameter[0]), any_cast<GLfloat*>(parameter[1]));

		return true;
	}
	case GL11Flags::GetPixelMapuiv:
	{
		GLGetPixelMapuiv(any_cast<GLenum>(parameter[0]), any_cast<GLuint*>(parameter[1]));

		return true;
	}
	case GL11Flags::GetPixelMapusv:
	{
		GLGetPixelMapusv(any_cast<GLenum>(parameter[0]), any_cast<GLushort*>(parameter[1]));

		return true;
	}
	case GL11Flags::GetPointerv:
	{
		GLGetPointerv(any_cast<GLenum>(parameter[0]), any_cast<GLvoid**>(parameter[1]));

		return true;
	}
	case GL11Flags::Hint:
	{
		GLHint(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]));

		return true;
	}
	case GL11Flags::LightModelf:
	{
		GLLightModelf(any_cast<GLenum>(parameter[0]), any_cast<GLfloat>(parameter[1]));

		return true;
	}
	case GL11Flags::LightModelfv:
	{
		GLLightModelfv(any_cast<GLenum>(parameter[0]), any_cast<const GLfloat*>(parameter[1]));

		return true;
	}
	case GL11Flags::LightModeli:
	{
		GLLightModeli(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]));

		return true;
	}
	case GL11Flags::LightModeliv:
	{
		GLLightModeliv(any_cast<GLenum>(parameter[0]), any_cast<const GLint*>(parameter[1]));

		return true;
	}
	case GL11Flags::LineStipple:
	{
		GLLineStipple(any_cast<GLint>(parameter[0]), any_cast<GLushort>(parameter[1]));

		return true;
	}
	case GL11Flags::NewList:
	{
		GLNewList(any_cast<GLuint>(parameter[0]), any_cast<GLenum>(parameter[1]));

		return true;
	}
	case GL11Flags::PixelStoref:
	{
		GLPixelStoref(any_cast<GLenum>(parameter[0]), any_cast<GLfloat>(parameter[1]));

		return true;
	}
	case GL11Flags::PixelStorei:
	{
		GLPixelStorei(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]));

		return true;
	}
	case GL11Flags::PixelTransferf:
	{
		GLPixelTransferf(any_cast<GLenum>(parameter[0]), any_cast<GLfloat>(parameter[1]));

		return true;
	}
	case GL11Flags::PixelTransferi:
	{
		GLPixelTransferi(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]));

		return true;
	}
	case GL11Flags::PixelZoom:
	{
		GLPixelZoom(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]));

		return true;
	}
	case GL11Flags::PolygonMode:
	{
		GLPolygonMode(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]));

		return true;
	}
	case GL11Flags::PolygonOffset:
	{
		GLPolygonOffset(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]));

		return true;
	}
	case GL11Flags::RasterPos2d:
	{
		GLRasterPos2d(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]));

		return true;
	}
	case GL11Flags::RasterPos2f:
	{
		GLRasterPos2f(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]));

		return true;
	}
	case GL11Flags::RasterPos2i:
	{
		GLRasterPos2i(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]));

		return true;
	}
	case GL11Flags::RasterPos2s:
	{
		GLRasterPos2s(any_cast<GLshort>(parameter[0]), any_cast<GLshort>(parameter[1]));

		return true;
	}
	case GL11Flags::Rectdv:
	{
		GLRectdv(any_cast<const GLdouble*>(parameter[0]), any_cast<const GLdouble*>(parameter[1]));

		return true;
	}
	case GL11Flags::Rectfv:
	{
		GLRectfv(any_cast<const GLfloat*>(parameter[0]), any_cast<const GLfloat*>(parameter[1]));

		return true;
	}
	case GL11Flags::Rectiv:
	{
		GLRectiv(any_cast<const GLint*>(parameter[0]), any_cast<const GLint*>(parameter[1]));

		return true;
	}
	case GL11Flags::Rectsv:
	{
		GLRectsv(any_cast<const GLshort*>(parameter[0]), any_cast<const GLshort*>(parameter[1]));

		return true;
	}
	case GL11Flags::SelectBuffer:
	{
		GLSelectBuffer(any_cast<GLsizei>(parameter[0]), any_cast<GLuint*>(parameter[1]));

		return true;
	}
	case GL11Flags::TexCoord2d:
	{
		GLTexCoord2d(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]));

		return true;
	}
	case GL11Flags::TexCoord2f:
	{
		GLTexCoord2f(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]));

		return true;
	}
	case GL11Flags::TexCoord2i:
	{
		GLTexCoord2i(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]));

		return true;
	}
	case GL11Flags::TexCoord2s:
	{
		GLTexCoord2s(any_cast<GLshort>(parameter[0]), any_cast<GLshort>(parameter[1]));

		return true;
	}
	case GL11Flags::Vertex2d:
	{
		GLVertex2d(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]));

		return true;
	}
	case GL11Flags::Vertex2f:
	{
		GLVertex2f(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]));

		return true;
	}
	case GL11Flags::Vertex2i:
	{
		GLVertex2i(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]));

		return true;
	}
	case GL11Flags::Vertex2s:
	{
		GLVertex2s(any_cast<GLshort>(parameter[0]), any_cast<GLshort>(parameter[1]));

		return true;
	}
	default:
		return false;
	}
}  

bool System
	::GL11TestParameter3(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::CallLists:
	{
		GLCallLists(any_cast<GLsizei>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<const GLvoid*>(parameter[2]));

		return true;
	}
	case GL11Flags::Color3b:
	{
		GLColor3b(any_cast<GLbyte>(parameter[0]), any_cast<GLbyte>(parameter[1]), any_cast<GLbyte>(parameter[2]));

		return true;
	}
	case GL11Flags::Color3d:
	{
		GLColor3d(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]));

		return true;
	}
	case GL11Flags::Color3f:
	{
		GLColor3f(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]));

		return true;
	}
	case GL11Flags::Color3i:
	{
		GLColor3i(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]));

		return true;
	}
	case GL11Flags::Color3s:
	{
		GLColor3s(any_cast<GLshort>(parameter[0]), any_cast<GLshort>(parameter[1]), any_cast<GLshort>(parameter[2]));

		return true;
	}
	case GL11Flags::Color3ub:
	{
		GLColor3ub(any_cast<GLubyte>(parameter[0]), any_cast<GLubyte>(parameter[1]), any_cast<GLubyte>(parameter[2]));

		return true;
	}
	case GL11Flags::Color3ui:
	{
		GLColor3ui(any_cast<GLuint>(parameter[0]), any_cast<GLuint>(parameter[1]), any_cast<GLuint>(parameter[2]));

		return true;
	}
	case GL11Flags::Color3us:
	{
		GLColor3us(any_cast<GLushort>(parameter[0]), any_cast<GLushort>(parameter[1]), any_cast<GLushort>(parameter[2]));

		return true;
	}
	case GL11Flags::DrawArrays:
	{
		GLDrawArrays(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLsizei>(parameter[2]));

		return true;
	}
	case GL11Flags::EvalMesh1:
	{
		GLEvalMesh1(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]));

		return true;
	}
	case GL11Flags::FeedbackBuffer:
	{
		GLFeedbackBuffer(any_cast<GLsizei>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLfloat*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetLightfv:
	{
		GLGetLightfv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLfloat*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetLightiv:
	{
		GLGetLightiv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLint*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetMapdv:
	{
		GLGetMapdv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLdouble*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetMapfv:
	{
		GLGetMapfv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLfloat*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetMapiv:
	{
		GLGetMapiv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLint*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetMaterialfv:
	{
		GLGetMaterialfv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLfloat*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetMaterialiv:
	{
		GLGetMaterialiv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLint*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetTexEnvfv:
	{
		GLGetTexEnvfv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLfloat*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetTexEnviv:
	{
		GLGetTexEnviv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLint*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetTexGendv:
	{
		GLGetTexGendv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLdouble*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetTexGenfv:
	{
		GLGetTexGenfv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLfloat*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetTexGeniv:
	{
		GLGetTexGeniv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLint*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetTexParameterfv:
	{
		GLGetTexParameterfv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLfloat*>(parameter[2]));

		return true;
	}
	case GL11Flags::GetTexParameteriv:
	{
		GLGetTexParameteriv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLint*>(parameter[2]));

		return true;
	}
	case GL11Flags::IndexPointer:
	{
		GLIndexPointer(any_cast<GLenum>(parameter[0]), any_cast<GLsizei>(parameter[1]), any_cast<const GLvoid*>(parameter[2]));

		return true;
	}
	case GL11Flags::InterleavedArrays:
	{
		GLInterleavedArrays(any_cast<GLenum>(parameter[0]), any_cast<GLsizei>(parameter[1]), any_cast<const GLvoid*>(parameter[2]));

		return true;
	}
	case GL11Flags::Lightf:
	{
		GLLightf(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLfloat>(parameter[2]));

		return true;
	}
	case GL11Flags::Lightfv:
	{
		GLLightfv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<const GLfloat*>(parameter[2]));

		return true;
	}
	case GL11Flags::Lighti:
	{
		GLLighti(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLint>(parameter[2]));

		return true;
	}
	case GL11Flags::Lightiv:
	{
		GLLightiv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<const GLint*>(parameter[2]));

		return true;
	}
	case GL11Flags::MapGrid1d:
	{
		GLMapGrid1d(any_cast<GLint>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]));

		return true;
	}
	case GL11Flags::MapGrid1f:
	{
		GLMapGrid1f(any_cast<GLint>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]));

		return true;
	}
	case GL11Flags::Materialf:
	{
		GLMaterialf(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLfloat>(parameter[2]));

		return true;
	}
	case GL11Flags::Materialfv:
	{
		GLMaterialfv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<const GLfloat*>(parameter[2]));

		return true;
	}
	case GL11Flags::Materiali:
	{
		GLMateriali(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLint>(parameter[2]));

		return true;
	}
	case GL11Flags::Materialiv:
	{
		GLMaterialiv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<const GLint*>(parameter[2]));

		return true;
	}
	case GL11Flags::Normal3b:
	{
		GLNormal3b(any_cast<GLbyte>(parameter[0]), any_cast<GLbyte>(parameter[1]), any_cast<GLbyte>(parameter[2]));

		return true;
	}
	case GL11Flags::Normal3d:
	{
		GLNormal3d(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]));

		return true;
	}
	case GL11Flags::Normal3f:
	{
		GLNormal3f(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]));

		return true;
	}
	case GL11Flags::Normal3i:
	{
		GLNormal3i(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]));

		return true;
	}
	case GL11Flags::Normal3s:
	{
		GLNormal3s(any_cast<GLshort>(parameter[0]), any_cast<GLshort>(parameter[1]), any_cast<GLshort>(parameter[2]));

		return true;
	}
	case GL11Flags::NormalPointer:
	{
		GLNormalPointer(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<const GLvoid*>(parameter[2]));

		return true;
	}
	case GL11Flags::PixelMapfv:
	{
		GLPixelMapfv(any_cast<GLenum>(parameter[0]), any_cast<GLsizei>(parameter[1]), any_cast<const GLfloat*>(parameter[2]));

		return true;
	}
	case GL11Flags::PixelMapuiv:
	{
		GLPixelMapuiv(any_cast<GLenum>(parameter[0]), any_cast<GLsizei>(parameter[1]), any_cast<const GLuint*>(parameter[2]));

		return true;
	}
	case GL11Flags::PixelMapusv:
	{
		GLPixelMapusv(any_cast<GLenum>(parameter[0]), any_cast<GLsizei>(parameter[1]), any_cast<const GLushort*>(parameter[2]));

		return true;
	}
	case GL11Flags::PrioritizeTextures:
	{
		GLPrioritizeTextures(any_cast<GLsizei>(parameter[0]), any_cast<const GLuint*>(parameter[1]), any_cast<const GLclampf*>(parameter[2]));

		return true;
	}
	case GL11Flags::RasterPos3d:
	{
		GLRasterPos3d(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]));

		return true;
	}
	case GL11Flags::RasterPos3f:
	{
		GLRasterPos3f(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]));

		return true;
	}
	case GL11Flags::RasterPos3i:
	{
		GLRasterPos3i(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]));

		return true;
	}
	case GL11Flags::RasterPos3s:
	{
		GLRasterPos3s(any_cast<GLshort>(parameter[0]), any_cast<GLshort>(parameter[1]), any_cast<GLshort>(parameter[2]));

		return true;
	}
	case GL11Flags::Scaled:
	{
		GLScaled(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]));

		return true;
	}
	case GL11Flags::Scalef:
	{
		GLScalef(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]));

		return true;
	}
	case GL11Flags::StencilFunc:
	{
		GLStencilFunc(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLuint>(parameter[2]));

		return true;
	}
	case GL11Flags::StencilOp:
	{
		GLStencilOp(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLenum>(parameter[2]));

		return true;
	}
	case GL11Flags::TexCoord3d:
	{
		GLTexCoord3d(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]));

		return true;
	}
	case GL11Flags::TexCoord3f:
	{
		GLTexCoord3f(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]));

		return true;
	}
	case GL11Flags::TexCoord3i:
	{
		GLTexCoord3i(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]));

		return true;
	}
	case GL11Flags::TexCoord3s:
	{
		GLTexCoord3s(any_cast<GLshort>(parameter[0]), any_cast<GLshort>(parameter[1]), any_cast<GLshort>(parameter[2]));

		return true;
	}
	case GL11Flags::TexEnvf:
	{
		GLTexEnvf(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLfloat>(parameter[2]));

		return true;
	}
	case GL11Flags::TexEnvfv:
	{
		GLTexEnvfv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<const GLfloat*>(parameter[2]));

		return true;
	}
	case GL11Flags::TexEnvi:
	{
		GLTexEnvi(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLint>(parameter[2]));

		return true;
	}
	case GL11Flags::TexEnviv:
	{
		GLTexEnviv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<const GLint*>(parameter[2]));

		return true;
	}
	case GL11Flags::TexGend:
	{
		GLTexGend(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLdouble>(parameter[2]));

		return true;
	}
	case GL11Flags::TexGendv:
	{
		GLTexGendv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<const GLdouble*>(parameter[2]));

		return true;
	}
	case GL11Flags::TexGenf:
	{
		GLTexGenf(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLfloat>(parameter[2]));

		return true;
	}
	case GL11Flags::TexGenfv:
	{
		GLTexGenfv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<const GLfloat*>(parameter[2]));

		return true;
	}
	case GL11Flags::TexGeni:
	{
		GLTexGeni(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLint>(parameter[2]));

		return true;
	}
	case GL11Flags::TexGeniv:
	{
		GLTexGeniv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<const GLint*>(parameter[2]));

		return true;
	}
	case GL11Flags::TexParameterf:
	{
		GLTexParameterf(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLfloat>(parameter[2]));

		return true;
	}
	case GL11Flags::TexParameterfv:
	{
		GLTexParameterfv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<const GLfloat*>(parameter[2]));

		return true;
	}
	case GL11Flags::TexParameteri:
	{
		GLTexParameteri(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLint>(parameter[2]));

		return true;
	}
	case GL11Flags::TexParameteriv:
	{
		GLTexParameteriv(any_cast<GLenum>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<const GLint*>(parameter[2]));

		return true;
	}
	case GL11Flags::Translated:
	{
		GLTranslated(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]));

		return true;
	}
	case GL11Flags::Translatef:
	{
		GLTranslatef(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]));

		return true;
	}
	case GL11Flags::Vertex3d:
	{
		GLVertex3d(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]));

		return true;
	}
	case GL11Flags::Vertex3f:
	{
		GLVertex3f(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]));

		return true;
	}
	case GL11Flags::Vertex3i:
	{
		GLVertex3i(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]));

		return true;
	}
	case GL11Flags::Vertex3s:
	{
		GLVertex3s(any_cast<GLshort>(parameter[0]), any_cast<GLshort>(parameter[1]), any_cast<GLshort>(parameter[2]));

		return true;
	}
	default:
		return false;
	}
}    

bool System
	::GL11TestParameter4(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::ClearAccum:
	{
		GLClearAccum(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]), any_cast<GLfloat>(parameter[3]));

		return true;
	}
	case GL11Flags::ClearColor:
	{
		GLClearColor(any_cast<GLclampf>(parameter[0]), any_cast<GLclampf>(parameter[1]), any_cast<GLclampf>(parameter[2]), any_cast<GLclampf>(parameter[3]));

		return true;
	}
	case GL11Flags::Color4b:
	{
		GLColor4b(any_cast<GLbyte>(parameter[0]), any_cast<GLbyte>(parameter[1]), any_cast<GLbyte>(parameter[2]), any_cast<GLbyte>(parameter[3]));

		return true;
	}
	case GL11Flags::Color4d:
	{
		GLColor4d(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]), any_cast<GLdouble>(parameter[3]));

		return true;
	}
	case GL11Flags::Color4f:
	{
		GLColor4f(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]), any_cast<GLfloat>(parameter[3]));

		return true;
	}
	case GL11Flags::Color4i:
	{
		GLColor4i(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]), any_cast<GLint>(parameter[3]));

		return true;
	}
	case GL11Flags::Color4s:
	{
		GLColor4s(any_cast<GLshort>(parameter[0]), any_cast<GLshort>(parameter[1]), any_cast<GLshort>(parameter[2]), any_cast<GLshort>(parameter[3]));

		return true;
	}
	case GL11Flags::Color4ub:
	{
		GLColor4ub(any_cast<GLubyte>(parameter[0]), any_cast<GLubyte>(parameter[1]), any_cast<GLubyte>(parameter[2]), any_cast<GLubyte>(parameter[3]));

		return true;
	}
	case GL11Flags::Color4ui:
	{
		GLColor4ui(any_cast<GLuint>(parameter[0]), any_cast<GLuint>(parameter[1]), any_cast<GLuint>(parameter[2]), any_cast<GLuint>(parameter[3]));

		return true;
	}
	case GL11Flags::Color4us:
	{
		GLColor4us(any_cast<GLushort>(parameter[0]), any_cast<GLushort>(parameter[1]), any_cast<GLushort>(parameter[2]), any_cast<GLushort>(parameter[3]));

		return true;
	}
	case GL11Flags::ColorMask:
	{
		GLColorMask(any_cast<GLboolean>(parameter[0]), any_cast<GLboolean>(parameter[1]), any_cast<GLboolean>(parameter[2]), any_cast<GLboolean>(parameter[3]));

		return true;
	}
	case GL11Flags::ColorPointer:
	{
		GLColorPointer(any_cast<GLint>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLsizei>(parameter[2]), any_cast<const GLvoid*>(parameter[3]));

		return true;
	}
	case GL11Flags::DrawElements:
	{
		GLDrawElements(any_cast<GLenum>(parameter[0]), any_cast<GLsizei>(parameter[1]), any_cast<GLenum>(parameter[2]), any_cast<const GLvoid*>(parameter[3]));

		return true;
	}
	case GL11Flags::GetTexLevelParameterfv:
	{
		GLGetTexLevelParameterfv(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLenum>(parameter[2]), any_cast<GLfloat*>(parameter[3]));

		return true;
	}
	case GL11Flags::GetTexLevelParameteriv:
	{
		GLGetTexLevelParameteriv(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLenum>(parameter[2]), any_cast<GLint*>(parameter[3]));

		return true;
	}
	case GL11Flags::RasterPos4d:
	{
		GLRasterPos4d(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]), any_cast<GLdouble>(parameter[3]));

		return true;
	}
	case GL11Flags::RasterPos4f:
	{
		GLRasterPos4f(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]), any_cast<GLfloat>(parameter[3]));

		return true;
	}
	case GL11Flags::RasterPos4i:
	{
		GLRasterPos4i(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]), any_cast<GLint>(parameter[3]));

		return true;
	}
	case GL11Flags::RasterPos4s:
	{
		GLRasterPos4s(any_cast<GLshort>(parameter[0]), any_cast<GLshort>(parameter[1]), any_cast<GLshort>(parameter[2]), any_cast<GLshort>(parameter[3]));

		return true;
	}
	case GL11Flags::Rectd:
	{
		GLRectd(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]), any_cast<GLdouble>(parameter[3]));

		return true;
	}
	case GL11Flags::Rectf:
	{
		GLRectf(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]), any_cast<GLfloat>(parameter[3]));

		return true;
	}
	case GL11Flags::Recti:
	{
		GLRecti(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]), any_cast<GLint>(parameter[3]));

		return true;
	}
	case GL11Flags::Rects:
	{
		GLRects(any_cast<GLshort>(parameter[0]), any_cast<GLshort>(parameter[1]), any_cast<GLshort>(parameter[2]), any_cast<GLshort>(parameter[3]));

		return true;
	}
	case GL11Flags::Rotated:
	{
		GLRotated(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]), any_cast<GLdouble>(parameter[3]));

		return true;
	}
	case GL11Flags::Rotatef:
	{
		GLRotatef(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]), any_cast<GLfloat>(parameter[3]));

		return true;
	}
	case GL11Flags::Scissor:
	{
		GLScissor(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLsizei>(parameter[2]), any_cast<GLsizei>(parameter[3]));

		return true;
	}
	case GL11Flags::TexCoord4d:
	{
		GLTexCoord4d(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]), any_cast<GLdouble>(parameter[3]));

		return true;
	}
	case GL11Flags::TexCoord4f:
	{
		GLTexCoord4f(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]), any_cast<GLfloat>(parameter[3]));

		return true;
	}
	case GL11Flags::TexCoord4i:
	{
		GLTexCoord4i(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]), any_cast<GLint>(parameter[3]));

		return true;
	}
	case GL11Flags::TexCoord4s:
	{
		GLTexCoord4s(any_cast<GLshort>(parameter[0]), any_cast<GLshort>(parameter[1]), any_cast<GLshort>(parameter[2]), any_cast<GLshort>(parameter[3]));

		return true;
	}
	case GL11Flags::TexCoordPointer:
	{
		GLTexCoordPointer(any_cast<GLint>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLsizei>(parameter[2]), any_cast<const GLvoid*>(parameter[3]));

		return true;
	}
	case GL11Flags::Vertex4d:
	{
		GLVertex4d(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]), any_cast<GLdouble>(parameter[3]));

		return true;
	}
	case GL11Flags::Vertex4f:
	{
		GLVertex4f(any_cast<GLfloat>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]), any_cast<GLfloat>(parameter[3]));

		return true;
	}
	case GL11Flags::Vertex4i:
	{
		GLVertex4i(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]), any_cast<GLint>(parameter[3]));

		return true;
	}
	case GL11Flags::Vertex4s:
	{
		GLVertex4s(any_cast<GLshort>(parameter[0]), any_cast<GLshort>(parameter[1]), any_cast<GLshort>(parameter[2]), any_cast<GLshort>(parameter[3]));

		return true;
	}
	case GL11Flags::VertexPointer:
	{
		GLVertexPointer(any_cast<GLint>(parameter[0]), any_cast<GLenum>(parameter[1]), any_cast<GLsizei>(parameter[2]), any_cast<const GLvoid*>(parameter[3]));

		return true;
	}
	case GL11Flags::Viewport:
	{
		GLViewport(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLsizei>(parameter[2]), any_cast<GLsizei>(parameter[3]));

		return true;
	}
	default:
		return false;
	}
} 
 
bool System
	::GL11TestParameter5(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::CopyPixels:
	{
		GLCopyPixels(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLsizei>(parameter[2]), any_cast<GLsizei>(parameter[3]), any_cast<GLenum>(parameter[4]));

		return true;
	}
	case GL11Flags::DrawPixels:
	{
		GLDrawPixels(any_cast<GLsizei>(parameter[0]), any_cast<GLsizei>(parameter[1]), any_cast<GLenum>(parameter[2]), any_cast<GLenum>(parameter[3]), any_cast<const GLvoid*>(parameter[4]));

		return true;
	}
	case GL11Flags::EvalMesh2:
	{
		GLEvalMesh2(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]), any_cast<GLint>(parameter[3]), any_cast<GLint>(parameter[4]));

		return true;
	}
	case GL11Flags::GetTexImage:
	{
		GLGetTexImage(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLenum>(parameter[2]), any_cast<GLenum>(parameter[3]), any_cast<GLvoid*>(parameter[4]));

		return true;
	}
	default:
		return false;
	}
}
 
bool System
	::GL11TestParameter6(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::CopyTexSubImage1D:
	{
		GLCopyTexSubImage1D(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]), any_cast<GLint>(parameter[3]), any_cast<GLint>(parameter[4]), any_cast<GLsizei>(parameter[5]));

		return true;
	}
	case GL11Flags::Frustum:
	{
		GLFrustum(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]), any_cast<GLdouble>(parameter[3]), any_cast<GLdouble>(parameter[4]), any_cast<GLdouble>(parameter[5]));

		return true;
	}
	case GL11Flags::Map1d:
	{
		GLMap1d(any_cast<GLenum>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]), any_cast<GLint>(parameter[3]), any_cast<GLint>(parameter[4]), any_cast<const GLdouble*>(parameter[5]));

		return true;
	}
	case GL11Flags::Map1f:
	{
		GLMap1f(any_cast<GLenum>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]), any_cast<GLint>(parameter[3]), any_cast<GLint>(parameter[4]), any_cast<const GLfloat*>(parameter[5]));

		return true;
	}
	case GL11Flags::MapGrid2d:
	{
		GLMapGrid2d(any_cast<GLint>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]), any_cast<GLint>(parameter[3]), any_cast<GLdouble>(parameter[4]), any_cast<GLdouble>(parameter[5]));

		return true;
	}
	case GL11Flags::MapGrid2f:
	{
		GLMapGrid2f(any_cast<GLint>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]), any_cast<GLint>(parameter[3]), any_cast<GLfloat>(parameter[4]), any_cast<GLfloat>(parameter[5]));

		return true;
	}
	case GL11Flags::Ortho:
	{
		GLOrtho(any_cast<GLdouble>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]), any_cast<GLdouble>(parameter[3]), any_cast<GLdouble>(parameter[4]), any_cast<GLdouble>(parameter[5]));

		return true;
	}
	default:
		return false;
	}
}
 
bool System
	::GL11TestParameter7(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::Bitmap:
	{
		GLBitmap(any_cast<GLsizei>(parameter[0]), any_cast<GLsizei>(parameter[1]), any_cast<GLfloat>(parameter[2]), any_cast<GLfloat>(parameter[3]), any_cast<GLfloat>(parameter[4]), any_cast<GLfloat>(parameter[5]), any_cast<const GLubyte*>(parameter[6]));

		return true;
	}
	case GL11Flags::CopyTexImage1D:
	{
		GLCopyTexImage1D(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLenum>(parameter[2]), any_cast<GLint>(parameter[3]), any_cast<GLint>(parameter[4]), any_cast<GLsizei>(parameter[5]), any_cast<GLint>(parameter[6]));

		return true;
	}
	case GL11Flags::ReadPixels:
	{
		GLReadPixels(any_cast<GLint>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLsizei>(parameter[2]), any_cast<GLsizei>(parameter[3]), any_cast<GLenum>(parameter[4]), any_cast<GLenum>(parameter[5]), any_cast<GLvoid*>(parameter[6]));

		return true;
	}
	case GL11Flags::TexSubImage1D:
	{
		GLTexSubImage1D(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]), any_cast<GLsizei>(parameter[3]), any_cast<GLenum>(parameter[4]), any_cast<GLenum>(parameter[5]), any_cast<const GLvoid*>(parameter[6]));

		return true;
	}
	default:
		return false;
	}
}	
 
bool System
	::GL11TestParameter8(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::CopyTexImage2D:
	{
		GLCopyTexImage2D(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLenum>(parameter[2]), any_cast<GLint>(parameter[3]), any_cast<GLint>(parameter[4]), any_cast<GLsizei>(parameter[5]), any_cast<GLsizei>(parameter[6]), any_cast<GLint>(parameter[7]));

		return true;
	}	
	case GL11Flags::CopyTexSubImage2D:
	{
		GLCopyTexSubImage2D(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]), any_cast<GLint>(parameter[3]), any_cast<GLint>(parameter[4]), any_cast<GLint>(parameter[5]), any_cast<GLsizei>(parameter[6]), any_cast<GLsizei>(parameter[7]));

		return true;
	}
	case GL11Flags::TexImage1D:
	{
		GLTexImage1D(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]), any_cast<GLsizei>(parameter[3]), any_cast<GLint>(parameter[4]), any_cast<GLenum>(parameter[5]), any_cast<GLenum>(parameter[6]), any_cast<const GLvoid*>(parameter[7]));

		return true;
	}
	default:
		return false;
	}
} 
 
bool System
	::GL11TestParameter9(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::TexImage2D:
	{
		GLTexImage2D(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]), any_cast<GLsizei>(parameter[3]), any_cast<GLsizei>(parameter[4]), any_cast<GLint>(parameter[5]), any_cast<GLenum>(parameter[6]), any_cast<GLenum>(parameter[7]), any_cast<const GLvoid*>(parameter[8]));

		return true;
	}
	case GL11Flags::TexSubImage2D:
	{
		GLTexSubImage2D(any_cast<GLenum>(parameter[0]), any_cast<GLint>(parameter[1]), any_cast<GLint>(parameter[2]), any_cast<GLint>(parameter[3]), any_cast<GLsizei>(parameter[4]), any_cast<GLsizei>(parameter[5]), any_cast<GLenum>(parameter[6]), any_cast<GLenum>(parameter[7]), any_cast<const GLvoid*>(parameter[8]));

		return true;
	}
	default:
		return false;
	}
}
 
bool System
	::GL11TestParameter10(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::Map2d:
	{
		GLMap2d(any_cast<GLenum>(parameter[0]), any_cast<GLdouble>(parameter[1]), any_cast<GLdouble>(parameter[2]), any_cast<GLint>(parameter[3]), any_cast<GLint>(parameter[4]), any_cast<GLdouble>(parameter[5]), any_cast<GLdouble>(parameter[6]), any_cast<GLint>(parameter[7]), any_cast<GLint>(parameter[8]), any_cast<const GLdouble*>(parameter[9]));

		return true;
	}
	case GL11Flags::Map2f:
	{
		GLMap2f(any_cast<GLenum>(parameter[0]), any_cast<GLfloat>(parameter[1]), any_cast<GLfloat>(parameter[2]), any_cast<GLint>(parameter[3]), any_cast<GLint>(parameter[4]), any_cast<GLfloat>(parameter[5]), any_cast<GLfloat>(parameter[6]), any_cast<GLint>(parameter[7]), any_cast<GLint>(parameter[8]), any_cast<const GLfloat*>(parameter[9]));

		return true;
	}
	default:
		return false;
	}
}
 
GLboolean System
	::GL11TestParameter1ReturnBoolean(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::IsEnabled:
	{
		return GLIsEnabled(any_cast<GLenum>(parameter[0]));
	}
	case GL11Flags::IsList:
	{
		return GLIsList(any_cast<GLuint>(parameter[0]));
	}
	case GL11Flags::IsTexture:
	{
		return GLIsTexture(any_cast<GLuint>(parameter[0]));
	}
	default:
		return GL_FALSE;
	}
}
 
GLboolean System
	::GL11TestParameter3ReturnBoolean(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::AreTexturesResident:
	{
		return GLAreTexturesResident(any_cast<GLsizei>(parameter[0]), any_cast<const GLuint*>(parameter[1]),any_cast<GLboolean*>(parameter[2]));		 
	}
	default:
		return GL_FALSE;
	}
}

const GLubyte* System
	::GL11TestParameter1ReturnConstGLubytePtr(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::GetString:
	{
		return GLGetString(any_cast<GLenum>(parameter[0]));
	}
	default:
		return nullptr;
	}
}

GLint System
	::GL11TestParameter1ReturnGLint(GL11Flags gl11, const Parameter& parameter)
{
	switch (gl11)
	{
	case GL11Flags::RenderMode:
	{
		return GLRenderMode(any_cast<GLenum>(parameter[0]));
	}
	default:
		return 0;
	}
}
 