// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.3 (2019/09/05 11:45)

#include "TrianglesMeshTesting.h"
#include "VisualTest.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/SaveVisual.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorOrthonormalBasisDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

#include <random>
#include <vector>

using CoreTools::WriteFileManager;
using std::vector;
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26429)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TrianglesMeshTesting)

void Rendering::TrianglesMeshTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    CameraManager::Create();
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesMeshFile);
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

void Rendering::TrianglesMeshTesting::CreateTrianglesMeshFile()
{
    WriteFileManager manage(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMesh.trv"));

    std::default_random_engine generator;
    std::uniform_real<float> firstFloatRandomDistribution(-1.0f, 1.0f);

    constexpr int type = System::EnumCastUnderlying(VisualPrimitiveType::TriangleMesh);
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
                         VertexFormatFlags::AttributeUsage::TextureCoord, 0)
    };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    firstVertexFormat->SaveToFile(manage);

    // VertexBuffer
    int numElements = 20;
    int elementSize = firstVertexFormat->GetStride();
    constexpr int usage = System::EnumCastUnderlying(BufferUsage::Static);

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

            for (unsigned bufferIndex = 0; bufferIndex < buffer.size() / sizeof(float);
                 ++bufferIndex)
            {
                float* floatBufferPtr = reinterpret_cast<float*>(&buffer[bufferIndex * sizeof(float)]);

                *floatBufferPtr = firstFloatRandomDistribution(generator);
            }

            manage.Write(componentSize, numComponents, &buffer[0]);
        }

        vertexIndex += elementSize;
    }

    // IndexBuffer
    int indexBufferNumElements = 105;
    elementSize = 4;
    int numBytes = indexBufferNumElements * elementSize;

    manage.Write(sizeof(int), &indexBufferNumElements);
    manage.Write(sizeof(int), &elementSize);
    manage.Write(sizeof(int), &usage);
    manage.Write(sizeof(int), &numBytes);

    vector<char> buffer(numBytes);

    for (unsigned bufferIndex = 0; bufferIndex < buffer.size() / sizeof(float);
         ++bufferIndex)
    {
        int* intBufferPtr = reinterpret_cast<int*>(&buffer[bufferIndex * sizeof(int)]);

        *intBufferPtr = bufferIndex % numElements;
    }

    manage.Write(elementSize, numBytes / elementSize, &buffer[0]);

    int offset = 0;

    manage.Write(sizeof(int), &offset);
}

