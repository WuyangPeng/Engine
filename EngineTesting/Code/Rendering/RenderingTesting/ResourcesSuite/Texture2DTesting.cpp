// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/03 17:34)

#include "Texture2DTesting.h"
#include "Mathematics/Base/BitHacksDetail.h"
#include "Rendering/Resources/Texture2D.h"
#include "Rendering/Resources/LoadTexture.h"
#include "Rendering/Resources/SaveTexture.h"
#include "Rendering/Renderers/RendererManager.h"
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

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, Texture2DTesting) 

void Rendering::Texture2DTesting
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
 
void Rendering::Texture2DTesting
	::BaseTest()
{
	Texture2DSharedPtr firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture2D.trt"));

	//ASSERT_FALSE(firstTexture2D.IsNullPtr());

	ASSERT_ENUM_EQUAL(TextureFormat::R8G8B8, firstTexture2D->GetFormat());
	ASSERT_ENUM_EQUAL(TextureFlags::Texture2D, firstTexture2D->GetTextureType());
	ASSERT_ENUM_EQUAL(BufferUsage::Texture, firstTexture2D->GetUsage());
	ASSERT_EQUAL(1, firstTexture2D->GetNumLevels());

	ASSERT_EQUAL(2, firstTexture2D->GetNumDimensions());
	ASSERT_EQUAL(16, firstTexture2D->GetDimension(0,0));
	ASSERT_EQUAL(12, firstTexture2D->GetDimension(1,0));
	ASSERT_EQUAL(16 * 12 * firstTexture2D->GetPixelSize(), firstTexture2D->GetNumLevelBytes(0));
	ASSERT_EQUAL(16 * 12 * firstTexture2D->GetPixelSize(), firstTexture2D->GetNumTotalBytes());
	ASSERT_EQUAL(0, firstTexture2D->GetLevelOffset(0));

	ASSERT_EQUAL(3, firstTexture2D->GetPixelSize());

	ASSERT_FALSE(firstTexture2D->IsCompressed());
	ASSERT_TRUE(firstTexture2D->IsMipmapable());

	for (int i = 0; i < TextureMaxUserFields;++i)
	{
		ASSERT_EQUAL(0, firstTexture2D->GetUserField(i));
		firstTexture2D->SetUserField(i, i);
	}

	for (int i = 0; i < TextureMaxUserFields; ++i)
	{
		ASSERT_EQUAL(i, firstTexture2D->GetUserField(i));	
	}

	ASSERT_EQUAL(16, firstTexture2D->GetWidth());
	ASSERT_EQUAL(12, firstTexture2D->GetHeight());

	ASSERT_UNEQUAL_NULL_PTR(firstTexture2D->GetTextureData(0));

// 	ConstTexture2DSharedPtr secondTexture2D = firstTexture2D.PolymorphicDowncastConstObjectSharedPtr<ConstTexture2DSharedPtr>();
// 
// 	ASSERT_UNEQUAL_NULL_PTR(secondTexture2D->GetTextureData(0));
// 
// 	ASSERT_EQUAL(firstTexture2D->GetTextureData(0)[firstTexture2D->GetNumLevelBytes(0) - 1],0x14);
}

void Rendering::Texture2DTesting
	::MipmapsTest()
{
	Texture2DSharedPtr firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture2D.trt"));

	ASSERT_FALSE(firstTexture2D->HasMipmaps());

	firstTexture2D->GenerateMipmaps();

	ASSERT_TRUE(firstTexture2D->HasMipmaps());

	ASSERT_ENUM_EQUAL(TextureFormat::R8G8B8, firstTexture2D->GetFormat());
	ASSERT_ENUM_EQUAL(TextureFlags::Texture2D, firstTexture2D->GetTextureType());
	ASSERT_ENUM_EQUAL(BufferUsage::Texture, firstTexture2D->GetUsage());
	ASSERT_EQUAL(Mathematics::BitHacks::Log2OfPowerOfTwo(16) + 1,firstTexture2D->GetNumLevels());

	ASSERT_EQUAL(2, firstTexture2D->GetNumDimensions());

	int width = 16;
	int height = 12;
	int total = 0;

	for (int i = 0; i < firstTexture2D->GetNumLevels(); ++i)
	{
		ASSERT_EQUAL(width, firstTexture2D->GetDimension(0, i));
		ASSERT_EQUAL(height, firstTexture2D->GetDimension(1, i));
		ASSERT_EQUAL(width * height * firstTexture2D->GetPixelSize(), 
			         firstTexture2D->GetNumLevelBytes(i));
		ASSERT_EQUAL(total, firstTexture2D->GetLevelOffset(i));

		total += width * height * firstTexture2D->GetPixelSize();

		if(1 < width)
			width >>= 1;

		if(1 < height)
			height >>= 1;
	}

	ASSERT_EQUAL(total, firstTexture2D->GetNumTotalBytes());
	ASSERT_EQUAL(3, firstTexture2D->GetPixelSize());

	ASSERT_FALSE(firstTexture2D->IsCompressed());
	ASSERT_TRUE(firstTexture2D->IsMipmapable());

	ASSERT_EQUAL(16, firstTexture2D->GetWidth());
	ASSERT_EQUAL(12, firstTexture2D->GetHeight());
} 

