// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:40)

#include "System/SystemExport.h"

#include "GL11Extensions.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

// OpenGL 1.1
namespace System
{
	ExistsOpenGLExtensions g_ExistsOpenGL11{ ExistsOpenGLExtensions::Exists };
}

System::ExistsOpenGLExtensions System
	::IsExistsOpenGL11() noexcept
{
	return g_ExistsOpenGL11;
}

#undef glAccum
#undef glAlphaFunc
#undef glAreTexturesResident
#undef glArrayElement
#undef glBegin
#undef glBindTexture
#undef glBitmap
#undef glBlendFunc
#undef glCallList
#undef glCallLists
#undef glClear
#undef glClearAccum
#undef glClearColor
#undef glClearDepth
#undef glClearIndex
#undef glClearStencil
#undef glClipPlane
#undef glColor3b
#undef glColor3bv
#undef glColor3d
#undef glColor3dv
#undef glColor3f
#undef glColor3fv
#undef glColor3i
#undef glColor3iv
#undef glColor3s
#undef glColor3sv
#undef glColor3ub
#undef glColor3ubv
#undef glColor3ui
#undef glColor3uiv
#undef glColor3us
#undef glColor3usv
#undef glColor4b
#undef glColor4bv
#undef glColor4d
#undef glColor4dv
#undef glColor4f
#undef glColor4fv
#undef glColor4i
#undef glColor4iv
#undef glColor4s
#undef glColor4sv
#undef glColor4ub
#undef glColor4ubv
#undef glColor4ui
#undef glColor4uiv
#undef glColor4us
#undef glColor4usv
#undef glColorMask
#undef glColorMaterial
#undef glColorPointer
#undef glCopyPixels
#undef glCopyTexImage1D
#undef glCopyTexImage2D
#undef glCopyTexSubImage1D
#undef glCopyTexSubImage2D
#undef glCullFace
#undef glDeleteLists
#undef glDeleteTextures
#undef glDepthFunc
#undef glDepthMask
#undef glDepthRange
#undef glDisable
#undef glDisableClientState
#undef glDrawArrays
#undef glDrawBuffer
#undef glDrawElements
#undef glDrawPixels
#undef glEdgeFlag
#undef glEdgeFlagPointer
#undef glEdgeFlagv
#undef glEnable
#undef glEnableClientState
#undef glEnd
#undef glEndList
#undef glEvalCoord1d
#undef glEvalCoord1dv
#undef glEvalCoord1f
#undef glEvalCoord1fv
#undef glEvalCoord2d
#undef glEvalCoord2dv
#undef glEvalCoord2f
#undef glEvalCoord2fv
#undef glEvalMesh1
#undef glEvalMesh2
#undef glEvalPoint1
#undef glEvalPoint2
#undef glFeedbackBuffer
#undef glFinish
#undef glFlush
#undef glFogf
#undef glFogfv
#undef glFogi
#undef glFogiv
#undef glFrontFace
#undef glFrustum
#undef glGenLists
#undef glGenTextures
#undef glGetBooleanv
#undef glGetClipPlane
#undef glGetDoublev
#undef glGetError
#undef glGetFloatv
#undef glGetIntegerv
#undef glGetLightfv
#undef glGetLightiv
#undef glGetMapdv
#undef glGetMapfv
#undef glGetMapiv
#undef glGetMaterialfv
#undef glGetMaterialiv
#undef glGetPixelMapfv
#undef glGetPixelMapuiv
#undef glGetPixelMapusv
#undef glGetPointerv
#undef glGetPolygonStipple
#undef glGetString
#undef glGetTexEnvfv
#undef glGetTexEnviv
#undef glGetTexGendv
#undef glGetTexGenfv
#undef glGetTexGeniv
#undef glGetTexImage
#undef glGetTexLevelParameterfv
#undef glGetTexLevelParameteriv
#undef glGetTexParameterfv
#undef glGetTexParameteriv
#undef glHint
#undef glIndexMask
#undef glIndexPointer
#undef glIndexd
#undef glIndexdv
#undef glIndexf
#undef glIndexfv
#undef glIndexi
#undef glIndexiv
#undef glIndexs
#undef glIndexsv
#undef glIndexub
#undef glIndexubv
#undef glInitNames
#undef glInterleavedArrays
#undef glIsEnabled
#undef glIsList
#undef glIsTexture
#undef glLightModelf
#undef glLightModelfv
#undef glLightModeli
#undef glLightModeliv
#undef glLightf
#undef glLightfv
#undef glLighti
#undef glLightiv
#undef glLineStipple
#undef glLineWidth
#undef glListBase
#undef glLoadIdentity
#undef glLoadMatrixd
#undef glLoadMatrixf
#undef glLoadName
#undef glLogicOp
#undef glMap1d
#undef glMap1f
#undef glMap2d
#undef glMap2f
#undef glMapGrid1d
#undef glMapGrid1f
#undef glMapGrid2d
#undef glMapGrid2f
#undef glMaterialf
#undef glMaterialfv
#undef glMateriali
#undef glMaterialiv
#undef glMatrixMode
#undef glMultMatrixd
#undef glMultMatrixf
#undef glNewList
#undef glNormal3b
#undef glNormal3bv
#undef glNormal3d
#undef glNormal3dv
#undef glNormal3f
#undef glNormal3fv
#undef glNormal3i
#undef glNormal3iv
#undef glNormal3s
#undef glNormal3sv
#undef glNormalPointer
#undef glOrtho
#undef glPassThrough
#undef glPixelMapfv
#undef glPixelMapuiv
#undef glPixelMapusv
#undef glPixelStoref
#undef glPixelStorei
#undef glPixelTransferf
#undef glPixelTransferi
#undef glPixelZoom
#undef glPointSize
#undef glPolygonMode
#undef glPolygonOffset
#undef glPolygonStipple
#undef glPopAttrib
#undef glPopClientAttrib
#undef glPopMatrix
#undef glPopName
#undef glPrioritizeTextures
#undef glPushAttrib
#undef glPushClientAttrib
#undef glPushMatrix
#undef glPushName
#undef glRasterPos2d
#undef glRasterPos2dv
#undef glRasterPos2f
#undef glRasterPos2fv
#undef glRasterPos2i
#undef glRasterPos2iv
#undef glRasterPos2s
#undef glRasterPos2sv
#undef glRasterPos3d
#undef glRasterPos3dv
#undef glRasterPos3f
#undef glRasterPos3fv
#undef glRasterPos3i
#undef glRasterPos3iv
#undef glRasterPos3s
#undef glRasterPos3sv
#undef glRasterPos4d
#undef glRasterPos4dv
#undef glRasterPos4f
#undef glRasterPos4fv
#undef glRasterPos4i
#undef glRasterPos4iv
#undef glRasterPos4s
#undef glRasterPos4sv
#undef glReadBuffer
#undef glReadPixels
#undef glRectd
#undef glRectdv
#undef glRectf
#undef glRectfv
#undef glRecti
#undef glRectiv
#undef glRects
#undef glRectsv
#undef glRenderMode
#undef glRotated
#undef glRotatef
#undef glScaled
#undef glScalef
#undef glScissor
#undef glSelectBuffer
#undef glShadeModel
#undef glStencilFunc
#undef glStencilMask
#undef glStencilOp
#undef glTexCoord1d
#undef glTexCoord1dv
#undef glTexCoord1f
#undef glTexCoord1fv
#undef glTexCoord1i
#undef glTexCoord1iv
#undef glTexCoord1s
#undef glTexCoord1sv
#undef glTexCoord2d
#undef glTexCoord2dv
#undef glTexCoord2f
#undef glTexCoord2fv
#undef glTexCoord2i
#undef glTexCoord2iv
#undef glTexCoord2s
#undef glTexCoord2sv
#undef glTexCoord3d
#undef glTexCoord3dv
#undef glTexCoord3f
#undef glTexCoord3fv
#undef glTexCoord3i
#undef glTexCoord3iv
#undef glTexCoord3s
#undef glTexCoord3sv
#undef glTexCoord4d
#undef glTexCoord4dv
#undef glTexCoord4f
#undef glTexCoord4fv
#undef glTexCoord4i
#undef glTexCoord4iv
#undef glTexCoord4s
#undef glTexCoord4sv
#undef glTexCoordPointer
#undef glTexEnvf
#undef glTexEnvfv
#undef glTexEnvi
#undef glTexEnviv
#undef glTexGend
#undef glTexGendv
#undef glTexGenf
#undef glTexGenfv
#undef glTexGeni
#undef glTexGeniv
#undef glTexImage1D
#undef glTexImage2D
#undef glTexParameterf
#undef glTexParameterfv
#undef glTexParameteri
#undef glTexParameteriv
#undef glTexSubImage1D
#undef glTexSubImage2D
#undef glTranslated
#undef glTranslatef
#undef glVertex2d
#undef glVertex2dv
#undef glVertex2f
#undef glVertex2fv
#undef glVertex2i
#undef glVertex2iv
#undef glVertex2s
#undef glVertex2sv
#undef glVertex3d
#undef glVertex3dv
#undef glVertex3f
#undef glVertex3fv
#undef glVertex3i
#undef glVertex3iv
#undef glVertex3s
#undef glVertex3sv
#undef glVertex4d
#undef glVertex4dv
#undef glVertex4f
#undef glVertex4fv
#undef glVertex4i
#undef glVertex4iv
#undef glVertex4s
#undef glVertex4sv
#undef glVertexPointer
#undef glViewport

