///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:31)

#include "ImplStaticAssertHelperTesting.h"
#include "CoreTools/Contract/ImplStaticAssertHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <type_traits>

using std::is_same;

CoreTools::ImplStaticAssertHelperTesting::ImplStaticAssertHelperTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ImplStaticAssertHelperTesting)

void CoreTools::ImplStaticAssertHelperTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ImplStaticAssertHelperTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticAssertTest);
}

void CoreTools::ImplStaticAssertHelperTesting::StaticAssertTest() noexcept
{
    static_assert(is_same<CoreTools::TrueType, ShareClasses::NonConstMember>::value, "test static assert");
    static_assert(is_same<CoreTools::FalseType, ShareClasses::NonConstCopyMember>::value, "test static assert");
    static_assert(is_same<CoreTools::FalseType, ShareClasses::CopyConstructor>::value, "test static assert");

    static_assert(is_same<CoreTools::FalseType, PerformanceUnsharedClasses::NonConstMember>::value, "test static assert");
    static_assert(is_same<CoreTools::FalseType, PerformanceUnsharedClasses::NonConstCopyMember>::value, "test static assert");
    static_assert(is_same<CoreTools::FalseType, PerformanceUnsharedClasses::CopyConstructor>::value, "test static assert");

    static_assert(is_same<CoreTools::TrueType, CopyUnsharedClasses::NonConstMember>::value, "test static assert");
    static_assert(is_same<CoreTools::FalseType, CopyUnsharedClasses::NonConstCopyMember>::value, "test static assert");
    static_assert(is_same<CoreTools::TrueType, CopyUnsharedClasses::CopyConstructor>::value, "test static assert");

    static_assert(is_same<CoreTools::FalseType, DelayCopyUnsharedClasses::NonConstMember>::value, "test static assert");
    static_assert(is_same<CoreTools::TrueType, DelayCopyUnsharedClasses::NonConstCopyMember>::value, "test static assert");
    static_assert(is_same<CoreTools::FalseType, DelayCopyUnsharedClasses::CopyConstructor>::value, "test static assert");

    static_assert(is_same<CoreTools::TrueType, NonCopyClasses::NonConstMember>::value, "test static assert");
    static_assert(is_same<CoreTools::FalseType, NonCopyClasses::NonConstCopyMember>::value, "test static assert");
    static_assert(is_same<CoreTools::FalseType, NonCopyClasses::CopyConstructor>::value, "test static assert");
}
