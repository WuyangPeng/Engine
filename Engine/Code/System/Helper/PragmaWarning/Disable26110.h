// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/02/16 22:05)

// 调用函数ReleaseSRWLockExclusive之前，调用者未能持有锁slimReaderWriterLock。

#if defined(TCRE_USE_MSVC)
	#pragma warning(disable : 26110) 
#endif // TCRE_USE_MSVC  
