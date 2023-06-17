///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:44)

#ifndef RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_H
#define RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

#include <string>

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(SingleShaderConstantsData, SingleShaderConstantsDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SingleShaderConstantsData
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(SingleShaderConstantsData);
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit SingleShaderConstantsData(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        SingleShaderConstantsData(const std::string& name, int numRegistersUsed);

        CLASS_INVARIANT_DECLARE;

        void SetConstant(const std::string& name, int numRegistersUsed);

        NODISCARD std::string GetConstantName() const;
        NODISCARD int GetNumRegistersUsed() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_H
