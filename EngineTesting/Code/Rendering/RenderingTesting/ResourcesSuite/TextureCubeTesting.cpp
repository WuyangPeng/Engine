// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/03 17:35)

#include "TextureCubeTesting.h"
#include "Mathematics/Base/BitHacksDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/LoadTexture.h"
#include "Rendering/Resources/SaveTexture.h"
#include "Rendering/Resources/TextureCube.h"
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

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TextureCubeTesting) 

void Rendering::TextureCubeTesting
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
 
void Rendering::TextureCubeTesting
	::BaseTest()
{
	 TextureCubeSharedPtr firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/TextureCube.trt"));

	//ASSERT_FALSE(firstTextureCube.IsNullPtr());

	ASSERT_ENUM_EQUAL(TextureFormat::R8G8B8, firstTextureCube->GetFormat());
	ASSERT_ENUM_EQUAL(TextureFlags::TextureCube, firstTextureCube->GetTextureType());
	ASSERT_ENUM_EQUAL(BufferUsage::Texture, firstTextureCube->GetUsage());
	ASSERT_EQUAL(1, firstTextureCube->GetNumLevels());

	ASSERT_EQUAL(2, firstTextureCube->GetNumDimensions());
	ASSERT_EQUAL(12, firstTextureCube->GetDimension(0,0));
	ASSERT_EQUAL(12, firstTextureCube->GetDimension(1,0));
	ASSERT_EQUAL(12 * 12 * firstTextureCube->GetPixelSize(), firstTextureCube->GetNumLevelBytes(0));
	ASSERT_EQUAL(12 * 12 * firstTextureCube->GetPixelSize() * 6, firstTextureCube->GetNumTotalBytes());
	ASSERT_EQUAL(0, firstTextureCube->GetLevelOffset(0));

	ASSERT_EQUAL(3, firstTextureCube->GetPixelSize());

	ASSERT_FALSE(firstTextureCube->IsCompressed());
	ASSERT_TRUE(firstTextureCube->IsMipmapable());

	for (int i = 0; i < TextureMaxUserFields;++i)
	{
		ASSERT_EQUAL(0, firstTextureCube->GetUserField(i));
		firstTextureCube->SetUserField(i, i);
	}

	for (int i = 0; i < TextureMaxUserFields; ++i)
	{
		ASSERT_EQUAL(i, firstTextureCube->GetUserField(i));	
	}

	ASSERT_EQUAL(12, firstTextureCube->GetWidth());
	ASSERT_EQUAL(12, firstTextureCube->GetHeight());

	for (int i = 0; i < 6; ++i)
	{
		ASSERT_UNEQUAL_NULL_PTR(firstTextureCube->GetTextureData(i,0));

// 		ConstTextureCubeSharedPtr secondTextureCube = firstTextureCube.PolymorphicDowncastConstObjectSharedPtr<ConstTextureCubeSharedPtr>();
// 
// 		ASSERT_UNEQUAL_NULL_PTR(secondTextureCube->GetTextureData(i, 0));
	}
	
	ASSERT_EQUAL(firstTextureCube->GetTextureData(5, 0)[firstTextureCube->GetNumLevelBytes(0) - 1], 0x08);
}

