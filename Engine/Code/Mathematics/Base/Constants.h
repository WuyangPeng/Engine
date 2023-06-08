///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/30 15:46)

#ifndef MATHEMATICS_BASE_CONSTANTS_H
#define MATHEMATICS_BASE_CONSTANTS_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    constexpr auto maxBisectionsFloat16 = 27;
    constexpr auto maxBisectionsFloat32 = 155;
    constexpr auto maxBisectionsFloat64 = 1077;
    constexpr auto maxBisectionsBsNumber = 0xFFFFFFFFu;
    constexpr auto maxBisectionsBsRational = 0xFFFFFFFFu;
    constexpr auto maxBisectionsGeneric = 2048;

    template <typename T>
    constexpr T pi = static_cast<T>(3.1415926535897931);

    template <typename T>
    constexpr T halfPi = static_cast<T>(1.5707963267948966);

    template <typename T>
    constexpr T quarterPi = static_cast<T>(0.7853981633974483);

    template <typename T>
    constexpr T twoPi = static_cast<T>(6.2831853071795862);

    template <typename T>
    constexpr T invPi = static_cast<T>(0.3183098861837907);

    template <typename T>
    constexpr T invTwoPi = static_cast<T>(0.1591549430918953);

    template <typename T>
    constexpr T invHalfPi = static_cast<T>(0.6366197723675813);

    template <typename T>
    constexpr T degToRad = static_cast<T>(0.0174532925199433);

    template <typename T>
    constexpr T radToDeg = static_cast<T>(57.295779513082321);

    template <typename T>
    constexpr T sqrt2 = static_cast<T>(1.4142135623730951);

    template <typename T>
    constexpr T invSqrt2 = static_cast<T>(0.7071067811865475);

    template <typename T>
    constexpr T sqrt3 = static_cast<T>(1.7320508075688772);

    template <typename T>
    constexpr T invSqrt3 = static_cast<T>(0.57735026918962576);

    template <typename T>
    constexpr T ln2 = static_cast<T>(0.6931471805599453);

    template <typename T>
    constexpr T invLn2 = static_cast<T>(1.4426950408889634);

    template <typename T>
    constexpr T ln10 = static_cast<T>(2.3025850929940459);

    template <typename T>
    constexpr T invLn10 = static_cast<T>(0.43429448190325176);

    template <typename T>
    constexpr T sqrtDeg1C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T sqrtDeg1C1 = static_cast<T>(+4.1421356237309505e-01);

    template <typename T>
    constexpr T sqrtDeg1MaxError = static_cast<T>(1.7766952966368793e-2);

    template <typename T>
    constexpr T sqrtDeg2C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T sqrtDeg2C1 = static_cast<T>(+4.8563183076125260e-01);

    template <typename T>
    constexpr T sqrtDeg2C2 = static_cast<T>(-7.1418268388157458e-02);

    template <typename T>
    constexpr T sqrtDeg2MaxError = static_cast<T>(1.1795695163108744e-3);

    template <typename T>
    constexpr T sqrtDeg3C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T sqrtDeg3C1 = static_cast<T>(+4.9750045320242231e-01);

    template <typename T>
    constexpr T sqrtDeg3C2 = static_cast<T>(-1.0787308044477850e-01);

    template <typename T>
    constexpr T sqrtDeg3C3 = static_cast<T>(+2.4586189615451115e-02);

    template <typename T>
    constexpr T sqrtDeg3MaxError = static_cast<T>(1.1309620116468910e-4);

    template <typename T>
    constexpr T sqrtDeg4C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T sqrtDeg4C1 = static_cast<T>(+4.9955939832918816e-01);

    template <typename T>
    constexpr T sqrtDeg4C2 = static_cast<T>(-1.2024066151943025e-01);

    template <typename T>
    constexpr T sqrtDeg4C3 = static_cast<T>(+4.5461507257698486e-02);

    template <typename T>
    constexpr T sqrtDeg4C4 = static_cast<T>(-1.0566681694362146e-02);

    template <typename T>
    constexpr T sqrtDeg4MaxError = static_cast<T>(1.2741170151556180e-5);

    template <typename T>
    constexpr T sqrtDeg5C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T sqrtDeg5C1 = static_cast<T>(+4.9992197660031912e-01);

    template <typename T>
    constexpr T sqrtDeg5C2 = static_cast<T>(-1.2378506719245053e-01);

    template <typename T>
    constexpr T sqrtDeg5C3 = static_cast<T>(+5.6122776972699739e-02);

    template <typename T>
    constexpr T sqrtDeg5C4 = static_cast<T>(-2.3128836281145482e-02);

    template <typename T>
    constexpr T sqrtDeg5C5 = static_cast<T>(+5.0827122737047148e-03);

    template <typename T>
    constexpr T sqrtDeg5MaxError = static_cast<T>(1.5725568940708201e-6);

    template <typename T>
    constexpr T sqrtDeg6C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T sqrtDeg6C1 = static_cast<T>(+4.9998616695784914e-01);

    template <typename T>
    constexpr T sqrtDeg6C2 = static_cast<T>(-1.2470733323278438e-01);

    template <typename T>
    constexpr T sqrtDeg6C3 = static_cast<T>(+6.0388587356982271e-02);

    template <typename T>
    constexpr T sqrtDeg6C4 = static_cast<T>(-3.1692053551807930e-02);

    template <typename T>
    constexpr T sqrtDeg6C5 = static_cast<T>(+1.2856590305148075e-02);

    template <typename T>
    constexpr T sqrtDeg6C6 = static_cast<T>(-2.6183954624343642e-03);

    template <typename T>
    constexpr T sqrtDeg6MaxError = static_cast<T>(2.0584155535630089e-7);

    template <typename T>
    constexpr T sqrtDeg7C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T sqrtDeg7C1 = static_cast<T>(+4.9999754817809228e-01);

    template <typename T>
    constexpr T sqrtDeg7C2 = static_cast<T>(-1.2493243476353655e-01);

    template <typename T>
    constexpr T sqrtDeg7C3 = static_cast<T>(+6.1859954146370910e-02);

    template <typename T>
    constexpr T sqrtDeg7C4 = static_cast<T>(-3.6091595023208356e-02);

    template <typename T>
    constexpr T sqrtDeg7C5 = static_cast<T>(+1.9483946523450868e-02);

    template <typename T>
    constexpr T sqrtDeg7C6 = static_cast<T>(-7.5166134568007692e-03);

    template <typename T>
    constexpr T sqrtDeg7C7 = static_cast<T>(+1.4127567687864939e-03);

    template <typename T>
    constexpr T sqrtDeg7MaxError = static_cast<T>(2.8072302919734948e-8);

    template <typename T>
    constexpr T sqrtDeg8C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T sqrtDeg8C1 = static_cast<T>(+4.9999956583056759e-01);

    template <typename T>
    constexpr T sqrtDeg8C2 = static_cast<T>(-1.2498490369914350e-01);

    template <typename T>
    constexpr T sqrtDeg8C3 = static_cast<T>(+6.2318494667579216e-02);

    template <typename T>
    constexpr T sqrtDeg8C4 = static_cast<T>(-3.7982961896432244e-02);

    template <typename T>
    constexpr T sqrtDeg8C5 = static_cast<T>(+2.3642612312869460e-02);

    template <typename T>
    constexpr T sqrtDeg8C6 = static_cast<T>(-1.2529377587270574e-02);

    template <typename T>
    constexpr T sqrtDeg8C7 = static_cast<T>(+4.5382426960713929e-03);

    template <typename T>
    constexpr T sqrtDeg8C8 = static_cast<T>(-7.8810995273670414e-04);

    template <typename T>
    constexpr T sqrtDeg8MaxError = static_cast<T>(3.9460605685825989e-9);

    template <typename T>
    constexpr T invSqrtDeg1C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T invSqrtDeg1C1 = static_cast<T>(-2.9289321881345254e-01);

    template <typename T>
    constexpr T invSqrtDeg1MaxError = static_cast<T>(3.7814314552701983e-2);

    template <typename T>
    constexpr T invSqrtDeg2C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T invSqrtDeg2C1 = static_cast<T>(-4.4539812104566801e-01);

    template <typename T>
    constexpr T invSqrtDeg2C2 = static_cast<T>(+1.5250490223221547e-01);

    template <typename T>
    constexpr T invSqrtDeg2MaxError = static_cast<T>(4.1953446330581234e-3);

    template <typename T>
    constexpr T invSqrtDeg3C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T invSqrtDeg3C1 = static_cast<T>(-4.8703230993068791e-01);

    template <typename T>
    constexpr T invSqrtDeg3C2 = static_cast<T>(+2.8163710486669835e-01);

    template <typename T>
    constexpr T invSqrtDeg3C3 = static_cast<T>(-8.7498013749463421e-02);

    template <typename T>
    constexpr T invSqrtDeg3MaxError = static_cast<T>(5.6307702007266786e-4);

    template <typename T>
    constexpr T invSqrtDeg4C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T invSqrtDeg4C1 = static_cast<T>(-4.9710061558048779e-01);

    template <typename T>
    constexpr T invSqrtDeg4C2 = static_cast<T>(+3.4266247597676802e-01);

    template <typename T>
    constexpr T invSqrtDeg4C3 = static_cast<T>(-1.9106356536293490e-01);

    template <typename T>
    constexpr T invSqrtDeg4C4 = static_cast<T>(+5.2608486153198797e-02);

    template <typename T>
    constexpr T invSqrtDeg4MaxError = static_cast<T>(8.1513919987605266e-5);

    template <typename T>
    constexpr T invSqrtDeg5C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T invSqrtDeg5C1 = static_cast<T>(-4.9937760586004143e-01);

    template <typename T>
    constexpr T invSqrtDeg5C2 = static_cast<T>(+3.6508741295133973e-01);

    template <typename T>
    constexpr T invSqrtDeg5C3 = static_cast<T>(-2.5884890281853501e-01);

    template <typename T>
    constexpr T invSqrtDeg5C4 = static_cast<T>(+1.3275782221320753e-01);

    template <typename T>
    constexpr T invSqrtDeg5C5 = static_cast<T>(-3.2511945299404488e-02);

    template <typename T>
    constexpr T invSqrtDeg5MaxError = static_cast<T>(1.2289367475583346e-5);

    template <typename T>
    constexpr T invSqrtDeg6C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T invSqrtDeg6C1 = static_cast<T>(-4.9987029229547453e-01);

    template <typename T>
    constexpr T invSqrtDeg6C2 = static_cast<T>(+3.7220923604495226e-01);

    template <typename T>
    constexpr T invSqrtDeg6C3 = static_cast<T>(-2.9193067713256937e-01);

    template <typename T>
    constexpr T invSqrtDeg6C4 = static_cast<T>(+1.9937605991094642e-01);

    template <typename T>
    constexpr T invSqrtDeg6C5 = static_cast<T>(-9.3135712130901993e-02);

    template <typename T>
    constexpr T invSqrtDeg6C6 = static_cast<T>(+2.0458166789566690e-02);

    template <typename T>
    constexpr T invSqrtDeg6MaxError = static_cast<T>(1.9001451223750465e-6);

    template <typename T>
    constexpr T invSqrtDeg7C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T invSqrtDeg7C1 = static_cast<T>(-4.9997357250704977e-01);

    template <typename T>
    constexpr T invSqrtDeg7C2 = static_cast<T>(+3.7426216884998809e-01);

    template <typename T>
    constexpr T invSqrtDeg7C3 = static_cast<T>(-3.0539882498248971e-01);

    template <typename T>
    constexpr T invSqrtDeg7C4 = static_cast<T>(+2.3976005607005391e-01);

    template <typename T>
    constexpr T invSqrtDeg7C5 = static_cast<T>(-1.5410326351684489e-01);

    template <typename T>
    constexpr T invSqrtDeg7C6 = static_cast<T>(+6.5598809723041995e-02);

    template <typename T>
    constexpr T invSqrtDeg7C7 = static_cast<T>(-1.3038592450470787e-02);

    template <typename T>
    constexpr T invSqrtDeg7MaxError = static_cast<T>(2.9887724993168940e-7);

    template <typename T>
    constexpr T invSqrtDeg8C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T invSqrtDeg8C1 = static_cast<T>(-4.9999471066120371e-01);

    template <typename T>
    constexpr T invSqrtDeg8C2 = static_cast<T>(+3.7481415745794067e-01);

    template <typename T>
    constexpr T invSqrtDeg8C3 = static_cast<T>(-3.1023804387422160e-01);

    template <typename T>
    constexpr T invSqrtDeg8C4 = static_cast<T>(+2.5977002682930106e-01);

    template <typename T>
    constexpr T invSqrtDeg8C5 = static_cast<T>(-1.9818790717727097e-01);

    template <typename T>
    constexpr T invSqrtDeg8C6 = static_cast<T>(+1.1882414252613671e-01);

    template <typename T>
    constexpr T invSqrtDeg8C7 = static_cast<T>(-4.6270038088550791e-02);

    template <typename T>
    constexpr T invSqrtDeg8C8 = static_cast<T>(+8.3891541755747312e-03);

    template <typename T>
    constexpr T invSqrtDeg8MaxError = static_cast<T>(4.7596926146947771e-8);

    template <typename T>
    constexpr T sinDeg3C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T sinDeg3C1 = static_cast<T>(-1.4727245910375519e-01);

    template <typename T>
    constexpr T sinDeg3MaxError = static_cast<T>(1.3481903639145865e-2);

    template <typename T>
    constexpr T sinDeg5C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T sinDeg5C1 = static_cast<T>(-1.6600599923812209e-01);

    template <typename T>
    constexpr T sinDeg5C2 = static_cast<T>(+7.5924178409012000e-03);

    template <typename T>
    constexpr T sinDeg5MaxError = static_cast<T>(1.4001209384639779e-4);

    template <typename T>
    constexpr T sinDeg7C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T sinDeg7C1 = static_cast<T>(-1.6665578084732124e-01);

    template <typename T>
    constexpr T sinDeg7C2 = static_cast<T>(+8.3109378830028557e-03);

    template <typename T>
    constexpr T sinDeg7C3 = static_cast<T>(-1.8447486103462252e-04);

    template <typename T>
    constexpr T sinDeg7MaxError = static_cast<T>(1.0205878936686563e-6);

    template <typename T>
    constexpr T sinDeg9C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T sinDeg9C1 = static_cast<T>(-1.6666656235308897e-01);

    template <typename T>
    constexpr T sinDeg9C2 = static_cast<T>(+8.3329962509886002e-03);

    template <typename T>
    constexpr T sinDeg9C3 = static_cast<T>(-1.9805100675274190e-04);

    template <typename T>
    constexpr T sinDeg9C4 = static_cast<T>(+2.5967200279475300e-06);

    template <typename T>
    constexpr T sinDeg9MaxError = static_cast<T>(5.2010746265374053e-9);

    template <typename T>
    constexpr T sinDeg11C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T sinDeg11C1 = static_cast<T>(-1.6666666601721269e-01);

    template <typename T>
    constexpr T sinDeg11C2 = static_cast<T>(+8.3333303183525942e-03);

    template <typename T>
    constexpr T sinDeg11C3 = static_cast<T>(-1.9840782426250314e-04);

    template <typename T>
    constexpr T sinDeg11C4 = static_cast<T>(+2.7521557770526783e-06);

    template <typename T>
    constexpr T sinDeg11C5 = static_cast<T>(-2.3828544692960918e-08);

    template <typename T>
    constexpr T sinDeg11MaxError = static_cast<T>(1.9295870457014530e-11);

    template <typename T>
    constexpr T cosDeg2C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T cosDeg2C1 = static_cast<T>(-4.0528473456935105e-01);

    template <typename T>
    constexpr T cosDeg2MaxError = static_cast<T>(5.4870946878404048e-2);

    template <typename T>
    constexpr T cosDeg4C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T cosDeg4C1 = static_cast<T>(-4.9607181958647262e-01);

    template <typename T>
    constexpr T cosDeg4C2 = static_cast<T>(+3.6794619653489236e-02);

    template <typename T>
    constexpr T cosDeg4MaxError = static_cast<T>(9.1879932449712154e-4);

    template <typename T>
    constexpr T cosDeg6C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T cosDeg6C1 = static_cast<T>(-4.9992746217057404e-01);

    template <typename T>
    constexpr T cosDeg6C2 = static_cast<T>(+4.1493920348353308e-02);

    template <typename T>
    constexpr T cosDeg6C3 = static_cast<T>(-1.2712435011987822e-03);

    template <typename T>
    constexpr T cosDeg6MaxError = static_cast<T>(9.2028470133065365e-6);

    template <typename T>
    constexpr T cosDeg8C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T cosDeg8C1 = static_cast<T>(-4.9999925121358291e-01);

    template <typename T>
    constexpr T cosDeg8C2 = static_cast<T>(+4.1663780117805693e-02);

    template <typename T>
    constexpr T cosDeg8C3 = static_cast<T>(-1.3854239405310942e-03);

    template <typename T>
    constexpr T cosDeg8C4 = static_cast<T>(+2.3154171575501259e-05);

    template <typename T>
    constexpr T cosDeg8MaxError = static_cast<T>(5.9804533020235695e-8);

    template <typename T>
    constexpr T cosDeg10C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T cosDeg10C1 = static_cast<T>(-4.9999999508695869e-01);

    template <typename T>
    constexpr T cosDeg10C2 = static_cast<T>(+4.1666638865338612e-02);

    template <typename T>
    constexpr T cosDeg10C3 = static_cast<T>(-1.3888377661039897e-03);

    template <typename T>
    constexpr T cosDeg10C4 = static_cast<T>(+2.4760495088926859e-05);

    template <typename T>
    constexpr T cosDeg10C5 = static_cast<T>(-2.6051615464872668e-07);

    template <typename T>
    constexpr T cosDeg10MaxError = static_cast<T>(2.7006769043325107e-10);

    template <typename T>
    constexpr T tanDeg3C0 = static_cast<T>(1.0);

    template <typename T>
    constexpr T tanDeg3C1 = static_cast<T>(4.4295926544736286e-01);

    template <typename T>
    constexpr T tanDeg3MaxError = static_cast<T>(1.1661892256204731e-2);

    template <typename T>
    constexpr T tanDeg5C0 = static_cast<T>(1.0);

    template <typename T>
    constexpr T tanDeg5C1 = static_cast<T>(3.1401320403542421e-01);

    template <typename T>
    constexpr T tanDeg5C2 = static_cast<T>(2.0903948109240345e-01);

    template <typename T>
    constexpr T tanDeg5MaxError = static_cast<T>(5.8431854390143118e-4);

    template <typename T>
    constexpr T tanDeg7C0 = static_cast<T>(1.0);

    template <typename T>
    constexpr T tanDeg7C1 = static_cast<T>(3.3607213284422555e-01);

    template <typename T>
    constexpr T tanDeg7C2 = static_cast<T>(1.1261037305184907e-01);

    template <typename T>
    constexpr T tanDeg7C3 = static_cast<T>(9.8352099470524479e-02);

    template <typename T>
    constexpr T tanDeg7MaxError = static_cast<T>(3.5418688397723108e-5);

    template <typename T>
    constexpr T tanDeg9C0 = static_cast<T>(1.0);

    template <typename T>
    constexpr T tanDeg9C1 = static_cast<T>(3.3299232843941784e-01);

    template <typename T>
    constexpr T tanDeg9C2 = static_cast<T>(1.3747843432474838e-01);

    template <typename T>
    constexpr T tanDeg9C3 = static_cast<T>(3.7696344813028304e-02);

    template <typename T>
    constexpr T tanDeg9C4 = static_cast<T>(4.6097377279281204e-02);

    template <typename T>
    constexpr T tanDeg9MaxError = static_cast<T>(2.2988173242199927e-6);

    template <typename T>
    constexpr T tanDeg11C0 = static_cast<T>(1.0);

    template <typename T>
    constexpr T tanDeg11C1 = static_cast<T>(3.3337224456224224e-01);

    template <typename T>
    constexpr T tanDeg11C2 = static_cast<T>(1.3264516053824593e-01);

    template <typename T>
    constexpr T tanDeg11C3 = static_cast<T>(5.8145237645931047e-02);

    template <typename T>
    constexpr T tanDeg11C4 = static_cast<T>(1.0732193237572574e-02);

    template <typename T>
    constexpr T tanDeg11C5 = static_cast<T>(2.1558456793513869e-02);

    template <typename T>
    constexpr T tanDeg11MaxError = static_cast<T>(1.5426257940140409e-7);

    template <typename T>
    constexpr T tanDeg13C0 = static_cast<T>(1.0);

    template <typename T>
    constexpr T tanDeg13C1 = static_cast<T>(3.3332916426394554e-01);

    template <typename T>
    constexpr T tanDeg13C2 = static_cast<T>(1.3343404625112498e-01);

    template <typename T>
    constexpr T tanDeg13C3 = static_cast<T>(5.3104565343119248e-02);

    template <typename T>
    constexpr T tanDeg13C4 = static_cast<T>(2.5355038312682154e-02);

    template <typename T>
    constexpr T tanDeg13C5 = static_cast<T>(1.8253255966556026e-03);

    template <typename T>
    constexpr T tanDeg13C6 = static_cast<T>(1.0069407176615641e-02);

    template <typename T>
    constexpr T tanDeg13MaxError = static_cast<T>(1.0550264249037378e-8);

    template <typename T>
    constexpr T acosDeg1C0 = static_cast<T>(+1.5707963267948966);

    template <typename T>
    constexpr T acosDeg1C1 = static_cast<T>(-1.5658276442180141e-01);

    template <typename T>
    constexpr T acosDeg1MaxError = static_cast<T>(1.1659002803738105e-2);

    template <typename T>
    constexpr T acosDeg2C0 = static_cast<T>(+1.5707963267948966);

    template <typename T>
    constexpr T acosDeg2C1 = static_cast<T>(-2.0347053865798365e-01);

    template <typename T>
    constexpr T acosDeg2C2 = static_cast<T>(+4.6887774236182234e-02);

    template <typename T>
    constexpr T acosDeg2MaxError = static_cast<T>(9.0311602490029258e-4);

    template <typename T>
    constexpr T acosDeg3C0 = static_cast<T>(+1.5707963267948966);

    template <typename T>
    constexpr T acosDeg3C1 = static_cast<T>(-2.1253291899190285e-01);

    template <typename T>
    constexpr T acosDeg3C2 = static_cast<T>(+7.4773789639484223e-02);

    template <typename T>
    constexpr T acosDeg3C3 = static_cast<T>(-1.8823635069382449e-02);

    template <typename T>
    constexpr T acosDeg3MaxError = static_cast<T>(9.3066396954288172e-5);

    template <typename T>
    constexpr T acosDeg4C0 = static_cast<T>(+1.5707963267948966);

    template <typename T>
    constexpr T acosDeg4C1 = static_cast<T>(-2.1422258835275865e-01);

    template <typename T>
    constexpr T acosDeg4C2 = static_cast<T>(+8.4936675142844198e-02);

    template <typename T>
    constexpr T acosDeg4C3 = static_cast<T>(-3.5991475120957794e-02);

    template <typename T>
    constexpr T acosDeg4C4 = static_cast<T>(+8.6946239090712751e-03);

    template <typename T>
    constexpr T acosDeg4MaxError = static_cast<T>(1.0930595804481413e-5);

    template <typename T>
    constexpr T acosDeg5C0 = static_cast<T>(+1.5707963267948966);

    template <typename T>
    constexpr T acosDeg5C1 = static_cast<T>(-2.1453292139805524e-01);

    template <typename T>
    constexpr T acosDeg5C2 = static_cast<T>(+8.7973089282889383e-02);

    template <typename T>
    constexpr T acosDeg5C3 = static_cast<T>(-4.5130266382166440e-02);

    template <typename T>
    constexpr T acosDeg5C4 = static_cast<T>(+1.9467466687281387e-02);

    template <typename T>
    constexpr T acosDeg5C5 = static_cast<T>(-4.3601326117634898e-03);

    template <typename T>
    constexpr T acosDeg5MaxError = static_cast<T>(1.3861070257241426e-6);

    template <typename T>
    constexpr T acosDeg6C0 = static_cast<T>(+1.5707963267948966);

    template <typename T>
    constexpr T acosDeg6C1 = static_cast<T>(-2.1458939285677325e-01);

    template <typename T>
    constexpr T acosDeg6C2 = static_cast<T>(+8.8784960563641491e-02);

    template <typename T>
    constexpr T acosDeg6C3 = static_cast<T>(-4.8887131453156485e-02);

    template <typename T>
    constexpr T acosDeg6C4 = static_cast<T>(+2.7011519960012720e-02);

    template <typename T>
    constexpr T acosDeg6C5 = static_cast<T>(-1.1210537323478320e-02);

    template <typename T>
    constexpr T acosDeg6C6 = static_cast<T>(+2.3078166879102469e-03);

    template <typename T>
    constexpr T acosDeg6MaxError = static_cast<T>(1.8491291330427484e-7);

    template <typename T>
    constexpr T acosDeg7C0 = static_cast<T>(+1.5707963267948966);

    template <typename T>
    constexpr T acosDeg7C1 = static_cast<T>(-2.1459960076929829e-01);

    template <typename T>
    constexpr T acosDeg7C2 = static_cast<T>(+8.8986946573346160e-02);

    template <typename T>
    constexpr T acosDeg7C3 = static_cast<T>(-5.0207843052845647e-02);

    template <typename T>
    constexpr T acosDeg7C4 = static_cast<T>(+3.0961594977611639e-02);

    template <typename T>
    constexpr T acosDeg7C5 = static_cast<T>(-1.7162031184398074e-02);

    template <typename T>
    constexpr T acosDeg7C6 = static_cast<T>(+6.7072304676685235e-03);

    template <typename T>
    constexpr T acosDeg7C7 = static_cast<T>(-1.2690614339589956e-03);

    template <typename T>
    constexpr T acosDeg7MaxError = static_cast<T>(2.5574620927948377e-8);

    template <typename T>
    constexpr T acosDeg8C0 = static_cast<T>(+1.5707963267948966);

    template <typename T>
    constexpr T acosDeg8C1 = static_cast<T>(-2.1460143648688035e-01);

    template <typename T>
    constexpr T acosDeg8C2 = static_cast<T>(+8.9034700107934128e-02);

    template <typename T>
    constexpr T acosDeg8C3 = static_cast<T>(-5.0625279962389413e-02);

    template <typename T>
    constexpr T acosDeg8C4 = static_cast<T>(+3.2683762943179318e-02);

    template <typename T>
    constexpr T acosDeg8C5 = static_cast<T>(-2.0949278766238422e-02);

    template <typename T>
    constexpr T acosDeg8C6 = static_cast<T>(+1.1272900916992512e-02);

    template <typename T>
    constexpr T acosDeg8C7 = static_cast<T>(-4.1160981058965262e-03);

    template <typename T>
    constexpr T acosDeg8C8 = static_cast<T>(+7.1796493341480527e-04);

    template <typename T>
    constexpr T acosDeg8MaxError = static_cast<T>(3.6340015129032732e-9);

    template <typename T>
    constexpr T atanDeg3C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T atanDeg3C1 = static_cast<T>(-2.1460183660255172e-01);

    template <typename T>
    constexpr T atanDeg3MaxError = static_cast<T>(1.5970326392614240e-2);

    template <typename T>
    constexpr T atanDeg5C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T atanDeg5C1 = static_cast<T>(-3.0189478312144946e-01);

    template <typename T>
    constexpr T atanDeg5C2 = static_cast<T>(+8.7292946518897740e-02);

    template <typename T>
    constexpr T atanDeg5MaxError = static_cast<T>(1.3509832247372636e-3);

    template <typename T>
    constexpr T atanDeg7C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T atanDeg7C1 = static_cast<T>(-3.2570157599356531e-01);

    template <typename T>
    constexpr T atanDeg7C2 = static_cast<T>(+1.5342994884206673e-01);

    template <typename T>
    constexpr T atanDeg7C3 = static_cast<T>(-4.2330209451053591e-02);

    template <typename T>
    constexpr T atanDeg7MaxError = static_cast<T>(1.5051227215514412e-4);

    template <typename T>
    constexpr T atanDeg9C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T atanDeg9C1 = static_cast<T>(-3.3157878236439586e-01);

    template <typename T>
    constexpr T atanDeg9C2 = static_cast<T>(+1.8383034738018011e-01);

    template <typename T>
    constexpr T atanDeg9C3 = static_cast<T>(-8.9253037587244677e-02);

    template <typename T>
    constexpr T atanDeg9C4 = static_cast<T>(+2.2399635968909593e-02);

    template <typename T>
    constexpr T atanDeg9MaxError = static_cast<T>(1.8921598624582064e-5);

    template <typename T>
    constexpr T atanDeg11C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T atanDeg11C1 = static_cast<T>(-3.3294527685374087e-01);

    template <typename T>
    constexpr T atanDeg11C2 = static_cast<T>(+1.9498657165383548e-01);

    template <typename T>
    constexpr T atanDeg11C3 = static_cast<T>(-1.1921576270475498e-01);

    template <typename T>
    constexpr T atanDeg11C4 = static_cast<T>(+5.5063351366968050e-02);

    template <typename T>
    constexpr T atanDeg11C5 = static_cast<T>(-1.2490720064867844e-02);

    template <typename T>
    constexpr T atanDeg11MaxError = static_cast<T>(2.5477724974187765e-6);

    template <typename T>
    constexpr T atanDeg13C0 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T atanDeg13C1 = static_cast<T>(-3.3324998579202170e-01);

    template <typename T>
    constexpr T atanDeg13C2 = static_cast<T>(+1.9856563505717162e-01);

    template <typename T>
    constexpr T atanDeg13C3 = static_cast<T>(-1.3374657325451267e-01);

    template <typename T>
    constexpr T atanDeg13C4 = static_cast<T>(+8.1675882859940430e-02);

    template <typename T>
    constexpr T atanDeg13C5 = static_cast<T>(-3.5059680836411644e-02);

    template <typename T>
    constexpr T atanDeg13C6 = static_cast<T>(+7.2128853633444123e-03);

    template <typename T>
    constexpr T atanDeg13MaxError = static_cast<T>(3.5859104691865484e-7);

    template <typename T>
    constexpr T exp2Deg1C0 = static_cast<T>(1.0);

    template <typename T>
    constexpr T exp2Deg1C1 = static_cast<T>(1.0);

    template <typename T>
    constexpr T exp2Deg1MaxError = static_cast<T>(8.6071332055934313e-2);

    template <typename T>
    constexpr T exp2Deg2C0 = static_cast<T>(1.0);

    template <typename T>
    constexpr T exp2Deg2C1 = static_cast<T>(6.5571332605741528e-01);

    template <typename T>
    constexpr T exp2Deg2C2 = static_cast<T>(3.4428667394258472e-01);

    template <typename T>
    constexpr T exp2Deg2MaxError = static_cast<T>(3.8132476831060358e-3);

    template <typename T>
    constexpr T exp2Deg3C0 = static_cast<T>(1.0);

    template <typename T>
    constexpr T exp2Deg3C1 = static_cast<T>(6.9589012084456225e-01);

    template <typename T>
    constexpr T exp2Deg3C2 = static_cast<T>(2.2486494900110188e-01);

    template <typename T>
    constexpr T exp2Deg3C3 = static_cast<T>(7.9244930154334980e-02);

    template <typename T>
    constexpr T exp2Deg3MaxError = static_cast<T>(1.4694877755186408e-4);

    template <typename T>
    constexpr T exp2Deg4C0 = static_cast<T>(1.0);

    template <typename T>
    constexpr T exp2Deg4C1 = static_cast<T>(6.9300392358459195e-01);

    template <typename T>
    constexpr T exp2Deg4C2 = static_cast<T>(2.4154981722455560e-01);

    template <typename T>
    constexpr T exp2Deg4C3 = static_cast<T>(5.1744260331489045e-02);

    template <typename T>
    constexpr T exp2Deg4C4 = static_cast<T>(1.3701998859367848e-02);

    template <typename T>
    constexpr T exp2Deg4MaxError = static_cast<T>(4.7617792624521371e-6);

    template <typename T>
    constexpr T exp2Deg5C0 = static_cast<T>(1.0);

    template <typename T>
    constexpr T exp2Deg5C1 = static_cast<T>(6.9315298010274962e-01);

    template <typename T>
    constexpr T exp2Deg5C2 = static_cast<T>(2.4014712313022102e-01);

    template <typename T>
    constexpr T exp2Deg5C3 = static_cast<T>(5.5855296413199085e-02);

    template <typename T>
    constexpr T exp2Deg5C4 = static_cast<T>(8.9477503096873079e-03);

    template <typename T>
    constexpr T exp2Deg5C5 = static_cast<T>(1.8968500441332026e-03);

    template <typename T>
    constexpr T exp2Deg5MaxError = static_cast<T>(1.3162098333463490e-7);

    template <typename T>
    constexpr T exp2Deg6C0 = static_cast<T>(1.0);

    template <typename T>
    constexpr T exp2Deg6C1 = static_cast<T>(6.9314698914837525e-01);

    template <typename T>
    constexpr T exp2Deg6C2 = static_cast<T>(2.4023013440952923e-01);

    template <typename T>
    constexpr T exp2Deg6C3 = static_cast<T>(5.5481276898206033e-02);

    template <typename T>
    constexpr T exp2Deg6C4 = static_cast<T>(9.6838443037086108e-03);

    template <typename T>
    constexpr T exp2Deg6C5 = static_cast<T>(1.2388324048515642e-03);

    template <typename T>
    constexpr T exp2Deg6C6 = static_cast<T>(2.1892283501756538e-04);

    template <typename T>
    constexpr T exp2Deg6MaxError = static_cast<T>(3.1589168225654163e-9);

    template <typename T>
    constexpr T exp2Deg7C0 = static_cast<T>(1.0);

    template <typename T>
    constexpr T exp2Deg7C1 = static_cast<T>(6.9314718588750690e-01);

    template <typename T>
    constexpr T exp2Deg7C2 = static_cast<T>(2.4022637363165700e-01);

    template <typename T>
    constexpr T exp2Deg7C3 = static_cast<T>(5.5505235570535660e-02);

    template <typename T>
    constexpr T exp2Deg7C4 = static_cast<T>(9.6136265387940512e-03);

    template <typename T>
    constexpr T exp2Deg7C5 = static_cast<T>(1.3429234504656051e-03);

    template <typename T>
    constexpr T exp2Deg7C6 = static_cast<T>(1.4299202757683815e-04);

    template <typename T>
    constexpr T exp2Deg7C7 = static_cast<T>(2.1662892777385423e-05);

    template <typename T>
    constexpr T exp2Deg7MaxError = static_cast<T>(6.6864513925679603e-11);

    template <typename T>
    constexpr T log2Deg1C1 = static_cast<T>(+1.0);

    template <typename T>
    constexpr T log2Deg1MaxError = static_cast<T>(8.6071332055934202e-2);

    template <typename T>
    constexpr T log2Deg2C1 = static_cast<T>(+1.3465553856377803);

    template <typename T>
    constexpr T log2Deg2C2 = static_cast<T>(-3.4655538563778032e-01);

    template <typename T>
    constexpr T log2Deg2MaxError = static_cast<T>(7.6362868906658110e-3);

    template <typename T>
    constexpr T log2Deg3C1 = static_cast<T>(+1.4228653756681227);

    template <typename T>
    constexpr T log2Deg3C2 = static_cast<T>(-5.8208556916449616e-01);

    template <typename T>
    constexpr T log2Deg3C3 = static_cast<T>(+1.5922019349637218e-01);

    template <typename T>
    constexpr T log2Deg3MaxError = static_cast<T>(8.7902902652883808e-4);

    template <typename T>
    constexpr T log2Deg4C1 = static_cast<T>(+1.4387257478171547);

    template <typename T>
    constexpr T log2Deg4C2 = static_cast<T>(-6.7778401359918661e-01);

    template <typename T>
    constexpr T log2Deg4C3 = static_cast<T>(+3.2118898377713379e-01);

    template <typename T>
    constexpr T log2Deg4C4 = static_cast<T>(-8.2130717995088531e-02);

    template <typename T>
    constexpr T log2Deg4MaxError = static_cast<T>(1.1318551355360418e-4);

    template <typename T>
    constexpr T log2Deg5C1 = static_cast<T>(+1.4419170408633741);

    template <typename T>
    constexpr T log2Deg5C2 = static_cast<T>(-7.0909645927612530e-01);

    template <typename T>
    constexpr T log2Deg5C3 = static_cast<T>(+4.1560609399164150e-01);

    template <typename T>
    constexpr T log2Deg5C4 = static_cast<T>(-1.9357573729558908e-01);

    template <typename T>
    constexpr T log2Deg5C5 = static_cast<T>(+4.5149061716699634e-02);

    template <typename T>
    constexpr T log2Deg5MaxError = static_cast<T>(1.5521274478735858e-5);

    template <typename T>
    constexpr T log2Deg6C1 = static_cast<T>(+1.4425449435950917);

    template <typename T>
    constexpr T log2Deg6C2 = static_cast<T>(-7.1814525675038965e-01);

    template <typename T>
    constexpr T log2Deg6C3 = static_cast<T>(+4.5754919692564044e-01);

    template <typename T>
    constexpr T log2Deg6C4 = static_cast<T>(-2.7790534462849337e-01);

    template <typename T>
    constexpr T log2Deg6C5 = static_cast<T>(+1.2179791068763279e-01);

    template <typename T>
    constexpr T log2Deg6C6 = static_cast<T>(-2.5841449829670182e-02);

    template <typename T>
    constexpr T log2Deg6MaxError = static_cast<T>(2.2162051216689793e-6);

    template <typename T>
    constexpr T log2Deg7C1 = static_cast<T>(+1.4426664401536078);

    template <typename T>
    constexpr T log2Deg7C2 = static_cast<T>(-7.2055423726162360e-01);

    template <typename T>
    constexpr T log2Deg7C3 = static_cast<T>(+4.7332419162501083e-01);

    template <typename T>
    constexpr T log2Deg7C4 = static_cast<T>(-3.2514018752954144e-01);

    template <typename T>
    constexpr T log2Deg7C5 = static_cast<T>(+1.9302965529095673e-01);

    template <typename T>
    constexpr T log2Deg7C6 = static_cast<T>(-7.8534970641157997e-02);

    template <typename T>
    constexpr T log2Deg7C7 = static_cast<T>(+1.5209108363023915e-02);

    template <typename T>
    constexpr T log2Deg7MaxError = static_cast<T>(3.2546531700261561e-7);

    template <typename T>
    constexpr T log2Deg8C1 = static_cast<T>(+1.4426896453621882);

    template <typename T>
    constexpr T log2Deg8C2 = static_cast<T>(-7.2115893912535967e-01);

    template <typename T>
    constexpr T log2Deg8C3 = static_cast<T>(+4.7861716616785088e-01);

    template <typename T>
    constexpr T log2Deg8C4 = static_cast<T>(-3.4699935395019565e-01);

    template <typename T>
    constexpr T log2Deg8C5 = static_cast<T>(+2.4114048765477492e-01);

    template <typename T>
    constexpr T log2Deg8C6 = static_cast<T>(-1.3657398692885181e-01);

    template <typename T>
    constexpr T log2Deg8C7 = static_cast<T>(+5.1421382871922106e-02);

    template <typename T>
    constexpr T log2Deg8C8 = static_cast<T>(-9.1364020499895560e-03);

    template <typename T>
    constexpr T log2Deg8MaxError = static_cast<T>(4.8796219218050219e-8);
}

#endif  // MATHEMATICS_BASE_CONSTANTS_H
