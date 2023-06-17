///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:50)

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

        // 几何更新。Draw函数将调用此更新，并根据目标记录的当前值调整TrianglesMesh数量。
        // 可以在不需要显示网格的应用程序手动调用。
        void SelectLevelOfDetail(VertexBuffer& vertexbuffer, const IndexBufferSharedPtr& indexbuffer, int aTargetRecord);

        CORE_TOOLS_NAMES_IMPL_DECLARE;

    private:
        // 成员LOD选择。
        int currentRecord;
        int targetRecord;
        CoreTools::ObjectAssociated<CollapseRecordArray> recordArray;
    };
}

#endif  // RENDERING_DETAIL_CLOD_MESH_IMPL_H
