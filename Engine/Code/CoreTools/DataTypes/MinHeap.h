///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/13 14:25)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_H

#include "CoreTools/CoreToolsDll.h"

#include "DataTypesFwd.h"
#include "MinHeapNode.h"
#include "MinHeapRecord.h"

#include <type_traits>

namespace CoreTools
{
    /// ����T�������С�ڱȽ������operator<(...)�����������Ƚ�������ǿ�ѡ�ġ�
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

        // ֧�ֵ��ԡ������������ݽṹ�Ƿ�����Ч����С�ѡ�
        NODISCARD bool IsValid() const noexcept;

        // ������С�ѵĴ�С��ʹ�����ָ�������Ԫ��������������С�ѵ���ǰ״̬��
        void Reset(int maxElements);

        // ��ȡ��С������������Ԫ������
        NODISCARD int GetMaxElements() const;

        // ��ȡ��С���еĵ�ǰԪ��������������{0..maxElements}�ķ�Χ�ڡ�
        NODISCARD int GetNumElements() const noexcept;

        /// ��ȡ��С�ѵĸ����ú�����ȡ������������С����ɾ��Ԫ�ء�
        /// �������ص���MinHeapRecord��
        /// �����С�Ѳ�Ϊ�գ���MinHeapRecord�е�'key'��Ч�� 'weight'��Ӧ����С�ѵĸ���'handle'���û�Ϊ��ӦӦ�ó�������ṩ�ı�ʶ����
        /// �����С��Ϊ�գ���'key'��Ч�����Ҳ������ɹ�������������£�'handle'�� 'weight'����Ч����Ӧʹ�á�
        NODISCARD MinHeapRecord GetMinimum() const;

        /// ����handle��weight��������С���С���������Ϊ'key'������ڲ���֮ǰ��С��δ������'key'����Ч�ģ����ң�handle��weight���洢����Ӧ�Ľڵ��С�
        /// ����ڲ���֮ǰ��С����������'key'��Ч���������ɹ������Ҳ��޸���С�ѡ�����ɹ���'key'�����Ժ��ڵ���Updateʱʹ�á�
        NODISCARD int Insert(int handle, const T& weight);

        /// �Ƴ�������СȨ�ص���С�ѵĸ����������ص���MinHeapRecord��
        /// �����С����ɾ��֮ǰ��Ϊ�գ���MinHeapRecord���'key'����Ч�ģ����Ҷ�Ӧ�ڴ洢�Ľڵ㣨handle��weight����
        /// ���ɾ��ǰ��С��Ϊ�գ���'key'��Ч���������ɹ������Ҳ��޸���С�ѡ�
        /// ����ʱ��'key'�ڽ�����һ�����롢ɾ������µ���֮ǰһֱ��Ч��
        /// ��������Ŀ�����õ�����ʹ��'key'�����ڱ�Ҫʱ�����κ��������޸ĵ���֮ǰ������'key'�������κ���Դ��
        NODISCARD MinHeapRecord Remove();

        /// ��С�ѽڵ��ֵ����ͨ���˺������ý����޸ġ��������ǽ����������ָ�Ϊ��С�ѡ�
        /// ����'updateKey' Ӧ����ͨ������"key = Insert(handle, oldWeight)"���صļ���
        /// ����'updateWeight'��Ҫ��ü����;������������ֵ��
        /// ��������Чʱ�����صĺ���Ϊ��updateKey����Ҳ����˵��Ҫ��0 <= updateKey < GetMaxElements()���ڲ�0 <= updateIndex < GetNumElements()��
        /// ���ҽ������¼������跶Χ��ʱ�������ŷ���'true'������������£�δ�޸���С�ѡ�
        NODISCARD bool Update(int updateKey, const T& updateWeight);

        NODISCARD MinHeapNodeContainer GetNodes() const;
        NODISCARD MinHeapNode GetNode(int key) const;

        NODISCARD int GetHandle(int key) const;
        NODISCARD T GetWeight(int key) const;

    private:
        using KeysContainer = std::vector<int>;
        using IndicesContainer = std::vector<int>;

    private:
        // ֧�ֶ��������˽ṹ������
        int numElements;
        KeysContainer keys;
        IndicesContainer indices;

        // ���������ڵ��ϵ��û�ָ����Ϣ��
        MinHeapNodeContainer nodes;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_H
