///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 13:57)

#include "ReferenceCastTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/ReferenceCastDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ReferenceCastTesting::ReferenceCastTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ReferenceCastTesting)

void CoreTools::ReferenceCastTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ReferenceCastTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CastTest);
}

void CoreTools::ReferenceCastTesting::CastTest()
{
    constexpr auto value0 = 2;

    ASSERT_EQUAL(ReferenceCast<int>(value0), value0);

    std::string value1{ "value1" };
    auto value2 = static_cast<std::string&>(ReferenceCast{ value1 });

    ASSERT_EQUAL(value2, value1);

    const std::string value3{ ReferenceCast{ value2 } };

    ASSERT_EQUAL(value2, value3);
}
