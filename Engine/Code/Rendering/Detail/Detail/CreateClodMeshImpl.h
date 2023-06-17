///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:51)

#ifndef RENDERING_DETAIL_CREATE_CLOD_MESH_IMPL_H
#define RENDERING_DETAIL_CREATE_CLOD_MESH_IMPL_H

#include "Rendering/RenderingDll.h"

#include "ClodMeshTriangleMesh.h"
#include "ClodMeshVertexEdgeTriangleGraph.h"
#include "Rendering/Detail/CollapseRecord.h"
#include "Rendering/Detail/CollapseRecordArray.h"

#include <vector>

// CreateClodMesh����CollapseRecord�����У�����ʾ��һ��������������۵���
// һ����<V0,V1>�۵�����V0�����¼�ơ�keep�����㣩����V1����throw�����㣩��
// δ�����κ��µĶ����������ԡ�
// ���⣬������������������������У�ʹ�ö�������������ȱ��Ƴ����۵��������Ƴ��������֮��
// ��֧�ַ��Ͷ���Ϊ��̬����Ӳ����Ⱦ����
// ϸ��ѡ��ĵȼ�ֻ��Ҫ��1���ı�����������μ�����
// �ͣ�2�����»��ڸ�CollapseRecord����ֵ��������������

// ������ʸ���д��ڶ��㻺���������ܻ����һЩ���������
// ���������ʹ�õ���������������ÿ�λ���Ŀ���¼�ı仯���¼�����Լ���α��
// ����������£����㻺������ɶ�̬�ģ�������Ҫ������Ⱦ���������Դ渴��ÿһ֡��

// ��CollapseRecord��ɱ��޸��Դ洢�µĶ���Ͷ������������ԡ�
// ���磬��������ͨ��(V0+V1)/2��ƽ��������Ӧ��������ȡ��V0��V1��
// ����������£����㻺������ɶ�̬�ģ���Ҫ������Ⱦ���������Դ渴��ÿһ֡��

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CreateClodMeshImpl
    {
    public:
        using ClassType = CreateClodMeshImpl;
        using EdgeKey = Mathematics::EdgeKey;
        using TriangleKey = Mathematics::TriangleKey;

    public:
        explicit CreateClodMeshImpl(TrianglesMesh& mesh);

        CLASS_INVARIANT_DECLARE;

        NODISCARD CollapseRecordArraySharedPtr GetCollapseRecordArray() const;

    private:
        void Compute();
        void CreateVertexEdgeTriangleGraph();
        NODISCARD float ComputeMetric(const EdgeKey& edgeKey);
        NODISCARD Mathematics::Vector3F GetNormal(const TriangleKey& triangleKey);
        NODISCARD int CanCollapse(const EdgeKey& edgeKey);
        void Collapse(const EdgeKey& edgeKey, int indexThrow);
        NODISCARD bool ValidResults();
        void ReorderBuffers();
        void ComputeRecords();

    private:
        ClodMeshTriangleMesh clodMeshTriangleMesh;

        ClodMeshVertexEdgeTriangleGraph graph;

        // �ߵĺ�£����
        std::vector<ClodMeshCollapseInfo> collapses;

        std::vector<CollapseRecord> collapseRecord;
    };
}

#endif  // RENDERING_DETAIL_CREATE_CLOD_MESH_IMPL_H