extern "C"
{
	OPENGL_EXTERN void OPENGL_STDCALL glAccum(GLenum, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glAlphaFunc(GLenum, GLclampf);
	OPENGL_EXTERN GLboolean OPENGL_STDCALL glAreTexturesResident(GLsizei, const GLuint*, GLboolean*);
	OPENGL_EXTERN void OPENGL_STDCALL glArrayElement(GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glBegin(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glBindTexture(GLenum, GLuint);
	OPENGL_EXTERN void OPENGL_STDCALL glBitmap(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte*);
	OPENGL_EXTERN void OPENGL_STDCALL glBlendFunc(GLenum, GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glCallList(GLuint);
	OPENGL_EXTERN void OPENGL_STDCALL glCallLists(GLsizei, GLenum, const GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glClear(GLbitfield);
	OPENGL_EXTERN void OPENGL_STDCALL glClearAccum(GLfloat, GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glClearColor(GLclampf, GLclampf, GLclampf, GLclampf);
	OPENGL_EXTERN void OPENGL_STDCALL glClearDepth(GLclampd);
	OPENGL_EXTERN void OPENGL_STDCALL glClearIndex(GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glClearStencil(GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glClipPlane(GLenum, const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3b(GLbyte, GLbyte, GLbyte);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3bv(const GLbyte*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3d(GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3f(GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3i(GLint, GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3iv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3s(GLshort, GLshort, GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3sv(const GLshort*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3ub(GLubyte, GLubyte, GLubyte);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3ubv(const GLubyte*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3ui(GLuint, GLuint, GLuint);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3uiv(const GLuint*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3us(GLushort, GLushort, GLushort);
	OPENGL_EXTERN void OPENGL_STDCALL glColor3usv(const GLushort*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4b(GLbyte, GLbyte, GLbyte, GLbyte);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4bv(const GLbyte*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4d(GLdouble, GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4f(GLfloat, GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4i(GLint, GLint, GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4iv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4s(GLshort, GLshort, GLshort, GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4sv(const GLshort*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4ub(GLubyte, GLubyte, GLubyte, GLubyte);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4ubv(const GLubyte*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4ui(GLuint, GLuint, GLuint, GLuint);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4uiv(const GLuint*);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4us(GLushort, GLushort, GLushort, GLushort);
	OPENGL_EXTERN void OPENGL_STDCALL glColor4usv(const GLushort*);
	OPENGL_EXTERN void OPENGL_STDCALL glColorMask(GLboolean, GLboolean, GLboolean, GLboolean);
	OPENGL_EXTERN void OPENGL_STDCALL glColorMaterial(GLenum, GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glColorPointer(GLint, GLenum, GLsizei, const GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glCopyPixels(GLint, GLint, GLsizei, GLsizei, GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glCopyTexImage1D(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glCopyTexImage2D(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glCopyTexSubImage1D(GLenum, GLint, GLint, GLint, GLint, GLsizei);
	OPENGL_EXTERN void OPENGL_STDCALL glCopyTexSubImage2D(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	OPENGL_EXTERN void OPENGL_STDCALL glCullFace(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glDeleteLists(GLuint, GLsizei);
	OPENGL_EXTERN void OPENGL_STDCALL glDeleteTextures(GLsizei, const GLuint*);
	OPENGL_EXTERN void OPENGL_STDCALL glDepthFunc(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glDepthMask(GLboolean);
	OPENGL_EXTERN void OPENGL_STDCALL glDepthRange(GLclampd, GLclampd);
	OPENGL_EXTERN void OPENGL_STDCALL glDisable(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glDisableClientState(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glDrawArrays(GLenum, GLint, GLsizei);
	OPENGL_EXTERN void OPENGL_STDCALL glDrawBuffer(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glDrawElements(GLenum, GLsizei, GLenum, const GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glDrawPixels(GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glEdgeFlag(GLboolean);
	OPENGL_EXTERN void OPENGL_STDCALL glEdgeFlagPointer(GLsizei, const GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glEdgeFlagv(const GLboolean*);
	OPENGL_EXTERN void OPENGL_STDCALL glEnable(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glEnableClientState(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glEnd(void);
	OPENGL_EXTERN void OPENGL_STDCALL glEndList(void);
	OPENGL_EXTERN void OPENGL_STDCALL glEvalCoord1d(GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glEvalCoord1dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glEvalCoord1f(GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glEvalCoord1fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glEvalCoord2d(GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glEvalCoord2dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glEvalCoord2f(GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glEvalCoord2fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glEvalMesh1(GLenum, GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glEvalMesh2(GLenum, GLint, GLint, GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glEvalPoint1(GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glEvalPoint2(GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glFeedbackBuffer(GLsizei, GLenum, GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glFinish(void);
	OPENGL_EXTERN void OPENGL_STDCALL glFlush(void);
	OPENGL_EXTERN void OPENGL_STDCALL glFogf(GLenum, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glFogfv(GLenum, const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glFogi(GLenum, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glFogiv(GLenum, const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glFrontFace(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glFrustum(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN GLuint OPENGL_STDCALL glGenLists(GLsizei);
	OPENGL_EXTERN void OPENGL_STDCALL glGenTextures(GLsizei, GLuint*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetBooleanv(GLenum, GLboolean*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetClipPlane(GLenum, GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetDoublev(GLenum, GLdouble*);
	OPENGL_EXTERN GLenum OPENGL_STDCALL glGetError(void);
	OPENGL_EXTERN void OPENGL_STDCALL glGetFloatv(GLenum, GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetIntegerv(GLenum, GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetLightfv(GLenum, GLenum, GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetLightiv(GLenum, GLenum, GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetMapdv(GLenum, GLenum, GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetMapfv(GLenum, GLenum, GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetMapiv(GLenum, GLenum, GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetMaterialfv(GLenum, GLenum, GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetMaterialiv(GLenum, GLenum, GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetPixelMapfv(GLenum, GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetPixelMapuiv(GLenum, GLuint*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetPixelMapusv(GLenum, GLushort*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetPointerv(GLenum, GLvoid**);
	OPENGL_EXTERN void OPENGL_STDCALL glGetPolygonStipple(GLubyte*);
	OPENGL_EXTERN const GLubyte* OPENGL_STDCALL glGetString(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glGetTexEnvfv(GLenum, GLenum, GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetTexEnviv(GLenum, GLenum, GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetTexGendv(GLenum, GLenum, GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetTexGenfv(GLenum, GLenum, GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetTexGeniv(GLenum, GLenum, GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetTexImage(GLenum, GLint, GLenum, GLenum, GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetTexLevelParameterfv(GLenum, GLint, GLenum, GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetTexLevelParameteriv(GLenum, GLint, GLenum, GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetTexParameterfv(GLenum, GLenum, GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glGetTexParameteriv(GLenum, GLenum, GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glHint(GLenum, GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glIndexMask(GLuint);
	OPENGL_EXTERN void OPENGL_STDCALL glIndexPointer(GLenum, GLsizei, const GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glIndexd(GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glIndexdv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glIndexf(GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glIndexfv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glIndexi(GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glIndexiv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glIndexs(GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glIndexsv(const GLshort*);
	OPENGL_EXTERN void OPENGL_STDCALL glIndexub(GLubyte);
	OPENGL_EXTERN void OPENGL_STDCALL glIndexubv(const GLubyte*);
	OPENGL_EXTERN void OPENGL_STDCALL glInitNames(void);
	OPENGL_EXTERN void OPENGL_STDCALL glInterleavedArrays(GLenum, GLsizei, const GLvoid*);
	OPENGL_EXTERN GLboolean OPENGL_STDCALL glIsEnabled(GLenum);
	OPENGL_EXTERN GLboolean OPENGL_STDCALL glIsList(GLuint);
	OPENGL_EXTERN GLboolean OPENGL_STDCALL glIsTexture(GLuint);
	OPENGL_EXTERN void OPENGL_STDCALL glLightModelf(GLenum, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glLightModelfv(GLenum, const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glLightModeli(GLenum, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glLightModeliv(GLenum, const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glLightf(GLenum, GLenum, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glLightfv(GLenum, GLenum, const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glLighti(GLenum, GLenum, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glLightiv(GLenum, GLenum, const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glLineStipple(GLint, GLushort);
	OPENGL_EXTERN void OPENGL_STDCALL glLineWidth(GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glListBase(GLuint);
	OPENGL_EXTERN void OPENGL_STDCALL glLoadIdentity(void);
	OPENGL_EXTERN void OPENGL_STDCALL glLoadMatrixd(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glLoadMatrixf(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glLoadName(GLuint);
	OPENGL_EXTERN void OPENGL_STDCALL glLogicOp(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glMap1d(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glMap1f(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glMap2d(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glMap2f(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glMapGrid1d(GLint, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glMapGrid1f(GLint, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glMapGrid2d(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glMapGrid2f(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glMaterialf(GLenum, GLenum, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glMaterialfv(GLenum, GLenum, const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glMateriali(GLenum, GLenum, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glMaterialiv(GLenum, GLenum, const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glMatrixMode(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glMultMatrixd(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glMultMatrixf(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glNewList(GLuint, GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glNormal3b(GLbyte, GLbyte, GLbyte);
	OPENGL_EXTERN void OPENGL_STDCALL glNormal3bv(const GLbyte*);
	OPENGL_EXTERN void OPENGL_STDCALL glNormal3d(GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glNormal3dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glNormal3f(GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glNormal3fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glNormal3i(GLint, GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glNormal3iv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glNormal3s(GLshort, GLshort, GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glNormal3sv(const GLshort*);
	OPENGL_EXTERN void OPENGL_STDCALL glNormalPointer(GLenum, GLsizei, const GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glOrtho(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glPassThrough(GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glPixelMapfv(GLenum, GLsizei, const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glPixelMapuiv(GLenum, GLsizei, const GLuint*);
	OPENGL_EXTERN void OPENGL_STDCALL glPixelMapusv(GLenum, GLsizei, const GLushort*);
	OPENGL_EXTERN void OPENGL_STDCALL glPixelStoref(GLenum, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glPixelStorei(GLenum, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glPixelTransferf(GLenum, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glPixelTransferi(GLenum, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glPixelZoom(GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glPointSize(GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glPolygonMode(GLenum, GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glPolygonOffset(GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glPolygonStipple(const GLubyte*);
	OPENGL_EXTERN void OPENGL_STDCALL glPopAttrib(void);
	OPENGL_EXTERN void OPENGL_STDCALL glPopClientAttrib(void);
	OPENGL_EXTERN void OPENGL_STDCALL glPopMatrix(void);
	OPENGL_EXTERN void OPENGL_STDCALL glPopName(void);
	OPENGL_EXTERN void OPENGL_STDCALL glPrioritizeTextures(GLsizei, const GLuint*, const GLclampf*);
	OPENGL_EXTERN void OPENGL_STDCALL glPushAttrib(GLbitfield);
	OPENGL_EXTERN void OPENGL_STDCALL glPushClientAttrib(GLbitfield);
	OPENGL_EXTERN void OPENGL_STDCALL glPushMatrix(void);
	OPENGL_EXTERN void OPENGL_STDCALL glPushName(GLuint);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos2d(GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos2dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos2f(GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos2fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos2i(GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos2iv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos2s(GLshort, GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos2sv(const GLshort *);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos3d(GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos3dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos3f(GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos3fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos3i(GLint, GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos3iv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos3s(GLshort, GLshort, GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos3sv(const GLshort*);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos4d(GLdouble, GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos4dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos4f(GLfloat, GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos4fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos4i(GLint, GLint, GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos4iv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos4s(GLshort, GLshort, GLshort, GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glRasterPos4sv(const GLshort*);
	OPENGL_EXTERN void OPENGL_STDCALL glReadBuffer(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glReadPixels(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glRectd(GLdouble, GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glRectdv(const GLdouble*, const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glRectf(GLfloat, GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glRectfv(const GLfloat*, const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glRecti(GLint, GLint, GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glRectiv(const GLint*, const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glRects(GLshort, GLshort, GLshort, GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glRectsv(const GLshort*, const GLshort*);
	OPENGL_EXTERN GLint OPENGL_STDCALL glRenderMode(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glRotated(GLdouble, GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glRotatef(GLfloat, GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glScaled(GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glScalef(GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glScissor(GLint, GLint, GLsizei, GLsizei);
	OPENGL_EXTERN void OPENGL_STDCALL glSelectBuffer(GLsizei, GLuint*);
	OPENGL_EXTERN void OPENGL_STDCALL glShadeModel(GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glStencilFunc(GLenum, GLint, GLuint);
	OPENGL_EXTERN void OPENGL_STDCALL glStencilMask(GLuint);
	OPENGL_EXTERN void OPENGL_STDCALL glStencilOp(GLenum, GLenum, GLenum);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord1d(GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord1dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord1f(GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord1fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord1i(GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord1iv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord1s(GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord1sv(const GLshort*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord2d(GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord2dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord2f(GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord2fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord2i(GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord2iv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord2s(GLshort, GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord2sv(const GLshort*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord3d(GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord3dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord3f(GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord3fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord3i(GLint, GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord3iv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord3s(GLshort, GLshort, GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord3sv(const GLshort*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord4d(GLdouble, GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord4dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord4f(GLfloat, GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord4fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord4i(GLint, GLint, GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord4iv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord4s(GLshort, GLshort, GLshort, GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoord4sv(const GLshort*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexCoordPointer(GLint, GLenum, GLsizei, const GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexEnvf(GLenum, GLenum, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glTexEnvfv(GLenum, GLenum, const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexEnvi(GLenum, GLenum, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glTexEnviv(GLenum, GLenum, const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexGend(GLenum, GLenum, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glTexGendv(GLenum, GLenum, const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexGenf(GLenum, GLenum, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glTexGenfv(GLenum, GLenum, const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexGeni(GLenum, GLenum, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glTexGeniv(GLenum, GLenum, const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexImage1D(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexImage2D(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexParameterf(GLenum, GLenum, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glTexParameterfv(GLenum, GLenum, const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexParameteri(GLenum, GLenum, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glTexParameteriv(GLenum, GLenum, const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexSubImage1D(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glTexSubImage2D(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glTranslated(GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glTranslatef(GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex2d(GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex2dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex2f(GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex2fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex2i(GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex2iv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex2s(GLshort, GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex2sv(const GLshort*);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex3d(GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex3dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex3f(GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex3fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex3i(GLint, GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex3iv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex3s(GLshort, GLshort, GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex3sv(const GLshort*);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex4d(GLdouble, GLdouble, GLdouble, GLdouble);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex4dv(const GLdouble*);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex4f(GLfloat, GLfloat, GLfloat, GLfloat);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex4fv(const GLfloat*);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex4i(GLint, GLint, GLint, GLint);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex4iv(const GLint*);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex4s(GLshort, GLshort, GLshort, GLshort);
	OPENGL_EXTERN void OPENGL_STDCALL glVertex4sv(const GLshort*);
	OPENGL_EXTERN void OPENGL_STDCALL glVertexPointer(GLint, GLenum, GLsizei, const GLvoid*);
	OPENGL_EXTERN void OPENGL_STDCALL glViewport(GLint, GLint, GLsizei, GLsizei);
}  // extern "C"

void System
	::GLAccum(GLenum operation, GLfloat value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glAccum, operation, value);
}

void System
	::GLAlphaFunc(GLenum function, GLclampf reference) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glAlphaFunc, function, reference);
}

GLboolean System
	::GLAreTexturesResident(GLsizei numTextures, const GLuint* textures, GLboolean* residences) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3_RESULT(glAreTexturesResident, numTextures, textures, residences, GLboolean);
}

void System
	::GLArrayElement(GLint i) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glArrayElement, i);
}

void System
	::GLBegin(GLenum mode) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glBegin, mode);
}

void System
	::GLBindTexture(GLenum target, GLuint texture) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glBindTexture, target, texture);
}

void System
	::GLBitmap(GLsizei width, GLsizei height, GLfloat xOrigin, GLfloat yOrigin, GLfloat xMove, GLfloat yMove, const GLubyte* bitmap) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_7(glBitmap, width, height, xOrigin, yOrigin, xMove, yMove, bitmap);
}

void System
	::GLBlendFunc(GLenum srcFunction, GLenum dstFunction) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glBlendFunc, srcFunction, dstFunction);
}

void System
	::GLCallList(GLuint callList) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glCallList, callList);
}

void System
	::GLCallLists(GLsizei numLists, GLenum type, const GLvoid* listsPtr) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glCallLists, numLists, type, listsPtr);
}

void System
	::GLClear(GLbitfield mask) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glClear, mask);
}

void System
	::GLClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glClearAccum, red, green, blue, alpha);
}

void System
	::GLClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glClearColor, red, green, blue, alpha);
}

void System
	::GLClearDepth(GLclampd depth) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glClearDepth, depth);
}

void System
	::GLClearIndex(GLfloat index) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glClearIndex, index);
}

void System
	::GLClearStencil(GLint stencil) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glClearStencil, stencil);
}

void System
	::GLClipPlane(GLenum plane, const GLdouble* equation) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glClipPlane, plane, equation);
}

void System
	::GLColor3b(GLbyte red, GLbyte green, GLbyte blue) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glColor3b, red, green, blue);
}

void System
	::GLColor3bv(const GLbyte* rgb) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor3bv, rgb);
}

void System
	::GLColor3d(GLdouble red, GLdouble green, GLdouble blue) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glColor3d, red, green, blue);
}

void System
	::GLColor3dv(const GLdouble* rgb) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor3dv, rgb);
}

void System
	::GLColor3f(GLfloat red, GLfloat green, GLfloat blue) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glColor3f, red, green, blue);
}

void System
	::GLColor3fv(const GLfloat* rgb) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor3fv, rgb);
}

void System
	::GLColor3i(GLint red, GLint green, GLint blue) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glColor3i, red, green, blue);
}

void System
	::GLColor3iv(const GLint* rgb) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor3iv, rgb);
}

void System
	::GLColor3s(GLshort red, GLshort green, GLshort blue) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glColor3s, red, green, blue);
}

void System
	::GLColor3sv(const GLshort* asColor) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor3sv, asColor);
}

void System
	::GLColor3ub(GLubyte red, GLubyte green, GLubyte blue) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glColor3ub, red, green, blue);
}

void System
	::GLColor3ubv(const GLubyte* rgb) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor3ubv, rgb);
}

void System
	::GLColor3ui(GLuint red, GLuint green, GLuint blue) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glColor3ui, red, green, blue);
}

void System
	::GLColor3uiv(const GLuint* rgb) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor3uiv, rgb);
}

void System
	::GLColor3us(GLushort red, GLushort green, GLushort blue) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glColor3us, red, green, blue);
}

void System
	::GLColor3usv(const GLushort* rgb) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor3usv, rgb);
}

void System
	::GLColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glColor4b, red, green, blue, alpha);
}

void System
	::GLColor4bv(const GLbyte* rgba) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor4bv, rgba);
}

void System
	::GLColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glColor4d, red, green, blue, alpha);
}

void System
	::GLColor4dv(const GLdouble* rgba) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor4dv, rgba);
}

void System
	::GLColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glColor4f, red, green, blue, alpha);
}

void System
	::GLColor4fv(const GLfloat* rgba) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor4fv, rgba);
}

void System
	::GLColor4i(GLint red, GLint green, GLint blue, GLint alpha) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glColor4i, red, green, blue, alpha);
}

void System
	::GLColor4iv(const GLint* rgba) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor4iv, rgba);
}

void System
	::GLColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glColor4s, red, green, blue, alpha);
}

void System
	::GLColor4sv(const GLshort* rgba) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor4sv, rgba);
}

void System
	::GLColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glColor4ub, red, green, blue, alpha);
}

void System
	::GLColor4ubv(const GLubyte* rgba) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor4ubv, rgba);
}

void System
	::GLColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glColor4ui, red, green, blue, alpha);
}

void System
	::GLColor4uiv(const GLuint* rgba) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor4uiv, rgba);
}

void System
	::GLColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glColor4us, red, green, blue, alpha);
}

void System
	::GLColor4usv(const GLushort* rgba) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glColor4usv, rgba);
}

void System
	::GLColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glColorMask, red, green, blue, alpha);
}

void System
	::GLColorMaterial(GLenum face, GLenum mode) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glColorMaterial, face, mode);
}

void System
	::GLColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glColorPointer, size, type, stride, pointer);
}

void System
	::GLCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_5(glCopyPixels, x, y, width, height, type);
}

void System
	::GLCopyTexImage1D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_7(glCopyTexImage1D, target, level, internalFormat, x, y, width, border);
}

void System
	::GLCopyTexImage2D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_8(glCopyTexImage2D, target, level, internalFormat, x, y, width, height, border);
}

void System
	::GLCopyTexSubImage1D(GLenum target, GLint level, GLint xOffset, GLint x, GLint y, GLsizei width) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_6(glCopyTexSubImage1D, target, level, xOffset, x, y, width);
}

void System
	::GLCopyTexSubImage2D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_8(glCopyTexSubImage2D, target, level, xOffset, yOffset, x, y, width, height);
}

void System
	::GLCullFace(GLenum mode) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glCullFace, mode);
}

void System
	::GLDeleteLists(GLuint callList, GLsizei range) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glDeleteLists, callList, range);
}

void System
	::GLDeleteTextures(GLsizei numTextures, const GLuint* textures) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glDeleteTextures, numTextures, textures);
}

void System
	::GLDepthFunc(GLenum function) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glDepthFunc, function);
}

void System
	::GLDepthMask(GLboolean mask) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glDepthMask, mask);
}

void System
	::GLDepthRange(GLclampd near, GLclampd far) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glDepthRange, near, far);
}

void System
	::GLDisable(GLenum capability) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glDisable, capability);
}

void System
	::GLDisableClientState(GLenum glArray) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glDisableClientState, glArray);
}

void System
	::GLDrawArrays(GLenum mode, GLint first, GLsizei count) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glDrawArrays, mode, first, count);
}

void System
	::GLDrawBuffer(GLenum mode) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glDrawBuffer, mode);
}

void System
	::GLDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glDrawElements, mode, count, type, indices);
}

void System
	::GLDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_5(glDrawPixels, width, height, format, type, pixels);
}

void System
	::GLEdgeFlag(GLboolean flag) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glEdgeFlag, flag);
}

void System
	::GLEdgeFlagv(const GLboolean* flag) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glEdgeFlagv, flag);
}

void System
	::GLEdgeFlagPointer(GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glEdgeFlagPointer, stride, pointer);
}

void System
	::GLEnable(GLenum capability) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glEnable, capability);
}

void System
	::GLEnableClientState(GLenum glArray) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glEnableClientState, glArray);
}

void System
	::GLEnd() noexcept
{
	SYSTEM_PREVIOUSLY_BODY_0(glEnd);
}

void System
	::GLEndList() noexcept
{
	SYSTEM_PREVIOUSLY_BODY_0(glEndList);
}

void System
	::GLEvalCoord1f(GLfloat u) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glEvalCoord1f, u);
}

void System
	::GLEvalCoord1fv(const GLfloat* u) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glEvalCoord1fv, u);
}

void System
	::GLEvalCoord1d(GLdouble u) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glEvalCoord1d, u);
}

void System
	::GLEvalCoord1dv(const GLdouble* u) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glEvalCoord1dv, u);
}

void System
	::GLEvalCoord2f(GLfloat u, GLfloat v) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glEvalCoord2f, u, v);
}

void System
	::GLEvalCoord2fv(const GLfloat* v) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glEvalCoord2fv, v);
}

void System
	::GLEvalCoord2d(GLdouble u, GLdouble v) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glEvalCoord2d, u, v);
}

void System
	::GLEvalCoord2dv(const GLdouble* v) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glEvalCoord2dv, v);
}

void System
	::GLEvalMesh1(GLenum mode, GLint i1, GLint i2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glEvalMesh1, mode, i1, i2);
}

void System
	::GLEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_5(glEvalMesh2, mode, i1, i2, j1, j2);
}

void System
	::GLEvalPoint1(GLint i) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glEvalPoint1, i);
}

void System
	::GLEvalPoint2(GLint i, GLint j) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glEvalPoint2, i, j);
}

void System
	::GLFeedbackBuffer(GLsizei size, GLenum type, GLfloat* buffer) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glFeedbackBuffer, size, type, buffer);
}

void System
	::GLFinish() noexcept
{
	SYSTEM_PREVIOUSLY_BODY_0(glFinish);
}

void System
	::GLFlush() noexcept
{
	SYSTEM_PREVIOUSLY_BODY_0(glFlush);
}

void System
	::GLFogf(GLenum name, GLfloat param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glFogf, name, param);
}

void System
	::GLFogfv(GLenum name, const GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glFogfv, name, param);
}

void System
	::GLFogi(GLenum name, GLint param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glFogi, name, param);
}

void System
	::GLFogiv(GLenum name, const GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glFogiv, name, param);
}

void System
	::GLFrontFace(GLenum mode) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glFrontFace, mode);
}

void System
	::GLFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_6(glFrustum, left, right, bottom, top, near, far);
}

GLuint System
	::GLGenLists(GLsizei range) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1_RESULT(glGenLists, range, GLuint);
}

void System
	::GLGenTextures(GLsizei numTextures, GLuint* texture) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glGenTextures, numTextures, texture);
}

void System
	::GLGetBooleanv(GLenum name, GLboolean* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glGetBooleanv, name, param);
}

void System
	::GLGetClipPlane(GLenum plane, GLdouble* equation) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glGetClipPlane, plane, equation);
}

void System
	::GLGetDoublev(GLenum name, GLdouble* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glGetDoublev, name, param);
}

GLenum System
	::GLGetError() noexcept
{
	return glGetError();
}

void System
	::GLGetFloatv(GLenum name, GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glGetFloatv, name, param);
}

void System
	::GLGetIntegerv(GLenum name, GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glGetIntegerv, name, param);
}

void System
	::GLGetLightfv(GLenum light, GLenum name, GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetLightfv, light, name, param);
}

void System
	::GLGetLightiv(GLenum light, GLenum name, GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetLightiv, light, name, param);
}

void System
	::GLGetMapdv(GLenum target, GLenum query, GLdouble* value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetMapdv, target, query, value);
}

void System
	::GLGetMapfv(GLenum target, GLenum query, GLfloat* value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetMapfv, target, query, value);
}

void System
	::GLGetMapiv(GLenum target, GLenum query, GLint* value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetMapiv, target, query, value);
}

void System
	::GLGetMaterialfv(GLenum face, GLenum name, GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetMaterialfv, face, name, param);
}

void System
	::GLGetMaterialiv(GLenum face, GLenum name, GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetMaterialiv, face, name, param);
}

void System
	::GLGetPixelMapfv(GLenum pixelMap, GLfloat* value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glGetPixelMapfv, pixelMap, value);
}

void System
	::GLGetPixelMapuiv(GLenum pixelMap, GLuint* value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glGetPixelMapuiv, pixelMap, value);
}

void System
	::GLGetPixelMapusv(GLenum pixelMap, GLushort* value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glGetPixelMapusv, pixelMap, value);
}

void System
	::GLGetPointerv(GLenum name, GLvoid** param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glGetPointerv, name, param);
}

void System
	::GLGetPolygonStipple(GLubyte* pattern) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glGetPolygonStipple, pattern);
}

const GLubyte* System
	::GLGetString(GLenum name) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1_RESULT(glGetString, name, const GLubyte*);
}

void System
	::GLGetTexEnvfv(GLenum target, GLenum name, GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetTexEnvfv, target, name, param);
}

void System
	::GLGetTexEnviv(GLenum target, GLenum name, GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetTexEnviv, target, name, param);
}

void System
	::GLGetTexGendv(GLenum coord, GLenum name, GLdouble* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetTexGendv, coord, name, param);
}

void System
	::GLGetTexGenfv(GLenum coord, GLenum name, GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetTexGenfv, coord, name, param);
}

void System
	::GLGetTexGeniv(GLenum coord, GLenum name, GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetTexGeniv, coord, name, param);
}

void System
	::GLGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid* pixels) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_5(glGetTexImage, target, level, format, type, pixels);
}

void System
	::GLGetTexLevelParameterfv(GLenum target, GLint level, GLenum name, GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glGetTexLevelParameterfv, target, level, name, param);
}

void System
	::GLGetTexLevelParameteriv(GLenum target, GLint level, GLenum name, GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glGetTexLevelParameteriv, target, level, name, param);
}

void System
	::GLGetTexParameterfv(GLenum target, GLenum name, GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetTexParameterfv, target, name, param);
}

void System
	::GLGetTexParameteriv(GLenum target, GLenum name, GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glGetTexParameteriv, target, name, param);
}

void System
	::GLHint(GLenum target, GLenum mode) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glHint, target, mode);
}

void System
	::GLIndexMask(GLuint mask) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glIndexMask, mask);
}

void System
	::GLIndexPointer(GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glIndexPointer, type, stride, pointer);
}

