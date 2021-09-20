// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/22 21:26)

#include "ExampleHelper.h"
#include "Example.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"

Example::ExampleHelper
	::ExampleHelper(HInstance instance,char* cmdLine,const WindowApplicationInformation& information,
			        const Framework::EnvironmentDirectory& environmentDirectory)
	:ParentType{ instance,cmdLine,information,environmentDirectory }
{
	SELF_CLASS_IS_VALID_9;
}

Example::ExampleHelper
	::~ExampleHelper()
{
	SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Example, ExampleHelper)





