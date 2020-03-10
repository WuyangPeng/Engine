// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/17 14:09)

#ifndef RENDERING_DATA_TYPES_COLOUR_DEFAULT_TRAITS_H
#define RENDERING_DATA_TYPES_COLOUR_DEFAULT_TRAITS_H

#include <type_traits> 

namespace Rendering
{
	template <typename T,typename Enable = void>
	struct ColourDefaultTraits;

	template <typename T>
	struct ColourDefaultTraits<T,typename std::enable_if<std::is_floating_point_v<T>>::type>
	{
		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_MaxValue = 1;
	};
	
	template <typename T>
	struct ColourDefaultTraits<T,typename std::enable_if<std::is_integral_v<T>>::type>
	{
		static_assert(!std::is_same_v<char,T>,"char and T must be the same!");
		static_assert(!std::is_same_v<int8_t,T>,"char and T must be the same!");

		static constexpr auto sm_MinValue = 0;
		static constexpr auto sm_MaxValue = 0xFF;
	};	 
}

#endif // RENDERING_DATA_TYPES_COLOUR_DEFAULT_TRAITS_H
