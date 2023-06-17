///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:11)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_INDEX_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_INDEX_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TriangleIndex
    {
    public:
        using ClassType = TriangleIndex;

    public:
        TriangleIndex(int firstIndex, int secondIndex, int thirdIndex) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetFirstIndex() const noexcept;
        NODISCARD int GetSecondIndex() const noexcept;
        NODISCARD int GetThirdIndex() const noexcept;

        NODISCARD int operator[](int index) const;

    private:
        int index0;
        int index1;
        int index2;
    };
}

#endif  // RENDERING_SCENE_GRAPH_TRIANGLES_INDEX_H
