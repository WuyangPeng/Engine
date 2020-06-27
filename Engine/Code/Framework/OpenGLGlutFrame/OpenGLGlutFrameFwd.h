// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 15:58)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_FWD_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_FWD_H

namespace Framework
{
	enum class FrameParameter;

	class OpenGLGlutProcessManager;

	template <typename OpenGLGlutCallBack>
	class OpenGLGlutProcess;

	class OpenGLGlutCallBackInterface;

	template <typename MiddleLayer>
	class OpenGLGlutCallBack;

	class OpenGLGlutCallBackUnitTestSuite;	

	template <typename OpenGLGlutProcess>
	class OpenGLGlutFrameBuild;
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_FWD_H