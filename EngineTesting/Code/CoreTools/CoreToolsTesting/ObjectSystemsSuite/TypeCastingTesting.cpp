///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 15:44)

#include "TypeCastingTesting.h"
#include "Detail/BoolObject.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

using std::make_shared;
using std::shared_ptr;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TypeCastingTesting)

void CoreTools::TypeCastingTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StaticCastSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicCastSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PolymorphicCastSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedPtrDynamicCastSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedPtrPolymorphicCastSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedPtrExceptionTest);
}

void CoreTools::TypeCastingTesting::StaticCastSucceedTest() noexcept
{
}

void CoreTools::TypeCastingTesting::DynamicCastSucceedTest() noexcept
{
}

void CoreTools::TypeCastingTesting::PolymorphicCastSucceedTest() noexcept
{
}

void CoreTools::TypeCastingTesting::ExceptionTest() noexcept
{
}

void CoreTools::TypeCastingTesting::SharedPtrDynamicCastSucceedTest() noexcept
{
}

void CoreTools::TypeCastingTesting::SharedPtrPolymorphicCastSucceedTest() noexcept
{
}

void CoreTools::TypeCastingTesting::SharedPtrExceptionTest() noexcept
{
}
