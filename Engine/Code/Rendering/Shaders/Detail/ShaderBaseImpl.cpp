///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/11 20:51)

#include "Rendering/RenderingExport.h"

#include "ShaderBaseImpl.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::string;

Rendering::ShaderBaseImpl::ShaderBaseImpl(int numInputs, int numOutputs, int numConstants, int numSamplers)
    : input{ numInputs }, output{ numOutputs }, constants{ numConstants }, sampler{ numSamplers }, profile{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderBaseImpl::ShaderBaseImpl(int numInputs, int numOutputs)
    : input{ numInputs }, output{ numOutputs }, constants{ 0 }, sampler{ 0 }, profile{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderBaseImpl)

void Rendering::ShaderBaseImpl::SetInput(int index, const string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic)
{
    RENDERING_CLASS_IS_VALID_9;

    input.SetData(index, name, type, semantic);
}

void Rendering::ShaderBaseImpl::SetOutput(int index, const string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic)
{
    RENDERING_CLASS_IS_VALID_9;

    output.SetData(index, name, type, semantic);
}

void Rendering::ShaderBaseImpl::SetConstant(int index, const string& name, int numRegistersUsed)
{
    RENDERING_CLASS_IS_VALID_9;

    constants.SetConstant(index, name, numRegistersUsed);
}

void Rendering::ShaderBaseImpl::SetSampler(int index, const string& name, ShaderFlags::SamplerType type)
{
    RENDERING_CLASS_IS_VALID_9;

    sampler.SetSampler(index, name, type);
}

void Rendering::ShaderBaseImpl::SetFilter(int index, ShaderFlags::SamplerFilter filter)
{
    RENDERING_CLASS_IS_VALID_9;

    sampler.SetFilter(index, filter);
}

void Rendering::ShaderBaseImpl::SetCoordinate(int index, int dimension, ShaderFlags::SamplerCoordinate coordinate)
{
    RENDERING_CLASS_IS_VALID_9;

    sampler.SetCoordinate(index, dimension, coordinate);
}

void Rendering::ShaderBaseImpl::SetLodBias(int index, float lodBias)
{
    RENDERING_CLASS_IS_VALID_9;

    sampler.SetLodBias(index, lodBias);
}

void Rendering::ShaderBaseImpl::SetAnisotropy(int index, float anisotropy)
{
    RENDERING_CLASS_IS_VALID_9;

    sampler.SetAnisotropy(index, anisotropy);
}

void Rendering::ShaderBaseImpl::SetBorderColor(int index, const Colour& borderColor)
{
    RENDERING_CLASS_IS_VALID_9;

    sampler.SetBorderColor(index, borderColor);
}

int Rendering::ShaderBaseImpl::GetNumInputs() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return input.GetNumber();
}

std::string Rendering::ShaderBaseImpl::GetInputName(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return input.GetName(index);
}

Rendering::ShaderFlags::VariableType Rendering::ShaderBaseImpl::GetInputType(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return input.GetType(index);
}

Rendering::ShaderFlags::VariableSemantic Rendering::ShaderBaseImpl::GetInputSemantic(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return input.GetSemantic(index);
}

int Rendering::ShaderBaseImpl::GetNumOutputs() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return output.GetNumber();
}

std::string Rendering::ShaderBaseImpl::GetOutputName(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return output.GetName(index);
}

Rendering::ShaderFlags::VariableType Rendering::ShaderBaseImpl::GetOutputType(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return output.GetType(index);
}

Rendering::ShaderFlags::VariableSemantic Rendering::ShaderBaseImpl::GetOutputSemantic(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return output.GetSemantic(index);
}

int Rendering::ShaderBaseImpl::GetNumConstants() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return constants.GetNumConstants();
}

string Rendering::ShaderBaseImpl::GetConstantName(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return constants.GetConstantName(index);
}

int Rendering::ShaderBaseImpl::GetNumRegistersUsed(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return constants.GetNumRegistersUsed(index);
}

int Rendering::ShaderBaseImpl::GetNumSamplers() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sampler.GetNumSamplers();
}

string Rendering::ShaderBaseImpl::GetSamplerName(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sampler.GetSamplerName(index);
}

Rendering::ShaderFlags::SamplerType Rendering::ShaderBaseImpl::GetSamplerType(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sampler.GetSamplerType(index);
}

Rendering::ShaderFlags::SamplerFilter Rendering::ShaderBaseImpl::GetFilter(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sampler.GetFilter(index);
}

