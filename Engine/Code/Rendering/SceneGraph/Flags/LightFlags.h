// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 17:28)

#ifndef RENDERING_SCENE_GRAPH_LIGHT_FLAGS_H
#define RENDERING_SCENE_GRAPH_LIGHT_FLAGS_H

#include "Rendering/RenderingDll.h" 

namespace Rendering
{	 
    enum class LightType
    {
		Ambient,
		Directional,
		Point,
		Spot,
		Quantity
    };     
}

#endif // RENDERING_SCENE_GRAPH_LIGHT_FLAGS_H
