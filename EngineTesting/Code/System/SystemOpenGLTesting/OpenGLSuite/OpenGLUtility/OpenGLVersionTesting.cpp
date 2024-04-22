/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:49)

#include "OpenGLVersionTesting.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLVersionTesting::OpenGLVersionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLVersionTesting)

void System::OpenGLVersionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLVersionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VersionTest);
}

void System::OpenGLVersionTesting::VersionTest()
{
    const auto version = GetOpenGLVersion();
    ASSERT_UNEQUAL(version, OpenGLSystemVersion::VersionNone);

    ASSERT_LESS_EQUAL(OpenGLSystemVersion::Version46, version);
}
