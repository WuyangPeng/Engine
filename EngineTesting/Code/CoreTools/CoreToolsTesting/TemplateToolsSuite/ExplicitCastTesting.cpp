// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/06 16:03)

#include "ExplicitCastTesting.h"
#include "Detail/ExplicitCastTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/ExplicitCastDetail.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ExplicitCastTesting)

void CoreTools::ExplicitCastTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CastTest);
}

void CoreTools::ExplicitCastTesting ::CastTest()
{
    ExplicitCastTest explicitCastTest;

    IntegerTest(ExplicitCast<int>(explicitCastTest));
    StringTest(ExplicitCast<const string&>(explicitCastTest));
    PtrTest(ExplicitCast<const string*>(explicitCastTest));

#if 0  // 这里应该产生编译错误。
	IntegerTest(explicitCastTest);
#endif  // 0

#if 0  // 这里应该产生编译错误。
	StringTest(explicitCastTest);
#endif  // 0

#if 0  // 这里应该产生编译错误。
	PtrTest(explicitCastTest);
#endif  // 0
}

void CoreTools::ExplicitCastTesting ::IntegerTest(int value)
{
    ASSERT_EQUAL(value, 1);
}

void CoreTools::ExplicitCastTesting ::StringTest(const string& value)
{
    ASSERT_EQUAL(value, "ss");
}

void CoreTools::ExplicitCastTesting ::PtrTest(const string* value)
{
    if (value != nullptr)
    {
        ASSERT_EQUAL(*value, "ss");
    }
}
