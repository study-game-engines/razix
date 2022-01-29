#pragma once

#include <glm/glm.hpp>

namespace Razix {
    namespace Graphics {

        class RZMesh;

        enum class MeshPrimitive : int
        {
            Plane       = 0,
            Quad        = 1,
            Cube        = 2,
            Pyramid     = 3,
            Sphere      = 4,
            Capsule     = 5,
            Cylinder    = 6
        };

        /**
         * Mesh factory generates various mesh geometry primitives
         */


        RAZIX_API RZMesh* CreatePrimitive(MeshPrimitive primitive);

        RZMesh* CreateQuad();
        RZMesh* CreateScreenQuad();
        RZMesh* CreateQuad(float x, float y, float width, float height);
        RZMesh* CreateQuad(const glm::vec2& position, const glm::vec2& size);
        RZMesh* CreateCube();
        RZMesh* CreatePyramid();
        RZMesh* CreateSphere(uint32_t xSegments = 64, uint32_t ySegments = 64);
        RZMesh* CreateIcoSphere(uint32_t radius = 1, uint32_t subdivision = 64);
        RZMesh* CreateCapsule(float radius = 1.0f, float midHeight = 1.0f, int radialSegments = 64, int rings = 8);
        RZMesh* CreatePlane(float width, float height, const glm::vec3& normal);
        RZMesh* CreateCylinder(float bottomRadius = 1.0f, float topRadius = 1.0f, float height = 1.0f, int radialSegments = 64, int rings = 8);
    }
}
