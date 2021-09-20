// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 10:28)

#ifndef RENDERING_DETAIL_COLLAPSE_RECORD_H
#define RENDERING_DETAIL_COLLAPSE_RECORD_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include <vector>
RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(CollapseRecord,CollapseRecordImpl);

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
}

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE CollapseRecord
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(CollapseRecord);
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit CollapseRecord(int vKeep = -1, int vThrow = -1, int numVertices = 0, int numTriangles = 0);

        CLASS_INVARIANT_DECLARE;

        void SetIndices(const std::vector<int>& indices);
        const std::vector<int> GetIndices() const;
        int GetIndex(int index) const;
        int GetIndicesSize() const;
        void ClearIndices();

        int GetVKeep() const noexcept;
        void SetVKeep(int vKeep);
        int GetVThrow() const noexcept;
        void SetVThrow(int vThrow);
        int GetNumVertices() const noexcept;
        void SetNumVertices(int numVertices);
        int GetNumTriangles() const noexcept;
        void SetNumTriangles(int numTriangles);

        void Load(const CoreTools::BufferSourceSharedPtr& source);
        void Save(const CoreTools::BufferTargetSharedPtr& target) const;
        int GetStreamingSize() const;

    private:
        ;
        PackageType impl;
    };

    bool RENDERING_DEFAULT_DECLARE operator==(const CollapseRecord& lhs, const CollapseRecord& rhs);
}

#endif  // RENDERING_DETAIL_COLLAPSE_RECORD_H
