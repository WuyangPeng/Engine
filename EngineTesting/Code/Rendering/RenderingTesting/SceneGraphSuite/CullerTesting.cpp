// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.3 (2019/09/05 10:48)

#include "CullerTesting.h"
#include "SpatialTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/Culler.h"

#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/PlaneDetail.h"

#include <random>
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, CullerTesting)

void Rendering::CullerTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    CameraManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CameraTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PlaneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SpatialPtrTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VisibleTest);

    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26429)
void Rendering::CullerTesting::CameraTest()
{
    // 	CameraSharedPtr firstCamera(new Camera);
    // 	CameraSharedPtr secondCamera(new Camera);
    //
    // 	Culler	firstCuller(firstCamera.PolymorphicDowncastConstObjectSharedPtr<ConstCameraSharedPtr>());
    //
    // 	ASSERT_EQUAL(firstCuller.GetCamera(),firstCamera);
    //
    // 	firstCuller.SetCamera(secondCamera.PolymorphicDowncastConstObjectSharedPtr<ConstCameraSharedPtr>());
    //
    // 	ASSERT_EQUAL(firstCuller.GetCamera(),secondCamera);
    //
    // 	secondCamera->SetFrame(Camera::APoint(2.0f,1.5f,2.0f),Camera::AVector(0.0f,0.0f,1.0f),
    // 	                       Camera::AVector(1.0f,0.0f,0.0f),Camera::AVector(0.0f,1.0f,0.0f));
    //
    // 	float firstFrustum[6] = { 1.0f,100.0f,-1.0f,1.0f,-1.0f,1.0f };
    //
    // 	firstCuller.SetFrustum(firstFrustum);
    //
    // 	const float* secondFrustum = firstCuller.GetFrustum();
    //
    // 	for(int i = 0; i < 6;++i)
    // 	{
    // 	    ASSERT_APPROXIMATE(firstFrustum[0], secondFrustum[0],1e-8f);
    // 	}
    //
    // 	// 测试前六个裁剪平面
    //
    // 	ASSERT_EQUAL(firstCuller.GetPlaneState(),0xFFFFFFFF);
    //
    // 	float directionMin2 = firstFrustum[0] * firstFrustum[0];
    // 	float upMin2 = firstFrustum[2] * firstFrustum[2];
    // 	float upMax2 = firstFrustum[3] * firstFrustum[3];
    // 	float rightMin2 = firstFrustum[4] * firstFrustum[4];
    // 	float rightMax2 = firstFrustum[5] * firstFrustum[5];
    //
    // 	// 获取相机坐标系。
    // 	Camera::APoint position = secondCamera->GetPosition();
    // 	Camera::AVector directionVector = secondCamera->GetDirectionVector();
    // 	Camera::AVector upVector = secondCamera->GetUpVector();
    // 	Camera::AVector rightVector = secondCamera->GetRightVector();
    // 	float directionDotEye = Dot(position,directionVector);
    //
    // 	const Culler::Plane* firstPlane = firstCuller.GetPlanes ();
    //
    // 	// 测试近平面
    // 	ASSERT_TRUE(Approximate(firstPlane[System::EnumCastUnderlying(ViewFrustum::DirectionMin)],Culler::Plane(directionVector,directionDotEye + firstFrustum[0]),1e-8f));
    //
    //
    // 	// 测试远平面
    // 	ASSERT_TRUE(Approximate(firstPlane[System::EnumCastUnderlying(ViewFrustum::DirectionMax)],Culler::Plane(-directionVector,-directionDotEye - firstFrustum[1]),1e-8f));
    //
    //     // 测试底部平面
    //     float invLength = Camera::Math::InvSqrt(directionMin2 + upMin2);
    //     float c0 = -firstFrustum[2] * invLength;
    //     float c1 = +firstFrustum[0] * invLength;
    //     Camera::AVector normal = c0 * directionVector + c1 * upVector;
    //     float constant = Dot(position,normal);
    //
    // 	ASSERT_TRUE(Approximate(firstPlane[System::EnumCastUnderlying(ViewFrustum::UpMin)],Culler::Plane(normal, constant)));
    //
    //
    //     // 测试顶部平面
    //     invLength = Camera::Math::InvSqrt(directionMin2 + upMax2);
    //     c0 = +firstFrustum[3] * invLength;
    //     c1 = -firstFrustum[0] * invLength;
    //     normal = c0 * directionVector + c1 * upVector;
    //     constant = Dot(position,normal);
    //
    // 	ASSERT_TRUE(Approximate(firstPlane[System::EnumCastUnderlying(ViewFrustum::UpMax)],Culler::Plane(normal, constant),1e-8f));
    //
    //     // 测试左平面
    //     invLength = Camera::Math::InvSqrt(directionMin2 + rightMin2);
    //     c0 = -firstFrustum[4] * invLength;
    //     c1 = +firstFrustum[0] * invLength;
    //     normal = c0 * directionVector + c1 * rightVector;
    //     constant = Dot(position,normal);
    //
    // 	ASSERT_TRUE(Approximate(firstPlane[System::EnumCastUnderlying(ViewFrustum::RightMin)],Culler::Plane(normal, constant),1e-8f));
    //
    //     // 测试右平面
    //     invLength = Camera::Math::InvSqrt(directionMin2 + rightMax2);
    //     c0 = +firstFrustum[5] * invLength;
    //     c1 = -firstFrustum[0] * invLength;
    //     normal = c0 * directionVector + c1 * rightVector;
    //     constant = Dot(position,normal);
    //
    // 	ASSERT_TRUE(Approximate(firstPlane[System::EnumCastUnderlying(ViewFrustum::RightMax)],Culler::Plane(normal, constant),1e-8f));
}