void System
	::GLIndexd(GLdouble index) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glIndexd, index);
}

void System
	::GLIndexdv(const GLdouble* index) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glIndexdv, index);
}

void System
	::GLIndexf(GLfloat index) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glIndexf, index);
}

void System
	::GLIndexfv(const GLfloat* index) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glIndexfv, index);
}

void System
	::GLIndexi(GLint index) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glIndexi, index);
}

void System
	::GLIndexiv(const GLint* index) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glIndexiv, index);
}

void System
	::GLIndexs(GLshort index) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glIndexs, index);
}

void System
	::GLIndexsv(const GLshort* index) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glIndexsv, index);
}

void System
	::GLIndexub(GLubyte index) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glIndexub, index);
}

void System
	::GLIndexubv(const GLubyte* index) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glIndexubv, index);
}

void System
	::GLInitNames() noexcept
{
	SYSTEM_PREVIOUSLY_BODY_0(glInitNames);
}

void System
	::GLInterleavedArrays(GLenum format, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glInterleavedArrays, format, stride, pointer);
}

GLboolean System
	::GLIsEnabled(GLenum capability) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1_RESULT(glIsEnabled, capability, GLboolean);
}

GLboolean System
	::GLIsList(GLuint callList) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1_RESULT(glIsList, callList, GLboolean);
}

