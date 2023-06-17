///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:30)

#ifndef RENDERING_SHADERS_SHADER_CONSTANTS_DATA_IMPL_H
#define RENDERING_SHADERS_SHADER_CONSTANTS_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Shaders/SingleShaderConstantsData.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ShaderConstantsDataImpl
    {
    public:
        using ClassType = ShaderConstantsDataImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        ShaderConstantsDataImpl() noexcept;
        explicit ShaderConstantsDataImpl(int number);

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
        std::vector<SingleShaderConstantsData> singleShaderConstantsData;
    };
}

#endif  // RENDERING_SHADERS_SHADER_CONSTANTS_DATA_IMPL_H
