///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:43)

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

        // Ĭ�� lodBias �� 0.
        // Ĭ�� anisotropy �� 1.
        // Ĭ�� borderColor �� (0,0,0,0).

    public:
        // ����VertexShader��PixelShader�Ļ��ࡣ
        // �����ݵĶ�����ɫ��������������ɫ����������ɫ�������ʵ����
        // ��ˣ���ɫ����ÿ��ʵ�������ǵ�����ͨ����shaderName����ʶ��
        // ���λ�ͼ�漰��ɫ���������ࣩ��ShaderParameters�������������ʵ������

        // ���캯��������붯̬�ط��䡣��ɫ���е�ɾ�����ǵ����Ρ�
        // ֱ��ͨ��SetProgram�����ṩ�����г������ڸ����Ͳģ�
        // ��ɫ���Ľṹ�ǲ������ġ�
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
