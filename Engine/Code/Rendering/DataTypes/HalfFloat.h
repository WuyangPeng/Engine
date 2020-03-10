// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/18 11:19)

#ifndef RENDERING_DATA_TYPES_HALF_FLOAT_H
#define RENDERING_DATA_TYPES_HALF_FLOAT_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Base/Math.h"

#include <boost/operators.hpp>

namespace Rendering
{ 
    // һ��16λ��������1λ�ķ���λ(S),5λ��ָ��λ(E),��10λ��С��λ(M)��
    // 16λ��������ֵ�������¼���:
    //    (-1)^S * 0.0,                        ��� E == 0 �� M == 0,
    //    (-1)^S * 2^-14 * (M / 2^10),         ��� E == 0 �� M != 0,
    //    (-1)^S * 2^(E-15) * (1 + M/2^10),    ��� 0 < E < 31,
    //    (-1)^S * INF,                        ��� E == 31 �� M == 0, ����
    //    NaN,                                 ��� E == 31 �� M != 0,
    // ����
    //    S = floor((N mod 65536) / 32768),
    //    E = floor((N mod 32768) / 1024), ��
    //    M = N mod 1024. 
    // ʵ��Ҳ����ʹ�������������:
    //    (-1)^S * 0.0,                        ��� E == 0 �� M != 0,
    //    (-1)^S * 2^(E-15) * (1 + M/2^10),    ��� E == 31 �� M == 0, ����
    //    (-1)^S * 2^(E-15) * (1 + M/2^10),    ��� E == 31 �� M != 0,
    //
    // �����˵����ToHalf��ToFloat��ת���� 
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

		// �������㡣
		const HalfFloat operator- () const; 

		// �������¡�
		HalfFloat& operator+= (const HalfFloat& rhs);
		HalfFloat& operator-= (const HalfFloat& rhs);
		HalfFloat& operator*= (const HalfFloat& rhs);
		HalfFloat& operator/= (const HalfFloat& rhs);
        
    private:
        static HalfFloatType ConvertHalfFloat(float value);
        
    private:
        HalfFloatType m_HalfFloat;
    };

	// �Ƚ� 
	bool RENDERING_DEFAULT_DECLARE operator== (const HalfFloat& lhs,const HalfFloat& rhs);
	bool RENDERING_DEFAULT_DECLARE operator< (const HalfFloat& lhs,const HalfFloat& rhs);

	bool RENDERING_DEFAULT_DECLARE Approximate(const HalfFloat& lhs, const HalfFloat& rhs,const float epsilon = Mathematics::Mathf::sm_ZeroTolerance);

	// ��������� 
	RENDERING_DEFAULT_DECLARE std::ostream& operator<< (std::ostream& outFile, const HalfFloat& halfFloat);

	// ֻ��ӱ�Ҫ�������
	float RENDERING_DEFAULT_DECLARE operator * (float lhs,const HalfFloat& rhs);
	float RENDERING_DEFAULT_DECLARE operator * (const HalfFloat& lhs,float rhs);
	float RENDERING_DEFAULT_DECLARE operator / (float lhs,const HalfFloat& rhs);
}

template <>
RENDERING_DEFAULT_DECLARE Rendering::HalfFloat Mathematics::Math<Rendering::HalfFloat>
	::FAbs (Rendering::HalfFloat value) noexcept;

#endif // RENDERING_DATA_TYPES_HALF_FLOAT_H
