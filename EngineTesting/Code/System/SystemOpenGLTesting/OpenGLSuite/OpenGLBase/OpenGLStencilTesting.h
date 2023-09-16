///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 13:54)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_STENCIL_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_STENCIL_TESTING_H

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLStencilTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLStencilTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLStencilTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SetGLStencilFuncSeparateTest() noexcept;
        void SetGLStencilMaskSeparateTest() noexcept;
        void SetGLStencilOpSeparateTest() noexcept;

    private:
        using RasterizerStateCullFaceContainer = std::vector<RasterizerStateCullFace>;
        using DepthStencilStateModeContainer = std::vector<DepthStencilStateMode>;
        using DepthStencilStateOperationContainer = std::vector<DepthStencilStateOperation>;

    private:
        RasterizerStateCullFaceContainer rasterizerStateCullFaces;
        DepthStencilStateModeContainer depthStencilStateModes;
        DepthStencilStateOperationContainer stencilFails;
        DepthStencilStateOperationContainer depthFails;
        DepthStencilStateOperationContainer depthPasses;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_STENCIL_TESTING_H