Rendering::ShaderFlags::SamplerCoordinate
    Rendering::ShaderBaseImpl::GetCoordinate(int index, int dimension) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sampler.GetCoordinate(index, dimension);
}

float Rendering::ShaderBaseImpl::GetLodBias(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sampler.GetLodBias(index);
}

float Rendering::ShaderBaseImpl::GetAnisotropy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sampler.GetAnisotropy(index);
}

Rendering::ShaderSamplerData::Colour Rendering::ShaderBaseImpl::GetBorderColor(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sampler.GetBorderColor(index);
}

void Rendering::ShaderBaseImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    input.Load(source);
    output.Load(source);
    constants.Load(source);
    sampler.Load(source);
    profile = std::make_shared<ShaderProfileData>(0, 0);
    profile->Load(source);
}

void Rendering::ShaderBaseImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    input.Save(target);
    output.Save(target);
    constants.Save(target);
    sampler.Save(target);
    if (profile != nullptr)
    {
        profile->Save(target);
    }
}

int Rendering::ShaderBaseImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = input.GetStreamingSize();

    size += output.GetStreamingSize();
    size += constants.GetStreamingSize();
    size += sampler.GetStreamingSize();
    size += CORE_TOOLS_STREAM_SIZE(profile);

    return size;
}

void Rendering::ShaderBaseImpl::SetProfile(const ShaderProfileDataSharedPtr& aProfile) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    profile = aProfile;
}

Rendering::ConstShaderProfileDataSharedPtr Rendering::ShaderBaseImpl::GetProfile() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return profile;
}

Rendering::ShaderProfileDataSharedPtr Rendering::ShaderBaseImpl::GetProfile() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return profile;
}

void Rendering::ShaderBaseImpl::Link(MAYBE_UNUSED CoreTools::ObjectLink& source) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::ShaderBaseImpl::Register(MAYBE_UNUSED CoreTools::ObjectRegister& target) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
}

void Rendering::ShaderBaseImpl::SaveShader(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto numInputs = GetNumInputs();
    const auto numOutputs = GetNumOutputs();
    const auto numConstants = GetNumConstants();
    const auto numSamplers = GetNumSamplers();
    constexpr auto numProfiles = ShaderFlags::Profiles::MaxProfiles;

    manager.Write(sizeof(int32_t), &numInputs);
    manager.Write(sizeof(int32_t), &numOutputs);
    manager.Write(sizeof(int32_t), &numConstants);
    manager.Write(sizeof(int32_t), &numSamplers);
    manager.Write(sizeof(ShaderFlags::Profiles), &numProfiles);

    for (auto i = 0; i < numInputs; ++i)
    {
        const auto name = GetInputName(i);
        const auto type = GetInputType(i);
        const auto semantic = GetInputSemantic(i);

        manager.SaveStdString(name);
        manager.Write(sizeof(decltype(type)), &type);
        manager.Write(sizeof(decltype(semantic)), &semantic);
    }

    for (auto i = 0; i < numOutputs; ++i)
    {
        const auto name = GetOutputName(i);
        const auto type = GetOutputType(i);
        const auto semantic = GetOutputSemantic(i);

        manager.SaveStdString(name);
        manager.Write(sizeof(decltype(type)), &type);
        manager.Write(sizeof(decltype(semantic)), &semantic);
    }

    for (auto i = 0; i < numConstants; ++i)
    {
        const auto name = GetConstantName(i);
        const auto numRegistersUsed = GetNumRegistersUsed(i);
        manager.SaveStdString(name);
        manager.Write(sizeof(int32_t), &numRegistersUsed);
    }

    for (auto i = 0; i < numSamplers; ++i)
    {
        const auto name = GetSamplerName(i);
        const auto type = GetSamplerType(i);
        const auto filter = GetFilter(i);
        std::array<int, 3> coord{ System::EnumCastUnderlying(GetCoordinate(i, 0)), System::EnumCastUnderlying(GetCoordinate(i, 1)), System::EnumCastUnderlying(GetCoordinate(i, 2)) };
        const auto lodBias = GetLodBias(i);
        const auto anisotropy = GetAnisotropy(i);
        const auto borderColor = GetBorderColor(i);

        manager.SaveStdString(name);
        manager.Write(sizeof(decltype(type)), &type);
        manager.Write(sizeof(decltype(filter)), &filter);
        manager.Write(sizeof(int), 3, coord.data());
        manager.Write(sizeof(float), &lodBias);
        manager.Write(sizeof(float), &anisotropy);
        manager.Write(sizeof(float), 4, borderColor.GetPoint().data());
    }

    for (auto profileIndex = 0; profileIndex < System::EnumCastUnderlying(numProfiles); ++profileIndex)
    {
        manager.Write(sizeof(int32_t), &profileIndex);
        auto programString = profile->GetProgram(profileIndex);
        manager.SaveStdString(programString);

        if (!programString.empty())
        {
            for (auto index = 0; index < numConstants; ++index)
            {
                const auto baseRegister = profile->GetBaseRegister(profileIndex, index);
                manager.Write(sizeof(int32_t), &baseRegister);
            }
            for (auto index = 0; index < numSamplers; ++index)
            {
                const auto textureUnit = profile->GetTextureUnit(profileIndex, index);
                manager.Write(sizeof(int32_t), &textureUnit);
            }
        }
    }
}

