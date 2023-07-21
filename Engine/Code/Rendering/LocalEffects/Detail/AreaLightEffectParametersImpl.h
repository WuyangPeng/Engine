///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/07 10:39)

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
        using Colour = Colour<float>;

    public:
        AreaLightEffectParametersImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Colour GetAmbient() const noexcept;
        void SetAmbient(const Colour& aAmbient) noexcept;
        NODISCARD Colour GetDiffuse() const noexcept;
        void SetDiffuse(const Colour& aDiffuse) noexcept;
        NODISCARD Colour GetSpecular() const noexcept;
        void SetSpecular(const Colour& aSpecular) noexcept;
        NODISCARD Colour GetAttenuation() const noexcept;
        void SetAttenuation(const Colour& aAttenuation) noexcept;
        NODISCARD Colour GetPosition() const noexcept;
        void SetPosition(const Colour& aPosition) noexcept;
        NODISCARD Colour GetNormal() const noexcept;
        void SetNormal(const Colour& aNormal) noexcept;
        NODISCARD Colour GetAxis0() const noexcept;
        void SetAxis0(const Colour& aAxis0) noexcept;
        NODISCARD Colour GetAxis1() const noexcept;
        void SetAxis1(const Colour& aAxis1) noexcept;
        NODISCARD Colour GetExtent() const noexcept;
        void SetExtent(const Colour& aExtent) noexcept;

        NODISCARD int GetStreamingSize() const noexcept;

    private:
        Colour ambient;
        Colour diffuse;
        Colour specular;
        Colour attenuation;
        Colour position;  // (x, y, z, 1)
        Colour normal;  // (x, y, z, 0)
        Colour axis0;  // (x, y, z, 0)
        Colour axis1;  // (x, y, z, 0)
        Colour extent;  // (extent0, extent1, *, *)
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_PARAMETERS_IMPL_H