GLboolean System
	::GLIsTexture(GLuint texture) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1_RESULT(glIsTexture, texture, GLboolean);
}

void System
	::GLLightModelf(GLenum name, GLfloat param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glLightModelf, name, param);
}

void System
	::GLLightModelfv(GLenum name, const GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glLightModelfv, name, param);
}

void System
	::GLLightModeli(GLenum name, GLint param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glLightModeli, name, param);
}

void System
	::GLLightModeliv(GLenum name, const GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glLightModeliv, name, param);
}

void System
	::GLLightf(GLenum light, GLenum name, GLfloat param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glLightf, light, name, param);
}

void System
	::GLLightfv(GLenum light, GLenum name, const GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glLightfv, light, name, param);
}

void System
	::GLLighti(GLenum light, GLenum name, GLint param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glLighti, light, name, param);
}

void System
	::GLLightiv(GLenum light, GLenum name, const GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glLightiv, light, name, param);
}

void System
	::GLLineStipple(GLint factor, GLushort pattern) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glLineStipple, factor, pattern);
}

void System
	::GLLineWidth(GLfloat width) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glLineWidth, width);
}

void System
	::GLListBase(GLuint base) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glListBase, base);
}

void System
	::GLLoadIdentity() noexcept
{
	SYSTEM_PREVIOUSLY_BODY_0(glLoadIdentity);
}

