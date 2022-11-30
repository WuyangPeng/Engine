///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/04 23:54)

#include "OpenGLUtilityTesting.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;

System::OpenGLUtilityTesting::OpenGLUtilityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLUtilityTesting)

void System::OpenGLUtilityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLUtilityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VersionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLSupportsExtensionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WglSupportsExtensionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLErrorDescriptionTest);
}

void System::OpenGLUtilityTesting::VersionTest()
{
    const auto version = GetOpenGLVersion();
    ASSERT_ENUM_UNEQUAL(version, OpenGLSystemVersion::VersionNone);

    ASSERT_ENUM_LESS_EQUAL(OpenGLSystemVersion::Version46, version);
}

void System::OpenGLUtilityTesting::OpenGLSupportsExtensionTest()
{
    const auto exist = IsOpenGLSupportsExtension("GL_EXT_fog_coord");
    auto functionPointer = GetFunctionPointer("glFogCoordf");
    ASSERT_TRUE((exist && functionPointer != nullptr) || (!exist && functionPointer == nullptr));
}

void System::OpenGLUtilityTesting::WglSupportsExtensionTest()
{
    const auto exist = IsWglSupportsExtension("WGL_ARB_buffer_region");
    auto functionPointer = GetFunctionPointer("wglCreateBufferRegionARB");
    ASSERT_TRUE((exist && functionPointer != nullptr) || (!exist && functionPointer == nullptr));
}

void System::OpenGLUtilityTesting::OpenGLErrorDescriptionTest()
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

    error = GetOpenGLErrorDescription(OpenGLErrorCode::InvalidFramebufferOperation);
    ASSERT_EQUAL(error, "GL_INVALID_FRAMEBUFFER_OPERATION");

    error = GetOpenGLErrorDescription(OpenGLErrorCode::ContextLost);
    ASSERT_EQUAL(error, "GL_CONTEXT_LOST");
}