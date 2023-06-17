///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:44)

#ifndef RENDERING_SHADERS_SINGLES_SHADER_SAMPLER_DATA_H
#define RENDERING_SHADERS_SINGLES_SHADER_SAMPLER_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

#include <string>

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(SingleShaderSamplerData, SingleShaderSamplerDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SingleShaderSamplerData
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(SingleShaderSamplerData);
        using Colour = Colour<float>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit SingleShaderSamplerData(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        void SetSampler(const std::string& name, ShaderFlags::SamplerType type);
        void SetFilter(ShaderFlags::SamplerFilter filter);
        void SetCoordinate(int dimension, ShaderFlags::SamplerCoordinate coordinate);
        void SetLodBias(float lodBias);
        void SetAnisotropy(float anisotropy);
        void SetBorderColor(const Colour& borderColor);

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
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_SINGLES_SHADER_SAMPLER_DATA_H
