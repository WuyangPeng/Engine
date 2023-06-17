///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:40)

#ifndef RENDERING_SHADERS_SINGLE_SHADER_PROFILE_DATA_IMPL_H
#define RENDERING_SHADERS_SINGLE_SHADER_PROFILE_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SingleShaderProfileDataImpl
    {
    public:
        using ClassType = SingleShaderProfileDataImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        SingleShaderProfileDataImpl(int numConstants, int numSamplers);

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
        std::vector<int> baseRegisters;
        std::vector<int> textureUnits;
        std::string programs;
    };
}

#endif  // RENDERING_SHADERS_SINGLE_SHADER_PROFILE_DATA_IMPL_H
