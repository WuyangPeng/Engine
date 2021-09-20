// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 15:24)

#include "SpecializedIOTesting.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include <random>

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering,SpecializedIOTesting) 

void Rendering::SpecializedIOTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(StreamSizeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
	ASSERT_NOT_THROW_EXCEPTION_0(BoundTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntColourTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FloatColourTest);
}
 
void Rendering::SpecializedIOTesting
	::StreamSizeTest()
{
// 	Transform transform;
// 
// 	unsigned size = RENDERING_STREAM_SIZE(transform);
// 
// 	ASSERT_EQUAL(size,static_cast<unsigned>(transform.GetStreamingSize()));
// 
// 	transform.SetMatrix(Transform::Matrix());
// 
// 	size = RENDERING_STREAM_SIZE(transform);
// 
// 	ASSERT_EQUAL(size,static_cast<unsigned>(transform.GetStreamingSize()));
// 
// 	transform.SetRotate(Transform::Matrix());
// 
// 	size = RENDERING_STREAM_SIZE(transform);
// 
// 	ASSERT_EQUAL(size,static_cast<unsigned>(transform.GetStreamingSize()));
// 
// 	transform.SetScale(Transform::APoint(0.2f,0.3f,0.4f));
// 
// 	size = RENDERING_STREAM_SIZE(transform);
// 
// 	ASSERT_EQUAL(size,static_cast<unsigned>(transform.GetStreamingSize()));
// 
// 	transform.SetUniformScale(1.2f);
// 
// 	size = RENDERING_STREAM_SIZE(transform);
// 
// 	ASSERT_EQUAL(size,static_cast<unsigned>(transform.GetStreamingSize()));
// 
// 	size = RENDERING_STREAM_SIZE(Bound(Transform::APoint(),0.0f));
// 
// 	ASSERT_EQUAL(size,MATHEMATICS_STREAM_SIZE(Transform::APoint()) + sizeof(float));	
// 
// 	size = RENDERING_STREAM_SIZE(Colour<float>());
// 
// 	ASSERT_EQUAL(size,sizeof(float) * 4);
// 
// 	size = RENDERING_STREAM_SIZE(Colour<unsigned>());
// 
// 	ASSERT_EQUAL(size,sizeof(unsigned) * 4);    
}

void Rendering::SpecializedIOTesting
	::TransformTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);
