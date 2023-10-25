///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 14:34)

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

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26812)

void CoreTools::Pow3Testing::Pow3Test()
{
    ASSERT_EQUAL(Pow3<5>::Result, 3 * 3 * 3 * 3 * 3);
    ASSERT_EQUAL(Pow3<4>::Result, 3 * 3 * 3 * 3);
    ASSERT_EQUAL(Pow3<7>::Result, 3 * 3 * 3 * 3 * 3 * 3 * 3);
    ASSERT_EQUAL(Pow3<10>::Result, 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3);
}

#include SYSTEM_WARNING_POP