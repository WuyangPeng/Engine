// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.3 (2019/09/06 16:41)

#include "ClodMeshTesting.h"
#include "Rendering/Detail/ClodMesh.h"
#include "Rendering/Detail/CreateClodMesh.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/Detail/SwitchNode.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"

#include "CoreTools/FileManager/WriteFileManager.h"

#include <random>
#include <vector>

using std::vector;
using CoreTools::WriteFileManager;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ClodMeshTesting) 

void Rendering::ClodMeshTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	CameraManager::Create();
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesMeshFile);
	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
	
	RendererManager::Destroy();
	CameraManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::ClodMeshTesting
	::CreateTrianglesMeshFile()
{
	WriteFileManager manage(SYSTEM_TEXT("Resource/DetailSuite/ClodMesh.trv"));

	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-1.0f,1.0f);  	

	int type = System::EnumCastUnderlying(VisualPrimitiveType::TriangleMesh);
	manage.Write(sizeof(int), &type);

	// VertexFormat
	vector<VertexFormatType> firstVertexFormatType{
			VertexFormatType(VertexFormatFlags::AttributeType::Float3,
							 VertexFormatFlags::AttributeUsage::Position, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float3,
							 VertexFormatFlags::AttributeUsage::Normal, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float3,
							 VertexFormatFlags::AttributeUsage::Tangent, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float3,
							 VertexFormatFlags::AttributeUsage::Binormal, 0),
			VertexFormatType(VertexFormatFlags::AttributeType::Float2,
							 VertexFormatFlags::AttributeUsage::TextureCoord, 0) };

	VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

	firstVertexFormat->SaveToFile(manage);

	// VertexBuffer
	int numElements = 20;
	int elementSize = firstVertexFormat->GetStride();
	int usage = System::EnumCastUnderlying(BufferUsage::Static);

	manage.Write(sizeof(int), &numElements);
	manage.Write(sizeof(int), &elementSize);
	manage.Write(sizeof(int), &usage);

	int vertexIndex = 0;
	for (int i = 0; i < numElements; ++i)
	{
		for (int attributesIndex = 0; 
			 attributesIndex < firstVertexFormat->GetNumAttributes();
			 ++attributesIndex)
		{
			VertexFormat::AttributeType type2 = 
				firstVertexFormat->GetAttributeType(attributesIndex);
			
			int componentSize = VertexFormat::GetComponentSize(type2);
			int numComponents = VertexFormat::GetNumComponents(type2);

			vector<char> buffer(componentSize * numComponents);

			for (unsigned bufferIndex = 0;bufferIndex < buffer.size() / sizeof(float);
				 ++bufferIndex)
			{
				float* floatBufferPtr = reinterpret_cast<float*>(&buffer[bufferIndex * sizeof(float)]);
			
			    *floatBufferPtr = firstFloatRandomDistribution(generator);
			}

			manage.Write(componentSize,numComponents,&buffer[0]);
		}
		
		vertexIndex += elementSize;
	}

	// IndexBuffer
	int indexBufferNumElements = 48;
	elementSize = 4;
	int numBytes = indexBufferNumElements * elementSize;

	manage.Write(sizeof(int), &indexBufferNumElements);
	manage.Write(sizeof(int), &elementSize);
	manage.Write(sizeof(int), &usage);
	manage.Write(sizeof(int), &numBytes);

    vector<char> buffer(numBytes);

	int* intBufferPtr = reinterpret_cast<int*>(&buffer[0]);

	intBufferPtr[0] = 0;
	intBufferPtr[1] = 1;
	intBufferPtr[2] = 2;
	intBufferPtr[3] = 2;
	intBufferPtr[4] = 1;
	intBufferPtr[5] = 3;

	intBufferPtr[6] = 4;
	intBufferPtr[7] = 0;
	intBufferPtr[8] = 2;
	intBufferPtr[9] = 4;
	intBufferPtr[10] = 2;
	intBufferPtr[11] = 3;

	intBufferPtr[12] = 5;
	intBufferPtr[13] = 6;
	intBufferPtr[14] = 7;
	intBufferPtr[15] = 7;
	intBufferPtr[16] = 6;
	intBufferPtr[17] = 8;

	intBufferPtr[18] = 9;
	intBufferPtr[19] = 5;
	intBufferPtr[20] = 7;
	intBufferPtr[21] = 9;
	intBufferPtr[22] = 7;
	intBufferPtr[23] = 8;

	intBufferPtr[24] = 10;
	intBufferPtr[25] = 11;
	intBufferPtr[26] = 12;
	intBufferPtr[27] = 12;
	intBufferPtr[28] = 11;
	intBufferPtr[29] = 13;

	intBufferPtr[30] = 14;
	intBufferPtr[31] = 10;
	intBufferPtr[32] = 12;
	intBufferPtr[33] = 14;
	intBufferPtr[34] = 12;
	intBufferPtr[35] = 13;

	intBufferPtr[36] = 15;
	intBufferPtr[37] = 16;
	intBufferPtr[38] = 17;
	intBufferPtr[39] = 17;
	intBufferPtr[40] = 16;
	intBufferPtr[41] = 18;

	intBufferPtr[42] = 19;
	intBufferPtr[43] = 15;
	intBufferPtr[44] = 17;
	intBufferPtr[45] = 19;
	intBufferPtr[46] = 17;
	intBufferPtr[47] = 18;
	
	manage.Write(elementSize, numBytes / elementSize, &buffer[0]);

	int offset = 0;

	manage.Write(sizeof(int),&offset);
}
 
