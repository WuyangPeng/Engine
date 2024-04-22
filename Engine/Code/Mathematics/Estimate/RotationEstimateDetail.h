///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/18 19:38)

#ifndef MATHEMATICS_ESTIMATE_ROTATION_ESTIMATE_DETAIL_H
#define MATHEMATICS_ESTIMATE_ROTATION_ESTIMATE_DETAIL_H

#include "RotationEstimate.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T, int Degree>
requires((Degree & 1) == 0 && 4 <= Degree && Degree <= 16)
T Mathematics::RotC0Estimate(T t)
{
    constexpr auto select = (Degree - 4) / 2;
    constexpr auto& coefficient = rotation0EstimateCoefficient.at(select);
    constexpr auto last = Degree / 2;
    auto tSquare = t * t;
    auto poly = static_cast<T>(coefficient.at(last));
    for (auto i = 0, index = last - 1; i < last; ++i, --index)
    {
        poly = static_cast<T>(coefficient.at(index)) + poly * tSquare;
    }

    return poly;
}

template <typename T, int Degree>
requires((Degree & 1) == 0 && 4 <= Degree && Degree <= 16)
T Mathematics::RotC1Estimate(T t)
{
    constexpr auto select = (Degree - 4) / 2;
    constexpr auto& coefficient = rotation1EstimateCoefficient.at(select);
    auto constexpr last = Degree / 2;
    auto tSquare = t * t;
    auto poly = static_cast<T>(coefficient.at(last));
    for (auto i = 0, index = last - 1; i < last; ++i, --index)
    {
        poly = static_cast<T>(coefficient.at(index)) + poly * tSquare;
    }

    return poly;
}

template <typename T, int Degree>
requires((Degree & 1) == 0 && 4 <= Degree && Degree <= 16)
T Mathematics::RotC2Estimate(T t)
{
    constexpr auto select = (Degree - 4) / 2;
    constexpr auto& coefficient = rotation2EstimateCoefficient.at(select);
    constexpr auto last = Degree / 2;
    auto tSquare = t * t;
    auto poly = static_cast<T>(coefficient.at(last));
    for (auto i = 0, index = last - 1; i < last; ++i, --index)
    {
        poly = static_cast<T>(coefficient.at(index)) + poly * tSquare;
    }

    return poly;
}

template <typename T, int Degree>
requires((Degree & 1) == 0 && 4 <= Degree && Degree <= 16)
T Mathematics::RotC3Estimate(T t)
{
    constexpr auto select = (Degree - 4) / 2;
    constexpr auto& coefficient = rotation3EstimateCoefficient.at(select);
    constexpr auto last = Degree / 2;
    auto tSquare = t * t;
    auto poly = static_cast<T>(coefficient.at(last));
    for (auto i = 0, index = last - 1; i < last; ++i, --index)
    {
        poly = static_cast<T>(coefficient.at(index)) + poly * tSquare;
    }

    return poly;
}

template <typename T, int Degree>
Mathematics::Matrix3<T> Mathematics::RotationEstimate(const Vector3<T>& point)
{
    const auto identity = Matrix3<T>::GetIdentity();

    const Matrix3<T> s{ Math<T>::GetValue(0), -point[2], point[1], point[2], Math<T>::GetValue(0), -point[0], -point[1], point[0], Math<T>::GetValue(0) };

    auto p0P0 = point[0] * point[0];
    auto p0P1 = point[0] * point[1];
    auto p0P2 = point[0] * point[2];
    auto p1P1 = point[1] * point[1];
    auto p1P2 = point[1] * point[2];
    auto p2P2 = point[2] * point[2];
    const Matrix3<T> sSquare{ -(p1P1 + p2P2), p0P1, p0P2, p0P1, -(p0P0 + p2P2), p1P2, p0P2, p1P2, -(p0P0 + p1P1) };

    auto t = Vector3Tools<T>::GetLength(point);
    auto a = RotC0Estimate<T, Degree>(t);
    auto b = RotC1Estimate<T, Degree>(t);

    return identity + a * s + b * sSquare;
};

