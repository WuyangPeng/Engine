// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:00)

#ifndef FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_IMPL_H
#define FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "Framework/OpenGLGlutFrame/FrameParameter.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE GLUTApplicationInformationImpl  
	{
	public:
		using ClassType = GLUTApplicationInformationImpl;

	public:	
		GLUTApplicationInformationImpl(int majorVersion, int minorVersion,  FrameParameter frame);
		
		CLASS_INVARIANT_DECLARE;

		int GetOpenGLMajorVersion() const;
		int GetOpenGLMinorVersion() const;  
		FrameParameter GetFrame() const; 

	private:
		int m_OpenGLMajorVersion;
		int m_OpenGLMinorVersion;  
		FrameParameter m_Frame;
	};
}

#endif // FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_IMPL_H