void System
	::GLLoadMatrixd(const GLdouble* matrix) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glLoadMatrixd, matrix);
}

void System
	::GLLoadMatrixf(const GLfloat* matrix) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glLoadMatrixf, matrix);
}

void System
	::GLLoadName(GLuint name) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glLoadName, name);
}

void System
	::GLLogicOp(GLenum code) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glLogicOp, code);
}

void System
	::GLMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble* points) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_6(glMap1d, target, u1, u2, stride, order, points);
}

void System
	::GLMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat* points) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_6(glMap1f, target, u1, u2, stride, order, points);
}

void System
	::GLMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint uStride, GLint uOrder, GLdouble v1, GLdouble v2, GLint vStride, GLint vOrder, const GLdouble* points) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_10(glMap2d, target, u1, u2, uStride, uOrder, v1, v2, vStride, vOrder, points);
}

void System
	::GLMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint uStride, GLint uOrder, GLfloat v1, GLfloat v2, GLint vStride, GLint vOrder, const GLfloat* points) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_10(glMap2f, target, u1, u2, uStride, uOrder, v1, v2, vStride, vOrder, points);
}

void System
	::GLMapGrid1d(GLint numUPartitions, GLdouble u1, GLdouble u2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glMapGrid1d, numUPartitions, u1, u2);
}

