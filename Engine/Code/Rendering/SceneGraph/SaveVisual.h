// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 11:44)

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

		// ֧�ֱ���Visual��
	public:
		// ����һ��visual��*.trv�ļ�����ý��ϵͳ��
		static void SaveToFile(const Visual& visual, const System::String& name);
	};
}   

#endif // RENDERING_SCENE_GRAPH_SAVE_VISUAL_H
