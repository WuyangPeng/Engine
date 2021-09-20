// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 11:08)

#include "PickRecordContainerTesting.h"
#include "SpatialTest.h"
#include "Rendering/SceneGraph/PickRecord.h"
#include "Rendering/SceneGraph/PickRecordContainer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PickRecordContainerTesting) 

void Rendering::PickRecordContainerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}
 
void Rendering::PickRecordContainerTesting
	::BaseTest()
{
	PickRecordContainer firstPickRecordContainer;

	ASSERT_EQUAL(firstPickRecordContainer.GetSize(), 0);
	ASSERT_TRUE(firstPickRecordContainer.IsEmpty());

	for (int i = 0; i < 10; ++i)
	{
		PickRecord pickRecord;
		pickRecord.SetParameter(static_cast<float>(i));

		firstPickRecordContainer.InsertPickRecord(pickRecord);
	}

	ASSERT_EQUAL(firstPickRecordContainer.GetSize(),10);
	ASSERT_FALSE(firstPickRecordContainer.IsEmpty());

	for (int i = 0; i < 10; ++i)
	{
		ASSERT_APPROXIMATE(firstPickRecordContainer.GetPickRecord(i).GetParameter(), i, 1e-8f);
	}	

	PickRecordContainer secondPickRecordContainer;
	
	secondPickRecordContainer.InsertPickRecord(firstPickRecordContainer);

	ASSERT_EQUAL(secondPickRecordContainer.GetSize(), 10);

	for (int i = 0; i < 10; ++i)
	{
		ASSERT_APPROXIMATE(secondPickRecordContainer.GetPickRecord(i).GetParameter(), i, 1e-8f);
	}

	ASSERT_FALSE(secondPickRecordContainer.IsEmpty());
}
 