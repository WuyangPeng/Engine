///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:30)

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
