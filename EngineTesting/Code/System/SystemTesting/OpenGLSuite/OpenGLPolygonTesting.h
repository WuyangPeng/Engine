///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:34)

#ifndef SYSTEM_OPENGL_SUITE_OPENGL_POLYGON_TESTING_H
#define SYSTEM_OPENGL_SUITE_OPENGL_POLYGON_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLPolygonTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLPolygonTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLPolygonTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_OPENGL_SUITE_OPENGL_POLYGON_TESTING_H