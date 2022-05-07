///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 15:24)

#ifndef RENDERING_CURVES_SURFACES_FLOAT2_ARRAY_IMPL_H
#define RENDERING_CURVES_SURFACES_FLOAT2_ARRAY_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Base/Float.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Float2ArrayImpl
    {
    public:
        using ClassType = Float2ArrayImpl;
        using Float2 = Mathematics::Float2;
        using Float2Vector = std::vector<Float2>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        Float2ArrayImpl() noexcept;
        explicit Float2ArrayImpl(const Float2Vector& elements);

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        NODISCARD int GetNumElements() const;
        NODISCARD const Float2* GetData() const noexcept;

        NODISCARD const Float2& operator[](int index) const;
        NODISCARD Float2& operator[](int index);

    private:
        Float2Vector elements;
    };
}

#endif  // RENDERING_CURVES_SURFACES_FLOAT2_ARRAY_IMPL_H
