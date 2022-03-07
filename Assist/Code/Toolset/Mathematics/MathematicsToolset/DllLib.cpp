// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/05 17:36)

#include "Toolset/Mathematics/MathematicsToolset/MathematicsToolsetExport.h"

#include "Toolset/Mathematics/MathematicsToolset/MathematicsToolset.h"

#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"

#ifndef BUILDING_MATHEMATICS_STATIC

    #include "DllLib.h"

#else  // BUILDING_MATHEMATICS_STATIC

namespace MathematicsToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MATHEMATICS_STATIC