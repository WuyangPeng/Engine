/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
/// ÁªÏµ×÷Õß£º94458936@qq.com
///
/// ±ê×¼£ºstd:c++20
/// °æ±¾£º1.0.0.4 (2024/01/10 09:58)

#include "Rendering/RenderingExport.h"

#include "LightEffectImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/LocalEffects/LightCameraGeometry.h"
#include "Rendering/LocalEffects/Lighting.h"
#include "Rendering/LocalEffects/Material.h"

Rendering::LightEffectImpl::LightEffectImpl(CoreTools::DisableNotThrow disableNotThrow)
    : material{ Material::Create("Material") },
      lighting{ Lighting::Create("Lighting") },
      geometry{ LightCameraGeometry::Create() },
      materialConstant{},
      lightingConstant{},
      geometryConstant{}
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::LightEffectImpl::LightEffectImpl(MaterialSharedPtr material,
                                            LightSharedPtr lighting,
                                            LightCameraGeometrySharedPtr geometry,
                                            int numMaterialConstantBytes,
                                            int numLightingConstantBytes,
                                            int numGeometryConstantBytes)
    : material{ std::move(material) },
      lighting{ std::move(lighting) },
      geometry{ std::move(geometry) },
      materialConstant{ std::make_shared<ConstantBuffer>("materialConstant", numMaterialConstantBytes, true) },
      lightingConstant{ std::make_shared<ConstantBuffer>("lightingConstant", numLightingConstantBytes, true) },
      geometryConstant{ std::make_shared<ConstantBuffer>("geometryConstant", numGeometryConstantBytes, true) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, LightEffectImpl)

void Rendering::LightEffectImpl::SetMaterial(const MaterialSharedPtr& aMaterial) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    material = aMaterial;
}

void Rendering::LightEffectImpl::SetLighting(const LightSharedPtr& aLighting) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    lighting = aLighting;
}

void Rendering::LightEffectImpl::SetGeometry(const LightCameraGeometrySharedPtr& aGeometry) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    geometry = aGeometry;
}

Rendering::LightEffectImpl::ConstMaterialSharedPtr Rendering::LightEffectImpl::GetMaterial() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return material;
}

Rendering::LightEffectImpl::ConstLightSharedPtr Rendering::LightEffectImpl::GetLighting() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lighting;
}

Rendering::LightEffectImpl::ConstLightCameraGeometrySharedPtr Rendering::LightEffectImpl::GetGeometry() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return geometry;
}

Rendering::LightEffectImpl::ConstConstantBufferSharedPtr Rendering::LightEffectImpl::GetMaterialConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return materialConstant.object;
}

Rendering::LightEffectImpl::ConstConstantBufferSharedPtr Rendering::LightEffectImpl::GetLightingConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lightingConstant.object;
}

Rendering::LightEffectImpl::ConstConstantBufferSharedPtr Rendering::LightEffectImpl::GetGeometryConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return geometryConstant.object;
}

Rendering::LightEffectImpl::ConstantBufferSharedPtr Rendering::LightEffectImpl::GetMaterialConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return materialConstant.object;
}

Rendering::LightEffectImpl::ConstantBufferSharedPtr Rendering::LightEffectImpl::GetLightingConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return lightingConstant.object;
}

Rendering::LightEffectImpl::ConstantBufferSharedPtr Rendering::LightEffectImpl::GetGeometryConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return geometryConstant.object;
}

std::string Rendering::LightEffectImpl::GetGLSLLitFunction()
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return R"(
        vec4 Lit(float nDotL, float nDotH, float m)
        {
          float ambient = 1.0;
          float diffuse = max(nDotL, 0.0);
          float specular = step(0.0, nDotL) * pow(max(nDotH, 0.0), m);
          return vec4(ambient, diffuse, specular, 1.0);
        }
    )";
}

CoreTools::ObjectSharedPtr Rendering::LightEffectImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    if (auto result = material->GetObjectByName(name);
        !result->IsNullObject())
    {
        return result;
    }

    if (auto result = lighting->GetObjectByName(name);
        !result->IsNullObject())
    {
        return result;
    }

    if (auto result = materialConstant->GetObjectByName(name);
        !result->IsNullObject())
    {
        return result;
    }

    if (auto result = lightingConstant->GetObjectByName(name);
        !result->IsNullObject())
    {
        return result;
    }

    return geometryConstant->GetObjectByName(name);
}

