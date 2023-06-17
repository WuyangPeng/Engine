///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:37)

#include "Texture1DTesting.h"
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
#include "Rendering/Resources/Textures/Texture1D.h"

Rendering::Texture1DTesting::Texture1DTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture1DTesting)

void Rendering::Texture1DTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::Texture1DTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    RendererManager::Create();

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::Texture1DTesting::BaseTest()
{
    Texture1DSharedPtr firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture1D.trt"));

    ASSERT_EQUAL(1, firstTexture1D->GetNumLevels());

    ASSERT_EQUAL(1, firstTexture1D->GetNumDimensions());
    ASSERT_EQUAL(16, firstTexture1D->GetDimension(0, 0));
    ASSERT_EQUAL(0, firstTexture1D->GetLevelOffset(0, 0));

    ASSERT_EQUAL(16, firstTexture1D->GetLength());
}

void Rendering::Texture1DTesting::MipmapsTest()
{
    Texture1DSharedPtr firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture1D.trt"));

    ASSERT_FALSE(firstTexture1D->HasMipmaps());
}

void Rendering::Texture1DTesting::StreamTest()
{
    Texture1DSharedPtr firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture1D.trt"));
}

void Rendering::Texture1DTesting::FileTest()
{
    Texture1DSharedPtr firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture1D.trt"));

    SaveTexture::SaveToFile(*firstTexture1D, SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture1D.trt"));

    Texture1DSharedPtr secondTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture1D.trt"));

    ASSERT_EQUAL(firstTexture1D->GetNumLevels(), secondTexture1D->GetNumLevels());

    ASSERT_EQUAL(firstTexture1D->GetNumDimensions(), secondTexture1D->GetNumDimensions());

    for (int i = 0; i < firstTexture1D->GetNumLevels(); ++i)
    {
        ASSERT_EQUAL(firstTexture1D->GetDimension(0, i), secondTexture1D->GetDimension(0, i));
        ASSERT_EQUAL(firstTexture1D->GetNumLevelBytes(i), secondTexture1D->GetNumLevelBytes(i));
        ASSERT_EQUAL(firstTexture1D->GetLevelOffset(0, i), secondTexture1D->GetLevelOffset(0, i));
    }

    ASSERT_EQUAL(firstTexture1D->GetLength(), secondTexture1D->GetLength());

    for (int i = 0; i < secondTexture1D->GetNumLevels(); ++i)
    {
        for (int k = 0; k < secondTexture1D->GetNumLevelBytes(i); ++k)
        {
        }
    }
}
