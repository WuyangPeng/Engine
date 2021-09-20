// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 13:43)

#ifndef FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_H
#define FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
FRAMEWORK_PERFORMANCE_UNSHARED_EXPORT_IMPL(GLUTApplicationInformationImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE GLUTApplicationInformation
	{
	public:
            PERFORMANCE_UNSHARED_TYPE_DECLARE(GLUTApplicationInformation);

	public:
		GLUTApplicationInformation(int majorVersion, int minorVersion, FrameParameter frame);

		CLASS_INVARIANT_DECLARE;

		int GetOpenGLMajorVersion() const noexcept;
		int GetOpenGLMinorVersion() const noexcept;
		FrameParameter GetFrame() const noexcept;

	private:
                PackageType impl;
	};
}

#endif // FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_H
