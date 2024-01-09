/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 15:03)

#ifndef RENDERING_SHADERS_PROGRAM_DEFINES_H
#define RENDERING_SHADERS_PROGRAM_DEFINES_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <string>
#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ProgramDefines, ProgramDefinesImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ProgramDefines
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ProgramDefines);

        using DefinesType = std::pair<std::string, std::string>;
        using Container = std::vector<DefinesType>;
        using ContainerConstIter = Container::const_iterator;

    public:
        NODISCARD static ProgramDefines Create();

        CLASS_INVARIANT_DECLARE;

        template <typename T>
        void Set(const std::string& name, T value);

        void Remove(const std::string& name);
        void Clear() noexcept;
        void Update(const std::string& name, const std::string& value);

        NODISCARD std::string Get(const std::string& name) const;
        NODISCARD int GetSize() const;

        NODISCARD ContainerConstIter begin() const noexcept;
        NODISCARD ContainerConstIter end() const noexcept;

    private:
        explicit ProgramDefines(CoreTools::DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_PROGRAM_DEFINES_H
