///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/11 20:45)

#ifndef RENDERING_SHADERS_SHADER_IMPL_H
#define RENDERING_SHADERS_SHADER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "Rendering/Shaders/ShaderBaseData.h"
#include "Rendering/Shaders/ShaderConstantsData.h"
#include "Rendering/Shaders/ShaderProfileData.h"
#include "Rendering/Shaders/ShaderSamplerData.h"

#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ShaderBaseImpl
    {
    public:
        using ClassType = ShaderBaseImpl;
        using Colour = Colour<float>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ObjectLink = CoreTools::ObjectLink;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ReadFileManager = CoreTools::ReadFileManager;
        // 默认 lodBias 是 0.
        // 默认 anisotropy 是 1.
        // 默认 borderColor 是 (0,0,0,0).

    public:
        ShaderBaseImpl(int numInputs, int numOutputs);
        ShaderBaseImpl(int numInputs, int numOutputs, int numConstants, int numSamplers);

        CLASS_INVARIANT_DECLARE;

        // 支持延迟构造
        void SetInput(int index, const std::string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic);

        void SetOutput(int index, const std::string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic);

        void SetConstant(int index, const std::string& name, int numRegistersUsed);

        void SetSampler(int index, const std::string& name, ShaderFlags::SamplerType type);
        void SetFilter(int index, ShaderFlags::SamplerFilter filter);
        void SetCoordinate(int index, int dimension, ShaderFlags::SamplerCoordinate coordinate);
        void SetLodBias(int index, float lodBias);
        void SetAnisotropy(int index, float anisotropy);
        void SetBorderColor(int index, const Colour& borderColor);

        // 配置文件无关的数据。
        NODISCARD int GetNumInputs() const;
        NODISCARD std::string GetInputName(int index) const;
        NODISCARD ShaderFlags::VariableType GetInputType(int index) const;
        NODISCARD ShaderFlags::VariableSemantic GetInputSemantic(int index) const;

        NODISCARD int GetNumOutputs() const;
        NODISCARD std::string GetOutputName(int index) const;
        NODISCARD ShaderFlags::VariableType GetOutputType(int index) const;
        NODISCARD ShaderFlags::VariableSemantic GetOutputSemantic(int index) const;

        NODISCARD int GetNumConstants() const;
        NODISCARD std::string GetConstantName(int index) const;
        NODISCARD int GetNumRegistersUsed(int index) const;

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
        void Link(MAYBE_UNUSED CoreTools::ObjectLink& source) noexcept;
        void Register(MAYBE_UNUSED CoreTools::ObjectRegister& target) const noexcept;

        void SaveShader(WriteFileManager& manager) const;
        void LoadShader(ReadFileManager& manager, int numProfiles);

        void SetProfile(const ShaderProfileDataSharedPtr& aProfile) noexcept;
        NODISCARD ConstShaderProfileDataSharedPtr GetProfile() const noexcept;
        NODISCARD ShaderProfileDataSharedPtr GetProfile() noexcept;

    private:
        ShaderBaseData input;
        ShaderBaseData output;
        ShaderConstantsData constants;
        ShaderSamplerData sampler;
        ShaderProfileDataSharedPtr profile;
    };
}

#endif  // RENDERING_SHADERS_SHADER_IMPL_H
