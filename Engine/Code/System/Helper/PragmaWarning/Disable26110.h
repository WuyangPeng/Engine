//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 18:25)

// 调用函数ReleaseSRWLockExclusive之前，调用者未能持有锁slimReaderWriterLock。

#if defined(TCRE_USE_MSVC)
    #pragma warning(disable : 26110)
#endif  // TCRE_USE_MSVC