Rendering::LightEffectImpl::ObjectSharedPtrContainer Rendering::LightEffectImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto result = material->GetAllObjectsByName(name);

    auto lightingResult = lighting->GetAllObjectsByName(name);
    result.insert(result.end(), lightingResult.begin(), lightingResult.end());

    auto materialConstantResult = materialConstant->GetAllObjectsByName(name);
    result.insert(result.end(), materialConstantResult.begin(), materialConstantResult.end());

    auto lightingConstantResult = lightingConstant->GetAllObjectsByName(name);
    result.insert(result.end(), lightingConstantResult.begin(), lightingConstantResult.end());

    auto geometryConstantResult = geometryConstant->GetAllObjectsByName(name);
    result.insert(result.end(), geometryConstantResult.begin(), geometryConstantResult.end());

    return result;
}

CoreTools::ConstObjectSharedPtr Rendering::LightEffectImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (auto result = material->GetConstObjectByName(name);
        !result->IsNullObject())
    {
        return result;
    }

    if (auto result = lighting->GetConstObjectByName(name);
        !result->IsNullObject())
    {
        return result;
    }

    if (auto result = materialConstant->GetConstObjectByName(name);
        !result->IsNullObject())
    {
        return result;
    }

    if (auto result = lightingConstant->GetConstObjectByName(name);
        !result->IsNullObject())
    {
        return result;
    }

    return geometryConstant->GetConstObjectByName(name);
}

Rendering::LightEffectImpl::ConstObjectSharedPtrContainer Rendering::LightEffectImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto result = material->GetAllConstObjectsByName(name);

    auto lightingResult = lighting->GetAllConstObjectsByName(name);
    result.insert(result.end(), lightingResult.begin(), lightingResult.end());

    auto materialConstantResult = materialConstant->GetAllConstObjectsByName(name);
    result.insert(result.end(), materialConstantResult.begin(), materialConstantResult.end());

    auto lightingConstantResult = lightingConstant->GetAllConstObjectsByName(name);
    result.insert(result.end(), lightingConstantResult.begin(), lightingConstantResult.end());

    auto geometryConstantResult = geometryConstant->GetAllConstObjectsByName(name);
    result.insert(result.end(), geometryConstantResult.begin(), geometryConstantResult.end());

    return result;
}

int Rendering::LightEffectImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return material->GetStreamingSize() + lighting->GetStreamingSize() + geometry->GetStreamingSize() + materialConstant->GetStreamingSize() + lightingConstant->GetStreamingSize() + geometryConstant->GetStreamingSize();
}

void Rendering::LightEffectImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    material->Save(target);
    lighting->Save(target);
    geometry->Save(target);
    materialConstant->Save(target);
    lightingConstant->Save(target);
    geometryConstant->Save(target);
}

void Rendering::LightEffectImpl::Load(BufferSource& source)
{
    material->Load(source);
    lighting->Load(source);
    geometry->Load(source);
    materialConstant->Load(source);
    lightingConstant->Load(source);
    geometryConstant->Load(source);
}

void Rendering::LightEffectImpl::Link(ObjectLink& source)
{
    material->Link(source);
    lighting->Link(source);
    materialConstant->Link(source);
    lightingConstant->Link(source);
    geometryConstant->Link(source);
}

void Rendering::LightEffectImpl::Register(ObjectRegister& target) const
{
    if (const auto registerId = material->Register(target);
        registerId < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("material ×¢²áÊ§°Ü¡£"))
    }

    if (const auto registerId = lighting->Register(target);
        registerId < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("lighting ×¢²áÊ§°Ü¡£"))
    }

    if (const auto registerId = materialConstant->Register(target);
        registerId < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("materialConstant ×¢²áÊ§°Ü¡£"))
    }

    if (const auto registerId = lightingConstant->Register(target);
        registerId < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("lightingConstant ×¢²áÊ§°Ü¡£"))
    }

    if (const auto registerId = geometryConstant->Register(target);
        registerId < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("geometryConstant ×¢²áÊ§°Ü¡£"))
    }
}
