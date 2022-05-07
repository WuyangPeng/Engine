///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 15:05)

#ifndef RENDERING_SHADERS_SHADER_BASE_DATA_H
#define RENDERING_SHADERS_SHADER_BASE_DATA_H

#include "Rendering/RenderingDll.h"

#include "Flags/ShaderFlags.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

#include <string>
#include <vector>

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(ShaderBaseData, ShaderBaseDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderBaseData
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ShaderBaseData);
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit ShaderBaseData(int number);

        CLASS_INVARIANT_DECLARE;

        void Resize(int number);

        void InsertData(const std::string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic);

        void SetData(int index, const std::string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic);

        NODISCARD int GetNumber() const;
        NODISCARD std::string GetName(int index) const;
        NODISCARD ShaderFlags::VariableType GetType(int index) const;
        NODISCARD ShaderFlags::VariableSemantic GetSemantic(int index) const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_SHADER_BASE_DATA_H
