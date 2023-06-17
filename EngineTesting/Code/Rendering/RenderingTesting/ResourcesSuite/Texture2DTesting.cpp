///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:38)

#include "Texture2DTesting.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/BitHacksDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/Textures/LoadTexture.h"
#include "Rendering/Resources/Textures/SaveTexture.h"
#include "Rendering/Resources/Textures/Texture2D.h"

Rendering::Texture2DTesting::Texture2DTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture2DTesting)

void Rendering::Texture2DTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::Texture2DTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    RendererManager::Create();

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::Texture2DTesting::BaseTest()
{
    Texture2DSharedPtr firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture2D.trt"));

    ASSERT_EQUAL(1, firstTexture2D->GetNumLevels());

    ASSERT_EQUAL(2, firstTexture2D->GetNumDimensions());
    ASSERT_EQUAL(16, firstTexture2D->GetDimension(0, 0));
    ASSERT_EQUAL(12, firstTexture2D->GetDimension(1, 0));
    ASSERT_EQUAL(0, firstTexture2D->GetLevelOffset(0, 0));

    ASSERT_EQUAL(16, firstTexture2D->GetWidth());
    ASSERT_EQUAL(12, firstTexture2D->GetHeight());
}

void Rendering::Texture2DTesting::MipmapsTest()
{
    Texture2DSharedPtr firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture2D.trt"));

    ASSERT_FALSE(firstTexture2D->HasMipmaps());
}

void Rendering::Texture2DTesting::StreamTest()
{
    Texture2DSharedPtr firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture2D.trt"));
}

void Rendering::Texture2DTesting::FileTest()
{
    Texture2DSharedPtr firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture2D.trt"));

    SaveTexture::SaveToFile(*firstTexture2D, SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture2D.trt"));

    Texture2DSharedPtr secondTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture2D.trt"));

    ASSERT_ENUM_EQUAL(firstTexture2D->GetFormat(), secondTexture2D->GetFormat());

    ASSERT_EQUAL(firstTexture2D->GetNumLevels(), secondTexture2D->GetNumLevels());

    ASSERT_EQUAL(firstTexture2D->GetNumDimensions(), secondTexture2D->GetNumDimensions());

    for (int i = 0; i < firstTexture2D->GetNumLevels(); ++i)
    {
        ASSERT_EQUAL(firstTexture2D->GetDimension(0, i), secondTexture2D->GetDimension(0, i));
        ASSERT_EQUAL(firstTexture2D->GetDimension(1, i), secondTexture2D->GetDimension(1, i));
        ASSERT_EQUAL(firstTexture2D->GetNumLevelBytes(i), secondTexture2D->GetNumLevelBytes(i));
        ASSERT_EQUAL(firstTexture2D->GetLevelOffset(0, i), secondTexture2D->GetLevelOffset(0, i));
    }

    ASSERT_EQUAL(firstTexture2D->GetWidth(), secondTexture2D->GetWidth());
    ASSERT_EQUAL(firstTexture2D->GetHeight(), secondTexture2D->GetHeight());

    for (int i = 0; i < secondTexture2D->GetNumLevels(); ++i)
    {
        for (int k = 0; k < secondTexture2D->GetNumLevelBytes(i); ++k)
        {
        }
    }
}
