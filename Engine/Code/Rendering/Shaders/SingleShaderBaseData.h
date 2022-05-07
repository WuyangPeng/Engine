///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/13 16:37)

#ifndef RENDERING_SHADERS_SINGLE_SHADER_BASE_DATA_H
#define RENDERING_SHADERS_SINGLE_SHADER_BASE_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

#include <string>

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(SingleShaderBaseData, SingleShaderBaseDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SingleShaderBaseData
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(SingleShaderBaseData);
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit SingleShaderBaseData(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        SingleShaderBaseData(const std::string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic);

        CLASS_INVARIANT_DECLARE;

        void SetData(const std::string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic);

        NODISCARD std::string GetName() const;
        NODISCARD ShaderFlags::VariableType GetType() const noexcept;
        NODISCARD ShaderFlags::VariableSemantic GetSemantic() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_SINGLE_SHADER_BASE_DATA_H
