///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/25 14:54)

#ifndef RENDERING_LOCAL_EFFECTS_LIGHT_EFFECT_IMPL_H
#define RENDERING_LOCAL_EFFECTS_LIGHT_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/Shaders/Flags/ShaderAPIType.h"
#include "Rendering/Shaders/ShadersFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE LightEffectImpl
    {
    public:
        using ClassType = LightEffectImpl;
        using ProgramFactorySharedPtr = std::shared_ptr<ProgramFactory>;
        using ProgramSources = std::array<std::string, System::EnumCastUnderlying(ShaderAPIType::NumAPI)>;
        using MaterialSharedPtr = std::shared_ptr<Material>;
        using ConstMaterialSharedPtr = std::shared_ptr<const Material>;
        using LightSharedPtr = std::shared_ptr<Light>;
        using ConstLightSharedPtr = std::shared_ptr<const Light>;
        using LightCameraGeometrySharedPtr = std::shared_ptr<LightCameraGeometry>;
        using ConstLightCameraGeometrySharedPtr = std::shared_ptr<const LightCameraGeometry>;
        using ConstantBufferObjectAssociated = CoreTools::ObjectAssociated<ConstantBuffer>;
        using ConstantBufferSharedPtr = std::shared_ptr<ConstantBuffer>;
        using ConstConstantBufferSharedPtr = std::shared_ptr<const ConstantBuffer>;

    public:
        LightEffectImpl(const MaterialSharedPtr& material,
                        const LightSharedPtr& lighting,
                        const LightCameraGeometrySharedPtr& geometry) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetMaterial(const MaterialSharedPtr& aMaterial) noexcept;
        void SetLighting(const LightSharedPtr& aLighting) noexcept;
        void SetGeometry(const LightCameraGeometrySharedPtr& aGeometry) noexcept;

        NODISCARD ConstMaterialSharedPtr GetMaterial() const noexcept;
        NODISCARD ConstLightSharedPtr GetLighting() const noexcept;
        NODISCARD ConstLightCameraGeometrySharedPtr GetGeometry() const noexcept;

        NODISCARD ConstConstantBufferSharedPtr GetMaterialConstant() const noexcept;
        NODISCARD ConstConstantBufferSharedPtr GetLightingConstant() const noexcept;
        NODISCARD ConstConstantBufferSharedPtr GetGeometryConstant() const noexcept;

    protected:
        NODISCARD static std::string GetGLSLLitFunction();

    private:
        MaterialSharedPtr material;
        LightSharedPtr lighting;
        LightCameraGeometrySharedPtr geometry;

        ConstantBufferObjectAssociated materialConstant;
        ConstantBufferObjectAssociated lightingConstant;
        ConstantBufferObjectAssociated geometryConstant;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_LIGHT_EFFECT_IMPL_H