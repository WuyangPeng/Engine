// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 17:27)

#ifndef RENDERING_SCENE_GRAPH_CULLING_MODE_FLAGS_H
#define RENDERING_SCENE_GRAPH_CULLING_MODE_FLAGS_H

namespace Rendering
{
    // �޳�����
    enum class CullingMode
    {
        // ȷ���ɼ���״̬ͨ���Ƚ�����߽�����ȥ�ü�ƽ�档
        Dynamic, 

        // ǿ�ƶ��󱻲ü������һ��Node�Բü��������������������ü���
        Always,
        
        // ���ü�����������һ��Node�����ü������������������ü���
        // Ϊ��ʵ����һ��,��һ������������һ���ڵ�,
        // bNoCull��������Ϊ��true���ĵݹ���GetVisibleSet/OnGetVisibleSet��
        Never
    };
}

#endif // RENDERING_SCENE_GRAPH_CULLING_MODE_FLAGS_H
