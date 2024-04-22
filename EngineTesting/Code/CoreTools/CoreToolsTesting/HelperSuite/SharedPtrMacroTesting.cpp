/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 11:40)

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
