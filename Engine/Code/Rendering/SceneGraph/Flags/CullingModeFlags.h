///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:09)

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

#endif  // RENDERING_SCENE_GRAPH_CULLING_MODE_FLAGS_H
