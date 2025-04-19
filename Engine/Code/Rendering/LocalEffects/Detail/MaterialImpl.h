/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 20:35)

#ifndef RENDERING_LOCAL_EFFECTS_MATERIAL_IMPL_H
#define RENDERING_LOCAL_EFFECTS_MATERIAL_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/DataTypes/Colour.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE MaterialImpl
    {
    public:
        using ClassType = MaterialImpl;

        using ColourType = Colour<float>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        MaterialImpl() noexcept;
        MaterialImpl(const ColourType& emissive, const ColourType& ambient, const ColourType& diffuse, const ColourType& specular) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        NODISCARD ColourType GetEmissive() const noexcept;
        NODISCARD ColourType GetAmbient() const noexcept;
        NODISCARD ColourType GetDiffuse() const noexcept;
        NODISCARD ColourType GetSpecular() const noexcept;

        void SetEmissive(const ColourType& aEmissive) noexcept;
        void SetAmbient(const ColourType& aAmbient) noexcept;
        void SetDiffuse(const ColourType& aDiffuse) noexcept;
        void SetSpecular(const ColourType& aSpecular) noexcept;

        NODISCARD float GetAlpha() const noexcept;
        NODISCARD float GetSpecularExponent() const noexcept;

    private:
        ColourType emissive;  // 默认: (0,0,0,1)
        ColourType ambient;  // 默认: (0,0,0,1)

        // 材料的alpha使用diffuse的alpha通道
        ColourType diffuse;  // 默认: (0,0,0,1)

        // 材料的镜面指数使用specular的alpha通道
        ColourType specular;  // 默认: (0,0,0,1)
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_MATERIAL_IMPL_H