void Rendering::CullerTesting::PlaneTest()
{
    // 	CameraSharedPtr firstCamera(new Camera);
    //
    // 	Culler	firstCuller(firstCamera.PolymorphicDowncastConstObjectSharedPtr<ConstCameraSharedPtr>());
    //
    // 	firstCamera->SetFrame(Camera::APoint(2.0f,1.5f,2.0f),Camera::AVector(0.0f,0.0f,1.0f),Camera::AVector(1.0f,0.0f,0.0f),Camera::AVector(0.0f,1.0f,0.0f));
    //
    // 	firstCamera->SetFrustum(1.0f,100.0f,-1.0f,1.0f,-1.0f,1.0f);
    //
    // 	SpatialSharedPtr scene(new SpatialTest);
    //
    // 	ASSERT_EQUAL(firstCuller.GetPlaneState(),0u);
    // 	ASSERT_EQUAL(firstCuller.GetPlaneQuantity(),6);
    //
    // 	firstCuller.ComputeVisibleSet(scene);
    //
    // 	ASSERT_EQUAL(firstCuller.GetPlaneState(),0xFFFFFFFF);
    // 	ASSERT_EQUAL(firstCuller.GetPlaneQuantity(),6);
    //
    // 	firstCuller.SetPlaneState(0xFFFFFFFE);
    //
    // 	ASSERT_EQUAL(firstCuller.GetPlaneState(),0xFFFFFFFE);
    //
    // 	firstCuller.PopPlane();
    //
    // 	ASSERT_EQUAL(firstCuller.GetPlaneQuantity(),6);
    //
    // 	firstCuller.PushPlane(Culler::Plane());
    // 	firstCuller.PushPlane(Culler::Plane());
    //
    // 	ASSERT_EQUAL(firstCuller.GetPlaneQuantity(),8);
    //
    // 	firstCuller.PopPlane();
    //
    // 	ASSERT_EQUAL(firstCuller.GetPlaneQuantity(),7);
    //
    // 	Culler::Plane firstPlane(Camera::AVector::sm_UnitY,5.0f);
    //
    // 	firstCuller.PushPlane(firstPlane);
    //
    // 	ASSERT_EQUAL(firstCuller.GetPlaneQuantity(),8);
    //
    // 	ASSERT_TRUE(Approximate(firstCuller.GetPlanes()[7], firstPlane,1e-8f));
}

