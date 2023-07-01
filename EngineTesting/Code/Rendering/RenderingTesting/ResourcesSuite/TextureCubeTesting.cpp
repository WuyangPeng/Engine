///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:38)

#include "TextureCubeTesting.h"
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
#include "Rendering/Resources/Textures/LoadTexture.h"
#include "Rendering/Resources/Textures/SaveTexture.h"
#include "Rendering/Resources/Textures/TextureCube.h"

Rendering::TextureCubeTesting::TextureCubeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureCubeTesting)

void Rendering::TextureCubeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::TextureCubeTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

   

    CoreTools::InitTerm::ExecuteTerminator();
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

    ASSERT_FALSE(firstTextureCube->HasMipMaps());
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
