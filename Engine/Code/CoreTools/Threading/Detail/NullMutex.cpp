// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:21)

#include "CoreTools/CoreToolsExport.h"

#include "NullMutex.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

CoreTools::NullMutex
	::NullMutex() noexcept
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NullMutex)

void CoreTools::NullMutex
	::Initialize() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::NullMutex
	::Delete() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::NullMutex
	::Enter() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::NullMutex
	::Leave() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;
}

bool CoreTools::NullMutex
	::TryEnter() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return true;
}



