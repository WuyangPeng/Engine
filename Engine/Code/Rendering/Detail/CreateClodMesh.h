// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:29)

#ifndef RENDERING_DETAIL_CREATE_CLOD_MESH_H
#define RENDERING_DETAIL_CREATE_CLOD_MESH_H

#include "Rendering/RenderingDll.h"

#include "CollapseRecordArray.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

RENDERING_EXPORT_SHARED_PTR(CreateClodMeshImpl);

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
	class RENDERING_DEFAULT_DECLARE CreateClodMesh
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(CreateClodMesh);

	public:
		explicit CreateClodMesh(TrianglesMeshSharedPtr mesh);

		CLASS_INVARIANT_DECLARE;

		CollapseRecordArraySharedPtr GetCollapseRecordArray() const;
	
	private:		
		IMPL_TYPE_DECLARE(CreateClodMesh);
	};

}

#endif // RENDERING_DETAIL_CREATE_CLOD_MESH_H
