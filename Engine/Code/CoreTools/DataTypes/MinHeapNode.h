///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 09:26)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_NODE_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_NODE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    /// 存储在二叉树节点中的用户指定信息。
    /// handle是最小堆操作中涉及的应用程序对象的句柄。
    /// weight是与该对象相关联的权重。
    template <typename T>
    class MinHeapNode final
    {
    public:
        using ClassType = MinHeapNode<T>;

    public:
        MinHeapNode() noexcept;
        MinHeapNode(int handle, const T& weight) noexcept(std::is_arithmetic_v<T>);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetHandle() const noexcept;
        NODISCARD T GetWeight() const noexcept(std::is_arithmetic_v<T>);

        NODISCARD void SetHandle(int aHandle) noexcept;
        NODISCARD void SetWeight(const T& aWeight) noexcept(std::is_arithmetic_v<T>);

    private:
        int handle;
        T weight;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_NODE_H
