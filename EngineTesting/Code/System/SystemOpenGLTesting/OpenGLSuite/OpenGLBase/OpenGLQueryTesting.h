///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/16 14:11)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_QUERY_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_QUERY_TESTING_H

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
        void DoRunUnitTest() final;
        void MainTest();

        void NumExtensionsTest();
        void MajorVersionTest();
        void MinorVersionTest();
        void VertexArrayTest();
        void TextureTargetBindingTest();
        void ViewportTest();
        void DepthRangeTest();

    private:
        using TextureTargetBindingContainer = std::vector<TextureTargetBinding>;

    private:
        TextureTargetBindingContainer textureTargetBindings;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OEPNGL_QUERY_TESTING_H