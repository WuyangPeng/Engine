///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/11 10:46)

#ifndef RENDERING_DETAIL_CLOD_MESH_H
#define RENDERING_DETAIL_CLOD_MESH_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Detail/CollapseRecordArray.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ClodMesh, ClodMeshImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ClodMesh : public TrianglesMesh
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ClodMesh);
        using ParentType = TrianglesMesh;

    public:
        // ClodMesh�����ơ����񡱵�������������
        // ��Ϊ����Ҫ�ܹ������ظ�������������
        // ������ClodMesh��������ͬ�Ķ��㻺�������۵��ļ�¼��
        explicit ClodMesh(const VertexFormatSharedPtr& vertexformat,
                          const VertexBufferSharedPtr& vertexbuffer,
                          const IndexBuffer& indexbuffer,
                          const CollapseRecordArraySharedPtr& recordArray);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ClodMesh);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD int GetNumRecords() const;

        NODISCARD int GetTargetRecord() const noexcept;
        void SetTargetRecord(int targetRecord) noexcept;

        // LODѡ���ǻ���Ӧ���ֶ�ѡ��
        // Ҫʹ������������Ļ�ռ�ĸ��Ƿ�Χ��
        // ��ClodMesh���������д��GetAutomatedTargetRecord����

        // ��ȡĿ���¼�����⺯����������������д���Ի��Ŀ��������Զ������
        NODISCARD virtual int GetAutomatedTargetRecord() const;

        // ���θ��¡�Draw���������ô˸��£�������Ŀ���¼�ĵ�ǰֵ����TrianglesMesh������
        // �����ڲ���Ҫ��ʾ�����Ӧ�ó����ֶ����á�
        void SelectLevelOfDetail();

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;

    protected:
        // ֧�ַּ��ü���
        void GetVisibleSet(Culler& culler, bool noCull) override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(ClodMesh);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ClodMesh);
}

#endif  // RENDERING_DETAIL_CLOD_MESH_H
