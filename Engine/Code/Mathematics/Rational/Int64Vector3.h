/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:28)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR3_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR3_H

#include "Mathematics/MathematicsDll.h"

#include "Int64Vector.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <iosfwd>

MATHEMATICS_DELAY_COPY_UNSHARED_EXPORT_IMPL(Int64Vector3, Int64Vector3Impl);

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE Int64Vector3 : private boost::additive<Int64Vector3, boost::totally_ordered<Int64Vector3, boost::multiplicative<Int64Vector3, int64_t>>>
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(Int64Vector3);

    private:
        explicit Int64Vector3(CoreTools::DisableNotThrow disableNotThrow);

    public:
        NODISCARD static Int64Vector3 CreateDefault();

        explicit Int64Vector3(const Int64Vector<3>& rhs);
        Int64Vector3(int64_t x, int64_t y, int64_t z);

        Int64Vector3& operator=(const Int64Vector<3>& rhs);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int64_t GetX() const;
        void SetX(int64_t x);
        NODISCARD int64_t GetY() const;
        void SetY(int64_t y);
        NODISCARD int64_t GetZ() const;
        void SetZ(int64_t z);

        NODISCARD Int64Vector3 operator-() const;

        Int64Vector3& operator+=(const Int64Vector3& rhs);
        Int64Vector3& operator-=(const Int64Vector3& rhs);
        Int64Vector3& operator*=(int64_t scalar);
        Int64Vector3& operator/=(int64_t scalar);

        NODISCARD int64_t SquaredLength() const noexcept;

        // 返回 Dot(lhs,rhs).
        NODISCARD int64_t Dot(const Int64Vector3& rhs) const;

        // 返回 Cross(this,V)
        NODISCARD Int64Vector3 Cross(const Int64Vector3& rhs) const;

        // 返回 Dot(this,Cross(U,V))
        NODISCARD int64_t TripleScalar(const Int64Vector3& mhs, const Int64Vector3& rhs) const;

        NODISCARD bool operator==(const Int64Vector3& rhs) const;
        NODISCARD bool operator<(const Int64Vector3& rhs) const;

    private:
        PackageType impl;
    };

    MATHEMATICS_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const Int64Vector3& rhs);
}

#endif  // MATHEMATICS_RATIONAL_INT64_VECTOR3_H
