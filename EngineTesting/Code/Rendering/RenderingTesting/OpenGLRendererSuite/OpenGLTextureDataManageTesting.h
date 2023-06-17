///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:44)

#ifndef RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_TEXTURE_DATA_MANAGE_TESTING_H
#define RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_TEXTURE_DATA_MANAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class OpenGLTextureDataManageTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLTextureDataManageTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLTextureDataManageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_TEXTURE_DATA_MANAGE_TESTING_H