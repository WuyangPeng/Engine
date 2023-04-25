///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 13:46)

#include "Pow3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/Pow3.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::Pow3Testing::Pow3Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Pow3Testing)

void CoreTools::Pow3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::Pow3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Pow3Test);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26812)

void CoreTools::Pow3Testing::Pow3Test()
{
    ASSERT_EQUAL(Pow3<5>::Result, 3 * 3 * 3 * 3 * 3);
    ASSERT_EQUAL(Pow3<4>::Result, 3 * 3 * 3 * 3);
    ASSERT_EQUAL(Pow3<7>::Result, 3 * 3 * 3 * 3 * 3 * 3 * 3);
    ASSERT_EQUAL(Pow3<10>::Result, 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3);
}

#include STSTEM_WARNING_POP