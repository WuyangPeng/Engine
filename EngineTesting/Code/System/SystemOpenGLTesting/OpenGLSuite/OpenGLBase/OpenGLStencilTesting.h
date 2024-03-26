/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:34)

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

        void SetGLStencilFuncSeparateTest() const noexcept;
        void SetGLStencilMaskSeparateTest() const noexcept;
        void SetGLStencilOpSeparateTest() const noexcept;

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