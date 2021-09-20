// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.3.0.2 (2020/06/02 10:19)

#include "OpenGLGlutMainFunctionHelper1.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"

Framework::OpenGLGlutMainFunctionHelper1
	::OpenGLGlutMainFunctionHelper1(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
	:ParentType{ argc,argv,information,environmentDirectory }
{
	// ����δ���
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutMainFunctionHelper1) 