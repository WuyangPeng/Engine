// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 16:42)

#include "CollapseRecordTesting.h"
#include "Rendering/Detail/CollapseRecord.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
 
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, CollapseRecordTesting) 

void Rendering::CollapseRecordTesting
	::MainTest()
{ 
	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}
 #include SYSTEM_WARNING_DISABLE(26446)
void Rendering::CollapseRecordTesting
	::InitTest()
{
	CollapseRecord firstCollapseRecord(2, 7, 10, 12);

	ASSERT_EQUAL(firstCollapseRecord.GetIndicesSize(), 0);
	ASSERT_EQUAL(firstCollapseRecord.GetVKeep(), 2);
	ASSERT_EQUAL(firstCollapseRecord.GetVThrow(), 7);
	ASSERT_EQUAL(firstCollapseRecord.GetNumVertices(), 10);
	ASSERT_EQUAL(firstCollapseRecord.GetNumTriangles(), 12);

	vector<int> indices{ 2, 10, 3, 61, 1, 5, 6, 3 };

	firstCollapseRecord.SetIndices(indices);

	ASSERT_EQUAL(firstCollapseRecord.GetIndicesSize(),static_cast<int>(indices.size()));

	for (int i = 0; i < firstCollapseRecord.GetIndicesSize();++i)
	{
		ASSERT_EQUAL(firstCollapseRecord.GetIndex(i), indices[i]);
	}

	ASSERT_EQUAL(firstCollapseRecord.GetIndices(), indices);

	firstCollapseRecord.SetVKeep(5);
	ASSERT_EQUAL(firstCollapseRecord.GetVKeep(), 5);

	firstCollapseRecord.SetVThrow(114);
	ASSERT_EQUAL(firstCollapseRecord.GetVThrow(), 114);

	firstCollapseRecord.SetNumVertices(12);
	ASSERT_EQUAL(firstCollapseRecord.GetNumVertices(), 12);

	firstCollapseRecord.SetNumTriangles(111);
	ASSERT_EQUAL(firstCollapseRecord.GetNumTriangles(), 111);
}
