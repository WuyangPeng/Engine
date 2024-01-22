/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:21)

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
