///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/08 18:37)

#ifndef RENDERING_DETAIL_CLOD_MESH_COLLAPSE_INFO_H
#define RENDERING_DETAIL_CLOD_MESH_COLLAPSE_INFO_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    // 有关塌边的信息。
    class RENDERING_HIDDEN_DECLARE ClodMeshCollapseInfo
    {
    public:
        using ClassType = ClodMeshCollapseInfo;

    public:
        ClodMeshCollapseInfo(int vKeep = -1, int vThrow = -1) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetVKeep() const noexcept;
        void SetVKeep(int vKeep) noexcept;
        NODISCARD int GetVThrow() const noexcept;
        void SetVThrow(int vThrow) noexcept;
        NODISCARD int GetTThrow0() const noexcept;
        void SetTThrow0(int tThrow0) noexcept;
        NODISCARD int GetTThrow1() const noexcept;
        void SetTThrow1(int tThrow1) noexcept;

    private:
        int vKeepInfo;
        int vThrowInfo;
        int tThrow0Info;
        int tThrow1Info;
    };
}

#endif  // RENDERING_DETAIL_CLOD_MESH_COLLAPSE_INFO_H
