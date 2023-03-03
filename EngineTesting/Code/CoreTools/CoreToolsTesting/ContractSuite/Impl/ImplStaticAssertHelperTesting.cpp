///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/02/23 14:35)

#include "ImplStaticAssertHelperTesting.h"
#include "CoreTools/Contract/ImplStaticAssertHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <type_traits>

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
    static_assert(std::is_same_v<CoreTools::TrueType, ShareClasses::NonConstMember>, "test static assert");
    static_assert(std::is_same_v<CoreTools::FalseType, ShareClasses::NonConstCopyMember>, "test static assert");
    static_assert(std::is_same_v<CoreTools::FalseType, ShareClasses::CopyConstructor>, "test static assert");

    static_assert(std::is_same_v<CoreTools::FalseType, PerformanceUnsharedClasses::NonConstMember>, "test static assert");
    static_assert(std::is_same_v<CoreTools::FalseType, PerformanceUnsharedClasses::NonConstCopyMember>, "test static assert");
    static_assert(std::is_same_v<CoreTools::FalseType, PerformanceUnsharedClasses::CopyConstructor>, "test static assert");

    static_assert(std::is_same_v<CoreTools::TrueType, CopyUnsharedClasses::NonConstMember>, "test static assert");
    static_assert(std::is_same_v<CoreTools::FalseType, CopyUnsharedClasses::NonConstCopyMember>, "test static assert");
    static_assert(std::is_same_v<CoreTools::TrueType, CopyUnsharedClasses::CopyConstructor>, "test static assert");

    static_assert(std::is_same_v<CoreTools::FalseType, DelayCopyUnsharedClasses::NonConstMember>, "test static assert");
    static_assert(std::is_same_v<CoreTools::TrueType, DelayCopyUnsharedClasses::NonConstCopyMember>, "test static assert");
    static_assert(std::is_same_v<CoreTools::FalseType, DelayCopyUnsharedClasses::CopyConstructor>, "test static assert");

    static_assert(std::is_same_v<CoreTools::TrueType, NonCopyClasses::NonConstMember>, "test static assert");
    static_assert(std::is_same_v<CoreTools::FalseType, NonCopyClasses::NonConstCopyMember>, "test static assert");
    static_assert(std::is_same_v<CoreTools::FalseType, NonCopyClasses::CopyConstructor>, "test static assert");
}
