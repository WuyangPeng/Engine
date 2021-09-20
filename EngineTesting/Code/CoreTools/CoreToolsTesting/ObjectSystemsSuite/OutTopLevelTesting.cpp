// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.2.3 (2020/03/06 14:33)

#include "OutTopLevelTesting.h"
#include "Detail/NullObject.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SmartPointerManager.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, OutTopLevelTesting)

void CoreTools::OutTopLevelTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(TopLevelTest);
}

void CoreTools::OutTopLevelTesting ::TopLevelTest() noexcept
{
    // 	OutTopLevel topLevel{};
// 	ObjectInterfaceSmartPointer objectPtr{ NEW0 NullObject };
// 	objectPtr->SetUniqueID(0);
// 
// 	ASSERT_EQUAL(topLevel.GetTopLevelSize(), 0);
// 	ASSERT_FALSE(topLevel.IsTopLevel(objectPtr->GetUniqueID()));
// 
// 	auto testLoopCount = GetTestLoopCount();
// 
// 	for (auto index = 0; index < testLoopCount; ++index)
// 	{
// 		ObjectInterfaceSmartPointer nullObjectPtr{ NEW0 NullObject };
// 		topLevel.Insert(nullObjectPtr);
// 		auto nextUniqueID = index + 1;
// 		topLevel.SetUniqueID(index, nextUniqueID);
// 
// 		ASSERT_EQUAL(topLevel.GetTopLevelSize(), index + 1);
// 		ASSERT_FALSE(topLevel.IsTopLevel(objectPtr->GetUniqueID()));
// 		ASSERT_TRUE(topLevel.IsTopLevel(nullObjectPtr->GetUniqueID()));
// 		ASSERT_EQUAL(topLevel[index], nullObjectPtr);
// 	}
}

