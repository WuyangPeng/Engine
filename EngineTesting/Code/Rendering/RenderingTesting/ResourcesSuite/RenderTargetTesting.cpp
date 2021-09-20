// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 17:31)

#include "RenderTargetTesting.h"
#include "Rendering/Resources/RenderTarget.h"
#include "Rendering/Renderers/RendererManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
 
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"





UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, RenderTargetTesting) 

void Rendering::RenderTargetTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	RendererManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::RenderTargetTesting
	::BaseTest()
{
	 RenderTarget firstRenderTarget(5,TextureFormat::A8B8G8R8,20,22,false,true);

	 ASSERT_EQUAL(firstRenderTarget.GetNumTargets(),5);
	 ASSERT_ENUM_EQUAL(firstRenderTarget.GetFormat(),TextureFormat::A8B8G8R8);
	 ASSERT_EQUAL(firstRenderTarget.GetWidth(),20);
	 ASSERT_EQUAL(firstRenderTarget.GetHeight(),22);

	 ASSERT_FALSE(firstRenderTarget.HasMipmaps());
	 ASSERT_TRUE(firstRenderTarget.HasDepthStencil());

// 	 ASSERT_FALSE(firstRenderTarget.GetDepthStencilTexture().IsNullPtr());
// 
// 	 for (int i = 0;i < 5;++i)
// 	 {
// 		 ASSERT_FALSE(firstRenderTarget.GetColorTexture(i).IsNullPtr());
// 	 }
}

void Rendering::RenderTargetTesting
	::StreamTest()
{
// 	RenderTargetSharedPtr firstRenderTarget(new RenderTarget(5,TextureFormat::A8B8G8R8,20,22,false,true));
// 
// 	CoreTools::OutTopLevel outTopLevel;
// 	CoreTools::ObjectInterfaceSharedPtr firstBuffer(firstRenderTarget.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
// 
// 	outTopLevel.Insert(firstBuffer);
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
// 
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
// 
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	RenderTargetSharedPtr secondRenderTarget = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<RenderTargetSharedPtr>();
// 
// 	ASSERT_EQUAL(firstRenderTarget->GetNumTargets(),secondRenderTarget->GetNumTargets());
// 	ASSERT_ENUM_EQUAL(firstRenderTarget->GetFormat(),secondRenderTarget->GetFormat());
// 	ASSERT_EQUAL(firstRenderTarget->GetWidth(),secondRenderTarget->GetWidth());
// 	ASSERT_EQUAL(firstRenderTarget->GetHeight(),secondRenderTarget->GetHeight());
// 
// 	ASSERT_EQUAL(firstRenderTarget->HasMipmaps(),secondRenderTarget->HasMipmaps());
// 	ASSERT_EQUAL(firstRenderTarget->HasDepthStencil(),secondRenderTarget->HasDepthStencil());
// 
// 	ASSERT_FALSE(secondRenderTarget->GetDepthStencilTexture().IsNullPtr());
// 
// 	for (int i = 0;i < 5;++i)
// 	{
// 		ASSERT_FALSE(secondRenderTarget->GetColorTexture(i).IsNullPtr());
// 	}
}
 