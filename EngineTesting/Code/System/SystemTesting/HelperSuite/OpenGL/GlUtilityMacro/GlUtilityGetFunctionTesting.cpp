///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/18 13:00)

#include "GlUtilityGetFunctionTesting.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/SystemTesting/HelperSuite/Detail/GlUtilityMacroHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GlUtilityGetFunctionTesting::GlUtilityGetFunctionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GlUtilityGetFunctionTesting)

void System::GlUtilityGetFunctionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GlUtilityGetFunctionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetFunctionTest);
}

void System::GlUtilityGetFunctionTesting::GetFunctionTest()
{
    GLGetFunction glGetFunction{ nullptr };
    SYSTEM_GET_FUNCTION(glGetFunction);

    ASSERT_EQUAL(glGetFunction, &System::GLFunction);
}
