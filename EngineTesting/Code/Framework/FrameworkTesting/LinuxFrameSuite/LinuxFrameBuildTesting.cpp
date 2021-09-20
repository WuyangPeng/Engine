// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.1 (2020/05/22 23:48)

#include "LinuxFrameBuildTesting.h"  
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  

Framework::LinuxFrameBuildTesting
	::LinuxFrameBuildTesting(const OStreamShared& stream)
	:ParentType{ stream } 
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, LinuxFrameBuildTesting)

void Framework::LinuxFrameBuildTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::LinuxFrameBuildTesting
	::MainTest()
{
	CoreTools::DisableNoexcept();
}
 