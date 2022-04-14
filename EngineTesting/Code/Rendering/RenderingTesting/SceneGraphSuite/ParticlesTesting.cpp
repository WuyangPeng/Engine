// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 11:01)

#include "ParticlesTesting.h"
#include "VisualTest.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorOrthonormalBasisDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/Particles.h"
#include "Rendering/SceneGraph/SaveVisual.h"

#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"

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
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ParticlesTesting)

void Rendering::ParticlesTesting::MainTest()
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

    RendererManager::Destroy();
    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::ParticlesTesting::CreateTrianglesMeshFile()
{
    WriteFileManager manage(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesParticles.trv"));

    std::default_random_engine generator;
    std::uniform_real<float> firstFloatRandomDistribution(-1.0f, 1.0f);

    constexpr int type = System::EnumCastUnderlying(VisualPrimitiveType::TriangleMesh);
    manage.Write(sizeof(int), &type);

    // VertexFormat
    vector<VertexFormatType> firstVertexFormatType{ VertexFormatType(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0),
                                                    VertexFormatType(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 0) };

    VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);

    firstVertexFormat->SaveToFile(manage);

    // VertexBuffer
    int numElements = 80;
    int elementSize = firstVertexFormat->GetStride();
    constexpr int usage = System::EnumCastUnderlying(BufferUsage::Static);

    manage.Write(sizeof(int), &numElements);
    manage.Write(sizeof(int), &elementSize);
    manage.Write(sizeof(int), &usage);

    for (int i = 0; i < numElements; ++i)
    {
        for (int attributesIndex = 0; attributesIndex < firstVertexFormat->GetNumAttributes(); ++attributesIndex)
        {
            VertexFormat::AttributeType type2 = firstVertexFormat->GetAttributeType(attributesIndex);

            int componentSize = VertexFormat::GetComponentSize(type2);
            int numComponents = VertexFormat::GetNumComponents(type2);

            vector<char> buffer(componentSize * numComponents);

            for (unsigned bufferIndex = 0; bufferIndex < buffer.size() / sizeof(float); ++bufferIndex)
            {
                float* floatBufferPtr = reinterpret_cast<float*>(&buffer[bufferIndex * sizeof(float)]);

                *floatBufferPtr = firstFloatRandomDistribution(generator);
            }

            manage.Write(componentSize, numComponents, &buffer[0]);
        }
    }

    // IndexBuffer
    int indexBufferNumElements = 0;

    manage.Write(sizeof(int), &indexBufferNumElements);
}