void Rendering::TrianglesMeshTesting::InitTest()
{
    // 	VisualSharedPtr firstTrianglesMesh =
    // 		LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMesh.trv"));
    //
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetNumControllers(),0);
    //
    // 	ControllerInterfaceSharedPtr controllerTest(new VisualTest);
    // 	firstTrianglesMesh->AttachController(controllerTest);
    //
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetNumControllers(),1);
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetController(0), controllerTest);
    //
    // 	ControllerInterfaceSharedPtr secondVisualTest(new VisualTest);
    //
    // 	ASSERT_EQUAL_NULL_PTR(secondVisualTest->GetControllerObject());
    //
    // 	firstTrianglesMesh->AttachController(secondVisualTest);
    //
    // 	VisualTest* ptr = CoreTools::StaticCast<VisualTest>(secondVisualTest.GetData());
    //
    // 	ASSERT_EQUAL(secondVisualTest->GetControllerObject(),
    // 	             firstTrianglesMesh);
    // 	ASSERT_EQUAL_NULL_PTR(ptr->GetParent());
    //
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetNumControllers(),2);
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetController(0), controllerTest);
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetController(1), secondVisualTest);
    //
    // 	firstTrianglesMesh->DetachController(controllerTest);
    //
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetNumControllers(),1);
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetController(0), secondVisualTest);
    //
    // 	firstTrianglesMesh->DetachAllControllers();
    //
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetNumControllers(),0);
    //
    // 	// Visual����
    //
    // 	ASSERT_ENUM_EQUAL(firstTrianglesMesh->GetPrimitiveType(),VisualPrimitiveType::TriangleMesh);
    //
    // 	ASSERT_FALSE(firstTrianglesMesh->GetConstVertexFormat().IsNullPtr());
    // 	ASSERT_FALSE(firstTrianglesMesh->GetVertexFormat().IsNullPtr());
    //
    // 	ASSERT_FALSE(firstTrianglesMesh->GetConstVertexBuffer().IsNullPtr());
    // 	ASSERT_FALSE(firstTrianglesMesh->GetVertexBuffer().IsNullPtr());
    //
    // 	ASSERT_FALSE(firstTrianglesMesh->GetConstIndexBuffer().IsNullPtr());
    // 	ASSERT_FALSE(firstTrianglesMesh->GetIndexBuffer().IsNullPtr());
    //
    // 	ASSERT_TRUE(firstTrianglesMesh->GetEffectInstance().IsNullPtr());
    //
    // 	// TrianglesMesh����
    // 	TrianglesMeshSharedPtr secondTrianglesMesh =
    // 		firstTrianglesMesh.PolymorphicDowncastSharedPtr<TrianglesMeshSharedPtr>();
    // 	ASSERT_EQUAL(secondTrianglesMesh->GetNumTriangles(),
    // 		         secondTrianglesMesh->GetConstIndexBuffer()->GetNumElements() / 3);
    //
    // 	for (int index = 0; index < secondTrianglesMesh->GetVertexBuffer()->GetNumElements(); ++index)
    // 	{
    // 		VertexBufferAccessor vertexBufferAccessor(secondTrianglesMesh->GetConstVertexFormat(),
    // 			                                      secondTrianglesMesh->GetConstVertexBuffer());
    //
    // 		Mathematics::APointf point = vertexBufferAccessor.GetPosition<Mathematics::APointf>(index);
    //
    // 		ASSERT_TRUE(-1.0f <= point[0] && point[0] <= 1.0f);
    // 		ASSERT_TRUE(-1.0f <= point[1] && point[1] <= 1.0f);
    // 		ASSERT_TRUE(-1.0f <= point[2] && point[2] <= 1.0f);
    // 	}
    //
    // 	for (int index = 0; index < secondTrianglesMesh->GetNumTriangles(); ++index)
    // 	{
    // 		TriangleIndex triangleIndex = secondTrianglesMesh->GetTriangle(index);
    //
    // 		ASSERT_TRUE(0 <= triangleIndex.GetFirstIndex() && triangleIndex.GetFirstIndex() < 20);
    // 		ASSERT_TRUE(0 <= triangleIndex.GetSecondIndex() && triangleIndex.GetSecondIndex() < 20);
    // 		ASSERT_TRUE(0 <= triangleIndex.GetThirdIndex() && triangleIndex.GetThirdIndex() < 20);
    //
    // 		TrianglePosition modelTriangle = secondTrianglesMesh->GetModelTriangle(index);
    //
    // 		VertexBufferAccessor vertexBufferAccessor(secondTrianglesMesh->GetConstVertexFormat(),
    // 			secondTrianglesMesh->GetConstVertexBuffer());
    //
    // 		TrianglePosition testModelTriangle(vertexBufferAccessor.GetPosition<Mathematics::APointf>(triangleIndex.GetFirstIndex()),
    // 			vertexBufferAccessor.GetPosition<Mathematics::APointf>(triangleIndex.GetSecondIndex()),
    // 			vertexBufferAccessor.GetPosition<Mathematics::APointf>(triangleIndex.GetThirdIndex()));
    //
    // 		ASSERT_TRUE(Approximate(modelTriangle.GetFirstPosition(),
    // 			testModelTriangle.GetFirstPosition(), 1e-8f));
    //
    // 		ASSERT_TRUE(Approximate(modelTriangle.GetSecondPosition(),
    // 			testModelTriangle.GetSecondPosition(), 1e-8f));
    //
    // 		ASSERT_TRUE(Approximate(modelTriangle.GetThirdPosition(),
    // 			testModelTriangle.GetThirdPosition(), 1e-8f));
    //
    // 		TrianglePosition worldTriangle = secondTrianglesMesh->GetWorldTriangle(index);
    //
    // 		Mathematics::APointf firstPosition = secondTrianglesMesh->GetWorldTransform() * modelTriangle.GetFirstPosition();
    // 		Mathematics::APointf secondPosition = secondTrianglesMesh->GetWorldTransform() * modelTriangle.GetSecondPosition();
    // 		Mathematics::APointf thirdPosition = secondTrianglesMesh->GetWorldTransform() * modelTriangle.GetThirdPosition();
    //
    // 		ASSERT_TRUE(Approximate(firstPosition, worldTriangle.GetFirstPosition(), 1e-6f));
    // 		ASSERT_TRUE(Approximate(secondPosition, worldTriangle.GetSecondPosition(), 1e-6f));
    // 		ASSERT_TRUE(Approximate(thirdPosition, worldTriangle.GetThirdPosition(), 1e-6f));
    //
    // 	}
    //
    // 	for (int index = 0; index < secondTrianglesMesh->GetVertexBuffer()->GetNumElements(); ++index)
    // 	{
    // 		Mathematics::Vector3Df secondTrianglesMeshPosition =  secondTrianglesMesh->GetPosition(index);
    //
    // 		int vertexIndex = secondTrianglesMesh->GetConstVertexFormat()->GetIndex(VertexFormatFlags::AttributeUsage::Position);
    //
    // 		const char* positions = secondTrianglesMesh->GetConstVertexBuffer()->GetReadOnlyData() +
    // 			                    secondTrianglesMesh->GetConstVertexFormat()->GetOffset(vertexIndex);
    // 		int stride =  secondTrianglesMesh->GetConstVertexFormat()->GetStride();
    // 		const float* firstPositionPtr = reinterpret_cast<const float*>(positions + index * stride);
    // 		const float* secondPositionPtr = firstPositionPtr + sizeof(float);
    // 		const float* thirdPositionPtr = secondPositionPtr + sizeof(float);
    //
    // 		ASSERT_TRUE(Mathematics::Vector3DToolsf::Approximate(secondTrianglesMeshPosition,Mathematics::Vector3Df(*firstPositionPtr,*secondPositionPtr,*thirdPositionPtr),1e-6f));
    // 	}
    //
    // 	ASSERT_EQUAL(secondTrianglesMesh->GetNumVertices(),
    // 		         secondTrianglesMesh->GetConstVertexBuffer()->GetNumElements());
    //
    // 	VertexFormatSharedPtr secondVertexformat
    // 		= firstTrianglesMesh->GetConstVertexFormat()->Clone();
    // 	VertexBufferSharedPtr secondVertexbuffer(new VertexBuffer);
    // 	IndexBufferSharedPtr secondIndexbuffer(new IndexBuffer);
    //
    // 	firstTrianglesMesh->SetVertexFormat(secondVertexformat);
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetConstVertexFormat(),secondVertexformat);
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetVertexFormat(),secondVertexformat);
    //
    // 	firstTrianglesMesh->SetVertexBuffer(secondVertexbuffer);
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetConstVertexBuffer(),secondVertexbuffer);
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetVertexBuffer(),secondVertexbuffer);
    //
    // 	firstTrianglesMesh->SetIndexBuffer(secondIndexbuffer);
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetConstIndexBuffer(),secondIndexbuffer);
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetIndexBuffer(),secondIndexbuffer);
    //
    // 	ASSERT_TRUE(firstTrianglesMesh->GetEffectInstance().IsNullPtr());
}

