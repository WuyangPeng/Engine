///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 14:42)

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
