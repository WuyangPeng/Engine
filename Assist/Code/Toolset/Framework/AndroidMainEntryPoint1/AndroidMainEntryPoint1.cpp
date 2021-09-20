// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.1 (2020/05/25 14:42)

#include "AndroidMainEntryPoint1.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"
#include "Framework/AndroidFrame/AndroidFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelperDetail.h"

Framework::AndroidMainEntryPoint1
	::AndroidMainEntryPoint1(AndroidApp* state, const EnvironmentDirectory& environmentDirectory)
	:ParentType{ state,environmentDirectory }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
} 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidMainEntryPoint1)
 