void Rendering::ParticlesTesting::InitTest()
{
    // 	std::default_random_engine generator;
    // 	std::uniform_real<float> firstFloatRandomDistribution(-1.0f, 1.0f);
    //
    // 	LoadVisual loadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesParticles.trv"));
    //
    // 	vector<Mathematics::APointf> positions;
    // 	vector<float> sizes;
    //
    // 	VertexBufferAccessor vertexBufferAccessor(loadVisual.GetVertexFormat().PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>(),
    // 		                                      loadVisual.GetVertexBuffer().PolymorphicDowncastConstObjectSharedPtr<ConstVertexBufferSharedPtr>());
    //
    // 	for (int i = 0; i < vertexBufferAccessor.GetNumVertices() / 4;++i)
    // 	{
    // 		positions.push_back(vertexBufferAccessor.GetPosition<Mathematics::APointf>(i));
    // 		sizes.push_back(firstFloatRandomDistribution(generator));
    // 	}
    //
    // 	for (unsigned i = 0; i < positions.size(); ++i)
    // 	{
    // 		ASSERT_TRUE(-1.0f <= positions[i][0] && positions[i][0] <= 1.0f);
    // 		ASSERT_TRUE(-1.0f <= positions[i][1] && positions[i][1] <= 1.0f);
    // 		ASSERT_TRUE(-1.0f <= positions[i][2] && positions[i][2] <= 1.0f);
    // 	}
    //
    // 	ParticlesSharedPtr firstParticles(new Particles(loadVisual.GetVertexFormat(),
    // 		                                                loadVisual.GetVertexBuffer(),
    // 														4, positions, sizes,1.01f));
    //
    // 	ASSERT_EQUAL(firstParticles->GetNumControllers(), 0);
    //
    // 	ControllerInterfaceSharedPtr controllerTest(new VisualTest);
    // 	firstParticles->AttachController(controllerTest);
    //
    // 	ASSERT_EQUAL(firstParticles->GetNumControllers(), 1);
    // 	ASSERT_EQUAL(firstParticles->GetController(0), controllerTest);
    //
    // 	ControllerInterfaceSharedPtr secondVisualTest(new VisualTest);
    //
    // 	ASSERT_EQUAL_NULL_PTR(secondVisualTest->GetControllerObject());
    //
    // 	firstParticles->AttachController(secondVisualTest);
    //
    // 	VisualTest* ptr = CoreTools::StaticCast<VisualTest>(secondVisualTest.GetData());
    //
    // 	ASSERT_EQUAL(secondVisualTest->GetControllerObject(),
    // 	             firstParticles);
    // 	ASSERT_EQUAL_NULL_PTR(ptr->GetParent());
    //
    // 	ASSERT_EQUAL(firstParticles->GetNumControllers(), 2);
    // 	ASSERT_EQUAL(firstParticles->GetController(0), controllerTest);
    // 	ASSERT_EQUAL(firstParticles->GetController(1), secondVisualTest);
    //
    // 	firstParticles->DetachController(controllerTest);
    //
    // 	ASSERT_EQUAL(firstParticles->GetNumControllers(), 1);
    // 	ASSERT_EQUAL(firstParticles->GetController(0), secondVisualTest);
    //
    // 	firstParticles->DetachAllControllers();
    //
    // 	ASSERT_EQUAL(firstParticles->GetNumControllers(), 0);
    //
    // 	// Visual≤‚ ‘
    //
    // 	ASSERT_ENUM_EQUAL(firstParticles->GetPrimitiveType(), VisualPrimitiveType::TriangleMesh);
    //
    // 	ASSERT_FALSE(firstParticles->GetConstVertexFormat().IsNullPtr());
    // 	ASSERT_FALSE(firstParticles->GetVertexFormat().IsNullPtr());
    //
    // 	ASSERT_FALSE(firstParticles->GetConstVertexBuffer().IsNullPtr());
    // 	ASSERT_FALSE(firstParticles->GetVertexBuffer().IsNullPtr());
    //
    // 	ASSERT_FALSE(firstParticles->GetConstIndexBuffer().IsNullPtr());
    // 	ASSERT_FALSE(firstParticles->GetIndexBuffer().IsNullPtr());
    //
    // 	ASSERT_TRUE(firstParticles->GetEffectInstance().IsNullPtr());
    //
    // 	// TrianglesMesh≤‚ ‘
    // 	TrianglesMeshSharedPtr secondParticles = firstParticles.PolymorphicDowncastSharedPtr<TrianglesMeshSharedPtr>();
    // 	ASSERT_EQUAL(secondParticles->GetNumTriangles(),secondParticles->GetConstIndexBuffer()->GetNumElements() / 3);
    //
    // 	for (int index = 0; index < secondParticles->GetVertexBuffer()->GetNumElements(); ++index)
    // 	{
    // 		VertexBufferAccessor vertexBufferAccessor2(secondParticles->GetConstVertexFormat(),secondParticles->GetConstVertexBuffer());
    //
    // 		Mathematics::APointf point = vertexBufferAccessor2.GetPosition<Mathematics::APointf>(index);
    //
    // 		ASSERT_TRUE(-1.0f <= point[0] && point[0] <= 1.0f);
    // 		ASSERT_TRUE(-1.0f <= point[1] && point[1] <= 1.0f);
    // 		ASSERT_TRUE(-1.0f <= point[2] && point[2] <= 1.0f);
    // 	}
    //
    // 	for (int index = 0; index < secondParticles->GetNumTriangles(); ++index)
    // 	{
    // 		TriangleIndex triangleIndex = secondParticles->GetTriangle(index);
    //
    // 		ASSERT_TRUE(0 <= triangleIndex.GetFirstIndex() && triangleIndex.GetFirstIndex() < 80);
    // 		ASSERT_TRUE(0 <= triangleIndex.GetSecondIndex() && triangleIndex.GetSecondIndex() < 80);
    // 		ASSERT_TRUE(0 <= triangleIndex.GetThirdIndex() && triangleIndex.GetThirdIndex() < 80);
    //
    // 		TrianglePosition modelTriangle = secondParticles->GetModelTriangle(index);
    //
    // 		VertexBufferAccessor vertexBufferAccessor2(secondParticles->GetConstVertexFormat(),secondParticles->GetConstVertexBuffer());
    //
    // 		TrianglePosition testModelTriangle(vertexBufferAccessor2.GetPosition<Mathematics::APointf>(triangleIndex.GetFirstIndex()),
    // 			                               vertexBufferAccessor2.GetPosition<Mathematics::APointf>(triangleIndex.GetSecondIndex()),
    // 										   vertexBufferAccessor2.GetPosition<Mathematics::APointf>(triangleIndex.GetThirdIndex()));
    //
    // 		ASSERT_TRUE(Approximate(modelTriangle.GetFirstPosition(), testModelTriangle.GetFirstPosition(), 1e-8f));
    //
    // 		ASSERT_TRUE(Approximate(modelTriangle.GetSecondPosition(), testModelTriangle.GetSecondPosition(), 1e-8f));
    //
    // 		ASSERT_TRUE(Approximate(modelTriangle.GetThirdPosition(), testModelTriangle.GetThirdPosition(), 1e-8f));
    //
    // 		TrianglePosition worldTriangle = secondParticles->GetWorldTriangle(index);
    //
    // 		Mathematics::APointf firstPosition = secondParticles->GetWorldTransform() * modelTriangle.GetFirstPosition();
    // 		Mathematics::APointf secondPosition = secondParticles->GetWorldTransform() * modelTriangle.GetSecondPosition();
    // 		Mathematics::APointf thirdPosition = secondParticles->GetWorldTransform() * modelTriangle.GetThirdPosition();
    //
    // 		ASSERT_TRUE(Approximate(firstPosition, worldTriangle.GetFirstPosition(), 1e-6f));
    // 		ASSERT_TRUE(Approximate(secondPosition, worldTriangle.GetSecondPosition(), 1e-6f));
    // 		ASSERT_TRUE(Approximate(thirdPosition, worldTriangle.GetThirdPosition(), 1e-6f));
    // 	}
    //
    // 	for (int index = 0; index < secondParticles->GetVertexBuffer()->GetNumElements(); ++index)
    // 	{
    // 		Mathematics::Vector3Df secondTrianglesMeshPosition =  secondParticles->GetPosition(index);
    //
    // 		int vertexIndex = secondParticles->GetConstVertexFormat()->GetIndex(VertexFormatFlags::AttributeUsage::Position);
    //
    // 		const char* positions2 = secondParticles->GetConstVertexBuffer()->GetReadOnlyData() +
    // 			                    secondParticles->GetConstVertexFormat()->GetOffset(vertexIndex);
    // 		int stride =  secondParticles->GetConstVertexFormat()->GetStride();
    // 		const float* firstPositionPtr = reinterpret_cast<const float*>(positions2 + index * stride);
    // 		const float* secondPositionPtr = firstPositionPtr + sizeof(float);
    // 		const float* thirdPositionPtr = secondPositionPtr + sizeof(float);
    //
    // 		ASSERT_TRUE(Mathematics::Vector3DToolsf::Approximate(secondTrianglesMeshPosition,Mathematics::Vector3Df(*firstPositionPtr,*secondPositionPtr,*thirdPositionPtr),1e-6f));
    // 	}
    //
    // 	ASSERT_EQUAL(secondParticles->GetNumVertices(), secondParticles->GetConstVertexBuffer()->GetNumElements());
    //
    // 	// Particles≤‚ ‘
    // 	ASSERT_EQUAL(firstParticles->GetNumParticles(), vertexBufferAccessor.GetNumVertices() / 4);
    //
    // 	for (int i = 0; i < firstParticles->GetNumParticles();++i)
    // 	{
    // 		Mathematics::APointf position = firstParticles->GetPosition(i);
    // 		ASSERT_TRUE(Approximate(position, positions[i], 1e-8f));
    //
    // 		float size = firstParticles->GetSize(i);
    // 		ASSERT_APPROXIMATE(size, sizes[i], 1e-8f);
    // 	}
    //
    // 	ASSERT_APPROXIMATE(firstParticles->GetSizeAdjust(), 1.01f,1e-8f);
    //
    // 	ASSERT_EQUAL(firstParticles->GetNumActive(), vertexBufferAccessor.GetNumVertices() / 4);
    //
    // 	firstParticles->SetNumActive(vertexBufferAccessor.GetNumVertices());
    // 	ASSERT_EQUAL(firstParticles->GetNumActive(), vertexBufferAccessor.GetNumVertices() / 4);
    // 	ASSERT_EQUAL(firstParticles->GetNumParticles(), vertexBufferAccessor.GetNumVertices() / 4);
    //
    // 	int numParticles = firstParticles->GetNumParticles();
    // 	firstParticles->SetNumActive(2);
    // 	ASSERT_EQUAL(firstParticles->GetNumActive(), 2);
    // 	ASSERT_EQUAL(firstParticles->GetNumParticles(), numParticles);
    //
    // 	firstParticles->GenerateParticles(ConstCameraSharedPtr(new Camera));
    //
    // 	VertexFormatSharedPtr secondVertexformat  = firstParticles->GetConstVertexFormat()->Clone();
    // 	VertexBufferSharedPtr secondVertexbuffer(new VertexBuffer);
    // 	IndexBufferSharedPtr secondIndexbuffer(new IndexBuffer);
    //
    // 	firstParticles->SetVertexFormat(secondVertexformat);
    // 	ASSERT_EQUAL(firstParticles->GetConstVertexFormat(), secondVertexformat);
    // 	ASSERT_EQUAL(firstParticles->GetVertexFormat(), secondVertexformat);
    //
    // 	firstParticles->SetVertexBuffer(secondVertexbuffer);
    // 	ASSERT_EQUAL(firstParticles->GetConstVertexBuffer(), secondVertexbuffer);
    // 	ASSERT_EQUAL(firstParticles->GetVertexBuffer(), secondVertexbuffer);
    //
    // 	firstParticles->SetIndexBuffer(secondIndexbuffer);
    // 	ASSERT_EQUAL(firstParticles->GetConstIndexBuffer(), secondIndexbuffer);
    // 	ASSERT_EQUAL(firstParticles->GetIndexBuffer(), secondIndexbuffer);
    //
    // 	ASSERT_TRUE(firstParticles->GetEffectInstance().IsNullPtr());
}

