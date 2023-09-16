///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:01)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_POLYGON_MODE_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_POLYGON_MODE_TESTING_H

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLPolygonModeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLPolygonModeTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLPolygonModeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void OpenGLPolygonModeTest() noexcept;

    private:
        using RasterizerStateFillModeContainer = std::vector<RasterizerStateFillMode>;

    private:
        RasterizerStateFillModeContainer rasterizerStates;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_POLYGON_MODE_TESTING_H