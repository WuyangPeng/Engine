///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/17 13:18)

#include "MemberFunctionNoexceptMacroTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/MemberFunctionNoexceptMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::MemberFunctionNoexceptMacroTesting::MemberFunctionNoexceptMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MemberFunctionNoexceptMacroTesting)

void CoreTools::MemberFunctionNoexceptMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MemberFunctionNoexceptMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstMemberFunctionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NonConstMemberFunctionTest); 
}

void CoreTools::MemberFunctionNoexceptMacroTesting::ConstMemberFunctionTest()
{
    MemberFunctionNoexceptMacro MmberFunctionNoexceptMacro{ DisableNotThrow::Disable };

    MmberFunctionNoexceptMacro.ConstMemberFunction();
    MmberFunctionNoexceptMacro.ConstMemberFunction("");
    MmberFunctionNoexceptMacro.ConstMemberFunction(0);
    MmberFunctionNoexceptMacro.ConstMemberFunction(nullptr);
}

void CoreTools::MemberFunctionNoexceptMacroTesting::NonConstMemberFunctionTest()
{
    MemberFunctionNoexceptMacro MmberFunctionNoexceptMacro{ DisableNotThrow::Disable };

    MmberFunctionNoexceptMacro.NonConstCopyMemberFunction();
    MmberFunctionNoexceptMacro.NonConstCopyMemberFunction("");
    MmberFunctionNoexceptMacro.NonConstCopyMemberFunction(0);
    MmberFunctionNoexceptMacro.NonConstCopyMemberFunction(nullptr);
}
