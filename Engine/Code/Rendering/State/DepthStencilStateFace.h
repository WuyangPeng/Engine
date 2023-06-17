///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:25)

#ifndef RENDERING_STATE_DEPTH_STENCIL_STATE_FACE_H
#define RENDERING_STATE_DEPTH_STENCIL_STATE_FACE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/State/StateFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE DepthStencilStateFace
    {
    public:
        using ClassType = DepthStencilStateFace;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        DepthStencilStateFace() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD DepthStencilStateOperation GetFail() const noexcept;
        void SetFail(DepthStencilStateOperation aFail) noexcept;

        NODISCARD DepthStencilStateOperation GetDepthFail() const noexcept;
        void SetDepthFail(DepthStencilStateOperation aDepthFail) noexcept;

        NODISCARD DepthStencilStateOperation GetPass() const noexcept;
        void SetPass(DepthStencilStateOperation aPass) noexcept;

        NODISCARD DepthStencilStateComparison GetComparison() const noexcept;
        void SetComparison(DepthStencilStateComparison aComparison) noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        DepthStencilStateOperation fail;
        DepthStencilStateOperation depthFail;
        DepthStencilStateOperation pass;
        DepthStencilStateComparison comparison;
    };

    NODISCARD bool RENDERING_DEFAULT_DECLARE operator==(const DepthStencilStateFace& lhs, const DepthStencilStateFace& rhs) noexcept;
}

#endif  // RENDERING_STATE_DEPTH_STENCIL_STATE_FACE_H
