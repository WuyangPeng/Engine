/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/18 20:28)

#include "TypeTraitsTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/TypeTraits.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define COMPILE_ERROR_TEST

#undef COMPILE_ERROR_TEST

CoreTools::TypeTraitsTesting::TypeTraitsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TypeTraitsTesting)

void CoreTools::TypeTraitsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::TypeTraitsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TypeTraitsTest);
}

void CoreTools::TypeTraitsTesting::TypeTraitsTest() noexcept
{
    MAYBE_UNUSED constexpr TraitSelector<true> traitSelector0{};
    MAYBE_UNUSED constexpr IsNotArbitraryPrecisionType<float> isNotArbitraryPrecisionType0{};
    MAYBE_UNUSED constexpr IsDivisionType<float> isDivisionType0{};
    MAYBE_UNUSED constexpr IsNotDivisionType<int> isNotDivisionType0{};

#ifdef COMPILE_ERROR_TEST

    MAYBE_UNUSED constexpr TraitSelector<false> traitSelector1{};
    MAYBE_UNUSED constexpr IsArbitraryPrecisionType<float> isArbitraryPrecisionType0{};
    MAYBE_UNUSED constexpr IsDivisionType<int> isDivisionType1{};
    MAYBE_UNUSED constexpr IsNotDivisionType<float> isNotDivisionType1{};

#endif  // COMPILE_ERROR_TEST
}