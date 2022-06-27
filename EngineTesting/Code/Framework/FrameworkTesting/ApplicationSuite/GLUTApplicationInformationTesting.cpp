///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 11:13)

#include "GLUTApplicationInformationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/GLUTApplicationInformation.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"

namespace Framework
{
    using TestingType = GLUTApplicationInformation;
}

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

    TestingType information{ majorVersion, minorVersion, frame };

    ASSERT_EQUAL(information.GetOpenGLMajorVersion(), majorVersion);
    ASSERT_EQUAL(information.GetOpenGLMinorVersion(), minorVersion);
    ASSERT_ENUM_EQUAL(information.GetFrame(), frame);
}
