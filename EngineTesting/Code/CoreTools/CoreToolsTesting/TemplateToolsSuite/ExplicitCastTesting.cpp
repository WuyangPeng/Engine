///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 19:01)

#include "ExplicitCastTesting.h"
#include "Detail/ExplicitCastTest.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/ExplicitCastDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::string;

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
    StringTest(ExplicitCast<const string&>(explicitCastTest));
    PtrTest(ExplicitCast<const string*>(explicitCastTest));

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

void CoreTools::ExplicitCastTesting::StringTest(const string& value)
{
    ASSERT_EQUAL(value, "ss");
}

void CoreTools::ExplicitCastTesting::PtrTest(const string* value)
{
    if (value != nullptr)
    {
        ASSERT_EQUAL(*value, "ss");
    }
}
