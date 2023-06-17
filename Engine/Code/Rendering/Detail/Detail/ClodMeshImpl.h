///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:50)

#ifndef RENDERING_DETAIL_CLOD_MESH_IMPL_H
#define RENDERING_DETAIL_CLOD_MESH_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Detail/CollapseRecordArray.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ClodMeshImpl
    {
    public:
        using ClassType = ClodMeshImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;
        using Object = CoreTools::Object;

    public:
        ClodMeshImpl() noexcept;
        explicit ClodMeshImpl(const CollapseRecordArraySharedPtr& recordArray) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        NODISCARD int GetNumRecords() const;
        NODISCARD int GetTargetRecord() const noexcept;
        void SetTargetRecord(int aTargetRecord) noexcept;

        // ���θ��¡�Draw���������ô˸��£�������Ŀ���¼�ĵ�ǰֵ����TrianglesMesh������
        // �����ڲ���Ҫ��ʾ�����Ӧ�ó����ֶ����á�
        void SelectLevelOfDetail(VertexBuffer& vertexbuffer, const IndexBufferSharedPtr& indexbuffer, int aTargetRecord);

        CORE_TOOLS_NAMES_IMPL_DECLARE;

    private:
        // ��ԱLODѡ��
        int currentRecord;
        int targetRecord;
        CoreTools::ObjectAssociated<CollapseRecordArray> recordArray;
    };
}

#endif  // RENDERING_DETAIL_CLOD_MESH_IMPL_H
