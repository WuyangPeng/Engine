// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:07)

#ifndef CORE_TOOLS_THREADING_MUTEX_FACTORY_H
#define CORE_TOOLS_THREADING_MUTEX_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Threading/ThreadingFwd.h"

#include <memory>

namespace CoreTools
{
	class MutexImpl;

	class CORE_TOOLS_HIDDEN_DECLARE MutexFactory
	{
	public:
		using ClassType = MutexFactory;
		using MutexImplPtr = std::shared_ptr<MutexImpl>;

	public:
		static MutexImplPtr GenerateMutex(MutexCreate mutexCreate);
	};
}

#endif // CORE_TOOLS_THREADING_MUTEX_FACTORY_H