void Rendering::ClodMeshTesting
	::InitTest()
{
	VisualSharedPtr firstTrianglesMesh =	LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/DetailSuite/ClodMesh.trv"));

	TrianglesMeshSharedPtr mesh(new TrianglesMesh(firstTrianglesMesh->GetVertexFormat(),
		                                              firstTrianglesMesh->GetVertexBuffer(),
		                                              firstTrianglesMesh->GetIndexBuffer()));

	CreateClodMesh createClodMesh(mesh);

	ClodMesh firstNode(firstTrianglesMesh->GetVertexFormat(),
		               firstTrianglesMesh->GetVertexBuffer(),
					   firstTrianglesMesh->GetIndexBuffer(),
					   createClodMesh.GetCollapseRecordArray());
 
 	ASSERT_EQUAL(firstNode.GetNumControllers(),0);
 
	ControllerInterfaceSharedPtr secondNode(new SwitchNode);
	firstNode.AttachController(secondNode);

	ASSERT_EQUAL(firstNode.GetNumControllers(),1);
	ASSERT_EQUAL(firstNode.GetController(0), secondNode);

	ControllerInterfaceSharedPtr thirdNode(new SwitchNode);

	ASSERT_EQUAL_NULL_PTR(thirdNode->GetControllerObject());

	firstNode.AttachController(thirdNode);

// 	SwitchNode* ptr = CoreTools::StaticCast<SwitchNode>(thirdNode.GetData());
// 
// 	ASSERT_EQUAL(ptr->GetControllerObject(),&firstNode);
// 	ASSERT_EQUAL_NULL_PTR(ptr->GetParent());
// 
// 	ASSERT_EQUAL(firstNode.GetNumControllers(),2);
// 	ASSERT_EQUAL(firstNode.GetController(0), secondNode);
// 	ASSERT_EQUAL(firstNode.GetController(1), thirdNode);
// 
// 	firstNode.DetachController(secondNode);
// 
// 	ASSERT_EQUAL(firstNode.GetNumControllers(),1);
// 	ASSERT_EQUAL(firstNode.GetController(0), thirdNode);
// 
// 	firstNode.DetachAllControllers();
// 
// 	ASSERT_EQUAL(firstNode.GetNumControllers(),0);    
}

