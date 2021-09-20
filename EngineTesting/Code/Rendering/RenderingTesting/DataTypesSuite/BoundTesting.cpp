// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 14:35)

#include "BoundTesting.h"
#include "Rendering/DataTypes/Bound.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering,BoundTesting) 

void Rendering::BoundTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GrowToContainTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TransformByTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ComputeFromDataTest);
	ASSERT_NOT_THROW_EXCEPTION_0(LineIntersectionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(BoundIntersectionTest);
}
 
void Rendering::BoundTesting
	::BaseTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);  

	for(auto loop = 0;loop < GetTestLoopCount();++loop)
	{
//         Bound::APoint firstCenter(firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator));
// 
//         float firstRadius = Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator));
// 
//         Bound firstBound(firstCenter, firstRadius);
// 
//         ASSERT_TRUE(Approximate(firstCenter, firstBound.GetCenter(),1e-8f));
//         ASSERT_APPROXIMATE(firstRadius,firstBound.GetRadius(),1e-8f);
// 
//         Bound::APoint secondCenter(firstFloatRandomDistribution(generator),
//                                    firstFloatRandomDistribution(generator),
//                                    firstFloatRandomDistribution(generator));
// 
//         float secondRadius = Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator));
// 
//         firstBound.SetCenter(secondCenter);
// 
//         ASSERT_TRUE(Approximate(secondCenter, firstBound.GetCenter(),1e-8f));
//         ASSERT_APPROXIMATE(firstRadius,firstBound.GetRadius(),1e-8f);
// 
//         firstBound.SetRadius(secondRadius);
// 
//         ASSERT_TRUE(Approximate(secondCenter, firstBound.GetCenter(),1e-8f));
//         ASSERT_APPROXIMATE(secondRadius,firstBound.GetRadius(),1e-8f);
// 
//         Bound::AVector firstVector(firstFloatRandomDistribution(generator),
//                                    firstFloatRandomDistribution(generator),
//                                    firstFloatRandomDistribution(generator));
// 
//         firstVector.Normalize();
// 
//         Bound::Plane firstPlane(firstVector, secondCenter);
// 
//         ASSERT_ENUM_EQUAL(firstBound.WhichSide(firstPlane),Mathematics::NumericalValueSymbol::Zero);
// 
//         Bound::Plane secondPlane(firstVector, firstCenter);
// 
// 		float signedDistance = secondPlane.DistanceTo(secondCenter);
// 
// 		if (signedDistance <= -secondRadius)
// 		{
// 			ASSERT_ENUM_EQUAL(Mathematics::NumericalValueSymbol::Negative,firstBound.WhichSide(secondPlane));
// 		}
// 		else if (secondRadius <= signedDistance)
// 		{
// 			ASSERT_ENUM_EQUAL(Mathematics::NumericalValueSymbol::Positive,firstBound.WhichSide(secondPlane));
// 			
// 		}
// 		else
// 		{
// 			ASSERT_ENUM_EQUAL(Mathematics::NumericalValueSymbol::Zero,firstBound.WhichSide(secondPlane));
// 		}
	}
}

void Rendering::BoundTesting
	::GrowToContainTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);  

	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
	{
//         Bound::APoint firstCenter(firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator));
// 
//         float firstRadius = Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator));
// 
//         Bound firstBound(firstCenter, firstRadius);  
// 
//         Bound::APoint secondCenter(firstFloatRandomDistribution(generator),
//                                    firstFloatRandomDistribution(generator),
//                                    firstFloatRandomDistribution(generator));
// 
//         float secondRadius = Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator));
// 
//         Bound secondBound(secondCenter, secondRadius);
// 		Bound thirdBound(firstBound);
// 
//         firstBound.GrowToContain(secondBound);
// 
//         Bound::AVector centerDifference = secondBound.GetCenter() - thirdBound.GetCenter();
//         float lengthSqruared = centerDifference.SquaredLength();
//         float radiusDifference = secondBound.GetRadius() - thirdBound.GetRadius();
//         float radiusDifferenceSqruared = radiusDifference * radiusDifference;
// 
//         if (lengthSqruared <= radiusDifferenceSqruared)
//         {
//             if (0.0f <= radiusDifference)
//             {
//                 ASSERT_TRUE(Approximate(secondCenter, firstBound.GetCenter(),1e-8f));
//                 ASSERT_APPROXIMATE(secondRadius,firstBound.GetRadius(),1e-8f);      
//             }
//             else
//             {
//                 ASSERT_TRUE(Approximate(firstCenter, firstBound.GetCenter(),1e-8f));
//                 ASSERT_APPROXIMATE(firstRadius,firstBound.GetRadius(),1e-8f); 
//             }       
//         }
//         else
//         {
//             float length = Mathematics::FloatMath::Sqrt(lengthSqruared);
//             if (Mathematics::FloatMath::sm_ZeroTolerance < length)
//             {
//                 float coefficient = (length + radiusDifference) / (2.0f * length);
// 
//                 ASSERT_TRUE(Approximate(firstCenter + coefficient * centerDifference,firstBound.GetCenter(),1e-8f));
//             }
//             else
//             {
//                 ASSERT_TRUE(Approximate(firstCenter, firstBound.GetCenter(),1e-8f));
//             }
// 
//             ASSERT_APPROXIMATE(0.5f * (length + firstRadius + secondRadius),firstBound.GetRadius(),1e-8f);  
//         }

	}
}

