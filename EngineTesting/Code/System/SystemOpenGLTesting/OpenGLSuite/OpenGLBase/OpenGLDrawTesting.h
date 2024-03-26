/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:33)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_DRAW_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_DRAW_TESTING_H

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLDrawTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLDrawTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLDrawTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using OpenGLFloatContainer = std::vector<OpenGLFloat>;
        using OpenGLUnsignedIntContainer = std::vector<OpenGLUnsignedInt>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void InitDraw();
        void SetGLDrawRangeElementsTest();
        void SetGLDrawArraysTest();
        void SetGLFlushTest() noexcept;
        void BindBufferTest(int index, const OpenGLFloatContainer& buffer);

    private:
        OpenGLUnsignedInt vertexHandler;
        OpenGLFloatContainer vertices;
        OpenGLUnsignedIntContainer indices;
        OpenGLFloatContainer colors;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_DRAW_TESTING_H