void Rendering::ParticlesTesting::CopyTest()
{
    // 	std::default_random_engine generator;
    // 	std::uniform_real<float> firstFloatRandomDistribution(-1.0f, 1.0f);
    //
    // 	LoadVisual loadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesParticles.trv"));
    //
    // 	vector<Mathematics::APointf> positions;
    // 	vector<float> sizes;
    //
    // 	VertexBufferAccessor vertexBufferAccessor(loadVisual.GetVertexFormat().PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>(),
    // 		                                      loadVisual.GetVertexBuffer().PolymorphicDowncastConstObjectSharedPtr<ConstVertexBufferSharedPtr>());
    //
    // 	for (int i = 0; i < vertexBufferAccessor.GetNumVertices() / 4;++i)
    // 	{
    // 		positions.push_back(vertexBufferAccessor.GetPosition<Mathematics::APointf>(i));
    // 		sizes.push_back(firstFloatRandomDistribution(generator));
    // 	}
    //
    // 	ParticlesSharedPtr firstParticles(new Particles(loadVisual.GetVertexFormat(),
    // 		                                                loadVisual.GetVertexBuffer(),
    // 														4, positions, sizes,1.01f));
    //
    // 	firstParticles->GenerateParticles(ConstCameraSharedPtr(new Camera));
    //
    // 	ASSERT_EQUAL(firstParticles->GetNumControllers(), 0);
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
    // 	firstParticles->AttachController(secondVisualTest);
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
    // 	ASSERT_APPROXIMATE(secondPtr->GetLocalTransform().GetUniformScale (), 3.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(firstPtr->GetLocalTransform().GetUniformScale (), 5.0f,1e-8f);
    //
    // 	firstParticles->AttachController(thirdVisualTest);
    //
    // 	ASSERT_EQUAL(firstParticles->GetNumControllers(), 2);
    // 	ASSERT_EQUAL(firstParticles->GetController(0), secondVisualTest);
    // 	ASSERT_EQUAL(firstParticles->GetController(1), thirdVisualTest);
    //
    // 	secondVisualTest->DetachController(controllerTest);
    //
    // 	thirdVisualTest->AttachController(controllerTest);
    //
    // 	ASSERT_EQUAL(secondVisualTest->GetNumControllers(),0);
    //
    // 	// thirdVisualTest“—æ≠∏¥÷∆¡À“ª∏ˆVisualTest
    // 	ASSERT_EQUAL(thirdVisualTest->GetNumControllers(),2);
    //
    // 	// Visual≤‚ ‘
    // 	VisualSharedPtr secondTrianglesMesh = firstParticles->Clone().PolymorphicDowncastObjectSharedPtr<VisualSharedPtr>();
    //
    // 	ASSERT_UNEQUAL(secondTrianglesMesh->GetConstVertexFormat(), firstParticles->GetConstVertexFormat());
    // 	ASSERT_UNEQUAL(secondTrianglesMesh->GetVertexFormat(), firstParticles->GetVertexFormat());
    // 	ASSERT_UNEQUAL(secondTrianglesMesh->GetConstVertexBuffer(), firstParticles->GetConstVertexBuffer());
    // 	ASSERT_UNEQUAL(secondTrianglesMesh->GetVertexBuffer(), firstParticles->GetVertexBuffer());
    // 	ASSERT_UNEQUAL(secondTrianglesMesh->GetConstIndexBuffer(), firstParticles->GetConstIndexBuffer());
    // 	ASSERT_UNEQUAL(secondTrianglesMesh->GetIndexBuffer(), firstParticles->GetIndexBuffer());
}

