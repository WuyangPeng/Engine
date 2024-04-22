///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/18 19:38)

#ifndef MATHEMATICS_ESTIMATE_ROTATION_ESTIMATE_H
#define MATHEMATICS_ESTIMATE_ROTATION_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/PragmaWarning.h"
#include "Mathematics/Algebra/AlgebraFwd.h"

#include <array>

/// 旋转矩阵可以使用涉及三角项和多项式项的系数估计来构建。
namespace Mathematics
{
    //  rotc0(t) = sin(t)/t的常数。
    constexpr std::array<std::array<double, 9>, 7> rotation0EstimateCoefficient{
        {

            { // degree 4
              +1.00000000000000000e+00,
              -1.58971650732578684e-01,
              +5.84121356311684790e-03 },

            { // degree 6
              +1.00000000000000000e+00,
              -1.66218398161274539e-01,
              +8.06129151017077016e-03,
              -1.50545944866583496e-04 },

            { // degree 8
              +1.00000000000000000e+00,
              -1.66651290458553397e-01,
              +8.31836205080888937e-03,
              -1.93853969255209339e-04,
              +2.19921657358978346e-06 },

            { // degree 10
              +1.00000000000000000e+00,
              -1.66666320608302304e-01,
              +8.33284074932796014e-03,
              -1.98184457544372085e-04,
              +2.70931602688878442e-06,
              -2.07033154672609224e-08 },

            { // degree 12
              +1.00000000000000000e+00,
              -1.66666661172424652e-01,
              +8.33332258782261241e-03,
              -1.98405693280411671e-04,
              +2.75362742462233601e-06,
              -2.47308402132623094e-08,
              +1.36149931873379692e-10 },

            { // degree 14
              +1.00000000000000000e+00,
              -1.66666666641878403e-01,
              +8.33333324542580994e-03,
              -1.98412602287003715e-04,
              +2.75568576745228666e-06,
              -2.50407933908690801e-08,
              +1.59105811932465814e-10,
              -6.64696382424593659e-13 },

            { // degree 16
              +1.00000000000000000e+00,
              -1.66666666666648478e-01,
              +8.33333333318112164e-03,
              -1.98412698077537775e-04,
              +2.75573162083557394e-06,
              -2.50519743096581360e-08,
              +1.60558314470477309e-10,
              -7.60488921303402553e-13,
              +2.52255089807125025e-15 }

        }
    };

    constexpr std::array rotation0EstimateMaxError{
        6.9656371186750e-03,  // degree 4
        2.2379506089580e-04,  // degree 6
        4.8670096434722e-06,  // degree 8
        7.5654711606532e-08,  // degree 10
        8.7939167753293e-10,  // degree 12
        1.8030021919913e-12,  // degree 14
        6.8001160258291e-16  // degree 16
    };

    // rotc1(t) = (1-cos(t))/t^2的常数。
    constexpr std::array<std::array<double, 9>, 7> rotation1EstimateCoefficient{

        {

            { // degree 4
              +5.00000000000000000e-01,
              -4.06593520914583922e-02,
              +1.06698549928666312e-03 },

            { // degree 6
              +5.00000000000000000e-01,
              -4.16202835017619524e-02,
              +1.36087417563353699e-03,
              -1.99122437404000405e-05 },

            { // degree 8
              +5.00000000000000000e-01,
              -4.16653520191245796e-02,
              +1.38761160375298095e-03,
              -2.44138380330618480e-05,
              +2.28499434819148172e-07 },

            { // degree 10
              +5.00000000000000000e-01,
              -4.16666414534323168e-02,
              +1.38885303988547384e-03,
              -2.47850001122907892e-05,
              +2.72207208415419378e-07,
              -1.77358008604198045e-09 },

            { // degree 12
              +5.00000000000000000e-01,
              -4.16666663178411056e-02,
              +1.38888820709637153e-03,
              -2.48011431705276915e-05,
              +2.75439902957067131e-07,
              -2.06736081072201315e-09,
              +9.93003616566537400e-12 },

            { // degree 14
              +5.00000000000000000e-01,
              -4.16666666664263635e-02,
              +1.38888888750799658e-03,
              -2.48015851902670717e-05,
              +2.75571871163332658e-07,
              -2.08727380201649381e-09,
              +1.14076763269827225e-11,
              -4.28619236995285237e-14 },

            { // degree 16
              +5.00000000000000000e-01,
              -4.16666666666571719e-02,
              +1.38888888885105744e-03,
              -2.48015872513761947e-05,
              +2.75573160474227648e-07,
              -2.08766469798137579e-09,
              +1.14685460418668139e-11,
              -4.75415775440997119e-14,
              +1.40555891469552795e-16 }

        }
    };

