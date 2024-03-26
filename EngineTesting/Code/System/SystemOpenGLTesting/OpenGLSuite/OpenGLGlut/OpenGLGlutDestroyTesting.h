/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:37)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GLUT_DESTROY_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GLUT_DESTROY_TESTING_H

#include "OpenGLGlutTestingBase.h"

namespace System
{
    class OpenGLGlutDestroyTesting final : public OpenGLGlutTestingBase
    {
    public:
        using ClassType = OpenGLGlutDestroyTesting;
        using ParentType = OpenGLGlutTestingBase;

    public:
        explicit OpenGLGlutDestroyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DestroyWindowTest();

        static void RenderSceneCallback() noexcept;

    private:
        static int destroyWindowId;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GLUT_DESTROY_TESTING_H