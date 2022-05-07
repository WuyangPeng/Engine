///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/12 15:03)

#ifndef RENDERING_SHADERS_SINGLES_SHADER_SAMPLER_DATA_IMPL_H
#define RENDERING_SHADERS_SINGLES_SHADER_SAMPLER_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

#include <array>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SingleShaderSamplerDataImpl
    {
    public:
        using ClassType = SingleShaderSamplerDataImpl;
        using Colour = Colour<float>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        SingleShaderSamplerDataImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetSampler(const std::string& name, ShaderFlags::SamplerType type);
        void SetFilter(ShaderFlags::SamplerFilter aFilter) noexcept;
        void SetCoordinate(int dimension, ShaderFlags::SamplerCoordinate coordinate);
        void SetLodBias(float aLodBias) noexcept;
        void SetAnisotropy(float aAnisotropy) noexcept;
        void SetBorderColor(const Colour& aBorderColor) noexcept;

        NODISCARD std::string GetSamplerName() const;
        NODISCARD ShaderFlags::SamplerType GetSamplerType() const noexcept;
        NODISCARD ShaderFlags::SamplerFilter GetFilter() const noexcept;
        NODISCARD ShaderFlags::SamplerCoordinate GetCoordinate(int dimension) const;
        NODISCARD float GetLodBias() const noexcept;
        NODISCARD float GetAnisotropy() const noexcept;
        NODISCARD Colour GetBorderColor() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        constexpr static auto samplerCoordinateSize = 3;

    private:
        std::string samplerName;
        ShaderFlags::SamplerType samplerType;
        ShaderFlags::SamplerFilter filter;
        std::array<ShaderFlags::SamplerCoordinate, samplerCoordinateSize> coordinates;
        float lodBias;
        float anisotropy;
        Colour borderColor;
    };
}

#endif  // RENDERING_SHADERS_SINGLES_SHADER_SAMPLER_DATA_IMPL_H
