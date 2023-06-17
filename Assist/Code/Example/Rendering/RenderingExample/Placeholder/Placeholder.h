///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/12 14:37)
///	引擎辅助版本：0.8.0.10 (2022/07/12 18:01)

#ifndef RENDERING_EXAMPLE_PLACEHOLDER_H
#define RENDERING_EXAMPLE_PLACEHOLDER_H

#include "Example/Rendering/RenderingExample/RenderingExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace RenderingExample
{
    class RENDERING_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // RENDERING_EXAMPLE_PLACEHOLDER_H
