///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/06/29 19:38)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_GLUT_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_GLUT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLGlutTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLGlutTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLGlutTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateWindowTest();
        void DestroyWindowTest();
        void CallbackTest();

        static void RenderSceneCallback() noexcept;
        static void MouseClickCallback(int button, int state, int xCoordinate, int yCoordinate) noexcept;

    private:
        static int destroyWindowID;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_GLUT_TESTING_H