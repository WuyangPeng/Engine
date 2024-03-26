/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:34)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_QUERY_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_QUERY_TESTING_H

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLQueryTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLQueryTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLQueryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using TextureTargetBindingContainer = std::vector<TextureTargetBinding>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void NumExtensionsTest();
        void MajorVersionTest();
        void MinorVersionTest();
        void VertexArrayTest();
        void TextureTargetBindingTest();
        void ViewportTest();
        void DepthRangeTest();

        void GreaterZeroTest(OpenGLQuery openGLQuery);
        void EqualTest(OpenGLQuery openGLQuery, int version);
        void EqualZeroTest(OpenGLQuery openGLQuery);

    private:
        TextureTargetBindingContainer textureTargetBindings;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_QUERY_TESTING_H