///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:40)

#ifndef RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_IMPL_H
#define RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

#include <string>
#include <vector>

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

        void SetConstant(const std::string& aName, int aNumRegistersUsed);

        NODISCARD std::string GetConstantName() const;
        NODISCARD int GetNumRegistersUsed() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        std::string name;
        int numRegistersUsed;
    };
}

#endif  // RENDERING_SHADERS_SINGLE_SHADER_CONSTANTS_DATA_IMPL_H