template <typename T, int Degree>
std::array<Mathematics::Matrix3<T>, 3> Mathematics::RotationDerivativeEstimate(const Vector3<T>& point)
{
    std::array<Matrix3<T>, 3> skewE{ Matrix3<T>{ Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(-1), Math<T>::GetValue(0), Math<T>::GetValue(1), Math<T>::GetValue(0) },
                                     Matrix3<T>{ Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(1), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(-1), Math<T>::GetValue(0), Math<T>::GetValue(0) },
                                     Matrix3<T>{ Math<T>::GetValue(0), Math<T>::GetValue(-1), Math<T>::GetValue(0), Math<T>::GetValue(1), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0) } };

    const Matrix3<T> s{ Math<T>::GetValue(0), -point[2], point[1], point[2], Math<T>::GetValue(0), -point[0], -point[1], point[0], Math<T>::GetValue(0) };

    auto p0P0 = point[0] * point[0];
    auto p0P1 = point[0] * point[1];
    auto p0P2 = point[0] * point[2];
    auto p1P1 = point[1] * point[1];
    auto p1P2 = point[1] * point[2];
    auto p2P2 = point[2] * point[2];
    const Matrix3<T> sSquare{ -(p1P1 + p2P2), p0P1, p0P2, p0P1, -(p0P0 + p2P2), p1P2, p0P2, p1P2, -(p0P0 + p1P1) };

    auto t = Vector3Tools<T>::GetLength(point);
    auto a = RotC0Estimate<T, Degree>(t);
    auto b = RotC1Estimate<T, Degree>(t);
    auto c = RotC2Estimate<T, Degree>(t);
    auto d = RotC3Estimate<T, Degree>(t);

    std::array<Matrix3<T>, 3> rotationDerivativeEstimateReal{ Matrix3<T>{}, Matrix3<T>{}, Matrix3<T>{} };
    for (auto i = 0; i < 3; ++i)
    {
        rotationDerivativeEstimateReal.at(i) = a * skewE.at(i) + b * (s * skewE.at(i) + skewE.at(i) * s) - point[i] * (c * s + d * sSquare);
    }
    return rotationDerivativeEstimateReal;
}

template <typename T, int Degree>
void Mathematics::RotationAndDerivativeEstimate(const Vector3<T>& point, Matrix3<T>& rotation, std::array<Matrix3<T>, 3>& rotationDerivativeEstimateReal)
{
    auto identity = Matrix3<T>::GetIdentity();

    std::array<Matrix3<T>, 3> skewE{ Matrix3<T>{ Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(-1), Math<T>::GetValue(0), Math<T>::GetValue(1), Math<T>::GetValue(0) },
                                     Matrix3<T>{ Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(1), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(-1), Math<T>::GetValue(0), Math<T>::GetValue(0) },
                                     Matrix3<T>{ Math<T>::GetValue(0), Math<T>::GetValue(-1), Math<T>::GetValue(0), Math<T>::GetValue(1), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0), Math<T>::GetValue(0) } };

    Matrix3<T> s{ Math<T>::GetValue(0), -point[2], point[1], point[2], Math<T>::GetValue(0), -point[0], -point[1], point[0], Math<T>::GetValue(0) };

    auto p0P0 = point[0] * point[0];
    auto p0P1 = point[0] * point[1];
    auto p0P2 = point[0] * point[2];
    auto p1P1 = point[1] * point[1];
    auto p1P2 = point[1] * point[2];
    auto p2P2 = point[2] * point[2];
    Matrix3<T> sSquare{ -(p1P1 + p2P2), p0P1, p0P2, p0P1, -(p0P0 + p2P2), p1P2, p0P2, p1P2, -(p0P0 + p1P1) };

    auto t = Length(point);
    auto a = RotC0Estimate<T, Degree>(t);
    auto b = RotC1Estimate<T, Degree>(t);
    auto c = RotC2Estimate<T, Degree>(t);
    auto d = RotC3Estimate<T, Degree>(t);

    rotation = identity + a * s + b * sSquare;
    for (auto i = 0; i < 3; ++i)
    {
        rotationDerivativeEstimateReal[i] = a * skewE[i] + b * (s * skewE[i] + skewE[i] * s) - point[i] * (c * s + d * sSquare);
    }
}

#endif  // MATHEMATICS_ESTIMATE_ROTATION_ESTIMATE_DETAIL_H
