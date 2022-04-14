///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 18:14)

#ifndef RENDERING_RESOURCES_BUFFER_PARAMETER_H
#define RENDERING_RESOURCES_BUFFER_PARAMETER_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE BufferParameter
    {
    public:
        using ClassType = BufferParameter;

    public:
        BufferParameter() noexcept;
        BufferParameter(int offset, int componentSize, int numComponents) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Set(int aOffset, int aComponentSize, int aNumComponents) noexcept;

        NODISCARD int GetOffset() const noexcept;
        NODISCARD int GetComponentSize() const noexcept;
        NODISCARD int GetNumComponents() const noexcept;

    private:
        int offset;
        int componentSize;
        int numComponents;
    };
}

#endif  // RENDERING_RESOURCES_BUFFER_PARAMETER_H
