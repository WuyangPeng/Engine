// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/17 14:04)

#ifndef RENDERING_DATA_TYPES_COLOUR_H
#define RENDERING_DATA_TYPES_COLOUR_H

#include "ColourDefaultTraits.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>
#include <ostream>
#include <array>

// 颜色类会将值截断为sm_MinValue <= 和 <= sm_MaxValue之间，
// 如果要求颜色类的平均值，需要将每个值乘以一个权重，
// 然后再进行加法运算。
namespace Rendering
{	
	template <typename T>
	class Colour : private boost::additive<Colour<T>,
		                   boost::multipliable<Colour<T>,						   
						   boost::equality_comparable<Colour<T> > > > 
	{
	public:	
		static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

		using ClassType = Colour<T>;

	public:
		constexpr Colour() noexcept
			:m_Colour{ sm_MinValue, sm_MinValue, sm_MinValue, sm_MaxValue }
		{
		}

		Colour(T red,T green,T blue,T alpha = sm_MaxValue);
		
		template <typename RhsType>
		Colour(const Colour<RhsType>& colour);

        template <typename RhsType>
        Colour& operator= (const Colour<RhsType>& colour);

		CLASS_INVARIANT_DECLARE;
		
		T GetRed() const noexcept;
		T GetGreen() const noexcept;
		T GetBlue() const noexcept;
		T GetAlpha() const noexcept;
		const T* GetPoint() const noexcept;

		void SetColour(T red,T green,T blue,T alpha = sm_MaxValue);
		void SetRed(T red);
		void SetGreen(T green);
		void SetBlue(T blue);
		void SetAlpha(T alpha);

		Colour& operator+= (const Colour& rhs);
		Colour& operator-= (const Colour& rhs);
		Colour& operator*= (const Colour& rhs);

		template <typename RhsType>
		Colour& operator*= (RhsType rhs);
		template <typename RhsType>
		Colour& operator/= (RhsType rhs);	

	private:
		static T Clamp(T colour) noexcept;

		template <typename RhsType>
		static T ConvertingIntegralToFloatingPoint(RhsType rhs);

		template <typename RhsType>
		static T ConvertingFloatingPointToIntegral(RhsType rhs);

		void InitColour(T red,T green,T blue,T alpha) noexcept;
		void Standardization();
		void StandardizationRed();
		void StandardizationGreen();
		void StandardizationBlue();
		void StandardizationAlpha();

		template <typename RhsType,bool TIsFloatingPoint,bool RhsIsFloatingPoint>
		void ConvertingColourFormat(const Colour<RhsType>& colour,const std::integral_constant<bool,TIsFloatingPoint>&,
									const std::integral_constant<bool,RhsIsFloatingPoint>&);

		template <typename RhsType>
		void ConvertingColourFormat(const Colour<RhsType>& colour,const std::true_type&,const std::false_type&);

		template <typename RhsType>
		void ConvertingColourFormat(const Colour<RhsType>& colour,const std::false_type&,const std::true_type&);
        
        template <typename RhsType,bool RhsIsFloatingPoint>
		void Divide(RhsType rhs,const std::integral_constant<bool,RhsIsFloatingPoint>&);
        
        template <typename RhsType>
		void Divide(RhsType rhs,const std::false_type&);
			
	private:
		enum ColourSerial
		{
			Red = 0,
            Green,
			Blue,
            Alpha,
			ColourSize
		};

		static constexpr auto sm_MinValue = static_cast<T>(ColourDefaultTraits<T>::sm_MinValue);
		static constexpr auto sm_MaxValue = static_cast<T>(ColourDefaultTraits<T>::sm_MaxValue);

		std::array<T, ColourSize> m_Colour;
	};

	template <typename T>
	bool Approximate(const Colour<T>& lhs,const Colour<T>& rhs,T epsilon) noexcept;

	template <typename T>
	bool operator== (const Colour<T>& lhs,const Colour<T>& rhs) noexcept;

	template <typename LhsType,typename RhsType>
	const Colour<LhsType> operator* (const Colour<LhsType>& lhs,RhsType rhs);
	template <typename LhsType,typename RhsType>
	const Colour<RhsType> operator* (LhsType lhs,const Colour<RhsType>& rhs);
	template <typename LhsType,typename RhsType>
	const Colour<LhsType> operator/ (const Colour<LhsType>& lhs,RhsType rhs);

	template <typename T>
	std::ostream& operator<< (std::ostream& os,const Colour<T>& colour);
}

#endif // RENDERING_DATA_TYPES_COLOUR_H