    constexpr std::array rotation1EstimateMaxError{
        9.2119010150538e-04,  // degree 4
        2.3251261806301e-05,  // degree 6
        4.1693160884870e-07,  // degree 8
        5.5177887814395e-09,  // degree 10
        5.5865700954172e-11,  // degree 12
        7.1609385088323e-15,  // degree 14
        7.2164496600635e-16  // degree 16
    };

    // rotc2(t) = (sin(t) - t*cos(t))/t^3的常数。
    std::array<std::array<double, 9>, 7> constexpr rotation2EstimateCoefficient{
        {

            { // degree 4
              +3.33333333333333315e-01,
              -3.24417271573718483e-02,
              +9.05201583387763454e-04 },

            { // degree 6
              +3.33333333333333315e-01,
              -3.32912781805089902e-02,
              +1.16506615743456146e-03,
              -1.76083105011587047e-05 },

            { // degree 8
              +3.33333333333333315e-01,
              -3.33321218985461534e-02,
              +1.18929901553194335e-03,
              -2.16884239911580259e-05,
              +2.07111898922214621e-07 },

            { // degree 10
              +3.33333333333333315e-01,
              -3.33333098285276269e-02,
              +1.19044276839769606e-03,
              -2.20303898189124444e-05,
              +2.47382309403030923e-07,
              -1.63412179616686230e-09 },

            { // degree 12
              +3.33333333333333315e-01,
              -3.33333330053041110e-02,
              +1.19047554930712374e-03,
              -2.20454376929804210e-05,
              +2.50395723867477426e-07,
              -1.90797722371463640e-09,
              +9.25661071605387496e-12 },

            { // degree 14
              +3.33333333333333315e-01,
              -3.33333333331133561e-02,
              +1.19047618918715682e-03,
              -2.20458533943125258e-05,
              +2.50519837811549507e-07,
              -1.92670551155064303e-09,
              +1.06463697865186991e-11,
              -4.03135292145519115e-14 },

            { // degree 16
              +3.33333333333333315e-01,
              -3.33333333333034956e-02,
              +1.19047619036920628e-03,
              -2.20458552540489507e-05,
              +2.50521015434838418e-07,
              -1.92706504721931338e-09,
              +1.07026043656398707e-11,
              -4.46498739610373537e-14,
              +1.30526089083317312e-16 }

        }
    };

    constexpr std::array rotation2EstimateMaxError{
        8.1461508460229e-04,  // degree 4
        2.1075025784856e-05,  // degree 6
        3.8414838612888e-07,  // degree 8
        5.1435966597069e-09,  // degree 10
        5.2533449812486e-11,  // degree 12
        7.7715611723761e-15,  // degree 14
        2.2759572004816e-15  // degree 16
    };

    // rotc3(t) = (2*(1-cos(t)) - t*sin(t))/t^4的常数。
    std::array<std::array<double, 9>, 7> constexpr rotation3EstimateCoefficient{

        {

            { // degree 4
              +8.33333333333333287e-02,
              -5.46357009138465424e-03,
              +1.19638433962248889e-04 },
            { // degree 6
              +8.33333333333333287e-02,
              -5.55196372993948303e-03,
              +1.46646667516630680e-04,
              -1.82905866698780768e-06 },
            { // degree 8
              +8.33333333333333287e-02,
              -5.55546733314307706e-03,
              +1.48723933698110248e-04,
              -2.17865651989456709e-06,
              +1.77408035681006169e-08 },
            { // degree 10
              +8.33333333333333287e-02,
              -5.55555406357867952e-03,
              +1.48807404154064368e-04,
              -2.20360578135342372e-06,
              +2.06782449868995703e-08,
              -1.19178563894098852e-10 },
            { // degree 12
              +8.33333333333333287e-02,
              -5.55555555324832757e-03,
              +1.48809514798423797e-04,
              -2.20457622072950518e-06,
              +2.08728631685852690e-08,
              -1.36888190776165574e-10,
              +5.99292681875750821e-13 },
            { // degree 14
              +8.33333333333333287e-02,
              -5.55555555528319030e-03,
              +1.48809523101214977e-04,
              -2.20458493798151629e-06,
              +2.08765224186559757e-08,
              -1.37600800115177215e-10,
              +6.63762129016229865e-13,
              -2.19044013684859942e-15 },
            { // degree 16
              +8.33333333333333287e-02,
              -5.55555555501025672e-03,
              +1.48809521898935978e-04,
              -2.20458342827337994e-06,
              +2.08757075326674457e-08,
              -1.37379825035843510e-10,
              +6.32209097599974706e-13,
              +7.39204014316007136e-17,
              -6.43236558920699052e-17 }

        }
    };

