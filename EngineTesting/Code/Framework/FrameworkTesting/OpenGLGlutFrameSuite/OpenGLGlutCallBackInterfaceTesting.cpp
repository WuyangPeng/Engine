// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/12 19:08)

#include "OpenGLGlutCallBackInterfaceTesting.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackInterface.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  

Framework::OpenGLGlutCallBackInterfaceTesting
::OpenGLGlutCallBackInterfaceTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutCallBackInterfaceTesting)

void Framework::OpenGLGlutCallBackInterfaceTesting
::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::OpenGLGlutCallBackInterfaceTesting
	::MainTest()
{
	CoreTools::DisableNoexcept();
}