void Rendering::ParticlesTesting::TransformTest()
{
    // 	std::default_random_engine generator;
    // 	std::uniform_real<float> firstFloatRandomDistribution(-1.0f, 1.0f);
    //
    // 	LoadVisual loadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesParticles.trv"));
    //
    // 	vector<Mathematics::APointf> positions;
    // 	vector<float> sizes;
    //
    // 	VertexBufferAccessor vertexBufferAccessor(loadVisual.GetVertexFormat().PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>(),
    // 		                                      loadVisual.GetVertexBuffer().PolymorphicDowncastConstObjectSharedPtr<ConstVertexBufferSharedPtr>());
    //
    // 	for (int i = 0; i < vertexBufferAccessor.GetNumVertices() / 4;++i)
    // 	{
    // 		positions.push_back(vertexBufferAccessor.GetPosition<Mathematics::APointf>(i));
    // 		sizes.push_back(firstFloatRandomDistribution(generator));
    // 	}
    //
    // 	ParticlesSharedPtr firstParticles(new Particles(loadVisual.GetVertexFormat(),
    // 		                                                loadVisual.GetVertexBuffer(),
    // 														4, positions, sizes,1.01f));
    //
    // 	firstParticles->GenerateParticles(ConstCameraSharedPtr(new Camera));
    //
    // 	ControllerInterfaceSharedPtr secondSpatialTest(new VisualTest);
    // 	firstParticles->AttachController(secondSpatialTest);
    //
    // 	VisualTest* firstPtr = CoreTools::StaticCast<VisualTest>(secondSpatialTest.GetData());
    //
    // 	Transform firstTransform;
    // 	firstTransform.SetUniformScale(5.0f);
    //
    // 	Transform secondTransform;
    // 	secondTransform.SetTranslate(Transform::APoint(5.0f,3.0f,5.6f));
    //
    // 	firstParticles->SetLocalTransform(firstTransform);
    // 	firstPtr->SetLocalTransform(secondTransform);
    // 	firstPtr->SetParent(firstParticles.GetData());
    //
    // 	firstParticles->Update();
    //
    // 	ASSERT_TRUE(Approximate(firstParticles->GetLocalTransform(), firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(firstPtr->GetLocalTransform(), secondTransform,1e-8f));
    //
    // 	ASSERT_TRUE(Approximate(firstParticles->GetWorldTransform(), firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(firstPtr->GetWorldTransform(), firstTransform * secondTransform,1e-8f));
    //
    // 	// Visual≤‚ ‘
    // 	int numVertices = firstParticles->GetConstVertexBuffer()->GetNumElements();
    // 	int stride = firstParticles->GetConstVertexFormat()->GetStride();
    //
    // 	int positionIndex = firstParticles->GetConstVertexFormat()->GetIndex(VertexFormatFlags::AttributeUsage::Position);
    //
    // 	const char* data = firstParticles->GetConstVertexBuffer()->GetReadOnlyData();
    // 	int positionOffset = firstParticles->GetConstVertexFormat()->GetOffset(positionIndex);
    //
    // 	Bound modelBound;
    // 	modelBound.ComputeFromData(numVertices, stride, data + positionOffset);
    //
    // 	Bound worldBound = modelBound.TransformBy(firstParticles->GetWorldTransform());
    //
    // 	ASSERT_TRUE(Approximate(firstParticles->GetModelBound(), modelBound,1e-8f));
    //
    // 	ASSERT_TRUE(Approximate(firstParticles->GetWorldBound(), worldBound,1e-8f));
}