void Rendering::TextureCubeTesting
	::MipmapsTest()
{
	TextureCubeSharedPtr firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/TextureCube.trt"));

	ASSERT_FALSE(firstTextureCube->HasMipmaps());

	firstTextureCube->GenerateMipmaps();

	ASSERT_TRUE(firstTextureCube->HasMipmaps());

	ASSERT_ENUM_EQUAL(TextureFormat::R8G8B8, firstTextureCube->GetFormat());
	ASSERT_ENUM_EQUAL(TextureFlags::TextureCube, firstTextureCube->GetTextureType());
	ASSERT_ENUM_EQUAL(BufferUsage::Texture, firstTextureCube->GetUsage());
	ASSERT_EQUAL(Mathematics::BitHacks::Log2OfPowerOfTwo(12) + 1,firstTextureCube->GetNumLevels());

	ASSERT_EQUAL(2, firstTextureCube->GetNumDimensions());

	int width = 12;
	int height = 12;
	int total = 0;

	for (int i = 0; i < firstTextureCube->GetNumLevels(); ++i)
	{
		ASSERT_EQUAL(width, firstTextureCube->GetDimension(0, i));
		ASSERT_EQUAL(height, firstTextureCube->GetDimension(1, i));
		ASSERT_EQUAL(width * height * firstTextureCube->GetPixelSize(),firstTextureCube->GetNumLevelBytes(i));
		ASSERT_EQUAL(total, firstTextureCube->GetLevelOffset(i));

		total += width * height * firstTextureCube->GetPixelSize();

		if(1 < width)
			width >>= 1;

		if(1 < height)
			height >>= 1;
	}

	ASSERT_EQUAL(total * 6, firstTextureCube->GetNumTotalBytes());
	ASSERT_EQUAL(3, firstTextureCube->GetPixelSize());

	ASSERT_FALSE(firstTextureCube->IsCompressed());
	ASSERT_TRUE(firstTextureCube->IsMipmapable());

	ASSERT_EQUAL(12, firstTextureCube->GetWidth());
	ASSERT_EQUAL(12, firstTextureCube->GetHeight());
} 

void Rendering::TextureCubeTesting
	::StreamTest()
{
	 TextureCubeSharedPtr firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/TextureCube.trt"));
	firstTextureCube->GenerateMipmaps();

	for (int i = 0; i < TextureMaxUserFields; ++i)
	{	 
		firstTextureCube->SetUserField(i, i);
	}

// 	CoreTools::OutTopLevel outTopLevel;
// 	CoreTools::ObjectInterfaceSharedPtr firstBuffer(firstTextureCube.PolymorphicDowncastObjectSharedPtr<CoreTools::ObjectInterfaceSharedPtr>());
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
// 	TextureCubeSharedPtr secondTextureCube =
// 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<TextureCubeSharedPtr>();
// 	 
// 	ASSERT_FALSE(secondTextureCube.IsNullPtr());
// 
// 	ASSERT_ENUM_EQUAL(firstTextureCube->GetFormat(), secondTextureCube->GetFormat());
// 	ASSERT_ENUM_EQUAL(firstTextureCube->GetTextureType(), secondTextureCube->GetTextureType());
// 	ASSERT_ENUM_EQUAL(firstTextureCube->GetUsage(), secondTextureCube->GetUsage());
// 	ASSERT_EQUAL(firstTextureCube->GetNumLevels(), secondTextureCube->GetNumLevels());
// 
// 	ASSERT_EQUAL(firstTextureCube->GetNumDimensions(), secondTextureCube->GetNumDimensions());
// 
// 	for (int i = 0; i < firstTextureCube->GetNumLevels(); ++i)
// 	{
// 		ASSERT_EQUAL(firstTextureCube->GetDimension(0, i), secondTextureCube->GetDimension(0, i));
// 		ASSERT_EQUAL(firstTextureCube->GetDimension(1, i), secondTextureCube->GetDimension(1, i));
// 		ASSERT_EQUAL(firstTextureCube->GetNumLevelBytes(i), secondTextureCube->GetNumLevelBytes(i));
// 		ASSERT_EQUAL(firstTextureCube->GetLevelOffset(i), secondTextureCube->GetLevelOffset(i));
// 	}
// 	
// 	ASSERT_EQUAL(firstTextureCube->GetNumTotalBytes(), secondTextureCube->GetNumTotalBytes());
// 	ASSERT_EQUAL(firstTextureCube->GetPixelSize(), secondTextureCube->GetPixelSize());
// 
// 	ASSERT_EQUAL(firstTextureCube->IsCompressed(), secondTextureCube->IsCompressed());
// 	ASSERT_EQUAL(firstTextureCube->IsMipmapable(), secondTextureCube->IsMipmapable());
// 
// 	for (int i = 0; i < TextureMaxUserFields; ++i)
// 	{
// 		ASSERT_EQUAL(firstTextureCube->GetUserField(i), secondTextureCube->GetUserField(i));		 
// 	}
// 	
// 	ASSERT_EQUAL(firstTextureCube->GetWidth(), secondTextureCube->GetWidth());
// 	ASSERT_EQUAL(firstTextureCube->GetHeight(), secondTextureCube->GetHeight());
// 
// 	for (int face = 0; face < 6;++face)
// 	{
// 		for (int i = 0; i < secondTextureCube->GetNumLevels(); ++i)
// 		{
// 			for (int k = 0; k < secondTextureCube->GetNumLevelBytes(i); ++k)
// 			{
// 				ASSERT_EQUAL(secondTextureCube->GetTextureData(face, i)[k], secondTextureCube->GetTextureData(face, i)[k]);
// 			}
// 		}
// 	}	
}

