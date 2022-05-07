// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/05 10:52)

#include "MaterialTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/SceneGraph/Material.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, MaterialTesting)

void Rendering::MaterialTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::MaterialTesting::BaseTest()
{
    auto firstMaterial = Material::Create();

    ASSERT_TRUE(Approximate(firstMaterial->GetEmissive(), Material::Colour(0.0f, 0.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetAmbient(), Material::Colour(0.0f, 0.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetDiffuse(), Material::Colour(0.0f, 0.0f, 0.0f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(firstMaterial->GetSpecular(), Material::Colour(0.0f, 0.0f, 0.0f, 0.0f), 1e-8f));
    ASSERT_APPROXIMATE(firstMaterial->GetAlpha(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMaterial->GetSpecularExponent(), 0.0f, 1e-8f);

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

    auto secondMaterial = Material::Create(Material::Colour(0.1f, 0.2f, 0.3f, 1.0f), Material::Colour(0.2f, 0.3f, 0.4f, 1.0f),
                                           Material::Colour(0.5f, 0.6f, 0.7f, 0.0f), Material::Colour(0.8f, 0.9f, 1.0f, 1.0f));

    ASSERT_TRUE(Approximate(secondMaterial->GetEmissive(), Material::Colour(0.1f, 0.2f, 0.3f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(secondMaterial->GetAmbient(), Material::Colour(0.2f, 0.3f, 0.4f, 1.0f), 1e-8f));
    ASSERT_TRUE(Approximate(secondMaterial->GetDiffuse(), Material::Colour(0.5f, 0.6f, 0.7f, 0.0f), 1e-8f));
    ASSERT_TRUE(Approximate(secondMaterial->GetSpecular(), Material::Colour(0.8f, 0.9f, 1.0f, 1.0f), 1e-8f));
    ASSERT_APPROXIMATE(secondMaterial->GetAlpha(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMaterial->GetSpecularExponent(), 1.0f, 1e-8f);
}
