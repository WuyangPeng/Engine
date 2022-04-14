// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 09:40)

#include "ParticleControllerTesting.h"
#include "ParticleControllerTest.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/SceneGraph/Particles.h"
#include "Rendering/Controllers/Controller.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"


#include <random>
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ParticleControllerTesting) 

void Rendering::ParticleControllerTesting
	::MainTest()
{
	CoreTools::InitTerm::ExecuteInitializers();

	CameraManager::Create();
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	RendererManager::Destroy();
	CameraManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}
#include SYSTEM_WARNING_DISABLE(26440)
void Rendering::ParticleControllerTesting
	::InitTest()
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
// 	ParticlesSharedPtr firstParticles(new Particles(loadVisual.GetVertexFormat(),loadVisual.GetVertexBuffer(),4, positions, sizes,1.01f));
// 
// 	firstParticles->GenerateParticles(ConstCameraSharedPtr(new Camera));
// 	
// 	ControllerInterfaceSharedPtr controllerTest(new ParticleControllerTest);
// 
// 	ASSERT_EQUAL_NULL_PTR(controllerTest->GetControllerObject());
// 	
// 	firstParticles->AttachController(controllerTest);
// 
// 	ASSERT_EQUAL(controllerTest->GetControllerObject(), firstParticles.GetData());
// 
// 	firstParticles->DetachController(controllerTest);
// 
// 	ASSERT_EQUAL_NULL_PTR(controllerTest->GetControllerObject());
// 
// 	ParticleControllerTest* controllerTestPtr =	CoreTools::PolymorphicCast<ParticleControllerTest>(controllerTest.GetData());
// 
// 	controllerTestPtr->SetRepeat(ControllerRepeatType::Clamp);
// 	controllerTestPtr->SetTime(0.1,0.3);
// 	controllerTestPtr->SetPhase(1.5);
// 	controllerTestPtr->SetFrequency(2.0);
// 	controllerTestPtr->SetActive(true);
// 	controllerTestPtr->SetApplicationTime(5.0);
// 
// 	ASSERT_EQUAL(controllerTestPtr->GetRepeat(),ControllerRepeatType::Clamp);
// 	ASSERT_APPROXIMATE(controllerTestPtr->GetMinTime(),0.1,1e-10);
// 	ASSERT_APPROXIMATE(controllerTestPtr->GetMaxTime(),0.3,1e-10);
// 	ASSERT_APPROXIMATE(controllerTestPtr->GetPhase(),1.5,1e-10);
// 	ASSERT_APPROXIMATE(controllerTestPtr->GetFrequency(),2.0,1e-10);
// 	ASSERT_TRUE(controllerTestPtr->IsActive());
// 	ASSERT_APPROXIMATE(controllerTestPtr->GetApplicationTime(),5.0,1e-10);
}

