///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:31)

#ifndef RENDERING_SHADERS_SHADER_SAMPLER_DATA_IMPL_H
#define RENDERING_SHADERS_SHADER_SAMPLER_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "Rendering/Shaders/SingleShaderSamplerData.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ShaderSamplerDataImpl
    {
    public:
        using ClassType = ShaderSamplerDataImpl;
        using Colour = Colour<float>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        ShaderSamplerDataImpl() noexcept;
        explicit ShaderSamplerDataImpl(int numSamplers);

        CLASS_INVARIANT_DECLARE;

        void Resize(int number);

        void SetSampler(int index, const std::string& name, ShaderFlags::SamplerType type);
        void SetFilter(int index, ShaderFlags::SamplerFilter filter);
        void SetCoordinate(int index, int dimension, ShaderFlags::SamplerCoordinate coordinate);
        void SetLodBias(int index, float lodBias);
        void SetAnisotropy(int index, float anisotropy);
        void SetBorderColor(int index, const Colour& borderColor);

        NODISCARD int GetNumSamplers() const;
        NODISCARD std::string GetSamplerName(int index) const;
        NODISCARD ShaderFlags::SamplerType GetSamplerType(int index) const;
        NODISCARD ShaderFlags::SamplerFilter GetFilter(int index) const;
        NODISCARD ShaderFlags::SamplerCoordinate GetCoordinate(int index, int dimension) const;
        NODISCARD float GetLodBias(int index) const;
        NODISCARD float GetAnisotropy(int index) const;
        NODISCARD Colour GetBorderColor(int index) const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        std::vector<SingleShaderSamplerData> singleShaderSamplerData;
    };
}

#endif  // RENDERING_SHADERS_SHADER_SAMPLER_DATA_IMPL_H
