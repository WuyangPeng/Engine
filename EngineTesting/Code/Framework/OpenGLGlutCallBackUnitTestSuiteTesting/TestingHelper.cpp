// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/17 09:41)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"

OpenGLGlutCallBackUnitTestSuiteTesting::TestingHelper
	::TestingHelper(int argc,char* argv[],const GLUTApplicationInformation& information,const Framework::EnvironmentDirectory& environmentDirectory)
	:ParentType(argc,argv,information,environmentDirectory)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

OpenGLGlutCallBackUnitTestSuiteTesting::TestingHelper
	::~TestingHelper()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(OpenGLGlutCallBackUnitTestSuiteTesting,TestingHelper)






