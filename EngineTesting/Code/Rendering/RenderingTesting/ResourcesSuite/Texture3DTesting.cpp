///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:38)

#include "Texture3DTesting.h"
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
#include "Rendering/Resources/Textures/Texture3D.h"

Rendering::Texture3DTesting::Texture3DTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture3DTesting)

void Rendering::Texture3DTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::Texture3DTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();



    CoreTools::InitTerm::ExecuteTerminator();
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

    ASSERT_FALSE(firstTexture3D->HasMipMaps());
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
