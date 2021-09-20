// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.3 (2019/09/05 11:45)

#include "TrianglesStripTesting.h"
#include "VisualTest.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/TrianglesStrip.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/SaveVisual.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/SaveVisual.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"

#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/AVectorOrthonormalBasisDetail.h"
#include "Mathematics/Algebra/Vector2DDetail.h"

#include <random>
#include <vector>

using std::vector;
using CoreTools::WriteFileManager;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TrianglesStripTesting) 

void Rendering::TrianglesStripTesting
	::MainTest()
{
	CoreTools::InitTerm::ExecuteInitializers();

	CameraManager::Create();
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesStripFile);
	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FileTest);
	ASSERT_NOT_THROW_EXCEPTION_0(UpdateModelSpaceTest);
	
	RendererManager::Destroy();
	CameraManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::TrianglesStripTesting
	::CreateTrianglesStripFile() 
{
	WriteFileManager manage(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesStrip.trv"));

	std::default_random_engine generator;
	std::uniform_real<float>
		firstFloatRandomDistribution(-1.0f,1.0f);  	

	int type = System::EnumCastUnderlying(VisualPrimitiveType::TriangleStrip);
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

	VertexFormatSharedPtr firstVertexFormat =
		VertexFormat::Create(firstVertexFormatType);

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
	int indexBufferNumElements = 50;
	elementSize = 4;
	int numBytes = indexBufferNumElements * elementSize;

	manage.Write(sizeof(int), &indexBufferNumElements);
	manage.Write(sizeof(int), &elementSize);
	manage.Write(sizeof(int), &usage);
	manage.Write(sizeof(int), &numBytes);

    vector<char> buffer(numBytes);

	for (unsigned bufferIndex = 0;bufferIndex < buffer.size() / sizeof(float);
		 ++bufferIndex)
	{
		int* intBufferPtr = reinterpret_cast<int*>(&buffer[bufferIndex * sizeof(int)]);

		*intBufferPtr = bufferIndex % numElements;
	}
	
	manage.Write(elementSize, numBytes / elementSize, &buffer[0]);

	int offset = 0;

	manage.Write(sizeof(int),&offset);
}

void Rendering::TrianglesStripTesting
	::InitTest()
{
// 	VisualSharedPtr firstTrianglesStrip =
// 		LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesStrip.trv"));
// 	
// 	ASSERT_EQUAL(firstTrianglesStrip->GetNumControllers(),0);	
// 
// 	ControllerInterfaceSharedPtr controllerTest(new VisualTest);	
// 	firstTrianglesStrip->AttachController(controllerTest);
// 
// 	ASSERT_EQUAL(firstTrianglesStrip->GetNumControllers(),1);
// 	ASSERT_EQUAL(firstTrianglesStrip->GetController(0), controllerTest);
// 
// 	ControllerInterfaceSharedPtr secondVisualTest(new VisualTest);
// 
// 	ASSERT_EQUAL_NULL_PTR(secondVisualTest->GetControllerObject());
// 
// 	firstTrianglesStrip->AttachController(secondVisualTest);
// 
// 	VisualTest* ptr = CoreTools::StaticCast<VisualTest>(secondVisualTest.GetData());
// 
// 	ASSERT_EQUAL(secondVisualTest->GetControllerObject(),
// 	             firstTrianglesStrip);
// 	ASSERT_EQUAL_NULL_PTR(ptr->GetParent());
// 	
// 	ASSERT_EQUAL(firstTrianglesStrip->GetNumControllers(),2);
// 	ASSERT_EQUAL(firstTrianglesStrip->GetController(0), controllerTest);
// 	ASSERT_EQUAL(firstTrianglesStrip->GetController(1), secondVisualTest);
// 
// 	firstTrianglesStrip->DetachController(controllerTest);
// 
// 	ASSERT_EQUAL(firstTrianglesStrip->GetNumControllers(),1);
// 	ASSERT_EQUAL(firstTrianglesStrip->GetController(0), secondVisualTest);
// 
// 	firstTrianglesStrip->DetachAllControllers();
// 
// 	ASSERT_EQUAL(firstTrianglesStrip->GetNumControllers(),0);
// 
// 	// Visual测试
// 
// 	ASSERT_ENUM_EQUAL(firstTrianglesStrip->GetPrimitiveType(),VisualPrimitiveType::TriangleStrip);
// 
// 	ASSERT_FALSE(firstTrianglesStrip->GetConstVertexFormat().IsNullPtr());
// 	ASSERT_FALSE(firstTrianglesStrip->GetVertexFormat().IsNullPtr());
// 
// 	ASSERT_FALSE(firstTrianglesStrip->GetConstVertexBuffer().IsNullPtr());
// 	ASSERT_FALSE(firstTrianglesStrip->GetVertexBuffer().IsNullPtr());
// 
// 	ASSERT_FALSE(firstTrianglesStrip->GetConstIndexBuffer().IsNullPtr());
// 	ASSERT_FALSE(firstTrianglesStrip->GetIndexBuffer().IsNullPtr());
// 
// 	ASSERT_TRUE(firstTrianglesStrip->GetEffectInstance().IsNullPtr());		
// 
// 	// TrianglesStrip测试
// 	TrianglesStripSharedPtr secondTrianglesStrip = 
// 		firstTrianglesStrip.PolymorphicDowncastSharedPtr<TrianglesStripSharedPtr>();
// 	ASSERT_EQUAL(secondTrianglesStrip->GetNumTriangles(),
// 		         secondTrianglesStrip->GetConstIndexBuffer()->GetNumElements() - 2);
// 
// 	for (int index = 0; index < secondTrianglesStrip->GetVertexBuffer()->GetNumElements(); ++index)
// 	{
// 		VertexBufferAccessor vertexBufferAccessor(secondTrianglesStrip->GetConstVertexFormat(),
// 			                                      secondTrianglesStrip->GetConstVertexBuffer());
// 
// 		Mathematics::APointf point = vertexBufferAccessor.GetPosition<Mathematics::APointf>(index);
// 
// 		ASSERT_TRUE(-1.0f <= point[0] && point[0] <= 1.0f);
// 		ASSERT_TRUE(-1.0f <= point[1] && point[1] <= 1.0f);
// 		ASSERT_TRUE(-1.0f <= point[2] && point[2] <= 1.0f);
// 	}
// 
// 	for (int index = 0 ;index < secondTrianglesStrip->GetNumTriangles();++index)
// 	{
// 		TriangleIndex triangleIndex = secondTrianglesStrip->GetTriangle(index);
// 
// 		ASSERT_TRUE(0 <= triangleIndex.GetFirstIndex() && triangleIndex.GetFirstIndex() < 20);
// 		ASSERT_TRUE(0 <= triangleIndex.GetSecondIndex() && triangleIndex.GetSecondIndex() < 20);
// 		ASSERT_TRUE(0 <= triangleIndex.GetThirdIndex() && triangleIndex.GetThirdIndex() < 20);
// 
// 		TrianglePosition modelTriangle = secondTrianglesStrip->GetModelTriangle(index);
// 
// 		VertexBufferAccessor vertexBufferAccessor(secondTrianglesStrip->GetConstVertexFormat(), 
// 			                                      secondTrianglesStrip->GetConstVertexBuffer());	 
// 
// 		TrianglePosition testModelTriangle(vertexBufferAccessor.GetPosition<Mathematics::APointf>(triangleIndex.GetFirstIndex()),
// 			                               vertexBufferAccessor.GetPosition<Mathematics::APointf>(triangleIndex.GetSecondIndex()),
// 			                               vertexBufferAccessor.GetPosition<Mathematics::APointf>(triangleIndex.GetThirdIndex()));
// 
// 		ASSERT_TRUE(Approximate(modelTriangle.GetFirstPosition(),
// 			                    testModelTriangle.GetFirstPosition(),1e-8f));
// 
// 		ASSERT_TRUE(Approximate(modelTriangle.GetSecondPosition(),
// 			                    testModelTriangle.GetSecondPosition(),1e-8f));
// 
// 		ASSERT_TRUE(Approximate(modelTriangle.GetThirdPosition(),
// 			                    testModelTriangle.GetThirdPosition(),1e-8f));
// 
// 		TrianglePosition worldTriangle = secondTrianglesStrip->GetWorldTriangle(index);
// 
// 		Mathematics::APointf firstPosition = secondTrianglesStrip->GetWorldTransform() * modelTriangle.GetFirstPosition();
// 		Mathematics::APointf secondPosition = secondTrianglesStrip->GetWorldTransform() * modelTriangle.GetSecondPosition();
// 		Mathematics::APointf thirdPosition = secondTrianglesStrip->GetWorldTransform() * modelTriangle.GetThirdPosition();
// 
// 		ASSERT_TRUE(Approximate(firstPosition, worldTriangle.GetFirstPosition(), 1e-6f));
// 		ASSERT_TRUE(Approximate(secondPosition, worldTriangle.GetSecondPosition(), 1e-6f));
// 		ASSERT_TRUE(Approximate(thirdPosition, worldTriangle.GetThirdPosition(), 1e-6f));
// 	}
// 
// 	for (int index = 0; index < secondTrianglesStrip->GetVertexBuffer()->GetNumElements(); ++index)
// 	{
// 		Mathematics::Vector3Df secondTrianglesMeshPosition =  secondTrianglesStrip->GetPosition(index);
// 		
// 		int vertexIndex = secondTrianglesStrip->GetConstVertexFormat()->GetIndex(VertexFormatFlags::AttributeUsage::Position);
//  
// 		const char* positions = secondTrianglesStrip->GetConstVertexBuffer()->GetReadOnlyData() +
// 			                    secondTrianglesStrip->GetConstVertexFormat()->GetOffset(vertexIndex);
// 		int stride =  secondTrianglesStrip->GetConstVertexFormat()->GetStride();
// 		const float* firstPositionPtr = reinterpret_cast<const float*>(positions + index * stride);
// 		const float* secondPositionPtr = firstPositionPtr + sizeof(float);
// 		const float* thirdPositionPtr = secondPositionPtr + sizeof(float);
// 
// 		ASSERT_TRUE(Mathematics::Vector3DToolsf::Approximate(secondTrianglesMeshPosition,Mathematics::Vector3Df(*firstPositionPtr,*secondPositionPtr,*thirdPositionPtr),1e-6f)); 
// 	}
// 
// 	ASSERT_EQUAL(secondTrianglesStrip->GetNumVertices(),
// 		         secondTrianglesStrip->GetConstVertexBuffer()->GetNumElements()); 
// 
// 	VertexFormatSharedPtr secondVertexformat 
// 		= firstTrianglesStrip->GetConstVertexFormat()->Clone();
// 	VertexBufferSharedPtr secondVertexbuffer(new VertexBuffer);
// 	IndexBufferSharedPtr secondIndexbuffer(new IndexBuffer);
// 
// 	firstTrianglesStrip->SetVertexFormat(secondVertexformat);
// 	ASSERT_EQUAL(firstTrianglesStrip->GetConstVertexFormat(),secondVertexformat);
// 	ASSERT_EQUAL(firstTrianglesStrip->GetVertexFormat(),secondVertexformat);
// 
// 	firstTrianglesStrip->SetVertexBuffer(secondVertexbuffer);
// 	ASSERT_EQUAL(firstTrianglesStrip->GetConstVertexBuffer(),secondVertexbuffer);
// 	ASSERT_EQUAL(firstTrianglesStrip->GetVertexBuffer(),secondVertexbuffer);
// 
// 	firstTrianglesStrip->SetIndexBuffer(secondIndexbuffer);
// 	ASSERT_EQUAL(firstTrianglesStrip->GetConstIndexBuffer(),secondIndexbuffer);
// 	ASSERT_EQUAL(firstTrianglesStrip->GetIndexBuffer(),secondIndexbuffer);
// 
// 	ASSERT_TRUE(firstTrianglesStrip->GetEffectInstance().IsNullPtr());
}

void Rendering::TrianglesStripTesting
	::CopyTest()
{
// 	VisualSharedPtr firstTrianglesStrip =
// 		LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesStrip.trv"));
// 
// 	ASSERT_EQUAL(firstTrianglesStrip->GetNumControllers(), 0);
// 
// 	ControllerInterfaceSharedPtr controllerTest(new VisualTest);
// 
// 	ControllerInterfaceSharedPtr secondVisualTest(new VisualTest);
// 	VisualTest* firstPtr = CoreTools::StaticCast<VisualTest>(secondVisualTest.GetData());
// 
// 	ASSERT_EQUAL_NULL_PTR(secondVisualTest->GetControllerObject());
// 
// 	secondVisualTest->AttachController(controllerTest);
// 
// 	firstTrianglesStrip->AttachController(secondVisualTest);
// 
// 	Transform firstTransform;
// 
// 	firstTransform.SetUniformScale(5.0f);
// 	firstPtr->SetLocalTransform(firstTransform);
//  
//  	ControllerInterfaceSharedPtr thirdVisualTest(secondVisualTest->Clone());
// 	VisualTest* secondPtr = CoreTools::StaticCast<VisualTest>(thirdVisualTest.GetData());
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
// 	firstTrianglesStrip->AttachController(thirdVisualTest);
// 
// 	ASSERT_EQUAL(firstTrianglesStrip->GetNumControllers(), 2);
// 	ASSERT_EQUAL(firstTrianglesStrip->GetController(0), secondVisualTest);
// 	ASSERT_EQUAL(firstTrianglesStrip->GetController(1), thirdVisualTest);
// 
// 	secondVisualTest->DetachController(controllerTest);
// 
// 	thirdVisualTest->AttachController(controllerTest);
// 
// 	ASSERT_EQUAL(secondVisualTest->GetNumControllers(),0);
// 
// 	// thirdVisualTest已经复制了一个VisualTest
// 	ASSERT_EQUAL(thirdVisualTest->GetNumControllers(),2); 
// 	
// 	// Visual测试
// 	VisualSharedPtr secondTrianglesMesh = firstTrianglesStrip->Clone().PolymorphicDowncastObjectSharedPtr<VisualSharedPtr>();
// 
// 	ASSERT_UNEQUAL(secondTrianglesMesh->GetConstVertexFormat(), firstTrianglesStrip->GetConstVertexFormat());
// 	ASSERT_UNEQUAL(secondTrianglesMesh->GetVertexFormat(), firstTrianglesStrip->GetVertexFormat());
// 	ASSERT_UNEQUAL(secondTrianglesMesh->GetConstVertexBuffer(), firstTrianglesStrip->GetConstVertexBuffer());
// 	ASSERT_UNEQUAL(secondTrianglesMesh->GetVertexBuffer(), firstTrianglesStrip->GetVertexBuffer());
// 	ASSERT_UNEQUAL(secondTrianglesMesh->GetConstIndexBuffer(), firstTrianglesStrip->GetConstIndexBuffer());
// 	ASSERT_UNEQUAL(secondTrianglesMesh->GetIndexBuffer(), firstTrianglesStrip->GetIndexBuffer());
}

void Rendering::TrianglesStripTesting
	::TransformTest()
{
// 	VisualSharedPtr firstTrianglesStrip =
// 			LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesStrip.trv"));
// 
// 	ControllerInterfaceSharedPtr secondSpatialTest(new VisualTest);
// 	firstTrianglesStrip->AttachController(secondSpatialTest);
// 
// 	VisualTest* firstPtr = CoreTools::StaticCast<VisualTest>(secondSpatialTest.GetData());
// 
// 	Transform firstTransform;
// 	firstTransform.SetUniformScale(5.0f);
// 
// 	Transform secondTransform;
// 	secondTransform.SetTranslate(Transform::APoint(5.0f,3.0f,5.6f));
// 
// 	firstTrianglesStrip->SetLocalTransform(firstTransform);
// 	firstPtr->SetLocalTransform(secondTransform);
// 	firstPtr->SetParent(firstTrianglesStrip.GetData());
// 
// 	firstTrianglesStrip->Update();
// 
// 	ASSERT_TRUE(Approximate(firstTrianglesStrip->GetLocalTransform(),
// 	                        firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(firstPtr->GetLocalTransform(),
// 	                        secondTransform,1e-8f));
// 
// 	ASSERT_TRUE(Approximate(firstTrianglesStrip->GetWorldTransform(),
// 	                        firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(firstPtr->GetWorldTransform(),
// 	                        firstTransform * secondTransform,1e-8f));
// 
// 	// Visual测试
// 	int numVertices = firstTrianglesStrip->GetConstVertexBuffer()->GetNumElements();
// 	int stride = firstTrianglesStrip->GetConstVertexFormat()->GetStride();
// 
// 	int positionIndex = firstTrianglesStrip->GetConstVertexFormat()->GetIndex(VertexFormatFlags::AttributeUsage::Position);
// 
// 	const char* data = firstTrianglesStrip->GetConstVertexBuffer()->GetReadOnlyData();
// 	int positionOffset = firstTrianglesStrip->GetConstVertexFormat()->GetOffset(positionIndex);
// 
// 	Bound modelBound;
// 	modelBound.ComputeFromData(numVertices, stride, data + positionOffset);
// 
// 	Bound worldBound = modelBound.TransformBy(firstTrianglesStrip->GetWorldTransform());  
// 
// 	ASSERT_TRUE(Approximate(firstTrianglesStrip->GetModelBound(),
// 	                        modelBound,1e-8f)); 
// 
// 	ASSERT_TRUE(Approximate(firstTrianglesStrip->GetWorldBound(),
// 	                        worldBound,1e-8f)); 
  }

void Rendering::TrianglesStripTesting
	::StreamTest()
{
// 	VisualSharedPtr firstTrianglesStrip =
// 			LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesStrip.trv"));
//  
// 	CoreTools::OutTopLevel outTopLevel;
//  
// 	firstTrianglesStrip->SetUniqueID(5);
// 
// 	outTopLevel.Insert(firstTrianglesStrip.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
// 
// 	Transform firstTransform;
// 	Transform secondTransform;
// 	Bound firstBound(Bound::APoint(0.2f,5.0f,3.0f),2.0f);	
// 
// 	firstTransform.SetUniformScale(5.0f);
// 	secondTransform.SetUniformScale(3.0f);
// 
// 	firstTrianglesStrip->SetLocalTransform(firstTransform);
// 	firstTrianglesStrip->SetWorldTransform(secondTransform);
// 	firstTrianglesStrip->SetWorldBound(firstBound);
// 	firstTrianglesStrip->SetCullingMode(CullingMode::Always);
// 
// 	ControllerInterfaceSharedPtr thirdVisualTest(new VisualTest);
// 	firstTrianglesStrip->AttachController(thirdVisualTest);
// 
// 	thirdVisualTest->SetUniqueID(4);
// 
// 	ControllerInterfaceSharedPtr fourthVisualTest(new VisualTest);
// 	firstTrianglesStrip->AttachController(fourthVisualTest);
// 
// 	fourthVisualTest->SetUniqueID(3);
// 
// 	ControllerInterfaceSharedPtr fifthVisualTest(new VisualTest);
// 	firstTrianglesStrip->AttachController(fifthVisualTest);
// 
// 	fifthVisualTest->SetUniqueID(2);
// 
// 	ControllerInterfaceSharedPtr sixthVisualTest(new VisualTest);
// 	fifthVisualTest->AttachController(sixthVisualTest);
// 
// 	sixthVisualTest->SetUniqueID(1);
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =
// 		    outStream.GetBufferOutStreamInformation();
//         
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
//         
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	TrianglesStripSharedPtr  secondTrianglesStrip =
// 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<TrianglesStripSharedPtr>();
// 
// 	ASSERT_EQUAL(secondTrianglesStrip->GetNumControllers(), 3);
// 
// 	ASSERT_TRUE(Approximate(secondTrianglesStrip->GetLocalTransform(),
// 	                        firstTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(secondTrianglesStrip->GetWorldTransform(),
// 	                        secondTransform,1e-8f));
// 	ASSERT_TRUE(Approximate(secondTrianglesStrip->GetWorldBound(), firstBound, 1e-8f));
// 	ASSERT_ENUM_EQUAL(secondTrianglesStrip->GetCullingMode(), CullingMode::Always);
// 
// 	VisualTest* eighthVisualTest =
// 		CoreTools::DynamicCast<VisualTest>(secondTrianglesStrip->GetController(0).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(eighthVisualTest);
// 
// 	VisualTest* ninthVisualTest =
// 		CoreTools::DynamicCast<VisualTest>(secondTrianglesStrip->GetController(1).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(ninthVisualTest);
// 
// 	VisualTest* tenthVisualTest =
// 		CoreTools::DynamicCast<VisualTest>
// 		(secondTrianglesStrip->GetController(2).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(tenthVisualTest);
// 
// 	ASSERT_EQUAL(tenthVisualTest->GetNumControllers(), 1);
// 
// 	VisualTest* eleventhVisualTest =
// 		CoreTools::DynamicCast<VisualTest>
// 		(tenthVisualTest->GetController(0).GetData());
// 
// 	ASSERT_UNEQUAL_NULL_PTR(eleventhVisualTest);
// 
// 	// Visual测试
// 	ASSERT_ENUM_EQUAL(firstTrianglesStrip->GetPrimitiveType(), secondTrianglesStrip->GetPrimitiveType());
// 
// 	VertexBufferSharedPtr firstBuffer = firstTrianglesStrip->GetVertexBuffer();
// 	VertexBufferSharedPtr secondBuffer = secondTrianglesStrip->GetVertexBuffer();
// 
// 	IndexBufferSharedPtr thirdBuffer = firstTrianglesStrip->GetIndexBuffer();
// 	IndexBufferSharedPtr fourthBuffer = secondTrianglesStrip->GetIndexBuffer();
// 
// 	ASSERT_EQUAL(firstBuffer->GetNumElements(), secondBuffer->GetNumElements());
// 	ASSERT_EQUAL(firstBuffer->GetElementSize(), secondBuffer->GetElementSize());
// 	ASSERT_ENUM_EQUAL(firstBuffer->GetUsage(), secondBuffer->GetUsage());
// 	ASSERT_EQUAL(firstBuffer->GetNumBytes(), secondBuffer->GetNumBytes());
// 
// 	ASSERT_EQUAL(thirdBuffer->GetNumElements(), fourthBuffer->GetNumElements());
// 	ASSERT_EQUAL(thirdBuffer->GetElementSize(), fourthBuffer->GetElementSize());
// 	ASSERT_ENUM_EQUAL(thirdBuffer->GetUsage(), fourthBuffer->GetUsage());
// 	ASSERT_EQUAL(thirdBuffer->GetNumBytes(), fourthBuffer->GetNumBytes());
// 	ASSERT_EQUAL(thirdBuffer->GetOffset(), fourthBuffer->GetOffset());
// 
// 	for (int i = 0; i < firstBuffer->GetNumElements() * firstBuffer->GetElementSize(); ++i)
// 	{
// 		ASSERT_EQUAL(firstBuffer->GetReadOnlyData()[i], secondBuffer->GetReadOnlyData()[i]);
// 	}
// 
// 	for (int i = 0; i < thirdBuffer->GetNumElements() * thirdBuffer->GetElementSize(); ++i)
// 	{
// 		ASSERT_EQUAL(thirdBuffer->GetReadOnlyData()[i], fourthBuffer->GetReadOnlyData()[i]);
// 	}
// 
// 	VertexFormatSharedPtr firstVertexFormat = firstTrianglesStrip->GetVertexFormat();
// 	VertexFormatSharedPtr secondVertexFormat = secondTrianglesStrip->GetVertexFormat();
// 
// 	ASSERT_EQUAL(firstVertexFormat->GetNumAttributes(),
// 		         secondVertexFormat->GetNumAttributes()); 
// 
// 	for (int i = 0; i < firstVertexFormat->GetNumAttributes(); ++i)
// 	{
// 		ASSERT_EQUAL(firstVertexFormat->GetStreamIndex(i), secondVertexFormat->GetStreamIndex(i));
// 		ASSERT_EQUAL(firstVertexFormat->GetOffset(i), secondVertexFormat->GetOffset(i));
// 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeType(i),
// 			         secondVertexFormat->GetAttributeType(i));
// 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeUsage(i),
// 			         secondVertexFormat->GetAttributeUsage(i));
// 		ASSERT_EQUAL(firstVertexFormat->GetUsageIndex(i),
// 			         secondVertexFormat->GetUsageIndex(i));
// 	}
// 
// 	ASSERT_EQUAL(firstVertexFormat->GetStride(), secondVertexFormat->GetStride()); 

}

void Rendering::TrianglesStripTesting
	::FileTest()
{
// 	VisualSharedPtr firstTrianglesStrip =
// 			LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesStrip.trv"));
// 
// 	
// 	SaveVisual::SaveToFile(*firstTrianglesStrip, SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesStripSave.trv"));
// 
// 	LoadVisual secondLoadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesStripSave.trv"));
// 
// 	VisualTest secondVisualTest(secondLoadVisual.GetPrimitiveType(),
// 		                        secondLoadVisual.GetVertexFormat(),
// 								secondLoadVisual.GetVertexBuffer(),
// 								secondLoadVisual.GetIndexBuffer());
// 
// 	ASSERT_ENUM_EQUAL(firstTrianglesStrip->GetPrimitiveType(), secondLoadVisual.GetPrimitiveType());
// 
// 	VertexBufferSharedPtr firstBuffer = firstTrianglesStrip->GetVertexBuffer();
// 	VertexBufferSharedPtr secondBuffer = secondLoadVisual.GetVertexBuffer();
// 
// 	IndexBufferSharedPtr thirdBuffer = firstTrianglesStrip->GetIndexBuffer();
// 	IndexBufferSharedPtr fourthBuffer = secondLoadVisual.GetIndexBuffer();
// 
// 	ASSERT_EQUAL(firstBuffer->GetNumElements(), secondBuffer->GetNumElements());
// 	ASSERT_EQUAL(firstBuffer->GetElementSize(), secondBuffer->GetElementSize());
// 	ASSERT_ENUM_EQUAL(firstBuffer->GetUsage(), secondBuffer->GetUsage());
// 	ASSERT_EQUAL(firstBuffer->GetNumBytes(), secondBuffer->GetNumBytes());
// 
// 	ASSERT_EQUAL(thirdBuffer->GetNumElements(), fourthBuffer->GetNumElements());
// 	ASSERT_EQUAL(thirdBuffer->GetElementSize(), fourthBuffer->GetElementSize());
// 	ASSERT_ENUM_EQUAL(thirdBuffer->GetUsage(), fourthBuffer->GetUsage());
// 	ASSERT_EQUAL(thirdBuffer->GetNumBytes(), fourthBuffer->GetNumBytes());
// 	ASSERT_EQUAL(thirdBuffer->GetOffset(), fourthBuffer->GetOffset());
// 
// 	for (int i = 0; i < firstBuffer->GetNumElements() * firstBuffer->GetElementSize(); ++i)
// 	{
// 		ASSERT_EQUAL(firstBuffer->GetReadOnlyData()[i], secondBuffer->GetReadOnlyData()[i]);
// 	}
// 
// 	for (int i = 0; i < thirdBuffer->GetNumElements() * thirdBuffer->GetElementSize(); ++i)
// 	{
// 		ASSERT_EQUAL(thirdBuffer->GetReadOnlyData()[i], fourthBuffer->GetReadOnlyData()[i]);
// 	}
// 
// 	VertexFormatSharedPtr firstVertexFormat = firstTrianglesStrip->GetVertexFormat();
// 	VertexFormatSharedPtr secondVertexFormat = secondLoadVisual.GetVertexFormat();
// 
// 	ASSERT_EQUAL(firstVertexFormat->GetNumAttributes(),
// 		         secondVertexFormat->GetNumAttributes()); 
// 
// 	for (int i = 0; i < firstVertexFormat->GetNumAttributes(); ++i)
// 	{
// 		ASSERT_EQUAL(firstVertexFormat->GetStreamIndex(i), secondVertexFormat->GetStreamIndex(i));
// 		ASSERT_EQUAL(firstVertexFormat->GetOffset(i), secondVertexFormat->GetOffset(i));
// 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeType(i),
// 			         secondVertexFormat->GetAttributeType(i));
// 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeUsage(i),
// 			         secondVertexFormat->GetAttributeUsage(i));
// 		ASSERT_EQUAL(firstVertexFormat->GetUsageIndex(i),
// 			         secondVertexFormat->GetUsageIndex(i));
// 	}
// 
// 	ASSERT_EQUAL(firstVertexFormat->GetStride(), secondVertexFormat->GetStride());
}

void Rendering::TrianglesStripTesting
	::UpdateModelSpaceTest() 
{
// 	VisualSharedPtr firstTrianglesStrip =
// 		LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesStrip.trv"));
// 
// 	TrianglesStripSharedPtr secondTrianglesStrip =
// 		firstTrianglesStrip.PolymorphicDowncastObjectSharedPtr<TrianglesStripSharedPtr>();
// 
// 	firstTrianglesStrip->UpdateModelSpace(VisualUpdateType::Normals);
// 
// 	VertexBufferAccessor vertexBufferAccessor(firstTrianglesStrip.GetData());
// 	ASSERT_TRUE(vertexBufferAccessor.HasNormal());	
// 		
// 	const int numVertices = secondTrianglesStrip->GetNumVertices();
// 	for (int index = 0; index < numVertices; ++index)
// 	{		
// 		Mathematics::AVectorf normal = 
// 			vertexBufferAccessor.GetNormal<Mathematics::AVectorf>(index);
// 		
// 		ASSERT_TRUE(normal.IsNormalize());
// 	}	
// 	
// 	firstTrianglesStrip->UpdateModelSpace(VisualUpdateType::UseGeometry);
// 
// 	ASSERT_TRUE(vertexBufferAccessor.HasBinormal());
// 	ASSERT_TRUE(vertexBufferAccessor.HasTangent());
// 
// 	vector<Mathematics::AVectorf> tangentVector(numVertices);
// 	vector<Mathematics::AVectorf> binormalVector(numVertices);
// 	vector<Mathematics::Matrixf> derivativestNormal(numVertices);
// 	vector<Mathematics::Matrixf> projectMatrix(numVertices);
// 	vector<Mathematics::Matrixf> differentMatrix(numVertices); 
// 
// 	const int numTriangles = secondTrianglesStrip->GetNumTriangles();
// 
// 	for (int index = 0; index < numTriangles; ++index)
// 	{
// 		// 获取三角形的顶点索引。
// 		TriangleIndex triangleIndex = secondTrianglesStrip->GetTriangle(index);
// 
// 		for (int i = 0; i < 3;++i)
// 		{
// 			int firstIndex = triangleIndex[i];
// 			int secondIndex = triangleIndex[(i + 1) % 3];
// 			int thirdIndex = triangleIndex[(i + 2) % 3];
// 
// 			Mathematics::APointf position0 = vertexBufferAccessor.GetPosition<Mathematics::APointf>(firstIndex);
// 			Mathematics::APointf position1 = vertexBufferAccessor.GetPosition<Mathematics::APointf>(secondIndex);
// 			Mathematics::APointf position2 = vertexBufferAccessor.GetPosition<Mathematics::APointf>(thirdIndex);
// 
// 			Mathematics::AVectorf normal0 = vertexBufferAccessor.GetNormal<Mathematics::AVectorf>(firstIndex);
// 			Mathematics::AVectorf normal1 = vertexBufferAccessor.GetNormal<Mathematics::AVectorf>(secondIndex);
// 			Mathematics::AVectorf normal2 = vertexBufferAccessor.GetNormal<Mathematics::AVectorf>(thirdIndex);
// 
// 			// 计算pos0到pos1的边，投射顶点的切平面,并计算相邻法线的差。
// 			Mathematics::AVectorf edge = position1 - position0;
// 			Mathematics::AVectorf project = edge - Dot(edge, normal0) * normal0;
// 			Mathematics::AVectorf difference = normal1 - normal0;
// 			for (int row = 0; row < 3; ++row)
// 			{
// 				for (int col = 0; col < 3; ++col)
// 				{
// 					projectMatrix[firstIndex](row, col) += project[row] * project[col];
// 					differentMatrix[firstIndex](row, col) += difference[row] * project[col];
// 				}
// 			}
// 
// 			// 计算pos0到pos2的边，投射顶点的切平面,并计算相邻法线的差。
// 			edge = position2 - position0;
// 			project = edge - Dot(edge, normal0) * normal0;
// 			difference = normal2 - normal0;
// 			for (int row = 0; row < 3; ++row)
// 			{
// 				for (int col = 0; col < 3; ++col)
// 				{
// 					projectMatrix[firstIndex](row, col) += project[row] * project[col];
// 					differentMatrix[firstIndex](row, col) += difference[row] * project[col];
// 				}
// 			}
// 		}		 
// 	}
// 
// 	for (int index = 0; index < numVertices; ++index)
// 	{
// 		Mathematics::AVectorf  normal = vertexBufferAccessor.GetNormal<Mathematics::AVectorf>(index);
// 		for (int row = 0; row < 3; ++row)
// 		{
// 			for (int col = 0; col < 3; ++col)
// 			{
// 				projectMatrix[index](row, col) += 0.5f * projectMatrix[index](row, col) + normal[row] * normal[col];
// 				differentMatrix[index](row, col) *= 0.5f;
// 			}
// 		}
// 		
// 		projectMatrix[index].SetColumn(3, Mathematics::APointf::sm_Origin.GetHomogeneousPoint());
// 		derivativestNormal[index] = differentMatrix[index] * projectMatrix[index].Inverse();
// 	}
// 
// 	for (int index = 0; index < numVertices; ++index)
// 	{
// 		// 通过N计算 U 和 V。
// 		Mathematics::AVectorf normal = vertexBufferAccessor.GetNormal<Mathematics::AVectorf>(index);
// 		const Mathematics::AVectorOrthonormalBasisf aVectorOrthonormalBasis =
// 			GenerateComplementBasis(normal);
// 
// 		Mathematics::AVectorf uNormal = aVectorOrthonormalBasis.GetUVector();
// 		Mathematics::AVectorf vNormal = aVectorOrthonormalBasis.GetVVector();
// 		Mathematics::AVectorf wNormal = aVectorOrthonormalBasis.GetWVector();
// 
// 		// 计算S = J^T * dN / dX * J .
// 		// 理论上S是对称的,但因为我们估算dN/dX，
// 		// 我们必须稍微调整我们的计算,以确保S是对称的。
// 		float symmetric01 = Dot(uNormal, derivativestNormal[index] * vNormal);
// 		float symmetric10 = Dot(vNormal, derivativestNormal[index] * uNormal);
// 		float symmetricAverage = 0.5f * (symmetric01 + symmetric10);
// 		float symmetricMat[2][2] =
// 		{
// 			{ Dot(uNormal, derivativestNormal[index] * uNormal), symmetricAverage },
// 			{ symmetricAverage, Dot(vNormal, derivativestNormal[index] * vNormal) }
// 		};
// 
// 		// 计算S的特征值(最小和最大曲率)。
// 		float trace = symmetricMat[0][0] + symmetricMat[1][1];
// 		float det = symmetricMat[0][0] * symmetricMat[1][1] - symmetricMat[0][1] * symmetricMat[1][0];
// 		float discr = trace * trace - 4.0f * det;
// 		float rootDiscr = Mathematics::FloatMath::Sqrt(Mathematics::FloatMath::FAbs(discr));
// 		float minCurvature = 0.5f * (trace - rootDiscr);
// 		// float maxCurvature = 0.5f * (trace + rootDiscr);
// 
// 		// 计算S的特征向量.
// 		Mathematics::AVectorf evec0(symmetricMat[0][1], minCurvature - symmetricMat[0][0], 0.0f);
// 		Mathematics::AVectorf evec1(minCurvature - symmetricMat[1][1], symmetricMat[1][0], 0.0f);
// 		Mathematics::AVectorf tanvec, binvec;
// 		if (evec0.SquaredLength() >= evec1.SquaredLength())
// 		{
// 			evec0.Normalize();
// 			tanvec = evec0[0] * uNormal + evec0[1] * vNormal;
// 			binvec = Cross(wNormal, tanvec);
// 		}
// 		else
// 		{
// 			evec1.Normalize();
// 			tanvec = evec1[0] * uNormal + evec1[1] * vNormal;
// 			binvec = Cross(wNormal, tanvec);
// 		}
// 
// 		tangentVector[index] = tanvec;
// 		binormalVector[index] = binvec;
// 	}
// 
// 	for (int index = 0; index < numVertices; ++index)
// 	{	 
// 		Mathematics::AVectorf tangent = 
// 			vertexBufferAccessor.GetTangent<Mathematics::AVectorf>(index);
// 
// 		ASSERT_TRUE(Approximate(tangent, tangentVector[index], 1e-8f));
// 		
// 		Mathematics::AVectorf binormal = 
// 			vertexBufferAccessor.GetBinormal<Mathematics::AVectorf>(index);
// 
// 		ASSERT_TRUE(Approximate(binormal, binormalVector[index], 1e-8f));
// 	}
// 	
// 	firstTrianglesStrip->UpdateModelSpace(VisualUpdateType::UseTextureCoordChannel);
// 	
// 	for (int index = 0; index < numTriangles; ++index)
// 	{	 
// 		TriangleIndex triangleIndex = secondTrianglesStrip->GetTriangle(index);
// 
// 		vector<Mathematics::APointf> localPosition(3);
// 		vector<Mathematics::AVectorf> localNormal(3);
// 		vector<Mathematics::AVectorf> localTangent(3);
// 		vector<Mathematics::Vector2Df> localTextureCoord(3);
// 
// 		for (int current = 0; current < 3; ++current)
// 		{
// 			int currentTriangleIndex = triangleIndex[current];
// 			localPosition[current] = vertexBufferAccessor.GetPosition<Mathematics::APointf>(currentTriangleIndex);
// 			localNormal[current] = vertexBufferAccessor.GetNormal<Mathematics::AVectorf>(currentTriangleIndex);
// 			localTangent[current] = vertexBufferAccessor.GetTangent<Mathematics::AVectorf>(currentTriangleIndex);
// 			localTextureCoord[current] = vertexBufferAccessor.GetTextureCoord<Mathematics::Vector2Df>(0, currentTriangleIndex);
// 		}
// 
// 		for (int current = 0; current < 3; ++current)
// 		{
// 			Mathematics::AVectorf  currLocTangent = localTangent[current];
// 			if (!Approximate(currLocTangent, Mathematics::AVectorf::sm_Zero))
// 			{ 
// 				continue;
// 			}
// 
// 			Mathematics::AVectorf normalVector = localNormal[current];
// 			int prev = ((current + 2) % 3);
// 			int next = ((current + 1) % 3);
// 
// 			Mathematics::AVectorf tangentVector2;
// 
// 			Mathematics::AVectorf  differenceP1P0 = localPosition[next] - localPosition[current];
// 			Mathematics::AVectorf  differenceP2P0 = localPosition[prev] - localPosition[current];
// 
// 			if (Mathematics::FloatMath::FAbs(differenceP1P0.Length()) <
// 				Mathematics::FloatMath::sm_ZeroTolerance ||
// 				Mathematics::FloatMath::FAbs(differenceP2P0.Length()) <
// 				Mathematics::FloatMath::sm_ZeroTolerance)
// 			{				 
// 				tangentVector2 = Mathematics::AVectorf::sm_Zero;
// 			}
// 			else
// 			{
// 				float differenceU1U0 = localTextureCoord[next][0] - localTextureCoord[current][0];
// 				float differenceV1V0 = localTextureCoord[next][1] - localTextureCoord[current][1];
// 				if (Mathematics::FloatMath::FAbs(differenceV1V0) <
// 					Mathematics::FloatMath::sm_ZeroTolerance)
// 				{
// 					if (Mathematics::FloatMath::FAbs(differenceU1U0) <
// 						Mathematics::FloatMath::sm_ZeroTolerance)
// 					{
// 						tangentVector2 = Mathematics::AVectorf::sm_Zero;
// 					}
// 					else
// 					{
// 						tangentVector2 = differenceP1P0 / differenceU1U0;
// 					}
// 				}
// 				else
// 				{
// 					float differenceU2U0 = localTextureCoord[prev][0] - localTextureCoord[current][0];
// 					float differenceV2V0 = localTextureCoord[prev][1] - localTextureCoord[current][1];
// 					float det = differenceV1V0 * differenceU2U0 - differenceV2V0 * differenceU1U0;
// 					if (Mathematics::FloatMath::FAbs(det) <
// 						Mathematics::FloatMath::sm_ZeroTolerance)
// 					{
// 						 tangentVector2 = Mathematics::AVectorf::sm_Zero;
// 					}
// 					else
// 					{
// 						tangentVector2 = (differenceV1V0 * differenceP2P0 - differenceV2V0 * differenceP1P0) / det;
// 					}
// 				}
// 			}				
// 
// 			tangentVector2 -= Dot(normalVector, tangentVector2) * normalVector;
// 			tangentVector2.Normalize();
// 
// 			Mathematics::AVectorf bitangentVector = UnitCross(normalVector, tangentVector2);
// 
// 			int currentTriangleIndex = triangleIndex[current];
// 			if (vertexBufferAccessor.HasTangent())
// 			{
// 				localTangent[current] = tangentVector2;
// 
// 				Mathematics::AVectorf tangent =
// 					vertexBufferAccessor.GetBinormal<Mathematics::AVectorf>(currentTriangleIndex);
// 
// 				ASSERT_TRUE(Approximate(tangent, bitangentVector, 1e-8f));
// 			}
// 				
// 		}
// 	}
}

 