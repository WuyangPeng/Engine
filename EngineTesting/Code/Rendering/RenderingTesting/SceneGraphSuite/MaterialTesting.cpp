///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:33)

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

    ASSERT_TRUE(Approximate(firstMaterial->GetEmissive(), Material::Colour(0.0f, 0.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetAmbient(), Material::Colour(0.0f, 0.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetDiffuse(), Material::Colour(0.0f, 0.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetSpecular(), Material::Colour(0.0f, 0.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_APPROXIMATE(firstMaterial->GetAlpha(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMaterial->GetSpecularExponent(), 1.0f, 1e-8f);

    firstMaterial->SetEmissive(Material::Colour(1.0f, 0.0f, 0.0f, 1.0f));
    firstMaterial->SetAmbient(Material::Colour(0.0f, 1.0f, 0.0f, 1.0f));
    firstMaterial->SetDiffuse(Material::Colour(0.0f, 0.0f, 1.0f, 0.0f));
    firstMaterial->SetSpecular(Material::Colour(0.0f, 1.0f, 0.0f, 1.0f));

    ASSERT_TRUE(Approximate(firstMaterial->GetEmissive(), Material::Colour(1.0f, 0.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetAmbient(), Material::Colour(0.0f, 1.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetDiffuse(), Material::Colour(0.0f, 0.0f, 1.0f, 0.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetSpecular(), Material::Colour(0.0f, 1.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_APPROXIMATE(firstMaterial->GetAlpha(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMaterial->GetSpecularExponent(), 1.0f, 1e-8f);

    auto secondMaterial = Material::Create("Material", Material::Colour(0.1f, 0.2f, 0.3f, 1.0f), Material::Colour(0.2f, 0.3f, 0.4f, 1.0f),
                                           Material::Colour(0.5f, 0.6f, 0.7f, 0.0f), Material::Colour(0.8f, 0.9f, 1.0f, 1.0f));

    ASSERT_TRUE(Approximate(secondMaterial->GetEmissive(), Material::Colour(0.1f, 0.2f, 0.3f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(secondMaterial->GetAmbient(), Material::Colour(0.2f, 0.3f, 0.4f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(secondMaterial->GetDiffuse(), Material::Colour(0.5f, 0.6f, 0.7f, 0.0f), 1e-8f));
    ASSERT_TRUE(Approximate(secondMaterial->GetSpecular(), Material::Colour(0.8f, 0.9f, 1.0f, 1.0f), 1e-8f));
    ASSERT_APPROXIMATE(secondMaterial->GetAlpha(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMaterial->GetSpecularExponent(), 1.0f, 1e-8f);
}
