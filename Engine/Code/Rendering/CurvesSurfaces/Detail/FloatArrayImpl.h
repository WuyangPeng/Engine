///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 15:30)

#ifndef RENDERING_CURVES_SURFACES_FLOAT_ARRAY_IMPL_H
#define RENDERING_CURVES_SURFACES_FLOAT_ARRAY_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE FloatArrayImpl
    {
    public:
        using ClassType = FloatArrayImpl;
        using FloatVector = std::vector<float>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        FloatArrayImpl() noexcept;
        explicit FloatArrayImpl(const FloatVector& elements);

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        NODISCARD int GetNumElements() const;
        NODISCARD const float* GetData() const noexcept;

        NODISCARD const float& operator[](int index) const;
        NODISCARD float& operator[](int index);

    private:
        FloatVector elements;
    };
}

#endif  // RENDERING_CURVES_SURFACES_FLOAT_ARRAY_IMPL_H
