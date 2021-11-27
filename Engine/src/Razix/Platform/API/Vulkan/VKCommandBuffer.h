#pragma once

#include "Razix/Graphics/API/RZCommandBuffer.h"

#ifdef RAZIX_RENDER_API_VULKAN

#include <vulkan/vulkan.h>

namespace Razix {
    namespace Graphics {

        class VKCommandBuffer : public RZCommandBuffer
        {
        public:
            VKCommandBuffer();
            ~VKCommandBuffer();

            void Init() override;
            void BeginRecording() override;
            void EndRecording() override;
            void Execute() override;
            void Reset() override;
            void UpdateViewport(uint32_t width, uint32_t height) override;

            const VkCommandBuffer& getVKCmdBuffer() const { return m_CommandBuffer; }
    
        private:
            VkCommandBuffer m_CommandBuffer;    /* Handle to the Vulkan command buffer that will be executed by the GPu     */
            VkCommandPool   m_CommandPool;      /* The command pool from which the command buffer will be allocated from    */
        };
    }
}
#endif