void Rendering::ClodMeshTesting
	::CopyTest()
{
// 	VisualSharedPtr firstTrianglesMesh =	LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/DetailSuite/ClodMesh.trv"));
// 
// 	TrianglesMeshSharedPtr mesh(new TrianglesMesh(firstTrianglesMesh->GetVertexFormat(),
// 		                                              firstTrianglesMesh->GetVertexBuffer(),
// 		                                              firstTrianglesMesh->GetIndexBuffer()));
// 
// 	CreateClodMesh createClodMesh(mesh);
// 
// 	ClodMesh firstNode(firstTrianglesMesh->GetVertexFormat(),
// 		               firstTrianglesMesh->GetVertexBuffer(),
// 					   firstTrianglesMesh->GetIndexBuffer(),
// 					   createClodMesh.GetCollapseRecordArray());
// 
// 	ASSERT_EQUAL(firstNode.GetNumControllers(), 0);
// 
// 	ControllerInterfaceSharedPtr controllerTest(new SwitchNode);
// 
// 	ControllerInterfaceSharedPtr secondSpatialTest(new SwitchNode);
// 	SwitchNode* firstPtr = CoreTools::StaticCast<SwitchNode>(secondSpatialTest.GetData());
// 
// 	ASSERT_EQUAL_NULL_PTR(secondSpatialTest->GetControllerObject());
// 
// 	secondSpatialTest->AttachController(controllerTest);
// 
// 	firstNode.AttachController(secondSpatialTest);
// 
// 	Transform firstTransform;
// 
// 	firstTransform.SetUniformScale(5.0f);
// 	firstPtr->SetLocalTransform(firstTransform);
//  
//  	ControllerInterfaceSharedPtr thirdSpatialTest(secondSpatialTest->Clone());
// 	SwitchNode* secondPtr = CoreTools::StaticCast<SwitchNode>(thirdSpatialTest.GetData());
// 
// 	Transform secondTransform;
// 	secondTransform.SetUniformScale(3.0f);
// 	secondPtr->SetLocalTransform(secondTransform);
// 
// 	ASSERT_APPROXIMATE(secondPtr->GetLocalTransform().GetUniformScale (),
// 		               3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstPtr->GetLocalTransform().GetUniformScale (),
// 		               5.0f,1e-8f);
// 
// 	firstNode.AttachController(thirdSpatialTest);
// 
// 	ASSERT_EQUAL(firstNode.GetNumControllers(), 2);
// 	ASSERT_EQUAL(firstNode.GetController(0), secondSpatialTest);
// 	ASSERT_EQUAL(firstNode.GetController(1), thirdSpatialTest);
// 
// 	secondSpatialTest->DetachController(controllerTest);
// 
// 	thirdSpatialTest->AttachController(controllerTest);
// 
// 	ASSERT_EQUAL(secondSpatialTest->GetNumControllers(),0);
// 
// 	// thirdSpatialTest已经复制了一个controllerTest
// 	ASSERT_EQUAL(thirdSpatialTest->GetNumControllers(),2); 		
}
 
void Rendering::ClodMeshTesting
	::StreamTest()
{
// 	VisualSharedPtr firstTrianglesMesh =	LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/DetailSuite/ClodMesh.trv"));
// 
// 	TrianglesMeshSharedPtr mesh(new TrianglesMesh(firstTrianglesMesh->GetVertexFormat(),
// 		                                              firstTrianglesMesh->GetVertexBuffer(),
// 		                                              firstTrianglesMesh->GetIndexBuffer()));
// 
// 	CreateClodMesh createClodMesh(mesh);
// 
// 	CoreTools::OutTopLevel outTopLevel;
// 	ClodMeshSharedPtr firstNode(new ClodMesh(firstTrianglesMesh->GetVertexFormat(),
// 		                                         firstTrianglesMesh->GetVertexBuffer(),
// 												 firstTrianglesMesh->GetIndexBuffer(),
// 												 createClodMesh.GetCollapseRecordArray()));
// 
// 	ASSERT_EQUAL(firstNode->GetTargetRecord(), 0);
// 	firstNode->SetTargetRecord(1);
// 	ASSERT_EQUAL(firstNode->GetTargetRecord(), 1);
// 
// 	firstNode->Update();
// 
// 	outTopLevel.Insert(firstNode);
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
// 	ClodMeshSharedPtr secondNode =
// 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<ClodMeshSharedPtr>();
// 
// 	ASSERT_EQUAL(firstNode->GetNumRecords(), secondNode->GetNumRecords());
// 	ASSERT_TRUE(0 < firstNode->GetNumRecords());
// 
// 	ASSERT_EQUAL(firstNode->GetTargetRecord(), secondNode->GetTargetRecord());
// 	ASSERT_EQUAL(firstNode->GetTargetRecord(), 1);
// 
// 	ASSERT_EQUAL(firstNode->GetAutomatedTargetRecord(), secondNode->GetAutomatedTargetRecord());
}