void System
	::GLMapGrid1f(GLint numUPartitions, GLfloat u1, GLfloat u2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glMapGrid1f, numUPartitions, u1, u2);
}

void System
	::GLMapGrid2d(GLint numUPartitions, GLdouble u1, GLdouble u2, GLint numVPartitions, GLdouble v1, GLdouble v2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_6(glMapGrid2d, numUPartitions, u1, u2, numVPartitions, v1, v2);
}

void System
	::GLMapGrid2f(GLint numUPartitions, GLfloat u1, GLfloat u2, GLint numVPartitions, GLfloat v1, GLfloat v2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_6(glMapGrid2f, numUPartitions, u1, u2, numVPartitions, v1, v2);
}

void System
	::GLMaterialf(GLenum face, GLenum name, GLfloat param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glMaterialf, face, name, param);
}

void System
	::GLMaterialfv(GLenum face, GLenum name, const GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glMaterialfv, face, name, param);
}

void System
	::GLMateriali(GLenum face, GLenum name, GLint param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glMateriali, face, name, param);
}

void System
	::GLMaterialiv(GLenum face, GLenum name, const GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glMaterialiv, face, name, param);
}

void System
	::GLMatrixMode(GLenum mode) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glMatrixMode, mode);
}

void System
	::GLMultMatrixd(const GLdouble* matrix) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glMultMatrixd, matrix);
}

void System
	::GLMultMatrixf(const GLfloat* matrix) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glMultMatrixf, matrix);
}

void System
	::GLNewList(GLuint callList, GLenum mode) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glNewList, callList, mode);
}

void System
	::GLNormal3b(GLbyte bX, GLbyte bY, GLbyte bZ) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glNormal3b, bX, bY, bZ);
}

void System
	::GLNormal3bv(const GLbyte* abXYZ) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glNormal3bv, abXYZ);
}

void System
	::GLNormal3d(GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glNormal3d, x, y, z);
}

void System
	::GLNormal3dv(const GLdouble* xyz) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glNormal3dv, xyz);
}

void System
	::GLNormal3f(GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glNormal3f, x, y, z);
}

void System
	::GLNormal3fv(const GLfloat* xyz) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glNormal3fv, xyz);
}

void System
	::GLNormal3i(GLint x, GLint y, GLint z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glNormal3i, x, y, z);
}

void System
	::GLNormal3iv(const GLint* xyz) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glNormal3iv, xyz);
}

void System
	::GLNormal3s(GLshort x, GLshort y, GLshort z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glNormal3s, x, y, z);
}

void System
	::GLNormal3sv(const GLshort* xyz) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glNormal3sv, xyz);
}

void System
	::GLNormalPointer(GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glNormalPointer, type, stride, pointer);
}

void System
	::GLOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_6(glOrtho, left, right, bottom, top, near, far);
}

void System
	::GLPassThrough(GLfloat token) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glPassThrough, token);
}

void System
	::GLPixelMapfv(GLenum pixelMap, GLsizei size, const GLfloat* value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glPixelMapfv, pixelMap, size, value);
}

