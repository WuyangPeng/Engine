///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:08)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_FLAGS_H
#define RENDERING_SCENE_GRAPH_CAMERA_FLAGS_H

namespace Rendering
{
    // ���������ͶӰ����ͶӰ����ӳ�䵽���[0,1]��Direct3Dʹ�á�
    // ��ͼ����ӳ�䵽���[-1,1] ��OpenGLʹ�á�
    enum class DepthType
    {
        ZeroToOne,  // [0,1]
        MinusOneToOne,  // [-1,1]
        Quantity
    };

    // ��ͼƽ��ͷ�����[rmin,rmax], [umin,umax],��[dmin,dmax]��
    // ����[rmin,rmax]������ȷ�ķ���R,��Щ���ǡ��󡱺͡��ҡ�ƽ��ͷ���ֵ��
    // ����[umin,umax]������ȷ�ķ���U,��Щ���ǡ��ס��͡�����ƽ��ͷ���ֵ��
    // ����[dmin,dmax]������ȷ�ķ���D,��Щ���ǡ������͡�Զ��ƽ��ͷ���ֵ��
    // ƽ��ͷ���ֵ�洢��һ������������ӳ��:
    enum class ViewFrustum
    {
        DirectionMin = 0,  // near
        DirectionMax = 1,  // far
        UpMin = 2,  // bottom
        UpMax = 3,  // top
        RightMin = 4,  // left
        RightMax = 5,  // right
        Quantity = 6
    };

    // ��������ü�ƽ��Ķ�ջ������ܻ�ʹ��push��popƽ�棬������ͼƽ��ͷ���ƽ�档
    // PushPlane��Ҫ����������ƽ�����ꡣ���ݳ�Աm_PlaneState��λϵͳ�����úͽ���ƽ��ü���
    enum
    {
        MaxPlaneQuantity = 32
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_FLAGS_H
