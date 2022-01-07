// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:49)

#ifndef RENDERING_CURVES_SURFACES_FLOAT2_ARRAY_IMPL_H
#define RENDERING_CURVES_SURFACES_FLOAT2_ARRAY_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Base/Float.h"

#include <vector>
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
}

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
        int GetStreamingSize() const;

        int GetNumElements() const;
        const Float2* GetData() const noexcept;

        const Float2& operator[](int index) const;
        Float2& operator[](int index);

    private:
        Float2Vector m_Elements;
    };
}

#endif  // RENDERING_CURVES_SURFACES_FLOAT2_ARRAY_IMPL_H
