///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/13 14:25)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_H

#include "CoreTools/CoreToolsDll.h"

#include "DataTypesFwd.h"
#include "MinHeapNode.h"
#include "MinHeapRecord.h"

#include <type_traits>

namespace CoreTools
{
    /// 类型T必须具有小于比较运算符operator<(...)函数。其他比较运算符是可选的。
    template <typename T>
    class MinHeap final
    {
    public:
        using ClassType = MinHeap<T>;

        using MinHeapNode = MinHeapNode<T>;
        using MinHeapRecord = MinHeapRecord<T>;
        using MinHeapNodeContainer = std::vector<MinHeapNode>;

        static constexpr auto invalid = std::numeric_limits<int>::max();

    public:
        explicit MinHeap(int maxElements);

        // 支持调试。函数测试数据结构是否是有效的最小堆。
        NODISCARD bool IsValid() const noexcept;

        // 调整最小堆的大小，使其具有指定的最大元素数。不保留最小堆的先前状态。
        void Reset(int maxElements);

        // 获取最小堆中允许的最大元素数。
        NODISCARD int GetMaxElements() const;

        // 获取最小堆中的当前元素数。此数字在{0..maxElements}的范围内。
        NODISCARD int GetNumElements() const noexcept;

        /// 获取最小堆的根。该函数读取根，但不从最小堆中删除元素。
        /// 函数返回的是MinHeapRecord。
        /// 如果最小堆不为空，则MinHeapRecord中的'key'有效， 'weight'对应于最小堆的根，'handle'是用户为相应应用程序对象提供的标识符。
        /// 如果最小堆为空，则'key'无效，并且操作不成功，在这种情况下，'handle'和 'weight'都无效，不应使用。
        NODISCARD MinHeapRecord GetMinimum() const;

        /// 将（handle、weight）插入最小堆中。函数返回为'key'。如果在插入之前最小堆未满，则'key'是有效的，并且（handle，weight）存储在相应的节点中。
        /// 如果在插入之前最小堆已满，则'key'无效，操作不成功，并且不修改最小堆。插入成功后，'key'可以稍后在调用Update时使用。
        NODISCARD int Insert(int handle, const T& weight);

        /// 移除包含最小权重的最小堆的根。函数返回的是MinHeapRecord。
        /// 如果最小堆在删除之前不为空，则MinHeapRecord里的'key'是有效的，并且对应于存储的节点（handle，weight）。
        /// 如果删除前最小堆为空，则'key'无效，操作不成功，并且不修改最小堆。
        /// 返回时，'key'在进行另一个插入、删除或更新调用之前一直有效。
        /// 这样做的目的是让调用者使用'key'，并在必要时，在任何其他堆修改调用之前清理与'key'关联的任何资源。
        NODISCARD MinHeapRecord Remove();

        /// 最小堆节点的值必须通过此函数调用进行修改。副作用是将二进制树恢复为最小堆。
        /// 输入'updateKey' 应该是通过调用"key = Insert(handle, oldWeight)"返回的键。
        /// 输入'updateWeight'是要与该键（和句柄）关联的新值。
        /// 当函数有效时，返回的函数为“updateKey”；也就是说，要求0 <= updateKey < GetMaxElements()，内部0 <= updateIndex < GetNumElements()。
        /// 当且仅当更新键在所需范围内时，函数才返回'true'，在这种情况下，未修改最小堆。
        NODISCARD bool Update(int updateKey, const T& updateWeight);

        NODISCARD MinHeapNodeContainer GetNodes() const;
        NODISCARD MinHeapNode GetNode(int key) const;

        NODISCARD int GetHandle(int key) const;
        NODISCARD T GetWeight(int key) const;

    private:
        using KeysContainer = std::vector<int>;
        using IndicesContainer = std::vector<int>;

    private:
        // 支持二叉树拓扑结构和排序。
        int numElements;
        KeysContainer keys;
        IndicesContainer indices;

        // 二进制树节点上的用户指定信息。
        MinHeapNodeContainer nodes;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_H
