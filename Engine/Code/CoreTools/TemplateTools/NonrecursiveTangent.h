// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:38)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_TANGENT_H
#define CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_TANGENT_H

#include "CoreTools/CoreToolsDll.h"

#include "NonrecursiveSine.h"
#include "NonrecursiveCosine.h"

namespace CoreTools
{
	template <double& Radian>
	struct NonrecursiveTangent
	{
		static double Tan()
		{
			return NonrecursiveSine<Radian>::Sin() / NonrecursiveCosine<Radian>::Cos();
		}
	};
}

#define NONRECURSIVE_TANGENT( r ) CoreTools::NonrecursiveTangent< r >::Tan()

#endif // CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_TANGENT_H
