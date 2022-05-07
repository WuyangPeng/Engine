///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 16:34)

#ifndef RENDERING_SHADERS_SHADER_SAMPLER_DATA_H
#define RENDERING_SHADERS_SHADER_SAMPLER_DATA_H

#include "Rendering/RenderingDll.h"

#include "Flags/ShaderFlags.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Colour.h"

#include <string>
#include <vector>

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(ShaderSamplerData, ShaderSamplerDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderSamplerData
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ShaderSamplerData);
        using Colour = Colour<float>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit ShaderSamplerData(int numSamplers);

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
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_SHADER_SAMPLER_DATA_H
