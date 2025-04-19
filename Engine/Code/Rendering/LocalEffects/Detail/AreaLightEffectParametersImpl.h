/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 10:17)

#ifndef RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_PARAMETERS_IMPL_H
#define RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_PARAMETERS_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Colour.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE AreaLightEffectParametersImpl
    {
    public:
        using ClassType = AreaLightEffectParametersImpl;

        using ColourType = Colour<float>;

    public:
        AreaLightEffectParametersImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ColourType GetAmbient() const noexcept;
        void SetAmbient(const ColourType& aAmbient) noexcept;
        NODISCARD ColourType GetDiffuse() const noexcept;
        void SetDiffuse(const ColourType& aDiffuse) noexcept;
        NODISCARD ColourType GetSpecular() const noexcept;
        void SetSpecular(const ColourType& aSpecular) noexcept;
        NODISCARD ColourType GetAttenuation() const noexcept;
        void SetAttenuation(const ColourType& aAttenuation) noexcept;
        NODISCARD ColourType GetPosition() const noexcept;
        void SetPosition(const ColourType& aPosition) noexcept;
        NODISCARD ColourType GetNormal() const noexcept;
        void SetNormal(const ColourType& aNormal) noexcept;
        NODISCARD ColourType GetAxis0() const noexcept;
        void SetAxis0(const ColourType& aAxis0) noexcept;
        NODISCARD ColourType GetAxis1() const noexcept;
        void SetAxis1(const ColourType& aAxis1) noexcept;
        NODISCARD ColourType GetExtent() const noexcept;
        void SetExtent(const ColourType& aExtent) noexcept;

        NODISCARD int GetStreamingSize() const noexcept;

    private:
        ColourType ambient;
        ColourType diffuse;
        ColourType specular;
        ColourType attenuation;
        ColourType position;  // (x, y, z, 1)
        ColourType normal;  // (x, y, z, 0)
        ColourType axis0;  // (x, y, z, 0)
        ColourType axis1;  // (x, y, z, 0)
        ColourType extent;  // (extent0, extent1, *, *)
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_PARAMETERS_IMPL_H