void Rendering::ParticlesTesting::StreamTest()
{
    // 	std::default_random_engine generator;
    // 	std::uniform_real<float> firstFloatRandomDistribution(-1.0f, 1.0f);
    //
    // 	LoadVisual loadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesParticles.trv"));
    //
    // 	vector<Mathematics::APointf> positions;
    // 	vector<float> sizes;
    //
    // 	VertexBufferAccessor vertexBufferAccessor(loadVisual.GetVertexFormat().PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>(),
    // 		                                      loadVisual.GetVertexBuffer().PolymorphicDowncastConstObjectSharedPtr<ConstVertexBufferSharedPtr>());
    //
    // 	for (int i = 0; i < vertexBufferAccessor.GetNumVertices() / 4;++i)
    // 	{
    // 		positions.push_back(vertexBufferAccessor.GetPosition<Mathematics::APointf>(i));
    // 		sizes.push_back(firstFloatRandomDistribution(generator));
    // 	}
    //
    // 	ParticlesSharedPtr firstParticles(new Particles(loadVisual.GetVertexFormat(),
    // 		                                                loadVisual.GetVertexBuffer(),
    // 														4, positions, sizes,1.01f));
    //
    // 	firstParticles->GenerateParticles(ConstCameraSharedPtr(new Camera));
    //
    // 	CoreTools::OutTopLevel outTopLevel;
    //
    // 	firstParticles->SetUniqueID(5);
    //
    // 	outTopLevel.Insert(firstParticles.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
    //
    // 	Transform firstTransform;
    // 	Transform secondTransform;
    // 	Bound firstBound(Bound::APoint(0.2f,5.0f,3.0f),2.0f);
    //
    // 	firstTransform.SetUniformScale(5.0f);
    // 	secondTransform.SetUniformScale(3.0f);
    //
    // 	firstParticles->SetLocalTransform(firstTransform);
    // 	firstParticles->SetWorldTransform(secondTransform);
    // 	firstParticles->SetWorldBound(firstBound);
    // 	firstParticles->SetCullingMode(CullingMode::Always);
    //
    // 	ControllerInterfaceSharedPtr thirdVisualTest(new VisualTest);
    // 	firstParticles->AttachController(thirdVisualTest);
    //
    // 	thirdVisualTest->SetUniqueID(4);
    //
    // 	ControllerInterfaceSharedPtr fourthVisualTest(new VisualTest);
    // 	firstParticles->AttachController(fourthVisualTest);
    //
    // 	fourthVisualTest->SetUniqueID(3);
    //
    // 	ControllerInterfaceSharedPtr fifthVisualTest(new VisualTest);
    // 	firstParticles->AttachController(fifthVisualTest);
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
    // 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
    //
    // 	CoreTools::BufferInStream inStream(fileBufferPtr);
    //
    // 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
    //
    // 	TrianglesMeshSharedPtr  secondParticles = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<TrianglesMeshSharedPtr>();
    //
    // 	ASSERT_EQUAL(secondParticles->GetNumControllers(), 3);
    //
    // 	ASSERT_TRUE(Approximate(secondParticles->GetLocalTransform(), firstTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(secondParticles->GetWorldTransform(), secondTransform,1e-8f));
    // 	ASSERT_TRUE(Approximate(secondParticles->GetWorldBound(), firstBound, 1e-8f));
    // 	ASSERT_ENUM_EQUAL(secondParticles->GetCullingMode(), CullingMode::Always);
    //
    // 	VisualTest* eighthVisualTest = CoreTools::DynamicCast<VisualTest>(secondParticles->GetController(0).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(eighthVisualTest);
    //
    // 	VisualTest* ninthVisualTest = CoreTools::DynamicCast<VisualTest>(secondParticles->GetController(1).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(ninthVisualTest);
    //
    // 	VisualTest* tenthVisualTest = CoreTools::DynamicCast<VisualTest> (secondParticles->GetController(2).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(tenthVisualTest);
    //
    // 	ASSERT_EQUAL(tenthVisualTest->GetNumControllers(), 1);
    //
    // 	VisualTest* eleventhVisualTest = CoreTools::DynamicCast<VisualTest> (tenthVisualTest->GetController(0).GetData());
    //
    // 	ASSERT_UNEQUAL_NULL_PTR(eleventhVisualTest);
    //
    // 	// Visual≤‚ ‘
    // 	ASSERT_ENUM_EQUAL(firstParticles->GetPrimitiveType(), secondParticles->GetPrimitiveType());
    //
    // 	VertexBufferSharedPtr firstBuffer = firstParticles->GetVertexBuffer();
    // 	VertexBufferSharedPtr secondBuffer = secondParticles->GetVertexBuffer();
    //
    // 	IndexBufferSharedPtr thirdBuffer = firstParticles->GetIndexBuffer();
    // 	IndexBufferSharedPtr fourthBuffer = secondParticles->GetIndexBuffer();
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
    // 	VertexFormatSharedPtr firstVertexFormat = firstParticles->GetVertexFormat();
    // 	VertexFormatSharedPtr secondVertexFormat = secondParticles->GetVertexFormat();
    //
    // 	ASSERT_EQUAL(firstVertexFormat->GetNumAttributes(), secondVertexFormat->GetNumAttributes());
    //
    // 	for (int i = 0; i < firstVertexFormat->GetNumAttributes(); ++i)
    // 	{
    // 		ASSERT_EQUAL(firstVertexFormat->GetStreamIndex(i), secondVertexFormat->GetStreamIndex(i));
    // 		ASSERT_EQUAL(firstVertexFormat->GetOffset(i), secondVertexFormat->GetOffset(i));
    // 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeType(i), secondVertexFormat->GetAttributeType(i));
    // 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeUsage(i),  secondVertexFormat->GetAttributeUsage(i));
    // 		ASSERT_EQUAL(firstVertexFormat->GetUsageIndex(i), secondVertexFormat->GetUsageIndex(i));
    // 	}
    //
    // 	ASSERT_EQUAL(firstVertexFormat->GetStride(), secondVertexFormat->GetStride());
}