void Rendering::TrianglesMeshTesting::CopyTest()
{
    // 	VisualSharedPtr firstTrianglesMesh =
    // 		LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMesh.trv"));
    //
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetNumControllers(), 0);
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
    // 	firstTrianglesMesh->AttachController(secondVisualTest);
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
    // 	firstTrianglesMesh->AttachController(thirdVisualTest);
    //
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetNumControllers(), 2);
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetController(0), secondVisualTest);
    // 	ASSERT_EQUAL(firstTrianglesMesh->GetController(1), thirdVisualTest);
    //
    // 	secondVisualTest->DetachController(controllerTest);
    //
    // 	thirdVisualTest->AttachController(controllerTest);
    //
    // 	ASSERT_EQUAL(secondVisualTest->GetNumControllers(),0);
    //
    // 	// thirdVisualTest�Ѿ�������һ��VisualTest
    // 	ASSERT_EQUAL(thirdVisualTest->GetNumControllers(),2);
    //
    // 	// Visual����
    // 	VisualSharedPtr secondTrianglesMesh = firstTrianglesMesh->Clone().PolymorphicDowncastObjectSharedPtr<VisualSharedPtr>();
    //
    // 	ASSERT_UNEQUAL(secondTrianglesMesh->GetConstVertexFormat(), firstTrianglesMesh->GetConstVertexFormat());
    // 	ASSERT_UNEQUAL(secondTrianglesMesh->GetVertexFormat(), firstTrianglesMesh->GetVertexFormat());
    // 	ASSERT_UNEQUAL(secondTrianglesMesh->GetConstVertexBuffer(), firstTrianglesMesh->GetConstVertexBuffer());
    // 	ASSERT_UNEQUAL(secondTrianglesMesh->GetVertexBuffer(), firstTrianglesMesh->GetVertexBuffer());
    // 	ASSERT_UNEQUAL(secondTrianglesMesh->GetConstIndexBuffer(), firstTrianglesMesh->GetConstIndexBuffer());
    // 	ASSERT_UNEQUAL(secondTrianglesMesh->GetIndexBuffer(), firstTrianglesMesh->GetIndexBuffer());
}

