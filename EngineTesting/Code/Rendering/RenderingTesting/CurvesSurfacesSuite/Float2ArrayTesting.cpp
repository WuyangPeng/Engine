// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 17:01)

#include "Float2ArrayTesting.h"
#include "Rendering/CurvesSurfaces/Float2Array.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h" 


using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, Float2ArrayTesting) 

void Rendering::Float2ArrayTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	CoreTools::InitTerm::ExecuteTerminators();
}
 #include SYSTEM_WARNING_DISABLE(26440)
void Rendering::Float2ArrayTesting
	::InitTest()
{
// 	 vector<Mathematics::Float2> value;
// 	 const int size = 100;
// 
// 	 for (int i = 0; i < size; ++i)
// 	 {
// 		 value.push_back(Mathematics::Float2(static_cast<float>(i), static_cast<float>(i * 2)));
// 	 }
// 
// 	 const Float2Array firstFloatArray(value);
// 
// 	 ASSERT_EQUAL(firstFloatArray.GetNumElements(), size);
// 
// 	 const Mathematics::Float2* data = firstFloatArray.GetData();
// 
// 	 for (int i = 0; i < size;++i)
// 	 {
// // 		 ASSERT_APPROXIMATE(data[i].GetFirstValue(), static_cast<float>(i), 1e-8f);
// // 		 ASSERT_APPROXIMATE(firstFloatArray[i].GetFirstValue(), static_cast<float>(i), 1e-8f);
// // 		 ASSERT_APPROXIMATE(data[i].GetSecondValue(), static_cast<float>(i * 2), 1e-8f);
// // 		 ASSERT_APPROXIMATE(firstFloatArray[i].GetSecondValue(), static_cast<float>(i * 2), 1e-8f);
// 
// 	 }
// 
// 	 Float2Array secondFloatArray(value);
// 
// 	 for (int i = 0; i < size; ++i)
// 	 {
// 		 secondFloatArray[i].SetFirstValue(static_cast<float>(i + size));
// 		 secondFloatArray[i].SetSecondValue(static_cast<float>(2 * i + size));
// 	 }
// 
// 	 for (int i = 0; i < size; ++i)
// 	 {
// 		 ASSERT_APPROXIMATE(secondFloatArray[i].GetFirstValue(), static_cast<float>(i + size), 1e-8f);
// 		 ASSERT_APPROXIMATE(secondFloatArray[i].GetSecondValue(), static_cast<float>(2 * i + size), 1e-8f);
// 	 }
}

void Rendering::Float2ArrayTesting
	::CopyTest()
{
// 	 vector<Mathematics::Float2> value;
// 	 const int size = 100;
// 
// 	 for (int i = 0; i < size; ++i)
// 	 {
// 		 value.push_back(Mathematics::Float2(static_cast<float>(i), static_cast<float>(i * 2)));
// 	 }
// 
// 	 Float2Array firstFloatArray(value);
// 	 Float2Array secondFloatArray(firstFloatArray);
// 
// 	 for (int i = 0; i < size; ++i)
// 	 {
// 		 secondFloatArray[i].SetFirstValue(static_cast<float>(i + size));
// 		 secondFloatArray[i].SetSecondValue(static_cast<float>(2 * i + size));
// 	 }
// 
// 	 for (int i = 0; i < size; ++i)
// 	 {
// 		 ASSERT_APPROXIMATE(firstFloatArray[i].GetFirstValue(), static_cast<float>(i), 1e-8f);
// 		 ASSERT_APPROXIMATE(secondFloatArray[i].GetFirstValue(), static_cast<float>(i + size), 1e-8f);
// 		 ASSERT_APPROXIMATE(firstFloatArray[i].GetSecondValue(), static_cast<float>(2 * i), 1e-8f);
// 		 ASSERT_APPROXIMATE(secondFloatArray[i].GetSecondValue(), static_cast<float>(2 * i + size), 1e-8f);
// 	 }
// 
// 	 Float2Array thirdFloatArray(value);
// 
// 	 secondFloatArray = thirdFloatArray;
// 
// 	 for (int i = 0; i < size; ++i)
// 	 {
// 		 secondFloatArray[i].SetFirstValue(static_cast<float>(i + size));
// 		 secondFloatArray[i].SetSecondValue(static_cast<float>(2 * i + size));
// 	 }
// 
// 	 for (int i = 0; i < size; ++i)
// 	 {
// 		 ASSERT_APPROXIMATE(firstFloatArray[i].GetFirstValue(), static_cast<float>(i), 1e-8f);
// 		 ASSERT_APPROXIMATE(secondFloatArray[i].GetFirstValue(), static_cast<float>(i + size), 1e-8f);
// 		 ASSERT_APPROXIMATE(thirdFloatArray[i].GetFirstValue(), static_cast<float>(i), 1e-8f);
// 		 ASSERT_APPROXIMATE(firstFloatArray[i].GetSecondValue(), static_cast<float>(2 * i), 1e-8f);
// 		 ASSERT_APPROXIMATE(secondFloatArray[i].GetSecondValue(), static_cast<float>(2 * i + size), 1e-8f);
// 		 ASSERT_APPROXIMATE(thirdFloatArray[i].GetSecondValue(), static_cast<float>(2 * i), 1e-8f);
// 	 }
}
 
void Rendering::Float2ArrayTesting
	::StreamTest()
{
// 	vector<Mathematics::Float2> value;
// 	const int size = 100;
// 	
// 	for (int i = 0; i < size; ++i)
// 	{
// 		value.push_back(Mathematics::Float2(static_cast<float>(i), static_cast<float>(i * 2)));
// 	}
// 	 
// 	CoreTools::OutTopLevel outTopLevel;
// 	CoreTools::ObjectInterfaceSharedPtr firstFloatArray(new Float2Array(value));
// 
// 	outTopLevel.Insert(firstFloatArray);	 
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
//         
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
//         
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	Float2ArraySharedPtr secondFloatArray = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<Float2ArraySharedPtr>();
// 
// 	ASSERT_EQUAL(secondFloatArray->GetNumElements(), size);
//  
// 	 for (int i = 0; i < size;++i)
// 	 {		  
// 		 ASSERT_APPROXIMATE((*secondFloatArray)[i].GetFirstValue(), static_cast<float>(i), 1e-8f);
// 		 ASSERT_APPROXIMATE((*secondFloatArray)[i].GetSecondValue(), static_cast<float>(i * 2), 1e-8f);
// 	 }
}