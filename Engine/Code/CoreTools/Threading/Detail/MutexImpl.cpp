// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:21)

#include "CoreTools/CoreToolsExport.h"

#include "MutexImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::MutexImpl
	::MutexImpl() noexcept
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::MutexImpl
	::~MutexImpl() noexcept
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MutexImpl)