void Rendering::TrianglesMeshTesting::TransformTest()
{
    // 	VisualSharedPtr firstTrianglesMesh =
    // 			LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMesh.trv"));
    //
    // 	ControllerInterfaceSharedPtr secondSpatialTest(new VisualTest);
    // 	firstTrianglesMesh->AttachController(secondSpatialTest);
    //
    // 	VisualTest* firstPtr = CoreTools::StaticCast<VisualTest>(secondSpatialTest.GetData());
    //
    // 	Transform firstTransform;
    // 	firstTransform.SetUniformScale(5.0f);
    //
    // 	Transform secondTransform;
    // 	secondTransform.SetTranslate(Transform::APoint(5.0f,3.0f,5.6f));
    //
    // 	firstTrianglesMesh->SetLocalTransform(firstTransform);
    // 	firstPtr->SetLocalTransform(secondTransform);
    // 	firstPtr->SetParent(firstTrianglesMesh.GetData());
    //
    // 	firstTrianglesMesh->Update();
    //
    // 	ASSERT_TRUE(Approximate(firstTrianglesMesh->GetLocalTransform(),
    // 	                        firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(firstPtr->GetLocalTransform(),
    // 	                        secondTransform,1e-8f));
    //
    // 	ASSERT_TRUE(Approximate(firstTrianglesMesh->GetWorldTransform(),
    // 	                        firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(firstPtr->GetWorldTransform(),
    // 	                        firstTransform * secondTransform,1e-8f));
    //
    // 	// Visual����
    // 	int numVertices = firstTrianglesMesh->GetConstVertexBuffer()->GetNumElements();
    // 	int stride = firstTrianglesMesh->GetConstVertexFormat()->GetStride();
    //
    // 	int positionIndex = firstTrianglesMesh->GetConstVertexFormat()->GetIndex(VertexFormatFlags::AttributeUsage::Position);
    //
    // 	const char* data = firstTrianglesMesh->GetConstVertexBuffer()->GetReadOnlyData();
    // 	int positionOffset = firstTrianglesMesh->GetConstVertexFormat()->GetOffset(positionIndex);
    //
    // 	Bound modelBound;
    // 	modelBound.ComputeFromData(numVertices, stride, data + positionOffset);
    //
    // 	Bound worldBound = modelBound.TransformBy(firstTrianglesMesh->GetWorldTransform());
    //
    // 	ASSERT_TRUE(Approximate(firstTrianglesMesh->GetModelBound(),
    // 	                        modelBound,1e-8f));
    //
    // 	ASSERT_TRUE(Approximate(firstTrianglesMesh->GetWorldBound(),
    // 	                        worldBound,1e-8f));
}

