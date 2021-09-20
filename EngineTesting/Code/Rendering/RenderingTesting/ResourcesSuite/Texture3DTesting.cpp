// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/03 17:35)

#include "Texture3DTesting.h"
#include "Mathematics/Base/BitHacksDetail.h"
#include "Rendering/Resources/Texture3D.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/LoadTexture.h"
#include "Rendering/Resources/SaveTexture.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"





#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/FileManager/FileManagerHelper.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, Texture3DTesting) 

void Rendering::Texture3DTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MipmapsTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FileTest);

	RendererManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::Texture3DTesting
	::BaseTest()
{
	 Texture3DSharedPtr firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture3D.trt"));

//	ASSERT_FALSE(firstTexture3D.IsNullPtr());

	ASSERT_ENUM_EQUAL(TextureFormat::R8G8B8, firstTexture3D->GetFormat());
	ASSERT_ENUM_EQUAL(TextureFlags::Texture3D, firstTexture3D->GetTextureType());
	ASSERT_ENUM_EQUAL(BufferUsage::Texture, firstTexture3D->GetUsage());
	ASSERT_EQUAL(1, firstTexture3D->GetNumLevels());

	ASSERT_EQUAL(3, firstTexture3D->GetNumDimensions());
	ASSERT_EQUAL(16, firstTexture3D->GetDimension(0,0));
	ASSERT_EQUAL(12, firstTexture3D->GetDimension(1,0));
	ASSERT_EQUAL(8, firstTexture3D->GetDimension(2,0));
	ASSERT_EQUAL(16 * 12 * 8 * firstTexture3D->GetPixelSize(), firstTexture3D->GetNumLevelBytes(0));
	ASSERT_EQUAL(16 * 12 * 8 *firstTexture3D->GetPixelSize(), firstTexture3D->GetNumTotalBytes());
	ASSERT_EQUAL(0, firstTexture3D->GetLevelOffset(0));

	ASSERT_EQUAL(3, firstTexture3D->GetPixelSize());

	ASSERT_FALSE(firstTexture3D->IsCompressed());
	ASSERT_TRUE(firstTexture3D->IsMipmapable());

	for (int i = 0; i < TextureMaxUserFields;++i)
	{
		ASSERT_EQUAL(0, firstTexture3D->GetUserField(i));
		firstTexture3D->SetUserField(i, i);
	}

	for (int i = 0; i < TextureMaxUserFields; ++i)
	{
		ASSERT_EQUAL(i, firstTexture3D->GetUserField(i));	
	}

	ASSERT_EQUAL(16, firstTexture3D->GetWidth());
	ASSERT_EQUAL(12, firstTexture3D->GetHeight());
	ASSERT_EQUAL(8, firstTexture3D->GetThickness());

	ASSERT_UNEQUAL_NULL_PTR(firstTexture3D->GetTextureData(0));

// 	ConstTexture3DSharedPtr secondTexture3D = firstTexture3D.PolymorphicDowncastConstObjectSharedPtr<ConstTexture3DSharedPtr>();
// 
// 	ASSERT_UNEQUAL_NULL_PTR(secondTexture3D->GetTextureData(0));
// 
// 	ASSERT_EQUAL(firstTexture3D->GetTextureData(0)[firstTexture3D->GetNumLevelBytes(0) - 1],0x14);
}

