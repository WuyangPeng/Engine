// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/20 22:47)

#include "Editor/Skeleton/SkeletonEditorAssist/SkeletonEditorAssistExport.h"

#include "Editor/Skeleton/SkeletonEditorAssist/SkeletonEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SKELETON_EDITOR_STATIC

	DLL_MAIN_FUNCTION(SkeletonEditorAssist);

#else // !BUILDING_SKELETON_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(SkeletonEditorAssist);

#endif // BUILDING_SKELETON_EDITOR_STATIC
