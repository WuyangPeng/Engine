///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/06 09:42)

#ifndef RENDERING_LOCAL_EFFECTS_LIGHT_EFFECT_IMPL_H
#define RENDERING_LOCAL_EFFECTS_LIGHT_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/Contract/ContractFwd.h"
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

        using ObjectLink = CoreTools::ObjectLink;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using ObjectRegister = CoreTools::ObjectRegister;
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
        explicit LightEffectImpl(CoreTools::DisableNotThrow disableNotThrow);
        LightEffectImpl(MaterialSharedPtr material,
                        LightSharedPtr lighting,
                        LightCameraGeometrySharedPtr geometry,
                        int numMaterialConstantBytes,
                        int numLightingConstantBytes,
                        int numGeometryConstantBytes);

        CLASS_INVARIANT_DECLARE;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        NODISCARD int GetStreamingSize() const;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);
        void Link(ObjectLink& source);
        void Register(ObjectRegister& target) const;

        void SetMaterial(const MaterialSharedPtr& aMaterial) noexcept;
        void SetLighting(const LightSharedPtr& aLighting) noexcept;
        void SetGeometry(const LightCameraGeometrySharedPtr& aGeometry) noexcept;

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