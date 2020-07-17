// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/08 19:07)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_ALGORITHM_H
#define SYSTEM_HELPER_PRAGMA_WARNING_ALGORITHM_H 

#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH
	
	#include SYSTEM_WARNING_DISABLE(26401)
	#include SYSTEM_WARNING_DISABLE(26495)

	#include <boost/algorithm/string/trim.hpp>
	#include <boost/algorithm/string/split.hpp>
	#include <boost/algorithm/string/predicate.hpp>
	#include <boost/algorithm/string/classification.hpp>

#include STSTEM_WARNING_POP

#endif // SYSTEM_HELPER_PRAGMA_WARNING_ALGORITHM_H