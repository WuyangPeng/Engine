/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 17:02)

/// 警告： (<expression> && <non-zero constant>) 始终计算为 <expression> 的结果: 你是否打算使用 bitwise-and (`&`)运算符? 如果不是，请考虑删除冗余 "<non-zero constant>" 和 `&&` 运算符。

#if defined(TCRE_USE_MSVC)

    #pragma warning(disable : 6240)

#endif  // TCRE_USE_MSVC
