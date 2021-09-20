// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎辅助版本：0.3.0.1 (2020/05/25 13:46)

#include "GlutMainEntryPoint1.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"

Framework::GlutMainEntryPoint1
	::GlutMainEntryPoint1(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
	:ParentType{ argc,argv,information,environmentDirectory }
{
	// 构造未完成
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, GlutMainEntryPoint1)
