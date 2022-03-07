// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/05 11:49)

#include "Toolset/Database/DatabaseToolset/DatabaseToolsetExport.h"

#include "Toolset/Database/DatabaseToolset/DatabaseToolset.h"

#include "CoreTools/CoreToolsLib.h"
#include "Database/DatabaseLib.h"

#ifndef BUILDING_DATABASE_STATIC

    #include "DllLib.h"

#else  // BUILDING_DATABASE_STATIC

namespace DatabaseToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_DATABASE_STATIC
