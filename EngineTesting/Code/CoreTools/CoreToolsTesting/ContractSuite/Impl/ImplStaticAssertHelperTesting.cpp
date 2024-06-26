/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/25 22:24)

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

void CoreTools::ImplStaticAssertHelperTesting::StaticAssertTest()  
{
    ASSERT_NOT_THROW_EXCEPTION_0(ShareClassesStaticAssertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedClassesStaticAssertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedClassesStaticAssertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedClassesStaticAssertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyClassesStaticAssertTest);
}

void CoreTools::ImplStaticAssertHelperTesting::ShareClassesStaticAssertTest() noexcept
{
    static_assert(std::is_same_v<TrueType, ShareClasses::NonConstMember>, "test static assert");
    static_assert(std::is_same_v<FalseType, ShareClasses::NonConstCopyMember>, "test static assert");
    static_assert(std::is_same_v<FalseType, ShareClasses::CopyConstructor>, "test static assert");
}

void CoreTools::ImplStaticAssertHelperTesting::PerformanceUnsharedClassesStaticAssertTest() noexcept
{
    static_assert(std::is_same_v<FalseType, PerformanceUnsharedClasses::NonConstMember>, "test static assert");
    static_assert(std::is_same_v<FalseType, PerformanceUnsharedClasses::NonConstCopyMember>, "test static assert");
    static_assert(std::is_same_v<FalseType, PerformanceUnsharedClasses::CopyConstructor>, "test static assert");
}

void CoreTools::ImplStaticAssertHelperTesting::CopyUnsharedClassesStaticAssertTest() noexcept
{
    static_assert(std::is_same_v<TrueType, CopyUnsharedClasses::NonConstMember>, "test static assert");
    static_assert(std::is_same_v<FalseType, CopyUnsharedClasses::NonConstCopyMember>, "test static assert");
    static_assert(std::is_same_v<TrueType, CopyUnsharedClasses::CopyConstructor>, "test static assert");
}

void CoreTools::ImplStaticAssertHelperTesting::DelayCopyUnsharedClassesStaticAssertTest() noexcept
{
    static_assert(std::is_same_v<FalseType, DelayCopyUnsharedClasses::NonConstMember>, "test static assert");
    static_assert(std::is_same_v<TrueType, DelayCopyUnsharedClasses::NonConstCopyMember>, "test static assert");
    static_assert(std::is_same_v<FalseType, DelayCopyUnsharedClasses::CopyConstructor>, "test static assert");
}

void CoreTools::ImplStaticAssertHelperTesting::NonCopyClassesStaticAssertTest() noexcept
{
    static_assert(std::is_same_v<TrueType, NonCopyClasses::NonConstMember>, "test static assert");
    static_assert(std::is_same_v<FalseType, NonCopyClasses::NonConstCopyMember>, "test static assert");
    static_assert(std::is_same_v<FalseType, NonCopyClasses::CopyConstructor>, "test static assert");
}
