// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:30)

#include "ObjectManagerTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/StringObject.h"
#include "Detail/IntObject.h"
#include "Detail/NullObject.h"
#include "Detail/EnumObject.h"
#include "Detail/PointerObject.h"
#include "Detail/ErrorObject.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectLink.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ObjectManagerTesting)

void CoreTools::ObjectManagerTesting
	::MainTest()
{
	InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(SucceedTest);
	ASSERT_THROW_EXCEPTION_0(ExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(InsertTest);

	InitTerm::ExecuteTerminators();
}

void CoreTools::ObjectManagerTesting
	::SucceedTest()
{
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(ObjectInterface::GetCurrentRttiType().GetName()));
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(NullObject::GetCurrentRttiType().GetName()));
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(BoolObject::GetCurrentRttiType().GetName()));
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(IntObject::GetCurrentRttiType().GetName()));
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(StringObject::GetCurrentRttiType().GetName()));
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(EnumObject::GetCurrentRttiType().GetName()));
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(PointerObject::GetCurrentRttiType().GetName()));
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(Object::GetCurrentRttiType().GetName()));
}

void CoreTools::ObjectManagerTesting
	::ExceptionTest()
{
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(ErrorObject::GetCurrentRttiType().GetName()));
}

void CoreTools::ObjectManagerTesting
	::InsertTest()
{
    OBJECT_MANAGER_SINGLETON.Insert(ErrorObject::GetCurrentRttiType().GetName(), ErrorObject::Factory);
    ASSERT_UNEQUAL_NULL_PTR(OBJECT_MANAGER_SINGLETON.Find(ErrorObject::GetCurrentRttiType().GetName()));
}

