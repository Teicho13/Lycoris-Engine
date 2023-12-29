project "Lycoris-Core"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files 
   { 
    "Source/**.h", 
    "Source/**.cpp",
    "ThirdParty/glad/src/**.c",
    "ThirdParty/imgui/include/imgui/*.h",
    "ThirdParty/imgui/include/imgui/*.cpp",
    "ThirdParty/entt/include/*.hpp"
    }

   includedirs
   {
      "Source",
      "ThirdParty/GLFW/include",
      "ThirdParty/glad/include",
      "ThirdParty/imgui/include",
      "ThirdParty/entt/include"
   }


   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"