// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:39)

#ifndef FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_IMPL_H
#define FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameFwd.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE GLUTApplicationInformationImpl
	{
	public:
		using ClassType = GLUTApplicationInformationImpl;

	public:
		GLUTApplicationInformationImpl(int majorVersion, int minorVersion, FrameParameter frame) noexcept;

		CLASS_INVARIANT_DECLARE;

		int GetOpenGLMajorVersion() const noexcept;
		int GetOpenGLMinorVersion() const noexcept;
		FrameParameter GetFrame() const noexcept;

	private:
		int m_OpenGLMajorVersion;
		int m_OpenGLMinorVersion;
		FrameParameter m_Frame;
	};
}

#endif // FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_IMPL_H
