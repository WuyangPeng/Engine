/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:21)

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
