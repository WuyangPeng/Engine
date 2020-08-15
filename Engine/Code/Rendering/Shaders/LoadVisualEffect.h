// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 15:16)

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

		// ���ⲿ����Ƶ��ϵͳ��*.trve�ļ���ȡ�Ӿ�Ч����
		static const VisualEffectSmartPointer Load(const System::String& fileName);
	};
}

#endif // RENDERING_SHADERS_LOAD_VISUAL_EFFECT_H
