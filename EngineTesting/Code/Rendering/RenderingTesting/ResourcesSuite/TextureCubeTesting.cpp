///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 16:12)

#include "TextureCubeTesting.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Mathematics/Base/BitHacksDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/LoadTexture.h"
#include "Rendering/Resources/SaveTexture.h"
#include "Rendering/Resources/TextureCube.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TextureCubeTesting)

void Rendering::TextureCubeTesting::MainTest()
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

void Rendering::TextureCubeTesting::BaseTest()
{
    TextureCubeSharedPtr firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/TextureCube.trt"));

    ASSERT_ENUM_EQUAL(TextureFormat::R8G8B8, firstTextureCube->GetFormat());
    ASSERT_ENUM_EQUAL(TextureFlags::TextureCube, firstTextureCube->GetTextureType());
    ASSERT_ENUM_EQUAL(BufferUsage::Texture, firstTextureCube->GetUsage());
    ASSERT_EQUAL(1, firstTextureCube->GetNumLevels());

    ASSERT_EQUAL(2, firstTextureCube->GetNumDimensions());
    ASSERT_EQUAL(12, firstTextureCube->GetDimension(0, 0));
    ASSERT_EQUAL(12, firstTextureCube->GetDimension(1, 0));
    ASSERT_EQUAL(12 * 12 * firstTextureCube->GetPixelSize(), firstTextureCube->GetNumLevelBytes(0));
    ASSERT_EQUAL(12 * 12 * firstTextureCube->GetPixelSize() * 6, firstTextureCube->GetNumTotalBytes());
    ASSERT_EQUAL(0, firstTextureCube->GetLevelOffset(0));

    ASSERT_EQUAL(3, firstTextureCube->GetPixelSize());

    ASSERT_FALSE(firstTextureCube->IsCompressed());
    ASSERT_TRUE(firstTextureCube->IsMipmapable());

    for (int i = 0; i < TextureMaxUserFields; ++i)
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
        ASSERT_UNEQUAL_NULL_PTR(firstTextureCube->GetTextureData(i, 0));
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    ASSERT_EQUAL(firstTextureCube->GetTextureData(5, 0)[firstTextureCube->GetNumLevelBytes(0) - 1], 0x08);

#include STSTEM_WARNING_POP
}

void Rendering::TextureCubeTesting::MipmapsTest()
{
    TextureCubeSharedPtr firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/TextureCube.trt"));

    ASSERT_FALSE(firstTextureCube->HasMipmaps());
}

void Rendering::TextureCubeTesting::StreamTest()
{
    TextureCubeSharedPtr firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/TextureCube.trt"));

    for (int i = 0; i < TextureMaxUserFields; ++i)
    {
        firstTextureCube->SetUserField(i, i);
    }
}

void Rendering::TextureCubeTesting::FileTest()
{
    TextureCubeSharedPtr firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/TextureCube.trt"));

    SaveTexture::SaveToFile(*firstTextureCube, SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTextureCube.trt"));

    TextureCubeSharedPtr secondTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTextureCube.trt"));

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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

                ASSERT_EQUAL(secondTextureCube->GetTextureData(face, i)[k], secondTextureCube->GetTextureData(face, i)[k]);

#include STSTEM_WARNING_POP
            }
        }
    }
}
