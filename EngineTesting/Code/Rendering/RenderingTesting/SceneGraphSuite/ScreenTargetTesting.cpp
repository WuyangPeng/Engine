// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 11:23)

#include "ScreenTargetTesting.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Rendering/SceneGraph/ScreenTarget.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Shaders/ShaderManager.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"

#include <vector>

using std::vector;
using std::swap;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ScreenTargetTesting) 

void Rendering::ScreenTargetTesting
	::MainTest()
{
	CoreTools::InitTerm::ExecuteInitializers();

	CameraManager::Create();
	RendererManager::Create();
	ShaderManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(CameraTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TrianglesMeshTest);

	ShaderManager::Destroy();
	RendererManager::Destroy();
	CameraManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::ScreenTargetTesting
	::CameraTest()
{
// 	CameraSharedPtr firstCamera = ScreenTarget::CreateCamera();
// 
// 	ASSERT_TRUE(Approximate(firstCamera->GetPosition(), Mathematics::APointf::sm_Origin, 1e-8f));
// 	ASSERT_TRUE(Approximate(firstCamera->GetDirectionVector(), Mathematics::AVectorf::sm_UnitZ, 1e-8f));
// 	ASSERT_TRUE(Approximate(firstCamera->GetUpVector(), Mathematics::AVectorf::sm_UnitY, 1e-8f));
// 	ASSERT_TRUE(Approximate(firstCamera->GetRightVector(), Mathematics::AVectorf::sm_UnitX, 1e-8f));
//  
// 	ASSERT_APPROXIMATE(firstCamera->GetDirectionMin(), 0.0f, 1e-8f);
// 	ASSERT_APPROXIMATE(firstCamera->GetDirectionMax(), 1.0f, 1e-8f);
// 	ASSERT_APPROXIMATE(firstCamera->GetUpMin(), 0.0f, 1e-8f);
// 	ASSERT_APPROXIMATE(firstCamera->GetUpMax(), 1.0f, 1e-8f);
// 	ASSERT_APPROXIMATE(firstCamera->GetRightMin(), 0.0f, 1e-8f);
// 	ASSERT_APPROXIMATE(firstCamera->GetRightMax(), 1.0f, 1e-8f);	 
}

void Rendering::ScreenTargetTesting
	::TrianglesMeshTest()
{
		// VertexFormat
// 	vector<VertexFormatType> firstVertexFormatType{	VertexFormatType(VertexFormatFlags::AttributeType::Float3,VertexFormatFlags::AttributeUsage::Position, 0),
// 													VertexFormatType(VertexFormatFlags::AttributeType::Float2,VertexFormatFlags::AttributeUsage::TextureCoord, 0) };
// 
// 	VertexFormatSharedPtr firstVertexFormat = VertexFormat::Create(firstVertexFormatType);
// 
// 	SHADER_MANAGE_SINGLETON.SetVertexProfile(ShaderFlags::VertexShaderProfile::ARBVP1);
// 
// 	TrianglesMeshSharedPtr firstTrianglesMesh =
// 		ScreenTarget::CreateRectangle(firstVertexFormat, 50, 50, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
// 
// 	VertexBufferAccessor firstVertexBufferAccessor(firstVertexFormat.PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>(),firstTrianglesMesh->GetConstVertexBuffer());
// 
// 
// 	// Œ∆¿Ì≤‚ ‘
// 	Mathematics::Vector2Df firstTextureCoord = firstVertexBufferAccessor.GetTextureCoord<Mathematics::Vector2Df>(0, 0);
// 	Mathematics::Vector2Df secondTextureCoord = firstVertexBufferAccessor.GetTextureCoord<Mathematics::Vector2Df>(0, 1);
// 	Mathematics::Vector2Df thirdTextureCoord = firstVertexBufferAccessor.GetTextureCoord<Mathematics::Vector2Df>(0, 2);
// 	Mathematics::Vector2Df fourthTextureCoord = firstVertexBufferAccessor.GetTextureCoord<Mathematics::Vector2Df>(0, 3);
// 
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(firstTextureCoord, Mathematics::Vector2Df(0.0f, 0.0f), 1e-8f));
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(secondTextureCoord, Mathematics::Vector2Df(1.0f, 0.0f), 1e-8f));
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(thirdTextureCoord, Mathematics::Vector2Df(1.0f, 1.0f), 1e-8f));
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(fourthTextureCoord, Mathematics::Vector2Df(0.0f, 1.0f), 1e-8f));
// 
// 	vector<Mathematics::Vector2Df> screenTargetTextureCoords = ScreenTarget::CreateTextureCoords();
// 
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(firstTextureCoord, screenTargetTextureCoords[0], 1e-8f));
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(secondTextureCoord, screenTargetTextureCoords[1], 1e-8f));
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(thirdTextureCoord, screenTargetTextureCoords[2], 1e-8f));
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(fourthTextureCoord, screenTargetTextureCoords[3], 1e-8f));
// 
// 	// Œª÷√≤‚ ‘
// 	Mathematics::APointf firstPosition = firstVertexBufferAccessor.GetPosition<Mathematics::APointf>(0);
// 	Mathematics::APointf secondPosition = firstVertexBufferAccessor.GetPosition<Mathematics::APointf>(1);
// 	Mathematics::APointf thirdPosition = firstVertexBufferAccessor.GetPosition<Mathematics::APointf>(2);
// 	Mathematics::APointf fourthPosition = firstVertexBufferAccessor.GetPosition<Mathematics::APointf>(3);
// 
// 	ASSERT_TRUE(Approximate(firstPosition, Mathematics::APointf(0.0f, 0.0f, 0.0f), 1e-8f));
// 	ASSERT_TRUE(Approximate(secondPosition, Mathematics::APointf(1.0f, 0.0f, 0.0f), 1e-8f));
// 	ASSERT_TRUE(Approximate(thirdPosition, Mathematics::APointf(1.0f, 1.0f, 0.0f), 1e-8f));
// 	ASSERT_TRUE(Approximate(fourthPosition, Mathematics::APointf(0.0f, 1.0f, 0.0f), 1e-8f));
// 
// 	vector<Mathematics::APointf> screenTargetPositions = ScreenTarget::CreatePositions(50, 50, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
// 	
// 	ASSERT_TRUE(Approximate(Mathematics::APointf(0.0f, 0.0f, 0.0f), screenTargetPositions[0], 1e-8f));
// 	ASSERT_TRUE(Approximate(Mathematics::APointf(1.0f, 0.0f, 0.0f), screenTargetPositions[1], 1e-8f));
// 	ASSERT_TRUE(Approximate(Mathematics::APointf(1.0f, 1.0f, 0.0f), screenTargetPositions[2], 1e-8f));
// 	ASSERT_TRUE(Approximate(Mathematics::APointf(0.0f, 1.0f, 0.0f), screenTargetPositions[3], 1e-8f));
// 		 
// 	SHADER_MANAGE_SINGLETON.SetVertexProfile(ShaderFlags::VertexShaderProfile::VS11);
// 
// 	TrianglesMeshSharedPtr secondTrianglesMesh =	ScreenTarget::CreateRectangle(firstVertexFormat, 50, 50, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
// 
// 	VertexBufferAccessor secondVertexBufferAccessor(firstVertexFormat.PolymorphicDowncastConstObjectSharedPtr<ConstVertexFormatSharedPtr>(),secondTrianglesMesh->GetConstVertexBuffer());
// 
// 	// Œ∆¿Ì≤‚ ‘
// 	firstTextureCoord = secondVertexBufferAccessor.GetTextureCoord<Mathematics::Vector2Df>(0, 0);
// 	secondTextureCoord = secondVertexBufferAccessor.GetTextureCoord<Mathematics::Vector2Df>(0, 1);
// 	thirdTextureCoord = secondVertexBufferAccessor.GetTextureCoord<Mathematics::Vector2Df>(0, 2);
// 	fourthTextureCoord = secondVertexBufferAccessor.GetTextureCoord<Mathematics::Vector2Df>(0, 3);
// 
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(firstTextureCoord, Mathematics::Vector2Df(0.0f, 1.0f), 1e-8f));
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(secondTextureCoord, Mathematics::Vector2Df(1.0f, 1.0f), 1e-8f));
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(thirdTextureCoord, Mathematics::Vector2Df(1.0f, 0.0f), 1e-8f));
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(fourthTextureCoord, Mathematics::Vector2Df(0.0f, 0.0f), 1e-8f));
// 
// 	screenTargetTextureCoords =	ScreenTarget::CreateTextureCoords();
// 
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(firstTextureCoord, screenTargetTextureCoords[0], 1e-8f));
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(secondTextureCoord, screenTargetTextureCoords[1], 1e-8f));
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(thirdTextureCoord, screenTargetTextureCoords[2], 1e-8f));
// 	ASSERT_TRUE(Mathematics::Vector2DToolsf::Approximate(fourthTextureCoord, screenTargetTextureCoords[3], 1e-8f));
// 
// 	// Œª÷√≤‚ ‘
// 	firstPosition = secondVertexBufferAccessor.GetPosition<Mathematics::APointf>(0);
// 	secondPosition = secondVertexBufferAccessor.GetPosition<Mathematics::APointf>(1);
// 	thirdPosition = secondVertexBufferAccessor.GetPosition<Mathematics::APointf>(2);
// 	fourthPosition = secondVertexBufferAccessor.GetPosition<Mathematics::APointf>(3);
// 
// 	float dx = 0.5f / static_cast<float>(50 - 1);
// 	float dy = 0.5f / static_cast<float>(50 - 1);
// 	float xMin = -dx;
// 	float xMax = 1.0f - dx;
// 	float yMin = dy;
// 	float yMax = 1.0f + dy;
// 
// 	ASSERT_TRUE(Approximate(firstPosition, Mathematics::APointf(xMin, yMin, 0.0f), 1e-8f));
// 	ASSERT_TRUE(Approximate(secondPosition, Mathematics::APointf(xMax, yMin, 0.0f), 1e-8f));
// 	ASSERT_TRUE(Approximate(thirdPosition, Mathematics::APointf(xMax, yMax, 0.0f), 1e-8f));
// 	ASSERT_TRUE(Approximate(fourthPosition, Mathematics::APointf(xMin, yMax, 0.0f), 1e-8f));
// 
// 	screenTargetPositions =	ScreenTarget::CreatePositions(50, 50, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
// 
// 	ASSERT_TRUE(Approximate(firstPosition, screenTargetPositions[0], 1e-8f));
// 	ASSERT_TRUE(Approximate(secondPosition, screenTargetPositions[1], 1e-8f));
// 	ASSERT_TRUE(Approximate(thirdPosition, screenTargetPositions[2], 1e-8f));
// 	ASSERT_TRUE(Approximate(fourthPosition, screenTargetPositions[3], 1e-8f));
}

