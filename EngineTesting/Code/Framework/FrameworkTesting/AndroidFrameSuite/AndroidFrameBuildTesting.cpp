// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/12 19:12)

#include "AndroidFrameBuildTesting.h"
#include "Framework/AndroidFrame/AndroidFrameBuildDetail.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  

Framework::AndroidFrameBuildTesting
::AndroidFrameBuildTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidFrameBuildTesting)

void Framework::AndroidFrameBuildTesting
::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::AndroidFrameBuildTesting
	::MainTest()
{
	CoreTools::DisableNoexcept();
}



