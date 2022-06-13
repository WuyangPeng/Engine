///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:42)

#include "ObjectRegisterTesting.h"
#include "Detail/NullObject.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"

#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ObjectRegisterTesting)

void CoreTools::ObjectRegisterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIDExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterRootSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterObjectPtrSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterObjectPtrArraySucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterObjectSmartPtrSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterObjectSmartPtrArraySucceedTest);
}

void CoreTools::ObjectRegisterTesting::UniqueIDExceptionTest() noexcept
{
}

void CoreTools::ObjectRegisterTesting::RegisterRootSucceedTest() noexcept
{
}

void CoreTools::ObjectRegisterTesting::RegisterObjectPtrSucceedTest() noexcept
{
}

void CoreTools::ObjectRegisterTesting::RegisterObjectPtrArraySucceedTest() noexcept
{
}

void CoreTools::ObjectRegisterTesting::RegisterObjectSmartPtrSucceedTest() noexcept
{
}

void CoreTools::ObjectRegisterTesting::RegisterObjectSmartPtrArraySucceedTest() noexcept
{
}
