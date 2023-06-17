///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:09)

#ifndef RENDERING_SCENE_GRAPH_CULLING_MODE_FLAGS_H
#define RENDERING_SCENE_GRAPH_CULLING_MODE_FLAGS_H

namespace Rendering
{
    // 剔除参数
    enum class CullingMode
    {
        // 确定可见性状态通过比较世界边界容量去裁剪平面。
        Dynamic,

        // 强制对象被裁剪。如果一个Node对裁剪，则它的整个子树被裁剪。
        Always,

        // 不裁剪这个对象。如果一个Node不被裁剪，则整个子树不被裁剪。
        // 为了实现这一点,第一次遇到这样的一个节点,
        // bNoCull参数设置为“true”的递归链GetVisibleSet/OnGetVisibleSet。
        Never
    };
}

#endif  // RENDERING_SCENE_GRAPH_CULLING_MODE_FLAGS_H
