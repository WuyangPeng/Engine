///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 20:43)

#include "GLUTApplicationInformationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/Application/GLUTApplicationInformation.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"

Framework::GLUTApplicationInformationTesting::GLUTApplicationInformationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, GLUTApplicationInformationTesting)

void Framework::GLUTApplicationInformationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::GLUTApplicationInformationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InformationTest);
}

void Framework::GLUTApplicationInformationTesting::InformationTest()
{
    constexpr auto majorVersion = 3;
    constexpr auto minorVersion = 2;
    constexpr auto frame = FrameParameter::SixtyFrame;

    const GLUTApplicationInformation information{ majorVersion, minorVersion, frame };

    ASSERT_EQUAL(information.GetOpenGLMajorVersion(), majorVersion);
    ASSERT_EQUAL(information.GetOpenGLMinorVersion(), minorVersion);
    ASSERT_EQUAL(information.GetFrame(), frame);
}
