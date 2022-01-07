///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:05)

// 如果 double/float 为负值，则从浮点类型转换为无符号整数类型将导致不可移植的代码。

#if defined(TCRE_USE_MSVC)
    #pragma warning(disable : 26467)
#endif  // TCRE_USE_MSVC
