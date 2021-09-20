// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.3.0.1 (2020/05/25 13:46)

#include "GlutMainEntryPoint1.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"

Framework::GlutMainEntryPoint1
	::GlutMainEntryPoint1(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
	:ParentType{ argc,argv,information,environmentDirectory }
{
	// ����δ���
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, GlutMainEntryPoint1)
