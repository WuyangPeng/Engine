///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 14:43)

#ifndef RENDERING_RENDERER_ENGINE_PICK_RAY_IMPL_H
#define RENDERING_RENDERER_ENGINE_PICK_RAY_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

#include <boost/noncopyable.hpp>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PickRayImpl
    {
    public:
        using ClassType = PickRayImpl;

        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;

    public:
        PickRayImpl() noexcept;
        PickRayImpl(bool result, const APoint& origin, const AVector& direction) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsResult() const noexcept;
        NODISCARD APoint GetOrigin() const noexcept;
        NODISCARD AVector GetDirection() const noexcept;

    private:
        bool result;
        APoint origin;
        AVector direction;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_PICK_RAY_IMPL_H
