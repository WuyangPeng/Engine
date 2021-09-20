///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/20 13:42)

#include "SharedPtrMacroTesting.h"
#include "Detail/AbstractObject.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::SharedPtrMacroTesting::SharedPtrMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SharedPtrMacroTesting)

void CoreTools::SharedPtrMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SharedPtrMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MacroTest);
}

void CoreTools::SharedPtrMacroTesting::MacroTest() noexcept
{
    using SharedPtr = AbstractObjectSharedPtr;
    using ConstSharedPtr = ConstAbstractObjectSharedPtr;

    using WeakPtr = AbstractObjectWeakPtr;
    using ConstWeakPtr = ConstAbstractObjectWeakPtr;
}
