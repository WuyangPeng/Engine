///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/20 16:23)

#ifndef MATHEMATICS_ALGEBRA_CONVERT_COORDINATES_H
#define MATHEMATICS_ALGEBRA_CONVERT_COORDINATES_H

#include "Mathematics/MathematicsDll.h"

#include "Matrix/Matrix.h"

/// 转换两个坐标系之间的点和变换。
/// 数学涉及基础的变化。
/// 下面显示了3D转换的典型用法。
///
/// 基础的线性变化。
/// U的列是源坐标系的基向量。
/// 源坐标系中的向量X = { x0, x1, x2 }表示为
///   X = x0*(1,0,0) + x1*(0,1,0) + x2*(0,0,1)
///   该点的笛卡尔坐标是这些项的组合，
///   X = (x0, x1, x2)
///   V的列是目标坐标系的基向量。
///   目标坐标系中的向量Y = { y0, y1, y2 }表示为
///   Y = y0*(1,0,0,0) + y1*(0,0,1) + y2*(0,1,0)
/// 矢量的笛卡尔坐标是这些项的组合，
///   Y = (y0, y2, y1)
///   调用Y = convert.UToV(X)计算y0、y1和y2，
///   使得X和Y的笛卡尔坐标相同。例如
///   X = { 1.0, 2.0, 3.0 }
///     = 1.0*(1,0,0) + 2.0*(0,1,0) + 3.0*(0,0,1)
///     = (1, 2, 3)
///   Y = { 1.0, 3.0, 2.0 }
///     = 1.0*(1,0,0) + 3.0*(0,0,1) + 2.0*(0,1,0)
///    = (1, 2, 3)
///    X和Y表示相同的矢量（相等的笛卡尔坐标），
///    但在源坐标和目标坐标中具有不同的表示。
///
/// ConvertCoordinates<3, double> convert;
/// Vector<3, double> X, Y, P0, P1, diff;
/// Matrix<3, 3, double> U, V, A, B;
/// bool isRHU, isRHV;
/// U.SetCol(0, Vector3<double>{1.0, 0.0, 0.0});
/// U.SetCol(1, Vector3<double>{0.0, 1.0, 0.0});
/// U.SetCol(2, Vector3<double>{0.0, 0.0, 1.0});
/// V.SetCol(0, Vector3<double>{1.0, 0.0, 0.0});
/// V.SetCol(1, Vector3<double>{0.0, 0.0, 1.0});
/// V.SetCol(2, Vector3<double>{0.0, 1.0, 0.0});
/// convert(U, true, V, true);
/// isRHU = convert.IsRightHandedU();  // true
/// isRHV = convert.IsRightHandedV();  // false
/// X = { 1.0, 2.0, 3.0 };
/// Y = convert.UToV(X);  // { 1.0, 3.0, 2.0 }
/// P0 = U*X;
/// P1 = V*Y;
/// diff = P0 - P1;  // { 0, 0, 0 }
/// Y = { 0.0, 1.0, 2.0 };
/// X = convert.VToU(Y);  // { 0.0, 2.0, 1.0 }
/// P0 = U*X;
/// P1 = V*Y;
/// diff = P0 - P1;  // { 0, 0, 0 }
/// double cs = 0.6, sn = 0.8;  // cs*cs + sn*sn = 1
/// A.SetCol(0, Vector3<double>{  c,   s, 0.0});
/// A.SetCol(1, Vector3<double>{ -s,   c, 0.0});
/// A.SetCol(2, Vector3<double>{0.0, 0.0, 1.0});
/// B = convert.UToV(A);
///   // B.GetCol(0) = { c, 0, s}
///   // B.GetCol(1) = { 0, 1, 0}
///   // B.GetCol(2) = {-s, 0, c}
/// X = A*X;  // U is VOR
/// Y = B*Y;  // V is VOR
/// P0 = U*X;
/// P1 = V*Y;
/// diff = P0 - P1;  // { 0, 0, 0 }
///
/// 仿射变换基础。
/// U的前三列是源坐标系的基向量，最后一个分量必须设置为0。
/// 最后一列是该系统的原点，并且必须将最后一个零部件设置为1。
/// 源坐标系中的点X = { x0, x1, x2, 1 }表示为
///   X = x0*(-1,0,0,0) + x1*(0,0,1,0) + x2*(0,-1,0,0) + 1*(1,2,3,1)
///   该点的笛卡尔坐标是这些项的组合，
///   X = (-x0 + 1, -x2 + 2, x1 + 3, 1)
///   V的前三列是目标坐标系的基向量，
///   最后一个分量必须设置为0。
///   最后一列是该系统的原点，
///   并且必须将最后一个零部件设置为1。
///   目标坐标系中的点Y = { y0, y1, y2, 1 } 表示为
///   Y = y0*(0,1,0,0) + y1*(-1,0,0,0) + y2*(0,0,1,0) + 1*(4,5,6,1)
///   该点的笛卡尔坐标是这些项的组合，
///   Y = (-y1 + 4, y0 + 5, y2 + 6, 1)
///   调用Y = convert.UToV(X)计算y0、y1和y2，使得X和Y的笛卡尔坐标相同。例如
///   X = { -1.0, 4.0, -3.0, 1.0 }
///     = -1.0*(-1,0,0,0) + 4.0*(0,0,1,0) - 3.0*(0,-1,0,0) + 1.0*(1,2,3,1)
///     = (2, 5, 7, 1)
///   Y = { 0.0, 2.0, 1.0, 1.0 }
///     = 0.0*(0,1,0,0) + 2.0*(-1,0,0,0) + 1.0*(0,0,1,0) + 1.0*(4,5,6,1)
///     = (2, 5, 7, 1)
/// X和Y表示相同的点（相等的笛卡尔坐标），但在源和目标仿射坐标中具有不同的表示。
///
/// ConvertCoordinates<4, double> convert;
/// Vector<4, double> X, Y, P0, P1, diff;
/// Matrix<4, 4, double> U, V, A, B;
/// bool isRHU, isRHV;
/// U.SetCol(0, Vector4<double>{-1.0, 0.0, 0.0, 0.0});
/// U.SetCol(1, Vector4<double>{0.0, 0.0, 1.0, 0.0});
/// U.SetCol(2, Vector4<double>{0.0, -1.0, 0.0, 0.0});
/// U.SetCol(3, Vector4<double>{1.0, 2.0, 3.0, 1.0});
/// V.SetCol(0, Vector4<double>{0.0, 1.0, 0.0, 0.0});
/// V.SetCol(1, Vector4<double>{-1.0, 0.0, 0.0, 0.0});
/// V.SetCol(2, Vector4<double>{0.0, 0.0, 1.0, 0.0});
/// V.SetCol(3, Vector4<double>{4.0, 5.0, 6.0, 1.0});
/// convert(U, true, V, false);
/// isRHU = convert.IsRightHandedU();  // false
/// isRHV = convert.IsRightHandedV();  // true
/// X = { -1.0, 4.0, -3.0, 1.0 };
/// Y = convert.UToV(X);  // { 0.0, 2.0, 1.0, 1.0 }
/// P0 = U*X;
/// P1 = V*Y;
/// diff = P0 - P1;  // { 0, 0, 0, 0 }
/// Y = { 1.0, 2.0, 3.0, 1.0 };
/// X = convert.VToU(Y);  // { -1.0, 6.0, -4.0, 1.0 }
/// P0 = U*X;
/// P1 = V*Y;
/// diff = P0 - P1;  // { 0, 0, 0, 0 }
/// double c = 0.6, s = 0.8;  // c*c + s*s = 1
/// A.SetCol(0, Vector4<double>{  c,  s,   0.0, 0.0});
/// A.SetCol(1, Vector4<double>{ -s,  c,   0.0, 0.0});
/// A.SetCol(2, Vector4<double>{0.0, 0.0,  1.0, 0.0});
/// A.SetCol(3, Vector4<double>{0.3, 1.0, -2.0, 1.0});
/// B = convert.UToV(A);
/// // B.GetCol(0) = {   1,    0,    0, 0 }
/// // B.GetCol(1) = {   0,    c,    s, 0 }
/// // B.GetCol(2) = {   0,   -s,    c, 0 }
/// // B.GetCol(3) = { 2.0, -0.9, -2.6, 1 }
/// X = A*X;  // U is VOR
/// Y = Y*B;  // V is VOL (not VOR)
/// P0 = U*X;
/// P1 = V*Y;
/// diff = P0 - P1;  // { 0, 0, 0, 0 }
namespace Mathematics
{
    template <int N, typename Real>
    class ConvertCoordinates
    {
    public:
        using ClassType = ConvertCoordinates<N, Real>;