void Rendering::ParticleControllerTesting
	::CopyTest()
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
// 	ParticlesSharedPtr firstParticles(new Particles(loadVisual.GetVertexFormat(),loadVisual.GetVertexBuffer(),4, positions, sizes,1.01f));
// 
// 	firstParticles->GenerateParticles(ConstCameraSharedPtr(new Camera));
// 	
// 	ControllerInterfaceSharedPtr firstControllerTest(new ParticleControllerTest);
// 	firstParticles->AttachController(firstControllerTest);
// 
// 	ParticleControllerTest* firstControllerTestPtr = CoreTools::PolymorphicCast<ParticleControllerTest>(firstControllerTest.GetData());
// 
// 	firstControllerTestPtr->SetRepeat(ControllerRepeatType::Clamp);
// 	firstControllerTestPtr->SetTime(0.1,0.3);
// 	firstControllerTestPtr->SetPhase(1.5);
// 	firstControllerTestPtr->SetFrequency(2.0);
// 	firstControllerTestPtr->SetActive(true);
// 	firstControllerTestPtr->SetApplicationTime(5.0);
// 
// 	ControllerInterfaceSharedPtr secondControllerTest(firstControllerTest->Clone());
// 
// 	ASSERT_EQUAL(secondControllerTest->GetControllerObject(), firstParticles.GetData());
// 
// 	ASSERT_EQUAL(firstControllerTestPtr->GetRepeat(),ControllerRepeatType::Clamp);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetMinTime(),0.1,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetMaxTime(),0.3,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetPhase(),1.5,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetFrequency(),2.0,1e-10);
// 	ASSERT_TRUE(firstControllerTestPtr->IsActive());
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetApplicationTime(),5.0,1e-10);
// 
// 	ParticleControllerTest* secondControllerTestPtr = CoreTools::PolymorphicCast<ParticleControllerTest>(secondControllerTest.GetData());
// 
// 	ASSERT_EQUAL(secondControllerTestPtr->GetRepeat(),ControllerRepeatType::Clamp);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetMinTime(),0.1,1e-10);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetMaxTime(),0.3,1e-10);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetPhase(),1.5,1e-10);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetFrequency(),2.0,1e-10);
// 	ASSERT_TRUE(secondControllerTestPtr->IsActive());
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetApplicationTime(),5.0,1e-10);
// 
// 	firstControllerTestPtr->SetRepeat(ControllerRepeatType::ClampCycle);
// 	firstControllerTestPtr->SetTime(1.1,1.3);
// 	firstControllerTestPtr->SetPhase(2.5);
// 	firstControllerTestPtr->SetFrequency(3.0);
// 	firstControllerTestPtr->SetActive(false);
// 	firstControllerTestPtr->SetApplicationTime(15.0);
// 
// 	ASSERT_EQUAL(firstControllerTestPtr->GetRepeat(), ControllerRepeatType::ClampCycle);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetMinTime(),1.1,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetMaxTime(),1.3,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetPhase(),2.5,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetFrequency(),3.0,1e-10);
// 	ASSERT_FALSE(firstControllerTestPtr->IsActive());
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetApplicationTime(),15.0,1e-10);
// 
// 	ASSERT_EQUAL(secondControllerTestPtr->GetRepeat(),ControllerRepeatType::Clamp);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetMinTime(),0.1,1e-10);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetMaxTime(),0.3,1e-10);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetPhase(),1.5,1e-10);
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetFrequency(),2.0,1e-10);
// 	ASSERT_TRUE(secondControllerTestPtr->IsActive());
// 	ASSERT_APPROXIMATE(secondControllerTestPtr->GetApplicationTime(),5.0,1e-10);
}