// 	std::uniform_real<float> secondFloatRandomDistribution(0.0f,Mathematics::FloatMath::sm_TwoPI);
// 
// 	Transform firstTransform;
// 	Transform secondTransform;
// 
// 	secondTransform.SetRotate(Transform::Matrix());
// 
// 	Transform thirdTransform;
// 	thirdTransform.SetRotate(Transform::Matrix());
// 	thirdTransform.SetScale(Transform::APoint());
// 
// 	Transform fourthTransform;
// 	fourthTransform.SetMatrix(Transform::Matrix());
// 
// 	int maxSize = RENDERING_STREAM_SIZE(firstTransform) + 
// 	              RENDERING_STREAM_SIZE(secondTransform) +
//  	              RENDERING_STREAM_SIZE(thirdTransform) + 
//  	              RENDERING_STREAM_SIZE(fourthTransform);
// 
// 	for(int i = 0;i < GetTestLoopCount();++i)
// 	{
// 	    Transform::AVector axis(firstFloatRandomDistribution(generator),
//                                 firstFloatRandomDistribution(generator),
//                                 firstFloatRandomDistribution(generator));
// 	    axis.Normalize();
//         
// 	    float angle = secondFloatRandomDistribution(generator);
//         
// 	    Transform::Matrix rotate(axis,angle);
// 	         
// 	    Transform::Matrix matrix(firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  0.0f,firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  0.0f,firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),0.0f,
//                                  0.0f,0.0f,0.0f,1.0f);
// 
//         Transform::APoint  scale(firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator),
//                                  firstFloatRandomDistribution(generator));
// 
//         Transform::APoint translate(firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator));
// 
// 	    CoreTools::BufferTarget::FileBufferPtr
// 			fileBufferPtr(new CoreTools::FileBuffer(maxSize));
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    Transform firstTransform2;
// 
// 	    target.WriteAggregate(firstTransform2);
// 
// 	    currentWriteBufferSize += RENDERING_STREAM_SIZE(firstTransform2);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 	    Transform secondTransform2;
// 
// 	    secondTransform2.SetRotate(rotate);
// 	    secondTransform2.SetUniformScale(scale[0]);
// 	    secondTransform2.SetTranslate(translate);
// 
// 	    target.WriteAggregate(secondTransform2);
// 
// 	    currentWriteBufferSize += RENDERING_STREAM_SIZE(secondTransform2);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());
// 
// 	    Transform thirdTransform2;
// 
// 	    thirdTransform2.SetRotate(rotate);
// 	    thirdTransform2.SetScale(scale);
// 	    thirdTransform2.SetTranslate(translate);
// 
// 	    target.WriteAggregate(thirdTransform2);
// 
// 	    currentWriteBufferSize += RENDERING_STREAM_SIZE(thirdTransform2);
// 
// 	    Transform fourthTransform2;
// 
// 	    fourthTransform2.SetMatrix(matrix);
// 	    thirdTransform2.SetTranslate(translate);
// 
// 	    target.WriteAggregate(fourthTransform2);
// 
// 	    currentWriteBufferSize += RENDERING_STREAM_SIZE(fourthTransform2);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());   
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    Transform fifthTransform;
// 
// 	    source.ReadAggregate(fifthTransform);
// 
// 	    currentReadBufferSize += RENDERING_STREAM_SIZE(fifthTransform);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(fifthTransform.IsIdentity()); 
// 
// 	    Transform sixthTransform;
// 
// 	    source.ReadAggregate(sixthTransform);
// 
// 	    currentReadBufferSize += RENDERING_STREAM_SIZE(sixthTransform);
// 
// 	    ASSERT_TRUE(Approximate(sixthTransform.GetRotate(), secondTransform2.GetRotate(),1e-8f));  
// 	    ASSERT_APPROXIMATE(sixthTransform.GetUniformScale(), secondTransform2.GetUniformScale(),1e-8f);  
// 	    ASSERT_TRUE(Approximate(sixthTransform.GetTranslate(), secondTransform2.GetTranslate(),1e-8f));  
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 
// 	    Transform seventhTransform;
// 
// 	    source.ReadAggregate(seventhTransform);
// 
// 	    currentReadBufferSize += RENDERING_STREAM_SIZE(seventhTransform);
// 
// 	    ASSERT_TRUE(Approximate(seventhTransform.GetRotate(), thirdTransform2.GetRotate(),1e-8f));  
// 	    ASSERT_TRUE(Approximate(seventhTransform.GetScale(), thirdTransform2.GetScale(),1e-8f));    
// 	    ASSERT_TRUE(Approximate(seventhTransform.GetTranslate(), thirdTransform2.GetTranslate(),1e-8f));  
// 
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    Transform eighthTransform;
// 
// 	    source.ReadAggregate(eighthTransform);
// 
// 	    currentReadBufferSize += RENDERING_STREAM_SIZE(eighthTransform);
// 
// 	    ASSERT_TRUE(Approximate(eighthTransform.GetMatrix(), fourthTransform2.GetMatrix(),1e-8f));  
//     
// 	    ASSERT_TRUE(Approximate(eighthTransform.GetTranslate(), fourthTransform2.GetTranslate(),1e-8f));  
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}	 	  
}

void Rendering::SpecializedIOTesting
	::BoundTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(-100.0f,100.0f); 
