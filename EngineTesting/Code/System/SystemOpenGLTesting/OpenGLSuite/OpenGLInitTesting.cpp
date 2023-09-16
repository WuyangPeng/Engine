///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 13:52)

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
    ASSERT_NOT_THROW_EXCEPTION_0(InfoTest);
}

void System::OpenGLInitTesting::OpenGLInitTest()
{
    ASSERT_TRUE(OpenGLInit());

    PrintOpenGLInfo();
    PrintWglExtensionsInfo();
}

void System::OpenGLInitTesting::InfoTest()
{
    ASSERT_FALSE(GetOpenGLVendorString().empty());
    ASSERT_FALSE(GetOpenGLVersionString().empty());
    ASSERT_FALSE(GetOpenGLRendererString().empty());
    ASSERT_FALSE(GetOpenGLShadingLanguageVersion().empty());
}
