// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.2 (2020/06/02 15:34)

#include "MacintoshMainFunctionHelper1.h" 
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MacintoshFrame/MacintoshProcessDetail.h"
#include "Framework/MacintoshFrame/MacintoshFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/MacintoshMainFunctionHelperDetail.h"

Framework::MacintoshMainFunctionHelper1
	::MacintoshMainFunctionHelper1(const Framework::EnvironmentDirectory& environmentDirectory)
	:ParentType{ environmentDirectory }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;

	System::SystemPause();
} 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MacintoshMainFunctionHelper1)


