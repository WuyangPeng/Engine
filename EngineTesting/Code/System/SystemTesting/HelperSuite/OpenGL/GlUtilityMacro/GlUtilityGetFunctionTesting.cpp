/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 16:12)

#include "GlUtilityGetFunctionTesting.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/SystemTesting/HelperSuite/Detail/GlUtilityMacroHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GlUtilityGetFunctionTesting::GlUtilityGetFunctionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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