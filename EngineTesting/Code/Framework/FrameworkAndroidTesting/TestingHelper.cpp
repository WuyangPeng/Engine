// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/10 20:11)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"

Framework::TestingHelper
	::TestingHelper(AndroidApp* state,const Framework::EnvironmentDirectory& environmentDirectory)
	:ParentType(state,environmentDirectory)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::TestingHelper
	::~TestingHelper()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework,TestingHelper)







