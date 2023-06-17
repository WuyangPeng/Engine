///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:09)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_FLAGS_H
#define RENDERING_SCENE_GRAPH_VISUAL_FLAGS_H

namespace Rendering
{
    enum class VisualPrimitiveType
    {
        None,  // Ĭ�Ϲ���
        Polypoint,
        PolysegmentsDisjoint,
        PolysegmentsContiguous,
        Triangles,  // ����
        TriangleMesh,
        TriangleStrip,
        TriangleFan,
        MaxQuantity
    };

    // ���θ��¡�������㻺������λ���Ѿ��޸�,
    // ��������Ҫ��ԭʼ�����������θ��±���֡(���ߣ����ߣ�˫����)��
    // ����λ�ø��ºͶ��㻺��������ס�ġ�UpdateModelSpace�Ĳ���ָ�������㷨:

    //   VisualUpdateType::ModelBoundOnly:
    //      ֻ���µ�ģ�Ϳռ�󶨵���λ�á�

    // ������ѡ��,ģ�Ϳռ���������¼���,����ԭʼ�����͡�
    // ���ڱ���֡����,Visual�������һ��ԭʼ������������,
    // ���������ͨ��(���ߣ����ߣ�˫����)��
    // ���û��������ԭʼ������,���ø����ڿ���в����κ��¡�
    // ��Щͨ������ֻ�����ڶ��㻺�塣
    // ����,������㻺����û�з���,VisualUpdateType::Normals�Զ��㻺����û��Ӱ�졣
    // ����һ������,�����ָ��VisualUpdateType::UseGeometry��
    // ���㻺�����з��ߺ����ߵ�û��˫����,ֻ�з��ߺ����߸���
    // (�����㻺����������������˫����)��

    //   VisualUpdateType::Normals:
    //      ���·��ߡ�
    //
    //   VisualUpdateType::UseGeometry:
    //      ʹ����״������ȷ������֡��
    //      ���㷨ʹ����С���˷������ǰ���ġ�

    //   VisualUpdateTypeUseTcoordChannel + �Ǹ�����:
    //      ��׼�ķ��������ɱ���֡����ʹ�ôӶ��㻺�����е��������굥Ԫ��

    // Ҫͨ�����㻺����������Ƶ�ڴ��ʹ�ã������Ķ�����ɫ��ʹ�÷��ߣ����ߺ�˫��Ǯ��
    // ����ͨ�����ߺ����ߣ�Ȼ������ɫ������˫����Ϊbitangent = Cross(normal, tangent)

    enum class VisualUpdateType
    {
        ModelBoundOnly = -3,
        Normals = -2,
        UseGeometry = -1,
        UseTextureCoordChannel = 0
    };
}

#endif  // RENDERING_SCENE_GRAPH_VISUAL_FLAGS_H
