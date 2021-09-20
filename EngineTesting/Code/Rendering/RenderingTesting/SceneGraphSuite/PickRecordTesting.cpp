// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 11:08)

#include "PickRecordTesting.h"
#include "SpatialTest.h"
#include "Rendering/SceneGraph/PickRecord.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PickRecordTesting) 

void Rendering::PickRecordTesting
	::MainTest()
{
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::PickRecordTesting
	::BaseTest()
{
	PickRecord firstPickRecord;

	ConstSpatialSharedPtr firstSpatialSharedPtr = firstPickRecord.GetIntersected();
	//ASSERT_TRUE(firstSpatialSharedPtr.IsNullPtr());
	ASSERT_APPROXIMATE(firstPickRecord.GetParameter(), 0.0f,1e-8f);
	ASSERT_EQUAL(firstPickRecord.GetTriangle(), -1);
	ASSERT_TRUE(0.0f <= firstPickRecord.GetBary(0) && firstPickRecord.GetBary(0) <= 1.0f);
	ASSERT_TRUE(0.0f <= firstPickRecord.GetBary(1) && firstPickRecord.GetBary(1) <= 1.0f);
	ASSERT_TRUE(0.0f <= firstPickRecord.GetBary(2) && firstPickRecord.GetBary(2) <= 1.0f);
	ASSERT_APPROXIMATE(firstPickRecord.GetBary(0) + firstPickRecord.GetBary(1) + firstPickRecord.GetBary(2),1.0f,1e-8f);

// 	ConstSpatialSharedPtr secondSpatialSharedPtr(new SpatialTest);
// 	firstPickRecord.SetIntersected(secondSpatialSharedPtr);
// 
// 	ASSERT_EQUAL(firstPickRecord.GetIntersected(), secondSpatialSharedPtr);
// 
// 	firstPickRecord.SetParameter(0.5f);
// 	ASSERT_APPROXIMATE(firstPickRecord.GetParameter(), 0.5f,1e-8f);
// 
// 	firstPickRecord.SetTriangle(4);
// 	ASSERT_EQUAL(firstPickRecord.GetTriangle(), 4);
// 
// 	firstPickRecord.SetBary(0.2f,0.5f);
// 
// 	ASSERT_APPROXIMATE(firstPickRecord.GetBary(0),0.2f,1e-8f);
// 	ASSERT_APPROXIMATE(firstPickRecord.GetBary(1), 0.5f, 1e-8f);
// 	ASSERT_APPROXIMATE(firstPickRecord.GetBary(2), 0.3f, 1e-8f);
}

void Rendering::PickRecordTesting
	::OperatorTest()
{
	PickRecord firstPickRecord;
	firstPickRecord.SetParameter(0.5f);

	PickRecord secondPickRecord;
	secondPickRecord.SetParameter(0.15f);

	ASSERT_TRUE(firstPickRecord == firstPickRecord);
	ASSERT_TRUE(secondPickRecord == secondPickRecord);
	ASSERT_FALSE(firstPickRecord == secondPickRecord);

	ASSERT_FALSE(firstPickRecord != firstPickRecord);
	ASSERT_FALSE(secondPickRecord != secondPickRecord);
	ASSERT_TRUE(firstPickRecord != secondPickRecord);

	ASSERT_FALSE(firstPickRecord < secondPickRecord);
	ASSERT_FALSE(firstPickRecord <= secondPickRecord);
	ASSERT_TRUE(firstPickRecord > secondPickRecord);
	ASSERT_TRUE(firstPickRecord >= secondPickRecord);

	ASSERT_FALSE(firstPickRecord < firstPickRecord);
	ASSERT_TRUE(firstPickRecord <= firstPickRecord);
	ASSERT_FALSE(firstPickRecord > firstPickRecord);
	ASSERT_TRUE(firstPickRecord >= firstPickRecord);
}
