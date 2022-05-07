// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/07 22:36)

#include "Toolset/Physics/PhysicsToolset/PhysicsToolsetExport.h"

#include "Toolset/Physics/PhysicsToolset/PhysicsToolset.h"

#include "CoreTools/CoreToolsLib.h"
#include "Physics/PhysicsLib.h"

#ifndef BUILDING_PHYSICS_STATIC

    #include "DllLib.h"

#else  // BUILDING_PHYSICS_STATIC

namespace PhysicsToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_PHYSICS_STATIC
