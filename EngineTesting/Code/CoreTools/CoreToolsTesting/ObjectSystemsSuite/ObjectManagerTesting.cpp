///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 15:42)

#include "ObjectManagerTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/ErrorObject.h"
#include "Detail/IntObject.h"
#include "CoreTools/ObjectSystems/NullObject.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectLink.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
CoreTools::ObjectManagerTesting::ObjectManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ObjectManagerTesting)

void CoreTools::ObjectManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ObjectManagerTesting::MainTest()
{
    InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(SucceedTest);
    ASSERT_THROW_EXCEPTION_0(ExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InsertTest);

    InitTerm::ExecuteTerminators();
}

void CoreTools::ObjectManagerTesting::SucceedTest()
{
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(ObjectInterface::GetCurrentRttiType().GetName()));
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(NullObject::GetCurrentRttiType().GetName()));
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(BoolObject::GetCurrentRttiType().GetName()));
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(IntObject::GetCurrentRttiType().GetName()));
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(EnumObject::GetCurrentRttiType().GetName()));
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(Object::GetCurrentRttiType().GetName()));
}

void CoreTools::ObjectManagerTesting::ExceptionTest()
{
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(ErrorObject::GetCurrentRttiType().GetName()));
}

void CoreTools::ObjectManagerTesting::InsertTest()
{
    OBJECT_MANAGER_SINGLETON.Insert(ErrorObject::GetCurrentRttiType().GetName(), ErrorObject::Factory);
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(ErrorObject::GetCurrentRttiType().GetName()));
}
