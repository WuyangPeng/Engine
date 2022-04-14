// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/05 19:29)

#ifndef RESOURCE_MANAGER_TOOLSET_PLACEHOLDER_H
#define RESOURCE_MANAGER_TOOLSET_PLACEHOLDER_H

#include "Toolset/ResourceManager/ResourceManagerToolset/ResourceManagerToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ResourceManagerToolset
{
    class RESOURCE_MANAGER_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // RESOURCE_MANAGER_TOOLSET_PLACEHOLDER_H