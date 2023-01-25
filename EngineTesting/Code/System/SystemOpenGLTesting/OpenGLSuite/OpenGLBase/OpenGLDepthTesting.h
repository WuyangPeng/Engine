///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/16 19:35)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_DEPTH_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_DEPTH_TESTING_H

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLDepthTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLDepthTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLDepthTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SetGLDepthFuncTest() noexcept;
        void SetGLDepthMaskTest() noexcept;

    private:
        using DepthStencilStateModeContainer = std::vector<DepthStencilStateMode>;
        using DepthStencilStateWriteMaskContainer = std::vector<DepthStencilStateWriteMask>;

    private:
        DepthStencilStateModeContainer depthStencilStateModes;
        DepthStencilStateWriteMaskContainer depthStencilStateWriteMasks;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_DEPTH_TESTING_H