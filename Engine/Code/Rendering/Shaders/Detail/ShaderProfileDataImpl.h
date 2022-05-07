///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/12 14:24)

#ifndef RENDERING_SHADERS_SHADER_PROFILE_DATA_IMPL_H
#define RENDERING_SHADERS_SHADER_PROFILE_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "Rendering/Shaders/SingleShaderProfileData.h"

#include <array>
#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ShaderProfileDataImpl
    {
    public:
        using ClassType = ShaderProfileDataImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit ShaderProfileDataImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        ShaderProfileDataImpl(int numConstants, int numSamplers);

        CLASS_INVARIANT_DECLARE;

        void SetBaseRegister(int profile, int index, int baseRegister);
        void SetTextureUnit(int profile, int index, int textureUnit);
        void SetProgram(int profile, const std::string& program);

        // �����ļ���ص����ݡ�
        NODISCARD int GetBaseRegister(int profile, int index) const;
        NODISCARD int GetTextureUnit(int profile, int index) const;
        NODISCARD std::string GetProgram(int profile) const;

        NODISCARD int GetBaseRegisterSize() const noexcept;
        NODISCARD int GetTextureUnitSize() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        std::array<SingleShaderProfileData, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> shaderProfileData;
        int numConstants;
        int numSamplers;
    };
}

#endif  // RENDERING_SHADERS_SHADER_PROFILE_DATA_IMPL_H
