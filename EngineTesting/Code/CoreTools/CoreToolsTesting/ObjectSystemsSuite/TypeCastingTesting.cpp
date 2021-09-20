// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:34)

#include "TypeCastingTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/StringObject.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

using std::make_shared;
using std::shared_ptr;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TypeCastingTesting)

void CoreTools::TypeCastingTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticCastSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicCastSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PolymorphicCastSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedPtrDynamicCastSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedPtrPolymorphicCastSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedPtrExceptionTest);
}

void CoreTools::TypeCastingTesting ::StaticCastSucceedTest() noexcept
{
    // 	NullObject nullObject;
    // 	ObjectPtr ptr{ &nullObject };
    // 	ConstObjectPtr constPtr{ &nullObject };
    //
    // 	auto nullObjectPtr = StaticCast<NullObject>(ptr);
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(nullObjectPtr);
    //
    // 	auto constNullObjectPtr = StaticCast<NullObject>(constPtr);
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(constNullObjectPtr);
}

void CoreTools::TypeCastingTesting ::DynamicCastSucceedTest() noexcept
{
    // 	NullObject nullObject{};
    // 	ObjectPtr ptr{ &nullObject };
    // 	ConstObjectPtr constPtr{ &nullObject };
    //
    // 	NullObject* nullObjectPtr = DynamicCast<NullObject>(ptr);
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(nullObjectPtr);
    //
    // 	auto constNullObjectPtr = DynamicCast<NullObject>(constPtr);
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(constNullObjectPtr);
    //
    // 	auto boolObjectPtr = DynamicCast<BoolObject>(ptr);
    //
    // 	ASSERT_EQUAL_NULL_PTR(boolObjectPtr);
    //
    // 	auto constBoolObjectPtr = DynamicCast<BoolObject>(constPtr);
    //
    // 	ASSERT_EQUAL_NULL_PTR(constBoolObjectPtr);
}

void CoreTools::TypeCastingTesting ::PolymorphicCastSucceedTest() noexcept
{
    // 	NullObject nullObject{};
    // 	ObjectPtr ptr{ &nullObject };
    // 	ConstObjectPtr constPtr{ &nullObject };
    //
    // 	auto nullObjectPtr = PolymorphicDowncast<NullObject>(ptr);
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(nullObjectPtr);
    //
    // 	auto constNullObjectPtr = PolymorphicDowncast<NullObject>(constPtr);
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(constNullObjectPtr);
    //
    // 	nullObjectPtr = PolymorphicCast<NullObject>(ptr);
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(nullObjectPtr);
    //
    // 	constNullObjectPtr = PolymorphicCast<NullObject>(constPtr);
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(constNullObjectPtr);
}

void CoreTools::TypeCastingTesting ::ExceptionTest() noexcept
{
    // 	NullObject nullObject{};
    // 	ObjectPtr ptr{ &nullObject };
    //
    // 	auto boolObjectPtr = PolymorphicCast<BoolObject>(ptr);
    //
    // 	SYSTEM_UNUSED_ARG(boolObjectPtr);
}

void CoreTools::TypeCastingTesting ::SharedPtrDynamicCastSucceedTest() noexcept
{
    // 	shared_ptr<ObjectInterface> nullObjectPtr{ make_shared<NullObject>() };
    //
    // 	auto constNullObjectPtr = PolymorphicSharedPtrCast<NullObject>(nullObjectPtr);
    //
    // 	ASSERT_EQUAL(constNullObjectPtr, nullObjectPtr);
}

void CoreTools::TypeCastingTesting ::SharedPtrPolymorphicCastSucceedTest() noexcept
{
    // 	shared_ptr<ObjectInterface> nullObjectPtr{ make_shared<NullObject>() };
    //
    // 	auto constNullObjectPtr = PolymorphicSharedPtrDowncast<NullObject>(nullObjectPtr);
    //
    // 	ASSERT_EQUAL(constNullObjectPtr, nullObjectPtr);
}

void CoreTools::TypeCastingTesting ::SharedPtrExceptionTest() noexcept
{
    // 	shared_ptr<ObjectInterface> nullObjectPtr{ make_shared<NullObject>() };
    //
    // 	auto constNullObjectPtr = PolymorphicSharedPtrCast<StringObject>(nullObjectPtr);
}
