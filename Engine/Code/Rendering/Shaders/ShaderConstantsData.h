///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:43)

#ifndef RENDERING_SHADERS_SHADER_CONSTANTS_DATA_H
#define RENDERING_SHADERS_SHADER_CONSTANTS_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

#include <string>
#include <vector>

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(ShaderConstantsData, ShaderConstantsDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderConstantsData
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(ShaderConstantsData);
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit ShaderConstantsData(int numConstants);

        CLASS_INVARIANT_DECLARE;

        void Resize(int number);

        void SetConstant(int index, const std::string& name, int numRegistersUsed);

        void InsertData(const std::string& name, int numRegistersUsed);

        NODISCARD int GetNumConstants() const;
        NODISCARD std::string GetConstantName(int index) const;
        NODISCARD int GetNumRegistersUsed(int index) const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_SHADER_CONSTANTS_DATA_H
