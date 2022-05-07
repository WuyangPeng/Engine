///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/13 17:15)

#ifndef RENDERING_SHADERS_SINGLE_SHADER_PROFILE_DATA_H
#define RENDERING_SHADERS_SINGLE_SHADER_PROFILE_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

#include <string>
#include <vector>

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(SingleShaderProfileData, SingleShaderProfileDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SingleShaderProfileData
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(SingleShaderProfileData);
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit SingleShaderProfileData(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        SingleShaderProfileData(int numConstants, int numSamplers);

        CLASS_INVARIANT_DECLARE;

        void ResetData(int numConstants, int numSamplers);

        void SetBaseRegister(int index, int baseRegister);
        void SetTextureUnit(int index, int textureUnit);
        void SetProgram(const std::string& program);

        // �����ļ���ص����ݡ�
        NODISCARD int GetBaseRegister(int index) const;
        NODISCARD int GetTextureUnit(int index) const;
        NODISCARD std::string GetProgram() const;

        NODISCARD int GetBaseRegisterSize() const;
        NODISCARD int GetTextureUnitSize() const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_SINGLE_SHADER_PROFILE_DATA_H
