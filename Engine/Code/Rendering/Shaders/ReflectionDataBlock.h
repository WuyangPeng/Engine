///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 11:29)

#ifndef RENDERING_SHADERS_REFLECTION_DATA_BLOCK_H
#define RENDERING_SHADERS_REFLECTION_DATA_BLOCK_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <string>
#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ReflectionDataBlock, ReflectionDataBlockImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ReflectionDataBlock
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ReflectionDataBlock);

        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using ActiveVariables = std::vector<OpenGLInt>;

    public:
        explicit ReflectionDataBlock(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetName() const;
        void SetName(const std::string& name);

        NODISCARD OpenGLInt GetBufferBinding() const noexcept;
        void SetBufferBinding(OpenGLInt bufferBinding) noexcept;

        NODISCARD OpenGLInt GetBufferDataSize() const noexcept;
        void SetBufferDataSize(OpenGLInt bufferDataSize) noexcept;

        NODISCARD ReferencedBy GetReferencedBy() const noexcept;
        NODISCARD OpenGLInt GetReferencedBy(int index) const;
        void SetReferencedBy(int index, OpenGLInt referencedBy);

        NODISCARD OpenGLInt GetActiveVariables(int index) const;
        void SetActiveVariables(int index, OpenGLInt activeVariables);
        NODISCARD int GetActiveVariablesCount() const;
        void SetActiveVariables(const ActiveVariables& activeVariables);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_DATA_BLOCK_H
