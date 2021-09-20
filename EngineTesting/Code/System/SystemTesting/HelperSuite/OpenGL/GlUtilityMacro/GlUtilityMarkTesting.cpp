///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/18 13:23)

#include "GlUtilityMarkTesting.h"
#include "System/SystemTesting/HelperSuite/Detail/GlUtilityMacroHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GlUtilityMarkTesting::GlUtilityMarkTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GlUtilityMarkTesting)

void System::GlUtilityMarkTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GlUtilityMarkTesting::MainTest()  
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLStdCallTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExportFunctionTest);
}

void System::GlUtilityMarkTesting::OpenGLStdCallTest() noexcept
{
}

void System::GlUtilityMarkTesting::ExportFunctionTest() noexcept
{
    ExportTest::ExportFunction();
}
