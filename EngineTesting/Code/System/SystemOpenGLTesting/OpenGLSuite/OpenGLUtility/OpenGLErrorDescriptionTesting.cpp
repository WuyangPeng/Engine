/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:49)

#include "OpenGLErrorDescriptionTesting.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLErrorDescriptionTesting::OpenGLErrorDescriptionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLErrorDescriptionTesting)

void System::OpenGLErrorDescriptionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLErrorDescriptionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLErrorDescriptionTest);
}

void System::OpenGLErrorDescriptionTesting::OpenGLErrorDescriptionTest()
{
    auto error = GetOpenGLErrorDescription(OpenGLErrorCode::InvalidEnum);
    ASSERT_EQUAL(error, "GL_INVALID_ENUM");

    error = GetOpenGLErrorDescription(OpenGLErrorCode::InvalidValue);
    ASSERT_EQUAL(error, "GL_INVALID_VALUE");

    error = GetOpenGLErrorDescription(OpenGLErrorCode::InvalidOperation);
    ASSERT_EQUAL(error, "GL_INVALID_OPERATION");

    error = GetOpenGLErrorDescription(OpenGLErrorCode::StackOverflow);
    ASSERT_EQUAL(error, "GL_STACK_OVERFLOW");

    error = GetOpenGLErrorDescription(OpenGLErrorCode::StackUnderflow);
    ASSERT_EQUAL(error, "GL_STACK_UNDERFLOW");

    error = GetOpenGLErrorDescription(OpenGLErrorCode::OutOfMemory);
    ASSERT_EQUAL(error, "GL_OUT_OF_MEMORY");

    error = GetOpenGLErrorDescription(OpenGLErrorCode::InvalidFrameBufferOperation);
    ASSERT_EQUAL(error, "GL_INVALID_FRAMEBUFFER_OPERATION");

    error = GetOpenGLErrorDescription(OpenGLErrorCode::ContextLost);
    ASSERT_EQUAL(error, "GL_CONTEXT_LOST");
}