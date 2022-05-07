// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 11:46)

#include "VisibleSetTesting.h"
#include "SpatialTest.h"
#include "Rendering/SceneGraph/VisibleSet.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"


UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VisibleSetTesting) 
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
void Rendering::VisibleSetTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(VisibleSetTest); 

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::VisibleSetTesting
	::VisibleSetTest()
{
    VisibleSet firstVisibleSet = VisibleSet::Create();

	ASSERT_EQUAL(firstVisibleSet.GetNumVisible(),0);

	VisualSharedPtr firstSpatialPtr(new SpatialTest);
	VisualSharedPtr secondSpatialPtr(new SpatialTest);
	VisualSharedPtr thirdSpatialPtr(new SpatialTest);

	firstVisibleSet.Insert(firstSpatialPtr);	
	firstVisibleSet.Insert(secondSpatialPtr);
	firstVisibleSet.Insert(thirdSpatialPtr);

	ASSERT_EQUAL(firstVisibleSet.GetNumVisible(),3);

	ASSERT_EQUAL(firstVisibleSet.GetVisible(0), firstSpatialPtr);
	ASSERT_EQUAL(firstVisibleSet.GetVisible(1), secondSpatialPtr);
	ASSERT_EQUAL(firstVisibleSet.GetVisible(2), thirdSpatialPtr);

	firstVisibleSet.Clear ();

	ASSERT_EQUAL(firstVisibleSet.GetNumVisible(),0);		 	
}

 