///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:51)

#ifndef RENDERING_DETAIL_CREATE_CLOD_MESH_H
#define RENDERING_DETAIL_CREATE_CLOD_MESH_H

#include "Rendering/RenderingDll.h"

#include "CollapseRecordArray.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(CreateClodMeshImpl);

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
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CreateClodMesh);

    public:
        explicit CreateClodMesh(TrianglesMesh& mesh);

        CLASS_INVARIANT_DECLARE;

        NODISCARD CollapseRecordArraySharedPtr GetCollapseRecordArray() const;

    private:
        PackageType impl;
    };

}

#endif  // RENDERING_DETAIL_CREATE_CLOD_MESH_H
