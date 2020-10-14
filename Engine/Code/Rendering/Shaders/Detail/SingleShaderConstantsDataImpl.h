// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/24 15:00)

#ifndef RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_IMPL_H
#define RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include <string>
#include <vector>
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SingleShaderConstantsDataImpl
    {
    public:
        using ClassType = SingleShaderConstantsDataImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        SingleShaderConstantsDataImpl() noexcept;
        explicit SingleShaderConstantsDataImpl(const std::string& name, int numRegistersUsed);

        CLASS_INVARIANT_DECLARE;

        void SetConstant(const std::string& name, int numRegistersUsed);

        const std::string GetConstantName() const;
        int GetNumRegistersUsed() const noexcept;

        void Load(const CoreTools::BufferSourceSharedPtr& source);
        void Save(const CoreTools::BufferTargetSharedPtr& target) const;
        int GetStreamingSize() const;

    private:
        std::string m_Name;
        int m_NumRegistersUsed;
    };
}

#endif  // RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_IMPL_H
