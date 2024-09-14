/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/14 11:28)

/// 警告：共享的指针参数impl通过引用进行传递，并且未进行重置或重新分配。请改用 T* 或 T&。

#if defined(TCRE_USE_MSVC)

    #pragma warning(disable : 26417)

#endif  // TCRE_USE_MSVC
