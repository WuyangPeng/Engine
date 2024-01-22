/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:55)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_DETAIL_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_DETAIL_H

#include "OpenGLGlutCallBackUnitTestSuite.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename TestType, typename... Types>
void Framework::OpenGLGlutCallBackUnitTestSuite::AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    auto unitTest = std::make_shared<TestType>(GetStreamShared(), std::forward<Types>(args)...);

    AddTest(suiteName, suite, testName, unitTest);
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_DETAIL_H