        using Matrix = Algebra::Matrix<N, N, Real>;
        using Vector = Algebra::Vector<N, Real>;

    public:
        /// 构造基矩阵的变化。
        /// 该实现同时支持基的线性变化和基的仿射变化。
        ///
        /// 计算两个坐标系之间的基准变化。
        /// 当U和V不可逆时，抛出异常。
        /// 矩阵向量乘法约定影响矩阵变换的转换。
        /// 布尔输入指示在将矩阵应用为向量的变换时希望如何解释矩阵。
        ConvertCoordinates(const Matrix& u,
                           bool vectorOnRightU,
                           const Matrix& v,
                           bool vectorOnRightV);

        CLASS_INVARIANT_DECLARE;

        /// 成员访问
        NODISCARD Matrix GetC() const noexcept;
        NODISCARD Matrix GetInverseC() const noexcept;
        NODISCARD bool IsVectorOnRightU() const noexcept;
        NODISCARD bool IsVectorOnRightV() const noexcept;
        NODISCARD bool IsRightHandedU() const noexcept;
        NODISCARD bool IsRightHandedV() const noexcept;

        /// 转换坐标系之间的点。
        /// 系统的名称是U和V，以明确它们与构造函数的哪些输入相关联。
        /// X矢量存储U系统的坐标，Y矢量存储V系统的坐标。
        // Y = C^{-1}*X
        NODISCARD Vector UToV(const Vector& x) const;