// 	int maxSize = RENDERING_STREAM_SIZE(Bound(Bound::APoint(),0.0f));
// 
// 	for(int i = 0;i < GetTestLoopCount();++i)
// 	{
// 	    CoreTools::BufferTarget::FileBufferPtr
// 			fileBufferPtr(new CoreTools::FileBuffer(maxSize));
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    Bound firstBound(Bound::APoint(floatRandomDistribution(generator),
// 			                           floatRandomDistribution(generator), 
// 			                           floatRandomDistribution(generator)),
// 			             Mathematics::FloatMath::FAbs(floatRandomDistribution(generator)));
// 
// 	    target.WriteAggregate(firstBound);
// 
// 	    currentWriteBufferSize += RENDERING_STREAM_SIZE(firstBound);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());	   
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    Bound secondBound(Bound::APoint(),0.0f);
// 
// 	    source.ReadAggregate(secondBound);
// 
// 	    currentReadBufferSize += RENDERING_STREAM_SIZE(secondBound);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstBound.GetCenter(), secondBound.GetCenter(),1e-8f));  
// 	    ASSERT_APPROXIMATE(firstBound. GetRadius(), secondBound. GetRadius(),1e-8f);  
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}	  
}

void Rendering::SpecializedIOTesting
	::IntColourTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<> intRandomDistribution(0,255);
// 	int maxSize = RENDERING_STREAM_SIZE(Colour<unsigned>());
// 
// 	for(int i = 0;i < GetTestLoopCount();++i)
// 	{
// 	    CoreTools::BufferTarget::FileBufferPtr
// 			fileBufferPtr(new CoreTools::FileBuffer(maxSize));
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    Colour<unsigned> firstColour(intRandomDistribution(generator),
// 			                         intRandomDistribution(generator), 
// 			                         intRandomDistribution(generator),
// 			                         intRandomDistribution(generator));
//  
// 	    target.WriteAggregate(firstColour);
// 
// 	    currentWriteBufferSize += RENDERING_STREAM_SIZE(firstColour);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());	   
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    Colour<unsigned> secondColour;
// 
// 	    source.ReadAggregate(secondColour);
// 
// 	    currentReadBufferSize += RENDERING_STREAM_SIZE(secondColour);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_EQUAL(firstColour, secondColour);  
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}	  
}

void Rendering::SpecializedIOTesting
	::FloatColourTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> floatRandomDistribution(0.0f,1.0f); 
// 	int maxSize = RENDERING_STREAM_SIZE(Colour<unsigned>());
// 
// 	for(int i = 0;i < GetTestLoopCount();++i)
// 	{
// 	    CoreTools::BufferTarget::FileBufferPtr
// 			fileBufferPtr(new CoreTools::FileBuffer(maxSize));
// 
// 	    // –¥
// 	    int currentWriteBufferSize = 0;
// 
// 	    CoreTools::ObjectRegister objectRegister;
// 	    CoreTools::BufferTarget target(fileBufferPtr,objectRegister);
// 
// 	    ASSERT_EQUAL(target.GetBytesWritten(),currentWriteBufferSize);
// 
// 	    Colour<float> firstColour(floatRandomDistribution(generator),
// 			                      floatRandomDistribution(generator), 
// 			                      floatRandomDistribution(generator),
// 			                      floatRandomDistribution(generator));
// 
// 	    target.WriteAggregate(firstColour);
// 
// 	    currentWriteBufferSize += RENDERING_STREAM_SIZE(firstColour);
// 
// 	    ASSERT_EQUAL(currentWriteBufferSize,target.GetBytesWritten());	   
// 	    ASSERT_EQUAL(maxSize,target.GetBytesWritten());
// 
// 	    // ∂¡
// 
// 	    CoreTools::BufferSource source(fileBufferPtr);
// 	    int currentReadBufferSize = 0;
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    Colour<float> secondColour;
// 
// 	    source.ReadAggregate(secondColour);
// 
// 	    currentReadBufferSize += RENDERING_STREAM_SIZE(secondColour);
// 
// 	    ASSERT_EQUAL(source.GetBytesRead(),currentReadBufferSize);
// 
// 	    ASSERT_TRUE(Approximate(firstColour, secondColour,1e-8f));  
// 
// 	    ASSERT_EQUAL(maxSize,source.GetBytesRead());
// 	}		  
}
	   
