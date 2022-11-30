///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/18 23:38)

// 警告：调用函数ReleaseSRWLockExclusive之前，调用者未能持有锁slimReaderWriterLock。

#if defined(TCRE_USE_MSVC)
    #pragma warning(disable : 26110)
#endif  // TCRE_USE_MSVC
