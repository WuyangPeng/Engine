///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 11:15)

#include "ExplicitCastTesting.h"
#include "Detail/ExplicitCastTest.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/ExplicitCastDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ExplicitCastTesting::ExplicitCastTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ExplicitCastTesting)

void CoreTools::ExplicitCastTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ExplicitCastTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CastTest);
}

void CoreTools::ExplicitCastTesting::CastTest()
{
    ExplicitCastTest explicitCastTest{ DisableNotThrow::Disable };

    IntegerTest(ExplicitCast<int>(explicitCastTest));
    StringTest(ExplicitCast<const std::string&>(explicitCastTest));
    PtrTest(ExplicitCast<const std::string*>(explicitCastTest));

#if 0  // ����Ӧ�ò����������

    IntegerTest(explicitCastTest);

#endif  // 0

#if 0  // ����Ӧ�ò����������

    StringTest(explicitCastTest);

#endif  // 0

#if 0  // ����Ӧ�ò����������

    PtrTest(explicitCastTest);

#endif  // 0
}

void CoreTools::ExplicitCastTesting::IntegerTest(int value)
{
    ASSERT_EQUAL(value, 1);
}

void CoreTools::ExplicitCastTesting::StringTest(const std::string& value)
{
    ASSERT_EQUAL(value, "ss");
}

void CoreTools::ExplicitCastTesting::PtrTest(const std::string* value)
{
    if (value != nullptr)
    {
        ASSERT_EQUAL(*value, "ss");
    }
}
