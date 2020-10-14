// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 15:19)

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
		// �����Ӿ�Ч�����ⲿ����Ƶ��ϵͳ��*.trve�ļ���
		SaveVisualEffect(const VisualEffectSharedPtr& visualEffect, const System::String& fileName);

		CLASS_INVARIANT_DECLARE;	
	};
}

#endif // RENDERING_SHADERS_SAVE_VISUAL_EFFECT_H