void Rendering::Texture3DTesting
	::MipmapsTest()
{
	 Texture3DSharedPtr firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture3D.trt"));

	ASSERT_FALSE(firstTexture3D->HasMipmaps());

	firstTexture3D->GenerateMipmaps();

	ASSERT_TRUE(firstTexture3D->HasMipmaps());

	ASSERT_ENUM_EQUAL(TextureFormat::R8G8B8, firstTexture3D->GetFormat());
	ASSERT_ENUM_EQUAL(TextureFlags::Texture3D, firstTexture3D->GetTextureType());
	ASSERT_ENUM_EQUAL(BufferUsage::Texture, firstTexture3D->GetUsage());
	ASSERT_EQUAL(Mathematics::BitHacks::Log2OfPowerOfTwo(16) + 1,firstTexture3D->GetNumLevels());

	ASSERT_EQUAL(3, firstTexture3D->GetNumDimensions());

	int width = 16;
	int height = 12;
	int thickness = 8;
	int total = 0;

	for (int i = 0; i < firstTexture3D->GetNumLevels(); ++i)
	{
		ASSERT_EQUAL(width, firstTexture3D->GetDimension(0, i));
		ASSERT_EQUAL(height, firstTexture3D->GetDimension(1, i));
		ASSERT_EQUAL(thickness, firstTexture3D->GetDimension(2, i));
		ASSERT_EQUAL(width * height * thickness * firstTexture3D->GetPixelSize(), firstTexture3D->GetNumLevelBytes(i));
		ASSERT_EQUAL(total, firstTexture3D->GetLevelOffset(i));

		total += width * height * thickness * firstTexture3D->GetPixelSize();

		if(1 < width)
			width >>= 1;

		if(1 < height)
			height >>= 1;

		if(1 < thickness)
			thickness >>= 1;
	}

	ASSERT_EQUAL(total, firstTexture3D->GetNumTotalBytes());
	ASSERT_EQUAL(3, firstTexture3D->GetPixelSize());

	ASSERT_FALSE(firstTexture3D->IsCompressed());
	ASSERT_TRUE(firstTexture3D->IsMipmapable());

	ASSERT_EQUAL(16, firstTexture3D->GetWidth());
	ASSERT_EQUAL(12, firstTexture3D->GetHeight());
	ASSERT_EQUAL(8, firstTexture3D->GetThickness());
} 

void Rendering::Texture3DTesting
	::StreamTest()
{
	Texture3DSharedPtr firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture3D.trt"));
	firstTexture3D->GenerateMipmaps();

	for (int i = 0; i < TextureMaxUserFields; ++i)
	{	 
		firstTexture3D->SetUserField(i, i);
	}

// 	CoreTools::OutTopLevel outTopLevel;
// 	CoreTools::ObjectInterfaceSharedPtr firstBuffer(firstTexture3D.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
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
// 	Texture3DSharedPtr secondTexture3D = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<Texture3DSharedPtr>();
// 	 
// 	ASSERT_FALSE(secondTexture3D.IsNullPtr());
// 
// 	ASSERT_ENUM_EQUAL(firstTexture3D->GetFormat(), secondTexture3D->GetFormat());
// 	ASSERT_ENUM_EQUAL(firstTexture3D->GetTextureType(), secondTexture3D->GetTextureType());
// 	ASSERT_ENUM_EQUAL(firstTexture3D->GetUsage(), secondTexture3D->GetUsage());
// 	ASSERT_EQUAL(firstTexture3D->GetNumLevels(), secondTexture3D->GetNumLevels());
// 
// 	ASSERT_EQUAL(firstTexture3D->GetNumDimensions(), secondTexture3D->GetNumDimensions());
// 
// 	for (int i = 0; i < firstTexture3D->GetNumLevels(); ++i)
// 	{
// 		ASSERT_EQUAL(firstTexture3D->GetDimension(0, i), secondTexture3D->GetDimension(0, i));
// 		ASSERT_EQUAL(firstTexture3D->GetDimension(1, i), secondTexture3D->GetDimension(1, i));
// 		ASSERT_EQUAL(firstTexture3D->GetDimension(2, i), secondTexture3D->GetDimension(2, i));
// 		ASSERT_EQUAL(firstTexture3D->GetNumLevelBytes(i), secondTexture3D->GetNumLevelBytes(i));
// 		ASSERT_EQUAL(firstTexture3D->GetLevelOffset(i), secondTexture3D->GetLevelOffset(i));
// 	}
// 	
// 	ASSERT_EQUAL(firstTexture3D->GetNumTotalBytes(), secondTexture3D->GetNumTotalBytes());
// 	ASSERT_EQUAL(firstTexture3D->GetPixelSize(), secondTexture3D->GetPixelSize());
// 
// 	ASSERT_EQUAL(firstTexture3D->IsCompressed(), secondTexture3D->IsCompressed());
// 	ASSERT_EQUAL(firstTexture3D->IsMipmapable(), secondTexture3D->IsMipmapable());
// 
// 	for (int i = 0; i < TextureMaxUserFields; ++i)
// 	{
// 		ASSERT_EQUAL(firstTexture3D->GetUserField(i), secondTexture3D->GetUserField(i));		 
// 	}
// 	
// 	ASSERT_EQUAL(firstTexture3D->GetWidth(), secondTexture3D->GetWidth());
// 	ASSERT_EQUAL(firstTexture3D->GetHeight(), secondTexture3D->GetHeight());
// 	ASSERT_EQUAL(firstTexture3D->GetThickness(), secondTexture3D->GetThickness());
// 
// 	for (int i = 0; i < secondTexture3D->GetNumLevels(); ++i)
// 	{
// 		for (int k = 0; k < secondTexture3D->GetNumLevelBytes(i);++k)
// 		{
// 			ASSERT_EQUAL(secondTexture3D->GetTextureData(i)[k], secondTexture3D->GetTextureData(i)[k]);
// 		}		
// 	}
}

