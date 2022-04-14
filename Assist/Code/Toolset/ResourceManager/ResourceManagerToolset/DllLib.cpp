// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/05 19:30)

#include "Toolset/ResourceManager/ResourceManagerToolset/ResourceManagerToolsetExport.h"

#include "Toolset/ResourceManager/ResourceManagerToolset/ResourceManagerToolset.h"

#include "CoreTools/CoreToolsLib.h"
#include "ResourceManager/ResourceManagerLib.h"

#ifndef BUILDING_RESOURCE_MANAGER_STATIC

    #include "DllLib.h"

#else  // BUILDING_RESOURCE_MANAGER_STATIC

namespace ResourceManagerToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_RESOURCE_MANAGER_STATIC
