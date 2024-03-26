/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:33)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BLEND_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BLEND_TESTING_H

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace System
{
    class OpenGLBlendTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLBlendTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLBlendTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();

        void SetGLBlendColorTest() const noexcept;
        void SetGLBlendFuncSeparateTest();
        void SetGLBlendEquationSeparateTest();

        void DoSetGLBlendFuncSeparateTest(size_t index) const;
        void DoSetGLBlendEquationSeparateTest(size_t index) const;

    private:
        using BlendStateModeContainer = std::vector<BlendStateMode>;
        using BlendStateOperationContainer = std::vector<BlendStateOperation>;

    private:
        BlendStateModeContainer sourceFactorRGBs;
        BlendStateModeContainer destinationFactorRGBs;
        BlendStateModeContainer sourceFactorAlphas;
        BlendStateModeContainer destinationFactorAlphas;
        BlendStateOperationContainer modeRGBs;
        BlendStateOperationContainer modeAlphas;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_BLEND_TESTING_H