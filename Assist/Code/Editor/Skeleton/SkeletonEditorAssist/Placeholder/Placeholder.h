///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/10 21:35)

#ifndef SKELETON_EDITOR_PLACEHOLDER_H
#define SKELETON_EDITOR_PLACEHOLDER_H

#include "Editor/Skeleton/SkeletonEditorAssist/SkeletonEditorAssistDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace SkeletonEditorAssist
{
    class SKELETON_EDITOR_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // SKELETON_EDITOR_PLACEHOLDER_H
