/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 14:37)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_H

#include "CoreTools/CoreToolsDll.h"

#include "DataTypesFwd.h"
#include "MinHeapRecord.h"

#include <type_traits>

/// ��С����һ�ֶ���������ڵ����Ȩ�أ����Ҿ��и��ڵ��Ȩ��С�ڻ�������ӽڵ��Ȩ�ص�Լ����
/// �����ݽṹ�����������ȼ����С�
/// ���std::priority_queue�ӿ�������������������ʹ������
/// Ȼ��������ĳЩ�����㷨��˵���ýӿڲ�����ʵ��������ܡ�
/// ���磬���Ҫ�����߶�����г�ȡ����ÿ�������Ȩ��ȡ���������ڶ����λ�á�
/// �����СȨ�ض������С����ɾ���������������ڶ����Ȩ�ء���
/// ��������洢Ϊ˫����ʱ������O(1)ʱ�䡣
/// ���ڶ����Ѿ�����С���У�����޸����ǵ�Ȩ�ض�������С�����Ƴ���
/// Ȼ�����²��뵽��С������Ҫ�������ƶ����ʵ���λ�ã��Իָ���С�ѵĲ�������
/// ʹ��std::priority_queue�����޷�ֱ�ӷ����޸ĺ�Ķ��㣬
/// ����ʹ��������Щ���㣬ɾ�����ǣ��������ǵ�Ȩ�أ�Ȼ�����²������ǡ�
/// �������С��ʵ��֧�ָ��£��������Ƴ������²��롣
///
/// ValueType��ʾȨ�أ�������֧�ֱȽ�"<" �� "<="��
/// ������Ϣ���洢ΪKeyType�����洢����С���У��Է�����ʡ�
/// �ڣ����ţ����߳�ȡʾ���У�KeyType��һ�ִ洢���㼰�����ڶ��������Ľṹ��
/// ����Ĵ���˵������С�ѵĴ�����ʹ�á�
/// Weight()��������ѡ�������ָ���ȴ�������ɾ����Щ����ĺ�����
///
///    struct Vertex
///    {
///        int previous;
///        int current;
///        int next;
///    };
///
///    int numVertices = <���߶�����>;
///    std::vector<Vector<N, Real>> positions(numVertices);
///    <��������λ��[*]>;
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
///        <����Ӧ�ó������Ҫʹ��'vertex'>;
///
///        Vertex vertex = minHeapRecord.GetHandle();
///
///        // ��˫�����б���ɾ��'vertex'��
///        Vertex vertexPrevious = minHeap.GetHandle(records.at(vertex.previous));
///        Vertex vertexCurrent = minHeap.GetHandle(records.at(vertex.current));
///        Vertex vertexNext = minHeap.GetHandle(records.at(vertex.next));
///        vertexPrevious.next = vertexCurrent.next;
///        vertexNext.previous = vertexCurrent.previous;
///
///        // ������С�����ھӵ�Ȩ�ء�
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

        /// ֧�ֵ��ԡ������������ݽṹ�Ƿ�����Ч����С�ѡ�
        NODISCARD bool IsValid() const noexcept;
        NODISCARD bool IsValid(int childIndex) const;

        /// �����С�ѣ�ʹ�����ָ�������Ԫ�أ�
        /// numElementsΪ�㣬keys����Ϊrecords����Ȼ˳��
        void Reset(int maxElements);

        // ��ȡ��С������������Ԫ������
        NODISCARD int GetMaxElements() const;

        // ��ȡ��С���еĵ�ǰԪ��������������{0..maxElements}�ķ�Χ�ڡ�
        NODISCARD int GetNumElements() const noexcept;

        /// ��ȡ��С�ѵĸ����ú�����ȡ������������С����ɾ��Ԫ�ء�
        /// �������ص���MinHeapRecord��
        /// �����С�Ѳ�Ϊ�գ���MinHeapRecord�е�'index'��Ч�� 'weight'��Ӧ����С�ѵĸ���'handle'���û�Ϊ��ӦӦ�ó�������ṩ�ı�ʶ����
        /// �����С��Ϊ�գ����׳��쳣��
        NODISCARD MinHeapRecord GetMinimum() const;

        /// ����handle��weight��������С���С���������Ϊ'index'������ڲ���֮ǰ��С��δ������'index'����Ч�ģ����ң�handle��weight���洢����Ӧ�Ľڵ��С�
        /// ����ڲ���֮ǰ��С�����������׳��쳣�����Ҳ��޸���С�ѡ�����ɹ���'index'�����Ժ��ڵ���Updateʱʹ�á�
        /// ���磬�����߳�ȡʾ����ʾ���뽫'index'���ݸ�Update��
        /// auto index = minHeap.Insert(key, value);
        ///    <���κ���>;
        ///    minHeap.Update(index, newValue);
        NODISCARD int Insert(const KeyType& handle, const ValueType& weight);

        /// �Ƴ�������СȨ�ص���С�ѵĸ����������ص���MinHeapRecord��
        /// �����С����ɾ��֮ǰ��Ϊ�գ���MinHeapRecord���'index'����Ч�ģ����Ҷ�Ӧ�ڴ洢�Ľڵ㣨handle��weight����
        /// ���ɾ��ǰ��С��Ϊ�գ����׳��쳣���������ɹ������Ҳ��޸���С�ѡ�
        /// ��������Ŀ�����õ�����ʹ��'index'�����ڱ�Ҫʱ�����κ��������޸ĵ���֮ǰ������'index'�������κ���Դ��
        NODISCARD MinHeapRecord Remove();

        /// ��С�ѽڵ��ֵ����ͨ���˺������ý����޸ġ��������ǽ����������ָ�Ϊ��С�ѡ�
        /// ����'index' Ӧ����ͨ������"index = Insert(handle, oldWeight)"���صļ���
        /// ����'weight'��Ҫ��ü����;������������ֵ��
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
        /// ʹ�������洢ϵͳ��pointers���������á�
        /// ���ȣ����Ƕ�ÿ�������ֵ����Ψһ�ģ��Ա�֧����С�ѵ�Update()���ܡ�
        /// ��Σ����Ǳ������ڶ��н�������ʱ��Record�������Ǳ�ڵİ����ơ�

        /// ֧�ֶ��������˽ṹ������
        int numElements;

        /// ���������ڵ��ϵ��û�ָ����Ϣ��
        MinHeapRecordContainer records;

        KeysContainer pointers;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_H
