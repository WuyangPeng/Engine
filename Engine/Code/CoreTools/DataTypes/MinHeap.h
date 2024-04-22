/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:37)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_H

#include "CoreTools/CoreToolsDll.h"

#include "DataTypesFwd.h"
#include "MinHeapRecord.h"

#include <type_traits>

/// 最小堆是一种二叉树，其节点具有权重，并且具有父节点的权重小于或等于其子节点的权重的约束。
/// 该数据结构可以用作优先级队列。
/// 如果std::priority_queue接口足以满足您的需求，请使用它。
/// 然而，对于某些几何算法来说，该接口不足以实现最佳性能。
/// 例如，如果要对折线顶点进行抽取，则每个顶点的权重取决于其相邻顶点的位置。
/// 如果最小权重顶点从最小堆中删除，则必须更新相邻顶点的权重——
/// 当将顶点存储为双链表时，这是O(1)时间。
/// 相邻顶点已经在最小堆中，因此修改它们的权重而不从最小堆中移除，
/// 然后重新插入到最小堆中需要将它们移动到适当的位置，以恢复最小堆的不变量。
/// 使用std::priority_queue，您无法直接访问修改后的顶点，
/// 这迫使您搜索这些顶点，删除它们，更新它们的权重，然后重新插入它们。
/// 这里的最小堆实现支持更新，而无需移除和重新插入。
///
/// ValueType表示权重，它必须支持比较"<" 和 "<="。
/// 附加信息被存储为KeyType，并存储在最小堆中，以方便访问。
/// 在（开放）折线抽取示例中，KeyType是一种存储顶点及其相邻顶点索引的结构。
/// 下面的代码说明了最小堆的创建和使用。
/// Weight()函数是您选择的用于指导先从折线中删除哪些顶点的函数。
///
///    struct Vertex
///    {
///        int previous;
///        int current;
///        int next;
///    };
///
///    int numVertices = <折线顶点数>;
///    std::vector<Vector<N, Real>> positions(numVertices);
///    <分配所有位置[*]>;
///    MinHeap<Vertex, Real> minHeap{ numVertices };
///    std::vector<int> records(numVertices);
///    for (auto i = 0; i < numVertices; ++i)
///    {
///        Vertex vertex{};
///        vertex.previous = (i + numVertices - 1) % numVertices;
///        vertex.current = i;
///        vertex.next = (i + 1) % numVertices;
///        records.at(i) = minHeap.Insert(vertex, Weight(positions, vertex));
///    }
///
///    while (minHeap.GetNumElements() >= 2)
///    {
///        MinHeapRecord minHeapRecord = minHeap.Remove();
///        <根据应用程序的需要使用'vertex'>;
///
///        Vertex vertex = minHeapRecord.GetHandle();
///
///        // 从双链接列表中删除'vertex'。
///        Vertex vertexPrevious = minHeap.GetHandle(records.at(vertex.previous));
///        Vertex vertexCurrent = minHeap.GetHandle(records.at(vertex.current));
///        Vertex vertexNext = minHeap.GetHandle(records.at(vertex.next));
///        vertexPrevious.next = vertexCurrent.next;
///        vertexNext.previous = vertexCurrent.previous;
///
///        // 更新最小堆中邻居的权重。
///        minHeap.Update(records.at(vertex.previous), Weight(positions, vertexPrevious));
///        minHeap.Update(records.at(vertex.next), Weight(positions, vertexNext));
///    }
namespace CoreTools
{
    template <typename KeyType, typename ValueType>
    class MinHeap final
    {
    public:
        using ClassType = MinHeap<KeyType, ValueType>;

        using MinHeapRecord = MinHeapRecord<KeyType, ValueType>;
        using MinHeapRecordContainer = std::vector<MinHeapRecord>;

    public:
        explicit MinHeap(int maxElements);

        /// 支持调试。函数测试数据结构是否是有效的最小堆。
        NODISCARD bool IsValid() const noexcept;
        NODISCARD bool IsValid(int childIndex) const;

        /// 清除最小堆，使其具有指定的最大元素，
        /// numElements为零，keys设置为records的自然顺序。
        void Reset(int maxElements);

        // 获取最小堆中允许的最大元素数。
        NODISCARD int GetMaxElements() const;

        // 获取最小堆中的当前元素数。此数字在{0..maxElements}的范围内。
        NODISCARD int GetNumElements() const noexcept;

        /// 获取最小堆的根。该函数读取根，但不从最小堆中删除元素。
        /// 函数返回的是MinHeapRecord。
        /// 如果最小堆不为空，则MinHeapRecord中的'index'有效， 'weight'对应于最小堆的根，'handle'是用户为相应应用程序对象提供的标识符。
        /// 如果最小堆为空，则抛出异常。
        NODISCARD MinHeapRecord GetMinimum() const;

        /// 将（handle、weight）插入最小堆中。函数返回为'index'。如果在插入之前最小堆未满，则'index'是有效的，并且（handle，weight）存储在相应的节点中。
        /// 如果在插入之前最小堆已满，则抛出异常，并且不修改最小堆。插入成功后，'index'可以稍后在调用Update时使用。
        /// 例如，如折线抽取示例所示，请将'index'传递给Update：
        /// auto index = minHeap.Insert(key, value);
        ///    <做任何事>;
        ///    minHeap.Update(index, newValue);
        NODISCARD int Insert(const KeyType& handle, const ValueType& weight);

        /// 移除包含最小权重的最小堆的根。函数返回的是MinHeapRecord。
        /// 如果最小堆在删除之前不为空，则MinHeapRecord里的'index'是有效的，并且对应于存储的节点（handle，weight）。
        /// 如果删除前最小堆为空，则抛出异常，操作不成功，并且不修改最小堆。
        /// 这样做的目的是让调用者使用'index'，并在必要时，在任何其他堆修改调用之前清理与'index'关联的任何资源。
        NODISCARD MinHeapRecord Remove();

        /// 最小堆节点的值必须通过此函数调用进行修改。副作用是将二进制树恢复为最小堆。
        /// 输入'index' 应该是通过调用"index = Insert(handle, oldWeight)"返回的键。
        /// 输入'weight'是要与该键（和句柄）关联的新值。
        NODISCARD void Update(int index, const ValueType& weight);

        NODISCARD MinHeapRecord GetRecord(int index) const;

        NODISCARD KeyType GetHandle(int index) const;
        NODISCARD ValueType GetWeight(int index) const;

    private:
        using KeysContainer = std::vector<int>;

    private:
        NODISCARD int GetRecordKey(int index) const;
        void SetIndex(int index);

        void UpdateGreater(int index, const ValueType& weight);
        void UpdateLess(int index, const ValueType& weight);
        NODISCARD int GetMaxChildIndex(int childIndex);

    private:
        /// 使用两级存储系统。pointers有两个作用。
        /// 首先，它们对每个插入的值都是唯一的，以便支持最小堆的Update()功能。
        /// 其次，它们避免了在堆中进行排序时对Record对象进行潜在的昂贵复制。

        /// 支持二叉树拓扑结构和排序。
        int numElements;

        /// 二进制树节点上的用户指定信息。
        MinHeapRecordContainer records;

        KeysContainer pointers;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_H
