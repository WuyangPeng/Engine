///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/03 16:26)

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
