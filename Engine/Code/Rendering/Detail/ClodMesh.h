// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/24 10:28)

#ifndef RENDERING_DETAIL_CLOD_MESH_H
#define RENDERING_DETAIL_CLOD_MESH_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Detail/CollapseRecordArray.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

EXPORT_SHARED_PTR(Rendering, ClodMeshImpl, RENDERING_DEFAULT_DECLARE);

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ClodMesh : public TrianglesMesh
    {
    public:
        void Swap(ClodMesh& rhs) noexcept;

    public:
        TYPE_DECLARE(ClodMesh);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~ClodMesh() noexcept = default;
        ClodMesh(const ClodMesh& rhs);
        ClodMesh& operator=(const ClodMesh& rhs);
        ClodMesh(ClodMesh&& rhs) noexcept;
        ClodMesh& operator=(ClodMesh&& rhs) noexcept;
        using ParentType = TrianglesMesh;

    public:
        // ClodMesh�����ơ����񡱵�������������
        // ��Ϊ����Ҫ�ܹ������ظ�������������
        // ������ClodMesh��������ͬ�Ķ��㻺�������۵��ļ�¼��
        explicit ClodMesh(const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer,
                          const IndexBufferSharedPtr& indexbuffer, const CollapseRecordArraySharedPtr& recordArray);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ClodMesh);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        int GetNumRecords() const;

        int GetTargetRecord() const noexcept;
        void SetTargetRecord(int targetRecord) noexcept;

        // LODѡ���ǻ���Ӧ���ֶ�ѡ��
        // Ҫʹ������������Ļ�ռ�ĸ��Ƿ�Χ��
        // ��ClodMesh���������д��GetAutomatedTargetRecord����

        // ��ȡĿ���¼�����⺯����������������д���Ի��Ŀ��������Զ������
        virtual int GetAutomatedTargetRecord() const;

        // ���θ��¡�Draw���������ô˸��£�������Ŀ���¼�ĵ�ǰֵ����TrianglesMesh������
        // �����ڲ���Ҫ��ʾ�����Ӧ�ó����ֶ����á�
        void SelectLevelOfDetail();

        ControllerInterfaceSharedPtr Clone() const override;

    protected:
        // ֧�ַּ��ü���
        void GetVisibleSet(Culler& culler, bool noCull) override;

    private:
        using ImplPtr = std::shared_ptr<ImplType>;
    private:
        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(ClodMesh);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE(ClodMesh);
}
#include STSTEM_WARNING_POP
#endif  // RENDERING_DETAIL_CLOD_MESH_H
