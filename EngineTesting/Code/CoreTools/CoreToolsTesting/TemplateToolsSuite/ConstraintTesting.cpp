///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 18:56)

#include "ConstraintTesting.h"

#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MustBePod.h"
#include "CoreTools/TemplateTools/MustBeSameSize.h"
#include "CoreTools/TemplateTools/MustBeSubscriptable.h"
#include "CoreTools/TemplateTools/MustHaveBase.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ConstraintTesting)

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

#if 0  // ����Ӧ�ò����������

    MAYBE_UNUSED MustBePod<void> voidMustBePod{};

#endif  // 0

#if 0  // ����Ӧ�ò����������

    MAYBE_UNUSED MustBePod<ConstraintTesting> constraintTestingMustBePod{];

#endif  // 0

    MAYBE_UNUSED const MustBePodOrVoid<float> floatMustBePodOrVoid{};
    MAYBE_UNUSED const MustBePodOrVoid<void> voidMustBePodOrVoid{};

#if 0  // ����Ӧ�ò����������

    MAYBE_UNUSED MustBePodOrVoid<ConstraintTesting> constraintTestingMustBePodOrVoid{};

#endif  // 0
}

void CoreTools::ConstraintTesting::MustBeSameSizeTest() noexcept
{
    MAYBE_UNUSED const MustBeSameSize<int, unsigned int> integerMustBeSameSize{};
    MAYBE_UNUSED const MustBeSameSize<long, unsigned long> longMustBeSameSize{};

#if 0  // ����Ӧ�ò����������

    MAYBE_UNUSED MustBeSameSize<char, long> charAndLongMustBeSameSize{};

#endif  // 0
}

void CoreTools::ConstraintTesting::MustBeSubscriptableTest() noexcept
{
    MAYBE_UNUSED const MustBeSubscriptable<Tuple<3, int>> tupleMustBeSubscriptable{};
    MAYBE_UNUSED const MustBeSubscriptable<string> stringMustBeSubscriptable{};

#if 0  // ����Ӧ�ò����������

    MAYBE_UNUSED MustBeSubscriptable<int> integerMustBeSubscriptable{};

#endif  // 0

    MAYBE_UNUSED const MustBeSubscriptableAsDecayablePointer<string*> stringPtrMustBeSubscriptableAsDecayablePointer{};

#if 0  // ����Ӧ�ò����������

    MAYBE_UNUSED MustBeSubscriptableAsDecayablePointer<Tuple<3, int>> tupleMustBeSubscriptableAsDecayablePointer{};

#endif  // 0

#if 0  // ����Ӧ�ò����������

    MAYBE_UNUSED MustBeSubscriptableAsDecayablePointer<string> stringMustBeSubscriptableAsDecayablePointer{};

#endif  // 0
}

void CoreTools::ConstraintTesting::MustHaveBaseTest() noexcept
{
    MAYBE_UNUSED const MustHaveBase<ClassType, ParentType> mustHaveBase{};

#if 0  // ����Ӧ�ò����������

    MAYBE_UNUSED MustHaveBase<ParentType, ClassType> errorMustHaveBase{};

#endif  // 0
}