void Rendering::ParticlesTesting::FileTest()
{
    // 	std::default_random_engine generator;
    // 	std::uniform_real<float> firstFloatRandomDistribution(-1.0f, 1.0f);
    //
    // 	LoadVisual loadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesParticles.trv"));
    //
    // 	vector<Mathematics::APointf> positions;
    // 	vector<float> sizes;
    //
    // 	VertexBufferAccessor vertexBufferAccessor(loadVisual.GetVertexFormat().PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>(),
    // 		                                      loadVisual.GetVertexBuffer().PolymorphicDowncastConstObjectSharedPtr<ConstVertexBufferSharedPtr>());
    //
    // 	for (int i = 0; i < vertexBufferAccessor.GetNumVertices() / 4;++i)
    // 	{
    // 		positions.push_back(vertexBufferAccessor.GetPosition<Mathematics::APointf>(i));
    // 		sizes.push_back(firstFloatRandomDistribution(generator));
    // 	}
    //
    // 	ParticlesSharedPtr firstParticles(new Particles(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), 4, positions, sizes,1.01f));
    //
    // 	firstParticles->GenerateParticles(ConstCameraSharedPtr(new Camera));
    //
    // 	SaveVisual::SaveToFile(*firstParticles, SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesParticlesSave.trv"));
    //
    // 	LoadVisual secondLoadVisual(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesParticlesSave.trv"));
    //
    // 	VisualTest secondVisualTest(secondLoadVisual.GetPrimitiveType(),
    // 		                        secondLoadVisual.GetVertexFormat(),
    // 								secondLoadVisual.GetVertexBuffer(),
    // 								secondLoadVisual.GetIndexBuffer());
    //
    // 	ASSERT_ENUM_EQUAL(firstParticles->GetPrimitiveType(), secondLoadVisual.GetPrimitiveType());
    //
    // 	VertexBufferSharedPtr firstBuffer = firstParticles->GetVertexBuffer();
    // 	VertexBufferSharedPtr secondBuffer = secondLoadVisual.GetVertexBuffer();
    //
    // 	IndexBufferSharedPtr thirdBuffer = firstParticles->GetIndexBuffer();
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
    // 	VertexFormatSharedPtr firstVertexFormat = firstParticles->GetVertexFormat();
    // 	VertexFormatSharedPtr secondVertexFormat = secondLoadVisual.GetVertexFormat();
    //
    // 	ASSERT_EQUAL(firstVertexFormat->GetNumAttributes(), secondVertexFormat->GetNumAttributes());
    //
    // 	for (int i = 0; i < firstVertexFormat->GetNumAttributes(); ++i)
    // 	{
    // 		ASSERT_EQUAL(firstVertexFormat->GetStreamIndex(i), secondVertexFormat->GetStreamIndex(i));
    // 		ASSERT_EQUAL(firstVertexFormat->GetOffset(i), secondVertexFormat->GetOffset(i));
    // 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeType(i), secondVertexFormat->GetAttributeType(i));
    // 		ASSERT_ENUM_EQUAL(firstVertexFormat->GetAttributeUsage(i), secondVertexFormat->GetAttributeUsage(i));
    // 		ASSERT_EQUAL(firstVertexFormat->GetUsageIndex(i), secondVertexFormat->GetUsageIndex(i));
    // 	}
    //
    // 	ASSERT_EQUAL(firstVertexFormat->GetStride(), secondVertexFormat->GetStride());
}
