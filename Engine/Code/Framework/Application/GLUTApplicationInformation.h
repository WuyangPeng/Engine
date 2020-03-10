// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:08)

#ifndef FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_H
#define FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "Framework/OpenGLGlutFrame/FrameParameter.h"

FRAMEWORK_EXPORT_SHARED_PTR(GLUTApplicationInformationImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE GLUTApplicationInformation 
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(GLUTApplicationInformation);

	public:	
		GLUTApplicationInformation(int majorVersion,int minorVersion, FrameParameter frame);
		
		CLASS_INVARIANT_DECLARE;

		int GetOpenGLMajorVersion() const;
		int GetOpenGLMinorVersion() const;  
		FrameParameter GetFrame() const; 

	private:
		IMPL_TYPE_DECLARE(GLUTApplicationInformation);
	};
}

#endif // FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_H
