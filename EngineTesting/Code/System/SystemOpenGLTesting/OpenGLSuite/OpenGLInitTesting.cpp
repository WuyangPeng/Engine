/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:43)

#include "OpenGLInitTesting.h"
#include "System/OpenGL/OpenGLInit.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLInitTesting::OpenGLInitTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLInitTesting)

void System::OpenGLInitTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLInitTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLInitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PrintInfoTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLInfoTest);
}

void System::OpenGLInitTesting::OpenGLInitTest()
{
    ASSERT_TRUE(OpenGLInit());
}

void System::OpenGLInitTesting::PrintInfoTest() const
{
    PrintOpenGLInfo();
    PrintWglExtensionsInfo();
}

void System::OpenGLInitTesting::OpenGLInfoTest()
{
    ASSERT_FALSE(GetOpenGLVendorString().empty());
    ASSERT_FALSE(GetOpenGLVersionString().empty());
    ASSERT_FALSE(GetOpenGLRendererString().empty());
    ASSERT_FALSE(GetOpenGLShadingLanguageVersion().empty());
}
