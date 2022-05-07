///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/06 15:58)

#ifndef RENDERING_CONTROLLERS_MORPH_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_MORPH_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/Controllers/ControllerKeyInfo.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE MorphControllerImpl
    {
    public:
        using ClassType = MorphControllerImpl;
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;

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
        NODISCARD int GetNumVertices() const noexcept;
        NODISCARD int GetNumTargets() const noexcept;
        NODISCARD int GetNumKeys() const noexcept;
        NODISCARD APoint GetVertices(int target, int aVertices) const;
        NODISCARD float GetTimes(int key) const;
        NODISCARD float GetWeights(int key, int target) const;

        void SetVertices(int target, int vertices, const APoint& point);
        void SetTimes(int key, float time);
        void SetWeights(int key, int target, float weight);

        // ���ұ߽��ϵļ���
        NODISCARD ControllerKeyInfo GetKeyInfo(float ctrlTime) noexcept;

        NODISCARD int GetStreamingSize() const;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);

    private:
        // Ŀ�꼸���塣ÿ��Ŀ��Ķ������������ͱ�����ļ��ζ���Ķ���������ƥ�䡣
        // ����������λ��0����ЩĿ��֮һ��
        // ���ڹ��ڡ�������Կ�����£��������
        // ��λ�� i >= 1���鱻����Ϊ��i��Ŀ��͵�0��֮��Ĳ��졣
        int numVertices;
        int numTargets;
        std::vector<APoint> vertices;  // [numTargets][numVertices]

        // ���εļ����÷��Ͷ����Ŀ����ͨ��Ȩ��w[0]��w[N-1]ʹĿ������w[i]��[0,1]��w[i]��sum_i��1��
        // ÿ�������sum_{i=0}^{N-1} w[i] * X[i]������X[i]Ϊ��i��Ŀ���һ�����㡣
        // ����Ա���дΪ���X[0] + sum_{i=0}^{N-2} w'[i] Y[i] ������w'[i] = w[i+1]��
        // ��Y[i] = X[i+1] - X[0]��
        // �洢��������Ȩ����w'[i] �����ٴ洢����
        // ��Ҳ�����������˼���ʱ�䣨X[0]��ϵ��Ϊ1�����Ա���û�б�����������
        int numKeys;
        std::vector<float> times;  // [numKeys]
        std::vector<float> weights;  // [numKeys][numTargets-1]

        // O(1)�߽���Ҽ���
        int lastIndex;
    };
}

#endif  // RENDERING_CONTROLLERS_MORPH_CONTROLLER_IMPL_H
