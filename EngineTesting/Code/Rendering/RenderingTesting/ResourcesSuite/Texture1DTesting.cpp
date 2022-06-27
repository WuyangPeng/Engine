///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 15:58)

#include "Texture1DTesting.h"
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
#include "Rendering/Resources/Texture1D.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, Texture1DTesting)

void Rendering::Texture1DTesting::MainTest()
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

void Rendering::Texture1DTesting::BaseTest()
{
    Texture1DSharedPtr firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture1D.trt"));

    ASSERT_ENUM_EQUAL(TextureFormat::R8G8B8, firstTexture1D->GetFormat());
    ASSERT_ENUM_EQUAL(TextureFlags::Texture1D, firstTexture1D->GetTextureType());
    ASSERT_ENUM_EQUAL(BufferUsage::Texture, firstTexture1D->GetUsage());
    ASSERT_EQUAL(1, firstTexture1D->GetNumLevels());

    ASSERT_EQUAL(1, firstTexture1D->GetNumDimensions());
    ASSERT_EQUAL(16, firstTexture1D->GetDimension(0, 0));
    ASSERT_EQUAL(16 * firstTexture1D->GetPixelSize(), firstTexture1D->GetNumLevelBytes(0));
    ASSERT_EQUAL(16 * firstTexture1D->GetPixelSize(), firstTexture1D->GetNumTotalBytes());
    ASSERT_EQUAL(0, firstTexture1D->GetLevelOffset(0));

    ASSERT_EQUAL(3, firstTexture1D->GetPixelSize());

    ASSERT_FALSE(firstTexture1D->IsCompressed());
    ASSERT_TRUE(firstTexture1D->IsMipmapable());

    for (int i = 0; i < TextureMaxUserFields; ++i)
    {
        ASSERT_EQUAL(0, firstTexture1D->GetUserField(i));
        firstTexture1D->SetUserField(i, i);
    }

    for (int i = 0; i < TextureMaxUserFields; ++i)
    {
        ASSERT_EQUAL(i, firstTexture1D->GetUserField(i));
    }

    ASSERT_EQUAL(16, firstTexture1D->GetLength());

    ASSERT_UNEQUAL_NULL_PTR(firstTexture1D->GetTextureData(0));
}

void Rendering::Texture1DTesting::MipmapsTest()
{
    Texture1DSharedPtr firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture1D.trt"));

    ASSERT_FALSE(firstTexture1D->HasMipmaps());
}

void Rendering::Texture1DTesting::StreamTest()
{
    Texture1DSharedPtr firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture1D.trt"));

    for (int i = 0; i < TextureMaxUserFields; ++i)
    {
        firstTexture1D->SetUserField(i, i);
    }
}

void Rendering::Texture1DTesting::FileTest()
{
    Texture1DSharedPtr firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture1D.trt"));

    SaveTexture::SaveToFile(*firstTexture1D, SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture1D.trt"));

    Texture1DSharedPtr secondTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture1D.trt"));

    ASSERT_ENUM_EQUAL(firstTexture1D->GetFormat(), secondTexture1D->GetFormat());
    ASSERT_ENUM_EQUAL(firstTexture1D->GetTextureType(), secondTexture1D->GetTextureType());
    ASSERT_ENUM_EQUAL(firstTexture1D->GetUsage(), secondTexture1D->GetUsage());
    ASSERT_EQUAL(firstTexture1D->GetNumLevels(), secondTexture1D->GetNumLevels());

    ASSERT_EQUAL(firstTexture1D->GetNumDimensions(), secondTexture1D->GetNumDimensions());

    for (int i = 0; i < firstTexture1D->GetNumLevels(); ++i)
    {
        ASSERT_EQUAL(firstTexture1D->GetDimension(0, i), secondTexture1D->GetDimension(0, i));
        ASSERT_EQUAL(firstTexture1D->GetNumLevelBytes(i), secondTexture1D->GetNumLevelBytes(i));
        ASSERT_EQUAL(firstTexture1D->GetLevelOffset(i), secondTexture1D->GetLevelOffset(i));
    }

    ASSERT_EQUAL(firstTexture1D->GetNumTotalBytes(), secondTexture1D->GetNumTotalBytes());
    ASSERT_EQUAL(firstTexture1D->GetPixelSize(), secondTexture1D->GetPixelSize());

    ASSERT_EQUAL(firstTexture1D->IsCompressed(), secondTexture1D->IsCompressed());
    ASSERT_EQUAL(firstTexture1D->IsMipmapable(), secondTexture1D->IsMipmapable());

    for (int i = 0; i < TextureMaxUserFields; ++i)
    {
        ASSERT_EQUAL(firstTexture1D->GetUserField(i), secondTexture1D->GetUserField(i));
    }

    ASSERT_EQUAL(firstTexture1D->GetLength(), secondTexture1D->GetLength());

    for (int i = 0; i < secondTexture1D->GetNumLevels(); ++i)
    {
        for (int k = 0; k < secondTexture1D->GetNumLevelBytes(i); ++k)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            ASSERT_EQUAL(secondTexture1D->GetTextureData(i)[k], secondTexture1D->GetTextureData(i)[k]);

#include STSTEM_WARNING_POP
        }
    }
}
