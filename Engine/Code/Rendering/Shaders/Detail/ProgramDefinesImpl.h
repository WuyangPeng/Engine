///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/20 16:17)

#ifndef RENDERING_SHADERS_PROGRAM_DEFINES_IMPL_H
#define RENDERING_SHADERS_PROGRAM_DEFINES_IMPL_H

#include "Rendering/RenderingDll.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ProgramDefinesImpl
    {
    public:
        using ClassType = ProgramDefinesImpl;
        using DefinesType = std::pair<std::string, std::string>;
        using Container = std::vector<DefinesType>;

    public:
        ProgramDefinesImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Remove(const std::string& name);
        void Clear() noexcept;
        void Update(const std::string& name, const std::string& value);

        NODISCARD std::string Get(const std::string& name) const;

    private:
        Container definitions;
    };
}

#endif  // RENDERING_SHADERS_PROGRAM_DEFINES_IMPL_H