void Rendering::ShaderBaseImpl::LoadShader(ReadFileManager& manager, int numProfiles)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto i = 0; i < GetNumInputs(); ++i)
    {
        auto name = manager.LoadStdString();
        auto type = 0;
        auto semantic = 0;
        manager.Read(sizeof(int32_t), &type);
        manager.Read(sizeof(int32_t), &semantic);
        SetInput(i, name, ShaderFlags::VariableType{ type }, ShaderFlags::VariableSemantic{ semantic });
    }

    for (auto i = 0; i < GetNumOutputs(); ++i)
    {
        auto name = manager.LoadStdString();
        auto type = 0;
        auto semantic = 0;
        manager.Read(sizeof(int32_t), &type);
        manager.Read(sizeof(int32_t), &semantic);
        SetOutput(i, name, ShaderFlags::VariableType{ type }, ShaderFlags::VariableSemantic{ semantic });
    }

    for (auto i = 0; i < GetNumConstants(); ++i)
    {
        auto name = manager.LoadStdString();
        auto numRegistersUsed = 0;
        manager.Read(sizeof(int32_t), &numRegistersUsed);
        SetConstant(i, name, numRegistersUsed);
    }

    for (auto i = 0; i < GetNumSamplers(); ++i)
    {
        auto name = manager.LoadStdString();
        auto type = 0;
        auto filter = 0;
        std::array<int, 3> coord{ 0, 0, 0 };
        auto lodBias = 0.0f;
        auto anisotropy = 0.0f;
        std::array<float, 4> borderColor{ 0.0f, 0.0f, 0.0f, 0.0f };

        manager.Read(sizeof(int32_t), &type);
        manager.Read(sizeof(int32_t), &filter);
        manager.Read(sizeof(int32_t), 3, coord.data());
        manager.Read(sizeof(float), &lodBias);
        manager.Read(sizeof(float), &anisotropy);
        manager.Read(sizeof(float), 4, borderColor.data());
        SetSampler(i, name, ShaderFlags::SamplerType{ type });
        SetFilter(i, ShaderFlags::SamplerFilter{ filter });
        SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate{ coord.at(0) });
        SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate{ coord.at(1) });
        SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate{ coord.at(2) });
        SetLodBias(i, lodBias);
        SetAnisotropy(i, anisotropy);
        SetBorderColor(i, Colour(borderColor.at(0), borderColor.at(1), borderColor.at(2), borderColor.at(3)));
    }

    auto aProfile = std::make_shared<ShaderProfileData>(GetNumConstants(), GetNumSamplers());

    for (auto profileIndex = 0; profileIndex < numProfiles; ++profileIndex)
    {
        auto type = 0;
        manager.Read(sizeof(int32_t), &type);
        RENDERING_ASSERTION_0(0 <= type && type < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles), "无效profile");

        if (0 <= type && type < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles))
        {
            auto programName = manager.LoadStdString();
            aProfile->SetProgram(profileIndex, programName);

            if (!programName.empty())
            {
                for (auto index = 0; index < GetNumConstants(); ++index)
                {
                    auto baseRegister = 0;
                    manager.Read(sizeof(int32_t), &baseRegister);
                    aProfile->SetBaseRegister(profileIndex, index, baseRegister);
                }

                for (auto index = 0; index < GetNumSamplers(); ++index)
                {
                    auto textureUnit = 0;
                    manager.Read(sizeof(int32_t), &textureUnit);
                    aProfile->SetTextureUnit(profileIndex, index, textureUnit);
                }
            }
        }
    }

    SetProfile(aProfile);
}
