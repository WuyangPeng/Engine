///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 14:48)

#ifndef RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_BIND_TEXTURE_TESTING_H
#define RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_BIND_TEXTURE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class OpenGLBindTextureTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLBindTextureTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLBindTextureTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_BIND_TEXTURE_TESTING_H