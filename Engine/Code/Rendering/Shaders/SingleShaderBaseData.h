///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:44)

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
