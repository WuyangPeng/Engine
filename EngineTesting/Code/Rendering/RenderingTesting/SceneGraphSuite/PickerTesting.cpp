// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.3 (2019/09/05 11:06)

#include "PickerTesting.h"
#include "Rendering/Detail/SwitchNode.h"
#include "Rendering/SceneGraph/Picker.h"
#include "Rendering/SceneGraph/Node.h"
#include "Rendering/SceneGraph/Triangles.h"
#include "Rendering/SceneGraph/PickRecord.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Intersection/Intersection3D/StaticFindIntersectorLine3Triangle3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"


#include <random>

using std::swap;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PickerTesting) 

void Rendering::PickerTesting
	::MainTest()
{
	CoreTools::InitTerm::ExecuteInitializers();

	CameraManager::Create();
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);

	RendererManager::Destroy();
	CameraManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::PickerTesting
	::BaseTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-1.0f,1.0f);  

	for (int loop = 0; loop < GetTestLoopCount(); ++loop)
	{
// 		Mathematics::APointf origin(firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator));
// 
// 		Mathematics::AVectorf direction(firstFloatRandomDistribution(generator),
//                                         firstFloatRandomDistribution(generator),
// 									    firstFloatRandomDistribution(generator));
// 
// 		direction.Normalize();
// 
// 		float tMin = -Mathematics::FloatMath::sm_MaxReal;
// 		float tMax = Mathematics::FloatMath::sm_MaxReal;
// 
// 		SpatialSharedPtr scene(new Node);
// 		scene->Update();
// 
// 		Picker firstPicker(scene.PolymorphicDowncastConstObjectSharedPtr<ConstSpatialSharedPtr>(),origin,direction,tMin,tMax);
// 
// 		ASSERT_FALSE(firstPicker.IsRecordsExist());
// 
// 		SpatialSharedPtr switchScene(new SwitchNode);
// 		switchScene->Update();
// 
// 		Picker secondPicker(switchScene.PolymorphicDowncastConstObjectSharedPtr<ConstSpatialSharedPtr>(),origin, direction, tMin, tMax);
// 
// 		ASSERT_FALSE(secondPicker.IsRecordsExist());
// 
// 		VisualSharedPtr firstTrianglesMesh = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMesh.trv"));
// 		firstTrianglesMesh->Update();
// 
// 		TrianglesSharedPtr secondTrianglesMesh = firstTrianglesMesh.PolymorphicDowncastObjectSharedPtr<TrianglesSharedPtr>();
// 
// 		Picker thirdPicker(firstTrianglesMesh.PolymorphicDowncastConstObjectSharedPtr<ConstSpatialSharedPtr>(),
// 			               origin, direction, tMin, tMax);	
// 
// 		PickRecordContainer container;
// 
// 		if (firstTrianglesMesh->GetWorldBound().TestIntersection(origin, direction, tMin, tMax))
// 		{
// 			Transform worldInverseTransform =  firstTrianglesMesh->GetWorldTransform().GetInverseTransform();
// 			Mathematics::APointf modelOriginPoint = worldInverseTransform * origin;
// 			Mathematics::Vector3Df modelOrigin = modelOriginPoint.GetVector3D();
// 
// 			Mathematics::AVectorf modelDirectionVector = worldInverseTransform * direction;
// 			Mathematics::Vector3Df modelDirection = modelDirectionVector.GetVector3D();
// 
// 			Mathematics::Line3f line(modelOrigin, modelDirection);
// 	 
// 			VertexBufferAccessor vertexBufferAccessor (firstTrianglesMesh->GetConstVertexFormat(),  firstTrianglesMesh->GetConstVertexBuffer());
// 
// 			int numTriangles = secondTrianglesMesh->GetNumTriangles();
// 			for (int i = 0; i < numTriangles; ++i)
// 			{	
// 				TriangleIndex triangleIndex = secondTrianglesMesh->GetTriangle(i);
// 				
// 				Mathematics::Vector3Df vertex0 =  vertexBufferAccessor.GetPosition<Mathematics::Vector3Df>(triangleIndex.GetFirstIndex());
// 				Mathematics::Vector3Df vertex1 =  vertexBufferAccessor.GetPosition<Mathematics::Vector3Df>(triangleIndex.GetSecondIndex());
// 				Mathematics::Vector3Df vertex2 =  vertexBufferAccessor.GetPosition<Mathematics::Vector3Df>(triangleIndex.GetThirdIndex());
// 				Mathematics::Triangle3f triangle(vertex0, vertex1, vertex2);
// 
// 				Mathematics::StaticFindIntersectorLine3Triangle3f	intersector(line, triangle);
// 				
// 				if (intersector.IsIntersection() && tMin <= intersector.GetLineParameter() && intersector.GetLineParameter() <= tMax)
// 				{
// 					PickRecord record;
// 					
// 					record.SetIntersected(firstTrianglesMesh.PolymorphicDowncastConstObjectSharedPtr<ConstSpatialSharedPtr>());
// 					record.SetParameter(intersector.GetLineParameter());
// 					record.SetTriangle(i);
// 					record.SetBary(intersector.GetTriangleBary0(), intersector.GetTriangleBary1());
// 					
// 					container.InsertPickRecord(record);
// 				}	
// 				 
// 			}
// 
// 			if (container.IsEmpty())
// 			{
// 				ASSERT_FALSE(thirdPicker.IsRecordsExist());
// 			}
// 			else
// 			{
// 				ASSERT_TRUE(thirdPicker.IsRecordsExist());
// 			}
// 		}
// 		else
// 		{
// 			ASSERT_FALSE(thirdPicker.IsRecordsExist());
// 		}
// 
// 
// 		if (thirdPicker.IsRecordsExist())
// 		{
// 			// 最近值测试
// 			float closest = Mathematics::FloatMath::FAbs(container.GetPickRecord(0).GetParameter());
// 			int index = 0;
// 			const int numRecords = container.GetSize();
// 			for (int i = 1; i < numRecords; ++i)
// 			{
// 				float parameter = Mathematics::FloatMath::FAbs(container.GetPickRecord(i).GetParameter());
// 				if (parameter < closest)
// 				{
// 					closest = parameter;
// 					index = i;
// 				}
// 			}			
// 			ASSERT_APPROXIMATE(container.GetPickRecord(index).GetParameter(), thirdPicker.GetClosestToZero().GetParameter(), 1e-8f);
// 
// 			ASSERT_EQUAL(container.GetPickRecord(index).GetTriangle(), thirdPicker.GetClosestToZero().GetTriangle());
// 
// 			ASSERT_EQUAL(thirdPicker.GetClosestToZero().GetIntersected(), firstTrianglesMesh);
// 
// 			ASSERT_APPROXIMATE(container.GetPickRecord(index).GetBary(0),  thirdPicker.GetClosestToZero().GetBary(0), 1e-8f);
// 
// 			ASSERT_APPROXIMATE(container.GetPickRecord(index).GetBary(1), thirdPicker.GetClosestToZero().GetBary(1), 1e-8f);
// 
// 			ASSERT_APPROXIMATE(container.GetPickRecord(index).GetBary(2), thirdPicker.GetClosestToZero().GetBary(2), 1e-8f);
// 
// 			closest = Mathematics::FloatMath::sm_MaxReal;
// 
// 			int findIndex = -1;
// 			for (int i = 0; i < numRecords; ++i)
// 			{
// 				float parameter = container.GetPickRecord(i).GetParameter();
// 				if (0.0f <= parameter)
// 				{
// 					closest = parameter;
// 					findIndex = i;
// 					break;
// 				}
// 			}
// 			if (findIndex != -1)
// 			{
// 				for (int i = findIndex + 1; i < numRecords; ++i)
// 				{
// 					float parameter = container.GetPickRecord(i).GetParameter();
// 					if (0.0f <= parameter && parameter < closest)
// 					{
// 						closest = parameter;
// 						findIndex = i;
// 					}
// 				}
// 
// 				ASSERT_APPROXIMATE(container.GetPickRecord(findIndex).GetParameter(),  thirdPicker.GetClosestNonnegative().GetParameter(), 1e-8f);
// 				
// 				ASSERT_EQUAL(container.GetPickRecord(findIndex).GetTriangle(), thirdPicker.GetClosestNonnegative().GetTriangle());
// 
// 				ASSERT_EQUAL(thirdPicker.GetClosestNonnegative().GetIntersected(),  firstTrianglesMesh);
// 
// 			    ASSERT_APPROXIMATE(container.GetPickRecord(findIndex).GetBary(0),  thirdPicker.GetClosestNonnegative().GetBary(0), 1e-8f);
// 				
// 				ASSERT_APPROXIMATE(container.GetPickRecord(findIndex).GetBary(1), thirdPicker.GetClosestNonnegative().GetBary(1), 1e-8f);
// 				
// 				ASSERT_APPROXIMATE(container.GetPickRecord(findIndex).GetBary(2), thirdPicker.GetClosestNonnegative().GetBary(2), 1e-8f);				 
// 			}
// 
// 			// 获取第一个负数。
// 			closest = -Mathematics::FloatMath::sm_MaxReal;
// 
// 			findIndex = -1;
// 			for (int i = 0; i < numRecords; ++i)
// 			{
// 				float parameter = container.GetPickRecord(i).GetParameter();
// 				if (parameter <= 0.0f)
// 				{
// 					closest = parameter;
// 					findIndex = i;
// 					break;
// 				}
// 			}
// 			if (findIndex != -1)
// 			{
// 				for (int i = findIndex + 1; i < numRecords; ++i)
// 				{
// 					float parameter = container.GetPickRecord(i).GetParameter();
// 					if (closest < parameter && parameter <= 0.0f)
// 					{
// 						closest = parameter;
// 						findIndex = i;				
// 					}		
// 				}
// 
// 				ASSERT_APPROXIMATE(container.GetPickRecord(findIndex).GetParameter(),thirdPicker.GetClosestNonpositive().GetParameter(), 1e-8f);
// 				
// 				ASSERT_EQUAL(container.GetPickRecord(findIndex).GetTriangle(), thirdPicker.GetClosestNonpositive().GetTriangle());
// 
// 				ASSERT_EQUAL(thirdPicker.GetClosestNonpositive().GetIntersected(), firstTrianglesMesh);
// 
// 			    ASSERT_APPROXIMATE(container.GetPickRecord(findIndex).GetBary(0),thirdPicker.GetClosestNonpositive().GetBary(0), 1e-8f);
// 				
// 				ASSERT_APPROXIMATE(container.GetPickRecord(findIndex).GetBary(1), thirdPicker.GetClosestNonpositive().GetBary(1), 1e-8f);
// 				
// 				ASSERT_APPROXIMATE(container.GetPickRecord(findIndex).GetBary(2),thirdPicker.GetClosestNonpositive().GetBary(2), 1e-8f);
// 			}
// 		}
// 
// 		if (thirdPicker.IsRecordsExist())
// 		{
// 			// 节点递归测试
// 			NodeSharedPtr node = scene.PolymorphicDowncastObjectSharedPtr<NodeSharedPtr>();
// 			SpatialSharedPtr secondTrianglesMesh2 = firstTrianglesMesh.PolymorphicDowncastObjectSharedPtr<SpatialSharedPtr>();
// 			node->AttachChild(secondTrianglesMesh2);
// 			node->Update();
// 
// 			Picker fourthPicker(node.PolymorphicDowncastConstObjectSharedPtr<ConstSpatialSharedPtr>(),
// 			                    origin, direction, tMin, tMax);	
// 
// 			ASSERT_TRUE(fourthPicker.IsRecordsExist());
// 
// 			node->DetachChild(secondTrianglesMesh);
// 
// 			SwitchNodeSharedPtr switchNodeScene = switchScene.PolymorphicDowncastObjectSharedPtr<SwitchNodeSharedPtr>();
// 			switchNodeScene->AttachChild(secondTrianglesMesh);
// 			switchNodeScene->Update();
// 
// 			Picker fifthPicker(switchNodeScene.PolymorphicDowncastConstObjectSharedPtr<ConstSpatialSharedPtr>(),origin, direction, tMin, tMax);
// 
// 			ASSERT_FALSE(fifthPicker.IsRecordsExist());
// 
// 			switchNodeScene->SetActiveChild(0);
// 
// 			Picker sixthPicker(switchNodeScene.PolymorphicDowncastConstObjectSharedPtr<ConstSpatialSharedPtr>(),origin, direction, tMin, tMax);
// 
// 			ASSERT_TRUE(sixthPicker.IsRecordsExist());
// 		}

	}
}
 