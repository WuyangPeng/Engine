///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/09 15:01)

#ifndef FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_IMPL_H
#define FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_IMPL_H

#include "Framework/FrameworkDll.h"

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

        NODISCARD int GetOpenGLMajorVersion() const noexcept;
        NODISCARD int GetOpenGLMinorVersion() const noexcept;
        NODISCARD FrameParameter GetFrame() const noexcept;

    private:
        int openGLMajorVersion;
        int openGLMinorVersion;
        FrameParameter frame;
    };
}

#endif  // FRAMEWORK_APPLICATION_GLUT_WINDOW_APPLICATION_INFORMATION_IMPL_H
