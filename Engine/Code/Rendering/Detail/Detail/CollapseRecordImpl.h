///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/09 19:26)

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
        // ��<VKeep��VThrow>�۵�ʹVThrow��VKeepȡ����
        int recordVKeep;
        int recordVThrow;

        // ���۵���Ķ�������
        int numVertices;

        // ���۵������������
        int numTriangles;

        // [0..NumTriangles-1]�а���VThrow����������
        std::vector<int> indices;
    };
}

#endif  // RENDERING_DETAIL_COLLAPSE_RECORD_IMPL_H