void System
	::GLPixelMapuiv(GLenum pixelMap, GLsizei size, const GLuint* value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glPixelMapuiv, pixelMap, size, value);
}

void System
	::GLPixelMapusv(GLenum pixelMap, GLsizei size, const GLushort* value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glPixelMapusv, pixelMap, size, value);
}

void System
	::GLPixelStoref(GLenum name, GLfloat value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glPixelStoref, name, value);
}

void System
	::GLPixelStorei(GLenum name, GLint value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glPixelStorei, name, value);
}

void System
	::GLPixelTransferf(GLenum name, GLfloat value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glPixelTransferf, name, value);
}

void System
	::GLPixelTransferi(GLenum name, GLint value) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glPixelTransferi, name, value);
}

void System
	::GLPixelZoom(GLfloat xFactor, GLfloat yFactor) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glPixelZoom, xFactor, yFactor);
}

void System
	::GLPointSize(GLfloat size) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glPointSize, size);
}

void System
	::GLPolygonMode(GLenum face, GLenum mode) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glPolygonMode, face, mode);
}

void System
	::GLPolygonOffset(GLfloat scale, GLfloat bias) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glPolygonOffset, scale, bias);
}

void System
	::GLPolygonStipple(const GLubyte* amask) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glPolygonStipple, amask);
}

void System
	::GLPopAttrib() noexcept
{
	SYSTEM_PREVIOUSLY_BODY_0(glPopAttrib);
}

void System
	::GLPopClientAttrib() noexcept
{
	SYSTEM_PREVIOUSLY_BODY_0(glPopClientAttrib);
}

void System
	::GLPopMatrix() noexcept
{
	SYSTEM_PREVIOUSLY_BODY_0(glPopMatrix);
}

void System
	::GLPopName() noexcept
{
	SYSTEM_PREVIOUSLY_BODY_0(glPopName);
}

void System
	::GLPrioritizeTextures(GLsizei numTextures, const GLuint* textures, const GLclampf* priorities) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glPrioritizeTextures, numTextures, textures, priorities);
}

void System
	::GLPushAttrib(GLbitfield mask) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glPushAttrib, mask);
}

void System
	::GLPushClientAttrib(GLbitfield mask) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glPushClientAttrib, mask);
}

void System
	::GLPushMatrix() noexcept
{
	SYSTEM_PREVIOUSLY_BODY_0(glPushMatrix);
}

void System
	::GLPushName(GLuint name) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glPushName, name);
}

void System
	::GLRasterPos2d(GLdouble x, GLdouble y) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glRasterPos2d, x, y);
}

void System
	::GLRasterPos2dv(const GLdouble* xy) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glRasterPos2dv, xy);
}

void System
	::GLRasterPos2f(GLfloat x, GLfloat y) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glRasterPos2f, x, y);
}

void System
	::GLRasterPos2fv(const GLfloat* xy) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glRasterPos2fv, xy);
}

void System
	::GLRasterPos2i(GLint x, GLint y) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glRasterPos2i, x, y);
}

void System
	::GLRasterPos2iv(const GLint* xy) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glRasterPos2iv, xy);
}

void System
	::GLRasterPos2s(GLshort x, GLshort y) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glRasterPos2s, x, y);
}

void System
	::GLRasterPos2sv(const GLshort* xy) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glRasterPos2sv, xy);
}

void System
	::GLRasterPos3d(GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glRasterPos3d, x, y, z);
}

void System
	::GLRasterPos3dv(const GLdouble* xyz) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glRasterPos3dv, xyz);
}

void System
	::GLRasterPos3f(GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glRasterPos3f, x, y, z);
}

void System
	::GLRasterPos3fv(const GLfloat* xyz) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glRasterPos3fv, xyz);
}

void System
	::GLRasterPos3i(GLint x, GLint y, GLint z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glRasterPos3i, x, y, z);
}

void System
	::GLRasterPos3iv(const GLint* xyz) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glRasterPos3iv, xyz);
}

void System
	::GLRasterPos3s(GLshort x, GLshort y, GLshort z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glRasterPos3s, x, y, z);
}

void System
	::GLRasterPos3sv(const GLshort* xyz) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glRasterPos3sv, xyz);
}

void System
	::GLRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glRasterPos4d, x, y, z, w);
}

void System
	::GLRasterPos4dv(const GLdouble* xyzw) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glRasterPos4dv, xyzw);
}

void System
	::GLRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glRasterPos4f, x, y, z, w);
}

void System
	::GLRasterPos4fv(const GLfloat* xyzw) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glRasterPos4fv, xyzw);
}

void System
	::GLRasterPos4i(GLint x, GLint y, GLint z, GLint w) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glRasterPos4i, x, y, z, w);
}

void System
	::GLRasterPos4iv(const GLint* xyzw) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glRasterPos4iv, xyzw);
}

void System
	::GLRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glRasterPos4s, x, y, z, w);
}

void System
	::GLRasterPos4sv(const GLshort* xyzw) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glRasterPos4sv, xyzw);
}

void System
	::GLReadBuffer(GLenum mode) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glReadBuffer, mode);
}

void System
	::GLReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_7(glReadPixels, x, y, width, height, format, type, pixels);
}

void System
	::GLRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glRectd, x1, y1, x2, y2);
}

void System
	::GLRectdv(const GLdouble* x1Y1, const GLdouble* x2Y2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glRectdv, x1Y1, x2Y2);
}

void System
	::GLRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glRectf, x1, y1, x2, y2);
}

void System
	::GLRectfv(const GLfloat* x1Y1, const GLfloat* x2Y2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glRectfv, x1Y1, x2Y2);
}

void System
	::GLRecti(GLint x1, GLint y1, GLint x2, GLint y2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glRecti, x1, y1, x2, y2);
}

void System
	::GLRectiv(const GLint* x1Y1, const GLint* x2Y2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glRectiv, x1Y1, x2Y2);
}

void System
	::GLRects(GLshort x1, GLshort y1, GLshort x2, GLshort sY2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glRects, x1, y1, x2, sY2);
}

void System
	::GLRectsv(const GLshort* x1Y1, const GLshort* x2Y2) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glRectsv, x1Y1, x2Y2);
}

GLint System
	::GLRenderMode(GLenum mode) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1_RESULT(glRenderMode, mode, GLint);
}

void System
	::GLRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glRotated, angle, x, y, z);
}

void System
	::GLRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glRotatef, angle, x, y, z);
}

void System
	::GLScaled(GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glScaled, x, y, z);
}

void System
	::GLScalef(GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glScalef, x, y, z);
}

void System
	::GLScissor(GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glScissor, x, y, width, height);
}

void System
	::GLSelectBuffer(GLsizei size, GLuint* buffer) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glSelectBuffer, size, buffer);
}

void System
	::GLShadeModel(GLenum mode) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glShadeModel, mode);
}

void System
	::GLStencilFunc(GLenum function, GLint reference, GLuint mask) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glStencilFunc, function, reference, mask);
}

void System
	::GLStencilMask(GLuint mask) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glStencilMask, mask);
}

void System
	::GLStencilOp(GLenum fail, GLenum zFail, GLenum zPass) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glStencilOp, fail, zFail, zPass);
}

void System
	::GLTexCoord1d(GLdouble s) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord1d, s);
}

void System
	::GLTexCoord1dv(const GLdouble* s) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord1dv, s);
}

void System
	::GLTexCoord1f(GLfloat s) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord1f, s);
}

void System
	::GLTexCoord1fv(const GLfloat* s) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord1fv, s);
}

void System
	::GLTexCoord1i(GLint s) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord1i, s);
}

void System
	::GLTexCoord1iv(const GLint* s) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord1iv, s);
}

