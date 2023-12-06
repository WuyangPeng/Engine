///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:11)

#ifndef RENDERING_SCENE_GRAPH_STANDARD_MESH_H
#define RENDERING_SCENE_GRAPH_STANDARD_MESH_H

#include "Rendering/RenderingDll.h"

#include "TrianglesMesh.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(StandardMesh, StandardMeshImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE StandardMesh
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(StandardMesh);

    public:
        // ��׼������ÿ����������(0,0,0)Ϊ���ģ�
        // ���Ҿ���(0,0,1)��up�ᡣ
        // ����ϵͳ�е�������(1,0,0)�� (0,1,0)��
        // Ӧ�ó������ͨ���ṩһ������'transform'�����캯���Ա任����
        // ���һ����յ���״��Ҫ�Զ����ⲿ�۲��߿ɼ��ģ�
        // ��ô��inside������Ϊ��false��;�������á�inside������true����
        // ʹ�ù۲��߻ῴ�������ڲ�ʱ������
        // ���á�isStatic��Ϊ��true�����л������÷�BufferUsage::Static��
        // ����isStatic'�ǡ�false�����л������÷�BufferUsage::Dynamic��
        StandardMesh(const VertexFormatSharedPtr& vertexFormat, bool isStatic = true, bool inside = false, const Mathematics::TransformF* transform = nullptr);

        CLASS_INVARIANT_DECLARE;

        // �����������ߵ�ת��
        void SetTransform(const Mathematics::TransformF& transform);
        NODISCARD const Mathematics::TransformF& GetTransform() const noexcept;

        // ������ֶ����ע���ǵ����롰transform����nullptr(��λtransform)��

        // ��������z = 0ƽ�棬���ǹ۲��߿ɼ��ģ�
        // ����ƽ���Ϸ��ߣ�0,0,1�����һ�ࡣ
        // ���н�(-xExtent, -yExtent, 0)��(+xExtent, -yExtent, 0),
        // (-xExtent, +yExtent, 0)��(+xExtent, +yExtent, 0)��
        // �������ܹ���xSamples������x�����ySamples������y������
        // �����ܹ���xSamples * ySamples���㡣
        const TrianglesMeshSharedPtr Rectangle(int xSamples, int ySamples, float xExtent, float yExtent) const;

        // ��������z = 0ƽ�棬���ǹ۲��߿ɼ��ģ�
        // ����ƽ���Ϸ��ߣ�0,0,1�����һ�ࡣ
        // �������ģ�0,0,0����ָ���ġ��뾶����
        // ��������������ڵ�һ���㡣
        // ��Ʒ�����������ߵĹ�ͬԭ�����ĵ㡣
        // �С�radialSamples�������ߡ�
        // ����ÿ�����ߵķ����С�shellSamples'�����㡣
        NODISCARD TrianglesMeshSharedPtr Disk(int shellSamples, int radialSamples, float radius) const;

        // ����������(0,0,0)����λ������(1,0,0), (0,1,0), ��(0,0,1)
        // �ͷ�Χ���볤��'xExtent', 'yExtent', �� 'zExtent'��
        // �������8�������12�������Ρ�
        // ���ӣ����ӽ��ڵ�һ���˷�����(xExtent, yExtent, zExtent)��
        NODISCARD TrianglesMeshSharedPtr Box(float xExtent, float yExtent, float zExtent) const;

        // Բ��������(0,0,0)��ָ���İ뾶��ָ���ĸ߶ȡ�
        // Բ��������һ���߶�(0,0,0)+ t * (0,0,1)������|t| <= height/2��
        // Բ��������ʽ�ض���Ϊ x^2 + y^2 = radius^2.��
        // CylinderOmittedEndDisks,Բ�����̱�ʡ��,����һ�����ŵĹܡ�
        // CylinderIncludedEndDisks,Բ�����̱��������ڡ�
        // ÿ��������һ�������������Σ���ȫǶ���ڰ���һ������Ϊ����Ķ����,
        // ����ηֽ�Ϊ������,���������ι������Ķ���
        // ��ÿ�������ΰ���һ������εıߡ�
        NODISCARD TrianglesMeshSharedPtr CylinderOmittedEndDisks(int axisSamples, int radialSamples, float radius, float height) const;
        NODISCARD TrianglesMeshSharedPtr CylinderIncludedEndDisks(int axisSamples, int radialSamples, float radius, float height) const;

        // ���������ĵ� (0,0,0) ��ָ���뾶��
        // ������(0,0,radius)���ϼ���(0,0,-radius)��
        // ��������˽ṹ��һ�����ŵ�Բ��
        // (Ҳ��һ�����ε�������ȫ��λ��һ��ƽ�б�),Ȼ���ϵ��ϱ�������
        // �����ηֲ��������������Ҫһ�������ȷֲ�,����һ����ʮ�����ϸ������
        NODISCARD TrianglesMeshSharedPtr Sphere(int zSamples, int radialSamples, float radius) const;

        // Բ���������ĵ�(0,0,0)��
        // �����۲컷���ߵķ���(0,0,1),��������һ������
        // Բ�����Ļ��뾶Ϊ��outerRadius����
        // ���Բ�ľ���ı߽绷���ڰ뾶��
        NODISCARD TrianglesMeshSharedPtr Torus(int circleSamples, int radialSamples, float outerRadius, float innerRadius) const;

        // ����ͼ�����壬����������һ����λԲ��������(0,0,0)��
        NODISCARD TrianglesMeshSharedPtr Tetrahedron() const;
        NODISCARD TrianglesMeshSharedPtr Hexahedron() const;
        NODISCARD TrianglesMeshSharedPtr Octahedron() const;
        NODISCARD TrianglesMeshSharedPtr Dodecahedron() const;
        NODISCARD TrianglesMeshSharedPtr Icosahedron() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SCENE_GRAPH_STANDARD_MESH_H