void Rendering::TrianglesMeshTesting::StreamTest()
{
    // 	VisualSharedPtr firstTrianglesMesh =
    // 			LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMesh.trv"));
    //
    // 	CoreTools::OutTopLevel outTopLevel;
    //
    // 	firstTrianglesMesh->SetUniqueID(5);
    //
    // 	outTopLevel.Insert(firstTrianglesMesh.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
    //
    // 	Transform firstTransform;
    // 	Transform secondTransform;
    // 	Bound firstBound(Bound::APoint(0.2f,5.0f,3.0f),2.0f);
    //
    // 	firstTransform.SetUniformScale(5.0f);
    // 	secondTransform.SetUniformScale(3.0f);
    //
    // 	firstTrianglesMesh->SetLocalTransform(firstTransform);
    // 	firstTrianglesMesh->SetWorldTransform(secondTransform);
    // 	firstTrianglesMesh->SetWorldBound(firstBound);
    // 	firstTrianglesMesh->SetCullingMode(CullingMode::Always);
    //
    // 	ControllerInterfaceSharedPtr thirdVisualTest(new VisualTest);
    // 	firstTrianglesMesh->AttachController(thirdVisualTest);
    //
    // 	thirdVisualTest->SetUniqueID(4);
    //
    // 	ControllerInterfaceSharedPtr fourthVisualTest(new VisualTest);
    // 	firstTrianglesMesh->AttachController(fourthVisualTest);
    //
    // 	fourthVisualTest->SetUniqueID(3);
    //
    // 	ControllerInterfaceSharedPtr fifthVisualTest(new VisualTest);
    // 	firstTrianglesMesh->AttachController(fifthVisualTest);
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
    // 	TrianglesMeshSharedPtr  secondTrianglesMesh =
    // 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<TrianglesMeshSharedPtr>();
    //
    // 	ASSERT_EQUAL(secondTrianglesMesh->GetNumControllers(), 3);
    //
    // 	ASSERT_TRUE(Approximate(secondTrianglesMesh->GetLocalTransform(),
    // 	                        firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(secondTrianglesMesh->GetWorldTransform(),
    // 	                        secondTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(secondTrianglesMesh->GetWorldBound(), firstBound, 1e-8f));
    // 	ASSERT_ENUM_EQUAL(secondTrianglesMesh->GetCullingMode(), CullingMode::Always);
    //
    // 	VisualTest* eighthVisualTest =
    // 		CoreTools::DynamicCast<VisualTest>(secondTrianglesMesh->GetController(0).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(eighthVisualTest);
    //
    // 	VisualTest* ninthVisualTest =
    // 		CoreTools::DynamicCast<VisualTest>(secondTrianglesMesh->GetController(1).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(ninthVisualTest);
    //
    // 	VisualTest* tenthVisualTest =
    // 		CoreTools::DynamicCast<VisualTest>
    // 		(secondTrianglesMesh->GetController(2).GetData());
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
    // 	// Visual����
    // 	ASSERT_ENUM_EQUAL(firstTrianglesMesh->GetPrimitiveType(), secondTrianglesMesh->GetPrimitiveType());
    //
    // 	VertexBufferSharedPtr firstBuffer = firstTrianglesMesh->GetVertexBuffer();
    // 	VertexBufferSharedPtr secondBuffer = secondTrianglesMesh->GetVertexBuffer();
    //
    // 	IndexBufferSharedPtr thirdBuffer = firstTrianglesMesh->GetIndexBuffer();
    // 	IndexBufferSharedPtr fourthBuffer = secondTrianglesMesh->GetIndexBuffer();
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
    // 	VertexFormatSharedPtr firstVertexFormat = firstTrianglesMesh->GetVertexFormat();
    // 	VertexFormatSharedPtr secondVertexFormat = secondTrianglesMesh->GetVertexFormat();
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

void Rendering::TrianglesMeshTesting::FileTest()
{
    // 	VisualSharedPtr firstTrianglesMesh =
    // 			LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMesh.trv"));
    //
    //
    // 	SaveVisual::SaveToFile(*firstTrianglesMesh, SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMeshSave.trv"));
    //
    // 	LoadVisual secondLoadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMeshSave.trv"));
    //
    // 	VisualTest secondVisualTest(secondLoadVisual.GetPrimitiveType(),
    // 		                        secondLoadVisual.GetVertexFormat(),
    // 								secondLoadVisual.GetVertexBuffer(),
    // 								secondLoadVisual.GetIndexBuffer());
    //
    // 	ASSERT_ENUM_EQUAL(firstTrianglesMesh->GetPrimitiveType(), secondLoadVisual.GetPrimitiveType());
    //
    // 	VertexBufferSharedPtr firstBuffer = firstTrianglesMesh->GetVertexBuffer();
    // 	VertexBufferSharedPtr secondBuffer = secondLoadVisual.GetVertexBuffer();
    //
    // 	IndexBufferSharedPtr thirdBuffer = firstTrianglesMesh->GetIndexBuffer();
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
    // 	VertexFormatSharedPtr firstVertexFormat = firstTrianglesMesh->GetVertexFormat();
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

void Rendering::TrianglesMeshTesting::UpdateModelSpaceTest()
{
    // 	VisualSharedPtr firstTrianglesMesh =
    // 		LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMesh.trv"));
    //
    // 	TrianglesMeshSharedPtr secondTrianglesMesh =
    // 		firstTrianglesMesh.PolymorphicDowncastObjectSharedPtr<TrianglesMeshSharedPtr>();
    //
    // 	firstTrianglesMesh->UpdateModelSpace(VisualUpdateType::Normals);
    //
    // 	VertexBufferAccessor vertexBufferAccessor(firstTrianglesMesh.GetData());
    // 	ASSERT_TRUE(vertexBufferAccessor.HasNormal());
    //
    // 	const int numVertices = secondTrianglesMesh->GetNumVertices();
    // 	for (int index = 0; index < numVertices; ++index)
    // 	{
    // 		Mathematics::AVectorf normal =
    // 			vertexBufferAccessor.GetNormal<Mathematics::AVectorf>(index);
    //
    // 		ASSERT_TRUE(normal.IsNormalize());
    // 	}
    //
    // 	firstTrianglesMesh->UpdateModelSpace(VisualUpdateType::UseGeometry);
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
    // 	const int numTriangles = secondTrianglesMesh->GetNumTriangles();
    //
    // 	for (int index = 0; index < numTriangles; ++index)
    // 	{
    // 		// ��ȡ�����εĶ���������
    // 		TriangleIndex triangleIndex = secondTrianglesMesh->GetTriangle(index);
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
    // 			// ����pos0��pos1�ıߣ�Ͷ�䶥�����ƽ��,���������ڷ��ߵĲ
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
    // 			// ����pos0��pos2�ıߣ�Ͷ�䶥�����ƽ��,���������ڷ��ߵĲ
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
    // 		// ͨ��N���� U �� V��
    // 		Mathematics::AVectorf normal = vertexBufferAccessor.GetNormal<Mathematics::AVectorf>(index);
    // 		const Mathematics::AVectorOrthonormalBasisf aVectorOrthonormalBasis =
    // 			GenerateComplementBasis(normal);
    //
    // 		Mathematics::AVectorf uNormal = aVectorOrthonormalBasis.GetUVector();
    // 		Mathematics::AVectorf vNormal = aVectorOrthonormalBasis.GetVVector();
    // 		Mathematics::AVectorf wNormal = aVectorOrthonormalBasis.GetWVector();
    //
    // 		// ����S = J^T * dN / dX * J .
    // 		// ������S�ǶԳƵ�,����Ϊ���ǹ���dN/dX��
    // 		// ���Ǳ�����΢�������ǵļ���,��ȷ��S�ǶԳƵġ�
    // 		float symmetric01 = Dot(uNormal, derivativestNormal[index] * vNormal);
    // 		float symmetric10 = Dot(vNormal, derivativestNormal[index] * uNormal);
    // 		float symmetricAverage = 0.5f * (symmetric01 + symmetric10);
    // 		float symmetricMat[2][2] =
    // 		{
    // 			{ Dot(uNormal, derivativestNormal[index] * uNormal), symmetricAverage },
    // 			{ symmetricAverage, Dot(vNormal, derivativestNormal[index] * vNormal) }
    // 		};
    //
    // 		// ����S������ֵ(��С���������)��
    // 		float trace = symmetricMat[0][0] + symmetricMat[1][1];
    // 		float det = symmetricMat[0][0] * symmetricMat[1][1] - symmetricMat[0][1] * symmetricMat[1][0];
    // 		float discr = trace * trace - 4.0f * det;
    // 		float rootDiscr = Mathematics::MathF::Sqrt(Mathematics::MathF::FAbs(discr));
    // 		float minCurvature = 0.5f * (trace - rootDiscr);
    // 		// float maxCurvature = 0.5f * (trace + rootDiscr);
    //
    // 		// ����S����������.
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
    // 	firstTrianglesMesh->UpdateModelSpace(VisualUpdateType::UseTextureCoordChannel);
    //
    // 	for (int index = 0; index < numTriangles; ++index)
    // 	{
    // 		TriangleIndex triangleIndex = secondTrianglesMesh->GetTriangle(index);
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
    // 			if (Mathematics::MathF::FAbs(differenceP1P0.Length()) <
    // 				Mathematics::MathF::sm_ZeroTolerance ||
    // 				Mathematics::MathF::FAbs(differenceP2P0.Length()) <
    // 				Mathematics::MathF::sm_ZeroTolerance)
    // 			{
    // 				tangentVector2 = Mathematics::AVectorf::sm_Zero;
    // 			}
    // 			else
    // 			{
    // 				float differenceU1U0 = localTextureCoord[next][0] - localTextureCoord[current][0];
    // 				float differenceV1V0 = localTextureCoord[next][1] - localTextureCoord[current][1];
    // 				if (Mathematics::MathF::FAbs(differenceV1V0) <
    // 					Mathematics::MathF::sm_ZeroTolerance)
    // 				{
    // 					if (Mathematics::MathF::FAbs(differenceU1U0) <
    // 						Mathematics::MathF::sm_ZeroTolerance)
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
    // 					if (Mathematics::MathF::FAbs(det) <
    // 						Mathematics::MathF::sm_ZeroTolerance)
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