///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:16)

#ifndef MATHEMATICS_MESHES_EDGE_KEY_H
#define MATHEMATICS_MESHES_EDGE_KEY_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <array>
#include <iosfwd>

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE EdgeKey
    {
    public:
        using ClassType = EdgeKey;

    public:
        EdgeKey(int first, int second) noexcept;
        EdgeKey() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetKey(int index) const;
        void SetKey(int index, int value);

    private:
        NODISCARD std::array<int, 2> Init(int first, int second) noexcept;

    private:
        std::array<int, 2> vertex;
    };

    NODISCARD bool MATHEMATICS_DEFAULT_DECLARE operator<(const EdgeKey& lhs, const EdgeKey& rhs);

    MATHEMATICS_DEFAULT_DECLARE System::OStream& operator<<(System::OStream& os, const EdgeKey& edgeKey);
}

#endif  // MATHEMATICS_MESHES_EDGE_KEY_H