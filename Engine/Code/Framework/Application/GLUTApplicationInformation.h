///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:45)

#ifndef FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_H
#define FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameFwd.h"

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

        NODISCARD int GetOpenGLMajorVersion() const noexcept;
        NODISCARD int GetOpenGLMinorVersion() const noexcept;
        NODISCARD FrameParameter GetFrame() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_H
