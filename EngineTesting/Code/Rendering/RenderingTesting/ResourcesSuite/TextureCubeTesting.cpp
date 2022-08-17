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
#include "Rendering/Resources/Textures/LoadTexture.h"
#include "Rendering/Resources/Textures/SaveTexture.h"
#include "Rendering/Resources/Textures/TextureCube.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TextureCubeTesting)

void Rendering::TextureCubeTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    RendererManager::Create();

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::TextureCubeTesting::BaseTest()
{
    TextureCubeSharedPtr firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/TextureCube.trt"));

    ASSERT_EQUAL(1, firstTextureCube->GetNumLevels());

    ASSERT_EQUAL(2, firstTextureCube->GetNumDimensions());
    ASSERT_EQUAL(12, firstTextureCube->GetDimension(0, 0));
    ASSERT_EQUAL(12, firstTextureCube->GetDimension(1, 0));

    ASSERT_EQUAL(0, firstTextureCube->GetLevelOffset(0, 0));

    ASSERT_EQUAL(12, firstTextureCube->GetWidth());
    ASSERT_EQUAL(12, firstTextureCube->GetHeight());

    for (int i = 0; i < 6; ++i)
    {
    }
}

void Rendering::TextureCubeTesting::MipmapsTest()
{
    TextureCubeSharedPtr firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/TextureCube.trt"));

    ASSERT_FALSE(firstTextureCube->HasMipmaps());
}

void Rendering::TextureCubeTesting::StreamTest()
{
    TextureCubeSharedPtr firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/TextureCube.trt"));
}

void Rendering::TextureCubeTesting::FileTest()
{
    TextureCubeSharedPtr firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/TextureCube.trt"));

    SaveTexture::SaveToFile(*firstTextureCube, SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTextureCube.trt"));

    TextureCubeSharedPtr secondTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTextureCube.trt"));

    ASSERT_EQUAL(firstTextureCube->GetNumLevels(), secondTextureCube->GetNumLevels());

    ASSERT_EQUAL(firstTextureCube->GetNumDimensions(), secondTextureCube->GetNumDimensions());

    for (int i = 0; i < firstTextureCube->GetNumLevels(); ++i)
    {
        ASSERT_EQUAL(firstTextureCube->GetDimension(0, i), secondTextureCube->GetDimension(0, i));
        ASSERT_EQUAL(firstTextureCube->GetDimension(1, i), secondTextureCube->GetDimension(1, i));
        ASSERT_EQUAL(firstTextureCube->GetNumLevelBytes(i), secondTextureCube->GetNumLevelBytes(i));
        ASSERT_EQUAL(firstTextureCube->GetLevelOffset(0, i), secondTextureCube->GetLevelOffset(0, i));
    }

    ASSERT_EQUAL(firstTextureCube->GetWidth(), secondTextureCube->GetWidth());
    ASSERT_EQUAL(firstTextureCube->GetHeight(), secondTextureCube->GetHeight());

    for (int face = 0; face < 6; ++face)
    {
        for (int i = 0; i < secondTextureCube->GetNumLevels(); ++i)
        {
            for (int k = 0; k < secondTextureCube->GetNumLevelBytes(i); ++k)
            {
            }
        }
    }
}
