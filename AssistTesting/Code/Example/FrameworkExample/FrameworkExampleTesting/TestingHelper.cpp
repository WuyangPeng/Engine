// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.2.2 (2020/01/27 15:21)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

FrameworkExample::TestingHelper
	::TestingHelper(int argc, char** argv)
	:ParentType{ argc,argv,"��������ӡ���Ԫ�����׼�" }
{
	InitSuite();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(FrameworkExample, TestingHelper)

void FrameworkExample::TestingHelper
	::InitSuite() noexcept
{
	
}
