#pragma once

#include "Razix/Graphics/RHI/API/RZGraphicsContext.h"

#ifdef RAZIX_RENDER_API_DIRECTX12

    #include <d3d12.h>
    #include <wrl.h>

namespace Razix {
    namespace Graphics {
        class DX12Context : public RZGraphicsContext
        {
        public:
            DX12Context(RZWindow* windowHandle);
            ~DX12Context() {}

            void Init() override;
            void Destroy() override;
            void ClearWithColor(f32 r, f32 g, f32 b) override;

        private:
            RZWindow*                            m_Window; /* The Window handle                 */
            Microsoft::WRL::ComPtr<ID3D12Device> m_Device; /* D3D12 handle to the GPU device    */
        };
    }    // namespace Graphics
}    // namespace Razix

#endif