void Rendering::Texture3DTesting
	::FileTest()
{
	Texture3DSharedPtr firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture3D.trt"));
	firstTexture3D->GenerateMipmaps();

	SaveTexture::SaveToFile(*firstTexture3D, SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture3D.trt"));

	Texture3DSharedPtr secondTexture3D =  LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture3D.trt"));

// 	ASSERT_FALSE(secondTexture3D.IsNullPtr());
// 
// 	ASSERT_ENUM_EQUAL(firstTexture3D->GetFormat(), secondTexture3D->GetFormat());
// 	ASSERT_ENUM_EQUAL(firstTexture3D->GetTextureType(), secondTexture3D->GetTextureType());
// 	ASSERT_ENUM_EQUAL(firstTexture3D->GetUsage(), secondTexture3D->GetUsage());
// 	ASSERT_EQUAL(firstTexture3D->GetNumLevels(), secondTexture3D->GetNumLevels());
// 
// 	ASSERT_EQUAL(firstTexture3D->GetNumDimensions(), secondTexture3D->GetNumDimensions());
// 
// 	for (int i = 0; i < firstTexture3D->GetNumLevels(); ++i)
// 	{
// 		ASSERT_EQUAL(firstTexture3D->GetDimension(0, i), secondTexture3D->GetDimension(0, i));
// 		ASSERT_EQUAL(firstTexture3D->GetDimension(1, i), secondTexture3D->GetDimension(1, i));
// 		ASSERT_EQUAL(firstTexture3D->GetDimension(2, i), secondTexture3D->GetDimension(2, i));
// 		ASSERT_EQUAL(firstTexture3D->GetNumLevelBytes(i), secondTexture3D->GetNumLevelBytes(i));
// 		ASSERT_EQUAL(firstTexture3D->GetLevelOffset(i), secondTexture3D->GetLevelOffset(i));
// 	}
// 
// 	ASSERT_EQUAL(firstTexture3D->GetNumTotalBytes(), secondTexture3D->GetNumTotalBytes());
// 	ASSERT_EQUAL(firstTexture3D->GetPixelSize(), secondTexture3D->GetPixelSize());
// 
// 	ASSERT_EQUAL(firstTexture3D->IsCompressed(), secondTexture3D->IsCompressed());
// 	ASSERT_EQUAL(firstTexture3D->IsMipmapable(), secondTexture3D->IsMipmapable());
// 
// 	for (int i = 0; i < TextureMaxUserFields; ++i)
// 	{
// 		ASSERT_EQUAL(firstTexture3D->GetUserField(i), secondTexture3D->GetUserField(i));
// 	}
// 
// 	ASSERT_EQUAL(firstTexture3D->GetWidth(), secondTexture3D->GetWidth());
// 	ASSERT_EQUAL(firstTexture3D->GetHeight(), secondTexture3D->GetHeight());
// 	ASSERT_EQUAL(firstTexture3D->GetThickness(), secondTexture3D->GetThickness());
// 
// 	for (int i = 0; i < secondTexture3D->GetNumLevels(); ++i)
// 	{
// 		for (int k = 0; k < secondTexture3D->GetNumLevelBytes(i); ++k)
// 		{
// 			ASSERT_EQUAL(secondTexture3D->GetTextureData(i)[k], secondTexture3D->GetTextureData(i)[k]);
// 		}
// 	}	
}
