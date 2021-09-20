// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/12 19:08)

#include "OpenGLGlutProcessManagerTesting.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  

Framework::OpenGLGlutProcessManagerTesting
::OpenGLGlutProcessManagerTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutProcessManagerTesting)

void Framework::OpenGLGlutProcessManagerTesting
::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::OpenGLGlutProcessManagerTesting
	::MainTest()
{
    CoreTools::DisableNoexcept();
}