void Rendering::ParticleControllerTesting
	::UpdateTest()
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
// 	ParticlesSharedPtr firstParticles(new Particles(loadVisual.GetVertexFormat(),loadVisual.GetVertexBuffer(),4, positions, sizes,1.01f));
// 
// 	firstParticles->GenerateParticles(ConstCameraSharedPtr(new Camera));
// 	
// 	ControllerInterfaceSharedPtr firstControllerTest(new ParticleControllerTest);
// 
// 	ParticleControllerTest* firstControllerTestPtr = CoreTools::PolymorphicCast<ParticleControllerTest>(firstControllerTest.GetData());
// 
// 	firstParticles->AttachController(firstControllerTest);
// 
// 	firstControllerTestPtr->SetRepeat(ControllerRepeatType::Clamp);
// 	firstControllerTestPtr->SetTime(4.1,12.3);
// 	firstControllerTestPtr->SetPhase(1.5);
// 	firstControllerTestPtr->SetFrequency(2.0);
// 	firstControllerTestPtr->SetActive(true);
// 	firstControllerTestPtr->SetApplicationTime(5.0);
// 
// 	double controlTime = 2.0 * 5.0 + 1.5;
// 
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(5.0),controlTime,1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(6.0),firstControllerTestPtr->GetMaxTime(),1e-10);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(1.0),firstControllerTestPtr->GetMinTime(),1e-10);
// 
// 	firstControllerTestPtr->SetRepeat(ControllerRepeatType::Wrap);
// 
// 	double timeRange = firstControllerTestPtr->GetMaxTime() - firstControllerTestPtr->GetMinTime();
// 	double multiples = (controlTime - firstControllerTestPtr->GetMinTime()) / timeRange;
// 	double integerTime = Mathematics::Mathd::Floor(multiples);
// 	double fractionTime = multiples - integerTime;
// 
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(5.0), firstControllerTestPtr->GetMinTime() + fractionTime * timeRange,1e-10);
// 
// 	firstControllerTestPtr->SetRepeat(ControllerRepeatType::ClampCycle);
// 
// 	if (static_cast<int>(integerTime) & 1)
// 	{
//  	   ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(5.0),firstControllerTestPtr->GetMaxTime() - fractionTime * timeRange,1e-10); 
// 	}
// 	else
// 	{
//  	   ASSERT_APPROXIMATE(firstControllerTestPtr->GetControlTime(5.0),firstControllerTestPtr->GetMinTime() + fractionTime * timeRange,1e-10); 
// 	}
// 	 
// 	int numParticles = firstControllerTestPtr->GetNumParticles();
// 
// 	ASSERT_EQUAL(numParticles, firstParticles->GetNumParticles());
// 
// 	firstControllerTestPtr->SetSystemLinearSpeed(1.0f);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetSystemLinearSpeed(), 1.0f, 1e-8f);
// 
// 	firstControllerTestPtr->SetSystemAngularSpeed(1.1f);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetSystemAngularSpeed(), 1.1f, 1e-8f);
//  
// 	firstControllerTestPtr->SetSystemLinearAxis(Mathematics::AVectorf::sm_UnitX);
// 	typedef bool(*Function)(const Mathematics::AVectorf& lhs, const Mathematics::AVectorf& rhs,const float epsilon);
// 	
// 	Function function = Mathematics::Approximate<float>;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, firstControllerTestPtr->GetSystemLinearAxis(),Mathematics::AVectorf::sm_UnitX,1e-8f);
// 
// 	firstControllerTestPtr->SetSystemAngularAxis(Mathematics::AVectorf::sm_UnitY);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, firstControllerTestPtr->GetSystemAngularAxis(),
// 		                            Mathematics::AVectorf::sm_UnitY,1e-8f); 
// 
// 	firstControllerTestPtr->SetSystemSizeChange(1.2f);
// 	ASSERT_APPROXIMATE(firstControllerTestPtr->GetSystemSizeChange(), 1.2f, 1e-8f); 
// 
// 	for (int i = 0; i < numParticles;++i)
// 	{
// 		firstControllerTestPtr->SetParticleLinearSpeed(i, static_cast<float>(i * 0.2f));
// 		firstControllerTestPtr->SetParticleSizeChange(i, static_cast<float>(i * 0.1f));
// 		firstControllerTestPtr->SetParticleLinearAxis(i, Mathematics::AVectorf::sm_UnitX);	
// 	}
// 
// 	for (int i = 0; i < numParticles; ++i)
// 	{
// 		ASSERT_APPROXIMATE(firstControllerTestPtr->GetParticleLinearSpeed(i), static_cast<float>(i * 0.2f), 1e-8f);
// 		ASSERT_APPROXIMATE(firstControllerTestPtr->GetParticleSizeChange(i), static_cast<float>(i * 0.1f), 1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(function, firstControllerTestPtr->GetParticleLinearAxis(i), Mathematics::AVectorf::sm_UnitX, 1e-8f);
// 		 
// 	} 
// 
// 	ControllerInterfaceSharedPtr thirdPolypoint = firstParticles->Clone();
// 	ParticlesSharedPtr fourthPolypoint = thirdPolypoint.PolymorphicDowncastObjectSharedPtr<ParticlesSharedPtr>();
// 
// 	ControllerInterfaceSharedPtr secondControllerTest = fourthPolypoint->GetController(0);
// 	ParticleControllerTest* secondControllerTestPtr = CoreTools::PolymorphicCast<ParticleControllerTest>(secondControllerTest.GetData());
// 	thirdPolypoint->AttachController(secondControllerTest);
// 
// 	for (int i = 0; i < numParticles; ++i)
// 	{
// 		ASSERT_APPROXIMATE(firstControllerTestPtr->GetParticleLinearSpeed(i), secondControllerTestPtr->GetParticleLinearSpeed(i), 1e-8f);
// 		ASSERT_APPROXIMATE(firstControllerTestPtr->GetParticleSizeChange(i),secondControllerTestPtr->GetParticleSizeChange(i), 1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(function, firstControllerTestPtr->GetParticleLinearAxis(i),secondControllerTestPtr->GetParticleLinearAxis(i), 1e-8f);
// 
// 	}
// 
// 	firstParticles->Update(1.0);	 
//  
// 	float ctrlTime = static_cast<float>(secondControllerTestPtr->GetControlTime(1.0));
// 
// 	float dSize = ctrlTime * secondControllerTestPtr->GetSystemSizeChange();
// 	fourthPolypoint->SetSizeAdjust(fourthPolypoint->GetSizeAdjust() + dSize);
// 	if (fourthPolypoint->GetSizeAdjust() < 0.0f)
// 	{
// 		fourthPolypoint->SetSizeAdjust(0.0f);
// 	}
// 
// 	float distance1 = ctrlTime * secondControllerTestPtr->GetSystemLinearSpeed();
// 	Mathematics::AVectorf deltaTrn1 = distance1 * secondControllerTestPtr->GetSystemLinearAxis();
// 	Transform localTransform = fourthPolypoint->GetLocalTransform();
// 	Mathematics::APointf translate = localTransform.GetTranslate() + deltaTrn1;
// 	localTransform.SetTranslate(translate);
// 
// 	float angle = ctrlTime * secondControllerTestPtr->GetSystemAngularSpeed();
// 	Mathematics::Matrixf deltaRot(secondControllerTestPtr->GetSystemAngularAxis(), angle);
// 	Mathematics::Matrixf rotate = deltaRot * localTransform.GetRotate();
// 	localTransform.SetRotate(rotate);
// 
// 	typedef bool(*TransformFunction)(const Transform& lhs, const Transform& rhs,const float epsilon);
// 
// 	TransformFunction transformFunction = Approximate;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(transformFunction, localTransform, firstParticles->GetLocalTransform(), 1e-8f);
//  
// 	typedef bool(*APointFunction)(const Mathematics::APointf& lhs, const Mathematics::APointf& rhs,const float epsilon);
// 
// 	APointFunction aPointFunction = Mathematics::Approximate<float>;
// 
// 	int numActive = firstParticles->GetNumActive();
// 	for (int i = 0; i < numActive; ++i)
// 	{
// 		Mathematics::APointf position = fourthPolypoint->GetPosition(i);
// 		float size = fourthPolypoint->GetSize(i);
// 
// 		float dSize1 = ctrlTime * secondControllerTestPtr->GetParticleSizeChange(i);
// 		size += dSize1;
// 		float distance = ctrlTime * secondControllerTestPtr->GetParticleLinearSpeed(i);
// 		Mathematics::AVectorf deltaTrn = distance * secondControllerTestPtr->GetParticleLinearAxis(i);
// 		position += deltaTrn;
// 		
// 		ASSERT_APPROXIMATE_USE_FUNCTION(aPointFunction, firstParticles->GetPosition(i), position, 1e-8f);
// 		ASSERT_APPROXIMATE(firstParticles->GetSize(i), size, 1e-8f);
// 	}
}

