///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:33)

#include "MaterialTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/LocalEffects/Material.h"

Rendering::MaterialTesting::MaterialTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, MaterialTesting)

void Rendering::MaterialTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::MaterialTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::MaterialTesting::BaseTest()
{
    auto firstMaterial = Material::Create("Material");

    ASSERT_TRUE(Approximate(firstMaterial->GetEmissive(), Material::ColourType(0.0f, 0.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetAmbient(), Material::ColourType(0.0f, 0.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetDiffuse(), Material::ColourType(0.0f, 0.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetSpecular(), Material::ColourType(0.0f, 0.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_APPROXIMATE(firstMaterial->GetAlpha(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMaterial->GetSpecularExponent(), 1.0f, 1e-8f);

    firstMaterial->SetEmissive(Material::ColourType(1.0f, 0.0f, 0.0f, 1.0f));
    firstMaterial->SetAmbient(Material::ColourType(0.0f, 1.0f, 0.0f, 1.0f));
    firstMaterial->SetDiffuse(Material::ColourType(0.0f, 0.0f, 1.0f, 0.0f));
    firstMaterial->SetSpecular(Material::ColourType(0.0f, 1.0f, 0.0f, 1.0f));

    ASSERT_TRUE(Approximate(firstMaterial->GetEmissive(), Material::ColourType(1.0f, 0.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetAmbient(), Material::ColourType(0.0f, 1.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetDiffuse(), Material::ColourType(0.0f, 0.0f, 1.0f, 0.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetSpecular(), Material::ColourType(0.0f, 1.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_APPROXIMATE(firstMaterial->GetAlpha(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMaterial->GetSpecularExponent(), 1.0f, 1e-8f);

    auto secondMaterial = Material::Create("Material", Material::ColourType(0.1f, 0.2f, 0.3f, 1.0f), Material::ColourType(0.2f, 0.3f, 0.4f, 1.0f),
                                           Material::ColourType(0.5f, 0.6f, 0.7f, 0.0f), Material::ColourType(0.8f, 0.9f, 1.0f, 1.0f));

    ASSERT_TRUE(Approximate(secondMaterial->GetEmissive(), Material::ColourType(0.1f, 0.2f, 0.3f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(secondMaterial->GetAmbient(), Material::ColourType(0.2f, 0.3f, 0.4f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(secondMaterial->GetDiffuse(), Material::ColourType(0.5f, 0.6f, 0.7f, 0.0f), 1e-8f));
    ASSERT_TRUE(Approximate(secondMaterial->GetSpecular(), Material::ColourType(0.8f, 0.9f, 1.0f, 1.0f), 1e-8f));
    ASSERT_APPROXIMATE(secondMaterial->GetAlpha(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMaterial->GetSpecularExponent(), 1.0f, 1e-8f);
}
