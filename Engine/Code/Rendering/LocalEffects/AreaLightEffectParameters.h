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
        using ColourType = Colour<float>;

    public:
        NODISCARD static AreaLightEffectParameters Create();

        CLASS_INVARIANT_DECLARE;

        NODISCARD ColourType GetAmbient() const noexcept;
        void SetAmbient(const ColourType& ambient) noexcept;
        NODISCARD ColourType GetDiffuse() const noexcept;
        void SetDiffuse(const ColourType& diffuse) noexcept;
        NODISCARD ColourType GetSpecular() const noexcept;
        void SetSpecular(const ColourType& specular) noexcept;
        NODISCARD ColourType GetAttenuation() const noexcept;
        void SetAttenuation(const ColourType& attenuation) noexcept;
        NODISCARD ColourType GetPosition() const noexcept;
        void SetPosition(const ColourType& position) noexcept;
        NODISCARD ColourType GetNormal() const noexcept;
        void SetNormal(const ColourType& normal) noexcept;
        NODISCARD ColourType GetAxis0() const noexcept;
        void SetAxis0(const ColourType& axis0) noexcept;
        NODISCARD ColourType GetAxis1() const noexcept;
        void SetAxis1(const ColourType& axis1) noexcept;
        NODISCARD ColourType GetExtent() const noexcept;
        void SetExtent(const ColourType& extent) noexcept;

        NODISCARD int GetStreamingSize() const noexcept;

    private:
        explicit AreaLightEffectParameters(CoreTools::DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_PARAMETERS_H
