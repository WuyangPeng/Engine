// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:26)

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
		explicit CreateClodMeshImpl(TrianglesMeshSharedPtr mesh);

		CLASS_INVARIANT_DECLARE;

		CollapseRecordArraySharedPtr GetCollapseRecordArray() const;

	private:
		void Compute();	 
		void CreateVertexEdgeTriangleGraph();
		float ComputeMetric(const EdgeKey& edgeKey);
		const Mathematics::Vector3Df GetNormal( const TriangleKey& triangleKey );
		int CanCollapse(const EdgeKey& edgeKey);
		void Collapse(const EdgeKey& edgeKey, int indexThrow);
		bool ValidResults ();
		void ReorderBuffers ();
		void ComputeRecords ();

	private:
		ClodMeshTriangleMesh m_ClodMeshTriangleMesh;
		
		ClodMeshVertexEdgeTriangleGraph m_Graph;

		// �ߵĺ�£����
		std::vector<ClodMeshCollapseInfo> m_Collapses;
		
		std::vector<CollapseRecord> m_CollapseRecord;
	};
}

#endif // RENDERING_DETAIL_CREATE_CLOD_MESH_IMPL_H
