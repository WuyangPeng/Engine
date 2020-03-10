// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 11:44)

#ifndef RENDERING_SCENE_GRAPH_SAVE_VISUAL_H
#define RENDERING_SCENE_GRAPH_SAVE_VISUAL_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace Rendering
{
	class Visual;

	class RENDERING_DEFAULT_DECLARE SaveVisual
	{
	public:
		using ClassType = SaveVisual;

		// 支持保存Visual。
	public:
		// 保存一个visual从*.trv文件在流媒体系统。
		static void SaveToFile(const Visual& visual, const System::String& name);
	};
}   

#endif // RENDERING_SCENE_GRAPH_SAVE_VISUAL_H
