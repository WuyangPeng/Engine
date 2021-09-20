// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 16:42)

#include "CollapseRecordArrayTesting.h"
#include "Rendering/Detail/CollapseRecordArray.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"


using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, CollapseRecordArrayTesting) 

void Rendering::CollapseRecordArrayTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::CollapseRecordArrayTesting
	::InitTest()
{
	vector<CollapseRecord> collapseRecordVector;
	for (int i = 0;i < 10;++i)
	{
		CollapseRecord firstCollapseRecord(12 - i, 7, 10 + i, 12 + i);

		vector<int> indices{ 2, 10, 3, 61, 1, 5, 6, 3,i };

		firstCollapseRecord.SetIndices(indices);

		collapseRecordVector.push_back(firstCollapseRecord);
	}
	
	CollapseRecordArray collapseRecordArray(collapseRecordVector);

	ASSERT_EQUAL(collapseRecordArray.GetNumRecords(),static_cast<int>(collapseRecordVector.size()));
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(collapseRecordVector, collapseRecordArray.GetRecords());

	for (int i = 0; i < collapseRecordArray.GetNumRecords(); ++i)
	{
		ASSERT_EQUAL_DO_NOT_USE_MESSAGE(collapseRecordArray.GetRecord(i), collapseRecordVector[i]);
	}
}

void Rendering::CollapseRecordArrayTesting
	::CopyTest()
{
	vector<CollapseRecord> collapseRecordVector;
	for (int i = 0;i < 10;++i)
	{
		CollapseRecord firstCollapseRecord(12 - i, 7, 10 + i, 12 + i);

		vector<int> indices{ 2, 10, 3, 61, 1, 5, 6, 3,i };

		firstCollapseRecord.SetIndices(indices);

		collapseRecordVector.push_back(firstCollapseRecord);
	}
	
	CollapseRecordArray firstCollapseRecordArray(collapseRecordVector);

	firstCollapseRecordArray.SetUniqueID(2);

	CollapseRecordArray secondCollapseRecordArray(firstCollapseRecordArray);

	ASSERT_EQUAL(secondCollapseRecordArray.GetUniqueID(), 2u);
	ASSERT_EQUAL(firstCollapseRecordArray.GetUniqueID(), 2u);

	secondCollapseRecordArray.SetUniqueID(1);

	ASSERT_EQUAL(firstCollapseRecordArray.GetUniqueID(), 2u);
	ASSERT_EQUAL(secondCollapseRecordArray.GetUniqueID(), 1u);

	firstCollapseRecordArray = secondCollapseRecordArray;

	ASSERT_EQUAL(firstCollapseRecordArray.GetUniqueID(), 1u);
	ASSERT_EQUAL(secondCollapseRecordArray.GetUniqueID(), 1u);

	firstCollapseRecordArray.SetUniqueID(3);

	ASSERT_EQUAL(firstCollapseRecordArray.GetUniqueID(), 3u);
	ASSERT_EQUAL(secondCollapseRecordArray.GetUniqueID(), 1u);
}

void Rendering::CollapseRecordArrayTesting
	::StreamTest()
{
	vector<CollapseRecord> collapseRecordVector;
	for (int i = 0;i < 10;++i)
	{
		CollapseRecord firstCollapseRecord(12 - i, 7, 10 + i, 12 + i);

		vector<int> indices{ 2, 10, 3, 61, 1, 5, 6, 3,i };

		firstCollapseRecord.SetIndices(indices);

		collapseRecordVector.push_back(firstCollapseRecord);
	}
	
// 	CoreTools::OutTopLevel outTopLevel;
// 	CollapseRecordArraySharedPtr firstCollapseRecordArray(new CollapseRecordArray(collapseRecordVector));
// 	outTopLevel.Insert(firstCollapseRecordArray);
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =
// 		outStream.GetBufferOutStreamInformation();
// 
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
// 
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	CollapseRecordArraySharedPtr secondCollapseRecordArray =	inTopLevel[0].PolymorphicDowncastObjectSharedPtr<CollapseRecordArraySharedPtr>();
// 
// 
// 	ASSERT_EQUAL(firstCollapseRecordArray->GetNumRecords(), secondCollapseRecordArray->GetNumRecords());
// 	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(firstCollapseRecordArray->GetRecords(), secondCollapseRecordArray->GetRecords());
// 
// 	for (int i = 0; i < firstCollapseRecordArray->GetNumRecords(); ++i)
// 	{
// 		ASSERT_EQUAL_DO_NOT_USE_MESSAGE(firstCollapseRecordArray->GetRecord(i), secondCollapseRecordArray->GetRecord(i));
// 	}
}