void Rendering::TextureCubeTesting
	::FileTest()
{
	TextureCubeSharedPtr firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/TextureCube.trt"));
	firstTextureCube->GenerateMipmaps();

	SaveTexture::SaveToFile(*firstTextureCube, SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTextureCube.trt"));

	TextureCubeSharedPtr secondTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTextureCube.trt"));

	//ASSERT_FALSE(secondTextureCube.IsNullPtr());

	ASSERT_ENUM_EQUAL(firstTextureCube->GetFormat(), secondTextureCube->GetFormat());
	ASSERT_ENUM_EQUAL(firstTextureCube->GetTextureType(), secondTextureCube->GetTextureType());
	ASSERT_ENUM_EQUAL(firstTextureCube->GetUsage(), secondTextureCube->GetUsage());
	ASSERT_EQUAL(firstTextureCube->GetNumLevels(), secondTextureCube->GetNumLevels());

	ASSERT_EQUAL(firstTextureCube->GetNumDimensions(), secondTextureCube->GetNumDimensions());

	for (int i = 0; i < firstTextureCube->GetNumLevels(); ++i)
	{
		ASSERT_EQUAL(firstTextureCube->GetDimension(0, i), secondTextureCube->GetDimension(0, i));
		ASSERT_EQUAL(firstTextureCube->GetDimension(1, i), secondTextureCube->GetDimension(1, i));
		ASSERT_EQUAL(firstTextureCube->GetNumLevelBytes(i), secondTextureCube->GetNumLevelBytes(i));
		ASSERT_EQUAL(firstTextureCube->GetLevelOffset(i), secondTextureCube->GetLevelOffset(i));
	}

	ASSERT_EQUAL(firstTextureCube->GetNumTotalBytes(), secondTextureCube->GetNumTotalBytes());
	ASSERT_EQUAL(firstTextureCube->GetPixelSize(), secondTextureCube->GetPixelSize());

	ASSERT_EQUAL(firstTextureCube->IsCompressed(), secondTextureCube->IsCompressed());
	ASSERT_EQUAL(firstTextureCube->IsMipmapable(), secondTextureCube->IsMipmapable());

	for (int i = 0; i < TextureMaxUserFields; ++i)
	{
		ASSERT_EQUAL(firstTextureCube->GetUserField(i), secondTextureCube->GetUserField(i));
	}

	ASSERT_EQUAL(firstTextureCube->GetWidth(), secondTextureCube->GetWidth());
	ASSERT_EQUAL(firstTextureCube->GetHeight(), secondTextureCube->GetHeight());

	for (int face = 0; face < 6; ++face)
	{
		for (int i = 0; i < secondTextureCube->GetNumLevels(); ++i)
		{
			for (int k = 0; k < secondTextureCube->GetNumLevelBytes(i); ++k)
			{
				ASSERT_EQUAL(secondTextureCube->GetTextureData(face, i)[k], secondTextureCube->GetTextureData(face, i)[k]);
			}
		}
	}
}
