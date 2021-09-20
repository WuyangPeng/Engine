// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.3 (2020/03/06 15:55)

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

void CoreTools::ConstraintTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MustBePodTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MustBeSameSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MustBeSubscriptableTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MustHaveBaseTest);
}

void CoreTools::ConstraintTesting ::MustBePodTest() noexcept
{
    [[maybe_unused]] const MustBePod<int> integerMustBePod;

#if 0  // ����Ӧ�ò����������
	MustBePod<void> voidMustBePod;
	SYSTEM_UNUSED_ARG(voidMustBePod);
#endif  // 0

#if 0  // ����Ӧ�ò����������
	MustBePod<ConstraintTesting> constraintTestingMustBePod;
	SYSTEM_UNUSED_ARG(constraintTestingMustBePod);
#endif  // 0

    [[maybe_unused]] const MustBePodOrVoid<float> floatMustBePodOrVoid;
    [[maybe_unused]] const MustBePodOrVoid<void> voidMustBePodOrVoid;

#if 0  // ����Ӧ�ò����������
	MustBePodOrVoid<ConstraintTesting> constraintTestingMustBePodOrVoid;
	SYSTEM_UNUSED_ARG(constraintTestingMustBePodOrVoid);
#endif  // 0
}

void CoreTools::ConstraintTesting ::MustBeSameSizeTest() noexcept
{
    [[maybe_unused]] const MustBeSameSize<int, unsigned int> integerMustBeSameSize;
    [[maybe_unused]] const MustBeSameSize<long, unsigned long> longMustBeSameSize;

#if 0  // ����Ӧ�ò����������
	MustBeSameSize<char, long> charAndLongMustBeSameSize;
	SYSTEM_UNUSED_ARG(charAndLongMustBeSameSize);
#endif  // 0
}

void CoreTools::ConstraintTesting ::MustBeSubscriptableTest() noexcept
{
    [[maybe_unused]] const MustBeSubscriptable<Tuple<3, int>> tupleMustBeSubscriptable;
    [[maybe_unused]] const MustBeSubscriptable<string> stringMustBeSubscriptable;

#if 0  // ����Ӧ�ò����������
	MustBeSubscriptable<int> integerMustBeSubscriptable;
	SYSTEM_UNUSED_ARG(integerMustBeSubscriptable);
#endif  // 0

    [[maybe_unused]] const MustBeSubscriptableAsDecayablePointer<string*> stringPtrMustBeSubscriptableAsDecayablePointer;

#if 0  // ����Ӧ�ò����������
	MustBeSubscriptableAsDecayablePointer<Tuple<3, int> > tupleMustBeSubscriptableAsDecayablePointer;
	SYSTEM_UNUSED_ARG(tupleMustBeSubscriptableAsDecayablePointer);
#endif  // 0

#if 0  // ����Ӧ�ò����������
	MustBeSubscriptableAsDecayablePointer<string> stringMustBeSubscriptableAsDecayablePointer;
	SYSTEM_UNUSED_ARG(stringMustBeSubscriptableAsDecayablePointer);
#endif  // 0
}

void CoreTools::ConstraintTesting ::MustHaveBaseTest() noexcept
{
    [[maybe_unused]] const MustHaveBase<ClassType, ParentType> mustHaveBase;

#if 0  // ����Ӧ�ò����������
	MustHaveBase<ParentType, ClassType> errorMustHaveBase;
	SYSTEM_UNUSED_ARG(errorMustHaveBase);
#endif  // 0
}
