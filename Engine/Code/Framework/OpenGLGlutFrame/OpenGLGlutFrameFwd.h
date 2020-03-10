// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:19)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_FWD_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_FWD_H

namespace Framework
{
	class OpenGLGlutProcessManager;
	class OpenGLGlutCallBackInterface;
	class OpenGLGlutCallBackUnitTestSuite;

	template <typename OpenGLGlutCallBack>
	class OpenGLGlutProcess;

	template <typename ModelViewControllerMiddleLayerContainer>
	class OpenGLGlutCallBack;

	template <typename OpenGLGlutProcess>
	class OpenGLGlutFrameBuild;
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_FWD_H