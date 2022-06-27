///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 16:10)

#include "Texture3DTesting.h"
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
#include "Rendering/Resources/Texture3D.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, Texture3DTesting)

void Rendering::Texture3DTesting::MainTest()
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

void Rendering::Texture3DTesting::BaseTest()
{
    Texture3DSharedPtr firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture3D.trt"));

    ASSERT_ENUM_EQUAL(TextureFormat::R8G8B8, firstTexture3D->GetFormat());
    ASSERT_ENUM_EQUAL(TextureFlags::Texture3D, firstTexture3D->GetTextureType());
    ASSERT_ENUM_EQUAL(BufferUsage::Texture, firstTexture3D->GetUsage());
    ASSERT_EQUAL(1, firstTexture3D->GetNumLevels());

    ASSERT_EQUAL(3, firstTexture3D->GetNumDimensions());
    ASSERT_EQUAL(16, firstTexture3D->GetDimension(0, 0));
    ASSERT_EQUAL(12, firstTexture3D->GetDimension(1, 0));
    ASSERT_EQUAL(8, firstTexture3D->GetDimension(2, 0));
    ASSERT_EQUAL(16 * 12 * 8 * firstTexture3D->GetPixelSize(), firstTexture3D->GetNumLevelBytes(0));
    ASSERT_EQUAL(16 * 12 * 8 * firstTexture3D->GetPixelSize(), firstTexture3D->GetNumTotalBytes());
    ASSERT_EQUAL(0, firstTexture3D->GetLevelOffset(0));

    ASSERT_EQUAL(3, firstTexture3D->GetPixelSize());

    ASSERT_FALSE(firstTexture3D->IsCompressed());
    ASSERT_TRUE(firstTexture3D->IsMipmapable());

    for (int i = 0; i < TextureMaxUserFields; ++i)
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
}

void Rendering::Texture3DTesting::MipmapsTest()
{
    Texture3DSharedPtr firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture3D.trt"));

    ASSERT_FALSE(firstTexture3D->HasMipmaps());
}

void Rendering::Texture3DTesting::StreamTest()
{
    Texture3DSharedPtr firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture3D.trt"));

    for (int i = 0; i < TextureMaxUserFields; ++i)
    {
        firstTexture3D->SetUserField(i, i);
    }
}

void Rendering::Texture3DTesting::FileTest()
{
    Texture3DSharedPtr firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture3D.trt"));

    SaveTexture::SaveToFile(*firstTexture3D, SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture3D.trt"));

    Texture3DSharedPtr secondTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture3D.trt"));
}
