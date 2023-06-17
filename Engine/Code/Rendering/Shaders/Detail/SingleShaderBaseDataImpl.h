///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:39)

#ifndef RENDERING_SHADERS_SINGLE_SHADER_BASE_DATA_IMPL_H
#define RENDERING_SHADERS_SINGLE_SHADER_BASE_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

#include <string>

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

        void SetData(const std::string& aName, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic aSemantic);

        NODISCARD std::string GetName() const;
        NODISCARD ShaderFlags::VariableType GetType() const noexcept;
        NODISCARD ShaderFlags::VariableSemantic GetSemantic() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        std::string name;
        ShaderFlags::VariableType variableType;
        ShaderFlags::VariableSemantic semantic;
    };
}

#endif  // RENDERING_SHADERS_SINGLE_SHADER_BASE_DATA_IMPL_H
