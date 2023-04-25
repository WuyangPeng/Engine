///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 11:13)

#include "ConstraintTesting.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MustBePod.h"
#include "CoreTools/TemplateTools/MustBeSameSize.h"
#include "CoreTools/TemplateTools/MustBeSubscriptable.h"
#include "CoreTools/TemplateTools/MustHaveBase.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ConstraintTesting::ConstraintTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ConstraintTesting)

void CoreTools::ConstraintTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ConstraintTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MustBePodTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MustBeSameSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MustBeSubscriptableTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MustHaveBaseTest);
}

void CoreTools::ConstraintTesting::MustBePodTest() noexcept
{
    MAYBE_UNUSED const MustBePod<int> integerMustBePod{};

#if 0  // 这里应该产生编译错误。

    MAYBE_UNUSED MustBePod<void> voidMustBePod{};

#endif  // 0

#if 0  // 这里应该产生编译错误。

    MAYBE_UNUSED MustBePod<ConstraintTesting> constraintTestingMustBePod{];

#endif  // 0

    MAYBE_UNUSED const MustBePodOrVoid<float> floatMustBePodOrVoid{};
    MAYBE_UNUSED constexpr MustBePodOrVoid<void> voidMustBePodOrVoid{};

#if 0  // 这里应该产生编译错误。

    MAYBE_UNUSED MustBePodOrVoid<ConstraintTesting> constraintTestingMustBePodOrVoid{};

#endif  // 0
}

void CoreTools::ConstraintTesting::MustBeSameSizeTest() noexcept
{
    MAYBE_UNUSED const MustBeSameSize<int, unsigned int> integerMustBeSameSize{};
    MAYBE_UNUSED const MustBeSameSize<long, unsigned long> longMustBeSameSize{};

#if 0  // 这里应该产生编译错误。

    MAYBE_UNUSED MustBeSameSize<char, long> charAndLongMustBeSameSize{};

#endif  // 0
}

void CoreTools::ConstraintTesting::MustBeSubscriptableTest() noexcept
{
    MAYBE_UNUSED const MustBeSubscriptable<Tuple<3, int>> tupleMustBeSubscriptable{};
    MAYBE_UNUSED const MustBeSubscriptable<std::string> stringMustBeSubscriptable{};

#if 0  // 这里应该产生编译错误。

    MAYBE_UNUSED MustBeSubscriptable<int> integerMustBeSubscriptable{};

#endif  // 0

    MAYBE_UNUSED const MustBeSubscriptableAsDecayablePointer<std::string*> stringPtrMustBeSubscriptableAsDecayablePointer{};

#if 0  // 这里应该产生编译错误。

    MAYBE_UNUSED MustBeSubscriptableAsDecayablePointer<Tuple<3, int>> tupleMustBeSubscriptableAsDecayablePointer{};

#endif  // 0

#if 0  // 这里应该产生编译错误。

    MAYBE_UNUSED MustBeSubscriptableAsDecayablePointer<string> stringMustBeSubscriptableAsDecayablePointer{};

#endif  // 0
}

void CoreTools::ConstraintTesting::MustHaveBaseTest() noexcept
{
    MAYBE_UNUSED const MustHaveBase<ClassType, ParentType> mustHaveBase{};

#if 0  // 这里应该产生编译错误。

    MAYBE_UNUSED MustHaveBase<ParentType, ClassType> errorMustHaveBase{};

#endif  // 0
}
