// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:03)

#include "ParametersInterfaceTesting.h"
#include "Detail/Parameters.h"
#include "CoreTools/Helper/AssertMacro.h"  
#include "CoreTools/Helper/MemoryMacro.h" 
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/MessageEvent/ParametersInterface.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(CoreTools, ParametersInterface)

void CoreTools::ParametersInterfaceTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CloneTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SubclassTest);
}

void CoreTools::ParametersInterfaceTesting
	::CloneTest()
{
	TestingType parametersInterface;
	ParametersInterfaceSharedPtr smartPointer{ make_shared<TestingType>(parametersInterface) };
	auto cloneSmartPointer = smartPointer->Clone();

	ASSERT_UNEQUAL_NULL_PTR(smartPointer);
	ASSERT_UNEQUAL_NULL_PTR(cloneSmartPointer);
}

void CoreTools::ParametersInterfaceTesting
	::SubclassTest()
{
	auto testValue = 5;

	ParametersSharedPtr smartPointer{ make_shared<Parameters>(testValue) };
	auto cloneSmartPointer = smartPointer->Clone();

	ASSERT_UNEQUAL_NULL_PTR(smartPointer);
	ASSERT_UNEQUAL_NULL_PTR(cloneSmartPointer);

	ASSERT_EQUAL(smartPointer->GetValue(), testValue);

	smartPointer->SetValue(testValue + 1);

	ASSERT_EQUAL(smartPointer->GetValue(), testValue + 1);

// 	auto polymorphicDowncastSmartPointer = PolymorphicSharedPtrDowncast<const Parameters>(cloneSmartPointer);
// 	ASSERT_UNEQUAL_NULL_PTR(polymorphicDowncastSmartPointer);
// 
// 	ASSERT_EQUAL(polymorphicDowncastSmartPointer->GetValue(), testValue);

// 	auto cloneSubclassSmartPointer = polymorphicDowncastSmartPointer->CloneClassType();
// 
// 	ASSERT_UNEQUAL_NULL_PTR(cloneSubclassSmartPointer);
// 	ASSERT_EQUAL(cloneSubclassSmartPointer->GetValue(), testValue);
}

