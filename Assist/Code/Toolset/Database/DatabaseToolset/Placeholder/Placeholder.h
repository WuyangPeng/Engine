// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/05 11:47)

#ifndef DATABASE_TOOLSET_PLACEHOLDER_H
#define DATABASE_TOOLSET_PLACEHOLDER_H

#include "Toolset/Database/DatabaseToolset/DatabaseToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace DatabaseToolset
{
    class DATABASE_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // DATABASE_TOOLSET_PLACEHOLDER_H
