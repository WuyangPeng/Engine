// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 15:16)

#ifndef RENDERING_SHADERS_LOAD_VISUAL_EFFECT_H
#define RENDERING_SHADERS_LOAD_VISUAL_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "VisualEffect.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE LoadVisualEffect 
	{
	public:
		using ClassType = LoadVisualEffect;

	public:
                LoadVisualEffect() noexcept;		

		CLASS_INVARIANT_DECLARE;

		// 从外部的视频流系统的*.trve文件读取视觉效果。
		static const VisualEffectSmartPointer Load(const System::String& fileName);
	};
}

#endif // RENDERING_SHADERS_LOAD_VISUAL_EFFECT_H
