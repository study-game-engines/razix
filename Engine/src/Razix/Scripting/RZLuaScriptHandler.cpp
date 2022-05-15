// clang-format off
#include "rzxpch.h"
// clang-format on
#include "RZLuaScriptHandler.h"

#include "Razix/Core/RZApplication.h"
#include "Razix/Core/RZSplashScreen.h"

#include "Razix/Scene/RZScene.h"

#include "Razix/Scripting/LuaScriptComponent.h"

namespace Razix {
    namespace Scripting {

        void RZLuaScriptHandler::StartUp()
        {
            // Instance is automatically created once the system is Started Up
            RAZIX_CORE_INFO("[Lua Script Manager] Starting Up Lua Script Handler");
            Razix::RZSplashScreen::Get().setLogString("Starting Lua Script Handler...");

            // Load lua default libraries that can be used by the client
            m_State.open_libraries(sol::lib::base, sol::lib::package, sol::lib::math, sol::lib::table);

            // Bind the Engine Systems Scripting API to be exposed to user via lua
            bindApplicationAPI();

            // Bind the logging API that can be used by the user via scripts
            bindLoggingAPI();

            // Bind the ImGui bindings
            bindImGui();
        }

        void RZLuaScriptHandler::ShutDown()
        {
            RAZIX_CORE_ERROR("[Lua Script Manager] Shutting Lua Script Handler");
        }

        void RZLuaScriptHandler::OnStart(RZScene* scene)
        {
            RAZIX_PROFILE_FUNCTIONC(RZ_PROFILE_COLOR_SCRIPTING);

            auto& registry = scene->getRegistry();

            auto view = registry.view<LuaScriptComponent>();

            if (view.empty())
                return;

            for (auto entity: view) {
                auto& luaScript = registry.get<LuaScriptComponent>(entity);
                luaScript.OnStart();
            }
        }

        void RZLuaScriptHandler::OnUpdate(RZScene* scene, RZTimestep dt)
        {
            RAZIX_PROFILE_FUNCTIONC(RZ_PROFILE_COLOR_SCRIPTING);

            auto& registry = scene->getRegistry();

            auto view = registry.view<LuaScriptComponent>();

            if (view.empty())
                return;

            for (auto entity: view) {
                auto& luaScript = registry.get<LuaScriptComponent>(entity);
                luaScript.OnUpdate(dt);
            }
        }

        void RZLuaScriptHandler::bindApplicationAPI()
        {
            sol::usertype<RZApplication> appType = m_State.new_usertype<RZApplication>("RZApplication");

            appType.set_function("GetWindowSize", &RZApplication::getWindowSize);
            m_State.set_function("GetAppInstance", &RZApplication::Get);
        }

        void RZLuaScriptHandler::bindLoggingAPI()
        {
            auto log = m_State.create_table("RZLog");

            log.set_function("Trace", [&](sol::this_state s, std::string_view message) { RAZIX_TRACE(message); });

            log.set_function("Info", [&](sol::this_state s, std::string_view message) { RAZIX_INFO(message); });

            log.set_function("Warn", [&](sol::this_state s, std::string_view message) { RAZIX_WARN(message); });

            log.set_function("Error", [&](sol::this_state s, std::string_view message) { RAZIX_ERROR(message); });
        }

        void RZLuaScriptHandler::bindSceneManagerAPI()
        {
        }

        void RZLuaScriptHandler::bindInputAPI()
        {
        }

        void RZLuaScriptHandler::bindECSAPI()
        {
        }

    }    // namespace Scripting
}    // namespace Razix