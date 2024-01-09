///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/06 10:17)

#ifndef RENDERING_LOCAL_EFFECTS_LIGHT_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_LIGHT_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(LightEffect, LightEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE LightEffect : public VisualEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(LightEffect);
        using ParentType = VisualEffect;

        using MaterialSharedPtr = std::shared_ptr<Material>;
        using ConstMaterialSharedPtr = std::shared_ptr<const Material>;
        using LightSharedPtr = std::shared_ptr<Lighting>;
        using ConstLightSharedPtr = std::shared_ptr<const Lighting>;
        using LightCameraGeometrySharedPtr = std::shared_ptr<LightCameraGeometry>;
        using ConstLightCameraGeometrySharedPtr = std::shared_ptr<const LightCameraGeometry>;
        using ConstantBufferSharedPtr = std::shared_ptr<ConstantBuffer>;
        using ConstConstantBufferSharedPtr = std::shared_ptr<const ConstantBuffer>;
        using BaseRendererSharedPtr = std::shared_ptr<BaseRenderer>;

    public:
        explicit LightEffect(ProgramFactory& factory,
                             const BaseRendererSharedPtr& baseRenderer,
                             const std::string& vertexShaderFile,
                             const std::string& pixelShaderFile,
                             const MaterialSharedPtr& material,
                             const LightSharedPtr& lighting,
                             const LightCameraGeometrySharedPtr& geometry,
                             int numMaterialConstantBytes,
                             int numLightingConstantBytes,
                             int numGeometryConstantBytes);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(LightEffect);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        void SetMaterial(const MaterialSharedPtr& material) noexcept;
        void SetLighting(const LightSharedPtr& lighting) noexcept;
        void SetGeometry(const LightCameraGeometrySharedPtr& geometry) noexcept;

        NODISCARD ConstMaterialSharedPtr GetMaterial() const noexcept;
        NODISCARD ConstLightSharedPtr GetLighting() const noexcept;
        NODISCARD ConstLightCameraGeometrySharedPtr GetGeometry() const noexcept;

        NODISCARD ConstConstantBufferSharedPtr GetMaterialConstant() const noexcept;
        NODISCARD ConstConstantBufferSharedPtr GetLightingConstant() const noexcept;
        NODISCARD ConstConstantBufferSharedPtr GetGeometryConstant() const noexcept;

        NODISCARD ConstantBufferSharedPtr GetMaterialConstant() noexcept;
        NODISCARD ConstantBufferSharedPtr GetLightingConstant() noexcept;
        NODISCARD ConstantBufferSharedPtr GetGeometryConstant() noexcept;

        NODISCARD static std::string GetGLSLLitFunction();

        virtual void UpdateMaterialConstant();
        virtual void UpdateLightingConstant();
        virtual void UpdateGeometryConstant();

        void SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer) override;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_LIGHT_EFFECT_H
