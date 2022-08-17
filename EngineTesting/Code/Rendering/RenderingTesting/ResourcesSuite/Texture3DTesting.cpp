///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/15 16:10)

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
#include "Rendering/Resources/Textures/LoadTexture.h"
#include "Rendering/Resources/Textures/SaveTexture.h"
#include "Rendering/Resources/Textures/Texture3D.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, Texture3DTesting)

void Rendering::Texture3DTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    RendererManager::Create();

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::Texture3DTesting::BaseTest()
{
    Texture3DSharedPtr firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture3D.trt"));

    ASSERT_EQUAL(1, firstTexture3D->GetNumLevels());

    ASSERT_EQUAL(3, firstTexture3D->GetNumDimensions());
    ASSERT_EQUAL(16, firstTexture3D->GetDimension(0, 0));
    ASSERT_EQUAL(12, firstTexture3D->GetDimension(1, 0));
    ASSERT_EQUAL(8, firstTexture3D->GetDimension(2, 0));

    ASSERT_EQUAL(16, firstTexture3D->GetWidth());
    ASSERT_EQUAL(12, firstTexture3D->GetHeight());
    ASSERT_EQUAL(8, firstTexture3D->GetThickness());
}

void Rendering::Texture3DTesting::MipmapsTest()
{
    Texture3DSharedPtr firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture3D.trt"));

    ASSERT_FALSE(firstTexture3D->HasMipmaps());
}

void Rendering::Texture3DTesting::StreamTest()
{
    Texture3DSharedPtr firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture3D.trt"));
}

void Rendering::Texture3DTesting::FileTest()
{
    Texture3DSharedPtr firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/Texture3D.trt"));

    SaveTexture::SaveToFile(*firstTexture3D, SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture3D.trt"));

    Texture3DSharedPtr secondTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/ResourcesSuite/MipmapsTexture3D.trt"));
}
