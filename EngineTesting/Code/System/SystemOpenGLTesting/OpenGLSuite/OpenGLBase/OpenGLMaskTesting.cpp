/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:42)

#include "OpenGLMaskTesting.h"
#include "System/OpenGL/OpenGLBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLMaskTesting::OpenGLMaskTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLMaskTesting)

void System::OpenGLMaskTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLMaskTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLColorMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLSampleMaskTest);
}

void System::OpenGLMaskTesting::SetGLColorMaskTest() const noexcept
{
    SetGLColorMask(false, false, false, false);
    SetGLColorMask(0, true, true, true, true);
}

void System::OpenGLMaskTesting::SetGLSampleMaskTest() const noexcept
{
    SetGLSampleMask(0, 0);
}