void Rendering::BoundTesting
	::TransformByTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);  

	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
	{
//         Bound::APoint firstCenter(firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator));
// 
//         float firstRadius = Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator));
// 
//         Bound firstBound(firstCenter, firstRadius); 
// 
// 		Transform transform;
//  
//         Transform::Matrix matrix(firstFloatRandomDistribution(generator),
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
//         transform.SetMatrix(matrix);
// 
//         Bound secondBound = firstBound.TransformBy(transform);
// 
// 		ASSERT_TRUE(Approximate(firstBound.GetCenter(),firstCenter,1e-8f));
// 		ASSERT_APPROXIMATE(firstBound.GetRadius(),firstRadius,1e-8f);
// 
//         ASSERT_TRUE(Approximate(transform * firstBound.GetCenter(), 
//                                 secondBound.GetCenter(),1e-8f));
// 
//         ASSERT_APPROXIMATE(transform.GetNorm() * firstBound.GetRadius(),secondBound.GetRadius(),1e-8f); 
	} 
}

void Rendering::BoundTesting
	::ComputeFromDataTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);  

    constexpr int size = 100;

	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
	{ 
// 	    vector<float> buffer;
// 	    for(int i = 0;i < size * 3;++i)
// 	    {
// 	    	 buffer.push_back(firstFloatRandomDistribution(generator));
// 	    }
// 
// 	    Bound firstBound(Bound::APoint(), 0.0f); 
// 
// 	    firstBound.ComputeFromData(size,4 * 3,reinterpret_cast<const char*>(&buffer[0]));
// 
// 	    Bound::APoint center(0.0f, 0.0f, 0.0f); 
// 	    for (int i = 0; i < size; ++i)
// 	    {       
// 	        center[0] += buffer[i * 3];
// 	        center[1] += buffer[i * 3 + 1];
// 	        center[2] += buffer[i * 3 + 2];
// 	    }
// 
// 	    center /= static_cast<float>(size);
// 
// 	    ASSERT_TRUE(Approximate(center,firstBound.GetCenter(),1e-8f));
// 
// 	    float radius = 0.0f;
// 	    for (int i = 0; i < 100; ++i)
// 	    {
// 	        Bound::AVector difference(buffer[i * 3] - center[0],
// 			                          buffer[i * 3 + 1] - center[1],
// 						              buffer[i * 3 + 2] - center[2]); 
//         
// 	        float radiusSquared = difference.SquaredLength();
//         
// 	        if (radius < radiusSquared)
// 	        {
//                  radius = radiusSquared;
// 	        }
// 	    }
// 
//         ASSERT_APPROXIMATE(Mathematics::FloatMath::Sqrt(radius),firstBound.GetRadius(),1e-8f); 
	} 
}