void System
	::GLTexCoord1s(GLshort s) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord1s, s);
}

void System
	::GLTexCoord1sv(const GLshort* s) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord1sv, s);
}

void System
	::GLTexCoord2d(GLdouble s, GLdouble t) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glTexCoord2d, s, t);
}

void System
	::GLTexCoord2dv(const GLdouble* st) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord2dv, st);
}

void System
	::GLTexCoord2f(GLfloat s, GLfloat t) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glTexCoord2f, s, t);
}

void System
	::GLTexCoord2fv(const GLfloat* st) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord2fv, st);
}

void System
	::GLTexCoord2i(GLint s, GLint t) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glTexCoord2i, s, t);
}

void System
	::GLTexCoord2iv(const GLint* st) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord2iv, st);
}

void System
	::GLTexCoord2s(GLshort s, GLshort st) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glTexCoord2s, s, st);
}

void System
	::GLTexCoord2sv(const GLshort* st) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord2sv, st);
}

void System
	::GLTexCoord3d(GLdouble s, GLdouble t, GLdouble r) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexCoord3d, s, t, r);
}

void System
	::GLTexCoord3dv(const GLdouble* str) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord3dv, str);
}

void System
	::GLTexCoord3f(GLfloat s, GLfloat t, GLfloat r) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexCoord3f, s, t, r);
}

void System
	::GLTexCoord3fv(const GLfloat* str) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord3fv, str);
}

void System
	::GLTexCoord3i(GLint s, GLint t, GLint r) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexCoord3i, s, t, r);
}

void System
	::GLTexCoord3iv(const GLint* str) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord3iv, str);
}

void System
	::GLTexCoord3s(GLshort s, GLshort st, GLshort r) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexCoord3s, s, st, r);
}

void System
	::GLTexCoord3sv(const GLshort* str) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord3sv, str);
}

void System
	::GLTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glTexCoord4d, s, t, r, q);
}

void System
	::GLTexCoord4dv(const GLdouble* strq) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord4dv, strq);
}

void System
	::GLTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glTexCoord4f, s, t, r, q);
}

void System
	::GLTexCoord4fv(const GLfloat* strq) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord4fv, strq);
}

void System
	::GLTexCoord4i(GLint s, GLint t, GLint r, GLint q) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glTexCoord4i, s, t, r, q);
}

void System
	::GLTexCoord4iv(const GLint* strq) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord4iv, strq);
}

void System
	::GLTexCoord4s(GLshort s, GLshort st, GLshort r, GLshort q) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glTexCoord4s, s, st, r, q);
}

void System
	::GLTexCoord4sv(const GLshort* strq) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glTexCoord4sv, strq);
}

void System
	::GLTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glTexCoordPointer, size, type, stride, pointer);
}

void System
	::GLTexEnvf(GLenum target, GLenum name, GLfloat param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexEnvf, target, name, param);
}

void System
	::GLTexEnvfv(GLenum target, GLenum name, const GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexEnvfv, target, name, param);
}

void System
	::GLTexEnvi(GLenum target, GLenum name, GLint param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexEnvi, target, name, param);
}

void System
	::GLTexEnviv(GLenum target, GLenum name, const GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexEnviv, target, name, param);
}

void System
	::GLTexGend(GLenum coord, GLenum name, GLdouble param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexGend, coord, name, param);
}

void System
	::GLTexGendv(GLenum coord, GLenum name, const GLdouble* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexGendv, coord, name, param);
}

void System
	::GLTexGenf(GLenum coord, GLenum name, GLfloat param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexGenf, coord, name, param);
}

void System
	::GLTexGenfv(GLenum coord, GLenum name, const GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexGenfv, coord, name, param);
}

void System
	::GLTexGeni(GLenum coord, GLenum name, GLint param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexGeni, coord, name, param);
}

void System
	::GLTexGeniv(GLenum coord, GLenum name, const GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexGeniv, coord, name, param);
}

void System
	::GLTexImage1D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid* pixels) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_8(glTexImage1D, target, level, internalFormat, width, border, format, type, pixels);
}

void System
	::GLTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_9(glTexImage2D, target, level, internalFormat, width, height, border, format, type, pixels);
}

void System
	::GLTexParameterf(GLenum target, GLenum name, GLfloat param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexParameterf, target, name, param);
}

void System
	::GLTexParameterfv(GLenum target, GLenum name, const GLfloat* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexParameterfv, target, name, param);
}

void System
	::GLTexParameteri(GLenum target, GLenum name, GLint param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexParameteri, target, name, param);
}

void System
	::GLTexParameteriv(GLenum target, GLenum name, const GLint* param) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTexParameteriv, target, name, param);
}

void System
	::GLTexSubImage1D(GLenum target, GLint level, GLint xOffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_7(glTexSubImage1D, target, level, xOffset, width, format, type, pixels);
}

void System
	::GLTexSubImage2D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_9(glTexSubImage2D, target, level, xOffset, yOffset, width, height, format, type, pixels);
}

void System
	::GLTranslated(GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTranslated, x, y, z);
}

void System
	::GLTranslatef(GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glTranslatef, x, y, z);
}

void System
	::GLVertex2d(GLdouble x, GLdouble y) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glVertex2d, x, y);
}

void System
	::GLVertex2dv(const GLdouble* xy) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glVertex2dv, xy);
}

void System
	::GLVertex2f(GLfloat x, GLfloat y) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glVertex2f, x, y);
}

void System
	::GLVertex2fv(const GLfloat* xy) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glVertex2fv, xy);
}

void System
	::GLVertex2i(GLint x, GLint y) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glVertex2i, x, y);
}

void System
	::GLVertex2iv(const GLint* xy) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glVertex2iv, xy);
}

void System
	::GLVertex2s(GLshort x, GLshort y) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_2(glVertex2s, x, y);
}

void System
	::GLVertex2sv(const GLshort* xy) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glVertex2sv, xy);
}

void System
	::GLVertex3d(GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glVertex3d, x, y, z);
}

void System
	::GLVertex3dv(const GLdouble* xyz) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glVertex3dv, xyz);
}

void System
	::GLVertex3f(GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glVertex3f, x, y, z);
}

void System
	::GLVertex3fv(const GLfloat* xyz) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glVertex3fv, xyz);
}

void System
	::GLVertex3i(GLint x, GLint y, GLint z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glVertex3i, x, y, z);
}

void System
	::GLVertex3iv(const GLint* xyz) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glVertex3iv, xyz);
}

void System
	::GLVertex3s(GLshort x, GLshort y, GLshort z) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_3(glVertex3s, x, y, z);
}

void System
	::GLVertex3sv(const GLshort* xyz) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glVertex3sv, xyz);
}

void System
	::GLVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glVertex4d, x, y, z, w);
}

void System
	::GLVertex4dv(const GLdouble* xyzw) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glVertex4dv, xyzw);
}

void System
	::GLVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glVertex4f, x, y, z, w);
}

void System
	::GLVertex4fv(const GLfloat* xyzw) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glVertex4fv, xyzw);
}

void System
	::GLVertex4i(GLint x, GLint y, GLint z, GLint w) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glVertex4i, x, y, z, w);
}

void System
	::GLVertex4iv(const GLint* xyzw) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glVertex4iv, xyzw);
}

void System
	::GLVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glVertex4s, x, y, z, w);
}

void System
	::GLVertex4sv(const GLshort* xyzw) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_1(glVertex4sv, xyzw);
}

void System
	::GLVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glVertexPointer, size, type, stride, pointer);
}

void System
	::GLViewport(GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_PREVIOUSLY_BODY_4(glViewport, x, y, width, height);
}
