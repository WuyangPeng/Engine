/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 09:59)

#include "Rendering/RenderingExport.h"

#include "LightEffect.h"
#include "Detail/LightEffectImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Buffers/ConstantBufferDetail.h"
#include "Rendering/Shaders/ShaderDetail.h"
#include "Rendering/Shaders/VisualProgram.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, LightEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, LightEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightEffect);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, LightEffect)

Rendering::LightEffect::LightEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, LightEffect)
CORE_TOOLS_WITH_IMPL_OBJECT_REGISTER_DEFINE(Rendering, LightEffect)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, LightEffect)
CORE_TOOLS_WITH_IMPL_OBJECT_LINK_DEFINE(Rendering, LightEffect)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, LightEffect)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, LightEffect)

Rendering::LightEffect::LightEffect(const std::string& name,
                                    ProgramFactory& factory,
                                    const BaseRendererSharedPtr& baseRenderer,
                                    const std::string& vertexShaderFile,
                                    const std::string& pixelShaderFile,
                                    const MaterialSharedPtr& material,
                                    const LightSharedPtr& lighting,
                                    const LightCameraGeometrySharedPtr& geometry,
                                    int numMaterialConstantBytes,
                                    int numLightingConstantBytes,
                                    int numGeometryConstantBytes)
    : ParentType{ name, factory, baseRenderer, vertexShaderFile, pixelShaderFile },
      impl{ material, lighting, geometry, numMaterialConstantBytes, numLightingConstantBytes, numGeometryConstantBytes }
{
    const auto vertexShader = GetVertexShader();

    vertexShader->Set("ProjectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, LightEffect)

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::LightEffect::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

void Rendering::LightEffect::SetMaterial(const MaterialSharedPtr& material) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetMaterial(material);
}

void Rendering::LightEffect::SetLighting(const LightSharedPtr& lighting) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLighting(lighting);
}

void Rendering::LightEffect::SetGeometry(const LightCameraGeometrySharedPtr& geometry) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetGeometry(geometry);
}

Rendering::LightEffect::ConstMaterialSharedPtr Rendering::LightEffect::GetMaterial() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetMaterial();
}

Rendering::LightEffect::ConstLightSharedPtr Rendering::LightEffect::GetLighting() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLighting();
}

Rendering::LightEffect::ConstLightCameraGeometrySharedPtr Rendering::LightEffect::GetGeometry() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetGeometry();
}

Rendering::LightEffect::ConstConstantBufferSharedPtr Rendering::LightEffect::GetMaterialConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetMaterialConstant();
}

Rendering::LightEffect::ConstConstantBufferSharedPtr Rendering::LightEffect::GetLightingConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLightingConstant();
}

Rendering::LightEffect::ConstConstantBufferSharedPtr Rendering::LightEffect::GetGeometryConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetGeometryConstant();
}

Rendering::LightEffect::ConstantBufferSharedPtr Rendering::LightEffect::GetMaterialConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetMaterialConstant();
}

Rendering::LightEffect::ConstantBufferSharedPtr Rendering::LightEffect::GetLightingConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetLightingConstant();
}

Rendering::LightEffect::ConstantBufferSharedPtr Rendering::LightEffect::GetGeometryConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetGeometryConstant();
}

std::string Rendering::LightEffect::GetGLSLLitFunction()
{
    return ImplType::GetGLSLLitFunction();
}

void Rendering::LightEffect::UpdateMaterialConstant()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto renderer = GetBaseRenderer();

    if (const auto materialConstant = GetMaterialConstant();
        materialConstant != nullptr)
    {
        if (!renderer->Update(materialConstant))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("materialConstant 更新错误。"));
        }
    }
}

void Rendering::LightEffect::UpdateLightingConstant()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto renderer = GetBaseRenderer();

    if (const auto lightingConstant = GetLightingConstant();
        lightingConstant != nullptr)
    {
        if (!renderer->Update(lightingConstant))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("lightingConstant 更新错误。"));
        }
    }
}

void Rendering::LightEffect::UpdateGeometryConstant()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto renderer = GetBaseRenderer();

    if (const auto geometryConstant = GetGeometryConstant();
        geometryConstant != nullptr)
    {
        if (!renderer->Update(geometryConstant))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("geometryConstant 更新错误。"));
        }
    }
}

void Rendering::LightEffect::SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer)
{
    ParentType::SetProjectionViewWorldMatrixConstant(buffer);

    const auto vertexShader = GetVertexShader();

    vertexShader->Set("ProjectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
}