        // X = C*Y
        NODISCARD Vector VToU(const Vector& y) const;

        /// 转换坐标系之间的变换。
        /// 输出是根据函数声明之前显示的表计算的。
        /// 上标T表示转置运算符。
        /// vectorOnRightU = true:  转换是 X' = A*X
        /// vectorOnRightU = false: 转换是 (X')^T = X^T*A
        /// vectorOnRightV = true:  转换是 Y' = B*Y
        /// vectorOnRightV = false: 转换是 (Y')^T = Y^T*B

        /// vectorOnRightU  | vectorOnRightV  | output
        /// ----------------+-----------------+---------------------
        /// true            | true            | C^{-1} * A * C
        /// true            | false           | (C^{-1} * A * C)^T
        /// false           | true            | C^{-1} * A^T * C
        /// false           | false           | (C^{-1} * A^T * C)^T
        NODISCARD Matrix UToV(const Matrix& a) const;

        // vectorOnRightU  | vectorOnRightV  | output
        // ----------------+-----------------+---------------------
        // true            | true            | C * B * C^{-1}
        // true            | false           | C * B^T * C^{-1}
        // false           | true            | (C * B * C^{-1})^T
        // false           | false           | (C * B^T * C^{-1})^T
        NODISCARD Matrix VToU(const Matrix& b) const;

    private:
        /// C = U^{-1}*V, C^{-1} = V^{-1}*U
        Matrix c;
        Matrix inverseC;
        bool isVectorOnRightU;
        bool isVectorOnRightV;
        bool isRightHandedU;
        bool isRightHandedV;
    };
}

#endif  // MATHEMATICS_ALGEBRA_CONVERT_COORDINATES_H
