// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/14 21:25)

#include "GLUTApplicationInformationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"
#include "Framework/Application/GLUTApplicationInformation.h"

namespace Framework
{
	using TestingType = GLUTApplicationInformation;
}

Framework::GLUTApplicationInformationTesting
	::GLUTApplicationInformationTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, GLUTApplicationInformationTesting)

void Framework::GLUTApplicationInformationTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::GLUTApplicationInformationTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(InformationTest);
}

void Framework::GLUTApplicationInformationTesting
	::InformationTest()
{
	constexpr auto majorVersion = 3;
	constexpr auto minorVersion = 2;
	constexpr auto frame = FrameParameter::SixtyFrame; 

	TestingType information{ majorVersion, minorVersion,frame };

	ASSERT_EQUAL(information.GetOpenGLMajorVersion(), majorVersion);
	ASSERT_EQUAL(information.GetOpenGLMinorVersion(), minorVersion);
	ASSERT_ENUM_EQUAL(information.GetFrame(), frame);
}



