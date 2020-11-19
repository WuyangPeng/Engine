///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 17:32)
///
#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR3_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR3_H

#include "Mathematics/MathematicsDll.h"

#include "Int64Vector.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iosfwd>

MATHEMATICS_EXPORT_SHARED_PTR(Int64Vector3Impl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE Int64Vector3 : private boost::additive<Int64Vector3, boost::totally_ordered<Int64Vector3, boost::multiplicative<Int64Vector3, int64_t>>>
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Int64Vector3);

    public:
        Int64Vector3();
        explicit Int64Vector3(const Int64Vector<3>& rhs);
        Int64Vector3(int64_t x, int64_t y, int64_t z);

        Int64Vector3& operator=(const Int64Vector<3>& rhs);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int64_t GetX() const;
        void SetX(int64_t x);
        [[nodiscard]] int64_t GetY() const;
        void SetY(int64_t y);
        [[nodiscard]] int64_t GetZ() const;
        void SetZ(int64_t z);

        [[nodiscard]] const Int64Vector3 operator-() const;

        Int64Vector3& operator+=(const Int64Vector3& rhs);
        Int64Vector3& operator-=(const Int64Vector3& rhs);
        Int64Vector3& operator*=(int64_t scalar);
        Int64Vector3& operator/=(int64_t scalar);

        [[nodiscard]] int64_t SquaredLength() const noexcept;

        // 返回 Dot(lhs,rhs).
        [[nodiscard]] int64_t Dot(const Int64Vector3& rhs) const;

        // 返回 Cross(this,V)
        [[nodiscard]] Int64Vector3 Cross(const Int64Vector3& rhs) const;

        // 返回 Dot(this,Cross(U,V))
        [[nodiscard]] int64_t TripleScalar(const Int64Vector3& mhs, const Int64Vector3& rhs) const;

        [[nodiscard]] bool operator==(const Int64Vector3& rhs) const;
        [[nodiscard]] bool operator<(const Int64Vector3& rhs) const;

    private:
        IMPL_TYPE_DECLARE(Int64Vector3);
    };

    MATHEMATICS_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const Int64Vector3& rhs);
}

#endif  // MATHEMATICS_RATIONAL_INT64_VECTOR3_H
