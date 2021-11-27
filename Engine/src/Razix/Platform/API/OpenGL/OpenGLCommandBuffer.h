#pragma once

#include "Razix/Graphics/API/RZCommandBuffer.h"
 
namespace Razix {
    namespace Graphics {

        class OpenGLCommandBuffer : public RZCommandBuffer
        {
        public:
            OpenGLCommandBuffer();
            ~OpenGLCommandBuffer();

            void Init() override;
            void BeginRecording() override;
            void EndRecording() override;
            void Execute() override;
            void Reset() override;

            void UpdateViewport(uint32_t width, uint32_t height) override;
        };

    }
}