void Rendering::ParticleControllerTesting
	::StreamTest()
{
// 	CoreTools::OutTopLevel outTopLevel;
// 
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
// 
// 	CoreTools::ObjectInterfaceSharedPtr firstControlledObjectTest(firstParticles.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
// 
// 	Particles* secondControlledObjectTest =	CoreTools::PolymorphicCast<Particles>(firstControlledObjectTest.GetData());
// 
// 	firstControlledObjectTest->SetUniqueID(1);
// 
// 	ControllerInterfaceSharedPtr firstControllerTest(new ParticleControllerTest);
// 	secondControlledObjectTest->AttachController(firstControllerTest);
// 
// 	firstControllerTest->SetUniqueID(2);
// 
// 	ParticleControllerTest* secondControllerTest =	CoreTools::PolymorphicCast<ParticleControllerTest>(firstControllerTest.GetData());
// 
// 	secondControllerTest->SetRepeat(ControllerRepeatType::Clamp);
// 	secondControllerTest->SetTime(0.1,0.3);
// 	secondControllerTest->SetPhase(1.5);
// 	secondControllerTest->SetFrequency(2.0);
// 	secondControllerTest->SetActive(true);
// 	secondControllerTest->SetApplicationTime(5.0);
// 
// 	secondControllerTest->SetSystemLinearSpeed(1.0f);	 
// 	secondControllerTest->SetSystemAngularSpeed(1.1f);	 
// 	secondControllerTest->SetSystemLinearAxis(Mathematics::AVectorf::sm_UnitX);
// 	secondControllerTest->SetSystemAngularAxis(Mathematics::AVectorf::sm_UnitY);	
// 
// 	int numParticles = secondControllerTest->GetNumParticles();
// 
// 	secondControllerTest->SetSystemLinearSpeed(1.0f);
// 	secondControllerTest->SetSystemAngularSpeed(1.1f);
// 	secondControllerTest->SetSystemLinearAxis(Mathematics::AVectorf::sm_UnitX); 
// 	secondControllerTest->SetSystemAngularAxis(Mathematics::AVectorf::sm_UnitY);
// 	secondControllerTest->SetSystemSizeChange(1.2f); 
// 
// 	for (int i = 0; i < numParticles;++i)
// 	{
// 		secondControllerTest->SetParticleLinearSpeed(i, static_cast<float>(i * 0.2f));
// 		secondControllerTest->SetParticleSizeChange(i, static_cast<float>(i * 0.1f));
// 		secondControllerTest->SetParticleLinearAxis(i, Mathematics::AVectorf::sm_UnitX);
// 	}
// 
// 	outTopLevel.Insert(firstControlledObjectTest);
//         
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =  outStream.GetBufferOutStreamInformation();
//         
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
//         
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	ParticlesSharedPtr  thirdControlledObjectTest =	inTopLevel[0].PolymorphicDowncastObjectSharedPtr<ParticlesSharedPtr>();
// 
// 	ControllerInterfaceSharedPtr thirdControllerTest = thirdControlledObjectTest->GetController(0);
// 
// 	ParticleControllerTest* fourthControlledTest =	CoreTools::PolymorphicCast<ParticleControllerTest>(thirdControllerTest.GetData());
// 
// 	ASSERT_EQUAL(fourthControlledTest->GetRepeat(), secondControllerTest->GetRepeat());
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetMinTime(),
// 	                   secondControllerTest-> GetMinTime(),1e-10);
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetMaxTime(),
// 	                   secondControllerTest-> GetMaxTime(),1e-10);
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetPhase(),
// 	                   secondControllerTest->GetPhase(),1e-10);
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetFrequency(),secondControllerTest-> GetFrequency(),1e-10);
// 	ASSERT_EQUAL(fourthControlledTest->IsActive(),secondControllerTest->IsActive());
// 
// 	ASSERT_EQUAL(fourthControlledTest->GetControllerObject(),thirdControlledObjectTest.GetData());
// 
// 	ASSERT_EQUAL(fourthControlledTest->GetNumParticles(), secondControllerTest->GetNumParticles());
// 
// 	typedef bool(*Function)(const Mathematics::AVectorf& lhs, const Mathematics::AVectorf& rhs,const float epsilon);
// 
// 	Function function = Mathematics::Approximate<float>;
// 
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetSystemLinearSpeed(), secondControllerTest->GetSystemLinearSpeed(), 1e-8f);
//  
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetSystemAngularSpeed(), secondControllerTest->GetSystemAngularSpeed(), 1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, fourthControlledTest->GetSystemLinearAxis(),secondControllerTest->GetSystemLinearAxis(),1e-8f); 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(function, fourthControlledTest->GetSystemAngularAxis(), secondControllerTest->GetSystemAngularAxis(),1e-8f);
// 	ASSERT_APPROXIMATE(fourthControlledTest->GetSystemSizeChange(), secondControllerTest->GetSystemSizeChange(), 1e-8f);
// 
// 	for (int i = 0; i < numParticles; ++i)
// 	{
// 		ASSERT_APPROXIMATE(fourthControlledTest->GetParticleLinearSpeed(i), secondControllerTest->GetParticleLinearSpeed(i), 1e-8f);
// 		ASSERT_APPROXIMATE(fourthControlledTest->GetParticleSizeChange(i), secondControllerTest->GetParticleSizeChange(i), 1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(function, fourthControlledTest->GetParticleLinearAxis(i), secondControllerTest->GetParticleLinearAxis(i), 1e-8f);
// 	} 	
}
