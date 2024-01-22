/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 10:17)

#ifndef RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_PARAMETERS_H
#define RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_PARAMETERS_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/DataTypes/Colour.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(AreaLightEffectParameters, AreaLightEffectParametersImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE AreaLightEffectParameters
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(AreaLightEffectParameters);
        using Colour = Colour<float>;

    public:
        NODISCARD static AreaLightEffectParameters Create();

        CLASS_INVARIANT_DECLARE;

        NODISCARD Colour GetAmbient() const noexcept;
        void SetAmbient(const Colour& ambient) noexcept;
        NODISCARD Colour GetDiffuse() const noexcept;
        void SetDiffuse(const Colour& diffuse) noexcept;
        NODISCARD Colour GetSpecular() const noexcept;
        void SetSpecular(const Colour& specular) noexcept;
        NODISCARD Colour GetAttenuation() const noexcept;
        void SetAttenuation(const Colour& attenuation) noexcept;
        NODISCARD Colour GetPosition() const noexcept;
        void SetPosition(const Colour& position) noexcept;
        NODISCARD Colour GetNormal() const noexcept;
        void SetNormal(const Colour& normal) noexcept;
        NODISCARD Colour GetAxis0() const noexcept;
        void SetAxis0(const Colour& axis0) noexcept;
        NODISCARD Colour GetAxis1() const noexcept;
        void SetAxis1(const Colour& axis1) noexcept;
        NODISCARD Colour GetExtent() const noexcept;
        void SetExtent(const Colour& extent) noexcept;

        NODISCARD int GetStreamingSize() const noexcept;

    private:
        explicit AreaLightEffectParameters(CoreTools::DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_PARAMETERS_H