void Rendering::CullerTesting::SpatialPtrTest()
{
    // 	CameraSharedPtr firstCamera(new Camera);
    //
    // 	Culler	firstCuller(firstCamera.PolymorphicDowncastConstObjectSharedPtr<ConstCameraSharedPtr>());
    //
    // 	VisualSharedPtr firstSpatialPtr(new SpatialTest);
    // 	VisualSharedPtr secondSpatialPtr(new SpatialTest);
    //
    // 	ASSERT_EQUAL(firstCuller.GetNumVisible(),0);
    //
    // 	firstCuller.Insert(firstSpatialPtr);
    // 	firstCuller.Insert(secondSpatialPtr);
    //
    // 	ASSERT_EQUAL(firstCuller.GetNumVisible(),2);
    //
    // 	ASSERT_EQUAL(firstCuller.GetVisible(0), firstSpatialPtr);
    // 	ASSERT_EQUAL(firstCuller.GetVisible(1), secondSpatialPtr);
}

void Rendering::CullerTesting::VisibleTest()
{
    // 	std::default_random_engine generator;
    // 	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);
    //
    // 	for(int loop = 0;loop < GetTestLoopCount();++loop)
    // 	{
    //         Bound::APoint firstCenter(firstFloatRandomDistribution(generator),
    //                                   firstFloatRandomDistribution(generator),
    //                                   firstFloatRandomDistribution(generator));
    //
    //         float firstRadius = Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator));
    //
    //         Bound firstBound(firstCenter, firstRadius);
    //
    //         Camera::APoint firstPosition(firstFloatRandomDistribution(generator),
    //                                      firstFloatRandomDistribution(generator),
    //                                      firstFloatRandomDistribution(generator));
    //
    //         Camera::AVector firstVector(firstFloatRandomDistribution(generator),
    //                                     firstFloatRandomDistribution(generator),
    //                                     firstFloatRandomDistribution(generator));
    //
    //         firstVector.Normalize();
    //
    // 		Camera::AVector secondVector(firstFloatRandomDistribution(generator),
    // 			                         firstFloatRandomDistribution(generator),
    // 									 firstFloatRandomDistribution(generator));
    //
    // 		secondVector.Normalize();
    //
    // 		Camera::AVector thirdVector(firstFloatRandomDistribution(generator),
    // 			                        firstFloatRandomDistribution(generator),
    // 									firstFloatRandomDistribution(generator));
    //
    // 		thirdVector.Normalize();
    //
    //         float directionMin(- Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator)));
    //
    //         float directionMax = -directionMin;
    //
    //         float upMin(- Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator)));
    //
    //         float upMax = -upMin;
    //
    //         float rightMin(- Mathematics::MathF::FAbs(firstFloatRandomDistribution(generator)));
    //
    //         float rightMax = -rightMin;
    //
    // 		CameraSharedPtr firstCamera(new Camera(true, 1e-4f));
    //
    //         firstCamera->SetFrame(firstPosition, firstVector,secondVector, thirdVector);
    //         firstCamera->SetFrustum(directionMin, directionMax, upMin,upMax, rightMin, rightMax);
    //
    // 		Culler	firstCuller(firstCamera.PolymorphicDowncastConstObjectSharedPtr<ConstCameraSharedPtr>());
    //
    // 		SpatialSharedPtr scene(new SpatialTest);
    //
    //         firstCuller.ComputeVisibleSet(scene);
    //
    //         if (firstBound.GetRadius() <= Camera::Math::sm_ZeroTolerance)
    //         {
    //             ASSERT_FALSE(firstCuller.IsVisible(firstBound));
    //         }
    //         else
    //         {
    //             bool isVisible = true;
    // 			unsigned int mask = (1 << 5);
    //
    //             for (int index = 5; 0 <= index; --index)
    //             {
    // 				int planeState = firstCuller.GetPlaneState();
    //
    // 				if (planeState & mask)
    // 				{
    // 					Mathematics::NumericalValueSymbol side =
    // 						firstBound.WhichSide(firstCuller.GetPlanes()[index]);
    //
    // 					if (side == Mathematics::NumericalValueSymbol::Negative)
    // 					{
    // 						ASSERT_FALSE(firstCuller.IsVisible(firstBound));
    // 						isVisible = false;
    // 						break;
    // 					}
    //
    // 					if (side == Mathematics::NumericalValueSymbol::Positive)
    // 					{
    // 						planeState &= ~mask;;
    // 					}
    // 				}
    //             }
    //
    //             if(isVisible)
    //             {
    //                 ASSERT_TRUE(firstCuller.IsVisible(firstBound));
    //             }
    //         }
    //
    //         vector<Mathematics::APointf> pointVector;
    //         int numVertices = 10;
    //
    //         for (int index = 0; index <= numVertices; ++index)
    //         {
    //             pointVector.push_back(Mathematics::APointf(firstFloatRandomDistribution(generator),
    //                                                        firstFloatRandomDistribution(generator),
    //                                                        firstFloatRandomDistribution(generator)));
    //         }
    //
    //         bool isVisible = true;
    //
    //         for (int index = 5; 0 < index; --index)
    //         {
    //             const Mathematics::Planef& plane = firstCuller.GetPlanes()[index];
    //
    //             int which = numVertices;
    //             for (int j = 0; j < numVertices; ++j)
    //             {
    //                 Mathematics::NumericalValueSymbol side = plane.WhichSide(pointVector[j]);
    //                 if (side !=  Mathematics::NumericalValueSymbol::Negative)
    //                 {
    //                     which = j;
    //                     break;
    //                 }
    //             }
    //
    //             if (which == numVertices)
    //             {
    //                  ASSERT_FALSE(firstCuller.IsVisible(numVertices,&pointVector[0],true));
    //                  isVisible = false;
    //                  break;
    //             }
    //         }
    //
    //         if(isVisible)
    //         {
    //             ASSERT_TRUE(firstCuller.IsVisible(numVertices,&pointVector[0], true));
    //         }
    //
    // 		isVisible = true;
    //
    // 		for (int index = 5; 0 <= index; --index)
    // 		{
    // 			const Mathematics::Planef& plane = firstCuller.GetPlanes()[index];
    //
    // 			int which = numVertices;
    // 			for (int j = 0; j < numVertices; ++j)
    // 			{
    // 				Mathematics::NumericalValueSymbol side = plane.WhichSide(pointVector[j]);
    // 				if (side != Mathematics::NumericalValueSymbol::Negative)
    // 				{
    // 					which = j;
    // 					break;
    // 				}
    // 			}
    //
    // 			if (which == numVertices)
    // 			{
    // 				ASSERT_FALSE(firstCuller.IsVisible(numVertices, &pointVector[0], false));
    // 				isVisible = false;
    // 				break;
    // 			}
    // 		}
    //
    // 		if (isVisible)
    // 		{
    // 			ASSERT_TRUE(firstCuller.IsVisible(numVertices, &pointVector[0], false));
    // 		}
    //
    //         Mathematics::Planef plane(pointVector[0],pointVector[1],pointVector[2]);
    //
    //         float nDotEMinusC = plane.DistanceTo(firstCamera->GetPosition());
    //
    //         Mathematics::AVectorf normal = plane.GetNormal();
    //         float nDotDirection = Dot(normal, firstCamera->GetDirectionVector());
    //         float nDotUp = Dot(normal, firstCamera->GetUpVector());
    //         float nDotRight = Dot(normal, firstCamera->GetRightVector());
    //         float directionRatio = firstCamera->GetDirectionMax() / firstCamera->GetDirectionMin();
    //
    //         int positive = 0;
    //         int negative = 0;
    //
    //         float pDirectionMin = firstCamera->GetDirectionMin() * nDotDirection;
    //         float nearUpMin = firstCamera->GetUpMin() * nDotUp;
    //         float nearUpMax = firstCamera->GetUpMax() * nDotUp;
    //         float nearRightMin = firstCamera->GetRightMin() * nDotRight;
    // 		float nearRightMax = firstCamera->GetRightMax() * nDotRight;
    //
    //         float signDistance = nDotEMinusC + pDirectionMin + nearUpMin + nearRightMin;
    //         if (0.0f < signDistance)
    //         {
    //             ++positive;
    //         }
    //         else if (signDistance < 0.0f)
    //         {
    //             ++negative;
    //         }
    //
    //         signDistance = nDotEMinusC + pDirectionMin + nearUpMin + nearRightMax;
    //         if (0.0f < signDistance)
    //         {
    //             ++positive;
    //         }
    //         else if (signDistance < 0.0f)
    //         {
    //             ++negative;
    //         }
    //
    //         signDistance = nDotEMinusC + pDirectionMin + nearUpMax + nearRightMin;
    //         if (0.0f < signDistance)
    //         {
    //             ++positive;
    //         }
    //         else if (signDistance < 0.0f)
    //         {
    //             ++negative;
    //         }
    //
    //         signDistance = nDotEMinusC + pDirectionMin + nearUpMax + nearRightMax;
    //         if (0.0f < signDistance)
    //         {
    //             ++positive;
    //         }
    //         else if (signDistance < 0.0f)
    //         {
    //             ++negative;
    //         }
    //
    //         float pDirectionMax = firstCamera->GetDirectionMax() * nDotDirection;
    //         float farUpMin = directionRatio * nearUpMin;
    //         float farUpMax = directionRatio * nearUpMax;
    //         float farRightMin = directionRatio * nearRightMin;
    //         float farRightMax = directionRatio * nearRightMax;
    //
    //         signDistance = nDotEMinusC + pDirectionMax + farUpMin + farRightMin;
    //         if (0.0f < signDistance)
    //         {
    //             ++positive;
    //         }
    //         else if (signDistance < 0.0f)
    //         {
    //             ++negative;
    //         }
    //
    //         signDistance = nDotEMinusC + pDirectionMax + farUpMin + farRightMax;
    //         if (0.0f < signDistance)
    //         {
    //             ++positive;
    //         }
    //         else if (signDistance < 0.0f)
    //         {
    //             ++negative;
    //         }
    //
    //
    //         signDistance = nDotEMinusC + pDirectionMax + farUpMax + farRightMin;
    //         if (0.0f < signDistance)
    //         {
    //             ++positive;
    //         }
    //         else if (signDistance < 0.0f)
    //         {
    //             ++negative;
    //         }
    //
    //         signDistance = nDotEMinusC + pDirectionMax + farUpMax + farRightMax;
    //         if (0.0f < signDistance)
    //         {
    //             ++positive;
    //         }
    //         else if (signDistance < 0.0f)
    //         {
    //             ++negative;
    //         }
    //
    //         if (0 < positive)
    //         {
    //             if (0 < negative)
    //             {
    //                 ASSERT_ENUM_EQUAL(Mathematics::NumericalValueSymbol::Zero,firstCuller.WhichSide(plane));
    //             }
    //             else
    //             {
    // 				ASSERT_ENUM_EQUAL(Mathematics::NumericalValueSymbol::Positive,firstCuller.WhichSide(plane));
    //             }
    //         }
    //         else
    //         {
    // 			ASSERT_ENUM_EQUAL(Mathematics::NumericalValueSymbol::Negative,firstCuller.WhichSide(plane));
    //         }
    // 	}
}
