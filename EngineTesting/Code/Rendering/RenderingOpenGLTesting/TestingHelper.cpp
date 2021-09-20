// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 12:52)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"

Rendering::TestingHelper
	::TestingHelper(int argc,char* argv[],const GLUTApplicationInformation& information,const Framework::EnvironmentDirectory& environmentDirectory)
	:ParentType{ argc,argv,information,environmentDirectory }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TestingHelper
	::~TestingHelper()
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TestingHelper)

