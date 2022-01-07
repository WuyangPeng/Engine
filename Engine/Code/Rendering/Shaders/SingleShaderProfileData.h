// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/24 15:28)

#ifndef RENDERING_SHADERS_SINGLE_SHADER_PROFILE_DATA_H
#define RENDERING_SHADERS_SINGLE_SHADER_PROFILE_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include <string>
#include <vector>
RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(SingleShaderProfileData,SingleShaderProfileDataImpl);

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
}

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SingleShaderProfileData
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(SingleShaderProfileData);
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        SingleShaderProfileData();
        SingleShaderProfileData(int numConstants, int numSamplers);

        CLASS_INVARIANT_DECLARE;

        void ResetData(int numConstants, int numSamplers);

        void SetBaseRegister(int index, int baseRegister);
        void SetTextureUnit(int index, int textureUnit);
        void SetProgram(const std::string& program);

        // 配置文件相关的数据。
        int GetBaseRegister(int index) const;
        int GetTextureUnit(int index) const;
        const std::string GetProgram() const;

        int GetBaseRegisterSize() const;
        int GetTextureUnitSize() const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        int GetStreamingSize() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_SINGLE_SHADER_PROFILE_DATA_H
