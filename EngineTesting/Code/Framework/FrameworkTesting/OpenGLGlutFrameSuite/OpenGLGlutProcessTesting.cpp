// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/12 19:08)

#include "OpenGLGlutProcessTesting.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Contract/Noexcept.h"

Framework::OpenGLGlutProcessTesting
::OpenGLGlutProcessTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutProcessTesting)

void Framework::OpenGLGlutProcessTesting
::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}


void Framework::OpenGLGlutProcessTesting
	::MainTest()
{
    CoreTools::DisableNoexcept();
}

