// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/07 22:18)

#ifndef RENDERING_TOOLSET_PLACEHOLDER_H
#define RENDERING_TOOLSET_PLACEHOLDER_H

#include "Toolset/Rendering/RenderingToolset/RenderingToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace RenderingToolset
{
    class RENDERING_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // RENDERING_TOOLSET_PLACEHOLDER_H