///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/11 10:51)

#ifndef RENDERING_DETAIL_COLLAPSE_RECORD_H
#define RENDERING_DETAIL_COLLAPSE_RECORD_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(CollapseRecord, CollapseRecordImpl);

#include <vector>

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE CollapseRecord
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(CollapseRecord);
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit CollapseRecord(int vKeep, int vThrow = -1, int numVertices = 0, int numTriangles = 0);

        CLASS_INVARIANT_DECLARE;

        void SetIndices(const std::vector<int>& indices);
        NODISCARD std::vector<int> GetIndices() const;
        NODISCARD int GetIndex(int index) const;
        NODISCARD int GetIndicesSize() const;
        void ClearIndices();

        NODISCARD int GetVKeep() const noexcept;
        void SetVKeep(int vKeep);
        NODISCARD int GetVThrow() const noexcept;
        void SetVThrow(int vThrow);
        NODISCARD int GetNumVertices() const noexcept;
        void SetNumVertices(int numVertices);
        NODISCARD int GetNumTriangles() const noexcept;
        void SetNumTriangles(int numTriangles);

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        PackageType impl;
    };

    NODISCARD bool RENDERING_DEFAULT_DECLARE operator==(const CollapseRecord& lhs, const CollapseRecord& rhs);
}

#endif  // RENDERING_DETAIL_COLLAPSE_RECORD_H