    constexpr std::array rotation3EstimateMaxError{
        8.4612036888886e-05,  // degree 4
        1.8051973185995e-06,  // degree 6
        2.8016103950645e-08,  // degree 8
        3.2675391559156e-10,  // degree 10
        1.3714029911682e-13,  // degree 12
        3.2078506517763e-14,  // degree 14
        4.7774284528401e-14  // degree 16
    };

    /// 对于 [0,pi]中的t，估计 rotc0(t) = sin(t)/t 。例如，6阶的估计值是
    /// float t;  // in [0,pi]
    /// float result = RotC0Estimate<float, 6>(t);
    template <typename T, int Degree>
    requires((Degree & 1) == 0 && 4 <= Degree && Degree <= 16)
    NODISCARD T RotC0Estimate(T t);

    /// 估计rotc1(t) = (1 - cos(t))/t^2，t在 [0,pi]中。例如，6阶的估计值是
    /// float t;  // in [0,pi]
    /// float result = RotC1Estimate<float, 6>(t);
    template <typename T, int Degree>
    requires((Degree & 1) == 0 && 4 <= Degree && Degree <= 16)
    NODISCARD T RotC1Estimate(T t);

    /// 对于[0,pi]中的t，估计rotc2(t) = (sin(t) - t*cos(t))/t^3。例如，6阶的估计值是
    /// float t;  // in [0,pi]
    ///   float result = RotC2Estimate<float, 6>(t);
    template <typename T, int Degree>
    requires((Degree & 1) == 0 && 4 <= Degree && Degree <= 16)
    NODISCARD T RotC2Estimate(T t);

    /// 对于[0,pi]中的t，估计rotc3(t) = (2*(1-cos(t)) - t*sin(t))/t^4。例如，6阶的估计值是
    /// float t;  // in [0,pi]
    /// float result = RotC3Estimate<float, 6>(t);
    template <typename T, int Degree>
    requires((Degree & 1) == 0 && 4 <= Degree && Degree <= 16)
    NODISCARD T RotC3Estimate(T t);

    template <typename T, int Degree>
    requires((Degree & 1) == 0 && 4 <= Degree && Degree <= 16)
    NODISCARD constexpr T GetRotC0EstimateMaxError()
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return static_cast<T>(rotation0EstimateMaxError[(Degree - 4) / 2]);

#include SYSTEM_WARNING_POP
    }

    template <typename T, int Degree>
    requires((Degree & 1) == 0 && 4 <= Degree && Degree <= 16)
    NODISCARD constexpr T GetRotC1EstimateMaxError()
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return static_cast<T>(rotation1EstimateMaxError[(Degree - 4) / 2]);

#include SYSTEM_WARNING_POP
    }

    template <typename T, int Degree>
    requires((Degree & 1) == 0 && 4 <= Degree && Degree <= 16)
    NODISCARD constexpr T GetRotC2EstimateMaxError()
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return static_cast<T>(rotation2EstimateMaxError[(Degree - 4) / 2]);

#include SYSTEM_WARNING_POP
    }

    template <typename T, int Degree>
    requires((Degree & 1) == 0 && 4 <= Degree && Degree <= 16)
    NODISCARD constexpr T GetRotC3EstimateMaxError()
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return static_cast<T>(rotation3EstimateMaxError[(Degree - 4) / 2]);

#include SYSTEM_WARNING_POP
    }

    /// 构造旋转矩阵的估计
    /// rotation = exp(S) = I + rotc0(t) * S + rotc1(t) * S^2
    /// 从长度为t = |(p0,p1,p2)|的向量(p0,p1,p2)和斜对称矩阵 S = {{0,-p2,p1},{p2,0,-p0},{-p1,p0,0}}。
    template <typename T, int Degree>
    NODISCARD Matrix3<T> RotationEstimate(const Vector3<T>& point);

    template <typename T, int Degree>
    NODISCARD std::array<Matrix3<T>, 3> RotationDerivativeEstimate(const Vector3<T>& point);

    template <typename T, int Degree>
    void RotationAndDerivativeEstimate(const Vector3<T>& point, Matrix3<T>& rotation, std::array<Matrix3<T>, 3>& rotationDerivativeEstimateReal);

}

#endif  // MATHEMATICS_ESTIMATE_ROTATION_ESTIMATE_H
