/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:35)

#include "ExplicitCastTesting.h"
#include "Detail/ExplicitCastTest.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/ExplicitCastDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define EXPLICIT_CAST_COMPILE_ERROR

#undef EXPLICIT_CAST_COMPILE_ERROR

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

#ifdef EXPLICIT_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

    IntegerTest(explicitCastTest);

#endif  // EXPLICIT_CAST_COMPILE_ERROR

#ifdef EXPLICIT_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

    StringTest(explicitCastTest);

#endif  // EXPLICIT_CAST_COMPILE_ERROR

#ifdef EXPLICIT_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

    PtrTest(explicitCastTest);

#endif  // EXPLICIT_CAST_COMPILE_ERROR
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
