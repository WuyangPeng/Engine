// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/17 18:41)

#ifndef RENDERING_DATA_TYPES_TEXTURE_COLOUR_H
#define RENDERING_DATA_TYPES_TEXTURE_COLOUR_H

#include "ColourTextureFormatTraits.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits> 
#include <array>

// 颜色类会将值截断为sm_MinValue <= 和 <= sm_MaxValue之间，
// 如果要求颜色类的平均值，需要将每个值乘以一个权重，然后再进行加法运算。
namespace Rendering
{	
	template <TextureFormat Format>
	class TextureColour : private boost::additive<TextureColour <Format>,
		                          boost::multipliable<TextureColour <Format>,						   
						          boost::equality_comparable<TextureColour <Format> > > > 
	{
	public:	
		using ClassType = TextureColour<Format>;
		using BitType = typename ColourTextureFormatTraits<Format>::BitType;
		
	public:
		TextureColour();				
		TextureColour(BitType red, BitType green, BitType blue, BitType alpha);

		// 如果存在alpha，则设为最大值
		TextureColour(BitType red, BitType green, BitType blue);

		explicit TextureColour(BitType value); 
		TextureColour(BitType firstValue, BitType secondValue);	 

		// 只有当成员是一致时（alpha成员除外），才允许转换
		template <TextureFormat RhsFormat>
		TextureColour(const TextureColour<RhsFormat>& colour);

        template <TextureFormat RhsFormat>
        TextureColour& operator= (const TextureColour<RhsFormat>& colour);

		CLASS_INVARIANT_DECLARE;
		
		BitType GetRed() const;
		BitType GetGreen() const;
		BitType GetBlue() const;
		BitType GetAlpha() const;
		BitType GetLuminance() const;
		const BitType* GetPoint() const;
		BitType operator[](int index) const;

		void SetColour(BitType red, BitType green, BitType blue, BitType alpha) noexcept;

		// 如果存在alpha，则设为最大值。
                void SetColour(BitType red, BitType green, BitType blue) noexcept;

		void SetColour(BitType value) noexcept;
                void SetColour(BitType firstValue, BitType secondValue) noexcept;

		void SetRed(BitType red);
		void SetGreen (BitType green);
		void SetBlue(BitType blue);
		void SetAlpha(BitType alpha);
		void SetLuminance(BitType luminance);

		TextureColour& operator+= (const TextureColour& rhs);
		TextureColour& operator-= (const TextureColour& rhs);
		TextureColour& operator*= (const TextureColour& rhs);

		template <typename RhsType>
		TextureColour& operator*= (RhsType rhs);
		template <typename RhsType>
		TextureColour& operator/= (RhsType rhs);	

	private:
		static BitType Clamp(BitType colour, BitType maxValue) noexcept;

		void Standardization() noexcept;

		template <int Index>
		void Standardization(const std::false_type&,BitType maxValue) noexcept;
		template <int Index>
		void Standardization(const std::true_type&,BitType maxValue) noexcept;

		template <TextureFormat RhsFormat>
		void ConvertingColourFormat(const TextureColour<RhsFormat>& colour);

		template <TextureFormat RhsFormat,int Index,int RhsIndex,
			      bool IsFloatingPoint, bool RhsIsFloatingPoint>
		void ConvertingBit(const TextureColour<RhsFormat>& colour,BitType maxValue,
						   typename TextureColour<RhsFormat>::BitType rhsMinValue,
		                   typename TextureColour<RhsFormat>::BitType rhsMaxValue,
						   const std::integral_constant<bool,IsFloatingPoint>&,
						   const std::integral_constant<bool,RhsIsFloatingPoint>&);

		template <TextureFormat RhsFormat,int Index,int RhsIndex>
		void ConvertingBit(const TextureColour<RhsFormat>& colour,BitType maxValue,
						   typename TextureColour<RhsFormat>::BitType rhsMinValue,
						   typename TextureColour<RhsFormat>::BitType rhsMaxValue,
						   const std::false_type&,const std::true_type&);

		template <TextureFormat RhsFormat,int Index,int RhsIndex,bool HaveBit>
		void Converting(const TextureColour<RhsFormat>& colour,BitType maxValue, 
						typename TextureColour<RhsFormat>::BitType rhsMaxValue,
		                const std::integral_constant<bool,HaveBit>&);

		template <TextureFormat RhsFormat,int Index,int RhsIndex>
		void Converting(const TextureColour<RhsFormat>& colour,BitType maxValue,  
						typename TextureColour<RhsFormat>::BitType rhsMaxValue,
			            const std::false_type&);

		template <TextureFormat RhsFormat, bool HaveAlpha,bool RhsHaveAlpha>
		void ConvertingAlpha(const TextureColour<RhsFormat>& colour,
		                     const std::integral_constant<bool, HaveAlpha>&,
				             const std::integral_constant<bool, RhsHaveAlpha>&);

		template <TextureFormat RhsFormat>
		void ConvertingAlpha(const TextureColour<RhsFormat>& colour,const std::true_type&,const std::true_type&);

		template <TextureFormat RhsFormat>
		void ConvertingAlpha(const TextureColour<RhsFormat>& colour,const std::true_type&,const std::false_type&);

		template <int Index,bool HaveBit>
		void Multiply(const std::integral_constant<bool,HaveBit>&, BitType maxValue,const TextureColour& colour);
		template <int Index>
		void Multiply(const std::false_type&, BitType maxValue,const TextureColour& colour);		 
        
        template <typename RhsType, bool RhsIsFloatingPoint>
		void Divide(RhsType rhs,const std::integral_constant<bool,RhsIsFloatingPoint>&);
        
        template <typename RhsType>
		void Divide(RhsType rhs,const std::false_type&);

	private:
		static const BitType sm_MinValue; 
		static const BitType sm_RedMaxValue;
		static const BitType sm_GreenMaxValue;
		static const BitType sm_BlueMaxValue;
		static const BitType sm_AlphaMaxValue;
		static const BitType sm_LuminanceMaxValue;
		
		static constexpr auto sm_IsFloatingPoint = ColourTextureFormatTraits<Format>::sm_IsFloatingPoint;
		static constexpr auto sm_ArraySize = ColourTextureFormatTraits<Format>::sm_ArraySize;
			
	private:
		std::array<BitType, sm_ArraySize> m_Colour;
	};

	template <TextureFormat Format>
	bool Approximate(const TextureColour<Format>& lhs,const TextureColour<Format>& rhs,typename TextureColour<Format>::BitType epsilon);	

	template <TextureFormat Format>
	bool operator== (const TextureColour<Format>& lhs,const TextureColour<Format>& rhs);

	template <TextureFormat LhsFormat,typename RhsType>
	const TextureColour<LhsFormat> operator* (const TextureColour<LhsFormat>& lhs,RhsType rhs);
	template <typename LhsType, TextureFormat RhsFormat>
	const TextureColour<RhsFormat> operator* (LhsType lhs,const TextureColour<RhsFormat>& rhs);
	template <TextureFormat LhsFormat,typename RhsType>
	const TextureColour<LhsFormat> operator/ (const TextureColour<LhsFormat>& lhs,RhsType rhs);
}

#endif // RENDERING_DATA_TYPES_TEXTURE_COLOUR_H
