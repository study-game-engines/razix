#pragma once

#include "Razix/Graphics/API/GraphicsContext.h"

struct GLFWwindow;

namespace Razix
{
    namespace Graphics {
        class OpenGLContext : public RZGraphicsContext
        {
        public:
            OpenGLContext(GLFWwindow* windowHandle);

            virtual void Init() override;
            virtual void Destroy() override;
            virtual void SwapBuffers() override;
            virtual void ClearWithColor(float r, float g, float b) override;

        private:
            GLFWwindow* m_WindowHandle;
        };
    }

}
