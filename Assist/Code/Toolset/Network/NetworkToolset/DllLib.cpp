// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/05 1:20)

#include "Toolset/Network/NetworkToolset/NetworkToolsetExport.h"

#include "Toolset/Network/NetworkToolset/NetworkToolset.h"

#include "CoreTools/CoreToolsLib.h"
#include "Network/NetworkLib.h"

#ifndef BUILDING_NETWORK_STATIC

    #include "DllLib.h"

#else  // BUILDING_NETWORK_STATIC

namespace NetworkToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_NETWORK_STATIC