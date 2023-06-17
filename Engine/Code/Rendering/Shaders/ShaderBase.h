///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:43)

#ifndef RENDERING_SHADERS_SHADER_H
#define RENDERING_SHADERS_SHADER_H

#include "Rendering/RenderingDll.h"

#include "ShaderProfileData.h"
#include "Flags/ShaderFlags.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Colour.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ShaderBase, ShaderBaseImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderBase : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ShaderBase);
        using ParentType = Object;
        using Colour = Colour<float>;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        ~ShaderBase() noexcept = 0;
        ShaderBase(const ShaderBase& rhs) = default;
        ShaderBase& operator=(const ShaderBase& rhs) = default;
        ShaderBase(ShaderBase&& rhs) noexcept = default;
        ShaderBase& operator=(ShaderBase&& rhs) noexcept = default;

        // 默认 lodBias 是 0.
        // 默认 anisotropy 是 1.
        // 默认 borderColor 是 (0,0,0,0).

    public:
        // 类是VertexShader和PixelShader的基类。
        // 类数据的定义着色器，但不包含着色器常数和着色器纹理的实例。
        // 因此，着色器的每个实例可能是单例，通过“shaderName”标识。
        // 几何绘图涉及着色器（抽象类）和ShaderParameters（常量和纹理的实例）。

        // 构造函数数组必须动态地分配。着色器承担删除它们的责任。
        // 直到通过SetProgram函数提供的所有程序（用于各种型材）
        // 着色器的结构是不完整的。
        ShaderBase(const std::string& programName, int numInputs, int numOutputs, int numConstants, int numSamplers);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ShaderBase);

        void SetInput(int index, const std::string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic);

        void SetOutput(int index, const std::string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic);

        void SetConstant(int index, const std::string& name, int numRegistersUsed);

        void SetSampler(int index, const std::string& name, ShaderFlags::SamplerType type);
        void SetFilter(int index, ShaderFlags::SamplerFilter filter);
        void SetCoordinate(int index, int dimension, ShaderFlags::SamplerCoordinate coordinate);
        void SetLodBias(int index, float lodBias);
        void SetAnisotropy(int index, float anisotropy);
        void SetBorderColor(int index, const Colour& borderColor);

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

        void SaveShader(WriteFileManager& manager) const;
        void LoadShader(ReadFileManager& manager, int numProfiles);

        void SetProfile(const ShaderProfileDataSharedPtr& profile) noexcept;
        NODISCARD ConstShaderProfileDataSharedPtr GetProfile() const noexcept;

        NODISCARD ShaderProfileDataSharedPtr GetProfile() noexcept;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ShaderBase);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ShaderBase);
}

#endif  // RENDERING_SHADERS_SHADER_H
