// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/18 15:29)

#include "Rendering/RenderingExport.h"

#include "HalfFloat.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

using std::ostream;

Rendering::HalfFloat
    ::HalfFloat(float value)
	:m_HalfFloat{ ConvertHalfFloat(value) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::HalfFloat
	::HalfFloat(int value)
	:m_HalfFloat{ ConvertHalfFloat(boost::numeric_cast<float>(value)) }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

// static
Rendering::HalfFloat::HalfFloatType
    Rendering::HalfFloat
    ::ConvertHalfFloat(float value)
{
    auto bits = *reinterpret_cast<unsigned int*>(&value);
	auto biasExp = static_cast<unsigned short>((bits & 0x7F800000) >> 23);
    if (0x0071 <= biasExp)
    {
        if (biasExp <= 0x008E)
        {
            if (biasExp != 0)
            {
                // 截断23位小数到10位。 
				auto signBit = static_cast<unsigned short>((bits & 0x80000000) >> 16);
				auto mantissa = (bits & 0x007FFFFF) >> 13;
                biasExp = (biasExp - 0x0070) << 10;
                return static_cast<HalfFloatType>(signBit | biasExp | mantissa);
            }
            else
            {
                // E = 0 (替代编码为0,, M并不重要)
                return static_cast<HalfFloatType>(0);
            }
        }
        else
        {
            // E = 30, M = 1023 (半浮点数的最大量级)
			auto signBit = static_cast<unsigned short>((bits & 0x80000000) >> 16);
            return signBit | static_cast<unsigned short>(0x7BFF);
        }
    }
    else
    {
        // E = 1, M = 0 (半浮点数的最小量级)
		auto signBit = static_cast<unsigned short>((bits & 0x80000000) >> 16);
        return signBit | static_cast<unsigned short>(0x0400);
    }
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,HalfFloat)

void Rendering::HalfFloat
	::FromHalfFloatType( HalfFloatType value )
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	m_HalfFloat = value;
}

float Rendering::HalfFloat
    ::ToFloat () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
	auto biasExp  = static_cast<unsigned int>(m_HalfFloat & 0x7C00) >> 10;
    if (biasExp != 0)
    {
		auto signBit  = static_cast<unsigned int>(m_HalfFloat & 0x8000) << 16;
		auto mantissa = static_cast<unsigned int>(m_HalfFloat & 0x03FF) << 13;
        biasExp = (biasExp + 0x0070) << 23;
		auto result = signBit | biasExp | mantissa;
        return *reinterpret_cast<float*>(&result);
    }
    else
    {
        // E = 0 (替代编码为0,, M并不重要)
        return 0.0f;
    }
}

Rendering::HalfFloat::HalfFloatType Rendering::HalfFloat
    ::ToHalfFloat() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return m_HalfFloat;
}
 
const Rendering::HalfFloat Rendering::HalfFloat
    ::operator- () const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    float value = -ToFloat ();

	return HalfFloat{ value };
}

 
Rendering::HalfFloat& Rendering::HalfFloat
    ::operator+= (const HalfFloat& rhs)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

	auto value = ToFloat ();

    value += rhs.ToFloat ();

    m_HalfFloat = ConvertHalfFloat(value);

    return *this;
}

Rendering::HalfFloat& Rendering::HalfFloat
    ::operator-= (const HalfFloat& rhs)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

	auto value = ToFloat ();

    value -= rhs.ToFloat ();

    m_HalfFloat = ConvertHalfFloat(value);

    return *this;

}

Rendering::HalfFloat& Rendering::HalfFloat
    ::operator*= (const HalfFloat& rhs)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

	auto value = ToFloat ();

    value *= rhs.ToFloat ();

    m_HalfFloat = ConvertHalfFloat(value);

    return *this;
}

Rendering::HalfFloat& Rendering::HalfFloat
    ::operator/= (const HalfFloat& rhs)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (m_HalfFloat != 0)
    {
         float value = ToFloat ();

         value /= rhs.ToFloat ();

         m_HalfFloat = ConvertHalfFloat(value);
    }
    else
    {
         RENDERING_ASSERTION_1(false,"除零错误！");		 
        
         m_HalfFloat = 0;
    }

    return *this;
}

bool Rendering
    ::operator== (const HalfFloat& lhs,const HalfFloat& rhs)
{
    if(lhs.ToHalfFloat() == rhs.ToHalfFloat())
        return true;
    else
        return false;
}


bool Rendering
    ::operator< (const HalfFloat& lhs,const HalfFloat& rhs)
{
    if(lhs.ToFloat() < rhs.ToFloat())
        return true;
    else
        return false;
}

bool Rendering
    ::Approximate(const HalfFloat& lhs, const HalfFloat& rhs,const float epsilon)
{
    if(Mathematics::Mathf::Approximate(lhs.ToFloat(),rhs.ToFloat(), epsilon))
        return true;
    else
        return false;
}

ostream& Rendering
    ::operator<< (ostream& outFile,const HalfFloat& halfFloat)
{
    outFile << halfFloat.ToFloat();

    return outFile;
}

float Rendering
	::operator*( float lhs,const HalfFloat& rhs )
{
	return lhs * rhs.ToFloat();
}

float Rendering
	::operator*( const HalfFloat& lhs,float rhs )
{
	return lhs.ToFloat() * rhs;
}

float Rendering
	::operator/( float lhs,const HalfFloat& rhs )
{
	if (rhs.ToHalfFloat() != 0)
	{
		return lhs / rhs.ToFloat();
	}
	else
	{
		RENDERING_ASSERTION_1(false,"除零错误！");		 

		return Mathematics::Mathf::sm_MaxReal;
	}
}

template <>
Rendering::HalfFloat Mathematics::Math<Rendering::HalfFloat>
	::FAbs (Rendering::HalfFloat value) noexcept
{
	return Rendering::HalfFloat{ Mathf::FAbs(value.ToFloat()) };
}