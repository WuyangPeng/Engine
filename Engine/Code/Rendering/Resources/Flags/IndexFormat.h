///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/09 16:08)

#ifndef RENDERING_RESOURCES_INDEX_FORMAT_H
#define RENDERING_RESOURCES_INDEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumMacro.h"

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

    ENUM_ANDABLE_OPERATOR_DEFINE(IndexFormatType)
}

#endif  // RENDERING_RESOURCES_INDEX_FORMAT_H