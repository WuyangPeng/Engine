///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/15 19:14)

#include "OpenGLSupportsExtensionTesting.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLSupportsExtensionTesting::OpenGLSupportsExtensionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLSupportsExtensionTesting)

void System::OpenGLSupportsExtensionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLSupportsExtensionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLSupportsExtensionTest);
}

void System::OpenGLSupportsExtensionTesting::OpenGLSupportsExtensionTest()
{
    const auto exist = IsOpenGLSupportsExtension("GL_EXT_fog_coord");
    const auto functionPointer = GetFunctionPointer("glFogCoordf");
    ASSERT_TRUE((exist && functionPointer != nullptr) || (!exist && functionPointer == nullptr));
}
