/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 16:12)

#ifndef SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_MARK_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_MARK_TESTING_H

#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GlUtilityMarkTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GlUtilityMarkTesting;
        using ParentType = UnitTest;

    public:
        explicit GlUtilityMarkTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void OPENGL_STDCALL OpenGLStdCallTest() const noexcept;
        void ExportFunctionTest() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_MARK_TESTING_H
