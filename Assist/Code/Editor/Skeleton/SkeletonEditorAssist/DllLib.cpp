///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:30)

#include "Editor/Skeleton/SkeletonEditorAssist/SkeletonEditorAssistExport.h"

#include "Editor/Skeleton/SkeletonEditorAssist/SkeletonEditorAssist.h"

#ifndef BUILDING_SKELETON_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_SKELETON_EDITOR_STATIC

namespace SkeletonEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SKELETON_EDITOR_STATIC
