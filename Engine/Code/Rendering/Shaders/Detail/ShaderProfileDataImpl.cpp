///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/12 14:25)

#include "Rendering/RenderingExport.h"

#include "ShaderProfileDataImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include <algorithm>

using std::for_each;
using std::string;

Rendering::ShaderProfileDataImpl::ShaderProfileDataImpl(int numConstants, int numSamplers)
    : shaderProfileData{ SingleShaderProfileData{ CoreTools::DisableNotThrow::Disable },
                         SingleShaderProfileData{ CoreTools::DisableNotThrow::Disable },
                         SingleShaderProfileData{ CoreTools::DisableNotThrow::Disable },
                         SingleShaderProfileData{ CoreTools::DisableNotThrow::Disable },
                         SingleShaderProfileData{ CoreTools::DisableNotThrow::Disable } },
      numConstants{ numConstants },
      numSamplers{ numSamplers }
{
    for_each(shaderProfileData.begin(), shaderProfileData.end(), std::bind(&SingleShaderProfileData::ResetData, std::placeholders::_1, numConstants, numSamplers));

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderProfileDataImpl::ShaderProfileDataImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ShaderProfileDataImpl{ 0, 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderProfileDataImpl)

void Rendering::ShaderProfileDataImpl::SetBaseRegister(int profile, int index, int baseRegister)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= profile && profile < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles), "��������");

    shaderProfileData.at(profile).SetBaseRegister(index, baseRegister);
}

void Rendering::ShaderProfileDataImpl::SetTextureUnit(int profile, int index, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= profile && profile < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles), "��������");

    shaderProfileData.at(profile).SetTextureUnit(index, textureUnit);
}

void Rendering::ShaderProfileDataImpl::SetProgram(int profile, const std::string& program)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= profile && profile < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles), "��������");

    shaderProfileData.at(profile).SetProgram(program);
}

int Rendering::ShaderProfileDataImpl::GetBaseRegister(int profile, int index) const
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= profile && profile < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles), "��������");

    return shaderProfileData.at(profile).GetBaseRegister(index);
}

int Rendering::ShaderProfileDataImpl::GetTextureUnit(int profile, int index) const
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= profile && profile < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles), "��������");

    return shaderProfileData.at(profile).GetTextureUnit(index);
}

std::string Rendering::ShaderProfileDataImpl::GetProgram(int profile) const
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= profile && profile < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles), "��������");

    return shaderProfileData.at(profile).GetProgram();
}

int Rendering::ShaderProfileDataImpl::GetBaseRegisterSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numConstants;
}

int Rendering::ShaderProfileDataImpl::GetTextureUnitSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numSamplers;
}

void Rendering::ShaderProfileDataImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    // �����Ƿ��޸�MaxProfiles��
    int maxProfiles{ 0 };
    source.Read(maxProfiles);

    RENDERING_ASSERTION_2(maxProfiles == System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles), "��ı���MaxProfiles��ֵ���������˾ɵ����ݼ���");

    for (auto i = 0; i < maxProfiles; ++i)
    {
        shaderProfileData.at(i).Load(source);
    }

    source.Read(numConstants);
    source.Read(numSamplers);
}

void Rendering::ShaderProfileDataImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles));

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        shaderProfileData.at(i).Save(target);
    }

    target.Write(numConstants);
    target.Write(numSamplers);
}

int Rendering::ShaderProfileDataImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles));

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        size += shaderProfileData.at(i).GetStreamingSize();
    }

    size += CORE_TOOLS_STREAM_SIZE(numConstants);
    size += CORE_TOOLS_STREAM_SIZE(numSamplers);

    return size;
}
