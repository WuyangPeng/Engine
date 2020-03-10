// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/18 11:19)

#ifndef RENDERING_DATA_TYPES_HALF_FLOAT_H
#define RENDERING_DATA_TYPES_HALF_FLOAT_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Base/Math.h"

#include <boost/operators.hpp>

namespace Rendering
{ 
    // 一个16位浮点数有1位的符号位(S),5位的指数位(E),和10位的小数位(M)。
    // 16位浮点数的值是由以下几点:
    //    (-1)^S * 0.0,                        如果 E == 0 和 M == 0,
    //    (-1)^S * 2^-14 * (M / 2^10),         如果 E == 0 和 M != 0,
    //    (-1)^S * 2^(E-15) * (1 + M/2^10),    如果 0 < E < 31,
    //    (-1)^S * INF,                        如果 E == 31 和 M == 0, 或者
    //    NaN,                                 如果 E == 31 和 M != 0,
    // 这里
    //    S = floor((N mod 65536) / 32768),
    //    E = floor((N mod 32768) / 1024), 和
    //    M = N mod 1024. 
    // 实现也可以使用下列替代编码:
    //    (-1)^S * 0.0,                        如果 E == 0 和 M != 0,
    //    (-1)^S * 2^(E-15) * (1 + M/2^10),    如果 E == 31 和 M == 0, 或者
    //    (-1)^S * 2^(E-15) * (1 + M/2^10),    如果 E == 31 和 M != 0,
    //
    // 这个表说明了ToHalf和ToFloat的转换。 
    // ---------------------------
    // bias16  exp32  bias32
    // ---------------------------
    //     0    -127      0 (0x00)
    //     :       :      :
    //     0     -15    112 (0x70)
    // ---------------------------
    //     1     -14    113 (0x71)
    //     :       :      :
    //    15       0    127 (0x7F)
    //     :       :      :
    //    30      15    142 (0x8E)
    // ---------------------------
    //    31      16    143 (0x8F)
    //     :       :      :
    //    31     128    255 (0xFF)
    // ---------------------------
 
    class RENDERING_DEFAULT_DECLARE HalfFloat : private boost::arithmetic<HalfFloat,boost::totally_ordered<HalfFloat> >
    {
    public:
		using ClassType = HalfFloat;
        using HalfFloatType = uint16_t;
        
    public:
        explicit HalfFloat(float value = 0.0f);
		explicit HalfFloat(int value);
        
		CLASS_INVARIANT_DECLARE;

		void FromHalfFloatType(HalfFloatType value);
        
        float ToFloat () const;
        HalfFloatType ToHalfFloat() const;

		// 算术运算。
		const HalfFloat operator- () const; 

		// 算术更新。
		HalfFloat& operator+= (const HalfFloat& rhs);
		HalfFloat& operator-= (const HalfFloat& rhs);
		HalfFloat& operator*= (const HalfFloat& rhs);
		HalfFloat& operator/= (const HalfFloat& rhs);
        
    private:
        static HalfFloatType ConvertHalfFloat(float value);
        
    private:
        HalfFloatType m_HalfFloat;
    };

	// 比较 
	bool RENDERING_DEFAULT_DECLARE operator== (const HalfFloat& lhs,const HalfFloat& rhs);
	bool RENDERING_DEFAULT_DECLARE operator< (const HalfFloat& lhs,const HalfFloat& rhs);

	bool RENDERING_DEFAULT_DECLARE Approximate(const HalfFloat& lhs, const HalfFloat& rhs,const float epsilon = Mathematics::Mathf::sm_ZeroTolerance);

	// 调试输出。 
	RENDERING_DEFAULT_DECLARE std::ostream& operator<< (std::ostream& outFile, const HalfFloat& halfFloat);

	// 只添加必要的运算符
	float RENDERING_DEFAULT_DECLARE operator * (float lhs,const HalfFloat& rhs);
	float RENDERING_DEFAULT_DECLARE operator * (const HalfFloat& lhs,float rhs);
	float RENDERING_DEFAULT_DECLARE operator / (float lhs,const HalfFloat& rhs);
}

template <>
RENDERING_DEFAULT_DECLARE Rendering::HalfFloat Mathematics::Math<Rendering::HalfFloat>
	::FAbs (Rendering::HalfFloat value) noexcept;

#endif // RENDERING_DATA_TYPES_HALF_FLOAT_H