void Rendering::BoundTesting
	::LineIntersectionTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);  

	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
	{
//         Bound::APoint firstCenter(firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator));
// 
//         float firstRadius = Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator));
// 
//         Bound firstBound(firstCenter, firstRadius);   
// 
//         Bound::AVector firstVector(firstFloatRandomDistribution(generator),
//                                    firstFloatRandomDistribution(generator),
//                                    firstFloatRandomDistribution(generator));
// 
//         firstVector.Normalize();
// 
//         Bound::APoint firstOrigin(firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator));
// 
//         float firstLength = Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator));
// 
// 	    ASSERT_TRUE(firstBound.TestIntersection(firstCenter,firstVector,
// 	                                            -Mathematics::FloatMath::sm_MaxReal,
// 	                                            Mathematics::FloatMath::sm_MaxReal));
// 
// 	    ASSERT_TRUE(firstBound.TestIntersection(firstCenter,firstVector,
// 	                                            0.0f,
// 	                                            Mathematics::FloatMath::sm_MaxReal));
// 		
//         Bound::AVector difference = firstOrigin - firstCenter;
//         float a = difference.SquaredLength() - firstRadius * firstRadius;
// 
//         if (a <= 0.0f)
//         {
//             ASSERT_TRUE(firstBound.TestIntersection(firstOrigin,firstVector,
// 	                                                -Mathematics::FloatMath::sm_MaxReal,
// 	                                                Mathematics::FloatMath::sm_MaxReal));
// 
// 	    
//             ASSERT_TRUE(firstBound.TestIntersection(firstOrigin,firstVector,
//                                                     0.0f,
//                                                     Mathematics::FloatMath::sm_MaxReal));
//         }
// 		else
// 		{
// 			float dot = Dot(firstVector,difference);
// 			if (0.0f <= dot)
// 			{
//                 ASSERT_FALSE(firstBound.TestIntersection(firstOrigin,firstVector,
//                                                          0.0f,
//                                                          Mathematics::FloatMath::sm_MaxReal));
// 			}
//             else
//             {
//                 float discr = dot * dot - a;
//                 ASSERT_EQUAL(0.0f <= discr,firstBound.TestIntersection(firstOrigin,firstVector,0.0f,Mathematics::FloatMath::sm_MaxReal));
//             }
// 
// 			float discr = dot * dot - a;
// 			ASSERT_EQUAL(0.0f <= discr,firstBound.TestIntersection(firstOrigin,firstVector,-Mathematics::FloatMath::sm_MaxReal,Mathematics::FloatMath::sm_MaxReal));
// 		}
// 
//         float segmentExtent = 0.5f * (0.0f + firstLength);
//         Bound::APoint segmentOrigin = firstCenter + segmentExtent * firstVector;
//         
//         difference = segmentOrigin - firstCenter;
//         a = difference.SquaredLength() - firstRadius * firstRadius;
//         float dot = Dot(firstVector,difference);
//         float discr = dot * dot - a;
//         if (discr < 0.0f)
//         {
//             ASSERT_FALSE(firstBound.TestIntersection(firstCenter, firstVector, 0.0f, firstLength));       
//         }
//         
//         float tmp0 = segmentExtent * segmentExtent + a;
//         float tmp1 = 2.0f * dot * segmentExtent;
//         float qm = tmp0 - tmp1;
//         float qp = tmp0 + tmp1;
//         if (qm * qp < 0.0f)
//         {
//             ASSERT_TRUE(firstBound.TestIntersection(firstCenter, firstVector,0.0f, firstLength));
//         }
// 		else
// 		{
// 			ASSERT_EQUAL(0.0f < qm && Mathematics::FloatMath::FAbs(dot) < segmentExtent,
//                          firstBound.TestIntersection(firstCenter, firstVector,0.0f, firstLength));
// 		}       
	}
}


void Rendering::BoundTesting
	::BoundIntersectionTest()
{
//     std::default_random_engine generator;
//     std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);
//     
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
//         Bound::APoint firstCenter(firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator));
//         
//         float firstRadius = Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator));
//         
//         Bound firstBound(firstCenter, firstRadius);
//         
//         Bound::AVector firstVector(firstFloatRandomDistribution(generator),
//                                    firstFloatRandomDistribution(generator),
//                                    firstFloatRandomDistribution(generator));
//         
//         firstVector.Normalize();
//         
//         Bound::APoint secondCenter(firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator),
//                                   firstFloatRandomDistribution(generator));
//         
//         float secondRadius = Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator));
//         
//         Bound secondBound(secondCenter, secondRadius);
//         
//         Bound::AVector secondVector(firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator));
//         
//         secondVector.Normalize();
//         
//         float max = Mathematics::FloatMath::FAbs(firstFloatRandomDistribution(generator));
//         
//         Bound::AVector difference = firstBound.GetCenter() - secondBound.GetCenter();
//         float radiusSum = firstBound.GetRadius() + secondBound.GetRadius();
//         
//         ASSERT_EQUAL(difference.SquaredLength() <= radiusSum * radiusSum,
//                      TestIntersection(firstBound,secondBound));
//         
//         Bound::AVector realVelocity = secondVector - firstVector;
//         Bound::AVector centerDifference = secondBound.GetCenter() - firstBound.GetCenter();;
//         float realVelocitySquaredLength = realVelocity.SquaredLength();
//         float centerDifferenceSquaredLength = centerDifference.SquaredLength();
//         radiusSum = firstBound.GetRadius() + secondBound.GetRadius();
//         float radiusSumSquared = radiusSum * radiusSum;
//         
//         if (0.0f < realVelocitySquaredLength)
//         {
//             float dot = Dot(centerDifference,realVelocity);
//             if (dot <= 0.0f)
//             {
//                 if (-max * realVelocitySquaredLength <= dot)
//                 {
//                     ASSERT_EQUAL(realVelocitySquaredLength * centerDifferenceSquaredLength - dot * dot <= realVelocitySquaredLength * radiusSumSquared,
// 						         TestIntersection(firstBound,firstVector,secondBound,secondVector,max));
//                 }
//                 else
//                 {
//                     ASSERT_EQUAL(max * (max * realVelocitySquaredLength + 2.0f * dot) + centerDifferenceSquaredLength <= radiusSumSquared,
//                                  TestIntersection(firstBound,firstVector,secondBound,secondVector,max));
//                 }
//             }
//         }
// 		else
// 		{
// 			ASSERT_EQUAL(centerDifferenceSquaredLength <= radiusSumSquared,
// 				         TestIntersection(firstBound,firstVector,secondBound,secondVector,max));
// 		}            
//     }
}