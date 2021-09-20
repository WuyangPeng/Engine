// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 15:36)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TINY_TEST_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TINY_TEST_H

#include "CoreTools/TemplateTools/Tiny.h"

namespace CoreTools
{
	template<typename Tiny, typename Pos>
	struct CheckAt
	{
		using ItemAt = typename boost::mpl::at<Tiny, Pos>::type;
		using Beg = typename boost::mpl::begin<Tiny>::type;
		using Item = typename boost::mpl::deref<typename boost::mpl::advance<Beg, Pos>::type>::type;

		BOOST_STATIC_ASSERT((boost::is_same<ItemAt, Item>::value));

		using ClassType = CheckAt<Tiny, Pos>;
		using type = CheckAt<Tiny, Pos>;
	}; 

	template<typename Tiny>
	struct TinyTest
	{
		using ClassType = TinyTest<Tiny>;
		using type = TinyTest<Tiny>;

		BOOST_STATIC_ASSERT((boost::is_same<Tiny, typename Tiny::type>::value));

		using Beg = typename boost::mpl::begin<Tiny>::type;
		using End = typename boost::mpl::end<Tiny>::type;
		using Distance = typename boost::mpl::distance<Beg, End>::type;
		using Size = typename boost::mpl::size<Tiny>::type;

		BOOST_STATIC_ASSERT(Size::value == Distance::value);

		using CheckAt2 = typename boost::mpl::eval_if<boost::mpl::greater<Size, TinyTwo>, CheckAt<Tiny, TinyTwo>, boost::mpl::true_>::type;

		using CheckAt1 = typename boost::mpl::eval_if<boost::mpl::greater<Size, TinyOne>, CheckAt<Tiny, TinyOne>, boost::mpl::true_>::type;

		using CheckAt0 = typename boost::mpl::eval_if<boost::mpl::greater<Size, TinyZero>, CheckAt<Tiny, TinyZero>, boost::mpl::true_>::type;
	};
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TINY_TEST_H


