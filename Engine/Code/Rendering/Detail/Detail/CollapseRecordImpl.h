///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/09 19:26)

#ifndef RENDERING_DETAIL_COLLAPSE_RECORD_IMPL_H
#define RENDERING_DETAIL_COLLAPSE_RECORD_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CollapseRecordImpl
    {
    public:
        using ClassType = CollapseRecordImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit CollapseRecordImpl(int vKeep = -1, int vThrow = -1, int numVertices = 0, int numTriangles = 0) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetIndices(const std::vector<int>& aIndices);
        NODISCARD std::vector<int> GetIndices() const;
        NODISCARD int GetIndex(int index) const;
        NODISCARD int GetIndicesSize() const;
        void ClearIndices() noexcept;

        NODISCARD int GetVKeep() const noexcept;
        void SetVKeep(int vKeep) noexcept;
        NODISCARD int GetVThrow() const noexcept;
        void SetVThrow(int vThrow) noexcept;
        NODISCARD int GetNumVertices() const noexcept;
        void SetNumVertices(int aNumVertices) noexcept;
        NODISCARD int GetNumTriangles() const noexcept;
        void SetNumTriangles(int aNumTriangles) noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        // 边<VKeep，VThrow>折叠使VThrow被VKeep取代。
        int recordVKeep;
        int recordVThrow;

        // 边折叠后的顶点数。
        int numVertices;

        // 边折叠后的三角形数
        int numTriangles;

        // [0..NumTriangles-1]中包含VThrow的索引数组
        std::vector<int> indices;
    };
}

#endif  // RENDERING_DETAIL_COLLAPSE_RECORD_IMPL_H
