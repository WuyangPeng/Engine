///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/10 21:34)

#include "Editor/Skeleton/SkeletonEditorAssist/SkeletonEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Skeleton/SkeletonEditorAssist/SkeletonEditorAssistFwd.h"

#ifndef BUILDING_SKELETON_EDITOR_STATIC

DLL_MAIN_FUNCTION(SkeletonEditorAssist);

#else  // !BUILDING_SKELETON_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(SkeletonEditorAssist);

#endif  // BUILDING_SKELETON_EDITOR_STATIC
