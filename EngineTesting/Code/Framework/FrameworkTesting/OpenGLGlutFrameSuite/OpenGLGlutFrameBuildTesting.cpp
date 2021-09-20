// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/12 19:08)

#include "OpenGLGlutFrameBuildTesting.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  

Framework::OpenGLGlutFrameBuildTesting
::OpenGLGlutFrameBuildTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutFrameBuildTesting)

void Framework::OpenGLGlutFrameBuildTesting
::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::OpenGLGlutFrameBuildTesting
	::MainTest()
{
    CoreTools::DisableNoexcept();
}

