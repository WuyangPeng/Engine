///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/03 11:47)

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
        void DoRunUnitTest() final;
        void MainTest();

        void OPENGL_STDCALL OpenGLStdCallTest() noexcept;
        void ExportFunctionTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_MARK_TESTING_H
