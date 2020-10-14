// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/23 10:14)

#ifndef RENDERING_CONTROLLERS_MORPH_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_MORPH_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/Controllers/ControllerKeyInfo.h"

#include <vector>
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
    class BufferTarget;
    class BufferSource;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE MorphControllerImpl
    {
    public:
        using ClassType = MorphControllerImpl;
        using AVector = Mathematics::FloatAVector;
        using APoint = Mathematics::FloatAPoint;

    public:
        // �������Ŀ�����ε�Ŀ�꣬���̶�����������ڵļ���
        // ���캯����һЩ�����������Ĺ�����
        // ÿ��Ŀ�궥�㣬ʱ�䣬��Ȩ�ض���������Ӧ�ĳ�Ա���ʷ��䡣

        // numVertices: ÿ��Ŀ��Ķ�������������е�Ŀ�������ͬ�����Ķ��㡣

        // numTargets:  ���ε�Ŀ����

        // numKeys:  ������Ŀ��ÿ����������һ���ض���ʱ�䡣

        MorphControllerImpl(int numVertices, int numTargets, int numKeys);
        MorphControllerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        // ���ù��캯����������ʹ����Щ�������ö������飬ʱ���Ȩ�ء�
        int GetNumVertices() const noexcept;
        int GetNumTargets() const noexcept;
        int GetNumKeys() const noexcept;
        const APoint GetVertices(int target, int vertices) const;
        float GetTimes(int key) const;
        float GetWeights(int key, int target) const;

        void SetVertices(int target, int vertices, const APoint& point);
        void SetTimes(int key, float times);
        void SetWeights(int key, int target, float weights);

        // ���ұ߽��ϵļ���
        const ControllerKeyInfo GetKeyInfo(float ctrlTime) noexcept;

        int GetStreamingSize() const;
        void Save(const CoreTools::BufferTargetSharedPtr& target) const;
        void Load(const CoreTools::BufferSourceSharedPtr& source);

    private:
        // Ŀ�꼸���塣ÿ��Ŀ��Ķ������������ͱ�����ļ��ζ���Ķ���������ƥ�䡣
        // ����������λ��0����ЩĿ��֮һ��
        // ���ڹ��ڡ�������Կ�����£��������
        // ��λ�� i >= 1���鱻����Ϊ��i��Ŀ��͵�0��֮��Ĳ��졣
        int m_NumVertices;
        int m_NumTargets;
        std::vector<APoint> m_Vertices;  // [numTargets][numVertices]

        // ���εļ����÷��Ͷ����Ŀ����ͨ��Ȩ��w[0]��w[N-1]ʹĿ������w[i]��[0,1]��w[i]��sum_i��1��
        // ÿ�������sum_{i=0}^{N-1} w[i] * X[i]������X[i]Ϊ��i��Ŀ���һ�����㡣
        // ����Ա���дΪ���X[0] + sum_{i=0}^{N-2} w'[i] Y[i] ������w'[i] = w[i+1]��
        // ��Y[i] = X[i+1] - X[0]��
        // �洢��������Ȩ����w'[i] �����ٴ洢����
        // ��Ҳ�����������˼���ʱ�䣨X[0]��ϵ��Ϊ1�����Ա���û�б�����������
        int m_NumKeys;
        std::vector<float> m_Times;  // [numKeys]
        std::vector<float> m_Weights;  // [numKeys][numTargets-1]

        // O(1)�߽���Ҽ���
        int m_LastIndex;
    };
}

#endif  // RENDERING_CONTROLLERS_MORPH_CONTROLLER_IMPL_H
