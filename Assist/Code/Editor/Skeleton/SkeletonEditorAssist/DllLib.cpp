// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/20 22:47)

#include "Editor/Skeleton/SkeletonEditorAssist/SkeletonEditorAssistExport.h"

#include "Editor/Skeleton/SkeletonEditorAssist/SkeletonEditorAssist.h"

#include "CoreTools/CoreToolsLib.h" 

#ifndef BUILDING_SKELETON_EDITOR_STATIC

	#include "DllLib.h"

#else // BUILDING_SKELETON_EDITOR_STATIC

	namespace SkeletonEditorAssist
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SKELETON_EDITOR_STATIC
