// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:32)

#include "ObjectRegisterTesting.h"
#include "Detail/NullObject.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/Helper/AssertMacro.h"

#include "CoreTools/Helper/ClassInvariantMacro.h"


#include "System/Helper/PragmaWarning/NumericCast.h"
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ObjectRegisterTesting)

void CoreTools::ObjectRegisterTesting
	::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIDExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(RegisterRootSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(RegisterObjectPtrSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(RegisterObjectPtrArraySucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(RegisterObjectSmartPtrSucceedTest);
	ASSERT_NOT_THROW_EXCEPTION_0(RegisterObjectSmartPtrArraySucceedTest);
}

void CoreTools::ObjectRegisterTesting ::UniqueIDExceptionTest() noexcept
{
    // 	ObjectRegister objectRegister{};
// 	ObjectInterfaceSmartPointer objectPtr{ NEW0 NullObject };
// 
// 	ASSERT_EQUAL(objectRegister.GetOrderedSize(), 0);
// 	objectRegister.GetUniqueID(objectPtr);
}

void CoreTools::ObjectRegisterTesting ::RegisterRootSucceedTest() noexcept
{
    // 	auto testLoopCount = GetTestLoopCount();
// 
// 	ObjectRegister objectRegister{};
// 
// 	ASSERT_EQUAL(objectRegister.GetOrderedSize(), 0);
// 
// 	vector<ObjectInterfaceSmartPointer> objectSmartPtrVector{};
// 
// 	for (auto index = 0; index < testLoopCount; ++index)
// 	{
// 		objectSmartPtrVector.emplace_back(NEW0 NullObject);
// 	}
// 
// 	objectRegister.RegisterRoot(ConstObjectInterfaceSmartPointer{});
// 
// 	for (auto index = 0; index < testLoopCount; ++index)
// 	{
// 		objectRegister.RegisterRoot(objectSmartPtrVector[index]);
// 
// 		ASSERT_EQUAL(objectRegister.GetOrderedSize(), index + 2);
// 		ASSERT_EQUAL(objectRegister.GetUniqueID(objectSmartPtrVector[index]), boost::numeric_cast<uint64_t>(index + 1));
// 		ASSERT_EQUAL(objectRegister[index + 1], objectSmartPtrVector[index]);
// 	}
}

void CoreTools::ObjectRegisterTesting ::RegisterObjectPtrSucceedTest() noexcept
{
    // 	auto testLoopCount = GetTestLoopCount();
// 
// 	ObjectRegister objectRegister{};
// 
// 	ASSERT_EQUAL(objectRegister.GetOrderedSize(), 0);
// 
// 	vector<ObjectInterfaceSmartPointer> objectSmartPtrVector{};
// 
// 	for (auto index = 0; index < testLoopCount; ++index)
// 	{
// 		objectSmartPtrVector.emplace_back(NEW0 NullObject);
// 	}
// 
// 	for (auto index = 0; index < testLoopCount; ++index)
// 	{
// 		objectRegister.Register(objectSmartPtrVector[index].GetData());
// 
// 		ASSERT_EQUAL(objectRegister.GetOrderedSize(), index + 1);
// 		ASSERT_EQUAL(objectRegister.GetUniqueID(objectSmartPtrVector[index]), boost::numeric_cast<uint64_t>(index));
// 		ASSERT_EQUAL(objectRegister[index], objectSmartPtrVector[index]);
// 	}
}

void CoreTools::ObjectRegisterTesting ::RegisterObjectPtrArraySucceedTest() noexcept
{
    // 	auto testLoopCount = GetTestLoopCount();
// 
// 	ObjectRegister objectRegister{};
// 
// 	ASSERT_EQUAL(objectRegister.GetOrderedSize(), 0);
// 
// 	vector<ObjectInterfaceSmartPointer> objectSmartPtrVector{};
// 	vector<ObjectPtr> objectPtrVector{};
// 
// 	for (auto index = 0; index < testLoopCount; ++index)
// 	{
// 		objectSmartPtrVector.emplace_back(NEW0 NullObject);
// 		objectPtrVector.push_back(objectSmartPtrVector[index].GetData());
// 	}
// 
// 	objectRegister.Register(testLoopCount, objectPtrVector.data());
// 
// 	for (auto index = 0; index < testLoopCount; ++index)
// 	{
// 		ASSERT_EQUAL(objectRegister.GetUniqueID(objectSmartPtrVector[index]), boost::numeric_cast<uint64_t>(index));
// 		ASSERT_EQUAL(objectRegister[index], objectPtrVector[index]);
// 	}
// 
// 	ASSERT_EQUAL(objectRegister.GetOrderedSize(), testLoopCount);
}

void CoreTools::ObjectRegisterTesting ::RegisterObjectSmartPtrSucceedTest() noexcept
{
    // 	auto testLoopCount = GetTestLoopCount();
// 
// 	ObjectRegister objectRegister{};
// 
// 	ASSERT_EQUAL(objectRegister.GetOrderedSize(), 0);
// 
// 	vector<ObjectInterfaceSmartPointer> objectSmartPtrVector{};
// 
// 	for (auto index = 0; index < testLoopCount; ++index)
// 	{
// 		objectSmartPtrVector.emplace_back(NEW0 NullObject);
// 	}
// 
// 	for (auto index = 0; index < testLoopCount; ++index)
// 	{
// 		objectRegister.Register(objectSmartPtrVector[index].GetData());
// 
// 		ASSERT_EQUAL(objectRegister.GetOrderedSize(), index + 1);
// 		ASSERT_EQUAL(objectRegister.GetUniqueID(objectSmartPtrVector[index]), boost::numeric_cast<uint64_t>(index));
// 		ASSERT_EQUAL(objectRegister[index], objectSmartPtrVector[index]);
// 	}
}

void CoreTools::ObjectRegisterTesting ::RegisterObjectSmartPtrArraySucceedTest() noexcept
{
    // 	auto testLoopCount = GetTestLoopCount();
// 
// 	ObjectRegister objectRegister{};
// 
// 	ASSERT_EQUAL(objectRegister.GetOrderedSize(), 0);
// 
// 	vector<ObjectInterfaceSmartPointer> objectSmartPtrVector;
// 
// 	for (auto index = 0; index < testLoopCount; ++index)
// 	{
// 		objectSmartPtrVector.emplace_back(NEW0 NullObject);
// 	}
// 
// 	objectRegister.RegisterSmartPointer(testLoopCount, objectSmartPtrVector.data());
// 
// 	for (auto index = 0; index < testLoopCount; ++index)
// 	{
// 		ASSERT_EQUAL(objectRegister.GetUniqueID(objectSmartPtrVector[index]), boost::numeric_cast<uint64_t>(index));
// 		ASSERT_EQUAL(objectRegister[index], objectSmartPtrVector[index]);
// 	}
// 
// 	ASSERT_EQUAL(objectRegister.GetOrderedSize(), testLoopCount);
}

