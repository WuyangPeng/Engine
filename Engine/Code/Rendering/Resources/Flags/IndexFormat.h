///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:24)

#ifndef RENDERING_RESOURCES_INDEX_FORMAT_H
#define RENDERING_RESOURCES_INDEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumOperator.h"

namespace Rendering
{
    enum class IndexFormatType : uint32_t
    {
        Zero = 0x00000000,

        None = 0xFFFFFFFF,
        Polypoint = 0x00000001,
        PolysegmentDisjoint = 0x00000002,
        PolysegmentContiguous = 0x00000004,
        Trimesh = 0x00000008,
        Tristrip = 0x00000010,
        PolysegmentDisjointAdj = 0x00000020,
        PolysegmentContiguousAdj = 0x00000040,
        TrimeshAdj = 0x00000080,
        TristripAdj = 0x00000100,

        HasPoints = Polypoint,

        HasSegments = PolysegmentDisjoint |
                      PolysegmentContiguous |
                      PolysegmentDisjointAdj |
                      PolysegmentContiguousAdj,

        HasTriangles = Trimesh |
                       Tristrip |
                       TrimeshAdj |
                       TristripAdj,

        NumTypes = 9
    };

}

#endif  // RENDERING_RESOURCES_INDEX_FORMAT_H