void Rendering::Texture2DTesting
	::StreamTest()
{
	Texture2DSharedPtr firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture2D.trt"));
	firstTexture2D->GenerateMipmaps();

	for (int i = 0; i < TextureMaxUserFields; ++i)
	{	 
		firstTexture2D->SetUserField(i, i);
	}

// 	CoreTools::OutTopLevel outTopLevel;
// 	CoreTools::ObjectInterfaceSharedPtr firstBuffer(firstTexture2D.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
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
// 	Texture2DSharedPtr secondTexture2D =	inTopLevel[0].PolymorphicDowncastObjectSharedPtr<Texture2DSharedPtr>();
// 	 
// 	ASSERT_FALSE(secondTexture2D.IsNullPtr());
// 
// 	ASSERT_ENUM_EQUAL(firstTexture2D->GetFormat(), secondTexture2D->GetFormat());
// 	ASSERT_ENUM_EQUAL(firstTexture2D->GetTextureType(), secondTexture2D->GetTextureType());
// 	ASSERT_ENUM_EQUAL(firstTexture2D->GetUsage(), secondTexture2D->GetUsage());
// 	ASSERT_EQUAL(firstTexture2D->GetNumLevels(), secondTexture2D->GetNumLevels());
// 
// 	ASSERT_EQUAL(firstTexture2D->GetNumDimensions(), secondTexture2D->GetNumDimensions());
// 
// 	for (int i = 0; i < firstTexture2D->GetNumLevels(); ++i)
// 	{
// 		ASSERT_EQUAL(firstTexture2D->GetDimension(0, i), secondTexture2D->GetDimension(0, i));
// 		ASSERT_EQUAL(firstTexture2D->GetDimension(1, i), secondTexture2D->GetDimension(1, i));
// 		ASSERT_EQUAL(firstTexture2D->GetNumLevelBytes(i), secondTexture2D->GetNumLevelBytes(i));
// 		ASSERT_EQUAL(firstTexture2D->GetLevelOffset(i), secondTexture2D->GetLevelOffset(i));
// 	}
// 	
// 	ASSERT_EQUAL(firstTexture2D->GetNumTotalBytes(), secondTexture2D->GetNumTotalBytes());
// 	ASSERT_EQUAL(firstTexture2D->GetPixelSize(), secondTexture2D->GetPixelSize());
// 
// 	ASSERT_EQUAL(firstTexture2D->IsCompressed(), secondTexture2D->IsCompressed());
// 	ASSERT_EQUAL(firstTexture2D->IsMipmapable(), secondTexture2D->IsMipmapable());
// 
// 	for (int i = 0; i < TextureMaxUserFields; ++i)
// 	{
// 		ASSERT_EQUAL(firstTexture2D->GetUserField(i), secondTexture2D->GetUserField(i));		 
// 	}
// 	
// 	ASSERT_EQUAL(firstTexture2D->GetWidth(), secondTexture2D->GetWidth());
// 	ASSERT_EQUAL(firstTexture2D->GetHeight(), secondTexture2D->GetHeight());
// 
// 	for (int i = 0; i < secondTexture2D->GetNumLevels(); ++i)
// 	{
// 		for (int k = 0; k < secondTexture2D->GetNumLevelBytes(i);++k)
// 		{
// 			ASSERT_EQUAL(secondTexture2D->GetTextureData(i)[k], secondTexture2D->GetTextureData(i)[k]);
// 		}		
// 	}
}

void Rendering::Texture2DTesting
	::FileTest()
{
	Texture2DSharedPtr firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture2D.trt"));
	firstTexture2D->GenerateMipmaps();

	SaveTexture::SaveToFile(*firstTexture2D, SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture2D.trt"));

	Texture2DSharedPtr secondTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture2D.trt"));

	//ASSERT_FALSE(secondTexture2D.IsNullPtr());

	ASSERT_ENUM_EQUAL(firstTexture2D->GetFormat(), secondTexture2D->GetFormat());
	ASSERT_ENUM_EQUAL(firstTexture2D->GetTextureType(), secondTexture2D->GetTextureType());
	ASSERT_ENUM_EQUAL(firstTexture2D->GetUsage(), secondTexture2D->GetUsage());
	ASSERT_EQUAL(firstTexture2D->GetNumLevels(), secondTexture2D->GetNumLevels());

	ASSERT_EQUAL(firstTexture2D->GetNumDimensions(), secondTexture2D->GetNumDimensions());

	for (int i = 0; i < firstTexture2D->GetNumLevels(); ++i)
	{
		ASSERT_EQUAL(firstTexture2D->GetDimension(0, i), secondTexture2D->GetDimension(0, i));
		ASSERT_EQUAL(firstTexture2D->GetDimension(1, i), secondTexture2D->GetDimension(1, i));
		ASSERT_EQUAL(firstTexture2D->GetNumLevelBytes(i), secondTexture2D->GetNumLevelBytes(i));
		ASSERT_EQUAL(firstTexture2D->GetLevelOffset(i), secondTexture2D->GetLevelOffset(i));
	}

	ASSERT_EQUAL(firstTexture2D->GetNumTotalBytes(), secondTexture2D->GetNumTotalBytes());
	ASSERT_EQUAL(firstTexture2D->GetPixelSize(), secondTexture2D->GetPixelSize());

	ASSERT_EQUAL(firstTexture2D->IsCompressed(), secondTexture2D->IsCompressed());
	ASSERT_EQUAL(firstTexture2D->IsMipmapable(), secondTexture2D->IsMipmapable());

	for (int i = 0; i < TextureMaxUserFields; ++i)
	{
		ASSERT_EQUAL(firstTexture2D->GetUserField(i), secondTexture2D->GetUserField(i));
	}

	ASSERT_EQUAL(firstTexture2D->GetWidth(), secondTexture2D->GetWidth());
	ASSERT_EQUAL(firstTexture2D->GetHeight(), secondTexture2D->GetHeight());

	for (int i = 0; i < secondTexture2D->GetNumLevels(); ++i)
	{
		for (int k = 0; k < secondTexture2D->GetNumLevelBytes(i); ++k)
		{
			ASSERT_EQUAL(secondTexture2D->GetTextureData(i)[k], secondTexture2D->GetTextureData(i)[k]);
		}
	}
}
