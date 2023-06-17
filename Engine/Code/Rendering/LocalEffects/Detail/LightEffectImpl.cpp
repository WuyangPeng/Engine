///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:43)

#include "Rendering/RenderingExport.h"

#include "LightEffectImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::LightEffectImpl::LightEffectImpl(const MaterialSharedPtr& material,
                                            const LightSharedPtr& lighting,
                                            const LightCameraGeometrySharedPtr& geometry) noexcept
    : material{ material },
      lighting{ lighting },
      geometry{ geometry },
      materialConstant{},
      lightingConstant{},
      geometryConstant{}
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

std::string Rendering::LightEffectImpl::GetGLSLLitFunction()
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return R"(
        vec4 Lit(float nDotL, float nDotH, float m)
        {
          float ambient = 1.0;
          float diffuse = max(nDotL, 0.0);
          float specular = step(0.0, NdotL) * pow(max(nDotH, 0.0), m);
          return vec4(ambient, diffuse, specular, 1.0);
        }
    )";
}
