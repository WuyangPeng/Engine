// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 15:19)

#ifndef RENDERING_SHADERS_SAVE_VISUAL_EFFECT_H
#define RENDERING_SHADERS_SAVE_VISUAL_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"
#include "System/Helper/UnicodeUsing.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE SaveVisualEffect 
	{
	public:
		using ClassType = SaveVisualEffect;

	public:
		// 保存视觉效果到外部的视频流系统的*.trve文件。
		SaveVisualEffect(const VisualEffectSharedPtr& visualEffect, const System::String& fileName);

		CLASS_INVARIANT_DECLARE;	
	};
}

#endif // RENDERING_SHADERS_SAVE_VISUAL_EFFECT_H
