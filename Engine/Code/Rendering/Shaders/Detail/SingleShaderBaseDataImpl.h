// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 14:59)

#ifndef RENDERING_SHADERS_SINGLE_SHADER_BASE_DATA_IMPL_H
#define RENDERING_SHADERS_SINGLE_SHADER_BASE_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/Flags/ShaderFlags.h"

#include <string>

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SingleShaderBaseDataImpl
    {
    public:
        using ClassType = SingleShaderBaseDataImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        SingleShaderBaseDataImpl() noexcept;
        SingleShaderBaseDataImpl(const std::string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic);

        CLASS_INVARIANT_DECLARE;

        void SetData(const std::string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic);

        const std::string GetName() const;
        ShaderFlags::VariableType GetType() const noexcept;
        ShaderFlags::VariableSemantic GetSemantic() const noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        int GetStreamingSize() const;

    private:
        std::string m_Name;
        ShaderFlags::VariableType m_Type;
        ShaderFlags::VariableSemantic m_Semantic;
    };
}

#endif  // RENDERING_SHADERS_SINGLE_SHADER_BASE_DATA_IMPL_H
